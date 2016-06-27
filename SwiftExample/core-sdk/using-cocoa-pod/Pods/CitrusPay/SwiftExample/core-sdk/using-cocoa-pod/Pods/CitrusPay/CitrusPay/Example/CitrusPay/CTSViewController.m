//
//  CTSViewController.m
//  CitrusPay
//
//  Created by Mukesh Patil on 12/30/2015.
//  Copyright © 2015 CitrusPay. All rights reserved.
//

#import "CTSViewController.h"
#import "MerchantConstants.h"

@interface CTSViewController ()

@end

@implementation CTSViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    CTSKeyStore *keyStore = [[CTSKeyStore alloc] init];
    keyStore.signinId = SignInId;
    keyStore.signinSecret = SignInSecretKey;
    keyStore.signUpId = SubscriptionId;
    keyStore.signUpSecret = SubscriptionSecretKey;
    keyStore.vanity = VanityUrl;
    
    NSString *filePath;
    NSBundle *bundle = [NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:@"CitrusPayiOSSDK-Resources" ofType:@"bundle"]];
    filePath = [bundle pathForResource:@"SandboxEnv" ofType:@"plist"];
    NSLog(@"filePath %@", filePath);
    
    if([[NSFileManager defaultManager] fileExistsAtPath:filePath] == NO){
        [NSException raise:@"FILE NOT FOUND" format:@"file not found at %@.%@",filePath,@"plist"];
    }
    
    NSString *imagePath;
    imagePath = [bundle pathForResource:@"Mastercard" ofType:@"tiff"];
    NSLog(@"imagePath %@", imagePath);
    
    if([[NSFileManager defaultManager] fileExistsAtPath:imagePath] == NO){
        [NSException raise:@"FILE NOT FOUND" format:@"file not found at %@.%@",imagePath,@"tiff"];
    }
    
    
    //    [CitrusPaymentSDK initializeWithKeyStore:keyStore environment:CTSEnvProduction];
    [CitrusPaymentSDK initializeWithKeyStore:keyStore environment:CTSEnvSandbox];
    
    
    authLayer = [CTSAuthLayer fetchSharedAuthLayer];
    proifleLayer = [CTSProfileLayer fetchSharedProfileLayer];
    paymentLayer = [CTSPaymentLayer fetchSharedPaymentLayer];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
