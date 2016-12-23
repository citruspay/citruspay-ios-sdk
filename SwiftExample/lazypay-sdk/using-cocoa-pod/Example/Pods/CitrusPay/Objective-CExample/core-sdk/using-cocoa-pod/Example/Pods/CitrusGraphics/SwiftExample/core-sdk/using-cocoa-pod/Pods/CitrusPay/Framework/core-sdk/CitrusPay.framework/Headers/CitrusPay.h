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
#import "CTSOauthManager.h"
#import "HVDOverlay.h"

/**
 *   CTSEnvironment Constant.
 */
typedef enum{
    /**
     *   CTSEnvSandbox Constant.
     */
    CTSEnvSandbox,
    /**
     *   CTSEnvProduction Constant.
     */
    CTSEnvProduction
} CTSEnvironment;


/**
 *   CitrusPaymentSDK Singleton Class.
 */
@interface CitrusPaymentSDK : NSObject
/**
 *   Initialize SDK With KeyStore.
 *
 *  @param keyStore The signinId String, signUpId String, signinSecret String, signUpSecret String and vanity String.
 *  @param env The CTSEnvSandbox or CTSEnvProduction.
 */
+(void)initializeWithKeyStore:(CTSKeyStore *)keyStore
                  environment:(CTSEnvironment)env;

/**
 *   Initialize SDK With KeyStore.
 *
 *  @param keyStore The signinId String, signUpId String, signinSecret String, signUpSecret String and vanity String.
 *  @param envPlist The CTSEnvSandbox or CTSEnvProduction.
 */
+(void)initializeWithKeyStore:(CTSKeyStore *)keyStore
              environmentPath:(NSString *)envPlist;

/**
 *   Get the SDK version.
 *
 *  @return The SDK version string.
 */
+(NSString *)sdkVersion;


/**
 *   Fetch Shared AuthLayer.
 *
 *  @return The AuthLayer object.
 */
+(CTSAuthLayer *)fetchSharedAuthLayer;


/**
 *   Fetch Shared ProfileLayer.
 *
 *  @return The ProfileLayer object.
 */
+(CTSProfileLayer *)fetchSharedProfileLayer;


/**
 *   Fetch Shared PaymentLayer.
 *
 *  @return The PaymentLayer object.
 */
+(CTSPaymentLayer *)fetchSharedPaymentLayer;


/**
 *   Enable DEBUGLogs.
 */
+ (void)enableDEBUGLogs;


/**
 *   Disable OneTapPayment.
 */
+(void)disableOneTapPayment;


/**
 *   Enable OneTapPayment.
 */
+(void)enableOneTapPayment;


/**
 *   Check OneTap Payment Enabled.
 *
 *  @return The BOOL Value.
 */
+(BOOL)isOneTapPaymentEnabled;

/**
 *   Enable Push ViewController.
 */
+(void)enablePush;


/**
 *   Disable Push ViewController.
 */
+(void)disablePush;


/**
 *   Check is Push Enabled.
 *
 *  @return The BOOL Value.
 */
+(BOOL)isPushEnabled;


/**
 *   Disable Loader.
 */
+(void)disableLoader;


/**
 *   Enable Loader.
 */
+(void)enableLoader;


/**
 *   Check is Loader Enabled.
 *
 *  @return The BOOL Value.
 */
+(BOOL)isLoaderEnabled;


/**
 *   Set Loader Color.
 *
 *  @param loaderColor Passed Loader color.
 */
+(void)setLoaderColor:(UIColor *)loaderColor;


/**
 *   Get Loader Color.
 *
 *  @return Show the color passed in.
 */
+(UIColor *)getLoaderColor;


/**
 *   Check is Blaze Card Payment Enabled.
 *
 *  @return The BOOL Value.
 */
+ (BOOL)isBlazeCardPaymentEnabled;


/**
 *   Enable Blaze Card Payment.
 */
+ (void)enableBlazeCardPayment;


/**
 *   Disable Blaze Card Payment.
 */
+ (void)disableBlazeCardPayment;


/**
 *   Check is Blaze Net Payment Enabled.
 *
 *  @return The BOOL Value.
 */
+ (BOOL)isBlazeNetPaymentEnabled;


/**
 *   Enable Blaze Net Payment.
 */
+ (void)enableBlazeNetPayment;

/**
 *   Disable Blaze Net Payment.
 */
+ (void)disableBlazeNetPayment;

@end