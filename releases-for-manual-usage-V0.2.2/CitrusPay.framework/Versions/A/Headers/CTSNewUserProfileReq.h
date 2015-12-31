//
//  CTSNewUserProfileReq.h
//  CTS iOS Sdk
//
//  Created by Yadnesh Wankhede on 30/03/15.
//  Copyright (c) 2015 Citrus. All rights reserved.
//

#import "JSONModel.h"

@interface CTSNewUserProfileReq : JSONModel
@property(strong) NSString<Optional>* email;
@property( strong) NSString<Optional>* mobile;
@end
