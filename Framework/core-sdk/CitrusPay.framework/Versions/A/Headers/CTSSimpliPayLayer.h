//
//  CTSSimpliPayLayer.h
//  CitrusPay
//
//  Created by Mukesh Patil on 5/13/16.
//  Copyright © 2016 CitrusPay. All rights reserved.
//

#import "CTSPaymentLayer.h"

//#import "CTSPaymentReceipt.h"
//#import "CTSSimpliChargeDistribution.h"
//#import "CTSPaymentOptions.h"

//// CallBack Handlers
//typedef void (^CTSSmartPayCompletionHandler)(CTSPaymentReceipt *paymentReceipt,
//                                             NSError *error);
//
//typedef void (^CTSPaymentDistributionCompletionHandler)(CTSSimpliChargeDistribution *amountDistribution,
//                                                        NSError *error);

@interface CTSSimpliPayLayer : CTSPaymentLayer

/**
 *  simpliPay - for all payment single end point
 *
 *  @param amount - set transaction amount
 *  @param billURL - set bill generator url
 *  @param paymentOption -  set payment details
 *  @param useMVC - set bool value YES or NO
 *  @param useCash - set bool value YES or NO
 *  @param useDynamicPrice - set bool value YES or NO
 *  @param ruleInfo - set ruleInfo for dynamic pricing
 *  @param andParentViewController - set current controller self object
 *  @param completionHandler - return callback into paymentReceipt & error
 */
- (void)simpliPayInternal:(NSString *)amount
          billURL:(NSString *)billURL
    paymentOption:(CTSPaymentOptions <Optional> *)paymentOption
           useMVC:(BOOL)useMVC
          useCash:(BOOL)useCash
  useDynamicPrice:(BOOL)useDynamicPrice
         ruleInfo:(CTSRuleInfo <Optional> *)ruleInfo
andParentViewController:(UIViewController *)controller
completionHandler:(CTSSmartPayCompletionHandler)completion;


/**
 *  calculate Payment Distribution - for split payment
 *
 *  @param amount - set transaction amount
 *  @param completionHandler - return callback into amountDistribution viz mvcAmount, cashAmount, remainingAmount & totalAmount, BOOL useMVC, useCash & enoughMVCAndCash;
 */
- (void)calculatePaymentDistributionInternal:(NSString *)amount
                   completionHandler:(CTSPaymentDistributionCompletionHandler)completion;

/**
 *  load money - into Citruspay account
 *
 *  @param amount - set transaction amount
 *  @param returnURL - set return url
 *  @param paymentOption -  set payment details
 *  @param andParentViewController - set current controller self object
 *  @param completionHandler - return callback into paymentReceipt & error
 */
- (void)loadMoneyInternal:(NSString *)amount
        returnURL:(NSString *)returnURL
    paymentOption:(CTSPaymentOptions *)paymentOption
andParentViewController:(UIViewController *)controller
completionHandler:(CTSSmartPayCompletionHandler)completion;
@end