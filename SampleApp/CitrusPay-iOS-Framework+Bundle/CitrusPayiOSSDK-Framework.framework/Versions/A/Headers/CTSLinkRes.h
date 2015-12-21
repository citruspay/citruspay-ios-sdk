//
//  CTSLinkRes.h
//  CTS iOS Sdk
//
//  Created by Yadnesh Wankhede on 20/05/15.
//  Copyright (c) 2015 Citrus. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef enum {
    LinkUserStatusEotpSignIn,
    LinkUserStatusMotpSigIn,
    LinkUserStatusForceMobVerEotpSignin,
    LinkUserStatusSignup
} LinkUserStatus;
@interface CTSLinkRes : NSObject
@property(assign) LinkUserStatus linkUserStatus;
@property(assign) NSString* message;
- (instancetype)initWith:(LinkUserStatus)status entity:(NSString *)entity;

@end
