//
//  FKFlickrPhotosSetTags.h
//  FlickrKit
//
//  Generated by FKAPIBuilder.
//  Copyright (c) 2013 DevedUp Ltd. All rights reserved. http://www.devedup.com
//
//  DO NOT MODIFY THIS FILE - IT IS MACHINE GENERATED


#import "FKFlickrAPIMethod.h"

typedef NS_ENUM(NSInteger, FKFlickrPhotosSetTagsError) {
	FKFlickrPhotosSetTagsError_PhotoNotFound = 1,		 /* The photo id passed was not the id of a photo belonging to the calling user. It might be an invalid id, or the photo might be owned by another user.  */
	FKFlickrPhotosSetTagsError_MaximumNumberOfTagsReached = 2,		 /* The number of tags specified exceeds the limit for the photo. No tags were modified. */
	FKFlickrPhotosSetTagsError_SSLIsRequired = 95,		 /* SSL is required to access the Flickr API. */
	FKFlickrPhotosSetTagsError_InvalidSignature = 96,		 /* The passed signature was invalid. */
	FKFlickrPhotosSetTagsError_MissingSignature = 97,		 /* The call required signing but no signature was sent. */
	FKFlickrPhotosSetTagsError_LoginFailedOrInvalidAuthToken = 98,		 /* The login details or auth token passed were invalid. */
	FKFlickrPhotosSetTagsError_UserNotLoggedInOrInsufficientPermissions = 99,		 /* The method requires user authentication but the user was not logged in, or the authenticated method call did not have the required permissions. */
	FKFlickrPhotosSetTagsError_InvalidAPIKey = 100,		 /* The API key passed was not valid or has expired. */
	FKFlickrPhotosSetTagsError_ServiceCurrentlyUnavailable = 105,		 /* The requested service is temporarily unavailable. */
	FKFlickrPhotosSetTagsError_WriteOperationFailed = 106,		 /* The requested operation failed due to a temporary issue. */
	FKFlickrPhotosSetTagsError_FormatXXXNotFound = 111,		 /* The requested response format was not found. */
	FKFlickrPhotosSetTagsError_MethodXXXNotFound = 112,		 /* The requested method was not found. */
	FKFlickrPhotosSetTagsError_InvalidSOAPEnvelope = 114,		 /* The SOAP envelope send in the request could not be parsed. */
	FKFlickrPhotosSetTagsError_InvalidXMLRPCMethodCall = 115,		 /* The XML-RPC request document could not be parsed. */
	FKFlickrPhotosSetTagsError_BadURLFound = 116,		 /* One or more arguments contained a URL that has been used for abuse on Flickr. */

};

/*

Set the tags for a photo.




*/
@interface FKFlickrPhotosSetTags : NSObject <FKFlickrAPIMethod>

/* The id of the photo to set tags for.
 */
@property (nonatomic, copy) NSString *photo_id; /* (Required) */

/* All tags for the photo (as a single space-delimited string). */
@property (nonatomic, copy) NSString *tags; /* (Required) */


@end
