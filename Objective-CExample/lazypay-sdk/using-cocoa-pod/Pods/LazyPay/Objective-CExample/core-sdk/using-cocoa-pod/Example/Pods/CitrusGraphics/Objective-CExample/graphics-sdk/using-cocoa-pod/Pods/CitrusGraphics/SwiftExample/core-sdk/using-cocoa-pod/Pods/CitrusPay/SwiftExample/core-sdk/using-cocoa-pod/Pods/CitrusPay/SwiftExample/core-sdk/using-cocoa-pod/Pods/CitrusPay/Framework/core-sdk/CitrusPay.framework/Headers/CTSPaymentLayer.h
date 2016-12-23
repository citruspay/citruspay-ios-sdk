//
//  CTSPaymentLayer.h
//  RestFulltester
//
//  Created by Raji Nair on 19/06/14.
//  Copyright (c) 2014 Citrus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "CTSRestPluginBase.h"
#import "CTSRuleInfo.h"
#import "CTSAuthLayer.h"
#import "CitrusCashRes.h"
#import "CTSPaymentDetailUpdate.h"
#import "CTSUser.h"
#import "CTSDyPResponse.h"
#import "CTSBill.h"
#import "CTSPgSettings.h"
#import "CTSTransferMoneyResponse.h"
#import "CTSAmount.h"
#import "CTSCashoutBankAccount.h"
#import "CTSCardBinResponse.h"
#import "CTSCashoutToBankRes.h"
#import "CTSPrepaidBill.h"
#import "CTSPaymentTransactionRes.h"
#import "CTSPGHealthRes.h"
#import "CTSDyPValidateRuleReq.h"
#import "CTSPrepaidPayResp.h"
#import "CTSPaymentRequest.h"
#import "HVDOverlay.h"

#import "CTSSimpliChargeDistribution.h"
#import "CTSPaymentOptions.h"
#import "CTSPaymentReceipt.h"
#import "CTSAutoLoadSubGetResp.h"
#import "CTSLoadAndPayRes.h"
#import "CTSLoadMoney.h"
#import "CTSAutoLoad.h"

#import "PaymentType.h"

/// Class Models.
@class   CTSPaymentWebViewController , CTSContactUpdate, CTSUserAddress;

/*!
 PaymentRequestType enum.
 */
typedef enum {
    PaymentAsGuestReqId,
    PaymentUsingtokenizedCardBankReqId,
    PaymentUsingSignedInCardBankReqId,
    PaymentPgSettingsReqId,
    PaymentAsCitruspayInternalReqId,
    PaymentAsCitruspayReqId,
    PaymentGetPrepaidBillReqId,
    PaymentLoadMoneyCitrusPayReqId,
    PaymentCashoutToBankReqId,
    PaymentChargeInnerWebNormalReqId,
    PaymentChargeInnerWeblTokenReqId,
    PaymentChargeInnerWebLoadMoneyReqId,
    PGHealthReqId,
    PaymentDynamicPricingReqId,
    PaymentRequestTransferMoney,
    PaymentDPValidateRuleReqId,
    PaymentDPCalculateReqId,
    PaymentDPQueryMerchantReqId,
    PaymentCardBinServiceReqId,
    PayUsingDynamicPricingReqId,
    PayPrepaidNewReqId,
    PayPrepaidNewInternalReqId,
    PaymentNewAsGuestReqId,
}PaymentRequestType;


/*!
 *  @brief AutoLoadSubsctiptionType enum.
 */
typedef enum{
    AutoLoadSubsctiptionTypeActive,
    AutoLoadSubsctiptionTypeInActive,
    AutoLoadSubsctiptionTypeAll
}AutoLoadSubsctiptionType;

/*!
 *  @brief CitrusPaymentType enum.
 */
typedef enum{
    CitrusPaymentTypeDirect,
    CitrusPaymentTypeCitrusCash,
}CitrusPaymentType;

/*!
 *  @brief LoadMoneyResponeKey.
 */
extern NSString * const LoadMoneyResponeKey;

#define LogThread LogTrace(@"THREAD  %@", [NSThread currentThread]);

/// Class Models.
@class CTSAuthLayer;
@class CTSAuthenticationProtocol;
@class CTSPaymentLayer;

/*!
 *  @brief CTSPaymentProtocol.
 */
