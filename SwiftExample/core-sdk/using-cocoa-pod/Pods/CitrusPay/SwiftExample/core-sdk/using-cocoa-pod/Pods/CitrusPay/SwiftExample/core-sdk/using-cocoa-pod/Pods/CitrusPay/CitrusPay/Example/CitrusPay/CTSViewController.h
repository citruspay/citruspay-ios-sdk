//
//  CTSViewController.h
//  CitrusPay
//
//  Created by Mukesh Patil on 12/30/2015.
//  Copyright © 2015 CitrusPay. All rights reserved.
//

@import UIKit;
#import <CitrusPay/CitrusPay.h>

@interface CTSViewController : UIViewController {
    CTSAuthLayer *authLayer;
    CTSProfileLayer *proifleLayer;
    CTSPaymentLayer *paymentLayer;
}

@end
