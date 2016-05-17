//
//  CTSPaymentOptions.h
//  CitrusPay
//
//  Created by Mukesh Patil on 1/28/16.
//  Copyright © 2016 CitrusPay. All rights reserved.
//

#import "JSONModel.h"

#import "CTSError.h"
#import "CTSConsumerProfileDetails.h"

@interface CTSPaymentOptions : JSONModel
@property (strong) NSString <Optional>
* paymentMode,
* name,
* cardNumber,
* cardExpiryDate,
* cardScheme,
* amount,
* currency,
* cvv,
* bank,
* issuerCode,
* campaignCode,
* savedCardToken,
* maxBalance;

+ (CTSPaymentOptions *)CreditCardOption:(NSString *)cardNumber
                         cardExpiryDate:(NSString *)cardExpiryDate
                                    cvv:(NSString *)cvv;

+ (CTSPaymentOptions *)DebitCardOption:(NSString *)cardNumber
                        cardExpiryDate:(NSString *)cardExpiryDate
                                   cvv:(NSString *)cvv;

+ (CTSPaymentOptions *)NetBankingOption:(NSString *)bank
                             issuerCode:(NSString *)issuerCode;

+ (CTSPaymentOptions *)CreditCardTokenized:(CTSConsumerProfileDetails *)paymentDetails;

+ (CTSPaymentOptions *)DebitCardTokenized:(CTSConsumerProfileDetails *)paymentDetails;

+ (CTSPaymentOptions *)NetBankingTokenized:(CTSConsumerProfileDetails *)paymentDetails;

+ (CTSPaymentOptions *)PrepaidOption;
+ (CTSPaymentOptions *)MVCOption:(NSString *)campaignCode;

- (void)setTransactionAmount:(NSString *)amount;

- (CTSErrorCode)validatePaymentInfo;

@end
