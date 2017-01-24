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

/*!
 *  @brief CTSProfileProtocol.
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

@optional
- (void)profile:(CTSProfileLayer*)profile
  didGetBalance:(CTSAmount *)amount
               error:(NSError*)error;

@optional
- (void)profile:(CTSProfileLayer*)profile
  didAddCashoutAccount:(NSError*)error;


@optional
- (void)profile:(CTSProfileLayer*)profile
didReceiveCashoutAccount:(CTSCashoutBankAccountResp *)cashoutAccount
          error:(NSError*)error;


@optional
- (void)profile:(CTSProfileLayer*)profile
didGetNewProfile:(CTSNewContactProfile *)profile
          error:(NSError*)error;


@optional
- (void)profile:(CTSProfileLayer*)profile
didDeleteCardWithError:(NSError*)error;
@end


typedef void (^ASGetContactInfoCallBack)(CTSProfileContactRes* contactInfo, NSError* error);

typedef void (^ASGetPaymentInfoCallBack)(CTSConsumerProfile *, NSError *);

typedef void (^ASUpdatePaymentInfoCallBack)(NSError* error);

typedef void (^ASUpdateContactInfoCallBack)(NSError* error);

typedef void (^ASGetBalanceCallBack)(CTSAmount *amount, NSError* error);

typedef void (^ASActivatePrepaidCallBack)(BOOL isActivated, NSError* error);

typedef void (^ASUpdateCashoutBankAccountCallback)( NSError* error);

typedef void (^ASGetCashoutBankAccountCallback)(CTSCashoutBankAccountResp *bankAccount, NSError* error);

typedef void (^ASNewContactProfileCallback)(CTSNewContactProfile* profile, NSError*error);

typedef void (^ASUpdateMobileNumberCallback)(CTSUpdateMobileNumberRes *updateMobileNumber, NSError* error);

typedef void (^ASDeleteCardCallback)(NSError* error);

typedef void (^ASDPMerchantQueryCallback)(CTSDPResponse*reponse, NSError* error);

typedef void (^ASGetProfileInfoCallBack)(CTSUserProfile *userProfile, NSError* error);

typedef void (^ASUpdateProfileInfoCallBack)(NSError* error);

typedef void (^ASSaveCardsCallback) (CTSSaveCardResponse *reponse, NSError *error);


/*!
 *  @brief CTSProfileLayer.
 */
@interface CTSProfileLayer : CTSRestPluginBase

/*!
 *  @brief The CTSProfileLayer class' delegate object.
 */
@property (weak) id <CTSProfileProtocol> delegate;

/*!
 *  @brief initWithKeyStore.
 *
 *  @param keystoreArg The signinId String, signUpId String, signinSecret String, signUpSecret String and vanity String.
 *
 *  @return The Newly created object.
 */
- (instancetype)initWithKeyStore:(CTSKeyStore *)keystoreArg;

//-(instancetype)init __attribute__((unavailable("init not available Please use [CitrusPaymentSDK fetchSharedProfileLayer]")));

/*!
 *  @brief Fetch Shared ProfileLayer.
 *
 *  @return The ProfileLayer object.
 */
+(CTSProfileLayer*)fetchSharedProfileLayer;

/*!
 *  @brief update contact related information
 *
 *  @param contactInfo The contactInfo CTSContactUpdate.
 *  @param callback    The callback ASUpdateContactInfoCallBack.
 */
- (void)updateContactInformation:(CTSContactUpdate*)contactInfo
           withCompletionHandler:(ASUpdateContactInfoCallBack)callback;

/*!
 *  @brief update payment related information
 *
 *  @param paymentOptions The paymentOptions CTSPaymentOptions.
 *  @param callback       The callback ASUpdatePaymentInfoCallBack.
 */
- (void)updatePaymentInformation:(CTSPaymentOptions *)paymentOptions
           withCompletionHandler:(ASUpdatePaymentInfoCallBack)callback;

/*!
 *  @brief to request contact related information
 *
 *  @param callback The callback ASGetContactInfoCallBack.
 */
- (void)requestContactInformationWithCompletionHandler:
        (ASGetContactInfoCallBack)callback;

/*!
 *  @brief request user's payment information
 *
 *  @param completion The completion ASGetPaymentInfoCallBack.
 */
