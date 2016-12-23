//
//  CTSSimpliChargeDistribution.h
//  CitrusPay
//
//  Created by Mukesh Patil on 5/13/16.
//  Copyright © 2016 CitrusPay. All rights reserved.
//

#import <JSONModel/JSONModel.h>


@interface CTSSimpliChargeDistribution : JSONModel
/*!
 *  @brief The CTSBlazeNetError class' mvcAmount, cashAmount, remainingAmount, totalAmount object.
 */
@property (strong) NSString <Optional>
* mvcAmount,
* cashAmount,
* remainingAmount,
* totalAmount;
/*!
 *  @brief The CTSBlazeNetError class' useMVC, useCash, enoughMVCAndCash object.
 */
@property (assign) BOOL useMVC, useCash, enoughMVCAndCash;
@end
