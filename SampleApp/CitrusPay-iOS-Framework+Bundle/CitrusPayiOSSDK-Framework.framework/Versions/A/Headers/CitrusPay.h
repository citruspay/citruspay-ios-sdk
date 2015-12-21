//
//  CitrusPay.h
//  CTS iOS Sdk
//
//  Created by Yadnesh on 9/14/15.
//  Copyright (c) 2015 Citrus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CTSDataCache.h"
#import "CTSKeyStore.h"
#import "CTSAuthLayer.h"
#import "CTSProfileLayer.h"
#import "CTSPaymentLayer.h"

typedef enum{
    CTSEnvSandbox,
    CTSEnvProduction
} CTSEnvironment;


@interface CitrusPaymentSDK : NSObject
//urls
//key store

+(void)initializeWithKeyStore:(CTSKeyStore *)keyStore environment:(CTSEnvironment)env;
+(void)initializeWithKeyStore:(CTSKeyStore *)keyStore environmentPath:(NSString *)envPlist;
+(NSString *)sdkVersion;
+(CTSAuthLayer *)fetchSharedAuthLayer;
+(CTSProfileLayer *)fetchSharedProfileLayer;
+(CTSPaymentLayer *)fetchSharedPaymentLayer;
@end
