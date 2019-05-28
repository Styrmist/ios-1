//
//  FKFlickrUrlsLookupUser.m
//  FlickrKit
//
//  Generated by FKAPIBuilder.
//  Copyright (c) 2013 DevedUp Ltd. All rights reserved. http://www.devedup.com
//
//  DO NOT MODIFY THIS FILE - IT IS MACHINE GENERATED


#import "FKFlickrUrlsLookupUser.h" 

@implementation FKFlickrUrlsLookupUser



- (BOOL) needsLogin {
    return NO;
}

- (BOOL) needsSigning {
    return NO;
}

- (FKPermission) requiredPerms {
    return -1;
}

- (NSString *) name {
    return @"flickr.urls.lookupUser";
}

- (BOOL) isValid:(NSError **)error {
    BOOL valid = YES;
	NSMutableString *errorDescription = [[NSMutableString alloc] initWithString:@"You are missing required params: "];
	if(!self.url) {
		valid = NO;
		[errorDescription appendString:@"'url', "];
	}

	if(error != NULL) {
		if(!valid) {	
			NSDictionary *userInfo = @{NSLocalizedDescriptionKey: errorDescription};
			*error = [NSError errorWithDomain:FKFlickrKitErrorDomain code:FKErrorInvalidArgs userInfo:userInfo];
		}
	}
    return valid;
}

- (NSDictionary *) args {
    NSMutableDictionary *args = [NSMutableDictionary dictionary];
	if(self.url) {
		[args setValue:self.url forKey:@"url"];
	}

    return [args copy];
}

- (NSString *) descriptionForError:(NSInteger)error {
    switch(error) {
		case FKFlickrUrlsLookupUserError_UserNotFound:
			return @"User not found";
		case FKFlickrUrlsLookupUserError_InvalidAPIKey:
			return @"Invalid API Key";
		case FKFlickrUrlsLookupUserError_ServiceCurrentlyUnavailable:
			return @"Service currently unavailable";
		case FKFlickrUrlsLookupUserError_WriteOperationFailed:
			return @"Write operation failed";
		case FKFlickrUrlsLookupUserError_FormatXXXNotFound:
			return @"Format \"xxx\" not found";
		case FKFlickrUrlsLookupUserError_MethodXXXNotFound:
			return @"Method \"xxx\" not found";
		case FKFlickrUrlsLookupUserError_InvalidSOAPEnvelope:
			return @"Invalid SOAP envelope";
		case FKFlickrUrlsLookupUserError_InvalidXMLRPCMethodCall:
			return @"Invalid XML-RPC Method Call";
		case FKFlickrUrlsLookupUserError_BadURLFound:
			return @"Bad URL found";
  
		default:
			return @"Unknown error code";
    }
}

@end
