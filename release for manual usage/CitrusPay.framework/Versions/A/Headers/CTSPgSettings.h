//
//  CTSPgSettings.h
//  CTS iOS Sdk
//
//  Created by Yadnesh Wankhede on 09/07/14.
//  Copyright (c) 2014 Citrus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"
@interface CTSPgSettings : JSONModel
@property(  strong) NSMutableArray* creditCard;
@property(  strong) NSMutableArray* debitCard;
@property(  strong) NSMutableArray* netBanking;
@end
