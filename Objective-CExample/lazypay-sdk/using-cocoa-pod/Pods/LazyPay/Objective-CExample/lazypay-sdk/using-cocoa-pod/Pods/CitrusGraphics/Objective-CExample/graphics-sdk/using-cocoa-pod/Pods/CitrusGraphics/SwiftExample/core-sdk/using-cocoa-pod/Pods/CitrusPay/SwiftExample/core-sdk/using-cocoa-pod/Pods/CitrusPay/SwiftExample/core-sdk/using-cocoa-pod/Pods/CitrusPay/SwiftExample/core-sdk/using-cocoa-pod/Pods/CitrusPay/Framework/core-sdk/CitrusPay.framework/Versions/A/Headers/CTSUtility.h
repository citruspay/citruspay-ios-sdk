//
//  CTSUtility.h
//  RestFulltester
//
//  Created by Yadnesh Wankhede on 17/06/14.
//  Copyright (c) 2014 Citrus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CTSAuthLayerConstants.h"
#import "UserLogging.h"
#import "CTSBill.h"
#import "CTSContactUpdate.h"
#import "CTSUserAddress.h"
#import "CTSKeyStore.h"
#import "CTSProfileContactRes.h"
#import "CTSDyPPaymentInfo.h"
#import <UIKit/UIKit.h>
#import "CTSPaymentOption.h"
#import "CTSDataCache.h"
#import "CTSRuleInfo.h"
#import "CTSRestCoreResponse.h"
#import "CTSPgSettings.h"

#define SCHEME_MTRO @"MTRO"
#define SCHEME_VISA @"VISA"
#define SCHEME_AMEX @"AMEX"
#define SCHEME_RPAY @"RPAY"
#define SCHEME_DINERS @"DINERS"
#define SCHEME_MCRD @"MCRD"
#define SCHEME_JCB @"JCB"
#define SCHEME_DISCOVER @"DISCOVER"


#define CTSLocalizedString(key, comment) \
[CTSUtility NSLocalizedString:(key)]

extern NSString *const CTS_SIGNIN_USER_EMAIL ;

@interface CTSUtility : NSObject
typedef void (^ASBillCallback)(CTSBill* bill,NSError* error);