@protocol CTSPaymentProtocol<NSObject>
@optional
- (void)payment:(CTSPaymentLayer*)layer
didMakeUserPayment:(CTSPaymentTransactionRes*)paymentInfo
          error:(NSError*)error;

/**
 *  Guest payment callback
 *
 *  @param layer
 *  @param paymentInfo
 *  @param error
 */
@optional
- (void)payment:(CTSPaymentLayer*)layer
didMakePaymentUsingGuestFlow:(CTSPaymentTransactionRes*)paymentInfo
          error:(NSError*)error;

//Vikas new payment api
/**
 *  Guest payment callback
 *
 *  @param layer
 *  @param responseString
 *  @param error
 */

@optional
- (void)payment:(CTSPaymentLayer*)layer
didMakeNewPaymentUsingGuestFlow:(NSString*)responseString
          error:(NSError*)error;

/**
 *  response for tokenized payment
 *
 *  @param layer
 *  @param paymentInfo
 *  @param error
 */
@optional
- (void)payment:(CTSPaymentLayer*)layer
didMakeTokenizedPayment:(CTSPaymentTransactionRes*)paymentInfo
          error:(NSError*)error;

/**
 *  pg setting are recived for merchant
 *
 *  @param pgSetting pegsetting,nil in case of error
 *  @param error     ctserror
 */
@optional
- (void)payment:(CTSPaymentLayer*)layer
didPaymentCitrusCash:(CTSCitrusCashRes*)pgSettings
          error:(NSError*)error;

@optional
- (void)payment:(CTSPaymentLayer*)layer
didRequestMerchantPgSettings:(CTSPgSettings*)pgSettings
          error:(NSError*)error;


@optional
- (void)payment:(CTSPaymentLayer*)layer
didGetPrepaidBill:(CTSPrepaidBill*)bill
          error:(NSError*)error;


@optional
- (void)payment:(CTSPaymentLayer*)layer
   didLoadMoney:(CTSPaymentTransactionRes*)paymentInfo
          error:(NSError*)error;


@optional
- (void)payment:(CTSPaymentLayer*)layer
didCashoutToBank:(CTSCashoutToBankRes *)cashoutToBankRes
          error:(NSError*)error;
@end


typedef void (^ASMakeUserPaymentCallBack)(CTSPaymentTransactionRes* paymentInfo,
                                          NSError* error);

typedef void (^ASMakeTokenizedPaymentCallBack)(
                                               CTSPaymentTransactionRes* paymentInfo,
                                               NSError* error);

typedef void (^ASMakeGuestPaymentCallBack)(
                                           CTSPaymentTransactionRes* paymentInfo,
                                           NSError* error);

typedef void (^ASMakeNewPaymentCallBack)( NSString* responseString , NSError* error);

typedef void (^ASMakeCitruspayCallBackInternal)(CTSPaymentTransactionRes* paymentInfo,
                                                NSError* error);

typedef void (^ASCitruspayCallback)(CTSCitrusCashRes* citrusCashResponse,
                                    NSError* error);

typedef void (^ASGetMerchantPgSettingsCallBack)(CTSPgSettings* pgSettings,
                                                NSError* error);

typedef void (^ASGetPrepaidBill)(CTSPrepaidBill* prepaidBill,
                                 NSError* error);

typedef void (^ASLoadMoneyCallBack)(CTSPaymentTransactionRes* paymentInfo,
                                    NSError* error);

typedef void (^ASCashoutToBankCallBack)(CTSCashoutToBankRes *cashoutRes,
                                        NSError* error);

typedef void (^ASGetPGHealth)(CTSPGHealthRes* pgHealthRes,
                              NSError* error);

typedef void (^ASPerformDynamicPricingCallback)(CTSDyPResponse* dyPResponse,
                                                NSError* error);

typedef void (^ASDPValidateRuleCallback)(CTSDyPResponse* dyPResponse,
                                         NSError* error);

typedef void (^ASMoneyTransferCallback)(CTSTransferMoneyResponse* transferMoneyRes
                                        ,NSError* error);

typedef void (^ASCardBinServiceCallback)(CTSCardBinResponse* cardBinResponse
                                         ,NSError* error);

typedef void (^ASPrepaidPayCallback)(CTSPrepaidPayResp* prepaidPay,
                                     NSError* error);

