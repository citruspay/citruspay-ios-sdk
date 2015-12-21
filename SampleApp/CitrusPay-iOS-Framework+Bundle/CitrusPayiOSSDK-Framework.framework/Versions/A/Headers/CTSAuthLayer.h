//
//  CTSAuthLayer.h
//  RestFulltester
//
//  Created by Yadnesh Wankhede on 23/05/14.
//  Copyright (c) 2014 Citrus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CTSOauthTokenRes.h"
#import "RestLayerConstants.h"
#import "CTSAuthLayerConstants.h"
#import "CTSRestPluginBase.h"
#import "CTSRestCoreResponse.h"
//#import "MerchantConstants.h"
#import "CTSLinkUserRes.h"
#import "CTSUserDetails.h"
#import "CTSLinkRes.h"
#import "CTSResponse.h"
#import "CTSTokenValidityRes.h"
#import <UIKit/UIKit.h>
#import "CTSEotpVerSigninResp.h"
#import "CTSCitrusLinkRes.h"


#define CONSUMER_PORTAL_PRODUCTION_BASEURL @"https://consumer.citruspay.com/CitrusConsumerPortal/AppLanding/appLandingPage"
#define CONSUMER_PORTAL_STAGING_BASEURL @"https://stgconsumer.citruspay.com/CitrusConsumerPortal/AppLanding/appLandingPage"

@class CTSAuthLayer;
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
- (void)auth:(CTSAuthLayer*)layer didChangePasswordError:(NSError*)error;

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
- (void)auth:(CTSAuthLayer*)layer didRequestForResetPassword:(NSError*)error;



@optional
- (void)auth:(CTSAuthLayer*)layer didBindUser:(NSString*)userName error:(NSError *)error;


@optional
- (void)auth:(CTSAuthLayer*)layer didCitrusSigninInerror:(NSError *)error;

@optional
- (void)auth:(CTSAuthLayer*)layer didLinkUser:(CTSLinkUserRes *)linkUserRes error:(NSError *)error;


@optional
- (void)auth:(CTSAuthLayer*)layer didSetPasswordError:(NSError*)error;

@optional
- (void)auth:(CTSAuthLayer*)layer didSignup:(NSError*)error;

@optional
-(void)auth:(CTSAuthLayer *)layer didVerifyOTP:(BOOL)isVerified error:(NSError *)error;

@optional
-(void)auth:(CTSAuthLayer *)layer didGenerateVerificationCode:(CTSResponse *)response error:(NSError *)error;

@optional
-(void)auth:(CTSAuthLayer *)layer didGenerateOTPWithError:(NSError *)error;

@optional
-(void)auth:(CTSAuthLayer *)layer didLink:(CTSLinkRes *)linkRes error:(NSError *)error;


@optional
-(void)auth:(CTSAuthLayer *)layer didSignInWithOtpError:(NSError *)error;
@end

@interface CTSAuthLayer : CTSRestPluginBase {
  int seedState;
  NSString* userNameSignIn,*passwordSignin, *userNameSignup, *passwordSignUp, *mobileSignUp;
    NSString  *userNameBind,*mobileBind;
    BOOL isInLink;

  BOOL wasSignupCalled;
}
- (instancetype)initWithKeyStore:(CTSKeyStore *)keystoreArg;
typedef void (^ASSigninCallBack)(NSString* userName,
                                 NSString* token,
                                 NSError* error);

typedef void (^ASSignupCallBack)(NSString* userName,
                                 NSString* token,
                                 NSError* error);

typedef void (^ASChangePassword)(NSError* error);

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

typedef void (^ASLinkCallback)(CTSLinkRes *linkRes, NSError* error);

typedef void (^ASBindSignIn)(NSError* error);

typedef void (^ASOtpSigninCallBack)(NSError* error);

typedef void (^ASConsumerPortalCallBack)(NSError* error);

typedef void (^ASTokenValidityCallback)(CTSTokenValidityRes *res, NSError* error);

typedef void (^ASErrorCallback)( NSError* error);

typedef void (^ASUpdateMobileSigninCallback) (CTSEotpVerSigninResp *response,NSError *error);



@property(nonatomic, weak) id<CTSAuthenticationProtocol> delegate;

-(instancetype)init __attribute__((unavailable("init not available, Please use [CitrusPaymentSDK fetchSharedAuthLayer]")));

+(CTSAuthLayer*)fetchSharedAuthLayer;


/**
 *  sign in the user
 *
 *  @param userName email adress
 *  @param password
 *  @param callBack
 */
- (void)requestSigninWithUsername:(NSString*)userName
                         password:(NSString*)password
                completionHandler:(ASSigninCallBack)callBack;

/**
 *  to sign up the user
 *
 *  @param email    this will be the username
 *  @param mobile
 *  @param password
 *  @param callBack
 */
