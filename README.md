
#open-iOS V3.1.3

####[ChangeLog](https://github.com/citruspay/open-ios/wiki/ChangeLog)

####[Migration from 3.0.x to 3.1.x](https://github.com/citruspay/open-ios/wiki/5-Migration-From-V-3.0.x-to-V-3.1.x)


============
###SDK Installation Prerequisites
   * Xcode 6 or higher.
   
###Citrus PG Prerequisites
* You need to enroll with Citrus as a merchant.
* You need to host Bill generator on your server
* You need to host Return Url Page on your server. (After the transaction is complete, Citrus posts a response to this URL.)
* Make sure that you have obtained following parameters from your Citrus admin panel
	* Merchant Secret Key
	* Merchant Access Key
	* SignIn Key
	* SignIn Secret
	* SignUp Key
	* SignUp Secret

Note: Please DO NOT PROCEED if the above mentioned requirements have not been met.

###Features
Citrus iOS SDK broadly offers following features.
* Prepaid Payments.
* Direct credit/debit card (CC, DC) or netbanking payments (NB) .
* Saving Credit/Debit cards into user's account for easier future payments by abiding The Payment Card Industry Data Security Standard (PCI DSS).
* Loading Money into users Citrus prepaid account for Prepaid facility .
* Withdraw the money back into User's bank account from the Prepaid account .
* Creating Citrus account for the user .



### Installation From source code
Get the latest source code from github.com:
```bash
$ git clone https://github.com/citruspay/open-ios.git
```
### How to Run Sample code 
To run the sample code, double click on "CTS iOS Sdk.xcodeproj" file from downloaded sample code and select target as in video and run the App.

