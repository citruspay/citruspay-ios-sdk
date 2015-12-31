//
//  CTSProfileLayerConstants.h
//  RestFulltester
//
//  Created by Yadnesh Wankhede on 04/06/14.
//  Copyright (c) 2014 Citrus. All rights reserved.
//
#ifndef RestFulltester_CTSProfileLayerConstants_h
#define RestFulltester_CTSProfileLayerConstants_h

//

#define CITRUS_PROFILE_BASE_URL CITRUS_BASE_URL

#pragma - mark MLC_PROFILE_CARD_VALIDATION
typedef enum CardValidationError {
  WRONG_EXPIRY_DATE_FORMAT,
  WRONG_CARD_NUMBER,
  WRONG_CVV,
  SUCCESS
} CardValidationError;

#pragma - mark MLC_PROFILE_UPDATE_CONTACT

#define MLC_PROFILE_UPDATE_CONTACT_PATH @"/service/v2/profile/me/contact"
#define MLC_PROFILE_UPDATE__REQUEST_MAPPING \
  @{@"type" : @"type", @"firstName" : @"firstName", @"lastName" : @"lastName"}
#define MLC_PROFILE_UPDATE_CONTACT_METHOD PUT
#define MLC_PROFILE_UPDATE_CONTACT_ID @"UpdateContact"

#define MLC_PROFILE_UPDATE__REQUEST_TYPE [CTSContactUpdate class]

#pragma - mark MLC_PROFILE_GET_CONTACT
#define MLC_PROFILE_UPDATE_CONTACT_PATH @"/service/v2/profile/me/contact"
#define MLC_PROFILE_GET_CONTACT_METHOD GET
#define MLC_PROFILE_GET_CONTACT_RES_MAPPING \
  @{                                        \
    @"type" : @"type",                      \
    @"firstName" : @"firstName",            \
    @"lastName" : @"lastName",              \
    @"email" : @"email",                    \
    @"mobile" : @"mobile"                   \
  }

#define MLC_PROFILE_GET_CONTACT_QUERY_TYPE @"contact"
#define MLC_PROFILE_GET_RESPONSE_TYPE [CTSProfileContactRes class]
#define MLC_PROFILE_GET_CONTACT_ID @"getContact"

#pragma - mark MLC_PROFILE_UPDATE_PAYMENT
#define MLC_PROFILE_GET_PAYMENT_QUERY_TYPE @"payment"

#define MLC_PROFILE_PAYMENT_CREDIT_TYPE @"credit"
#define MLC_PROFILE_PAYMENT_DEBIT_TYPE @"debit"
#define MLC_PROFILE_PAYMENT_NETBANKING_TYPE @"netbanking"
#define MLC_PROFILE_UPDATE_PAYMENT_ID @"updatePayment"

#pragma - mark MLC_PROFILE_GET_PAYMENT
#define MLC_PROFILE_UPDATE_PAYMENT_PATH @"/service/v2/profile/me/payment"
#define MLC_PROFILE_UPDATE_PAYMENT_REQUEST_MAPPING \
  @{                                               \
    @"type" : @"type",                             \
    @"bank" : @"bank",                             \
    @"owner" : @"owner",                           \
    @"number" : @"number",                         \
    @"expiryDate" : @"expiryDate",                 \
    @"scheme" : @"scheme",                         \
    @"name" : @"name"                              \
  }

#define MLC_PROFILE_GET_PAYMENT_ID @"getPayment"

#define MLC_PROFILE_GET_PAYMENT_RESPONSE_MAPPING      \
  @{                                                  \
    @"type" : @"type",                                \
    @"bank" : @"bank",                                \
    @"owner" : @"owner",                              \
    @"number" : @"number",                            \
    @"expiryDate" : @"expiryDate",                    \
    @"scheme" : @"scheme",                            \
    @"name" : @"name",                                \
    @"token" : @"token",                              \
    @"mmid" : @"mmid",                                \
    @"impsRegisteredMobile" : @"impsRegisteredMobile" \
  }
#define MLC_PROFILE_GET_PAYMENT_RES_MAP \
  @{@"type" : @"type", @"defaultOption" : @"defaultOption"}


#define MLC_PROFILE_GET_BALANCE_PATH @"/service/v2/mycard/balance"
#define MLC_PROFILE_GET_BALANCE_TYPE GET

#define MLC_PROFILE_GET_BALANCE_ACTIVATE_PATH @"/service/v2/prepayment/balance"
#define MLC_PROFILE_GET_BALANCE_ACTIVATE_TYPE GET


#pragma - mark Cashout Bank Account
#define  CURRENCY @"INR"
#define MLC_PROFILE_CASHOUT_BANK_ACCOUNT_PATH @"/service/v2/profile/me/prepaid"


#define MLC_PROFILE_CASHOUT_BANK_ACCOUNT_UPDATE_TYPE GET

#define MLC_NEW_CONTACT_PROFILE_GET_PATH @"/service/um/profile/memberInfo"
#define MLC_NEW_CONTACT_PROFILE_GET_METHOD POST
#define MLC_NEW_CONTACT_PROFILE_GET_EMAIL @"email"
#define MLC_NEW_CONTACT_PROFILE_GET_MOBILE @"mobile"

#define MLC_PROFILE_UPDATE_MOBILE_PATH @"/service/v2/identity/me/mobile"
#define MLC_PROFILE_UPDATE_MOBILE_QUERY_MOBILE @"mobile"


//#define MLC_PROFILE_DELETE_CARD_PATH @"/service/v2/profile/me/payment"
#define MLC_PROFILE_DELETE_CARD_PATH @"/service/v2/profile/me/deletepayment"
#define MLC_PROFILE_DELETE_CARD_TYPE DELETE



#endif
