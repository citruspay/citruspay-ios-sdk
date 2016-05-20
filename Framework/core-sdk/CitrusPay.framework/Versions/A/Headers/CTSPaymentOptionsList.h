//
//  CTSPaymentOptionsList.h
//  CitrusPay
//
//  Created by Mukesh Patil on 1/28/16.
//  Copyright © 2016 CitrusPay. All rights reserved.
//

#import "JSONModel.h"
#import "CTSError.h"

#import "CTSPaymentOptions.h"
#import "CTSPaymentDetailUpdate.h"

@interface CTSPaymentOptionsList : JSONModel
@property (strong) NSMutableArray <CTSPaymentOptions *> * paymentOptions;

- (void)setTransactionAmount:(NSString *)amount
                  forPayment:(CTSPaymentOptions *)payment;

- (CTSErrorCode)validatePaymentInfo;

- (void)doCardCorrectionsIfNeeded;

- (BOOL)isTokenized;

- (CTSErrorCode)validateTokenized;

- (BOOL)validateBillAmountWithPaymentInfo:(NSString *)billAmount;

- (CTSPaymentDetailUpdate *)toCTSPaymentDetailUpdate;
@end