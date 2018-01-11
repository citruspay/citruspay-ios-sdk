//
//  CTSLogLevelWrapper.h
//  CitrusPay
//
//  Created by Rajvinder Singh on 11/27/17.
//  Copyright © 2017 Citrus Payment Solutions Private Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    LogLevelVerbose,
    LogLevelDebug,
    LogLevelInfo,
    LogLevelWarning,
    LogLevelError,
    LogLevelSevere,
    LogLevelNone
} LogLevel;

@interface CTSLogLevelWrapper : NSObject

+ (void)logWithLogLevel:(LogLevel)level logMessage:(NSString *)logMessage;

+ (void)setOutputLogLevel:(LogLevel)level;

@end
