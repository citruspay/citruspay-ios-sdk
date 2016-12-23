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

/**
 *   CTSWalletScope Enum.
 */
typedef enum{
    /**
     *   CTSWalletScopeLimited Constant.
     */
    CTSWalletScopeLimited,
    /**
     *   CTSWalletScopeFull Constant.
     */
    CTSWalletScopeFull
} CTSWalletScope;

/// Class Models.
@class CTSAuthLayer;

/**
 *   CTSAuthentication Protocol.
 */
@protocol CTSAuthenticationProtocol

/**
*   reports sign in respose.
*
*  @param layer The layer CTSAuthLayer.
*  @param userName The userName String.
*  @param token The token String.
*  @param error The error NSError.
*/
@optional
- (void)auth:(CTSAuthLayer*)layer
didSigninUsername:(NSString*)userName
  oauthToken:(NSString*)token
       error:(NSError*)error;

/**
 *   didSignupUsername.
 *
 *  @param layer The layer CTSAuthLayer.
 *  @param userName The userName String.
 *  @param token The token String.
 *  @param error The error NSError.
 */
@optional
- (void)auth:(CTSAuthLayer*)layer
didSignupUsername:(NSString*)userName
  oauthToken:(NSString*)token
       error:(NSError*)error;

/**
 *   didChangePasswordError.
 *
 *  @param layer The layer CTSAuthLayer.
 *  @param error The error NSError.
 */
@optional
- (void)auth:(CTSAuthLayer*)layer
didChangePasswordError:(NSError*)error;

/**
 *   didCheckIsUserCitrusMember.
 *
 *  @param layer The layer CTSAuthLayer.
 *  @param isMember The isMember BOOL.
 *  @param error The error NSError.
 */
@optional
- (void)auth:(CTSAuthLayer*)layer
didCheckIsUserCitrusMember:(BOOL)isMember
       error:(NSError*)error;

/**
 *   didRequestForResetPassword.
 *
 *  @param layer The layer CTSAuthLayer.
 *  @param error The error NSError.
 */
@optional
- (void)auth:(CTSAuthLayer*)layer
didRequestForResetPassword:(NSError*)error;


/**
 *   didBindUser.
 *
 *  @param layer The layer CTSAuthLayer.
 *  @param userName The userName String.
 *  @param error The error NSError.
 */
@optional
- (void)auth:(CTSAuthLayer*)layer
 didBindUser:(NSString*)userName
       error:(NSError *)error;


/**
 *   didCitrusSigninInerror.
 *
 *  @param layer The layer CTSAuthLayer.
 *  @param error The error NSError.
 */
@optional
- (void)auth:(CTSAuthLayer*)layer
didCitrusSigninInerror:(NSError *)error;

/**
 *   didLinkUser.
 *
 *  @param layer The layer CTSAuthLayer.
 *  @param linkUserRes The linkUserRes CTSLinkUserRes.
 *  @param error The error NSError.
 */
@optional
- (void)auth:(CTSAuthLayer*)layer
 didLinkUser:(CTSLinkUserRes *)linkUserRes
       error:(NSError *)error;


/**
 *   didSetPasswordError.
 *
 *  @param layer The layer CTSAuthLayer.
 *  @param error The error NSError.
 */
@optional
- (void)auth:(CTSAuthLayer*)layer
didSetPasswordError:(NSError*)error;

/**
 *   didSignup.
 *
 *  @param layer The layer CTSAuthLayer.
 *  @param error The error NSError.
 */
@optional
- (void)auth:(CTSAuthLayer*)layer
   didSignup:(NSError*)error;

/**
 *   didVerifyOTP.
 *
 *  @param layer The layer CTSAuthLayer.
 *  @param isVerified The isVerified BOOL.
 *  @param error The error NSError.
 */
@optional
-(void)auth:(CTSAuthLayer *)layer
didVerifyOTP:(BOOL)isVerified
      error:(NSError *)error;

/**
 *   didGenerateVerificationCode.
 *
 *  @param layer The layer CTSAuthLayer.
 *  @param response The response String.
 *  @param error The error NSError.
 */
@optional
-(void)auth:(CTSAuthLayer *)layer
didGenerateVerificationCode:(CTSResponse *)response
      error:(NSError *)error;

/**
 *   didGenerateOTPWithError.
 *
 *  @param layer The layer CTSAuthLayer.
 *  @param error The error NSError.
 */
@optional
-(void)auth:(CTSAuthLayer *)layer
didGenerateOTPWithError:(NSError *)error;