// CallBack Handlers
typedef void (^CTSSmartPayCompletionHandler)(CTSPaymentReceipt *paymentReceipt,
                                             NSError *error);

typedef void (^CTSPaymentDistributionCompletionHandler)(CTSSimpliChargeDistribution *amountDistribution,
                                                        NSError *error);

typedef void (^ASGetAutoloadSubsCallback)(CTSAutoLoadSubGetResp* autoloadSubscriptions,
                                          NSError* error);

typedef void (^ASAutoLoadCallback)( CTSAutoLoadSubResp *autoloadResponse,
                                   NSError* error);

typedef void (^ASLoadAndSubscribeCallback)(CTSLoadAndPayRes* loadAndSubscribe,
                                           NSError* error);

/*!
 *  @brief CTSPaymentLayer.
 */
@interface CTSPaymentLayer : CTSRestPluginBase <CTSAuthenticationProtocol, UIWebViewDelegate> {
    BOOL finished;
    NSString *cCashReturnUrl;
    PaymentRequestType prepaidRequestType;
    CTSPaymentDetailUpdate *tempCVVStoreObject;
}
/*!
 * @brief The CTSPaymentLayer class' citrusCashBackViewController object.
 */
@property (strong) UIViewController *citrusCashBackViewController;
/*!
 * @brief The CTSPaymentLayer class' citrusPayWebview object.
 */
@property(strong)UIWebView *citrusPayWebview;
/*!
 * @brief The CTSPaymentLayer class' merchantTxnId object.
 */
@property(strong) NSString* merchantTxnId;
/*!
 * @brief The CTSPaymentLayer class' signature object.
 */
@property(strong) NSString* signature;
/*!
 * @brief The CTSPaymentLayer class' delegate object.
 */
@property(weak) id <CTSPaymentProtocol> delegate;
/*!
 * @brief The CTSPaymentLayer class' paymentWebViewController object.
 */
@property(strong) CTSPaymentWebViewController *paymentWebViewController;


/*!
 *  @brief Fetch Shared PaymentLayer.
 *
 *  @return The PaymentLayer object.
 */
+(CTSPaymentLayer*)fetchSharedPaymentLayer;

/*!
 *  @brief initWithUrl.
 *
 *  @param url The Transaction Amount.
 *
 *  @return The Newly created object.
 */
- (instancetype)initWithUrl:(NSString *)url;

/*!
 *  @brief initWithKeyStore.
 *
 *  @param keystoreArg The signinId String, signUpId String, signinSecret String, signUpSecret String and vanity String.
 *
 *  @return The Newly created object.
 */
- (instancetype)initWithKeyStore:(CTSKeyStore *)keystoreArg;


/**
 ***************************************************************************************************************
 DEPRECATED Start
 ***************************************************************************************************************
 */

/*!
 *  @brief requestChargeTokenizedPayment.
 *
 *  @param paymentInfo The paymentInfo CTSPaymentDetailUpdate.
 *  @param contactInfo The contactInfo CTSContactUpdate.
 *  @param userAddress The userAddress CTSUserAddress.
 *  @param bill        The bill CTSBill.
 *  @param custParams  The custParams NSDictionary.
 *  @param callback    The callback ASMakeTokenizedPaymentCallBack.
 */
- (void)requestChargeTokenizedPayment:(CTSPaymentDetailUpdate*)paymentInfo
                          withContact:(CTSContactUpdate*)contactInfo
                          withAddress:(CTSUserAddress*)userAddress
                                 bill:(CTSBill *)bill
                         customParams:(NSDictionary *)custParams
                withCompletionHandler:(ASMakeTokenizedPaymentCallBack)callback DEPRECATED_MSG_ATTRIBUTE("use requestChargePayment:withContact:withAddress:bill:customParams:returnViewController:withCompletionHandler:");

/*!
 *  @brief requestChargePayment.
 *
 *  @param paymentInfo The paymentInfo CTSPaymentDetailUpdate.
 *  @param contactInfo The contactInfo CTSContactUpdate.
 *  @param userAddress The userAddress CTSUserAddress.
 *  @param bill        The bill CTSBill.
 *  @param custParams  The custParams NSDictionary.
 *  @param callback    The callback ASMakeGuestPaymentCallBack.
 */
