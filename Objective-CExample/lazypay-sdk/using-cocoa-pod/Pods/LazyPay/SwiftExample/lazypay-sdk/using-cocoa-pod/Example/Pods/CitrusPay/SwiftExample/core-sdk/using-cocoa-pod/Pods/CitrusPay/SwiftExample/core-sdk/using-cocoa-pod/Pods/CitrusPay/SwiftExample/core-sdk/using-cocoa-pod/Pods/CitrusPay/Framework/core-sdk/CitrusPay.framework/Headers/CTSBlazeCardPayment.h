//
//  CTSBlazeCardPayment.h
//  CitrusPay
//
//  Created by Mukesh Patil on 2/23/16.
//  Copyright © 2016 CitrusPay. All rights reserved.
//

#import <JSONModel/JSONModel.h>

#import "CTSError.h"

@interface CTSBlazeCardPayment : JSONModel
/*!
 *  @brief The CTSBlazeCardPayment class' cardType, cardScheme, cardNo, cvv, expiry, savedCardToken, name object.
 */
@property (strong) NSString <Optional> * cardType, * cardScheme, * cardNo, * cvv, * expiry, * savedCardToken, * name;

/*!
 *  @brief initWithCreditCard
 *
 *  @return The CTSBlazeCardPayment Object.
 */
- (instancetype)initWithCreditCard;

/*!
 *  @brief initWithDebitCard
 *
 *  @return The CTSBlazeCardPayment Object.
 */
- (instancetype)initWithDebitCard;

/*!
 *  @brief isTokenizedCard
 *
 *  @return The BOOL Value.
 */
- (BOOL)isTokenizedCard;

/*!
 *  @brief validateTokenized
 *
 *  @return The CTSErrorCode Object.
 */
- (CTSErrorCode)validateTokenized;

/*!
 *  @brief validatePaymentInfo
 *
 *  @return The CTSErrorCode Object.
 */
- (CTSErrorCode)validatePaymentInfo;

/*!
 *  @brief doCardCorrectionsIfNeeded
 */
- (void)doCardCorrectionsIfNeeded;

@end
