//
//  CTSCoreProtocol.h
//  CTS iOS Sdk
//
//  Created by Yadnesh Wankhede on 21/07/14.
//  Copyright (c) 2014 Citrus. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol CTSCoreProtocol<NSObject>
typedef enum {
  CTSNetworkStatusUnknown = -1,
  CTSNetworkStatusNotReachable = 0,
  CTSNetworkStatusReachableViaWWAN = 1,
  CTSNetworkStatusReachableViaWiFi = 2,
} CTSNetworkStatus;

/**
 *  whenever network status is changed this method gets called
 *
 *  @param networkStatus Enum defining various network states
 */
- (void)networkStatusChanged:(CTSNetworkStatus)networkStatus;

@end
