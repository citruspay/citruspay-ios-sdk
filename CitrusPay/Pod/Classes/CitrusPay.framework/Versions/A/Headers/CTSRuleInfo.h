//
//  CTSRuleInfo.h
//  CTS iOS Sdk
//
//  Created by Yadnesh on 9/1/15.
//  Copyright (c) 2015 Citrus. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef enum{
    DPRequestTypeValidate,
    DPRequestTypeCalculate,
    DPRequestTypeSearchAndApply,
}DPRequestType;
@interface CTSRuleInfo : NSObject
@property(strong)NSString *ruleName,*alteredAmount,*originalAmount;
@property(assign)DPRequestType operationType;
-(NSString *)toDpTypeString;
-(void)amountCorrections;
@end
