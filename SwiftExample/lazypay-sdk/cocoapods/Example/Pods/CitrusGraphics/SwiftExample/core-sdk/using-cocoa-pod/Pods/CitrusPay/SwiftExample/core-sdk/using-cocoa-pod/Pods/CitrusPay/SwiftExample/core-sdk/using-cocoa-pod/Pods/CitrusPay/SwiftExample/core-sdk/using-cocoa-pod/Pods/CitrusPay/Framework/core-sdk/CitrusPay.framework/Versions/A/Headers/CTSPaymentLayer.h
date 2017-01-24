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

@class   CTSPaymentWebViewController , CTSContactUpdate, CTSUserAddress;

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


typedef enum{
    AutoLoadSubsctiptionTypeActive,
    AutoLoadSubsctiptionTypeInActive,
    AutoLoadSubsctiptionTypeAll
}AutoLoadSubsctiptionType;


typedef enum{
    CitrusPaymentTypeDirect,
    CitrusPaymentTypeCitrusCash,
}CitrusPaymentType;

extern NSString * const LoadMoneyResponeKey;

#define LogThread LogTrace(@"THREAD  %@", [NSThread currentThread]);

@class CTSAuthLayer;
@class CTSAuthenticationProtocol;
@class CTSPaymentLayer;

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
didMakeNewPaymentUsingGuestFlow:(NSString*)responseString error:(NSError*)error;

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

@interface CTSPaymentLayer : CTSRestPluginBase<CTSAuthenticationProtocol, UIWebViewDelegate> {
    BOOL finished;
    NSString *cCashReturnUrl;
    PaymentRequestType prepaidRequestType;
    CTSPaymentDetailUpdate *tempCVVStoreObject;
}
@property(strong)UIViewController *citrusCashBackViewController;
@property(strong)UIWebView *citrusPayWebview;
@property(strong) NSString* merchantTxnId;
@property(strong) NSString* signature;
@property(weak) id<CTSPaymentProtocol> delegate;
@property(strong) CTSPaymentWebViewController *paymentWebViewController;


+(CTSPaymentLayer*)fetchSharedPaymentLayer ;
- (instancetype)initWithUrl:(NSString *)url;
- (instancetype)initWithKeyStore:(CTSKeyStore *)keystoreArg;

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

typedef void (^ASMoneyTransferCallback)(CTSTransferMoneyResponse* transferMoneyRes ,NSError* error);

typedef void (^ASCardBinServiceCallback)(CTSCardBinResponse* cardBinResponse ,NSError* error);

typedef void (^ASPrepaidPayCallback)(CTSPrepaidPayResp* prepaidPay ,NSError* error);

// CallBack Handlers
typedef void (^CTSSmartPayCompletionHandler)(CTSPaymentReceipt *paymentReceipt,
                                             NSError *error);

typedef void (^CTSPaymentDistributionCompletionHandler)(CTSSimpliChargeDistribution *amountDistribution,
                                                        NSError *error);
typedef void (^ASGetAutoloadSubsCallback)(CTSAutoLoadSubGetResp* autoloadSubscriptions ,NSError* error);

typedef void (^ASAutoLoadCallback)( CTSAutoLoadSubResp *autoloadResponse  ,NSError* error);

typedef void (^ASLoadAndSubscribeCallback)(CTSLoadAndPayRes* loadAndSubscribe,
                                           NSError* error);

// DEPRECATED
- (void)requestChargeTokenizedPayment:(CTSPaymentDetailUpdate*)paymentInfo
                          withContact:(CTSContactUpdate*)contactInfo
                          withAddress:(CTSUserAddress*)userAddress
                                 bill:(CTSBill *)bill
                         customParams:(NSDictionary *)custParams
                withCompletionHandler:(ASMakeTokenizedPaymentCallBack)callback DEPRECATED_MSG_ATTRIBUTE("use requestChargePayment:withContact:withAddress:bill:customParams:returnViewController:withCompletionHandler:");

- (void)requestChargePayment:(CTSPaymentDetailUpdate*)paymentInfo
                 withContact:(CTSContactUpdate*)contactInfo
                 withAddress:(CTSUserAddress*)userAddress
                        bill:(CTSBill *)bill
                customParams:(NSDictionary *)custParams
       withCompletionHandler:(ASMakeGuestPaymentCallBack)callback
DEPRECATED_MSG_ATTRIBUTE("use requestChargePayment:withContact:withAddress:bill:customParams:returnViewController:withCompletionHandler:");

