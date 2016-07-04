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

//-(instancetype)init __attribute__((unavailable("init not available Please use [CitrusPaymentSDK fetchSharedPaymentLayer]")));



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

//Vikas New Payment API
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




/**
 * called when client request to make payment through credit card/debit card

 *
 *  @param paymentInfo Payment Information
 *  @param contactInfo contact Information
 *  @param amount      payment amount
 */
/*- (void)makePaymentByCard:(CTSPaymentDetailUpdate*)paymentInfo
 withContact:(CTSContactUpdate*)contactInfo
 amount:(NSString*)amount
 withSignature:(NSString*)signature
 withTxnId:(NSString*)merchantTxnId;
 */

/**
 *  to make signed user's payment for netbanking/credit/debit card depending on
 *paymentInfo configuration
 *
 *  @param paymentInfo Payment Information
 *  @param contactInfo contact Information
 *  @param amount      payment amount
 */


//- (void)makeUserPayment:(CTSPaymentDetailUpdate*)paymentInfo
//              withContact:(CTSContactUpdate*)contactInfo
//              withAddress:(CTSUserAddress*)userAddress
//                   amount:(NSString*)amount
//            withReturnUrl:(NSString*)returnUrl
//            withSignature:(NSString*)signature
//                withTxnId:(NSString*)merchantTxnId
//    withCompletionHandler:(ASMakeUserPaymentCallBack)callback;






//////////// DEPRECATED
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
              withCompletionHandler:(ASLoadMoneyCallBack)callback DEPRECATED_MSG_ATTRIBUTE("use requestLoadMoneyInCitrusPay:withContact:withAddress:amount:returnUrl:customParams:returnViewController:withCompletionHandler:");

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
////////////////////// END DEPRECATED



//new prepaid pay api

- (void)requestChargeCitrusWalletWithContact:(CTSContactUpdate*)contactInfo
                               address:(CTSUserAddress*)userAddress
                                      bill:(CTSBill *)bill
                      returnViewController:(UIViewController *)controller
                     withCompletionHandler:(ASCitruspayCallback)callback;


- (void)requestChargePayment:(CTSPaymentDetailUpdate*)paymentInfo
                 withContact:(CTSContactUpdate*)contactInfo
                 withAddress:(CTSUserAddress*)userAddress
                        bill:(CTSBill *)bill
                customParams:(NSDictionary *)custParams
        returnViewController:(UIViewController *)controller
       withCompletionHandler:(ASCitruspayCallback)callback;


- (void)requestDirectChargePayment:(CTSPaymentDetailUpdate*)paymentInfo
                    withContact:(CTSContactUpdate*)contactInfo
                    withAddress:(CTSUserAddress*)userAddress
                           bill:(CTSBill *)bill
           returnViewController:(UIViewController *)controller
          withCompletionHandler:(ASCitruspayCallback)callback;


- (void)requestLoadMoneyInCitrusPay:(CTSPaymentDetailUpdate *)paymentInfo
                        withContact:(CTSContactUpdate*)contactInfo
                        withAddress:(CTSUserAddress*)userAddress
                             amount:(NSString *)amount
                          returnUrl:(NSString *)returnUrl
                       customParams:(NSDictionary *)custParams
               returnViewController:(UIViewController *)controller
              withCompletionHandler:(ASCitruspayCallback)callback;


- (void)requestChargeDynamicPricingContact:(CTSContactUpdate*)contactInfo
                 withAddress:(CTSUserAddress*)userAddress
                customParams:(NSDictionary *)custParams
        returnViewController:(UIViewController *)controller
       withCompletionHandler:(ASCitruspayCallback)callback;


/**
 *  request card pament options(visa,master,debit) and netbanking settngs for
 *the merchant
 *
 *  @param vanityUrl: pass in unique vanity url obtained from Citrus Payment
 *sol.
 */
- (void)requestMerchantPgSettings:(NSString*)vanityUrl
            withCompletionHandler:(ASGetMerchantPgSettingsCallBack)callback;


-(void)requestGetPrepaidBillForAmount:(NSString *)amount returnUrl:(NSString *)returnUrl withCompletionHandler:(ASGetPrepaidBill)callback;


-(void)requestCashoutToBank:(CTSCashoutBankAccount *)bankAccount amount:(NSString *)amount completionHandler:(ASCashoutToBankCallBack)callback;

/**
 @brief            get PG Health percentage.
 @param callback   Set success/failure callBack.
 @details          It will return JSON of PG health into bank code with percentage value.
 */

-(void)requestGetPGHealthWithCompletionHandler:(ASGetPGHealth)callback;

-(void)requestCardDetails:(NSString *)firstSix completionHandler:(ASCardBinServiceCallback)callback;

-(void)requestDPQueryMerchant:(NSString *)merchantAccessKey signature:(NSString *)signature completionHandler:(ASPerformDynamicPricingCallback)callback;

-(void)requestDPRuleCheck:(CTSDyPValidateRuleReq *)validateRule type:(DPRequestType)requestType  completionHandler:(ASPerformDynamicPricingCallback)callback;

-(void)requestTransferMoneyTo:(NSString *)username amount:(NSString *)amount message:(NSString *)message completionHandler:(ASMoneyTransferCallback)callback;

-(void)requestPerformDynamicPricingRule:(CTSRuleInfo *)ruleInfo paymentInfo:(CTSPaymentDetailUpdate *)payment bill:(CTSBill *)bill user:(CTSUser *)user type:(DPRequestType)requestType extraParams:(NSDictionary *)extraParams completionHandler:(ASPerformDynamicPricingCallback)callback;

-(void)requestPerformDynamicPricingRule:(CTSRuleInfo *)ruleInfo paymentInfo:(CTSPaymentDetailUpdate *)payment billUrl:(NSString *)billUrl user:(CTSUser *)user  extraParams:(NSDictionary *)extraParams completionHandler:(ASPerformDynamicPricingCallback)callback;

- (void)requestLoadMoneyPgSettingsCompletionHandler:(ASGetMerchantPgSettingsCallBack)callback;

@end
