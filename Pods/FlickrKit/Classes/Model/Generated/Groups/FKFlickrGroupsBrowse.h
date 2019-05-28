//
//  FKFlickrGroupsBrowse.h
//  FlickrKit
//
//  Generated by FKAPIBuilder.
//  Copyright (c) 2013 DevedUp Ltd. All rights reserved. http://www.devedup.com
//
//  DO NOT MODIFY THIS FILE - IT IS MACHINE GENERATED


#import "FKFlickrAPIMethod.h"

typedef NS_ENUM(NSInteger, FKFlickrGroupsBrowseError) {
	FKFlickrGroupsBrowseError_CategoryNotFound = 1,		 /* The value passed for cat_id was not a valid category id. */
	FKFlickrGroupsBrowseError_SSLIsRequired = 95,		 /* SSL is required to access the Flickr API. */
	FKFlickrGroupsBrowseError_InvalidSignature = 96,		 /* The passed signature was invalid. */
	FKFlickrGroupsBrowseError_MissingSignature = 97,		 /* The call required signing but no signature was sent. */
	FKFlickrGroupsBrowseError_LoginFailedOrInvalidAuthToken = 98,		 /* The login details or auth token passed were invalid. */
	FKFlickrGroupsBrowseError_UserNotLoggedInOrInsufficientPermissions = 99,		 /* The method requires user authentication but the user was not logged in, or the authenticated method call did not have the required permissions. */
	FKFlickrGroupsBrowseError_InvalidAPIKey = 100,		 /* The API key passed was not valid or has expired. */
	FKFlickrGroupsBrowseError_ServiceCurrentlyUnavailable = 105,		 /* The requested service is temporarily unavailable. */
	FKFlickrGroupsBrowseError_WriteOperationFailed = 106,		 /* The requested operation failed due to a temporary issue. */
	FKFlickrGroupsBrowseError_FormatXXXNotFound = 111,		 /* The requested response format was not found. */
	FKFlickrGroupsBrowseError_MethodXXXNotFound = 112,		 /* The requested method was not found. */
	FKFlickrGroupsBrowseError_InvalidSOAPEnvelope = 114,		 /* The SOAP envelope send in the request could not be parsed. */
	FKFlickrGroupsBrowseError_InvalidXMLRPCMethodCall = 115,		 /* The XML-RPC request document could not be parsed. */
	FKFlickrGroupsBrowseError_BadURLFound = 116,		 /* One or more arguments contained a URL that has been used for abuse on Flickr. */

};

/*

Browse the group category tree, finding groups and sub-categories.

<p>The <code>count</code> attribute of the <code>subcat</code> element gives the number of groups inside the subcat.</p>

<p>The <code>members</code> attribute of the <code>group</code> element gives the total number of members in the group. The <code>online</code> attribute gives a count of the members who are currently online. The <code>inchat</code> attribute gives a count of the number of people in the group's chat, regardless of whether they are members of the group.</p>

Response:

<category name="Alt" path="/Alt" pathids="/63">
	<subcat id="80" name="18+" count="0" /> 
	<subcat id="82" name="Absurd" count="4" /> 
	<group nsid="34955637532@N01" name="Cal's Public Test Group"
		members="13" online="1" chatnsid="34955637533@N01" inchat="0" /> 
	<group nsid="34158032587@N01" name="Eric's Alt Group Test"
		members="3" online="0" chatnsid="34158032588@N01" inchat="0" /> 
</category>


*/
@interface FKFlickrGroupsBrowse : NSObject <FKFlickrAPIMethod>

/* The category id to fetch a list of groups and sub-categories for. If not specified, it defaults to zero, the root of the category tree. */
@property (nonatomic, copy) NSString *cat_id;


@end
