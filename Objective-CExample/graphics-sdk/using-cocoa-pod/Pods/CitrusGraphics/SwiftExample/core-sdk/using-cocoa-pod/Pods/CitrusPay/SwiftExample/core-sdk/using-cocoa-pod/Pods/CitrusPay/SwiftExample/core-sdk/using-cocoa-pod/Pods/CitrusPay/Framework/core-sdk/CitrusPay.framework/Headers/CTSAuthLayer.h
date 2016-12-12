//
//  CTSAuthLayer.h
//  RestFulltester
//
//  Created by Yadnesh Wankhede on 23/05/14.
//  Copyright (c) 2014 Citrus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "CTSRestPluginBase.h"
#import "CTSAuthLayerConstants.h"
#import "CTSEotpVerSigninResp.h"
#import "CTSCitrusLinkRes.h"
#import "CTSMasterLinkRes.h"

/// Class Models.
@class CTSLinkUserRes, CTSLinkRes, CTSTokenValidityRes, CTSUserDetails, CTSResponse;

/*!
 *  @brief CTSWalletScope Enum.
 */
typedef enum{
    CTSWalletScopeLimited,
    CTSWalletScopeFull
} CTSWalletScope;

/// Class Models.
@class CTSAuthLayer;

/*!
 *  @brief CTSAuthentication Protocol.
 */
@protocol CTSAuthenticationProtocol

/**
 *  reports sign in respose
 *
 *  @param isSuccessful  status
 *  @param userName     username that was used for signin
 *  @param token : oauth token if signin followed by signup is successful is
 *successful,nil otherwise.
 *  @param error        error,nil in case of success.
 */
@optional
- (void)auth:(CTSAuthLayer*)layer
didSigninUsername:(NSString*)userName
  oauthToken:(NSString*)token
       error:(NSError*)error;

/**
 *  reports sign up reply
 *
 *  @param isSuccessful
 *  @param token : oauth token if signin is successful,nil otherwise
 *  @param error
 */
@optional
- (void)auth:(CTSAuthLayer*)layer
didSignupUsername:(NSString*)userName
  oauthToken:(NSString*)token
       error:(NSError*)error;

/**
 *  reports change password reply
 *
 *  @param layer
 *  @param error
 */
@optional
- (void)auth:(CTSAuthLayer*)layer
didChangePasswordError:(NSError*)error;

/**
 *  reports is user Citrus member
 *
 *  @param layer
 *  @param isMember Bool that reports membership status
 *  @param error
 */
@optional
- (void)auth:(CTSAuthLayer*)layer
didCheckIsUserCitrusMember:(BOOL)isMember
       error:(NSError*)error;

/**
 *  reports password reset
 *
 *  @param layer
 *  @param error
 */
@optional
- (void)auth:(CTSAuthLayer*)layer
didRequestForResetPassword:(NSError*)error;


@optional
- (void)auth:(CTSAuthLayer*)layer
 didBindUser:(NSString*)userName
       error:(NSError *)error;


@optional
- (void)auth:(CTSAuthLayer*)layer
didCitrusSigninInerror:(NSError *)error;

@optional
- (void)auth:(CTSAuthLayer*)layer
 didLinkUser:(CTSLinkUserRes *)linkUserRes
       error:(NSError *)error;


@optional
- (void)auth:(CTSAuthLayer*)layer
didSetPasswordError:(NSError*)error;

@optional
- (void)auth:(CTSAuthLayer*)layer
   didSignup:(NSError*)error;

/*!
 *  @brief <#Description#>
 */
@optional
-(void)auth:(CTSAuthLayer *)layer
didVerifyOTP:(BOOL)isVerified
      error:(NSError *)error;

@optional
-(void)auth:(CTSAuthLayer *)layer
didGenerateVerificationCode:(CTSResponse *)response
      error:(NSError *)error;

@optional
-(void)auth:(CTSAuthLayer *)layer
didGenerateOTPWithError:(NSError *)error;

@optional
-(void)auth:(CTSAuthLayer *)layer
    didLink:(CTSLinkRes *)linkRes
      error:(NSError *)error;

