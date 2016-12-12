//
//  PaymentType.h
//  CitrusPay
//
//  Created by Mukesh Patil on 8/3/16.
//  Copyright © 2016 CitrusPay. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CTSPaymentOptions.h"

#import "CTSRuleInfo.h"
#import "CTSContactUpdate.h"
#import "CTSUserAddress.h"

@interface PaymentType : NSObject
@property (strong) NSString * amount;
@property (strong) id URLOrCTSBill;
@property (strong) CTSPaymentOptions <Optional> * paymentOption;
@property (assign) BOOL useMVC;
@property (assign) BOOL useCash;
@property (assign) BOOL useDynamicPrice;
@property (strong) CTSRuleInfo <Optional> * ruleInfo;
@property (strong) CTSContactUpdate <Optional> * contactInfo;
@property (strong) CTSUserAddress <Optional> * addressInfo;
@property (strong) NSDictionary <Optional> * extraParams;

//load money
@property (strong) NSString <Optional> * returnURL;
@property (strong) NSDictionary <Optional> * customParams;

/**
 *  mvcPayment - through Single Payment Interface
 *
 *  @param amount - set transaction amount
 *  @param billURLOrCTSBill - set bill generator url or CTSBill Object
 *  @param paymentOption -  set payment details
 *  @param userContact -  set userContact
 *  @param userAddress -  set userAddress
 */
+ (PaymentType *)mvcPayment:(NSString *)amount
                    billUrl:(NSString *)billUrl
                    contact:(CTSContactUpdate <Optional> *)userContact
                    address:(CTSUserAddress <Optional> *)userAddress;

+ (PaymentType *)mvcPayment:(NSString *)amount
                 billObject:(CTSBill *)billObject
                    contact:(CTSContactUpdate <Optional> *)userContact
                    address:(CTSUserAddress <Optional> *)userAddress;

/**
 *  citrusCashPayment - through Single Payment Interface
 *
 *  @param amount - set transaction amount
 *  @param billURLOrCTSBill - set bill generator url or CTSBill Object
 *  @param paymentOption -  set payment details
 *  @param userContact -  set userContact
 *  @param userAddress -  set userAddress
 */
+ (PaymentType *)citrusCashPayment:(NSString *)amount
                           billUrl:(NSString *)billUrl
                           contact:(CTSContactUpdate <Optional> *)userContact
                           address:(CTSUserAddress <Optional> *)userAddress;

+ (PaymentType *)citrusCashPayment:(NSString *)amount
                        billObject:(CTSBill *)billObject
                           contact:(CTSContactUpdate <Optional> *)userContact
                           address:(CTSUserAddress <Optional> *)userAddress;

/**
 *  PGPayment - through Single Payment Interface
 *
 *  @param amount - set transaction amount
 *  @param billURLOrCTSBill - set bill generator url or CTSBill Object
 *  @param paymentOption -  set payment details
 *  @param userContact -  set userContact
 *  @param userAddress -  set userAddress
 */
+ (PaymentType *)PGPayment:(NSString *)amount
                   billUrl:(NSString *)billUrl
             paymentOption:(CTSPaymentOptions <Optional> *)paymentOption
                   contact:(CTSContactUpdate <Optional> *)userContact
                   address:(CTSUserAddress <Optional> *)userAddress;

+ (PaymentType *)PGPayment:(NSString *)amount
                billObject:(CTSBill *)billObject
             paymentOption:(CTSPaymentOptions <Optional> *)paymentOption
                   contact:(CTSContactUpdate <Optional> *)userContact
                   address:(CTSUserAddress <Optional> *)userAddress;

/**
 *  performDynamicPricing - through Single Payment Interface
 *
 *  @param amount - set transaction amount
 *  @param billURLOrCTSBill - set bill generator url or CTSBill Object
 *  @param paymentOption -  set payment details
 *  @param ruleInfo - set ruleInfo for dynamic pricing
 *  @param extraParams -  set extraParams
 *  @param userContact -  set userContact
 *  @param userAddress -  set userAddress
 */
+ (PaymentType *)performDynamicPricing:(NSString *)amount
                               billUrl:(NSString *)billUrl
                         paymentOption:(CTSPaymentOptions <Optional> *)paymentOption
                              ruleInfo:(CTSRuleInfo <Optional> *)ruleInfo
                           extraParams:(NSDictionary <Optional> *)extraParams
                               contact:(CTSContactUpdate <Optional> *)userContact
                               address:(CTSUserAddress <Optional> *)userAddress;

+ (PaymentType *)performDynamicPricing:(NSString *)amount
                            billObject:(CTSBill *)billObject
                         paymentOption:(CTSPaymentOptions <Optional> *)paymentOption
                              ruleInfo:(CTSRuleInfo <Optional> *)ruleInfo
                           extraParams:(NSDictionary <Optional> *)extraParams
                               contact:(CTSContactUpdate <Optional> *)userContact
                               address:(CTSUserAddress <Optional> *)userAddress;

/**
 *  splitPayment - through Single Payment Interface
 *
 *  @param amount - set transaction amount
 *  @param billURLOrCTSBill - set bill generator url or CTSBill Object
 *  @param useMVC - set bool value YES or NO
 *  @param useCash - set bool value YES or NO
 *  @param paymentOption -  set payment details
 *  @param userContact -  set userContact
 *  @param userAddress -  set userAddress
 */
+ (PaymentType *)splitPayment:(NSString *)amount
                      billUrl:(NSString *)billUrl
                       useMVC:(BOOL)useMVC
                      useCash:(BOOL)useCash
                paymentOption:(CTSPaymentOptions <Optional> *)paymentOption
                      contact:(CTSContactUpdate <Optional> *)userContact
                      address:(CTSUserAddress <Optional> *)userAddress;

+ (PaymentType *)splitPayment:(NSString *)amount
                   billObject:(CTSBill *)billObject
                       useMVC:(BOOL)useMVC
                      useCash:(BOOL)useCash
                paymentOption:(CTSPaymentOptions <Optional> *)paymentOption
                      contact:(CTSContactUpdate <Optional> *)userContact
                      address:(CTSUserAddress <Optional> *)userAddress;

/**
 *  load money - (Single Payment Interface) into Citruspay account -
 *
 *  @param amount - set transaction amount
 *  @param returnUrl - set return url
 *  @param paymentOption -  set payment details
 *  @param customParams -  set customParams
 *  @param userContact -  set userContact
 *  @param userAddress -  set userAddress
 */
+ (PaymentType *)loadMoney:(NSString *)amount
                 returnUrl:(NSString *)returnUrl
             paymentOption:(CTSPaymentOptions <Optional> *)paymentOption
              customParams:(NSDictionary <Optional> *)customParams
                   contact:(CTSContactUpdate <Optional> *)userContact
                   address:(CTSUserAddress <Optional> *)userAddress;
@end