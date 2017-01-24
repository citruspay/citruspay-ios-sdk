//
//  CTSConsumerProfile.h
//  CitrusPay
//
//  Created by Mukesh Patil on 1/27/16.
//  Copyright © 2016 CitrusPay. All rights reserved.
//

#import <JSONModel/JSONModel.h>

#import "CTSConsumerProfileDetails.h"

@class CTSUserDetails;

@interface CTSConsumerProfile : JSONModel
/*!
 *  @brief The CTSConsumerProfile class' merchantAccessKey, username, amount, currency, statusMsg object.
 */
@property (strong) NSString <Optional>
* merchantAccessKey,
* username,
* amount,
* currency,
* statusMsg;
/*!
 *  @brief The CTSConsumerProfile class' userDetails object.
 */
@property (strong) CTSUserDetails * userDetails;
/*!
 *  @brief The CTSConsumerProfile class' paymentOptionsList object.
 */
@property( strong) NSMutableArray<CTSConsumerProfileDetails *>* paymentOptionsList;

/*!
 *  @brief getSavedNBPaymentOptions.
 *
 *  @return The NSArray Object.
 */
- (NSArray *)getSavedNBPaymentOptions;
/*!
 *  @brief getSavedCCPaymentOptions.
 *
 *  @return The NSArray Object.
 */
- (NSArray *)getSavedCCPaymentOptions;
/*!
 *  @brief getSavedDCPaymentOptions
 *
 *  @return The NSArray Object..
 */
- (NSArray *)getSavedDCPaymentOptions;

/*!
 *  @brief getMVCAmount.
 *
 *  @return The NSString Object.
 */
- (NSString *)getMVCAmount;
/*!
 *  @brief getMVCMaxBalance.
 *
 *  @return The NSString Object.
 */
- (NSString *)getMVCMaxBalance;
/*!
 *  @brief getCampaignCode.
 *
 *  @return The NSString Object.
 */
- (NSString *)getCampaignCode;
/*!
 *  @brief getCashAmount.
 *
 *  @return The NSString Object.
 */
- (NSString *)getCashAmount;
/*!
 *  @brief getCashMaxBalance.
 *
 *  @return The NSString Object.
 */
- (NSString *)getCashMaxBalance;
@end