@optional
-(void)auth:(CTSAuthLayer *)layer
didSignInWithOtpError:(NSError *)error;
@end

typedef void (^ASSigninCallBack)(NSString* userName,
                                 NSString* token,
                                 NSError* error);

typedef void (^ASSignupCallBack)(NSString* userName,
                                 NSString* token,
                                 NSError* error);

typedef void (^ASChangePassword)(NSString *response, NSError* error);

typedef void (^ASSetPassword)(NSError* error);


typedef void (^ASIsUserCitrusMemberCallback)(BOOL isUserCitrusMember,
                                             NSError* error);

typedef void (^ASResetPasswordCallback)(NSError* error);

typedef void (^ASBindUserCallback)(NSString *userName,
                                   NSError* error);

typedef void (^ASCitrusSigninCallBack)(NSError* error);

typedef void (^ASLinkUserCallBack)(CTSLinkUserRes *linkUserRes, NSError* error);

typedef void (^ASAsyncSignUpOauthTokenCallBack)(NSError* error);

typedef void (^ASSignupNewCallBack)(NSError* error);

typedef void (^ASOtpVerificationCallback)(BOOL isVerified,NSError* error);

typedef void (^ASOtpRegenerationCallback)(CTSResponse* response, NSError* error);

typedef void (^ASGenerateOtpCallBack)(CTSResponse*response, NSError* error);

typedef void (^ASCitrusLinkCallback)(CTSCitrusLinkRes *linkResponse, NSError* error);

typedef void (^ASMasterLinkCallback)(CTSMasterLinkRes *linkResponse, NSError* error);

typedef void (^ASLinkCallback)(CTSLinkRes *linkRes, NSError* error);

typedef void (^ASBindSignIn)(NSError* error);

typedef void (^ASOtpSigninCallBack)(NSError* error);

typedef void (^ASConsumerPortalCallBack)(NSError* error);

typedef void (^ASTokenValidityCallback)(CTSTokenValidityRes *res, NSError* error);

typedef void (^ASErrorCallback)( NSError* error);

typedef void (^ASUpdateMobileSigninCallback) (CTSEotpVerSigninResp *response,NSError *error);


@interface CTSAuthLayer : CTSRestPluginBase {
    int seedState;
    NSString* userNameSignIn, *passwordSignin, *userNameSignup, *passwordSignUp, *mobileSignUp;
    NSString  *userNameBind,*mobileBind;
    BOOL isInLink;
    BOOL wasSignupCalled;
    BOOL ENABLELOGS;
}

/*!
 *  @brief The CTSAuthLayer class' delegate object.
 */
@property(nonatomic, weak) id<CTSAuthenticationProtocol> delegate;

/*!
 *  @brief enabledDebuggingMessages.
 *
 *  @param val The BOOL Value.
 */
- (void)enabledDebuggingMessages:(BOOL)val;

/*!
 *  @brief initWithKeyStore.
 *
 *  @param keystoreArg The signinId String, signUpId String, signinSecret String, signUpSecret String and vanity String.
 *
 *  @return The Newly created object.
 */
- (instancetype)initWithKeyStore:(CTSKeyStore *)keystoreArg;

/*!
 *  @brief init.
 *
 *  @return The Newly created object.
 */
-(instancetype)init __attribute__((unavailable("init not available, Please use [CitrusPaymentSDK fetchSharedAuthLayer]")));


/*!
 *  @brief Fetch Shared AuthLayer.
 *
 *  @return The AuthLayer object.
 */
+(CTSAuthLayer*)fetchSharedAuthLayer;

/*!
 *  @brief Creates request for the specified method, Username String and Password String.
 *
 *  @param userName The Username String.
 *  @param password The Password String.
 *  @param callBack A CallBack makes Signin the User.
 */
- (void)requestSigninWithUsername:(NSString*)userName
                         password:(NSString*)password
                completionHandler:(ASSigninCallBack)callBack;

