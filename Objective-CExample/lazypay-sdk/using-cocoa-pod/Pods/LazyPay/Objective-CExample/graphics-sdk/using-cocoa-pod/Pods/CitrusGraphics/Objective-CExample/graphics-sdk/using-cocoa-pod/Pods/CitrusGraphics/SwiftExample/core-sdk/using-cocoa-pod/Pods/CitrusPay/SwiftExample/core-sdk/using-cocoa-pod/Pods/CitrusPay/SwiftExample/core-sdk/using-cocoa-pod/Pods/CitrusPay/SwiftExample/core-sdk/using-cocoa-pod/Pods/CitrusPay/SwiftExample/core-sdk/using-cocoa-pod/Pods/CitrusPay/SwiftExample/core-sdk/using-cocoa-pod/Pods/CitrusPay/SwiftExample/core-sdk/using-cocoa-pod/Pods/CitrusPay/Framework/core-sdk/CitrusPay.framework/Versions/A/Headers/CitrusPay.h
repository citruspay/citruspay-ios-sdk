//
//  CitrusPay.h
//  CTS iOS Sdk
//
//  Created by Yadnesh on 9/14/15.
//  Copyright (c) 2015 Citrus. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "Version.h"

// Layers
#import "CTSAuthLayer.h"
#import "CTSProfileLayer.h"
#import "CTSPaymentLayer.h"

// Models
#import "UIUtility.h"
#import "CTSCitrusLinkRes.h"
#import "CTSKeyStore.h"
#import "CTSDataCache.h"
#import "UserLogging.h"

typedef enum{
    CTSEnvSandbox,
    CTSEnvProduction
} CTSEnvironment;

@interface CitrusPaymentSDK : NSObject
+(void)initializeWithKeyStore:(CTSKeyStore *)keyStore environment:(CTSEnvironment)env;
+(void)initializeWithKeyStore:(CTSKeyStore *)keyStore environmentPath:(NSString *)envPlist;
+(NSString *)sdkVersion;
+(CTSAuthLayer *)fetchSharedAuthLayer;
+(CTSProfileLayer *)fetchSharedProfileLayer;
+(CTSPaymentLayer *)fetchSharedPaymentLayer;
+ (void)enableDEBUGLogs;
+(void)disableOneTapPayment;
+(void)enableOneTapPayment;
+(BOOL)isOneTapPaymentEnabled;
+(void)enablePush;
+(void)disablePush;
+(BOOL)isPushEnabled;
+(void)disableLoader;
+(void)enableLoader;
+(BOOL)isLoaderEnabled;
+(void)setLoaderColor:(UIColor *)loaderColor;
+(UIColor *)getLoaderColor;

/**
 *  @preturn BlazeCard enabled
 */
+ (BOOL)isBlazeCardPaymentEnabled;

/**
 *  @preturn set BlazeCard enabled
 */
+ (void)enableBlazeCardPayment;

/**
 *  @preturn BlazeCard disable
 */
+ (void)disableBlazeCardPayment;


/**
 *  @preturn BlazeNet enabled
 */
+ (BOOL)isBlazeNetPaymentEnabled;

/**
 *  @preturn set BlazeNet enabled
 */
+ (void)enableBlazeNetPayment;

/**
 *  @preturn BlazeNet disable
 */
+ (void)disableBlazeNetPayment;

@end
