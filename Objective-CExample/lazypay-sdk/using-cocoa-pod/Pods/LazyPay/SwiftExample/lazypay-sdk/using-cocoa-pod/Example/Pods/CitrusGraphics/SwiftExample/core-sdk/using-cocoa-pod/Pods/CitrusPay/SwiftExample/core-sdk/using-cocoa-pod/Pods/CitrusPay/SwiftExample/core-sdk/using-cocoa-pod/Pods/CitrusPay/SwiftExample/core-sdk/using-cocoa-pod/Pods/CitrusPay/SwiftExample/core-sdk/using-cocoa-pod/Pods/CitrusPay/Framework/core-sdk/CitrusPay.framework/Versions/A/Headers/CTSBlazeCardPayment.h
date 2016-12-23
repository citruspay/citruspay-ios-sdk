//
//  CTSBlazeCardPayment.h
//  CitrusPay
//
//  Created by Mukesh Patil on 2/23/16.
//  Copyright © 2016 CitrusPay. All rights reserved.
//

#import "JSONModel.h"

#import "CTSError.h"

@interface CTSBlazeCardPayment : JSONModel
@property (strong) NSString <Optional> * cardType, * cardScheme, * cardNo, * cvv, * expiry, * savedCardToken, * name;

- (instancetype)initWithCreditCard;

- (instancetype)initWithDebitCard;

- (BOOL)isTokenizedCard;

- (CTSErrorCode)validateTokenized;

- (CTSErrorCode)validatePaymentInfo;

- (void)doCardCorrectionsIfNeeded;

@end