/**
 *   didLink.
 *
 *  @param layer The layer CTSAuthLayer.
 *  @param linkRes The linkRes String.
 *  @param error The error NSError.
 */
@optional
-(void)auth:(CTSAuthLayer *)layer
    didLink:(CTSLinkRes *)linkRes
      error:(NSError *)error;

/**
 *   didSignInWithOtpError.
 *
 *  @param layer The layer CTSAuthLayer.
 *  @param error The error NSError.
 */
@optional
-(void)auth:(CTSAuthLayer *)layer
didSignInWithOtpError:(NSError *)error;
@end

/**
 *   The CTSAuthLayer class' ASSigninCallBack CallBack.
 *
 *  @return The Newly created userName, token, error object.
 */
typedef void (^ASSigninCallBack)(NSString* userName,
                                 NSString* token,
                                 NSError* error);

/**
 *   The CTSAuthLayer class' ASSignupCallBack CallBack.
 *
 *  @return The Newly created userName, token, error object.
 */
typedef void (^ASSignupCallBack)(NSString* userName,
                                 NSString* token,
                                 NSError* error);

/**
 *   The CTSAuthLayer class' ASChangePassword CallBack.
 *
 *  @return The Newly created response, error object.
 */
typedef void (^ASChangePassword)(NSString *response, NSError* error);

/**
 *   The CTSAuthLayer class' ASSetPassword CallBack.
 *
 *  @return The Newly created error object.
 */
typedef void (^ASSetPassword)(NSError* error);


/**
 *   The CTSAuthLayer class' ASIsUserCitrusMemberCallback CallBack.
 *
 *  @return The Newly created isUserCitrusMember, error object.
 */
typedef void (^ASIsUserCitrusMemberCallback)(BOOL isUserCitrusMember,
                                             NSError* error);

/**
 *   The CTSAuthLayer class' ASResetPasswordCallback CallBack.
 *
 *  @return The Newly created error object.
 */
typedef void (^ASResetPasswordCallback)(NSError* error);

/**
 *   The CTSAuthLayer class' ASBindUserCallback CallBack.
 *
 *  @return The Newly created userName, error object.
 */
typedef void (^ASBindUserCallback)(NSString *userName,
                                   NSError* error);

/**
 *   The CTSAuthLayer class' ASCitrusSigninCallBack CallBack.
 *
 *  @return The Newly created error object.
 */
typedef void (^ASCitrusSigninCallBack)(NSError* error);

/**
 *   The CTSAuthLayer class' ASLinkUserCallBack CallBack.
 *
 *  @return The Newly created linkUserRes, error object.
 */
typedef void (^ASLinkUserCallBack)(CTSLinkUserRes *linkUserRes, NSError* error);

/**
 *   The CTSAuthLayer class' ASAsyncSignUpOauthTokenCallBack CallBack.
 *
 *  @return The Newly created error object.
 */
typedef void (^ASAsyncSignUpOauthTokenCallBack)(NSError* error);

/**
 *   The CTSAuthLayer class' ASSignupNewCallBack CallBack.
 *
 *  @return The Newly created error object.
 */
typedef void (^ASSignupNewCallBack)(NSError* error);

/**
 *   The CTSAuthLayer class' ASOtpVerificationCallback CallBack.
 *
 *  @return The Newly created isVerified, error object.
 */
typedef void (^ASOtpVerificationCallback)(BOOL isVerified,NSError* error);

/**
 *   The CTSAuthLayer class' ASOtpRegenerationCallback CallBack.
 *
 *  @return The Newly created response, error object.
 */
typedef void (^ASOtpRegenerationCallback)(CTSResponse* response, NSError* error);

/**
 *   The CTSAuthLayer class' ASGenerateOtpCallBack CallBack.
 *
 *  @return The Newly created response, error object.
 */
typedef void (^ASGenerateOtpCallBack)(CTSResponse*response, NSError* error);

/**
 *   The CTSAuthLayer class' ASCitrusLinkCallback CallBack.
 *
 *  @return The Newly created linkResponse, error object.
 */
typedef void (^ASCitrusLinkCallback)(CTSCitrusLinkRes *linkResponse, NSError* error);

/**
 *   The CTSAuthLayer class' ASMasterLinkCallback CallBack.
 *
 *  @return The Newly created linkResponse, error object.
 */
typedef void (^ASMasterLinkCallback)(CTSMasterLinkRes *linkResponse, NSError* error);

