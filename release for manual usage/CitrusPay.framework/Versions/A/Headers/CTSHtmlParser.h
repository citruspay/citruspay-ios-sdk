//
//  CTSHtmlParser.h
//  HTMLParser
//
//  Created by Vikas Singh on 11/13/15.
//  Copyright © 2015 Vikas Singh. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CTSHtmlElement.h"

@interface CTSHtmlParser : NSObject <NSXMLParserDelegate>

@property (strong) NSMutableString *currentNodeContent;
@property (strong) NSMutableArray *elementArray;
@property (strong) NSXMLParser *parser;
@property (strong) CTSHtmlElement *currentHTMLElement;

-(id) loadHtmlByURL:(NSString *)urlString;

@end

