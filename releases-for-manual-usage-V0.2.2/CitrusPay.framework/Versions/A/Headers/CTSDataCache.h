//
//  CTSDataCache.h
//  CTS iOS Sdk
//
//  Created by Yadnesh on 8/31/15.
//  Copyright (c) 2015 Citrus. All rights reserved.
//

#import <Foundation/Foundation.h>

#define CACHE_KEY_KEY_STORE @"CTSKeyStore"
#define CACHE_KEY_ENV @"CTSEnv"
#define BASE_URL @"BASE_URL"
#define DP_BASE_URL @"DP_BASE_URL"
#define NEW_PAYMENT_BASE_URL @"NEW_PAYMENT_BASE_URL"
#define BANK_LOGO_KEY @"BANK_LOGO_KEY"
#define SCHEME_LOGO_KEY @"SCHEME_LOGO_KEY"
#define CACHE_KEY_DP_BILL @"dpBill"
#define CACHE_KEY_DP_RESPONSE @"dpResponse"
#define CACHE_KEY_DP_PAYMENT_INFO @"dpPayMentInfo"
#define CACHE_KEY_DP_USER_INFO @"dpUserInfo"
#define CACHE_KEY_DP_BILL @"dpBill"
#define CACHE_KEY_CITRUS_LINK @"CitrusLinkResp"

@interface CTSDataCache : NSObject
@property(strong)NSMutableDictionary *cache;
+ (id)sharedCache;
- (void)cacheData:(id)object key:(NSString *)index;
- (id)fetchCachedDataForKey:(NSString *)index ;
- (id)fetchAndRemovedCachedDataForKey:(NSString *)index;
@end