- (void)requestPaymentInformationWithCompletionHandler:(ASGetPaymentInfoCallBack)completion;

/*!
 *  @brief requestGetBalance.
 *
 *  @param calback The calback ASGetBalanceCallBack.
 */
-(void)requestGetBalance:(ASGetBalanceCallBack)calback;

/*!
 *  @brief requestActivateAndGetBalance.
 *
 *  @param calback The calback ASGetBalanceCallBack.
 */
-(void)requestActivateAndGetBalance:(ASGetBalanceCallBack)calback;


/*!
 *  @brief requestActivatePrepaidAccount.
 *
 *  @param callback The callback ASActivatePrepaidCallBack.
 */
-(void)requestActivatePrepaidAccount:(ASActivatePrepaidCallBack)callback;


/*!
 *  @brief requestUpdateCashoutBankAccount.
 *
 *  @param bankAccount The bankAccount CTSCashoutBankAccount.
 *  @param callback    The callback ASUpdateCashoutBankAccountCallback.
 */
- (void)requestUpdateCashoutBankAccount:(CTSCashoutBankAccount*)bankAccount
           withCompletionHandler:(ASUpdateCashoutBankAccountCallback)callback;

/*!
 *  @brief requestCashoutBankAccountCompletionHandler.
 *
 *  @param callback The callback ASGetCashoutBankAccountCallback.
 */
-(void)requestCashoutBankAccountCompletionHandler:(ASGetCashoutBankAccountCallback)callback;

/*!
 *  @brief requestMemberInfoMobile.
 *
 *  @param mobile   The mobile NSString.
 *  @param email    The email NSString.
 *  @param callback The callback ASNewContactProfileCallback.
 */
-(void)requestMemberInfoMobile:(NSString *)mobile
                         email:(NSString *)email
         withCompletionHandler:(ASNewContactProfileCallback)callback;

/*!
 *  @brief update mobile number - Use this method For update new mobile number.
 *
 *  @param mobileNumber The mobileNumber NSString.
 *  @param callback     The callback ASUpdateMobileNumberCallback.
 */
- (void)requestUpdateMobile:(NSString *)mobileNumber
      WithCompletionHandler:(ASUpdateMobileNumberCallback)callback;


/*!
 *  @brief delete Saved Card - Use this method For delete saved cards.
 *
 *  @param lastFourDigits Last four digits of the saved card.
 *  @param scheme         correct scheme of the card.
 *  @param callback       The callback ASDeleteCardCallback.
 */
-(void)requestDeleteCard:(NSString *)lastFourDigits
                  scheme:(NSString *)scheme
   withCompletionHandler:(ASDeleteCardCallback)callback;

/*!
 *  @brief requestDeleteCardWithToken.
 *
 *  @param token    The token NSString.
 *  @param callback The callback ASDeleteCardCallback.
 */
-(void)requestDeleteCardWithToken:(NSString *)token
            withCompletionHandler:(ASDeleteCardCallback)callback;

/*!
 *  @brief requestDpMerchantQuery.
 *
 *  @param request  The request CTSDPMerchantQueryReq.
 *  @param callback The callback ASDPMerchantQueryCallback.
 */
-(void)requestDpMerchantQuery:(CTSDPMerchantQueryReq *)request
            completionHandler:(ASDPMerchantQueryCallback)callback;

/*!
 *  @brief requestUpdateProfileInformation.
 *
 *  @param profileInfo The profileInfo CTSProfileUpdate.
 *  @param callback    The callback ASUpdateProfileInfoCallBack.
 */
- (void)requestUpdateProfileInformation:(CTSProfileUpdate *)profileInfo
                  withCompletionHandler:(ASUpdateProfileInfoCallBack)callback;

/*!
 *  @brief requestProfileInformationWithCompletionHandler.
 *
 *  @param callback The callback ASGetProfileInfoCallBack.
 */
- (void)requestProfileInformationWithCompletionHandler:(ASGetProfileInfoCallBack)callback;

/*!
 *  @brief requestSaveCard.
 *
 *  @param paymentInfo The paymentInfo CTSPaymentDetailUpdate.
 *  @param callback    The callback ASSaveCardsCallback.
 */
-(void)requestSaveCard:(CTSPaymentDetailUpdate*)paymentInfo
            completion:(ASSaveCardsCallback )callback;
@end
