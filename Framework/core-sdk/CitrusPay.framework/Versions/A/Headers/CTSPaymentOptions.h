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
#import "CTSPaymentDetailUpdate.h"

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

+ (CTSPaymentOptions *)creditCardOption:(NSString *)cardNumber
                         cardExpiryDate:(NSString *)cardExpiryDate
                                    cvv:(NSString *)cvv;

+ (CTSPaymentOptions *)debitCardOption:(NSString *)cardNumber
                        cardExpiryDate:(NSString *)cardExpiryDate
                                   cvv:(NSString *)cvv;

+ (CTSPaymentOptions *)netBankingOption:(NSString *)bank
                             issuerCode:(NSString *)issuerCode;

+ (CTSPaymentOptions *)creditCardTokenized:(CTSConsumerProfileDetails *)paymentDetails;

+ (CTSPaymentOptions *)debitCardTokenized:(CTSConsumerProfileDetails *)paymentDetails;

+ (CTSPaymentOptions *)netBankingTokenized:(CTSConsumerProfileDetails *)paymentDetails;

+ (CTSPaymentOptions *)prepaidOption;
+ (CTSPaymentOptions *)MVCOption:(NSString *)campaignCode;

- (void)setTransactionAmount:(NSString *)amount;

- (CTSErrorCode)validatePaymentInfo;

- (BOOL)isTokenized;

- (CTSPaymentDetailUpdate *)toCTSPaymentDetailUpdate;

- (BOOL)canDoOneTapPayment;
@end
