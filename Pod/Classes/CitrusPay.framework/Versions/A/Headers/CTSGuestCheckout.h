//
//  CTSGuestCheckout.h
//  RestFulltester
//
//  Created by Raji Nair on 27/06/14.
//  Copyright (c) 2014 Citrus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"
@interface CTSGuestCheckout : JSONModel
@property( strong) NSString* returnUrl;
@property(strong) NSString<Optional>* expiryYear;
@property(strong) NSString<Optional>* amount;
@property(strong) NSString<Optional>* addressState;
@property(strong)NSString <Optional>*paymentMode;
@property(strong)NSString<Optional> *lastName;
@property(strong)NSString <Optional>*addressCity;
@property(strong)NSString <Optional>*address;
@property(strong)NSString <Optional>*email;
@property(strong)NSString <Optional>*cardHolderName;
@property(strong)NSString<Optional>*firstName;
@property(strong)NSString<Optional> *cvvNumber;
@property(strong)NSString <Optional>*cardType;
@property(strong)NSString<Optional>*issuerCode;
@property(strong)NSString <Optional>*merchantTxnId;
@property(strong)NSString<Optional>*addressZip;
@property(strong)NSString<Optional>*expiryMonth;
@property(strong)NSString<Optional>*mobile, *cardNumber;

@end
