//
//  CTSDataCache.h
//  CTS iOS Sdk
//
//  Created by Yadnesh on 8/31/15.
//  Copyright (c) 2015 Citrus. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const CACHE_KEY_KEY_STORE;
extern NSString * const CACHE_KEY_ENV;
extern NSString * const BASE_URL;
extern NSString * const DP_BASE_URL;
extern NSString * const NEW_PAYMENT_BASE_URL;
extern NSString * const BANK_LOGO_KEY;
extern NSString * const BANK_LOGO_WITH_BANK_NAME_KEY;
extern NSString * const SCHEME_LOGO_KEY;
extern NSString * const CACHE_KEY_DP_BILL;
extern NSString * const CACHE_KEY_DP_RESPONSE;
extern NSString * const CACHE_KEY_DP_PAYMENT_INFO;
extern NSString * const CACHE_KEY_DP_USER_INFO;
extern NSString * const CACHE_KEY_DP_BILL;
extern NSString * const CACHE_KEY_CITRUS_LINK;
extern NSString * const CACHE_KEY_ONE_TAP_PAYMENT;
extern NSString * const CACHE_KEY_PUSH_VIEW_CONTROLLER;
extern NSString * const CACHE_KEY_LOADER_OVERLAY;
extern NSString * const CACHE_KEY_LOADER_COLOR;
extern NSString * const CACHE_KEY_SAVED_PAYMENT_OPTIONS;
extern NSString * const CACHE_KEY_PG_SETTINGS;
extern NSString * const CACHE_KEY_MASTER_CITRUS_LINK;
extern NSString * const CACHE_KEY_LOAD_PG_SETTINGS;
extern NSString * const CACHE_KEY_IS_AUTO_LOAD_TX;
extern NSString * const CACHE_KEY_PREPAID_BILL;






extern NSString * const CACHE_KEY_BLAZECARD_PAYMENT;
extern NSString * const CACHE_KEY_BLAZENET_PAYMENT;


@interface CTSDataCache : NSObject
@property(strong)NSMutableDictionary *cache;
+ (id)sharedCache;
- (void)cacheData:(id)object key:(NSString *)index;
- (id)fetchCachedDataForKey:(NSString *)index ;
- (id)fetchAndRemovedCachedDataForKey:(NSString *)index;
@end
