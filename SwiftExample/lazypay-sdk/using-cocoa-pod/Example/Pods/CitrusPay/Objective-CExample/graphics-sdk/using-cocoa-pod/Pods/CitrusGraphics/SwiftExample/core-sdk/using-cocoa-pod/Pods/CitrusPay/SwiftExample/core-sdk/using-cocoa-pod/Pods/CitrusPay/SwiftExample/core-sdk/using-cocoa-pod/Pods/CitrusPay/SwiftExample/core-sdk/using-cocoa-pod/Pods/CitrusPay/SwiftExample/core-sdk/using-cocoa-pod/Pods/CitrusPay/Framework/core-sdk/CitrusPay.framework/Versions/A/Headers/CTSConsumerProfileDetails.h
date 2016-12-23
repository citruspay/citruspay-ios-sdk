//
//  CTSConsumerProfileDetails.h
//  CitrusPay
//
//  Created by Mukesh Patil on 1/27/16.
//  Copyright © 2016 CitrusPay. All rights reserved.
//

#import "JSONModel.h"

@interface CTSConsumerProfileDetails : JSONModel
@property (strong) NSString <Optional>
* paymentMode,
* name,
* savedCardToken,
* cardNumber,
* cardExpiryDate,
* bank,
* cardScheme,
* issuerCode,
* amount,
* currency,
* maxBalance,
* campaignCode,
* cvv,
* fingerPrint;

@property (assign) BOOL
selected,
shown,
defaultPaymentMode;

- (BOOL)canDoOneTapPayment;
@end
