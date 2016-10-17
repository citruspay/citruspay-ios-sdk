//
//  CTSProfileLayer.h
//  RestFulltester
//
//  Created by Yadnesh Wankhede on 04/06/14.
//  Copyright (c) 2014 Citrus. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CTSRestPluginBase.h"

#import "CTSNewContactProfile.h"
#import "CTSProfilePaymentRes.h"
#import "CTSContactUpdate.h"
#import "CTSUserAddress.h"
#import "CTSUserProfile.h"
#import "CTSSaveCardResponse.h"
#import "CTSProfileUpdate.h"
#import "CTSCashoutBankAccount.h"
#import "CTSCashoutBankAccountResp.h"
#import "CTSAmount.h"
#import "CTSProfileContactRes.h"
#import "CTSUpdateMobileNumberRes.h"
#import "CTSDPResponse.h"
#import "CTSPaymentDetailUpdate.h"
#import "CTSDPMerchantQueryReq.h"


#import "CTSConsumerProfile.h"
#import "CTSDPMerchantQueryReq.h"
#import "CTSPaymentOptions.h"

/// Class Models.
@class CTSAmount, CTSProfileContactRes, CTSCashoutBankAccountResp, CTSUpdateMobileNumberRes, CTSDPResponse, CTSPaymentDetailUpdate, CTSCashoutBankAccount;

/// CTSProfileLayer.
@class CTSProfileLayer;

/**
 *   CTSProfileProtocol.
 */
@protocol CTSProfileProtocol
/**
 *  called when client requests for contact information
 *
 *  @param contactInfo nil in case of error
 *  @param error       nil when successful
 */
@optional
- (void)profile:(CTSProfileLayer*)profile
    didReceiveContactInfo:(CTSProfileContactRes*)contactInfo
                    error:(NSError*)error;
/**
 *  called when client requests for payment information
 *
 *  @param contactInfo nil in case of error
 *  @param error       nil when succesful
 */
@optional
- (void)profile:(CTSProfileLayer*)profile
    didReceivePaymentInformation:(CTSProfilePaymentRes*)contactInfo
                           error:(NSError*)error;
/**
 *  when contact information is updated to server
 *
 *  @param error error if happned
 */
@optional
- (void)profile:(CTSProfileLayer*)profile
    didUpdateContactInfoError:(NSError*)error;

/**
 *  when payment information is updated on server
 *
 *  @param error nil when successful
 */
@optional
- (void)profile:(CTSProfileLayer*)profile
    didUpdatePaymentInfoError:(NSError*)error;

/**
 *   didGetBalance.
 *
 *  @param layer The layer CTSProfileLayer.
 *  @param amount The amount CTSAmount.
 *  @param error The error NSError.
 */
@optional
- (void)profile:(CTSProfileLayer*)profile
  didGetBalance:(CTSAmount *)amount
               error:(NSError*)error;

/**
 *   didAddCashoutAccount.
 *
 *  @param layer The layer CTSProfileLayer.
 *  @param error The error NSError.
 */
@optional
- (void)profile:(CTSProfileLayer*)profile
  didAddCashoutAccount:(NSError*)error;


/**
 *   didReceiveCashoutAccount.
 *
 *  @param layer The layer CTSProfileLayer.
 *  @param cashoutAccount The cashoutAccount CTSCashoutBankAccountResp.
 *  @param error The error NSError.
 */
@optional
- (void)profile:(CTSProfileLayer*)profile
didReceiveCashoutAccount:(CTSCashoutBankAccountResp *)cashoutAccount
          error:(NSError*)error;

/**
 *   didGetNewProfile.
 *
 *  @param layer The layer CTSProfileLayer.
 *  @param profile The profile CTSNewContactProfile.
 *  @param error The error NSError.
 */
@optional
- (void)profile:(CTSProfileLayer*)profile
didGetNewProfile:(CTSNewContactProfile *)profile
          error:(NSError*)error;

/**
 *   didDeleteCardWithError.
 *
 *  @param layer The layer CTSProfileLayer.
 *  @param error The error NSError.
 */
@optional
- (void)profile:(CTSProfileLayer*)profile
didDeleteCardWithError:(NSError*)error;
@end


/**
 *   The CTSProfileLayer class' ASGetContactInfoCallBack CallBack.
 *
 *  @return The Newly created contactInfo, error object.
 */
typedef void (^ASGetContactInfoCallBack)(CTSProfileContactRes* contactInfo, NSError* error);
/**
 *   The CTSProfileLayer class' ASGetPaymentInfoCallBack CallBack.
 *
 *  @return The Newly created CTSConsumerProfile, error object.
 */
typedef void (^ASGetPaymentInfoCallBack)(CTSConsumerProfile *, NSError *);
/**
 *   The CTSProfileLayer class' ASUpdatePaymentInfoCallBack CallBack.
 *
 *  @return The Newly created error object.
 */
