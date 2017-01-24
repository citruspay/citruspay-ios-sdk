//
//  CTSConsumerProfile.h
//  CitrusPay
//
//  Created by Mukesh Patil on 1/27/16.
//  Copyright © 2016 CitrusPay. All rights reserved.
//

#import "JSONModel.h"

#import "CTSConsumerProfileDetails.h"

@class CTSUserDetails;

@interface CTSConsumerProfile : JSONModel
@property (strong) NSString <Optional>
* merchantAccessKey,
* username,
* amount,
* currency,
* statusMsg;
@property (strong) CTSUserDetails * userDetails;
@property( strong) NSMutableArray<CTSConsumerProfileDetails *>* paymentOptionsList;

- (NSArray *)getSavedNBPaymentOptions;
- (NSArray *)getSavedCCPaymentOptions;
- (NSArray *)getSavedDCPaymentOptions;

- (NSString *)getMVCAmount;
- (NSString *)getMVCMaxBalance;
- (NSString *)getCampaignCode;
- (NSString *)getCashAmount;
- (NSString *)getCashMaxBalance;
@end
