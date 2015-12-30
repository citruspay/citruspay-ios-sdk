//
//  CTSTokenizedPaymentToken.h
//  CTS iOS Sdk
//
//  Created by Raji Nair on 07/08/14.
//  Copyright (c) 2014 Citrus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"
@interface CTSTokenizedPaymentToken : JSONModel
@property(strong) NSString<Optional>* type;
@property(strong) NSString<Optional>* id;
@property(strong) NSString<Optional>* cvv;
@end
