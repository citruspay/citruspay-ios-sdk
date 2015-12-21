//
//  CTSRestCoreConstants.h
//  CTSRestKit
//
//  Created by Yadnesh Wankhede on 30/07/14.
//  Copyright (c) 2014 CitrusPay. All rights reserved.
//

#ifndef CTSRestKit_CTSRestCoreConstants_h
#define CTSRestKit_CTSRestCoreConstants_h

enum {
  CTSStatusCodeClassInformational = 100,
  CTSStatusCodeClassSuccessful = 200,
  CTSStatusCodeClassRedirection = 300,
  CTStatusCodeClassClientError = 400,
  CTStatusCodeClassServerError = 500
};
typedef NSUInteger CTSStatusCodeClass;
#define CTSStatusCodeRangeLength 100
#endif
