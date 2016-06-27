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
 set your oauth keys
*/

#define SignInId @"9hh5re3r5q-signin"
#define SignInSecretKey @"ffcfaaf6e6e78c2f654791d9d6cb7f09"
#define SubscriptionId @"9hh5re3r5q-signup"
#define SubscriptionSecretKey @"3be4d7bf59c109e76a3619a33c1da9a8"

/*
 set your Vanity / Bill / Return URL
*/
#define VanityUrl @"nativeSDK"
#define LoadWalletReturnUrl @"https://salty-plateau-1529.herokuapp.com/redirectURL.sandbox.php"
#define BillUrl @"https://salty-plateau-1529.herokuapp.com/billGenerator.sandbox.php"

#endif