/*!
 *  @brief Creates request for the specified method, Email String, Mobile String and Password String.
 *
 *  @param email    The Email String.
 *  @param mobile   The Mobile String.
 *  @param password The Password String.
 *  @param callBack A CallBack makes Signup the User.
 */
- (void)requestSignUpWithEmail:(NSString*)email
                        mobile:(NSString*)mobile
                      password:(NSString*)password
             completionHandler:(ASSignupCallBack)callBack DEPRECATED_ATTRIBUTE;

/*!
 *  @brief Creates request for the userNameArg String, in case of forget password, after
 recieving this server will send email to this user to initiate the password reset.
 *
 *  @param userNameArg The userNameArg String.
 *  @param callBack A CallBack makes Reset Password to the User.
 */
- (void)requestResetPassword:(NSString*)userNameArg
           completionHandler:(ASResetPasswordCallback)callBack;

/*!
 *  @brief requestChangePasswordUserName.
 *
 *  @param userName    The userName String.
 *  @param oldPassword The oldPassword String.
 *  @param newPassword The newPassword String.
 *  @param callback    The Created Request.
 */
- (void)requestChangePasswordUserName:(NSString*)userName
                          oldPassword:(NSString*)oldPassword
                          newPassword:(NSString*)newPassword
                    completionHandler:(ASChangePassword)callback;

/*!
 *  @brief Check if username is registered for any member.
 *
 *  @param email    The email String.
 *  @param callback    The Created Request.
 */
- (void)requestIsUserCitrusMemberUsername:(NSString*)email
                        completionHandler:(ASIsUserCitrusMemberCallback)callback;

/*!
 *  @brief requestBindUsername.
 *
 *  @param email    The email String.
 *  @param mobile   The mobile String.
 *  @param callback The Created Request.
 */
- (void)requestBindUsername:(NSString*)email
                     mobile:(NSString *)mobile
          completionHandler:(ASBindUserCallback)callback DEPRECATED_MSG_ATTRIBUTE("Use with CTSLimitedScope requestMasterLink:mobile:scope:completionHandler:");


/*!
 *  @brief requestMobileBindUsername.
 *
 *  @param email    The email String.
 *  @param mobile   The mobile String.
 *  @param callback The Created Request.
 */
- (void)requestMobileBindUsername:(NSString*)email
                           mobile:(NSString *)mobile
                completionHandler:(ASBindUserCallback)callback;

/*!
 *  @brief requestSetPassword.
 *
 *  @param password The password String.
 *  @param userName The userName String.
 *  @param callback The Created Request.
 */
-(void)requestSetPassword:(NSString *)password
                 userName:(NSString *)userName
        completionHandler:(ASSetPassword)callback;

/*!
 *  @brief requestCitrusPaySignin.
 *
 *  @param userName The userName String.
 *  @param password The password String.
 *  @param callBack The Created Request.
 */
-(void)requestCitrusPaySignin:(NSString *)userName
                     password:(NSString*)password
            completionHandler:(ASCitrusSigninCallBack)callBack;


/*!
 *  @brief requestBindSignin.
 *
 *  @param userName The userName String.
 *  @param callback The Created Request.
 */
-(void)requestBindSignin:(NSString *)userName
       completionHandler:(ASBindSignIn)callback;

/*!
 *  @brief signOut.
 *
 *  @return The BOOL Value.
 */
- (BOOL)signOut;


/*!
 *  @brief isAnyoneSignedIn.
 *
 *  @return The BOOL Value.
 */
-(BOOL)isAnyoneSignedIn DEPRECATED_MSG_ATTRIBUTE("Use 'isLoggedIn'");

/*!
 *  @brief isUserBound.
 *
 *  @return The BOOL Value.
 */
-(BOOL)isUserBound;


/*!
 *  @brief isLoggedIn.
 *
 *  @return The BOOL Value.
 */
-(BOOL)isLoggedIn;

/*!
 *  @brief canLoadCitrusCash.
 *
 *  @return The BOOL Value.
 */
-(BOOL)canLoadCitrusCash;

/*!
 *  @brief isMerchantLoggedIn.
 *
 *  @return The BOOL Value.
 */