+ (NSString*)readFromDisk:(NSString*)key;
+ (void)saveToDisk:(id)data as:(NSString*)key;
+ (id)readDataFromDisk:(NSString*)key;
+ (NSDictionary*)readSigninTokenAsHeader;
+ (NSDictionary*)readSignupTokenAsHeader;
+ (NSDictionary*)readOauthTokenAsHeader:(NSString*)oauthToken;
+ (void)removeFromDisk:(NSString*)key;
+ (BOOL)validateEmail:(NSString*)email;
+ (BOOL)validateMobile:(NSString*)mobile;
+ (BOOL)validateCardNumber:(NSString*)number;
+ (BOOL)validateExpiryDate:(NSString*)date;
+ (BOOL)validateCVV:(NSString*)cvv cardNumber:(NSString*)cardNumber;
+ (BOOL)toBool:(NSString*)boolString;
+ (NSString*)fetchCardSchemeForCardNumber:(NSString *)cardNumber;
+ (NSDictionary*)getResponseIfTransactionIsFinished:(NSData*)postData;
+ (NSDictionary*)getResponseIfTransactionIsComplete:(UIWebView *)webview ;
+ (UIImage*)getSchmeTypeImage:(NSString*)cardNumber;
+ (BOOL)appendHyphenForCardnumber:(UITextField*)textField replacementString:(NSString*)string shouldChangeCharactersInRange:(NSRange)range;
+ (BOOL)appendHyphenForMobilenumber:(UITextField*)textField replacementString:(NSString*)string shouldChangeCharactersInRange:(NSRange)range;
+ (BOOL)enterNumericOnly:(NSString*)string;
+ (BOOL)enterCharecterOnly:(NSString*)string;
+ (BOOL)validateCVVNumber:(UITextField*)textField replacementString:(NSString*)string shouldChangeCharactersInRange:(NSRange)range;
+ (BOOL)validateCVVNumber:(UITextField*)textField cardNumber:(NSString*)cardNumber replacementString:(NSString*)string shouldChangeCharactersInRange:(NSRange)range;
+ (NSString*)createTXNId;
+(NSString*)correctExpiryDate:(NSString *)date;
+(BOOL)validateBill:(CTSBill *)bill;
+(BOOL)isVerifyPage:(NSString *)urlString;
+(NSArray *)getLoadResponseIfSuccesfull:(NSURLRequest *)request;
+(BOOL)string:(NSString *)source containsString:(NSString*)desti;
+(void)deleteSigninCookie;
+(BOOL)isCookieSetAlready;
+(BOOL)isMaestero:(NSString *)number;
+(int)extractReqId:(NSMutableDictionary *)response;
+(NSError *)extractError:(NSMutableDictionary *)response;
+(NSDictionary *)errorResponseIfReturnUrlDidntRespond:(NSString *)returnUrl webViewUrl:(NSString *)webviewUrl currentResponse:(NSDictionary *)responseDict;
+(NSDictionary *)errorResponseTransactionForcedClosedByUser;
+(NSString *)toStringBool:(BOOL)paramBool;
+(BOOL)convertToBool:(NSString *)boolStr;
+(BOOL)isEmail:(NSString *)string;
+(NSString *)toJson:(NSDictionary *)dict;
+(NSDictionary *)toDict:(NSString *)json;
+(NSString*)mobileNumberToTenDigitIfValid:(NSString *)number;
+(BOOL)isAmex:(NSString *)number;
+(BOOL)stringContainsSpecialChars:(NSString *)toCheck exceptChars:(NSString*)exceptionChars exceptCharSet:(NSCharacterSet*)exceptionCharSet;
+(BOOL)islengthInvalid:(NSString*)string;
+(BOOL)isURL:(NSURL *)aURL toUrl:(NSURL *)bUrl;
+(NSDictionary *)errorResponseDeviceOffline:(NSError *)error;
+(CTSContactUpdate *)correctContactIfNeeded:(CTSContactUpdate *)contact;
+(CTSUserAddress *)correctAdressIfNeeded:(CTSUserAddress *)address;
+(BOOL)isUserCookieValid;
+(NSError *)verifiyEmailOrMobile:(NSString *)userName;
+(BOOL)validateAmountString:(NSString *)amount;
+(CTSContactUpdate *)convertFromProfile:(CTSProfileContactRes *)profile;
+(CTSContactUpdate *)convertFromProfile:(CTSProfileContactRes *)profile contact:(CTSContactUpdate *)contact;
+(NSString *)fetchVanityUrl:(CTSKeyStore *)keyStore;
+(NSString *)fetchSigninId:(CTSKeyStore *)keyStore;
+(NSString *)fetchSigninSecret:(CTSKeyStore *)keyStore;
+(NSString *)fetchSignupId:(CTSKeyStore *)keyStore;
+(NSString *)fetchSigUpSecret:(CTSKeyStore *)keyStore;
+(NSString *)grantTypeFor:(PasswordType)type;
+(CTSKeyStore *)fetchCachedKeyStore;
+(NSString *)readAsBearer:(NSString *)oauthToken;
+(NSString*)fetchFromEnvironment:(NSString *)key;
//+(NSString *)toDpTypeString:(DPRequestType)type;
+ (CTSBill*)getDPBillFromServer:(CTSRuleInfo *)ruleInfo txn:(NSString *)txnID billUrl:(NSString*)billUrl;
+(NSString *)convertToDecimalAmountString:(NSString *)amount;
+(NSString*)getHTMLWithString:(NSString *)string;
+ (NSMutableArray *)fetchMappedCardSchemeForSaveCards:(NSArray*)cardsSchemeArray;
+ (UIImage *)fetchSchemeImageBySchemeType:(NSString *)scheme;
+ (UIImage *)fetchBankLogoImageByBankIssuerCode:(NSString *)bankIssuerCode;
+ (UIImage *)fetchBankLogoImageByBankName:(NSString *)bankName;
+(void)requestDPBillForRule:(CTSRuleInfo *)ruleInfo billURL:(NSString *)billUrl callback:(ASBillCallback)callback;
+(void)requestBillAmount:(NSString *)amount billURL:(NSString *)billUrl callback:(ASBillCallback)callback;
+(BOOL)isNonNumeric:(NSString *)string;
+(NSDictionary *)errorResponseTransactionFailed;
+(NSString *)fetchBankCodeForName:(NSString *)nameOfBank;
+(CTSKeyStore *)keyStore;
+(CTSRestCoreResponse*)addJsonErrorToResponse:(CTSRestCoreResponse*)response;
+(BOOL)isErrorJson:(NSString *)string;
+(void)storeLoginId:(NSString *)string;
+(NSString *)getLoginId;
+(void)removeLoginId;
+ (BOOL)isVerifyPage:(NSString *)page
             withURL:(NSString *)url;
+ (NSString *)NSLocalizedString:(NSString *)string;
+(BOOL)isSchemeAllowed:(NSString *)userScheme forOptions:(NSArray *)merchantOptions;
+(BOOL)isBankAllowed:(NSString *)userBank forOptions:(NSArray *)merchantOptions;
+(CTSPgSettings *)getCachedPgSetting;
+(CTSPgSettings *)getCachedLoadMoneyPgSetting;
+ (void)logProperties:(id)object;
+ (BOOL)validateDecimalAmountString:(NSString *)amount;
+ (NSString *)correctCommonAmountFormat:(NSString *)amount;
@end
