//
//  FKFlickrPhotosGetAllContexts.h
//  FlickrKit
//
//  Generated by FKAPIBuilder.
//  Copyright (c) 2013 DevedUp Ltd. All rights reserved. http://www.devedup.com
//
//  DO NOT MODIFY THIS FILE - IT IS MACHINE GENERATED


#import "FKFlickrAPIMethod.h"

typedef NS_ENUM(NSInteger, FKFlickrPhotosGetAllContextsError) {
	FKFlickrPhotosGetAllContextsError_PhotoNotFound = 1,		 /* The photo id passed was not the id of a valid photo. */
	FKFlickrPhotosGetAllContextsError_InvalidAPIKey = 100,		 /* The API key passed was not valid or has expired. */
	FKFlickrPhotosGetAllContextsError_ServiceCurrentlyUnavailable = 105,		 /* The requested service is temporarily unavailable. */
	FKFlickrPhotosGetAllContextsError_WriteOperationFailed = 106,		 /* The requested operation failed due to a temporary issue. */
	FKFlickrPhotosGetAllContextsError_FormatXXXNotFound = 111,		 /* The requested response format was not found. */
	FKFlickrPhotosGetAllContextsError_MethodXXXNotFound = 112,		 /* The requested method was not found. */
	FKFlickrPhotosGetAllContextsError_InvalidSOAPEnvelope = 114,		 /* The SOAP envelope send in the request could not be parsed. */
	FKFlickrPhotosGetAllContextsError_InvalidXMLRPCMethodCall = 115,		 /* The XML-RPC request document could not be parsed. */
	FKFlickrPhotosGetAllContextsError_BadURLFound = 116,		 /* One or more arguments contained a URL that has been used for abuse on Flickr. */

};

/*

Returns all visible sets and pools the photo belongs to.


Response:

<set id="392" title="记忆群组" />
<pool id="34427465471@N01" title="FlickrDiscuss" />

*/
@interface FKFlickrPhotosGetAllContexts : NSObject <FKFlickrAPIMethod>

/* The photo to return information for. */
@property (nonatomic, copy) NSString *photo_id; /* (Required) */


@end