- (BOOL)isMerchantLoggedIn;

/*!
 *  @brief generateBigIntegerString.
 *
 *  @param email The userName String.
 *
 *  @return The String Value.
 */
- (NSString*)generateBigIntegerString:(NSString*)email ;

/*!
 *  @brief requestLinkUser.
 *
 *  @param email    The userName String.
 *  @param mobile   The userName String.
 *  @param callBack The Created Request.
 */
-(void)requestLinkUser:(NSString *)email
                mobile:(NSString *)mobile
     completionHandler:(ASLinkUserCallBack)callBack DEPRECATED_MSG_ATTRIBUTE("Use 'requestCitrusLink:mobile:completion:'");


/*!
 *  @brief requestLinkTrustedUser.
 *
 *  @param user     The userName String.
 *  @param callback The Created Request.
 */
-(void)requestLinkTrustedUser:(CTSUserDetails *)user
            completionHandler:(ASLinkUserCallBack )callback;

/*!
 *  @brief requestSignInOauthToken.
 *
 *  @return The NSString Value.
 */
-(NSString *)requestSignInOauthToken;


/*!
 *  @brief requestSignUpOauthTokenCompletionHandler.
 *
 *  @param callback The Created Request.
 */
- (void)requestSignUpOauthTokenCompletionHandler:(ASAsyncSignUpOauthTokenCallBack)callback;


/*!
 *  @brief requestSignupUser.
 *
 *  @param user                The user String.
 *  @param pasword             The pasword String.
 *  @param isMarkMobileVerifed The isMarkMobileVerifed BOOL.
 *  @param isMarkEmailVerified The isMarkEmailVerified BOOL.
 *  @param callback            The Created Request.
 */
-(void)requestSignupUser:(CTSUserDetails *)user
                password:(NSString *)pasword
          mobileVerified:(BOOL)isMarkMobileVerifed
           emailVerified:(BOOL)isMarkEmailVerified
       completionHandler:(ASSignupNewCallBack)callback;

/*!
 *  @brief requestMobileVerificationWithCode.
 *
 *  @param otp      The otp String.
 *  @param callback The Created Request.
 */
-(void)requestMobileVerificationWithCode:(NSString *)otp
                       completionHandler:(ASOtpVerificationCallback)callback;

/*!
 *  @brief requestVerificationCodeRegenerate.
 *
 *  @param mobile   The mobile String.
 *  @param callback The Created Request.
 */
-(void)requestVerificationCodeRegenerate:(NSString *)mobile
                       completionHandler:(ASOtpRegenerationCallback)callback;

/*!
 *  @brief requestGenerateOTPFor.
 *
 *  @param entity   The entity String.
 *  @param callback The Created Request.
 */
-(void)requestGenerateOTPFor:(NSString *)entity
           completionHandler:(ASGenerateOtpCallBack)callback;

/*!
 *  @brief requestSigninWithUsername.
 *
 *  @param userNameArg The userNameArg String.
 *  @param otp         The otp String.
 *  @param callBack    The Created Request.
 */
-(void)requestSigninWithUsername:(NSString*)userNameArg
                             otp:(NSString*)otp
               completionHandler:(ASOtpSigninCallBack)callBack;

/*!
*  @brief requestLink.
*
*  @param user     The user String.
*  @param callback The Created Request.
*/
-(void)requestLink:(CTSUserDetails *)user
 completionHandler:(ASLinkCallback )callback;

/*!
 *  @brief accessConsumerPortalWithParentViewController.
 *
 *  @param controller The controller UIViewController.
 *  @param callback   The Created Request.
 */
- (void)accessConsumerPortalWithParentViewController:(UIViewController *)controller
                               withCompletionHandler:(ASConsumerPortalCallBack)callback;

/*!
 *  @brief requestLink.
 *
 *  @param user       The user String.
 *  @param isForceVer The isForceVer BOOL.
 *  @param callback   The Created Request.
 */
-(void)requestLink:(CTSUserDetails *)user
 forceVerification:(BOOL)isForceVer
 completionHandler:(ASLinkCallback )callback;

