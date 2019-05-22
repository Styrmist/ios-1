import UIKit

private let reuseIdentifier = "Cell"
private let ImageViewTag = 1

class LocationCollectionViewController: UICollectionViewController {
    
    var photos = [[String: AnyObject]]()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        collectionView?.register(LocationCollectionViewCell.self, forCellWithReuseIdentifier: "cell")
        collectionView?.prefetchDataSource = self
        
        let minimumInterItemSpacing: CGFloat = 3
        let minimumLineSpacing: CGFloat = 3
        let numberOfColumns: CGFloat = 3
        
        let width = ((collectionView?.frame.width)! - minimumInterItemSpacing - minimumLineSpacing) / numberOfColumns
        
        let layout = collectionViewLayout as! UICollectionViewFlowLayout
        layout.minimumInteritemSpacing = minimumInterItemSpacing
        layout.minimumLineSpacing = minimumLineSpacing
        
        layout.itemSize = CGSize(width: width, height: width)
        FlickrAPI.locationPhotos(longitude: -0.1337, latitude: 51.50998) { (photosArray, error) in
            self.photos = photosArray
            DispatchQueue.main.async {
                self.collectionView?.reloadData()
            }
        }
    
    }

    override func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
       return photos.count
    }

    override func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: reuseIdentifier, for: indexPath) as! LocationCollectionViewCell
        
        let photoDict = photos[(indexPath as NSIndexPath).row]
        
        if let imageUrlString = photoDict["url_m"] as? String
        {
            cell.imageView.loadFromURL(imageUrlString)
        }
        
        return cell
    }

    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "LocationMore"{
            if let cellIndex = self.collectionView?.indexPathsForSelectedItems {
                let detailVC = segue.destination as! DetailViewController
                detailVC.imageLink = (photos[cellIndex[0].row]["url_m"] as! String)
            }
            
        }
    }
}
extension LocationCollectionViewController: UICollectionViewDataSourcePrefetching {
    func collectionView(_ collectionView: UICollectionView, prefetchItemsAt indexPaths: [IndexPath]) {
        if indexPaths.last?[1] == photos.count - 1  {
            FlickrAPI.locationPhotos(longitude: longitude, latitude: latitude) { (photosArray, error) in
                self.photos += photosArray
                DispatchQueue.main.async {
                    self.collectionView?.reloadData()
                }
            }
        }
    }
}
