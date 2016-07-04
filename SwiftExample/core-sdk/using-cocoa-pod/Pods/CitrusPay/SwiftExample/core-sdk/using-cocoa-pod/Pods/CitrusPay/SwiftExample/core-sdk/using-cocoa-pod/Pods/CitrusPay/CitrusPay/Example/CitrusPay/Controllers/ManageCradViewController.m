//
//  ManageCradViewController.m
//  CTS iOS Sdk
//
//  Created by Vikas Singh on 10/5/15.
//  Copyright (c) 2015 Citrus. All rights reserved.
//

#import "ManageCradViewController.h"

@interface ManageCradViewController (){

    NSMutableArray *saveCardsArray;
}

@end

@implementation ManageCradViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    saveCardsArray = [[NSMutableArray alloc]init];
    [self getSaveCards:nil];
    self.saveCardsTableView.allowsMultipleSelectionDuringEditing = NO;
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (IBAction)getSaveCards:(id)sender{
    
    self.indicatorView.hidden = FALSE;
    [self.indicatorView startAnimating];
    
    // Get the bind user cards.
    // Configure your request here.
    [proifleLayer requestPaymentInformationWithCompletionHandler:^(CTSProfilePaymentRes *paymentInfo, NSError *error) {
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [self.indicatorView stopAnimating];
            self.indicatorView.hidden = TRUE;
            
        });
        if (error == nil) {
            // Your code to handle success.
            NSMutableString *toastString = [[NSMutableString alloc] init];
            if([paymentInfo.paymentOptions count])
            {
                saveCardsArray = (NSMutableArray *) paymentInfo.paymentOptions;
                // sleep(3);
                dispatch_async(dispatch_get_main_queue(), ^{
                    [self.saveCardsTableView reloadData];
                });
                
                
                //   [toastString appendString:[self convertToString:[paymentInfo.paymentOptions objectAtIndex:0]]];
                
            }
            else{
                toastString =(NSMutableString *) @"No saved cards, please save card first";
                [UIUtility toastMessageOnScreen:toastString];
            }
            
        } else {
            // Your code to handle error.
            [UIUtility toastMessageOnScreen:[NSString stringWithFormat:@"Couldn't find saved cards \nerror: %@",[error localizedDescription]]];
        }
    }];
}



#pragma mark - TableView Delegate Methods

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return saveCardsArray.count;
    
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell;
    
    static NSString *simpleTableIdentifier = @"saveCardIdentifier";
    
    cell = [tableView dequeueReusableCellWithIdentifier:simpleTableIdentifier];
    
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:simpleTableIdentifier];
        
    }
    [cell.contentView viewWithTag:1000].layer.cornerRadius = 5;
    NSDictionary *tempDict = [saveCardsArray objectAtIndex:indexPath.row];
    ((UILabel *) [cell.contentView viewWithTag:1001]).text = [tempDict valueForKey:@"name"];
    ((UILabel *) [cell.contentView viewWithTag:1002]).text = [tempDict valueForKey:@"number"];
    ((UILabel *) [cell.contentView viewWithTag:1003]).text = [tempDict valueForKey:@"owner"];
    NSMutableString *string = [[tempDict valueForKey:@"expiryDate"] mutableCopy];
    [string insertString:@"/" atIndex:2];
    ((UILabel *) [cell.contentView viewWithTag:1004]).text = string;
    
    
    dispatch_async(dispatch_get_main_queue(), ^{
        if ([[tempDict valueForKey:@"type"] isEqualToString:@"netbanking"]) {
            ((UIImageView *) [cell.contentView viewWithTag:1005]).image = [CTSUtility fetchBankLogoImageByBankName:[tempDict valueForKey:@"bank"]];
        }
        else {
            ((UIImageView *) [cell.contentView viewWithTag:1005]).image = [CTSUtility fetchSchemeImageBySchemeType:[tempDict valueForKey:@"scheme"]];
        }
    });
    UIButton *button;
    for (id view in cell.contentView.subviews){
        if ([view isKindOfClass:[UIButton class]]) {
            button  = (UIButton *) view;
            button.tag = indexPath.row;
        }
    }
    
    return cell;
}

- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath {
    // Return YES if you want the specified item to be editable.
    return YES;
}

// Override to support editing the table view.
- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath {
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        
        
        //delete saved card
        NSDictionary  *dict = [saveCardsArray objectAtIndex:indexPath.row];
       
        
        [proifleLayer requestDeleteCardWithToken:[dict valueForKey:@"token"] withCompletionHandler:^(NSError *error) {
            
            
            if (error == nil) {
                // Your code to handle success.
                NSMutableString *toastString = [[NSMutableString alloc] init];
                if([saveCardsArray count])
                {
                    // sleep(3);
                    dispatch_async(dispatch_get_main_queue(), ^{
                        [saveCardsArray removeObjectAtIndex:indexPath.row];
                        [self.saveCardsTableView reloadData];
                    });
                    
                }
                else{
                    toastString =(NSMutableString *) @"No saved cards, please save card first";
                    [UIUtility toastMessageOnScreen:toastString];
                }
                
            } else {
                // Your code to handle error.
                [UIUtility toastMessageOnScreen:[NSString stringWithFormat:@"Couldn't find saved cards \nerror: %@",[error localizedDescription]]];
            }
        }];
    }
}

@end
