//
//  CTSDPMerchantQueryReq.h
//  CTS iOS Sdk
//
//  Created by Yadnesh Wankhede on 10/20/15.
//  Copyright © 2015 Citrus. All rights reserved.
//

#import <JSONModel/JSONModel.h>

@interface CTSDPMerchantQueryReq : JSONModel
@property(strong)NSString *merchantAccessKey,*signature;
@end
