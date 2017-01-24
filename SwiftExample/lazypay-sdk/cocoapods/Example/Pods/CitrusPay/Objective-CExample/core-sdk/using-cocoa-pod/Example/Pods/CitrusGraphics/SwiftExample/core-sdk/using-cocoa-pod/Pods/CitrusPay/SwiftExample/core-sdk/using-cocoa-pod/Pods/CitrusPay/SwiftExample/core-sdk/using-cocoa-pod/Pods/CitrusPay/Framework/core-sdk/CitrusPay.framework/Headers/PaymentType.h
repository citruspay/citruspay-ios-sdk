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
/*!
 *  @brief The PaymentType class' amount object.
 */
@property (strong) NSString * amount;
/*!
 *  @brief The PaymentType class' URLOrCTSBill object.
 */
@property (strong) id URLOrCTSBill;
/*!
 *  @brief The PaymentType class' paymentOption object.
 */
@property (strong) CTSPaymentOptions <Optional> * paymentOption;
/*!
 *  @brief The PaymentType class' useMVC object.
 */
@property (assign) BOOL useMVC;
/*!
 *  @brief The PaymentType class' useCash object.
 */
@property (assign) BOOL useCash;
/*!
 *  @brief The PaymentType class' useDynamicPrice object.
 */
@property (assign) BOOL useDynamicPrice;
/*!
*  @brief The PaymentType class' ruleInfo object.
*/
@property (strong) CTSRuleInfo <Optional> * ruleInfo;
/*!
 *  @brief The PaymentType class' contactInfo object.
 */
@property (strong) CTSContactUpdate <Optional> * contactInfo;
/*!
 *  @brief The PaymentType class' addressInfo object.
 */
@property (strong) CTSUserAddress <Optional> * addressInfo;
/*!
 *  @brief The PaymentType class' extraParams object.
 */
@property (strong) NSDictionary <Optional> * extraParams;

//load money
/*!
 *  @brief The PaymentType class' returnURL object.
 */
@property (strong) NSString <Optional> * returnURL;
/*!
 *  @brief The PaymentType class' customParams object.
 */
@property (strong) NSDictionary <Optional> * customParams;


/*!
 *  @brief MVCPayment - Through Single Payment Interface.
 *
 *  @param amount      The Transaction Amount.
 *  @param billUrl     The Bill Generator URL.
 *  @param userContact The User Contact.
 *  @param userAddress The User Address.
 *
 *  @return The PaymentType Object.
 */
+ (PaymentType *)mvcPayment:(NSString *)amount
                    billUrl:(NSString *)billUrl
                    contact:(CTSContactUpdate <Optional> *)userContact
                    address:(CTSUserAddress <Optional> *)userAddress;

/*!
 *  @brief The MVCPayment - Through Single Payment Interface.
 *
 *  @param amount      The Transaction Amount.
 *  @param billObject  The CTSBill Object.
 *  @param userContact The User Contact.
 *  @param userAddress The User Address.
 *
 *  @return The PaymentType Object.
 */
+ (PaymentType *)mvcPayment:(NSString *)amount
                 billObject:(CTSBill *)billObject
                    contact:(CTSContactUpdate <Optional> *)userContact
                    address:(CTSUserAddress <Optional> *)userAddress;

/*!
 *  @brief The CitrusCashPayment - Through Single Payment Interface.
 *
 *  @param amount      The Transaction Amount.
 *  @param billUrl     The Bill Generator URL.
 *  @param userContact The User Contact.
 *  @param userAddress The User Address.
 *
 *  @return The PaymentType Object.
 */
+ (PaymentType *)citrusCashPayment:(NSString *)amount
                           billUrl:(NSString *)billUrl
                           contact:(CTSContactUpdate <Optional> *)userContact
                           address:(CTSUserAddress <Optional> *)userAddress;

/*!
 *  @brief The CitrusCashPayment - Through Single Payment Interface
 *
 *  @param amount      The Transaction Amount.
 *  @param billObject  The CTSBill Object.
 *  @param userContact The User Contact.
 *  @param userAddress The User Address.
 *
 *  @return The PaymentType Object.
 */
+ (PaymentType *)citrusCashPayment:(NSString *)amount
                        billObject:(CTSBill *)billObject
                           contact:(CTSContactUpdate <Optional> *)userContact
                           address:(CTSUserAddress <Optional> *)userAddress;

/*!
 *  @brief The PGPayment - Through Single Payment Interface.
 *
 *  @param amount      The Transaction Amount.
 *  @param billUrl     The Bill Generator URL.
 *  @param paymentOption The Payment Details.
 *  @param userContact The User Contact.
 *  @param userAddress The User Address.
 *
 *  @return The PaymentType Object.
 */
+ (PaymentType *)PGPayment:(NSString *)amount
                   billUrl:(NSString *)billUrl
             paymentOption:(CTSPaymentOptions <Optional> *)paymentOption
                   contact:(CTSContactUpdate <Optional> *)userContact
                   address:(CTSUserAddress <Optional> *)userAddress;

