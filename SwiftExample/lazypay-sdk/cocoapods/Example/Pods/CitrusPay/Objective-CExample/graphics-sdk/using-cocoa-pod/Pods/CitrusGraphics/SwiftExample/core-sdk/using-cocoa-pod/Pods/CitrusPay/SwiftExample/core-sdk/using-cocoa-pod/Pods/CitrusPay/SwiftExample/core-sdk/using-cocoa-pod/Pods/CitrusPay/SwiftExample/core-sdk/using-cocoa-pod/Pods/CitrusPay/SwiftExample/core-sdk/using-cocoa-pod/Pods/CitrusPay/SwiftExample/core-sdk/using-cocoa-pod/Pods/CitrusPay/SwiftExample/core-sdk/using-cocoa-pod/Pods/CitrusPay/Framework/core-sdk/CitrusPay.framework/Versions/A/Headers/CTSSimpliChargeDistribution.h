//
//  CTSSimpliChargeDistribution.h
//  CitrusPay
//
//  Created by Mukesh Patil on 5/13/16.
//  Copyright © 2016 CitrusPay. All rights reserved.
//

#import "JSONModel.h"


@interface CTSSimpliChargeDistribution : JSONModel
@property (strong) NSString <Optional>
* mvcAmount,
* cashAmount,
* remainingAmount,
* totalAmount;
@property (assign) BOOL useMVC, useCash, enoughMVCAndCash;
@end