- (void)requestLoadMoneyInCitrusPay:(CTSPaymentDetailUpdate *)paymentInfo
                        withContact:(CTSContactUpdate*)contactInfo
                        withAddress:(CTSUserAddress*)userAddress
                             amount:( NSString *)amount
                          returnUrl:(NSString *)returnUrl
                       customParams:(NSDictionary *)custParams
              withCompletionHandler:(ASLoadMoneyCallBack)callback  __attribute__((deprecated("Please use requestLoadMoney:returnURL:paymentOption:andParentViewController:completionHandler: instead")));

//new prepaid pay api
- (void)requestChargeCitrusWalletWithContact:(CTSContactUpdate*)contactInfo
                                     address:(CTSUserAddress*)userAddress
                                        bill:(CTSBill *)bill
                        returnViewController:(UIViewController *)controller
                       withCompletionHandler:(ASCitruspayCallback)callback __attribute__((deprecated("Please use requestSimpliPay:billURL:paymentOption:useMVC:useCash:useDynamicPrice:ruleInfo:andParentViewController:completionHandler: instead")));


//old prepaid pay api
- (void)requestChargeCitrusCashWithContact:(CTSContactUpdate*)contactInfo
                               withAddress:(CTSUserAddress*)userAddress
                                      bill:(CTSBill *)bill
                              customParams:(NSDictionary *)custParams
                      returnViewController:(UIViewController *)controller
                     withCompletionHandler:(ASCitruspayCallback)callback DEPRECATED_MSG_ATTRIBUTE("Use requestChargeCitrusWalletWithContact:address:bill:customParams:returnViewController:withCompletionHandler: ");

- (void)requestChargeTokenizedPayment:(CTSPaymentDetailUpdate*)paymentInfo
                          withContact:(CTSContactUpdate*)contactInfo
                          withAddress:(CTSUserAddress*)userAddress
                                 bill:(CTSBill *)bill
                         customParams:(NSDictionary *)custParams
                 returnViewController:(UIViewController *)controller
                withCompletionHandler:(ASCitruspayCallback)callback DEPRECATED_MSG_ATTRIBUTE("use requestChargePayment:withContact:withAddress:bill:customParams:returnViewController:withCompletionHandler:");


// single hop
- (void)requestDirectChargePayment:(CTSPaymentDetailUpdate*)paymentInfo
                       withContact:(CTSContactUpdate*)contactInfo
                       withAddress:(CTSUserAddress*)userAddress
                              bill:(CTSBill *)bill
              returnViewController:(UIViewController *)controller
             withCompletionHandler:(ASCitruspayCallback)callback __attribute__((deprecated("Please use requestSimpliPay:billURL:paymentOption:useMVC:useCash:useDynamicPrice:ruleInfo:andParentViewController:completionHandler: instead")));


//moto call
- (void)requestChargePayment:(CTSPaymentDetailUpdate*)paymentInfo
                 withContact:(CTSContactUpdate*)contactInfo
                 withAddress:(CTSUserAddress*)userAddress
                        bill:(CTSBill *)bill
                customParams:(NSDictionary *)custParams
        returnViewController:(UIViewController *)controller
       withCompletionHandler:(ASCitruspayCallback)callback __attribute__((deprecated("Please use requestSimpliPay:billURL:paymentOption:useMVC:useCash:useDynamicPrice:ruleInfo:andParentViewController:completionHandler: instead")));


- (void)requestLoadMoneyInCitrusPay:(CTSPaymentDetailUpdate *)paymentInfo
                        withContact:(CTSContactUpdate*)contactInfo
                        withAddress:(CTSUserAddress*)userAddress
                             amount:(NSString *)amount
                          returnUrl:(NSString *)returnUrl
                       customParams:(NSDictionary *)custParams
               returnViewController:(UIViewController *)controller
              withCompletionHandler:(ASCitruspayCallback)callback __attribute__((deprecated("Please use requestLoadMoney:returnURL:paymentOption:andParentViewController:completionHandler: instead")));


- (void)requestChargeDynamicPricingContact:(CTSContactUpdate*)contactInfo
                               withAddress:(CTSUserAddress*)userAddress
                              customParams:(NSDictionary *)custParams
                      returnViewController:(UIViewController *)controller
                     withCompletionHandler:(ASCitruspayCallback)callback;

-(void)requestPerformDynamicPricingRule:(CTSRuleInfo *)ruleInfo
                            paymentInfo:(CTSPaymentDetailUpdate *)payment
                                   bill:(CTSBill *)bill
                                   user:(CTSUser *)user
                                   type:(DPRequestType)requestType
                            extraParams:(NSDictionary *)extraParams
                      completionHandler:(ASPerformDynamicPricingCallback)callback __attribute__((deprecated("Please use requestSimpliPay:billURL:paymentOption:useMVC:useCash:useDynamicPrice:ruleInfo:andParentViewController:completionHandler: instead")));

