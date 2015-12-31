//
//  CTSPaymentDetailUpdate.h
//  RestFulltester
//
//  Created by Yadnesh Wankhede on 12/06/14.
//  Copyright (c) 2014 Citrus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CTSElectronicCardUpdate.h"
#import "CTSNetBankingUpdate.h"
#import "CTSPaymentOption.h"
#import "JSONModel.h"

@interface CTSPaymentDetailUpdate : JSONModel
@property( strong) NSString* type;
@property( strong) NSString <Optional>*defaultOption;
@property( strong) NSString<Optional>* password;
@property( strong) NSMutableArray<CTSPaymentOption>* paymentOptions;

-(instancetype)initCitrusPayWithEmail:(NSString *)email;

+(CTSPaymentDetailUpdate *)citrusPay DEPRECATED_ATTRIBUTE;

-(CTSPaymentDetailUpdate *)initCitrusCash;
/**
 *  to add card to the object, internally stored in an array to send to
 *server,card is validated before they are added to the array
 *
 *  @param card object of type CTSElectronicCardUpdate
 *
 *  @return returns SUCESS of type CardValidationError , else corrospding error
 *of type CardValidationError is returned
 */
- (void)addCard:(CTSElectronicCardUpdate*)card;

/**
 *  to add netbanking detail to the object, internally stored in an array to
 *send to server,currently no validation
 *
 *  @param netBankDetail : the detail related to bank
 *
 *  @return always returns true
 */



- (BOOL)addNetBanking:(CTSNetBankingUpdate*)netBankDetail;

-(void)addFakeNBCode;

-(CTSErrorCode)validate;

- (void)clearCVV;

- (void)clearNetbankCode;

-(CTSErrorCode)validateTokenized;

-(BOOL)isTokenized;

-(void)dummyCVVAndExpiryIfMaestro;

-(void)amexCreditcardCorrectionIfNeeded;

-(void)doCardCorrectionsIfNeeded;

@end
