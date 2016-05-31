//
//  HomeViewController.swift
//  CitrusPayExample
//
//  Created by Mukesh Patil on 4/19/16.
//  Copyright © 2016 CitrusPay. All rights reserved.
//

import UIKit

class HomeViewController: BaseClassViewController {
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        self.authLayer?.requestMasterLink(TEST_EMAIL,
            mobile: TEST_MOBILE,
            scope:CTSWalletScopeFull,
            completionHandler: { (linkResponse, error) -> Void in
                if(error != nil){
                    UIUtility.toastMessageOnScreen(error.localizedDescription)
                    print("Response JSON: \(error.localizedDescription)")
                }else{
                    UIUtility.toastMessageOnScreen(linkResponse.userMessage)
                    print("success")
                    
                    dispatch_async(dispatch_get_main_queue(),{
                        self.showAndVerifyOtp()
                    })
                }
                
        })
        
        
    }
    
    
    func showAndVerifyOtp() -> Void {
        
        if #available(iOS 8.0, *) {
            let alert = UIAlertController (title: "", message: "Please enter the OTP sent to your phone", preferredStyle: UIAlertControllerStyle.Alert)
            alert.addAction(UIAlertAction(title: "Cancel", style: UIAlertActionStyle.Default, handler: nil))
            alert.addAction(UIAlertAction(title: "Done", style: UIAlertActionStyle.Default, handler: { (action) -> Void in
                // Now do whatever you want with inputTextField (remember to unwrap the optional)
                self.authLayer?.requestMasterLinkSignInWithPassword(alert.textFields![0].text,
                    passwordType: PasswordTypeOtp,
                    completionHandler: { (error) -> Void in
                        if (error != nil) {
                            // Handle Error
                            UIUtility.toastMessageOnScreen("Verification Failed")
                            print("Verification Failed")
                        }
                        else{
                            // Handle Success
                            UIUtility.toastMessageOnScreen("Success")
                            print("success")
                        }
                })
            }))
            alert.addTextFieldWithConfigurationHandler({(textField: UITextField!) in
                textField.placeholder = "OTP"
                textField.keyboardType=UIKeyboardType.NumberPad
            })
            
            self.presentViewController(alert, animated: true, completion: nil)

        } else {
            // Fallback on earlier versions
        }
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    // this is just sample code 
    class  func requestBillAmount (amount :NSString, customParams :NSArray, billURL :NSString, completion : (bill :CTSBill? ,error :NSError?)->Void){
        let session = NSURLSession.sharedSession();
        
        let url = NSURL(string: "\(billURL)?amount\(amount)&\(customParams)")
        
        let loadTask = session.dataTaskWithURL(url!) { (data :NSData?, response :NSURLResponse?, error :NSError?) -> Void in
            if let errorResponse = error {
                completion(bill: nil, error: errorResponse)
            }else if let httpResponse = response as? NSHTTPURLResponse{
                if httpResponse.statusCode != 200 {
                    let errorResponse = NSError(domain: "Domain", code: httpResponse.statusCode, userInfo: [NSLocalizedDescriptionKey :"Http status code has unexpected value"])
                    completion(bill: nil, error: errorResponse)
                }else{
                    let dataString = String(data: data!, encoding: NSUTF8StringEncoding)
                    var jsonError : JSONModelError?
                    let sampleBill: CTSBill = CTSBill(string:dataString, error:&jsonError)
                    if (jsonError != nil) {
                        completion(bill: sampleBill, error: nil)
                    }
                    else {
                        completion(bill: sampleBill, error: nil)
                    }
                }
            }
        }
        loadTask.resume()
    }
    
}
