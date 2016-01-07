//
//  CTSContactUpdate.h
//  RestFulltester
//
//  Created by Yadnesh Wankhede on 12/06/14.
//  Copyright (c) 2014 Citrus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"

@class CTSProfileContactRes;

@interface CTSContactUpdate : JSONModel
@property(  strong) NSString* firstName, *lastName;
@property(  strong) NSString* type;
@property(  strong) NSString<Optional>* email;
@property(  strong) NSString<Optional>* mobile;
@property(  strong) NSString<Optional>* password;

-(void)substituteDefaults;
-(instancetype)initDefault;
-(void)substituteFromProfile:(CTSProfileContactRes *)profile;
@end
