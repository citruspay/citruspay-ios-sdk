//
//  BaseClassViewController.swift
//  CitrusPayExample
//
//  Created by Mukesh Patil on 4/19/16.
//  Copyright © 2016 CitrusPay. All rights reserved.
//

import Foundation

class BaseClassViewController: UIViewController {
    
    var authLayer : CTSAuthLayer?
    var profileLayer : CTSProfileLayer?
    var paymentLayer : CTSPaymentLayer?
    
    var contactInfo : CTSContactUpdate?
    var addressInfo : CTSUserAddress?
    var customParams: [String : AnyObject] = [:]
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        self.initializeSDK()
    }
    
    
    func initializeSDK() -> Void {
        
        let keyStore : CTSKeyStore = CTSKeyStore()
        keyStore.signinId = SignInId
        keyStore.signinSecret = SignInSecretKey
        keyStore.signUpId = SubscriptionId
        keyStore.signUpSecret = SubscriptionSecretKey
        keyStore.vanity = VanityUrl
        
        #if PRODUCTION_MODE
            CitrusPaymentSDK.initializeWithKeyStore(keyStore, environment: CTSEnvProduction)
            #else
            CitrusPaymentSDK.initializeWithKeyStore(keyStore, environment: CTSEnvSandbox)
        #endif
        
        
        CitrusPaymentSDK.enableDEBUGLogs()
        
        self.authLayer = CTSAuthLayer.fetchSharedAuthLayer()
        self.profileLayer = CTSProfileLayer.fetchSharedProfileLayer()
        self.paymentLayer = CTSPaymentLayer.fetchSharedPaymentLayer()
        
        
        contactInfo?.firstName = TEST_FIRST_NAME;
        contactInfo?.lastName = TEST_LAST_NAME;
        contactInfo?.email = TEST_EMAIL;
        contactInfo?.mobile = TEST_MOBILE;
        
        addressInfo?.city = TEST_CITY;
        addressInfo?.country = TEST_COUNTRY;
        addressInfo?.state = TEST_STATE;
        addressInfo?.street1 = TEST_STREET1;
        addressInfo?.street2 = TEST_STREET2;
        addressInfo?.zip = TEST_ZIP;
        
        customParams = ["USERDATA2":"MOB_RC|9988776655",
            "USERDATA10":"test",
            "USERDATA4":"MOB_RC|test@gmail.com",
            "USERDATA3":"MOB_RC|4111XXXXXXXX1111"]
        
    }
    
    
}

