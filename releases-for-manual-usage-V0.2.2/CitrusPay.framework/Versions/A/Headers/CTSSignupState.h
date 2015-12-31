//
//  SignupState.h
//  CTS iOS Sdk
//
//  Created by Yadnesh Wankhede on 10/09/14.
//  Copyright (c) 2014 Citrus. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CTSSignupState : NSObject
@property(strong) NSString* email, *mobile, *password;

- (instancetype)initWithEmail:(NSString*)email
                       mobile:(NSString*)mobile
                     password:(NSString*)password;
@end