-(void)requestPerformDynamicPricingRule:(CTSRuleInfo *)ruleInfo
                            paymentInfo:(CTSPaymentDetailUpdate *)payment
                                billUrl:(NSString *)billUrl
                                   user:(CTSUser *)user
                            extraParams:(NSDictionary *)extraParams
                      completionHandler:(ASPerformDynamicPricingCallback)callback __attribute__((deprecated("Please use requestSimpliPay:billURL:paymentOption:useMVC:useCash:useDynamicPrice:ruleInfo:andParentViewController:completionHandler: instead")));

- (void)requestPerformDynamicPricingRule:(CTSRuleInfo *)ruleInfo
                             paymentInfo:(CTSPaymentDetailUpdate *)payment
                                    bill:(CTSBill *)bill
                                    user:(CTSUser *)user
                             extraParams:(NSDictionary *)extraParams
                       completionHandler:(ASPerformDynamicPricingCallback)callback DEPRECATED_ATTRIBUTE;

//END DEPRECATED


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


-(void)requestGetPrepaidBillForAmount:(NSString *)amount
                            returnUrl:(NSString *)returnUrl
                withCompletionHandler:(ASGetPrepaidBill)callback;


-(void)requestCashoutToBank:(CTSCashoutBankAccount *)bankAccount
                     amount:(NSString *)amount
          completionHandler:(ASCashoutToBankCallBack)callback;

/**
 @brief            get PG Health percentage.
 @param callback   Set success/failure callBack.
 @details          It will return JSON of PG health into bank code with percentage value.
 */

-(void)requestGetPGHealthWithCompletionHandler:(ASGetPGHealth)callback;

-(void)requestCardDetails:(NSString *)firstSix
        completionHandler:(ASCardBinServiceCallback)callback;

-(void)requestTransferMoneyTo:(NSString *)username
                       amount:(NSString *)amount
                      message:(NSString *)message
            completionHandler:(ASMoneyTransferCallback)callback;

- (void)requestLoadMoneyPgSettingsCompletionHandler:(ASGetMerchantPgSettingsCallBack)callback;


/**
 *  internal methods
 ***************************************************************************************************************
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

-(HVDOverlay *)displayOverlay:(HVDOverlay *)overlay;

-(void)cvvEncrypt:(CTSCitrusCashRes *)response error:(NSError *)error;
/**
 ***************************************************************************************************************
 */



// Single Payment Interface - SimpliPay

/**
 *  requestSimpliPay - Single Payment Interface
 *
 *  @param paymentType - set paymentType (MVCPayment/citrusCashPayment/PGPayment/performDynamicPricing/splitPayment/loadMoney)
 *  @param andParentViewController - set current controller self object
 *  @param completionHandler - return callback into paymentReceipt & error
 */
- (void)requestSimpliPay:(PaymentType *)paymentType
 andParentViewController:(UIViewController *)controller
       completionHandler:(CTSSmartPayCompletionHandler)completion;

/**
 *  request calculate Payment Distribution - for split payment
 *
 *  @param amount - set transaction amount
 *  @param completionHandler - return callback into amountDistribution viz mvcAmount, 
    cashAmount, remainingAmount & totalAmount, BOOL useMVC, useCash & enoughMVCAndCash;
 */
- (void)requestCalculatePaymentDistribution:(NSString *)amount
                          completionHandler:(CTSPaymentDistributionCompletionHandler)completion;


// AutoLoad

-(void)requestUpdateAutoLoadSubId:(NSString *)subId autoLoadAmount:(NSString *)autoLoadAmt thresholdAmount:(NSString *)thresholdAmount completion:(ASAutoLoadCallback)callback;

-(void)requestGetAutoLoadSubType:(AutoLoadSubsctiptionType)type completion:(ASGetAutoloadSubsCallback)callback;

-(void)requestGetActiveAutoLoadSubscription:(ASAutoLoadCallback)callback;

-(void)requestDeactivateAutoLoadSubId:(NSString*)subId completion:(ASAutoLoadCallback)callback;

-(void)requestDeactivateAutoLoadSubscription:(ASAutoLoadCallback)callback;

- (void)requestLoadAndSubscribe:(CTSLoadMoney*)loadMoney
                       autoLoad:(CTSAutoLoad *)autoload
              withCompletionHandler:(ASLoadAndSubscribeCallback)callback;

- (void)requestSubscribeAutoAfterLoad:(CTSAutoLoad *)autoload
          withCompletionHandler:(ASAutoLoadCallback)callback;

- (void)requestLoadAndIncrementAutoloadSubId:(NSString *)subId
                                   loadMoney:(CTSLoadMoney*)loadMoney
                                    autoLoad:(CTSAutoLoad *)autoload
                       withCompletionHandler:(ASLoadAndSubscribeCallback)callback;



@end
