//
//  MerchantConstants.h
//  CTS iOS Sdk
//
//  Created by Yadnesh Wankhede on 13/08/14.
//  Copyright (c) 2014 Citrus. All rights reserved.
//


#ifndef CTS_iOS_Sdk_MerchantConstants_h
#define CTS_iOS_Sdk_MerchantConstants_h

#warning "set your own oauth keys and urls to see testing results"

/*
 set oauth keys
*/

// Sandbox
#define SignInId_Sandbox @"9hh5re3r5q-signin"
#define SignInSecretKey_Sandbox @"ffcfaaf6e6e78c2f654791d9d6cb7f09"
#define SubscriptionId_Sandbox @"9hh5re3r5q-signup"
#define SubscriptionSecretKey_Sandbox @"3be4d7bf59c109e76a3619a33c1da9a8"

#define VanityUrl_Sandbox @"nativeSDK"
#define BillUrl_Sandbox @"https://salty-plateau-1529.herokuapp.com/billGenerator.sandbox.php"
#define ReturnUrl_Sandbox @"https://salty-plateau-1529.herokuapp.com/redirectURL.sandbox.php"

// Production
#define SignInId_Production @"kkizp9tsqg-signin"
#define SignInSecretKey_Production @"1fc1f57639ec87cf4d49920f6b3a2c9d"
#define SubscriptionId_Production @"kkizp9tsqg-signup"
#define SubscriptionSecretKey_Production @"39c50a32eaabaf382223fdd05f331e1c"

#define VanityUrl_Production @"testing"
#define BillUrl_Production @"https://salty-plateau-1529.herokuapp.com/billGenerator.production.php"
#define ReturnUrl_Production @"https://salty-plateau-1529.herokuapp.com/redirectURL.production.php"

#endif
