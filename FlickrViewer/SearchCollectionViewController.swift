import UIKit
import CoreLocation

private let reuseIdentifier = "Cell"
private let ImageViewTag = 1
var latitude : Double = 0
var longitude : Double = 0

class SearchCollectionViewController: UICollectionViewController, CLLocationManagerDelegate {
    
    var textSearch = ""
    let locationManager = CLLocationManager()
    var photos = [[String: AnyObject]]()
    @IBOutlet weak var searchField: UITextField!
    @IBAction func search(_ sender: UITextField) {
        if let text = searchField.text {
            textSearch = text
        }
        FlickrAPI.searchPhotos(text: textSearch) { (photosArray, error) in
            self.photos = photosArray
            DispatchQueue.main.async {
                self.collectionView?.reloadData()
            }
        }
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        locationManager.requestAlwaysAuthorization()
        locationManager.requestWhenInUseAuthorization()
        if CLLocationManager.locationServicesEnabled() {
                locationManager.delegate = self
                locationManager.desiredAccuracy = kCLLocationAccuracyNearestTenMeters
                locationManager.startUpdatingLocation()
        }
        
        collectionView?.register(SearchCollectionViewCell.self, forCellWithReuseIdentifier: "cell")
        collectionView?.prefetchDataSource = self
        
        let minimumInterItemSpacing: CGFloat = 3
        let minimumLineSpacing: CGFloat = 3
        let numberOfColumns: CGFloat = 3
        
        let width = ((collectionView?.frame.width)! - minimumInterItemSpacing - minimumLineSpacing) / numberOfColumns
        
        let layout = collectionViewLayout as! UICollectionViewFlowLayout
        layout.minimumInteritemSpacing = minimumInterItemSpacing
        layout.minimumLineSpacing = minimumLineSpacing
        
        layout.itemSize = CGSize(width: width, height: width)
        
        FlickrAPI.searchPhotos(text: textSearch) { (photosArray, error) in
            self.photos = photosArray
            DispatchQueue.main.async {
                self.collectionView?.reloadData()
            }
        }
    }
    
    
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        guard let location: CLLocationCoordinate2D = manager.location?.coordinate else { return }
        latitude = location.latitude
        longitude = location.longitude
        locationManager.stopUpdatingLocation()
    }

    override func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return photos.count
    }

    override func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: reuseIdentifier, for: indexPath) as! SearchCollectionViewCell
      
        let photoDict = photos[(indexPath as NSIndexPath).row]
        
        if let imageUrlString = photoDict["url_m"] as? String
        {
            cell.imageView.loadFromURL(imageUrlString)
        }
        
        return cell
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "ShowMore"{
            if let cellIndex = self.collectionView?.indexPathsForSelectedItems {
                let detailVC = segue.destination as! DetailViewController
                detailVC.imageLink = (photos[cellIndex[0].row]["url_m"] as! String)
            }
            
        }
    }
}

extension SearchCollectionViewController: UICollectionViewDataSourcePrefetching {
    func collectionView(_ collectionView: UICollectionView, prefetchItemsAt indexPaths: [IndexPath]) {
        if indexPaths.last?[1] == photos.count - 1  {
            FlickrAPI.searchPhotos(text: textSearch) { (photosArray, error) in
                self.photos += photosArray
                DispatchQueue.main.async {
                    self.collectionView?.reloadData()
                }
            }
        }
    }
}
