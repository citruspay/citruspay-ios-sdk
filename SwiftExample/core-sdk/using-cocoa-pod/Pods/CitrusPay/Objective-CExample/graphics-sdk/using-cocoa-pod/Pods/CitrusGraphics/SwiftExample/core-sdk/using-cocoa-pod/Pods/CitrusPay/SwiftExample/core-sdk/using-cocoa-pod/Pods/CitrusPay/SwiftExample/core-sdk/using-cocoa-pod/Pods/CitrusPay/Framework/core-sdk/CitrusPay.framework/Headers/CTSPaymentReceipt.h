//
//  CTSPaymentReceipt.h
//  CitrusPay
//
//  Created by Mukesh Patil on 1/29/16.
//  Copyright © 2016 CitrusPay. All rights reserved.
//

#import <JSONModel/JSONModel.h>

@interface CTSPaymentReceipt : JSONModel
/*!
 *  @brief The CTSPaymentReceipt class' toDictionary object.
 */
@property (strong) NSMutableDictionary *toDictionary;
@end
