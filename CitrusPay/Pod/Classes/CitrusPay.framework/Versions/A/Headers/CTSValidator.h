//
//  CTSValidator.h
//  CTS iOS Sdk
//
//  Created by Yadnesh Wankhede on 30/06/15.
//  Copyright (c) 2015 Citrus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CTSError.h"
typedef enum {
    LengthMax255,
    LengthNonZero,
    NonNil,
    NoSpecialChars,
    NoWhiteSpace,
    NoNumber,
    NoChars,
    OnlyNumber,
    OnlyChars,
    OnlyAlphaNumeric,
    NoOnlyWhiteSpaces,
}ValidationTypes;




@interface CTSValidator : NSObject
-(instancetype)sharedInstance;
-(NSError*)validateField:(NSString *)sring for:(NSArray *)validations;


-(NSError *)validateField:(NSString *)sring for:(NSArray *)validations forError:(CTSErrorCode)errorCode;
@end
