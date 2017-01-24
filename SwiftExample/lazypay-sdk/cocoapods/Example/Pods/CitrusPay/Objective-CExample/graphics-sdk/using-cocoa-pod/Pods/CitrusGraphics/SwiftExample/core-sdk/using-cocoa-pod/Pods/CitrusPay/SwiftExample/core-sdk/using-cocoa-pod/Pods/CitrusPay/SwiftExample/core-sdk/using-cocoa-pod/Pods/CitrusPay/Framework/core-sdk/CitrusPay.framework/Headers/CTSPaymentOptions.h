//
//  CTSPaymentOptions.h
//  CitrusPay
//
//  Created by Mukesh Patil on 1/28/16.
//  Copyright © 2016 CitrusPay. All rights reserved.
//

#import <JSONModel/JSONModel.h>

#import "CTSError.h"
#import "CTSConsumerProfileDetails.h"
#import "CTSPaymentDetailUpdate.h"

@interface CTSPaymentOptions : JSONModel
/*!
 *  @brief The CTSPaymentOptions class' paymentMode, name, cardNumber, cardExpiryDate, cardScheme, amount, currency, cvv, bank, issuerCode, campaignCode, savedCardToken, maxBalance object.
 */
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

/*!
 *  @brief creditCardOption.
 *
 *  @param cardNumber     The CardNumber NSString.
 *  @param cardExpiryDate The CardExpiryDate NSString.
 *  @param cvv            The CVV NSString.
 *
 *  @return The CTSPaymentOptions Object.
 */
+ (CTSPaymentOptions *)creditCardOption:(NSString *)cardNumber
                         cardExpiryDate:(NSString *)cardExpiryDate
                                    cvv:(NSString *)cvv;

/*!
 *  @brief debitCardOption.
 *
 *  @param cardNumber     The CardNumber NSString.
 *  @param cardExpiryDate The CardExpiryDate NSString.
 *  @param cvv            The CVV NSString.
 *
 *  @return The CTSPaymentOptions Object.
 */
+ (CTSPaymentOptions *)debitCardOption:(NSString *)cardNumber
                        cardExpiryDate:(NSString *)cardExpiryDate
                                   cvv:(NSString *)cvv;

/*!
 *  @brief netBankingOption.
 *
 *  @param bank       The Bank NSString.
 *  @param issuerCode The IssuerCode NSString.
 *
 *  @return The CTSPaymentOptions Object.
 */
+ (CTSPaymentOptions *)netBankingOption:(NSString *)bank
                             issuerCode:(NSString *)issuerCode;

/*!
 *  @brief creditCardTokenized.
 *
 *  @param paymentDetails The PaymentDetails CTSConsumerProfileDetails.
 *
 *  @return The CTSPaymentOptions Object.
 */
+ (CTSPaymentOptions *)creditCardTokenized:(CTSConsumerProfileDetails *)paymentDetails;

/*!
 *  @brief debitCardTokenized.
 *
 *  @param paymentDetails The PaymentDetails CTSConsumerProfileDetails.
 *
 *  @return The CTSPaymentOptions Object.
 */
+ (CTSPaymentOptions *)debitCardTokenized:(CTSConsumerProfileDetails *)paymentDetails;

/*!
 *  @brief netBankingTokenized.
 *
 *  @param paymentDetails The PaymentDetails CTSConsumerProfileDetails.
 *
 *  @return The CTSPaymentOptions Object.
 */
+ (CTSPaymentOptions *)netBankingTokenized:(CTSConsumerProfileDetails *)paymentDetails;

/*!
 *  @brief prepaidOption.
 *
 *  @return The CTSPaymentOptions Object.
 */
+ (CTSPaymentOptions *)prepaidOption;
/*!
 *  @brief MVCOption
 *
 *  @param campaignCode MVCOption.
 *
 *  @return The CTSPaymentOptions Object.
 */
+ (CTSPaymentOptions *)MVCOption:(NSString *)campaignCode;

/*!
 *  @brief setTransactionAmount.
 *
 *  @param amount The Amount NSString.
 */
- (void)setTransactionAmount:(NSString *)amount;

/*!
 *  @brief validatePaymentInfo.
 *
 *  @return The CTSErrorCode Object.
 */
- (CTSErrorCode)validatePaymentInfo;

/*!
 *  @brief isTokenized.
 *
 *  @return The BOOL Object.
 */
- (BOOL)isTokenized;

/*!
 *  @brief toCTSPaymentDetailUpdate.
 *
 *  @return The CTSPaymentDetailUpdate Object.
 */
- (CTSPaymentDetailUpdate *)toCTSPaymentDetailUpdate;

/*!
 *  @brief canDoOneTapPayment.
 *
 *  @return The BOOL Object.
 */
- (BOOL)canDoOneTapPayment;
@end