![Drag Drop](http://g.recordit.co/frxNZEzITj.gif)

### Xcode integration

To integrate the SDK you just have to drag drop folder CitrusDevKit/  into your project as groups, import CitrusSdk.h and populate the macros in MerchantConstants.h with the parameters you obatained from your Citrus admin panel

![Drag Drop](https://dl.dropboxusercontent.com/u/6397934/citrus/SDKScreens/Integrate.gif)

import "CitrusSdk.h"

![import](https://dl.dropboxusercontent.com/u/6397934/citrus/GIT/Import.png)

## Let's Start Programming now

SDK operates in two different modes Sandbox and Production mode. for both the enviroments Citrus PG Prerequisites key sets are different. keys from one enviroment won't work on other. so please make sure you are using correct set of keys.
During the developement you would always want to use the Sandbox mode. once you are done with your App development you can switch to production mode . 

you need to use `[CitrusPaymentSDK initializeWithKeyStore: environment:]` to initialize the SDK

Sandbox:

		    [CitrusPaymentSDK initializeWithKeyStore:keyStore environment:CTSEnvSandbox];

Production:

		    [CitrusPaymentSDK initializeWithKeyStore:keyStore environment:CTSEnvProduction];


####How to configure KeyStore Object
   As you must have noticed the SDK initialization requires you to pass the Keystore object please see below how to configure it.     
   
   
   
		    CTSKeyStore *keyStore = [[CTSKeyStore alloc] init];
		    keyStore.signinId = @"test-signin";
		    keyStore.signinSecret = @"52f7e15efd4208cf5345dd554443fd99";
		    keyStore.signUpId = @"test-signup";
		    keyStore.signUpSecret = @"c78ec84e389814a05d3ae46546d16d2e";
		    keyStore.vanity = @"testing";


Only after you are done with initialization you can proceed with following guide 

The SDK is logically divided into 3 modules/layers or interfacing classes
 * CTSAuthLayer - handles all of the user creation related tasks .
 * CTSProfileLayer - handles all of the user profile related tasks .
 * CTSPaymentLayer - handles all of the payment related tasks .
 
To use any of the above layers your need to fetch their singlton instance from CitrusPaymentSDK's class methods,


		
		// initialization in your .m file
			CTSPaymentLayer *paymentLayer = [CitrusPaymentSDK fetchSharedPaymentLayer];
			CTSAuthLayer *authLayer = [CTSAuthLayer fetchSharedAuthLayer];
           	CTSProfileLayer *proifleLayer = [CTSProfileLayer fetchSharedProfileLayer];
   
 

Following are the specific tasks related to each of the layer 

#[Important Update for iOS 9](https://github.com/citruspay/open-ios/wiki/4.-Common-Errors#ios-9-ssl-errors--fix)


#####User Management
 * [See if anyone is logged in](https://github.com/citruspay/open-ios/wiki/1.--Integrating-CTSAuthLayer#see-if-anyone-is-logged-in)
 * [Bind User](https://github.com/citruspay/open-ios/wiki/1.--Integrating-CTSAuthLayer#bind-user) (doens't need password, enables user to save cards)
 * [Creating & Linking the User](https://github.com/citruspay/open-ios/wiki/1.--Integrating-CTSAuthLayer#get-users-prepaid-level-access-link-user) (creates user prepaid acount,fires otp for signin, required for all prepaid related operations)
 * [Signin the user for Prepaid level access](https://github.com/citruspay/open-ios/wiki/1.--Integrating-CTSAuthLayer#sign-in-the-user-for-prepaid-level-access)
 * [Reset User Password](https://github.com/citruspay/open-ios/wiki/1.--Integrating-CTSAuthLayer#reset-user-password)
 * [Sign Out](https://github.com/citruspay/open-ios/wiki/1.--Integrating-CTSAuthLayer#sign-out)
 

#####Card Management
 * [Save User Cards](https://github.com/citruspay/open-ios/wiki/2.--Integrating-CTSProfileLayer#save-user-cards)
 * [Get Saved Cards](https://github.com/citruspay/open-ios/wiki/2.--Integrating-CTSProfileLayer#get-saved-cards)
 * [Delete Saved Cards](https://github.com/citruspay/open-ios/wiki/2.--Integrating-CTSProfileLayer#delete-saved-cards)
 
#####Wallet Management & Payment
 * [Get User's Prepaid Balance](https://github.com/citruspay/open-ios/wiki/2.--Integrating-CTSProfileLayer#get-users-prepaid-balance)
 * [Save Cashout Bank Account](https://github.com/citruspay/open-ios/wiki/2.--Integrating-CTSProfileLayer#save-cash-out-bank-account)
 * [Get Saved Cashout Bank Acoount](https://github.com/citruspay/open-ios/wiki/2.--Integrating-CTSProfileLayer#get-saved-cashout-bank-acoount)
 * [Loading Money into Users Citrus Prepaid Account](https://github.com/citruspay/open-ios/wiki/3.--Integrating-CTSPaymentLayer#loading-money-into-users-citrus-prepaid-account)
 * [Paying via Prepaid account](https://github.com/citruspay/open-ios/wiki/3.--Integrating-CTSPaymentLayer#paying-via-prepaid-accountcitrus-cash)
 * [Initiate Cashout Proccess into users Account from Citrus prepaid account](https://github.com/citruspay/open-ios/wiki/3.--Integrating-CTSPaymentLayer#initiate-cashout-process-into-users-account-from-citrus-prepaid-account)
 * [Send Money to another Citrus User](https://github.com/citruspay/open-ios/wiki/3.--Integrating-CTSPaymentLayer#send-money-to-another-citrus-user)
 


#####Doing direct payments
  * [CC, DC, NB Direct Payments](https://github.com/citruspay/open-ios/wiki/3.--Integrating-CTSPaymentLayer#cc-dc-nb-direct-payments)
  * [Saved CC, DC Payments (A.K.A. Tokenized payments)](https://github.com/citruspay/open-ios/wiki/3.--Integrating-CTSPaymentLayer#saved-cc-dc-payments-aka-tokenized-payments)

#####Dynamic Pricing Offer Coupons and Surcharge
* [How to use dynamic pricing ?](https://github.com/citruspay/open-ios/wiki/3.--Integrating-CTSPaymentLayer#dynamic-pricing-offer-coupons-surcharge)

#####Others
  * [Fetch Available Schemes and Banks for the Merchant](https://github.com/citruspay/open-ios/wiki/3.--Integrating-CTSPaymentLayer#fetch-available-schemes-and-banks-for-the-merchant)
  * [Fetch the PG Health](https://github.com/citruspay/open-ios/wiki/3.--Integrating-CTSPaymentLayer#fetch-the-pg-health)


=====
####[Common Integration Issues](https://github.com/citruspay/open-ios/wiki/4.-Common-Errors)
* [Could Not Connect to Internet](https://github.com/citruspay/open-ios/wiki/4.-Common-Errors#could-not-connect-to-internet)
* [postResponseiOS() error](https://github.com/citruspay/open-ios/wiki/4.-Common-Errors#postresponseios-error)
* [iOS 9 SSL Errors](https://github.com/citruspay/open-ios/wiki/4.-Common-Errors#ios-9-ssl-errors--fix)





