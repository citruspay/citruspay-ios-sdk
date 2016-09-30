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

/*!
 *  @brief CTSEnvironment constant.
 */
typedef enum{
    CTSEnvSandbox,
    CTSEnvProduction
} CTSEnvironment;

@interface CitrusPaymentSDK : NSObject
/*!
 *  @brief Initialize SDK With KeyStore.
 *
 *  @param keyStore The signinId String, signUpId String, signinSecret String, signUpSecret String and vanity String.
 *  @param env The CTSEnvSandbox or CTSEnvProduction.
 */
+(void)initializeWithKeyStore:(CTSKeyStore *)keyStore
                  environment:(CTSEnvironment)env;

/*!
 *  @brief Initialize SDK With KeyStore.
 *
 *  @param keyStore The signinId String, signUpId String, signinSecret String, signUpSecret String and vanity String.
 *  @param envPlist The CTSEnvSandbox or CTSEnvProduction.
 */
+(void)initializeWithKeyStore:(CTSKeyStore *)keyStore
              environmentPath:(NSString *)envPlist;

/*!
 *  @brief Get the SDK version.
 *
 *  @return The SDK version string.
 */
+(NSString *)sdkVersion;


/*!
 *  @brief Fetch Shared AuthLayer.
 *
 *  @return The AuthLayer object.
 */
+(CTSAuthLayer *)fetchSharedAuthLayer;


/*!
 *  @brief Fetch Shared ProfileLayer.
 *
 *  @return The ProfileLayer object.
 */
+(CTSProfileLayer *)fetchSharedProfileLayer;


/*!
 *  @brief Fetch Shared PaymentLayer.
 *
 *  @return The PaymentLayer object.
 */
+(CTSPaymentLayer *)fetchSharedPaymentLayer;


/*!
 *  @brief Enable DEBUGLogs.
 */
+ (void)enableDEBUGLogs;


/*!
 *  @brief Disable OneTapPayment.
 */
+(void)disableOneTapPayment;


/*!
 *  @brief Enable OneTapPayment.
 */
+(void)enableOneTapPayment;


/*!
 *  @brief Check OneTap Payment Enabled.
 *
 *  @return The BOOL Value.
 */
+(BOOL)isOneTapPaymentEnabled;

/*!
 *  @brief Enable Push ViewController.
 */
+(void)enablePush;


/*!
 *  @brief Disable Push ViewController.
 */
+(void)disablePush;


/*!
 *  @brief Check is Push Enabled.
 *
 *  @return The BOOL Value.
 */
+(BOOL)isPushEnabled;


/*!
 *  @brief Disable Loader.
 */
+(void)disableLoader;


/*!
 *  @brief Enable Loader.
 */
+(void)enableLoader;


/*!
 *  @brief Check is Loader Enabled.
 *
 *  @return The BOOL Value.
 */
+(BOOL)isLoaderEnabled;


/*!
 *  @brief Set Loader Color.
 *
 *  @param loaderColor Passed Loader color.
 */
+(void)setLoaderColor:(UIColor *)loaderColor;


/*!
 *  @brief Get Loader Color.
 *
 *  @return Show the color passed in.
 */
+(UIColor *)getLoaderColor;


/*!
 *  @brief Check is Blaze Card Payment Enabled.
 *
 *  @return The BOOL Value.
 */
+ (BOOL)isBlazeCardPaymentEnabled;


/*!
 *  @brief Enable Blaze Card Payment.
 */
+ (void)enableBlazeCardPayment;


/*!
 *  @brief Disable Blaze Card Payment.
 */
+ (void)disableBlazeCardPayment;


/*!
 *  @brief Check is Blaze Net Payment Enabled.
 *
 *  @return The BOOL Value.
 */
+ (BOOL)isBlazeNetPaymentEnabled;


/*!
 *  @brief Enable Blaze Net Payment.
 */
+ (void)enableBlazeNetPayment;

/*!
 *  @brief Disable Blaze Net Payment.
 */
+ (void)disableBlazeNetPayment;

@end