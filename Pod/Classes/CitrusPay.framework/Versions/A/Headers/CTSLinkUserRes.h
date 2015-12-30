//
//  CTSLinkUserRes.h
//  CTS iOS Sdk
//
//  Created by Yadnesh Wankhede on 25/02/15.
//  Copyright (c) 2015 Citrus. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CTSLinkUserRes : NSObject

@property(assign)BOOL isPasswordAlreadySet;
@property(strong)NSString *message;


- (instancetype)initPasswordAlreadyNotSet;
- (instancetype)initPasswordAlreadySet;
@end