typedef void (^ASUpdatePaymentInfoCallBack)(NSError* error);
/**
 *   The CTSProfileLayer class' ASUpdateContactInfoCallBack CallBack.
 *
 *  @return The Newly created error object.
 */
typedef void (^ASUpdateContactInfoCallBack)(NSError* error);
/**
 *   The CTSProfileLayer class' ASGetBalanceCallBack CallBack.
 *
 *  @return The Newly created amount, error object.
 */
typedef void (^ASGetBalanceCallBack)(CTSAmount *amount, NSError* error);
/**
 *   The CTSProfileLayer class' ASActivatePrepaidCallBack CallBack.
 *
 *  @return The Newly created isActivated, error object.
 */
typedef void (^ASActivatePrepaidCallBack)(BOOL isActivated, NSError* error);
/**
 *   The CTSProfileLayer class' ASUpdateCashoutBankAccountCallback CallBack.
 *
 *  @return The Newly created error object.
 */
typedef void (^ASUpdateCashoutBankAccountCallback)(NSError* error);
/**
 *   The CTSProfileLayer class' ASGetCashoutBankAccountCallback CallBack.
 *
 *  @return The Newly created bankAccount, error object.
 */
typedef void (^ASGetCashoutBankAccountCallback)(CTSCashoutBankAccountResp *bankAccount, NSError* error);
/**
 *   The CTSProfileLayer class' ASNewContactProfileCallback CallBack.
 *
 *  @return The Newly created profile, error object.
 */
typedef void (^ASNewContactProfileCallback)(CTSNewContactProfile* profile, NSError*error);
/**
 *   The CTSProfileLayer class' ASUpdateMobileNumberCallback CallBack.
 *
 *  @return The Newly created updateMobileNumber, error object.
 */
typedef void (^ASUpdateMobileNumberCallback)(CTSUpdateMobileNumberRes *updateMobileNumber, NSError* error);
/**
 *   The CTSProfileLayer class' ASDeleteCardCallback CallBack.
 *
 *  @return The Newly created error object.
 */
typedef void (^ASDeleteCardCallback)(NSError* error);
/**
 *   The CTSProfileLayer class' ASDPMerchantQueryCallback CallBack.
 *
 *  @return The Newly created reponse, error object.
 */
typedef void (^ASDPMerchantQueryCallback)(CTSDPResponse *reponse, NSError* error);
/**
 *   The CTSProfileLayer class' ASGetProfileInfoCallBack CallBack.
 *
 *  @return The Newly created userProfile, error object.
 */
typedef void (^ASGetProfileInfoCallBack)(CTSUserProfile *userProfile, NSError* error);
/**
 *   The CTSProfileLayer class' ASUpdateProfileInfoCallBack CallBack.
 *
 *  @return The Newly created error object.
 */
typedef void (^ASUpdateProfileInfoCallBack)(NSError* error);
/**
 *   The CTSProfileLayer class' ASSaveCardsCallback CallBack.
 *
 *  @return The Newly created reponse, error object.
 */
typedef void (^ASSaveCardsCallback) (CTSSaveCardResponse *reponse, NSError *error);


/**
 *   CTSProfileLayer.
 */
@interface CTSProfileLayer : CTSRestPluginBase

/**
 *   The CTSProfileLayer class' delegate object.
 */
@property (weak) id <CTSProfileProtocol> delegate;

/**
 *   initWithKeyStore.
 *
 *  @param keystoreArg The signinId String, signUpId String, signinSecret String, signUpSecret String and vanity String.
 *
 *  @return The Newly created object.
 */
- (instancetype)initWithKeyStore:(CTSKeyStore *)keystoreArg;

//-(instancetype)init __attribute__((unavailable("init not available Please use [CitrusPaymentSDK fetchSharedProfileLayer]")));

/**
 *   Fetch Shared ProfileLayer.
 *
 *  @return The ProfileLayer object.
 */
+(CTSProfileLayer*)fetchSharedProfileLayer;

/**
 *   update contact related information
 *
 *  @param contactInfo The contactInfo CTSContactUpdate.
 *  @param callback    The callback ASUpdateContactInfoCallBack.
 */
- (void)updateContactInformation:(CTSContactUpdate*)contactInfo
           withCompletionHandler:(ASUpdateContactInfoCallBack)callback;

/**
 *   update payment related information
 *
 *  @param paymentOptions The paymentOptions CTSPaymentOptions.
 *  @param callback       The callback ASUpdatePaymentInfoCallBack.
 */
- (void)updatePaymentInfo:(CTSPaymentOptions *)paymentOption
    withCompletionHandler:(ASUpdatePaymentInfoCallBack)callback;