/*!
 *  @brief The PGPayment - Through Single Payment Interface.
 *
 *  @param amount      The Transaction Amount.
 *  @param billObject  The CTSBill Object.
 *  @param paymentOption The Payment Details.
 *  @param userContact The User Contact.
 *  @param userAddress The User Address.
 *
 *  @return The PaymentType Object.
 */
+ (PaymentType *)PGPayment:(NSString *)amount
                billObject:(CTSBill *)billObject
             paymentOption:(CTSPaymentOptions <Optional> *)paymentOption
                   contact:(CTSContactUpdate <Optional> *)userContact
                   address:(CTSUserAddress <Optional> *)userAddress;

/*!
 *  @brief The PerformDynamicPricing - Through Single Payment Interface.
 *
 *  @param amount      The Transaction Amount.
 *  @param billUrl     The Bill Generator URL.
 *  @param paymentOption The Payment Details.
 *  @param ruleInfo      The RuleInfo For Dynamic Pricing.
 *  @param extraParams   The ExtraParams.
 *  @param userContact The User Contact.
 *  @param userAddress The User Address.
 *
 *  @return The PaymentType Object.
 */
+ (PaymentType *)performDynamicPricing:(NSString *)amount
                               billUrl:(NSString *)billUrl
                         paymentOption:(CTSPaymentOptions <Optional> *)paymentOption
                              ruleInfo:(CTSRuleInfo <Optional> *)ruleInfo
                           extraParams:(NSDictionary <Optional> *)extraParams
                               contact:(CTSContactUpdate <Optional> *)userContact
                               address:(CTSUserAddress <Optional> *)userAddress;

/*!
 *  @brief The PerformDynamicPricing - Through Single Payment Interface.
 *
 *  @param amount      The Transaction Amount.
 *  @param billObject  The CTSBill Object.
 *  @param paymentOption The Payment Details.
 *  @param ruleInfo      The RuleInfo For Dynamic Pricing.
 *  @param extraParams   The ExtraParams.
 *  @param userContact The User Contact.
 *  @param userAddress The User Address.
 *
 *  @return The PaymentType Object.
 */
+ (PaymentType *)performDynamicPricing:(NSString *)amount
                            billObject:(CTSBill *)billObject
                         paymentOption:(CTSPaymentOptions <Optional> *)paymentOption
                              ruleInfo:(CTSRuleInfo <Optional> *)ruleInfo
                           extraParams:(NSDictionary <Optional> *)extraParams
                               contact:(CTSContactUpdate <Optional> *)userContact
                               address:(CTSUserAddress <Optional> *)userAddress;

/*!
 *  @brief The SplitPayment - Through Single Payment Interface.
 *
 *  @param amount      The Transaction Amount.
 *  @param billUrl     The Bill Generator URL.
 *  @param useMVC      The BOOL Object.
 *  @param useCash     The BOOL Object.
 *  @param paymentOption The Payment Details.
 *  @param userContact The User Contact.
 *  @param userAddress The User Address.
 *
 *  @return The PaymentType Object.
 */
+ (PaymentType *)splitPayment:(NSString *)amount
                      billUrl:(NSString *)billUrl
                       useMVC:(BOOL)useMVC
                      useCash:(BOOL)useCash
                paymentOption:(CTSPaymentOptions <Optional> *)paymentOption
                      contact:(CTSContactUpdate <Optional> *)userContact
                      address:(CTSUserAddress <Optional> *)userAddress;

/*!
 *  @brief The SplitPayment - Through Single Payment Interface.
 *
 *  @param amount      The Transaction Amount.
 *  @param billObject  The CTSBill Object.
 *  @param useMVC      The BOOL Object.
 *  @param useCash     The BOOL Object.
 *  @param paymentOption The Payment Details.
 *  @param userContact The User Contact.
 *  @param userAddress The User Address.
 *
 *  @return The PaymentType Object.
 */
+ (PaymentType *)splitPayment:(NSString *)amount
                   billObject:(CTSBill *)billObject
                       useMVC:(BOOL)useMVC
                      useCash:(BOOL)useCash
                paymentOption:(CTSPaymentOptions <Optional> *)paymentOption
                      contact:(CTSContactUpdate <Optional> *)userContact
                      address:(CTSUserAddress <Optional> *)userAddress;

/*!
 *  @brief The Load Money - (Single Payment Interface) into Citruspay account.
 *
 *  @param amount      The Transaction Amount.
 *  @param returnUrl     The Return URL.
 *  @param paymentOption The Payment Details.
 *  @param customParams  The CustomParams.
 *  @param userContact The User Contact.
 *  @param userAddress The User Address.
 *
 *  @return The PaymentType Object.
 */
+ (PaymentType *)loadMoney:(NSString *)amount
                 returnUrl:(NSString *)returnUrl
             paymentOption:(CTSPaymentOptions <Optional> *)paymentOption
              customParams:(NSDictionary <Optional> *)customParams
                   contact:(CTSContactUpdate <Optional> *)userContact
                   address:(CTSUserAddress <Optional> *)userAddress;
@end