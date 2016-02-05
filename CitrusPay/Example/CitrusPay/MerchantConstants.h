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
#define SignInId @"test-signin"
#define SignInSecretKey @"52f7e15efd4208cf5345dd554443fd99"
#define SubscriptionId @"test-signup"
#define SubscriptionSecretKey @"c78ec84e389814a05d3ae46546d16d2e"

/*
 set Vanity/bill/return url
 */
#define VanityUrl @"nativeSDK"
#define LoadWalletReturnUrl @"https://salty-plateau-1529.herokuapp.com/redirectURL.sandbox.php"
#define BillUrl @"https://salty-plateau-1529.herokuapp.com/billGenerator.sandbox.php"

#endif
