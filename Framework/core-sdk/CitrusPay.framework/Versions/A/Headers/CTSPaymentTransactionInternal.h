//
//  CTSPaymentTransactionInternal.h
//  CitrusPay
//
//  Created by Mukesh Patil on 1/29/16.
//  Copyright © 2016 CitrusPay. All rights reserved.
//

#import "JSONModel.h"
#import "CTSTransactionMessage.h"

@interface CTSPaymentTransactionInternal : JSONModel
@property (strong) NSString <Optional> * redirectUrl, * responseCode, * txnStatus;
@property (strong) CTSTransactionMessage * txnMsg;
@end