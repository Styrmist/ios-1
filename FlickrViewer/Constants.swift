import Foundation

class FlickrAPIConst{
    
    static let apiKey = "996026186ece04d3075511e27efc76a6"
    static let apiUrl = "https://api.flickr.com/services/rest/"
    static let endPoint = "flickr.photos.search"
    static let responseFormat = "json"
    static let noJsonCallback = "1"
    static let contentType  = "1"
    static let hasGeo = "1"
    static let media = "photos"
    static let radius = "1"
    static let radiusUnits = "km"
    static let perPage = "30"
    
    static var text = ""
    static var latitude = "50.450366"
    static var longtitude = "30.524445"
}

///// https://api.flickr.com/services/feeds/photos_public.gne?format=json&nojsoncallback=1