- (void)requestChargePayment:(CTSPaymentDetailUpdate*)paymentInfo
                 withContact:(CTSContactUpdate*)contactInfo
                 withAddress:(CTSUserAddress*)userAddress
                        bill:(CTSBill *)bill
                customParams:(NSDictionary *)custParams
       withCompletionHandler:(ASMakeGuestPaymentCallBack)callback
DEPRECATED_MSG_ATTRIBUTE("use requestChargePayment:withContact:withAddress:bill:customParams:returnViewController:withCompletionHandler:");

/*!
 *  @brief requestLoadMoneyInCitrusPay.
 *
 *  @param paymentInfo The paymentInfo CTSPaymentDetailUpdate.
 *  @param contactInfo The contactInfo CTSContactUpdate.
 *  @param userAddress The userAddress CTSUserAddress.
 *  @param amount      The amount NSString.
 *  @param returnUrl   The returnUrl NSString.
 *  @param custParams  The custParams NSDictionary.
 *  @param callback    The callback ASLoadMoneyCallBack.
 */
- (void)requestLoadMoneyInCitrusPay:(CTSPaymentDetailUpdate *)paymentInfo
                        withContact:(CTSContactUpdate*)contactInfo
                        withAddress:(CTSUserAddress*)userAddress
                             amount:(NSString *)amount
                          returnUrl:(NSString *)returnUrl
                       customParams:(NSDictionary *)custParams
              withCompletionHandler:(ASLoadMoneyCallBack)callback  __attribute__((deprecated("Please use requestLoadMoney:returnURL:paymentOption:andParentViewController:completionHandler: instead")));

//new prepaid pay api

/*!
 *  @brief requestChargeCitrusWalletWithContact.
 *
 *  @param contactInfo The contactInfo CTSContactUpdate.
 *  @param userAddress The userAddress CTSUserAddress.
 *  @param bill        The bill CTSBill.
 *  @param controller  The controller UIViewController.
 *  @param callback    The callback ASCitruspayCallback.
 */
- (void)requestChargeCitrusWalletWithContact:(CTSContactUpdate*)contactInfo
                                     address:(CTSUserAddress*)userAddress
                                        bill:(CTSBill *)bill
                        returnViewController:(UIViewController *)controller
                       withCompletionHandler:(ASCitruspayCallback)callback __attribute__((deprecated("Please use requestSimpliPay:billURL:paymentOption:useMVC:useCash:useDynamicPrice:ruleInfo:andParentViewController:completionHandler: instead")));


//old prepaid pay api

/*!
 *  @brief requestChargeCitrusCashWithContact.
 *
 *  @param contactInfo The contactInfo CTSContactUpdate.
 *  @param userAddress The userAddress CTSUserAddress.
 *  @param bill        The bill CTSBill.
 *  @param custParams  The custParams NSDictionary.
 *  @param controller  The controller UIViewController.
 *  @param callback    The callback ASCitruspayCallback.
 */
- (void)requestChargeCitrusCashWithContact:(CTSContactUpdate*)contactInfo
                               withAddress:(CTSUserAddress*)userAddress
                                      bill:(CTSBill *)bill
                              customParams:(NSDictionary *)custParams
                      returnViewController:(UIViewController *)controller
                     withCompletionHandler:(ASCitruspayCallback)callback DEPRECATED_MSG_ATTRIBUTE("Use requestChargeCitrusWalletWithContact:address:bill:customParams:returnViewController:withCompletionHandler: ");

/*!
 *  @brief requestChargeTokenizedPayment.
 *
 *  @param paymentInfo The paymentInfo CTSPaymentDetailUpdate.
 *  @param contactInfo The contactInfo CTSContactUpdate.
 *  @param userAddress The userAddress CTSUserAddress.
 *  @param bill        The bill CTSBill.
 *  @param custParams  The custParams NSDictionary.
 *  @param controller  The controller UIViewController.
 *  @param callback    The callback ASCitruspayCallback.
 */
- (void)requestChargeTokenizedPayment:(CTSPaymentDetailUpdate*)paymentInfo
                          withContact:(CTSContactUpdate*)contactInfo
                          withAddress:(CTSUserAddress*)userAddress
                                 bill:(CTSBill *)bill
                         customParams:(NSDictionary *)custParams
                 returnViewController:(UIViewController *)controller
                withCompletionHandler:(ASCitruspayCallback)callback DEPRECATED_MSG_ATTRIBUTE("use requestChargePayment:withContact:withAddress:bill:customParams:returnViewController:withCompletionHandler:");


