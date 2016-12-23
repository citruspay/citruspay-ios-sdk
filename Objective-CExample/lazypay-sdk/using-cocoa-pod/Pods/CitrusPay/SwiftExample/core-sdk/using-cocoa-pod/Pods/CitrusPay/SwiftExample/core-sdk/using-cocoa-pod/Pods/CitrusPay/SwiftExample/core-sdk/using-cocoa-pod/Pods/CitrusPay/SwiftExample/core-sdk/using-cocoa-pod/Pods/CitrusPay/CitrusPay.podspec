#
# Be sure to run `pod lib lint CitrusPay.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
s.name             = "CitrusPay"
s.version          = "3.7.0"
s.summary          = "CitrusPay iOS SDK."

s.description      = "Enhanced CitrusPay iOS SDK for Superior Native Payments Experience."

s.homepage         = "https://github.com/citruspay/citruspay-ios-sdk"
s.license          = 'MIT'
s.author           = { "Mukesh Patil" => "mukesh.patil@citruspay.com" }
s.source           = { :git => "https://github.com/citruspay/citruspay-ios-sdk.git", :tag => s.version.to_s }

s.platform     = :ios, '7.0'
s.requires_arc = true

s.ios.preserve_paths   = '**'
#s.public_header_files = 'Framework/core-sdk/CitrusPay.framework/**/*.h'
s.vendored_frameworks  = 'Framework/core-sdk/CitrusPay.framework'

s.resource = "Framework/core-sdk/CitrusPay.bundle"

s.dependency 'JSONModel'

#s.framework    = 'SystemConfiguration'
end