/**
 *   The CTSAuthLayer class' ASLinkCallback CallBack.
 *
 *  @return The Newly created linkRes, error object.
 */
typedef void (^ASLinkCallback)(CTSLinkRes *linkRes, NSError* error);

/**
 *   The CTSAuthLayer class' ASBindSignIn CallBack.
 *
 *  @return The Newly created error object.
 */
typedef void (^ASBindSignIn)(NSError* error);

/**
 *   The CTSAuthLayer class' ASOtpSigninCallBack CallBack.
 *
 *  @return The Newly created error object.
 */
typedef void (^ASOtpSigninCallBack)(NSError* error);

/**
 *   The CTSAuthLayer class' ASConsumerPortalCallBack CallBack.
 *
 *  @return The Newly created error object.
 */
typedef void (^ASConsumerPortalCallBack)(NSError* error);

/**
 *   The CTSAuthLayer class' ASTokenValidityCallback CallBack.
 *
 *  @return The Newly created res, error object.
 */
typedef void (^ASTokenValidityCallback)(CTSTokenValidityRes *res, NSError* error);

/**
 *   The CTSAuthLayer class' ASErrorCallback CallBack.
 *
 *  @return The Newly created error object.
 */
typedef void (^ASErrorCallback)( NSError* error);

/**
 *   The CTSAuthLayer class' ASUpdateMobileSigninCallback CallBack.
 *
 *  @return The Newly created response, error object.
 */
typedef void (^ASUpdateMobileSigninCallback) (CTSEotpVerSigninResp *response, NSError *error);


/**
 *   CTSAuthLayer Class.
 */
@interface CTSAuthLayer : CTSRestPluginBase {
    /**
     *   The CTSAuthLayer class' seedState object.
     */
    int seedState;
    /**
     *   The CTSAuthLayer class' userNameSignIn object.
     */
    NSString  *userNameSignIn;
    /**
     *   The CTSAuthLayer class' passwordSignin object.
     */
    NSString  *passwordSignin;
    /**
     *   The CTSAuthLayer class' userNameSignup object.
     */
    NSString  *userNameSignup;
    /**
     *   The CTSAuthLayer class' passwordSignUp object.
     */
    NSString  *passwordSignUp;
    /**
     *   The CTSAuthLayer class' mobileSignUp object.
     */
    NSString  *mobileSignUp;
    /**
     *   The CTSAuthLayer class' userNameBind object.
     */
    NSString  *userNameBind;
    /**
     *   The CTSAuthLayer class' mobileBind object.
     */
    NSString  *mobileBind;
    /**
     *   The CTSAuthLayer class' isInLink object.
     */
    BOOL isInLink;
    /**
     *   The CTSAuthLayer class' wasSignupCalled object.
     */
    BOOL wasSignupCalled;
    /**
     *   The CTSAuthLayer class' ENABLELOGS object.
     */
    BOOL ENABLELOGS;
}

/**
 *   The CTSAuthLayer class' delegate object.
 */
@property(nonatomic, weak) id<CTSAuthenticationProtocol> delegate;

/**
 *   enabledDebuggingMessages.
 *
 *  @param val The BOOL Value.
 */
- (void)enabledDebuggingMessages:(BOOL)val;

/**
 *   initWithKeyStore.
 *
 *  @param keystoreArg The signinId String, signUpId String, signinSecret String, signUpSecret String and vanity String.
 *
 *  @return The Newly created object.
 */
- (instancetype)initWithKeyStore:(CTSKeyStore *)keystoreArg;

/**
 *   init.
 *
 *  @return The Newly created object.
 */
-(instancetype)init __attribute__((unavailable("init not available, Please use [CitrusPaymentSDK fetchSharedAuthLayer]")));


/**
 *   Fetch Shared AuthLayer.
 *
 *  @return The AuthLayer object.
 */
+(CTSAuthLayer*)fetchSharedAuthLayer;

/**
 *   Creates request for the specified method, Username String and Password String.
 *
 *  @param userName The Username String.
 *  @param password The Password String.
 *  @param callBack A CallBack makes Signin the User.
 */
- (void)requestSigninWithUsername:(NSString*)userName
                         password:(NSString*)password
                completionHandler:(ASSigninCallBack)callBack;

/**
 *   Creates request for the specified method, Email String, Mobile String and Password String.
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

/**
 *   Creates request for the userNameArg String, in case of forget password, after
 recieving this server will send email to this user to initiate the password reset.
 *
 *  @param userNameArg The userNameArg String.
 *  @param callBack A CallBack makes Reset Password to the User.
 */
