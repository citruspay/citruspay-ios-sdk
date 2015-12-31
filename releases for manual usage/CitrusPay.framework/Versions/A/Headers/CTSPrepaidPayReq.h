//
//  CTSPrepaidPayReq.h
//  CTS iOS Sdk
//
//  Created by Yadnesh on 9/15/15.
//  Copyright (c) 2015 Citrus. All rights reserved.
//

#import "JSONModel.h"
#import "CTSAmount.h"
#import "CTSPrepaidUser.h"
@interface CTSPrepaidPayReq : JSONModel
/*
 {
 "amount":{
 "value":"1",
 "currency":"INR"
 },
 "merchantTxnId":"144281756671350",
 "merchantAccessKey":"F2VZD1HBS2VVXJPMWO77",
 "requestSignature":"aac4925b1397b9d31f1a90ed54cb6ce0506b21dc",
 "returnUrl":"https:\/\/salty-plateau-1529.herokuapp.com\/redirectURL.stg3.php",
 "userDetails":{
 "firstName":"Tester",
 "lastName":"Citrus",
 "email":"tester@gmail.com",
 "mobileNo":"9999999999",
 "street1":"streetone",
 "street2":"streettwo",
 "city":"Mumbai",
 "state":"Maharashtra",
 "country":"India",
 "zip":"400052"
 }
 }
 */
@property (strong)NSString *merchantTxnId,*requestSignature,*merchantAccessKey,*notifyUrl,*returnUrl,*requestOrigin;
@property (strong)NSDictionary *customParameters;
@property (strong)CTSAmount *amount;
@property(strong)CTSPrepaidUser *userDetails;
@end