/**
 *   update payment related information
 *
 *  @param paymentOptions The paymentOptions CTSPaymentDetailUpdate.
 *  @param callback       The callback ASUpdatePaymentInfoCallBack.
 */
- (void)updatePaymentInformation:(CTSPaymentDetailUpdate *)paymentInfo
           withCompletionHandler:(ASUpdatePaymentInfoCallBack)callback;

/**
 *   to request contact related information
 *
 *  @param callback The callback ASGetContactInfoCallBack.
 */
- (void)requestContactInformationWithCompletionHandler:
        (ASGetContactInfoCallBack)callback;

/**
 *   request user's payment information
 *
 *  @param completion The completion ASGetPaymentInfoCallBack.
 */
- (void)requestPaymentInformationWithCompletionHandler:(ASGetPaymentInfoCallBack)completion;

/**
 *   requestGetBalance.
 *
 *  @param calback The calback ASGetBalanceCallBack.
 */
-(void)requestGetBalance:(ASGetBalanceCallBack)calback;

/**
 *   requestActivateAndGetBalance.
 *
 *  @param calback The calback ASGetBalanceCallBack.
 */
-(void)requestActivateAndGetBalance:(ASGetBalanceCallBack)calback;


/**
 *   requestActivatePrepaidAccount.
 *
 *  @param callback The callback ASActivatePrepaidCallBack.
 */
-(void)requestActivatePrepaidAccount:(ASActivatePrepaidCallBack)callback;


/**
 *   requestUpdateCashoutBankAccount.
 *
 *  @param bankAccount The bankAccount CTSCashoutBankAccount.
 *  @param callback    The callback ASUpdateCashoutBankAccountCallback.
 */
- (void)requestUpdateCashoutBankAccount:(CTSCashoutBankAccount*)bankAccount
           withCompletionHandler:(ASUpdateCashoutBankAccountCallback)callback;

/**
 *   requestCashoutBankAccountCompletionHandler.
 *
 *  @param callback The callback ASGetCashoutBankAccountCallback.
 */
-(void)requestCashoutBankAccountCompletionHandler:(ASGetCashoutBankAccountCallback)callback;

/**
 *   requestMemberInfoMobile.
 *
 *  @param mobile   The mobile NSString.
 *  @param email    The email NSString.
 *  @param callback The callback ASNewContactProfileCallback.
 */
-(void)requestMemberInfoMobile:(NSString *)mobile
                         email:(NSString *)email
         withCompletionHandler:(ASNewContactProfileCallback)callback;

/**
 *   update mobile number - Use this method For update new mobile number.
 *
 *  @param mobileNumber The mobileNumber NSString.
 *  @param callback     The callback ASUpdateMobileNumberCallback.
 */
- (void)requestUpdateMobile:(NSString *)mobileNumber
      WithCompletionHandler:(ASUpdateMobileNumberCallback)callback;


/**
 *   delete Saved Card - Use this method For delete saved cards.
 *
 *  @param lastFourDigits Last four digits of the saved card.
 *  @param scheme         correct scheme of the card.
 *  @param callback       The callback ASDeleteCardCallback.
 */
-(void)requestDeleteCard:(NSString *)lastFourDigits
                  scheme:(NSString *)scheme
   withCompletionHandler:(ASDeleteCardCallback)callback;

/**
 *   requestDeleteCardWithToken.
 *
 *  @param token    The token NSString.
 *  @param callback The callback ASDeleteCardCallback.
 */
-(void)requestDeleteCardWithToken:(NSString *)token
            withCompletionHandler:(ASDeleteCardCallback)callback;

/**
 *   requestDpMerchantQuery.
 *
 *  @param request  The request CTSDPMerchantQueryReq.
 *  @param callback The callback ASDPMerchantQueryCallback.
 */
-(void)requestDpMerchantQuery:(CTSDPMerchantQueryReq *)request
            completionHandler:(ASDPMerchantQueryCallback)callback;

/**
 *   requestUpdateProfileInformation.
 *
 *  @param profileInfo The profileInfo CTSProfileUpdate.
 *  @param callback    The callback ASUpdateProfileInfoCallBack.
 */
- (void)requestUpdateProfileInformation:(CTSProfileUpdate *)profileInfo
                  withCompletionHandler:(ASUpdateProfileInfoCallBack)callback;

/**
 *   requestProfileInformationWithCompletionHandler.
 *
 *  @param callback The callback ASGetProfileInfoCallBack.
 */
- (void)requestProfileInformationWithCompletionHandler:(ASGetProfileInfoCallBack)callback;

/**
 *   requestSaveCard.
 *
 *  @param paymentInfo The paymentInfo CTSPaymentDetailUpdate.
 *  @param callback    The callback ASSaveCardsCallback.
 */
-(void)requestSaveCard:(CTSPaymentDetailUpdate*)paymentInfo
            completion:(ASSaveCardsCallback )callback;
@end
