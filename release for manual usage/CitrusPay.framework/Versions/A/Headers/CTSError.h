//
//  CTSError.h
//  CTS iOS Sdk
//
//  Created by Yadnesh Wankhede on 26/06/14.
//  Copyright (c) 2014 Citrus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CTSPaymentTransactionRes.h"
#import "CTSResponse.h"
#import "CTSDyPResponse.h"


typedef enum {
    NoError = 7000,
    UserNotSignedIn,
    EmailNotValid,
    MobileNotValid,
    CvvNotValid,
    CardNumberNotValid,
    ExpiryDateNotValid,
    ServerErrorWithCode,
    InvalidParameter,
    OauthTokenExpired,
    CantFetchSignupToken,
    TokenMissing,
    InternetDown,
    WrongBill,
    NoViewController,
    ReturnUrlNotValid,
    AmountNotValid,
    PrepaidBillFetchFailed,
    NoOrMoreInstruments,
    BankAccountNotValid,
    NoCookieFound,
    ReturnUrlCallbackNotValid,
    TransactionForcedClosed,
    TransactionAlreadyInProgress,
    InsufficientBalance,
    CardHolderNameInvalid,
    DeleteCardNumberNotValid,
    MessageNotValid,
    BinCardLengthNotValid,
    DPRuleNameNotValid,
    DPAlteredAmountNotValid,
    PaymentInfoInValid,
    DPRequestTypeInvalid,
    DPSignatureInvalid,
    DPResponseNotFound,
    CitrusPaymentTypeInvalid,
    BankIssuerCode,
    UndefinedPaymentType,
    NoSigninData,
    BillUrlNotInvalid,
    DPOriginalAmountNotValid,
    CardTokenInvalid,
    DPMerchantQueryNotValid,
    TransactionFailed,
    KeyStoreNotSet,
    CitrusLinkResponseNotFound,
    CompletionHandlerNotFound,
    UnknownPasswordType,
    NoNewPrepaidPrelivilage


} CTSErrorCode;






#define CITRUS_ERROR_DOMAIN @"com.citrus.errorDomain"
#define CITRUS_ERROR_DOMAIN_DP @"com.citrus.errorDomainDp"
#define CITRUS_ERROR_DESCRIPTION_KEY @"CTSServerErrorDescription"
#define INTERNET_DOWN_STATUS_CODE 0

@interface CTSError : NSObject
// Follwoing methods are for internal use only
+ (NSError*)getErrorForCode:(CTSErrorCode)code;
//+ (NSError*)getErrorForCode:(CTSErrorCode)code paramType:();

+ (NSError*)getServerErrorWithCode:(int)errorCode
                          withInfo:(NSDictionary*)information;
+(NSString *)getFakeJsonForCode:(CTSErrorCode)errorCode;
+(NSError *)errorForStatusCode:(int)statusCode;
+(NSError *)convertToError:(CTSPaymentTransactionRes *)ctsPaymentTxRes;
+(NSError *)convertToErrorDyIfNeeded:(CTSDyPResponse *)ctsPaymentTxRes;
+(NSError *)convertCTSResToErrorIfNeeded:(CTSResponse *)response;
@end
