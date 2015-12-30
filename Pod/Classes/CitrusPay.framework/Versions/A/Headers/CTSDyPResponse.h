//
//  CTSDyPResponse.h
//  CTS iOS Sdk
//
//  Created by Yadnesh on 7/27/15.
//  Copyright (c) 2015 Citrus. All rights reserved.
//

#import "JSONModel.h"
#import "CTSAmount.h"

@interface CTSDyPResponse : JSONModel
@property(assign)int resultCode;
@property(strong) CTSAmount<Optional> *alteredAmount,*originalAmount;
@property(strong)NSString<Optional> *resultMessage,*offerToken;
@property(strong)NSDictionary<Optional> *extraParams;
-(BOOL)isError;
@end
