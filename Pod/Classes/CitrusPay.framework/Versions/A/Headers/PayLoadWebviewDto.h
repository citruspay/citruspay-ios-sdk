//
//  PayLoadWebviewDto.h
//  CTS iOS Sdk
//
//  Created by Yadnesh Wankhede on 10/06/15.
//  Copyright (c) 2015 Citrus. All rights reserved.
//

#import <Foundation/Foundation.h>
//-(void)loadPaymentWebview:(NSString *)url reqId:(int)reqId returnUrl:(NSString *)returnUrl

@interface PayLoadWebviewDto : NSObject
@property (strong)NSString* url,*returnUrl;
@property(assign)int reqId;
- (instancetype)initWithUrl:(NSString *)url reqId:(int)reqId returnUrl:(NSString *)returnUrl;
@end
