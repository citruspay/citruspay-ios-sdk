//
//  PnPDeleteSavedCardViewController.h
//  PlugNPlay
//
//  Created by Rajvinder Singh on 12/5/17.
//  Copyright © 2017 Citrus Payment Solutions, Pvt. Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PnPDeleteSavedCardViewController;

@protocol PnPDeleteSavedCardViewControllerDelegate <NSObject>

@optional
- (void)savedCardDidDeletedWithController:(PnPDeleteSavedCardViewController *)controller;

@end

@interface PnPDeleteSavedCardViewController : UIViewController

@property (strong, nonatomic) NSDictionary *deleteCardDict;

@property (weak, nonatomic) id <PnPDeleteSavedCardViewControllerDelegate> delegate;

@end
