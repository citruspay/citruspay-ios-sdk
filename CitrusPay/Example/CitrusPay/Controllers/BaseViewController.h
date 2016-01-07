//
//  BaseViewController.h
//  CubeDemo
//
//  Created by Vikas Singh on 8/25/15.
//  Copyright (c) 2015 Vikas Singh. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CitrusPay/CitrusPay.h>
#import "MerchantConstants.h"

@interface BaseViewController : UIViewController{

    CTSAuthLayer *authLayer;
    CTSProfileLayer *proifleLayer;
    CTSPaymentLayer *paymentLayer;
    CTSContactUpdate* contactInfo;
    CTSUserAddress* addressInfo;
    NSDictionary *customParams;

}

- (void)initializeLayers;

@end
