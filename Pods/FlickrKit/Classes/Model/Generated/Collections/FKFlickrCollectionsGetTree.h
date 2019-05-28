//
//  FKFlickrCollectionsGetTree.h
//  FlickrKit
//
//  Generated by FKAPIBuilder.
//  Copyright (c) 2013 DevedUp Ltd. All rights reserved. http://www.devedup.com
//
//  DO NOT MODIFY THIS FILE - IT IS MACHINE GENERATED


#import "FKFlickrAPIMethod.h"

typedef NS_ENUM(NSInteger, FKFlickrCollectionsGetTreeError) {
	FKFlickrCollectionsGetTreeError_UserNotFound = 1,		 /* The specified user could not be found. */
	FKFlickrCollectionsGetTreeError_CollectionNotFound = 2,		 /* The specified collection does not exist. */
	FKFlickrCollectionsGetTreeError_InvalidAPIKey = 100,		 /* The API key passed was not valid or has expired. */
	FKFlickrCollectionsGetTreeError_ServiceCurrentlyUnavailable = 105,		 /* The requested service is temporarily unavailable. */
	FKFlickrCollectionsGetTreeError_WriteOperationFailed = 106,		 /* The requested operation failed due to a temporary issue. */
	FKFlickrCollectionsGetTreeError_FormatXXXNotFound = 111,		 /* The requested response format was not found. */
	FKFlickrCollectionsGetTreeError_MethodXXXNotFound = 112,		 /* The requested method was not found. */
	FKFlickrCollectionsGetTreeError_InvalidSOAPEnvelope = 114,		 /* The SOAP envelope send in the request could not be parsed. */
	FKFlickrCollectionsGetTreeError_InvalidXMLRPCMethodCall = 115,		 /* The XML-RPC request document could not be parsed. */
	FKFlickrCollectionsGetTreeError_BadURLFound = 116,		 /* One or more arguments contained a URL that has been used for abuse on Flickr. */

};

/*

Returns a tree (or sub tree) of collections belonging to a given user.

A nested tree of collections, and the collections and sets they contain.

Response:

<collections>
<collection id="12-72157594586579649" title="All My Photos" description="a collection" iconlarge="http://farm1.static.flickr.com/187/cols/37_43fac2cf79_l.jpg" 
iconsmall="http://farm1.static.flickr.com/187/cols/56_43fac2cf79_s.jpg">
<set id="92157594171298291" title="kitesurfing" description="a set"/>
<set id="72157594247596158" title="faves" description="some favorites."/>
</collection>
</collections>

*/
@interface FKFlickrCollectionsGetTree : NSObject <FKFlickrAPIMethod>

/* The ID of the collection to fetch a tree for, or zero to fetch the root collection. Defaults to zero. */
@property (nonatomic, copy) NSString *collection_id;

/* The ID of the account to fetch the collection tree for. Deafults to the calling user. */
@property (nonatomic, copy) NSString *user_id;


@end
