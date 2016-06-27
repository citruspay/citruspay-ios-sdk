#
# Be sure to run `pod lib lint CitrusPay.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = "CitrusPay"
  s.version          = "3.3.1"
  s.summary          = "CitrusPay iOS SDK."

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!  
  s.description      = "Enhanced CitrusPay iOS SDK for Superior Native Payments Experience."

  s.homepage         = "https://github.com/citruspay/citruspay-ios-sdk"
# s.screenshots     = "www.example.com/screenshots_1", "www.example.com/screenshots_2"
  s.license          = 'MIT'
  s.author           = { "Mukesh Patil" => "mukesh.patil@citruspay.com" }
  s.source           = { :git => "https://github.com/citruspay/citruspay-ios-sdk.git", :tag => s.version.to_s }
# s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.platform     = :ios, '7.0'
  s.requires_arc = true

  s.ios.preserve_paths   = '**'
  s.public_header_files = 'CitrusPay-Framework/CitrusPay.framework/**/*.h'
  s.vendored_frameworks  = 'CitrusPay-Framework/CitrusPay.framework'

  s.resource = "CitrusPay-Framework/CitrusPay.bundle"

  s.dependency 'JSONModel'
end
