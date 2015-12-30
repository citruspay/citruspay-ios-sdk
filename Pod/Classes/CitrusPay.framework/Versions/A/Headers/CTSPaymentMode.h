//
//  CTSPaymentMode.h
//  RestFulltester
//
//  Created by Raji Nair on 24/06/14.
//  Copyright (c) 2014 Citrus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"
@interface CTSPaymentMode : JSONModel
@property(strong) NSString<Optional>* cvv;
@property(strong) NSString<Optional>* expiry;
@property(strong) NSString<Optional>* holder;
@property(strong) NSString<Optional>* number;
@property(strong) NSString<Optional>* scheme;
@property(strong) NSString<Optional>* type;
@property(strong) NSString<Optional>* code;
@property(strong) NSString<Optional>* tokenid;

@end
