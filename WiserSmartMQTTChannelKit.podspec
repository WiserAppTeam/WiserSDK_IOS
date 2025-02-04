Pod::Spec.new do |s|
  s.name = "WiserSmartMQTTChannelKit"
  s.version = "3.26.6"
  s.summary = "A short description of #{s.name}."
  s.license = {"type"=>"MIT"}
  s.authors = {"0x5e"=>"gaosen.wiser.com"}
  s.homepage = "https:/.wiser.com"
  s.source = { :http => "https://raw.githubusercontent.com/sewiser/WiserSDK_IOS/master/xcframeworks/#{s.name}/#{s.version}/#{s.name}.xcframework.zip" }

  s.ios.deployment_target     = '9.0'
  s.ios.frameworks = 'CoreData'

  s.static_framework          = true
  # s.vendored_frameworks       = 'ios/*.framework'
  # s.vendored_libraries        = 'ios/*.a'
  # s.source_files = 'ios/*.framework/Versions/A/Headers/*.h'
  
  s.source_files = 'WiserSmartMQTTChannelKit.xcframework/ios-arm64/WiserSmartMQTTChannelKit.framework/Headers/*'

  s.vendored_frameworks = 'WiserSmartMQTTChannelKit.xcframework'

  s.dependency 'WiserSmartBaseKit'
  s.dependency 'TuyaSmartQUIC', '1.1.1'

end
