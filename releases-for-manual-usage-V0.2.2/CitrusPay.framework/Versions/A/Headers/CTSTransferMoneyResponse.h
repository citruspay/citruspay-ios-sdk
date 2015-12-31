//
//  CTSTransferMoneyResponse.h
//  CTS iOS Sdk
//
//  Created by Yadnesh on 8/6/15.
//  Copyright (c) 2015 Citrus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"
#import "CTSAmount.h"

//{"id":"1483995","type":"SuspenseTransfer","date":1438846498173,"amount":{"value":1,"currency":"INR"},"operation":"debit","status":"SUCCESSFUL","narrative":"from YaddyBoy with Love","reason":null,"balance":{"value":2630.00,"currency":"INR"},"ref":"yaddyboy100@mailinator.com:monish.correia@mailinator.com"}

@interface CTSTransferMoneyResponse : JSONModel
@property(strong,atomic)NSString<Optional>* type,*date,*operation,*status,*narrative,*reason,*ref;
@property(strong,atomic)CTSAmount<Optional>* amount,*balance;

@end