// single hop
/*!
 *  @brief requestDirectChargePayment.
 *
 *  @param paymentInfo The paymentInfo CTSPaymentDetailUpdate.
 *  @param contactInfo The contactInfo CTSContactUpdate.
 *  @param userAddress The userAddress CTSUserAddress.
 *  @param bill        The bill CTSBill.
 *  @param controller  The controller UIViewController.
 *  @param callback    The Transaction Amount.
 */
- (void)requestDirectChargePayment:(CTSPaymentDetailUpdate*)paymentInfo
                       withContact:(CTSContactUpdate*)contactInfo
                       withAddress:(CTSUserAddress*)userAddress
                              bill:(CTSBill *)bill
              returnViewController:(UIViewController *)controller
             withCompletionHandler:(ASCitruspayCallback)callback __attribute__((deprecated("Please use requestSimpliPay:billURL:paymentOption:useMVC:useCash:useDynamicPrice:ruleInfo:andParentViewController:completionHandler: instead")));


//moto call
/*!
 *  @brief requestChargePayment.
 *
 *  @param paymentInfo The paymentInfo CTSPaymentDetailUpdate.
 *  @param contactInfo The contactInfo CTSContactUpdate.
 *  @param userAddress The userAddress CTSUserAddress.
 *  @param bill        The bill CTSBill.
 *  @param custParams  The Transaction Amount.
 *  @param controller  The controller UIViewController.
 *  @param callback    The Transaction Amount.
 */
- (void)requestChargePayment:(CTSPaymentDetailUpdate*)paymentInfo
                 withContact:(CTSContactUpdate*)contactInfo
                 withAddress:(CTSUserAddress*)userAddress
                        bill:(CTSBill *)bill
                customParams:(NSDictionary *)custParams
        returnViewController:(UIViewController *)controller
       withCompletionHandler:(ASCitruspayCallback)callback __attribute__((deprecated("Please use requestSimpliPay:billURL:paymentOption:useMVC:useCash:useDynamicPrice:ruleInfo:andParentViewController:completionHandler: instead")));


/*!
 *  @brief requestLoadMoneyInCitrusPay.
 *
 *  @param paymentInfo The paymentInfo CTSPaymentDetailUpdate.
 *  @param contactInfo The contactInfo CTSContactUpdate.
 *  @param userAddress The userAddress CTSUserAddress.
 *  @param amount      The amount NSString.
 *  @param returnUrl   The returnUrl NSString.
 *  @param custParams  The custParams NSDictionary.
 *  @param controller  The controller UIViewController.
 *  @param callback    The callback ASCitruspayCallback.
 */
- (void)requestLoadMoneyInCitrusPay:(CTSPaymentDetailUpdate *)paymentInfo
                        withContact:(CTSContactUpdate*)contactInfo
                        withAddress:(CTSUserAddress*)userAddress
                             amount:(NSString *)amount
                          returnUrl:(NSString *)returnUrl
                       customParams:(NSDictionary *)custParams
               returnViewController:(UIViewController *)controller
              withCompletionHandler:(ASCitruspayCallback)callback __attribute__((deprecated("Please use requestLoadMoney:returnURL:paymentOption:andParentViewController:completionHandler: instead")));


/*!
 *  @brief requestChargeDynamicPricingContact.
 *
 *  @param contactInfo The contactInfo CTSContactUpdate.
 *  @param userAddress The userAddress CTSUserAddress.
 *  @param custParams  The custParams custParams.
 *  @param controller  The controller UIViewController.
 *  @param callback    The callback ASCitruspayCallback.
 */
- (void)requestChargeDynamicPricingContact:(CTSContactUpdate*)contactInfo
                               withAddress:(CTSUserAddress*)userAddress
                              customParams:(NSDictionary *)custParams
                      returnViewController:(UIViewController *)controller
                     withCompletionHandler:(ASCitruspayCallback)callback;

/*!
 *  @brief requestPerformDynamicPricingRule.
 *
 *  @param ruleInfo    The Transaction Amount.
 *  @param paymentInfo The paymentInfo CTSPaymentDetailUpdate.
 *  @param bill        The bill CTSBill.
 *  @param user        The user CTSUser.
 *  @param requestType The requestType DPRequestType.
 *  @param extraParams The extraParams NSDictionary.
 *  @param callback    The callback ASPerformDynamicPricingCallback.
 */
