//
//  CTSPaymentRes.h
//  RestFulltester
//
//  Created by Raji Nair on 20/06/14.
//  Copyright (c) 2014 Citrus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"
#import "CTSAmount.h"
@interface CTSPaymentRes : JSONModel
@property(strong) NSString* merchantTransactionId, *merchant, *customer,
    *description, *signature;
@property(strong) NSString<Optional>* redirectUrl;
@property(strong) CTSAmount* amount;
@end
