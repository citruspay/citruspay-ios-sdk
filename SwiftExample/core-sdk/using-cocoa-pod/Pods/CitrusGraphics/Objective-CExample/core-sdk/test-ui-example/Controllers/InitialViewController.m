//
//  InitialViewController.m
//  CTS iOS Sdk
//
//  Created by Vikas Singh on 1/13/16.
//  Copyright © 2016 Citrus. All rights reserved.
//

#import "InitialViewController.h"
#import "SignUpViewController.h"
#import "CardsViewController.h"

@interface InitialViewController (){
    
    BOOL isDirectPaymentEnable;
    UIAlertView *alert;

}

@end

@implementation InitialViewController

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
     self.signupOptionOneButton.layer.cornerRadius = 4;
     self.signupOptionTwoButton.layer.cornerRadius = 4;
     self.signupOptionThreeButton.layer.cornerRadius = 4;
    
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (IBAction)selectLoginTypeAction:(UIButton *)sender{
    
    if (sender.tag == 1000) {
        isDirectPaymentEnable = TRUE;
        dispatch_async(dispatch_get_main_queue(), ^{
            
            alert = [[UIAlertView alloc] initWithTitle:@"" message:@"Please enter amount." delegate:self cancelButtonTitle:@"Cancel" otherButtonTitles:@"Ok" , nil];
            alert.alertViewStyle = UIAlertViewStylePlainTextInput;
            UITextField * alertTextField = [alert textFieldAtIndex:0];
            alertTextField.keyboardType = UIKeyboardTypeDecimalPad;
            alertTextField.placeholder = @"Amount";
            [alert show];
        });
    }
    else {
        
        if (authLayer.requestSignInOauthToken.length != 0) {
            dispatch_async(dispatch_get_main_queue(), ^{
                [self performSegueWithIdentifier:@"HomeScreenIdentifier" sender:nil];
            });
        }
        else{
            dispatch_async(dispatch_get_main_queue(), ^{
                [self performSegueWithIdentifier:@"SignupViewIdentifier" sender:nil];
            });
        }
        
    }
}

#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    
    if ([segue.identifier isEqualToString:@"CardViewIdentifier"]) {
        
        CardsViewController *viewController = (CardsViewController *)[segue destinationViewController];
        viewController.isDirectPaymentEnable = isDirectPaymentEnable;
        viewController.amount = [alert textFieldAtIndex:0].text;
        viewController.landingScreen = 1;
    }
    
}

#pragma mark - AlertView Delegate Methods
- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex{
    
    [self.view endEditing:YES];
    
    if (buttonIndex==1) {
        dispatch_async(dispatch_get_main_queue(), ^{
            [self performSegueWithIdentifier:@"CardViewIdentifier" sender:self];
        });
    }
}

@end