-(void)requestPerformDynamicPricingRule:(CTSRuleInfo *)ruleInfo
                            paymentInfo:(CTSPaymentDetailUpdate *)payment
                                   bill:(CTSBill *)bill
                                   user:(CTSUser *)user
                                   type:(DPRequestType)requestType
                            extraParams:(NSDictionary *)extraParams
                      completionHandler:(ASPerformDynamicPricingCallback)callback __attribute__((deprecated("Please use requestSimpliPay:billURL:paymentOption:useMVC:useCash:useDynamicPrice:ruleInfo:andParentViewController:completionHandler: instead")));


/*!
 *  @brief requestPerformDynamicPricingRule.
 *
 *  @param ruleInfo    The Transaction Amount.
 *  @param paymentInfo The paymentInfo CTSPaymentDetailUpdate.
 *  @param billUrl     The billUrl NSString.
 *  @param user        The user CTSUser.
 *  @param extraParams The extraParams NSDictionary.
 *  @param callback    The callback ASPerformDynamicPricingCallback.
 */
-(void)requestPerformDynamicPricingRule:(CTSRuleInfo *)ruleInfo
                            paymentInfo:(CTSPaymentDetailUpdate *)payment
                                billUrl:(NSString *)billUrl
                                   user:(CTSUser *)user
                            extraParams:(NSDictionary *)extraParams
                      completionHandler:(ASPerformDynamicPricingCallback)callback __attribute__((deprecated("Please use requestSimpliPay:billURL:paymentOption:useMVC:useCash:useDynamicPrice:ruleInfo:andParentViewController:completionHandler: instead")));

/*!
 *  @brief requestPerformDynamicPricingRule.
 *
 *  @param ruleInfo    The Transaction Amount.
 *  @param paymentInfo The paymentInfo CTSPaymentDetailUpdate.
 *  @param bill        The bill CTSBill.
 *  @param user        The user CTSUser.
 *  @param extraParams The extraParams NSDictionary.
 *  @param callback    The callback ASPerformDynamicPricingCallback.
 */
- (void)requestPerformDynamicPricingRule:(CTSRuleInfo *)ruleInfo
                             paymentInfo:(CTSPaymentDetailUpdate *)payment
                                    bill:(CTSBill *)bill
                                    user:(CTSUser *)user
                             extraParams:(NSDictionary *)extraParams
                       completionHandler:(ASPerformDynamicPricingCallback)callback DEPRECATED_ATTRIBUTE;

// for lazy pay only - moto call

/*!
 *  @brief requestChargePayment.
 *
 *  @param paymentInfo The paymentInfo CTSPaymentDetailUpdate.
 *  @param contactInfo The contactInfo CTSContactUpdate.
 *  @param userAddress The userAddress CTSUserAddress.
 *  @param bill        The bill CTSBill.
 *  @param returnURL   The returnURL NSString.
 *  @param custParams  The custParams NSDictionary.
 *  @param controller  The controller UIViewController.
 *  @param callback    The callback ASCitruspayCallback.
 */
- (void)requestChargePayment:(CTSPaymentDetailUpdate *)paymentInfo
                 withContact:(CTSContactUpdate *)contactInfo
                 withAddress:(CTSUserAddress *)userAddress
                        bill:(CTSBill *)bill
                setReturnURL:(NSString *)returnURL
                customParams:(NSDictionary *)custParams
        returnViewController:(UIViewController *)controller
       withCompletionHandler:(ASCitruspayCallback)callback;
/**
 ***************************************************************************************************************
 DEPRECATED END
 ***************************************************************************************************************
 */


/*!
 *  @brief requestDPQueryMerchant.
 *
 *  @param merchantAccessKey The Transaction Amount.
 *  @param signature         The Transaction Amount.
 *  @param callback          The Transaction Amount.
 */
- (void)requestDPQueryMerchant:(NSString *)merchantAccessKey
                     signature:(NSString *)signature
             completionHandler:(ASPerformDynamicPricingCallback)callback;

/**
 *  request card pament options(visa,master,debit) and netbanking settngs for
 *the merchant
 *
 *  @param vanityUrl: pass in unique vanity url obtained from Citrus Payment
 *sol.
 */
