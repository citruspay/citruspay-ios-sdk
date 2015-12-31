//
//  CTSTokenValidityRes.h
//  CTS iOS Sdk
//
//  Created by Yadnesh on 9/22/15.
//  Copyright (c) 2015 Citrus. All rights reserved.
//

#import "JSONModel.h"

@interface CTSTokenValidityRes : JSONModel
@property(strong)NSString<Optional> *expiration;
@property(strong)NSDate<Ignore> *expirationDate;

@end
