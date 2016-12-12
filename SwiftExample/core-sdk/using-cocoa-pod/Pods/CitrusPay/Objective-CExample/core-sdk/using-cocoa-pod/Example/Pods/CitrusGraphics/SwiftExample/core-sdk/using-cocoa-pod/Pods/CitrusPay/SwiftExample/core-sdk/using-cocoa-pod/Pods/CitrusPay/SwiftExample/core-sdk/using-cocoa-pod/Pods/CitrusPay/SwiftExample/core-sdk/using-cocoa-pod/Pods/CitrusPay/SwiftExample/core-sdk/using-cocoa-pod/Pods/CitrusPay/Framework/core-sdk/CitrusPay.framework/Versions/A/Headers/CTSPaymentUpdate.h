//
//  CTSPaymentUpdate.h
//  RestFulltester
//
//  Created by Raji Nair on 21/06/14.
//  Copyright (c) 2014 Citrus. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CTSPaymentUpdate : NSObject
@property( strong) NSString* currency, *redirect, *amount, *returnUrl;

@end