- (void)requestMerchantPgSettings:(NSString*)vanityUrl
            withCompletionHandler:(ASGetMerchantPgSettingsCallBack)callback;

/*!
 *  @brief requestGetPrepaidBillForAmount.
 *
 *  @param amount    The Transaction Amount.
 *  @param returnUrl The Transaction Amount.
 *  @param callback  The Transaction Amount.
 */
-(void)requestGetPrepaidBillForAmount:(NSString *)amount
                            returnUrl:(NSString *)returnUrl
                withCompletionHandler:(ASGetPrepaidBill)callback;

/*!
 *  @brief requestCashoutToBank.
 *
 *  @param bankAccount The Transaction Amount.
 *  @param amount      The Transaction Amount.
 *  @param callback    The Transaction Amount.
 */
-(void)requestCashoutToBank:(CTSCashoutBankAccount *)bankAccount
                     amount:(NSString *)amount
          completionHandler:(ASCashoutToBankCallBack)callback;

/**
 @brief            get PG Health percentage.
 @param callback   Set success/failure callBack.
 @details          It will return JSON of PG health into bank code with percentage value.
 */

-(void)requestGetPGHealthWithCompletionHandler:(ASGetPGHealth)callback;

/*!
 *  @brief requestCardDetails.
 *
 *  @param firstSix The Transaction Amount.
 *  @param callback The Transaction Amount.
 */
-(void)requestCardDetails:(NSString *)firstSix
        completionHandler:(ASCardBinServiceCallback)callback;

/*!
 *  @brief requestTransferMoneyTo.
 *
 *  @param username The Transaction Amount.
 *  @param amount   The Transaction Amount.
 *  @param message  The Transaction Amount.
 *  @param callback The Transaction Amount.
 */
-(void)requestTransferMoneyTo:(NSString *)username
                       amount:(NSString *)amount
                      message:(NSString *)message
            completionHandler:(ASMoneyTransferCallback)callback;

/*!
 *  @brief requestLoadMoneyPgSettingsCompletionHandler.
 *
 *  @param callback The Transaction Amount.
 */
- (void)requestLoadMoneyPgSettingsCompletionHandler:(ASGetMerchantPgSettingsCallBack)callback;


/**
 ***************************************************************************************************************
 SIMPLIPAY - SINGLE PAYMEN INTERFACE
 ***************************************************************************************************************
 */
/*!
 *  @brief SimpliPay Init Orchestration Layer For All Payment Single End Point.
 *
 *  @param paymentType The PaymentType (MVCPayment/citrusCashPayment/PGPayment/performDynamicPricing/splitPayment/loadMoney).
 *  @param controller  The Current Controller Self Object.
 *  @param completion  The Callback into PaymentReceipt & Error.
 */
- (void)requestSimpliPay:(PaymentType *)paymentType
 andParentViewController:(UIViewController *)controller
       completionHandler:(CTSSmartPayCompletionHandler)completion;

/*!
 *  @brief Request Calculate Payment Distribution - for Split Payment.
 *
 *  @param amount     The Transaction Amount.
 *  @param completion The callback into AmountDistribution viz mvcAmount, cashAmount, remainingAmount & totalAmount, BOOL useMVC, useCash & enoughMVCAndCash.
 */
- (void)requestCalculatePaymentDistribution:(NSString *)amount
                          completionHandler:(CTSPaymentDistributionCompletionHandler)completion;



/**
 ***************************************************************************************************************
 AUTOLOAD
 ***************************************************************************************************************
 */

/*!
 *  @brief requestUpdateAutoLoadSubId.
 *
 *  @param subId           The subId NSString.
 *  @param autoLoadAmt     The autoLoadAmt NSString.
 *  @param thresholdAmount The thresholdAmount NSString.
 *  @param callback        The callback ASAutoLoadCallback.
 */
-(void)requestUpdateAutoLoadSubId:(NSString *)subId
                   autoLoadAmount:(NSString *)autoLoadAmt
                  thresholdAmount:(NSString *)thresholdAmount
                       completion:(ASAutoLoadCallback)callback;

/*!
 *  @brief requestGetAutoLoadSubType.
 *
 *  @param type     The type AutoLoadSubsctiptionType.
 *  @param callback The callback ASGetAutoloadSubsCallback.
 */
-(void)requestGetAutoLoadSubType:(AutoLoadSubsctiptionType)type
                      completion:(ASGetAutoloadSubsCallback)callback;

