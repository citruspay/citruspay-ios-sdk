//
//  CTSConsumerProfileDetails.h
//  CitrusPay
//
//  Created by Mukesh Patil on 1/27/16.
//  Copyright © 2016 CitrusPay. All rights reserved.
//

#import <JSONModel/JSONModel.h>

@interface CTSConsumerProfileDetails : JSONModel
/*!
 *  @brief The CTSConsumerProfileDetails class' paymentMode, name, savedCardToken, cardNumber, cardExpiryDate, bank, cardScheme, issuerCode, amount, currency, maxBalance, campaignCode, cvv, fingerPrint object.
 */
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

/*!
 *  @brief The CTSConsumerProfileDetails class' selected, shown, defaultPaymentMode object.
 */
@property (assign) BOOL
selected,
shown,
defaultPaymentMode;

/*!
 *  @brief canDoOneTapPayment.
 *
 *  @return The BOOL Object.
 */
- (BOOL)canDoOneTapPayment;
@end