- (void)requestResetPassword:(NSString*)userNameArg
           completionHandler:(ASResetPasswordCallback)callBack;

/**
 *   requestChangePasswordUserName.
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

/**
 *   Check if username is registered for any member.
 *
 *  @param email    The email String.
 *  @param callback    The Created Request.
 */
- (void)requestIsUserCitrusMemberUsername:(NSString*)email
                        completionHandler:(ASIsUserCitrusMemberCallback)callback;

/**
 *   requestBindUsername.
 *
 *  @param email    The email String.
 *  @param mobile   The mobile String.
 *  @param callback The Created Request.
 */
- (void)requestBindUsername:(NSString*)email
                     mobile:(NSString *)mobile
          completionHandler:(ASBindUserCallback)callback DEPRECATED_MSG_ATTRIBUTE("Use with CTSLimitedScope requestMasterLink:mobile:scope:completionHandler:");


/**
 *   requestMobileBindUsername.
 *
 *  @param email    The email String.
 *  @param mobile   The mobile String.
 *  @param callback The Created Request.
 */
- (void)requestMobileBindUsername:(NSString*)email
                           mobile:(NSString *)mobile
                completionHandler:(ASBindUserCallback)callback;

/**
 *   requestSetPassword.
 *
 *  @param password The password String.
 *  @param userName The userName String.
 *  @param callback The Created Request.
 */
-(void)requestSetPassword:(NSString *)password
                 userName:(NSString *)userName
        completionHandler:(ASSetPassword)callback;

/**
 *   requestCitrusPaySignin.
 *
 *  @param userName The userName String.
 *  @param password The password String.
 *  @param callBack The Created Request.
 */
-(void)requestCitrusPaySignin:(NSString *)userName
                     password:(NSString*)password
            completionHandler:(ASCitrusSigninCallBack)callBack;


/**
 *   requestBindSignin.
 *
 *  @param userName The userName String.
 *  @param callback The Created Request.
 */
-(void)requestBindSignin:(NSString *)userName
       completionHandler:(ASBindSignIn)callback;

/**
 *   signOut.
 *
 *  @return The BOOL Value.
 */
- (BOOL)signOut;


/**
 *   isAnyoneSignedIn.
 *
 *  @return The BOOL Value.
 */
-(BOOL)isAnyoneSignedIn DEPRECATED_MSG_ATTRIBUTE("Use 'isLoggedIn'");

/**
 *   isUserBound.
 *
 *  @return The BOOL Value.
 */
-(BOOL)isUserBound;


/**
 *   isLoggedIn.
 *
 *  @return The BOOL Value.
 */
-(BOOL)isLoggedIn;

/**
 *   canLoadCitrusCash.
 *
 *  @return The BOOL Value.
 */
-(BOOL)canLoadCitrusCash;

/**
 *   isMerchantLoggedIn.
 *
 *  @return The BOOL Value.
 */
- (BOOL)isMerchantLoggedIn;

/**
 *   generateBigIntegerString.
 *
 *  @param email The userName String.
 *
 *  @return The String Value.
 */
- (NSString*)generateBigIntegerString:(NSString*)email ;

/**
 *   requestLinkUser.
 *
 *  @param email    The userName String.
 *  @param mobile   The userName String.
 *  @param callBack The Created Request.
 */
-(void)requestLinkUser:(NSString *)email
                mobile:(NSString *)mobile
     completionHandler:(ASLinkUserCallBack)callBack DEPRECATED_MSG_ATTRIBUTE("Use 'requestCitrusLink:mobile:completion:'");


/**
 *   requestLinkTrustedUser.
 *
 *  @param user     The userName String.
 *  @param callback The Created Request.
 */
-(void)requestLinkTrustedUser:(CTSUserDetails *)user
            completionHandler:(ASLinkUserCallBack )callback;

/**
 *   requestSignInOauthToken.
 *
 *  @return The NSString Value.
 */
-(NSString *)requestSignInOauthToken;


/**
 *   requestSignUpOauthTokenCompletionHandler.
 *
 *  @param callback The Created Request.
 */
- (void)requestSignUpOauthTokenCompletionHandler:(ASAsyncSignUpOauthTokenCallBack)callback;


/**
 *   requestSignupUser.
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

/**
 *   requestMobileVerificationWithCode.
 *
 *  @param otp      The otp String.
 *  @param callback The Created Request.
 */
-(void)requestMobileVerificationWithCode:(NSString *)otp
                       completionHandler:(ASOtpVerificationCallback)callback;

