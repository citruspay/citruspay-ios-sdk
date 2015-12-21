//
//  CTSRestCore.h
//  CTSRestKit
//
//  Created by Yadnesh Wankhede on 29/07/14.
//  Copyright (c) 2014 CitrusPay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CTSRestCoreRequest.h"
#import "CTSRestCoreResponse.h"
#import "CTSRestCoreConstants.h"
#import "CTSError.h"
#import "UserLogging.h"

#define PGHEALTH_PRODUCTION_BASEURL @"https://citruspay.com"
#define PGHEALTH_SANDBOX_BASEURL @"https://sandbox.citruspay.com"

#define PRODUCTION_BASEURL @"https://admin.citruspay.com"

@class CTSRestCore;
@protocol CTSRestCoreDelegate
- (void)restCore:(CTSRestCore*)restCore
    didReceiveResponse:(CTSRestCoreResponse*)response;
@end

@interface CTSRestCore : NSObject{
    int delegationRequestId;
    BOOL finished;
}
@property(strong) NSString* baseUrl;
@property(weak) id<CTSRestCoreDelegate> delegate;


typedef void (^ASCTSRestResponse)(CTSRestCoreResponse* response);


- (instancetype)initWithBaseUrl:(NSString*)url;
- (void)requestAsyncServer:(CTSRestCoreRequest*)restRequest;
+ (CTSRestCoreResponse*)requestSyncServer:(CTSRestCoreRequest*)restRequest
                              withBaseUrl:(NSString*)baseUrl;
+ (NSString*)serializeParams:(NSDictionary*)params ;
-(void)requestAsyncServerDelegation:(CTSRestCoreRequest *)restRequest;
+ (NSMutableURLRequest*)requestByAddingParameters:(NSMutableURLRequest*)request
                                       parameters:(NSDictionary*)parameters;
-(void)requestAsyncServer:(CTSRestCoreRequest *)restRequest completion:(ASCTSRestResponse)callback;

//Vikas
+ (NSMutableURLRequest*)requestByAddingParameters:(NSMutableURLRequest*)request
                              withSerializeString:(NSString*)string;
@end
