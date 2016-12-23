# Getting Started  

![CitrusPay logo](http://www.citruspay.com/images/logo.png "CitrusPay") 

## CitrusPay iOS SDK V 4.0.2

## Introduction
The CitrusPay iOS SDK enables collection of payments via various payment methods.

It is meant for consumption by [CitrusPay](http://www.citruspay.com) partners who are developing their own iOS apps aimed at merchants and/or consumers.

##Features
CitrusPay iOS SDK broadly offers following features.
+ Prepaid Payments.
+ Direct credit/debit card (CC, DC) or netbanking payments (NB) .
+ Saving Credit/Debit cards into user's account for easier future payments by abiding The Payment Card Industry Data Security Standard (PCI DSS).
+ Loading Money into users Citrus prepaid account for Prepaid facility .
+ Withdraw the money back into User's bank account from the Prepaid account .
+ Creating Citrus account for the user .

####[ChangeLog](https://github.com/citruspay/citruspay-ios-sdk/wiki/ChangeLog)

####[Migration from 3.0.x to 3.1.x or higher](https://github.com/citruspay/citruspay-ios-sdk/wiki/5-Migration-From-V-3.0.x-to-V-3.1.x)

## Usage

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Requirements
+ Xcode 6 or higher.

###Citrus PG Prerequisites
+ You need to enroll with Citrus as a merchant.
+ You need to host Bill generator on your server
+ You need to host Return Url Page on your server. (After the transaction is complete, Citrus posts a response to this URL.)
+ Make sure that you have obtained following parameters from your Citrus admin panel
+ Merchant Secret Key
+ Merchant Access Key
+ SignIn Key
+ SignIn Secret
+ SignUp Key
+ SignUp Secret

Note: Please DO NOT PROCEED if the above mentioned requirements have not been met.

## Installation

#### Using [cocoapods](https://cocoapods.org/) (recommended)
+ The recommended installation mechanism for CitrusPay is via CocoaPods. CocoaPods is an Objective-C library dependency manager that streamlines the process of installing, configuring, and updating third-party libraries.
You can learn more about CocoaPods at the website: http://cocoapods.org/
+ Add `pod "CitrusPay"` to your podfile
+ Run `pod install`
+ You should now be able to add SDK to any of your target's source files and begin using CitrusPay SDK!
+ Using Swift `import CitrusPay` Or Objective-C `#import <CitrusPay/CitrusPay.h>`
+ Done!

#### Using Submodule
+ If you do not wish to use CocoaPods then the secondary recommendation is to use a submodule. This allows you to easily track updates using standard Git commands. The first step to installation is to add the submodule to your project:
~~~{.m}
$ cd /path/to/MyApplication
# If this is a new project, initialize git...
$ git init
$ git submodule add git://github.com/citruspay/citruspay-ios-sdk.git
$ git submodule update --init --recursive
$ open citruspay-ios-sdk
~~~
+ Navigate to "Framework" folder & drag "core-sdk" folder into your existing Xcode project
+ Select the target you wish to add "core-sdk" to
+ Navigate to `Build Phases` tab and expand the `Link Binary With Libraries` section
+ Click the + and `CitrusPay.framework` appropriate to your target's platform
+ Then navigate to `General` tab and expand the `Embedded Binaries` section
+ Click the + and `CitrusPay.framework` appropriate to your target's platform
+ Add dependency 
    1. Download the JSONModel repository as a [zip file](https://github.com/icanzilb/JSONModel/archive/master.zip) or clone it
    2. Copy the JSONModel folder into your Xcode project finder
    3. Drag the `JSONModel.xcodeproj` from sub-folder into your Xcode project (i.e using direct project dependency)
    4. Select the target you wish to add "JSONModel" to
    5. Navigate to `Build Phases` tab and expand the `Link Binary With Libraries` section
    6. Click the + and `JSONModel.framework` appropriate to your target's platform
    7. Then navigate to `General` tab and expand the `Embedded Binaries` section
    8. Click the + and `JSONModel.framework` appropriate to your target's platform
    9. Link your app to SystemConfiguration.framework
+ You should now be able to add SDK to any of your target's source files and begin using CitrusPay SDK!
+ Using Swift `import CitrusPay` Or Objective-C `#import <CitrusPay/CitrusPay.h>`
+ Done!


#### Using Library Binaries (manual way)
+ Download the latest zip file from our [releases page](https://github.com/citruspay/citruspay-ios-sdk/releases) or as a direct [download latest release](https://github.com/citruspay/citruspay-ios-sdk/releases/download/4.0.2/Framework.zip)
+ Unzip the file
+ Or clone it 
~~~{.m}
$ git clone --recursive https://github.com/citruspay/citruspay-ios-sdk.git
$ open citruspay-ios-sdk
~~~
+ Navigate to "Framework" folder & drag "core-sdk" folder into your existing Xcode project
+ In Xcode, go to your app's target settings. On the `Build Phases` tab, expand the `Link Binary With Libraries` section.
+ Include the following framework:
- `CitrusPay.framework`
+ In Xcode, go to your app's target settings. On the `General` tab, expand the `Embedded Binaries` section.
+ Include the following framework:
- `CitrusPay.framework`
+ Add dependency 
    1. Download the JSONModel repository as a [zip file](https://github.com/icanzilb/JSONModel/archive/master.zip) or clone it
    2. Copy the JSONModel folder into your Xcode project finder
    3. Drag the `JSONModel.xcodeproj` from sub-folder into your Xcode project (i.e using direct project dependency)
    4. Select the target you wish to add "JSONModel" to
    5. Navigate to `Build Phases` tab and expand the `Link Binary With Libraries` section
    6. Click the + and `JSONModel.framework` appropriate to your target's platform
    7. Then navigate to `General` tab and expand the `Embedded Binaries` section
    8. Click the + and `JSONModel.framework` appropriate to your target's platform
    9. Link your app to SystemConfiguration.framework
+ You should now be able to add SDK to any of your target's source files and begin using CitrusPay SDK!
+ Using Swift `import CitrusPay` Or Objective-C `#import <CitrusPay/CitrusPay.h>`
+ Done!

## Documentation
HTML documentation is hosted on our [CitrusPay Developer Guide](http://developers.citruspay.com/ios/iosReg.html).

Git Wiki documentation is available on the [Git Wiki Documentation](https://github.com/citruspay/citruspay-ios-sdk/wiki).

## SDK Organization

### CitrusPay.h
`CitrusPay.h` is the starting point for consuming the SDK, and contains the primary class you will interact with.
It exposes all the methods you can call to accept payments via the supported payment methods.
Detailed reference documentation is available on the reference page for the `CitrusPay` class.

### Data Models
All other classes in the SDK are data models that are used to exchange data between your app and the SDK. 
Detailed reference documentation is available on the reference page for each class.

## Next Steps
Head over to the [Git Wiki Documentation](https://github.com/citruspay/citruspay-ios-sdk/wiki) to see all the API methods available. When you are ready, look at the samples below to learn how to interact with the SDK.