/**
 *   requestVerificationCodeRegenerate.
 *
 *  @param mobile   The mobile String.
 *  @param callback The Created Request.
 */
-(void)requestVerificationCodeRegenerate:(NSString *)mobile
                       completionHandler:(ASOtpRegenerationCallback)callback;

/**
 *   requestGenerateOTPFor.
 *
 *  @param entity   The entity String.
 *  @param callback The Created Request.
 */
-(void)requestGenerateOTPFor:(NSString *)entity
           completionHandler:(ASGenerateOtpCallBack)callback;

/**
 *   requestSigninWithUsername.
 *
 *  @param userNameArg The userNameArg String.
 *  @param otp         The otp String.
 *  @param callBack    The Created Request.
 */
-(void)requestSigninWithUsername:(NSString*)userNameArg
                             otp:(NSString*)otp
               completionHandler:(ASOtpSigninCallBack)callBack;

/**
*   requestLink.
*
*  @param user     The user String.
*  @param callback The Created Request.
*/
-(void)requestLink:(CTSUserDetails *)user
 completionHandler:(ASLinkCallback )callback;

/**
 *   accessConsumerPortalWithParentViewController.
 *
 *  @param controller The controller UIViewController.
 *  @param callback   The Created Request.
 */
- (void)accessConsumerPortalWithParentViewController:(UIViewController *)controller
                               withCompletionHandler:(ASConsumerPortalCallBack)callback;

/**
 *   requestLink.
 *
 *  @param user       The user String.
 *  @param isForceVer The isForceVer BOOL.
 *  @param callback   The Created Request.
 */
-(void)requestLink:(CTSUserDetails *)user
 forceVerification:(BOOL)isForceVer
 completionHandler:(ASLinkCallback )callback;

/**
*   requestPrepaidSignIn.
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

/**
 *   requestTokenValidityWithCompletionHandler.
 *
 *  @param callback The Created Request.
 */
-(void)requestTokenValidityWithCompletionHandler:(ASTokenValidityCallback)callback;

/**
 *   requestUpdatePrepaidTokenCompletionHandler.
 *
 *  @param callback The Created Request.
 */
-(void)requestUpdatePrepaidTokenCompletionHandler:(ASErrorCallback)callback;

/**
 *   requestCitrusLink.
 *
 *  @param email    The email String.
 *  @param mobile   The mobile String.
 *  @param callback The Created Request.
 */
-(void)requestCitrusLink:(NSString *)email
                  mobile:(NSString *)mobile
              completion:(ASCitrusLinkCallback)callback;

/**
*   requestEotpSignInUpdateEmail.
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

/**
 *   requestVerifyAndSigninUUID.
 *
 *  @param uuid     The uuid String.
 *  @param password The password String.
 *  @param callback The Created Request.
 */
-(void)requestVerifyAndSigninUUID:(NSString *)uuid
                 verificationCode:(NSString *)password
                         callback:(ASCitrusSigninCallBack)callback;

/**
 *   requestCitrusLinkSignInWithPassoword.
 *
 *  @param password The password String.
 *  @param type     The type PasswordType.
 *  @param callback The Created Request.
 */
-(void)requestCitrusLinkSignInWithPassoword:(NSString *)password
                               passwordType:(PasswordType)type
                          completionHandler:(ASCitrusSigninCallBack)callback DEPRECATED_MSG_ATTRIBUTE("user requestMasterLinkSignInWithPassword:passwordType:completionHandler:");

/**
 *   requestRefreshOauthTokenCallback.
 *
 *  @param callback The Created Request.
 */
-(void)requestRefreshOauthTokenCallback:(ASErrorCallback )callback;

/**
*   requestMasterLink.
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

/**
 *   requestMasterLinkSignInWithPassword.
 *
 *  @param password The password String.
 *  @param type     The type Enum.
 *  @param callback The Created Request.
 */
-(void)requestMasterLinkSignInWithPassword:(NSString *)password
                              passwordType:(PasswordType)type
                         completionHandler:(ASCitrusSigninCallBack)callback;

/**
 *   requestResendOtp.
 *
 *  @param callback The Created Request.
 */
-(void)requestResendOtp:(ASErrorCallback)callback;

/**
 *   requestSetPassowordMobileAccount.
 *
 *  @param password The password String.
 *  @param callback The Created Request.
 */
-(void)requestSetPassowordMobileAccount:(NSString *)password
                      completionHandler:(ASSetPassword)callback;

@end