//
//  CTSPrepaidUser.h
//  CTS iOS Sdk
//
//  Created by Yadnesh on 9/22/15.
//  Copyright (c) 2015 Citrus. All rights reserved.
//

#import "JSONModel.h"
#import "CTSContactUpdate.h"
#import "CTSUserAddress.h"
//    "userDetails":{
//        "firstName":"Tester",
//        "lastName":"Citrus",
//        "email":"tester@gmail.com",
//        "mobileNo":"9999999999",
//        "street1":"streetone",
//        "street2":"streettwo",
//        "city":"Mumbai",
//        "state":"Maharashtra",
//        "country":"India",
//        "zip":"400052"
//    }
@interface CTSPrepaidUser : JSONModel
@property (strong)NSString<Optional> *firstName,*lastName,*email,*mobileNo,*street1,*street2,*city,*state,*country,*zip;
- (instancetype)initWithContact:(CTSContactUpdate *)contact address:(CTSUserAddress*)address;
@end
