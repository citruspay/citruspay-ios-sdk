//
//  PaymentWebViewController.h
//  CTS iOS Sdk
//
//  Created by Yadnesh Wankhede on 13/05/15.
//  Copyright (c) 2015 Citrus. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CTSPaymentDetailUpdate.h"


@interface CTSPaymentWebViewController : UIViewController <UIWebViewDelegate>
{
    UIActivityIndicatorView* indicator;
    BOOL transactionOver;
    UIAlertView *pleaseWait;
    BOOL isCancelTriggered;
    int cancelTxCount;
}

@property( strong) NSString *redirectURL,*returnUrl;
@property(assign) int reqId;
@property( strong) NSMutableDictionary *response;
@property(nonatomic,strong) NSMutableURLRequest *consumerPortalRequest;

@property(nonatomic,strong) CTSPaymentDetailUpdate *paymentInfo;
@property(nonatomic,strong) CTSBill *bill;
@property(nonatomic,strong) CTSContactUpdate *contactInfo;
@property(nonatomic,strong) CTSUserAddress *userAddress;
@property(nonatomic,strong) NSDictionary *custParams;
@property BOOL isForLoadMoney;

-(void)finishWebView;
@end
