# Getting Started                         {#mainpage}

![CitrusPay logo](http://www.citruspay.com "CitrusPay")

## Introduction
The CitrusPay iOS SDK enables collection of payments via various payment methods.

It is meant for consumption by [CitrusPay](http://www.citruspay.com) partners who are developing their own iOS apps aimed at merchants and/or consumers.

## Usage

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Requirements

## Installation

#### Using [cocoapods](https://cocoapods.org/) (recommended)
+ Add `pod "CitrusPay"` to your podfile
+ Run `pod install`
+ Done!

#### Using library binaries
+ Download the latest zip file from our [releases page](https://github.com/citruspay/citruspay-ios-sdk/wiki)
+ Unzip the file and copy the contents anywhere inside your project directory
+ In Xcode, go to your app's target settings. On the `Build Phases` tab, expand the `Link Binary With Libraries` section.
+ Include the following framework and bundle files you copied:
    - CitrusPay.framework
    - CitrusPayResources.bundle
+ Done!

## Documentation
HTML documentation is hosted on our [CitrusPay Developer Guide](http://developers.citruspay.com/ios/iosReg.html).

Pdf documentation is available on the [releases page](https://github.com/citruspay/citruspay-ios-sdk/wiki) or as a direct [download](https://github.com/citruspay/citruspay-ios-sdk/wiki).

## SDK Organization

### CitrusPay.h
`CitrusPay.h` is the starting point for consuming the SDK, and contains the primary class you will interact with.
It exposes all the methods you can call to accept payments via the supported payment methods.
Detailed reference documentation is available on the reference page for the `CitrusPay` class.

### Data Models
All other classes in the SDK are data models that are used to exchange data between your app and the SDK. 
Detailed reference documentation is available on the reference page for each class.

## Next Steps
Head over to the [documentation](https://github.com/citruspay/citruspay-ios-sdk) to see all the API methods available.
When you are ready, look at the samples below to learn how to interact with the SDK.

## Samples

See the [Example app](https://github.com/citruspay/citruspay-ios-sdk/tree/master/Example) for a working implementation of all API methods.

Note: make sure to open the project using `CitrusPay.xcworkspace` and not `CitrusPay.xcodeproj`.

### Initializing the SDK

+ Complete the installation steps (above).
+ Include CitrusPay.h
~~~{.m}
#import <CitrusPay/CitrusPay.h>