/*!
*  @brief requestPrepaidSignIn.
*
*  @param username  The userName String.
*  @param passoword The passoword String.
*  @param type      The type Enum.
*  @param callBack  The Created Request.
*/
-(void)requestPrepaidSignIn:(NSString *)username
                   password:(NSString *)passoword
               passwordType:(PasswordType)type
           compltionHandler:(ASCitrusSigninCallBack)callBack;

/*!
 *  @brief requestTokenValidityWithCompletionHandler.
 *
 *  @param callback The Created Request.
 */
-(void)requestTokenValidityWithCompletionHandler:(ASTokenValidityCallback)callback;

/*!
 *  @brief requestUpdatePrepaidTokenCompletionHandler.
 *
 *  @param callback The Created Request.
 */
-(void)requestUpdatePrepaidTokenCompletionHandler:(ASErrorCallback)callback;

/*!
 *  @brief requestCitrusLink.
 *
 *  @param email    The email String.
 *  @param mobile   The mobile String.
 *  @param callback The Created Request.
 */
-(void)requestCitrusLink:(NSString *)email
                  mobile:(NSString *)mobile
              completion:(ASCitrusLinkCallback)callback;

/*!
*  @brief requestEotpSignInUpdateEmail.
*
*  @param email    The email String.
*  @param password The password String.
*  @param type     The type PasswordType.
*  @param mobile   The mobile String.
*  @param callback The Created Request.
*/
-(void)requestEotpSignInUpdateEmail:(NSString *)email
                           password:(NSString *)password
                       passwordType:(PasswordType)type
                    requestedMobile:(NSString *)mobile
                           callback:(ASUpdateMobileSigninCallback)callback;

/*!
 *  @brief requestVerifyAndSigninUUID.
 *
 *  @param uuid     The uuid String.
 *  @param password The password String.
 *  @param callback The Created Request.
 */
-(void)requestVerifyAndSigninUUID:(NSString *)uuid
                 verificationCode:(NSString *)password
                         callback:(ASCitrusSigninCallBack)callback;

/*!
 *  @brief requestCitrusLinkSignInWithPassoword.
 *
 *  @param password The password String.
 *  @param type     The type PasswordType.
 *  @param callback The Created Request.
 */
-(void)requestCitrusLinkSignInWithPassoword:(NSString *)password
                               passwordType:(PasswordType)type
                          completionHandler:(ASCitrusSigninCallBack)callback DEPRECATED_MSG_ATTRIBUTE("user requestMasterLinkSignInWithPassword:passwordType:completionHandler:");

/*!
 *  @brief requestRefreshOauthTokenCallback.
 *
 *  @param callback The Created Request.
 */
-(void)requestRefreshOauthTokenCallback:(ASErrorCallback )callback;

/*!
*  @brief requestMasterLink.
*
*  @param email       The email String.
*  @param mobile      The mobile String.
*  @param walletScope The walletScope CTSWalletScope.
*  @param callback    The Created Request.
*/
-(void)requestMasterLink:(NSString *)email
                  mobile:(NSString *)mobile
                   scope:(CTSWalletScope)walletScope
       completionHandler:(ASMasterLinkCallback)callback;

/*!
 *  @brief requestMasterLinkSignInWithPassword.
 *
 *  @param password The password String.
 *  @param type     The type Enum.
 *  @param callback The Created Request.
 */
-(void)requestMasterLinkSignInWithPassword:(NSString *)password
                              passwordType:(PasswordType)type
                         completionHandler:(ASCitrusSigninCallBack)callback;

/*!
 *  @brief requestResendOtp.
 *
 *  @param callback The Created Request.
 */
-(void)requestResendOtp:(ASErrorCallback)callback;

/*!
 *  @brief requestSetPassowordMobileAccount.
 *
 *  @param password The password String.
 *  @param callback The Created Request.
 */
-(void)requestSetPassowordMobileAccount:(NSString *)password
                      completionHandler:(ASSetPassword)callback;

@end