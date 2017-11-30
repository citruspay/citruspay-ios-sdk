//
//  ViewController.m
//  CitrusGraphicsExample
//
//  Created by Mukesh Patil on 11/8/16.
//  Copyright © 2016 CitrusPay. All rights reserved.
//

#import "ViewController.h"

#import <CitrusGraphics/CitrusGraphics.h>

@interface ViewController () {
    NSArray *bankCIDArray;
}
@property (nonatomic, weak) IBOutlet UITableView *tableView;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    //    self.title = [NSString stringWithFormat:@"Citrus Graphics Demo v%@", CITRUSGRAPHICS_VERSION];
    bankCIDArray = @[@"CID001", @"CID002", @"CID003", @"CID004" , @"CID005", @"CID006", @"CID007", @"CID008", @"CID009", @"CID010", @"CID011", @"CID012", @"CID013"];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:YES];
    [self.tableView reloadData];
}

#pragma mark - TableView Delegate Methods

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 6 + bankCIDArray.count;
}

- (NSInteger)tableView:(UITableView *)tableView
 numberOfRowsInSection:(NSInteger)section {
    return 1;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
    if(section == 0) {
        return @"Card Scheme";
    }
    else if(section == 1){
        return @"Card Large Scheme";
    }
    else if(section == 2) {
        return @"Bank Logo";
    }
    else if(section == 3){
        return @"Bank Large Logo";
    }
    return 0;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 60;
}

- (UITableViewCell *)tableView:(UITableView *)tableView
         cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell;
    static NSString *CellIdentifier = @"CellIdentifier";
    cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier];
    }
    [cell.contentView viewWithTag:1000].layer.cornerRadius = 5;
    
    dispatch_async(dispatch_get_main_queue(), ^{
        [cell.imageView setSystemActivity];
        
        switch (indexPath.section) {
            case 0:
                cell.textLabel.text = @"VISA Card";
                [cell.imageView loadCitrusCardWithCardScheme:@"VISA"];
                break;
            case 1:
                cell.textLabel.text = @"VISA Card";
                [cell.imageView loadCitrusLargeCardWithCardScheme:@"VISA"];
                break;
            case 2:
                cell.textLabel.text = @"ICICI Bank";
                [cell.imageView loadCitrusBankWithBankCID:@"CID001"];
                break;
            case 3:
                cell.textLabel.text = @"ICICI Bank";
                [cell.imageView loadCitrusLargeBankWithBankCID:@"CID001"];
                break;
            case 4:
                cell.textLabel.text = @"HDFC Card";
                [cell.imageView loadCitrusBankWithIFSCCode:@"HDFC"];
                break;
            case 5:
                cell.textLabel.text = @"HDFC Card";
                [cell.imageView loadCitrusLargeBankWithIFSCCode:@"HDFC"];
                break;
                
            default:
                cell.textLabel.text = bankCIDArray[indexPath.section-6];
                [cell.imageView loadCitrusBankWithBankCID:bankCIDArray[indexPath.section-6]];
                break;
        }
        
    });
    
    
    return cell;
}


@end