- (void)requestSignUpWithEmail:(NSString*)email
                        mobile:(NSString*)mobile
                      password:(NSString*)password
             completionHandler:(ASSignupCallBack)callBack DEPRECATED_ATTRIBUTE;

/**
 *  in case of forget password,after recieving this server will send email to
 *this user to initiate the password reset
 *
 *  @param userNameArg
 */
- (void)requestResetPassword:(NSString*)userNameArg
           completionHandler:(ASResetPasswordCallback)callBack;

/**
 *  to change the user password
 *
 *  @param userName
 *  @param oldPassword
 *  @param newPassword
 *  @param callback
 */
- (void)requestChangePasswordUserName:(NSString*)userName
                          oldPassword:(NSString*)oldPassword
                          newPassword:(NSString*)newPassword
                    completionHandler:(ASChangePassword)callback;

/**
 *  to check if username is registered for any member
 *
 *  @param email    this is the username
 *  @param callback
 */
- (void)requestIsUserCitrusMemberUsername:(NSString*)email
                        completionHandler:
                            (ASIsUserCitrusMemberCallback)callback;

- (void)requestBindUsername:(NSString*)email
                     mobile:(NSString *)mobile
                        completionHandler:
(ASBindUserCallback)callback;



- (void)requestMobileBindUsername:(NSString*)email
                     mobile:(NSString *)mobile
          completionHandler:
(ASBindUserCallback)callback;

-(void)requestSetPassword:(NSString *)password userName:(NSString *)userName completionHandler:(ASSetPassword)callback;

-(void)requestCitrusPaySignin:(NSString *)userName  password:(NSString*)password
            completionHandler:(ASCitrusSigninCallBack)callBack;



-(void)requestBindSignin:(NSString *)userName completionHandler:(ASBindSignIn)callback;

/**
 *  signout
 *
 *  @return YES
 */
- (BOOL)signOut;

/**
 *  to confirm if anyone is signed in
 *
 *  @return yes if anyone is signed in, NO otherwise
 */
-(BOOL)isAnyoneSignedIn DEPRECATED_MSG_ATTRIBUTE("Use 'isLoggedIn'");;
-(BOOL)isUserBound;
- (BOOL)isLoggedIn;

- (NSString*)generateBigIntegerString:(NSString*)email ;


-(void)requestLinkUser:(NSString *)email mobile:(NSString *)mobile completionHandler:(ASLinkUserCallBack)callBack;

-(void)requestLinkTrustedUser:(CTSUserDetails *)user completionHandler:(ASLinkUserCallBack )callback;


-(NSString *)requestSignInOauthToken;

- (void)requestSignUpOauthTokenCompletionHandler:(ASAsyncSignUpOauthTokenCallBack)callback;

-(void)requestSignupUser:(CTSUserDetails *)user password:(NSString *)pasword mobileVerified:(BOOL)isMarkMobileVerifed emailVerified:(BOOL)isMarkEmailVerified completionHandler:(ASSignupNewCallBack)callback;

-(void)requestMobileVerificationWithCode:(NSString *)otp completionHandler:(ASOtpVerificationCallback)callback;

-(void)requestVerificationCodeRegenerate:(NSString *)mobile completionHandler:(ASOtpRegenerationCallback)callback;

-(void)requestGenerateOTPFor:(NSString *)entity completionHandler:(ASGenerateOtpCallBack)callback;

-(void)requestSigninWithUsername:(NSString*)userNameArg otp:(NSString*)otp completionHandler:(ASOtpSigninCallBack)callBack;

-(void)requestLink:(CTSUserDetails *)user completionHandler:(ASLinkCallback )callback;

- (void)accessConsumerPortalWithParentViewController:(UIViewController *)controller
                               withCompletionHandler:(ASConsumerPortalCallBack)callback;

-(void)requestLink:(CTSUserDetails *)user forceVerification:(BOOL)isForceVer completionHandler:(ASLinkCallback )callback;

-(void)requestPrepaidSignIn:(NSString *)username password:(NSString *)passoword passwordType:(PasswordType)type compltionHandler:(ASCitrusSigninCallBack)callBack;

-(void)requestTokenValidityWithCompletionHandler:(ASTokenValidityCallback)callback;

-(void)requestUpdatePrepaidTokenCompletionHandler:(ASErrorCallback)callback;

-(void)requestCitrusLink:(NSString *)email mobile:(NSString *)mobile completion:(ASCitrusLinkCallback)callback;

-(void)requestEotpSignInUpdateEmail:(NSString *)email password:(NSString *)password passwordType:(PasswordType)type requestedMobile:(NSString *)mobile  callback:(ASUpdateMobileSigninCallback)callback;

-(void)requestVerifyAndSigninUUID:(NSString *)uuid verificationCode:(NSString *)password callback:(ASCitrusSigninCallBack)callback;

-(void)requestCitrusLinkSignInWithPassoword:(NSString *)password passwordType:(PasswordType)type completionHandler:(ASCitrusSigninCallBack)callback;

@end
