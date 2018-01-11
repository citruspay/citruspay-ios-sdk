//
//  PnPWithdrawConfirmDetailsViewController.h
//  PlugNPlay
//
//  Created by Rajvinder Singh on 12/8/17.
//  Copyright © 2017 Citrus Payment Solutions, Pvt. Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PnPWithdrawConfirmDetailsViewController;

@protocol PnPWithdrawConfirmDetailsViewControllerDelegate <NSObject>

@optional
- (void)dismissAndPresentVC2:(PnPWithdrawConfirmDetailsViewController *)sender;

@end

@interface PnPWithdrawConfirmDetailsViewController : UIViewController

@property (assign,nonatomic) BOOL isAccountChange;
@property (assign,nonatomic) BOOL isSaveAccountChecked;

@property (weak, nonatomic) id <PnPWithdrawConfirmDetailsViewControllerDelegate> delegate;

@property (weak, nonatomic) IBOutlet UILabel *name;
@property (weak, nonatomic) IBOutlet UILabel *accountNumber;
@property (weak, nonatomic) IBOutlet UILabel *IfscCode;
@property (weak, nonatomic) IBOutlet UILabel *amount;
@property (weak, nonatomic) IBOutlet UILabel *amountLabel;
@property (weak, nonatomic) IBOutlet UIImageView *amountImage;
@property (weak, nonatomic) IBOutlet UIButton *btnConfirm;

@end
