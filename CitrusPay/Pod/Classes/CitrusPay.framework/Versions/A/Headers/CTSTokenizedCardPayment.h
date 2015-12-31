//
//  CTSTokenizedCardPayment.h
//  RestFulltester
//
//  Created by Raji Nair on 30/06/14.
//  Copyright (c) 2014 Citrus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CTSAmount.h"
#import "CTSUserDetails.h"
#import "CTSPaymentToken.h"
#import "JSONModel.h"

@interface CTSTokenizedCardPayment : JSONModel
@property(strong) CTSAmount* amount;
@property(strong) NSString<Optional>* merchantAccessKey;
@property(strong) NSString<Optional>* merchantTxnId;
@property(strong) NSString<Optional>* notifyUrl;
@property(strong) NSString<Optional>* requestSignature;
@property(strong) NSString<Optional>* returnUrl;
@property(strong) NSString<Optional>* merchant;
@property(strong) NSString<Optional>* merchantKey;
@property(strong) CTSUserDetails<Optional>* userDetails;
@property(strong) CTSPaymentToken<Optional>* paymentToken;
@end
