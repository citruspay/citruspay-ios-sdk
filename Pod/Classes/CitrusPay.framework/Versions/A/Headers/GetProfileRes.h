//
//  GetProfileRes.h
//  RestFulltester
//
//  Created by Yadnesh Wankhede on 04/06/14.
//  Copyright (c) 2014 Citrus. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "NSObject+logProperties.h"

@interface GetProfileRes : NSObject
@property( strong) NSString* mobileMoneyId;
@property( strong) NSString* scheme;
@property( strong) NSString* token;
@property( strong) NSString* expiryDate;
@property( strong) NSString* name;
@property( strong) NSString* owner;
@property( strong) NSString* bank;
@property( strong) NSString* accountNumber;
@property( strong) NSString* impsRegisteredMobile;


@end