/*!
 *  @brief requestGetActiveAutoLoadSubscription.
 *
 *  @param callback The callback ASAutoLoadCallback.
 */
-(void)requestGetActiveAutoLoadSubscription:(ASAutoLoadCallback)callback;

/*!
 *  @brief requestDeactivateAutoLoadSubId.
 *
 *  @param subId    The subId subId.
 *  @param callback The callback ASAutoLoadCallback.
 */
-(void)requestDeactivateAutoLoadSubId:(NSString*)subId
                           completion:(ASAutoLoadCallback)callback;

/*!
 *  @brief requestDeactivateAutoLoadSubscription.
 *
 *  @param callback The callback ASAutoLoadCallback.
 */
-(void)requestDeactivateAutoLoadSubscription:(ASAutoLoadCallback)callback;

/*!
 *  @brief requestLoadAndSubscribe.
 *
 *  @param loadMoney The loadMoney CTSLoadMoney.
 *  @param autoload  The autoload CTSAutoLoad.
 *  @param callback  The callback ASLoadAndSubscribeCallback.
 */
- (void)requestLoadAndSubscribe:(CTSLoadMoney*)loadMoney
                       autoLoad:(CTSAutoLoad *)autoload
              withCompletionHandler:(ASLoadAndSubscribeCallback)callback;

/*!
 *  @brief requestSubscribeAutoAfterLoad.
 *
 *  @param autoload The autoload CTSAutoLoad.
 *  @param callback The callback ASAutoLoadCallback.
 */
- (void)requestSubscribeAutoAfterLoad:(CTSAutoLoad *)autoload
          withCompletionHandler:(ASAutoLoadCallback)callback;

/*!
 *  @brief requestLoadAndIncrementAutoloadSubId.
 *
 *  @param subId     The subId NSString.
 *  @param loadMoney The loadMoney CTSLoadMoney.
 *  @param autoload  The autoload CTSLoadMoney.
 *  @param callback  The callback ASLoadAndSubscribeCallback.
 */
- (void)requestLoadAndIncrementAutoloadSubId:(NSString *)subId
                                   loadMoney:(CTSLoadMoney*)loadMoney
                                    autoLoad:(CTSAutoLoad *)autoload
                       withCompletionHandler:(ASLoadAndSubscribeCallback)callback;




/**
 ***************************************************************************************************************
 INTERNAL USAGE METHODS
 ***************************************************************************************************************
 */

/*!
 *  @brief configureReqPayment.
 *
 *  @param paymentInfo       The paymentInfo CTSPaymentDetailUpdate.
 *  @param contact           The contact CTSContactUpdate.
 *  @param address           The address CTSUserAddress.
 *  @param amount            The amount NSString.
 *  @param returnUrl         The returnUrl NSString.
 *  @param notifyUrl         The notifyUrl NSString.
 *  @param signatureArg      The signatureArg NSString.
 *  @param txnId             The txnId NSString.
 *  @param merchantAccessKey The merchantAccessKey NSString.
 *  @param custParams        The custParams NSDictionary.
 *  @param origin            The origin NSString.
 *
 *  @return The CTSPaymentRequest Object.
 */
- (CTSPaymentRequest*)configureReqPayment:(CTSPaymentDetailUpdate*)paymentInfo
                                  contact:(CTSContactUpdate*)contact
                                  address:(CTSUserAddress*)address
                                   amount:(NSString*)amount
                                returnUrl:(NSString*)returnUrl
                                notifyUrl:(NSString*)notifyUrl
                                signature:(NSString*)signatureArg
                                    txnId:(NSString*)txnId
                           merchantAccess:(NSString *)merchantAccessKey
                           withCustParams:(NSDictionary *)custParams
                                   origin:(NSString *)origin;

/*!
 *  @brief displayOverlay.
 *
 *  @param overlay The overlay HVDOverlay.
 *
 *  @return The HVDOverlay Object.
 */
-(HVDOverlay *)displayOverlay:(HVDOverlay *)overlay;

/*!
 *  @brief cvvEncrypt.
 *
 *  @param response The response CTSCitrusCashRes.
 *  @param error    The error AmoNSErrorunt.
 */
-(void)cvvEncrypt:(CTSCitrusCashRes *)response error:(NSError *)error;

@end
