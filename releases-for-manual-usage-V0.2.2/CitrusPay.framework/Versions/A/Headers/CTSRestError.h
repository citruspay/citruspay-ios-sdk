//
//  CTSRestError.h
//  RestFulltester
//
//  Created by Yadnesh Wankhede on 29/05/14.
//  Copyright (c) 2014 Citrus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"
@interface CTSRestError : JSONModel

@property( strong)NSString<Optional>*errorDescription;
@property( strong)NSString<Optional>*description;
@property( strong)NSString<Optional>* error;
@property(strong)NSString<Optional>* type;
@property(strong)NSString<Ignore>* serverResponse;
@property(strong)NSString<Optional >*errorCode;
@property(strong)NSString<Optional >*errorMessage;
@property(strong)NSString<Optional >*error_desc;



//{"errorCode":"ExcessTransactionLimit","errorMessage":"Transaction amount cannot be greater than INR 5000.00"}
@end
