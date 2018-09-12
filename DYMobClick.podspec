Pod::Spec.new do |s|
  s.name         = "DYMobClick"
  s.version      = "1.0.0"
  s.summary      = "A clone of emoticonkeyboard, support picking multiple photos、original photo and video"
  s.homepage     = "https://github.com/kerain/DYMobClick"
  s.license      = "MIT"
  s.author       = { "kerain" => "kerain@foxmail.com" }
  s.platform     = :ios
  s.ios.deployment_target = "8.0"
  s.source       = { :git => "https://github.com/kerain/DYMobClick.git", :tag => "#{s.version}" }
  s.requires_arc = true
  s.source_files = "DYAnalytics/DYAnalytics/*.h"
  s.resources    = "DYAnalytics/DYAnalytics/*.plist"
  s.vendored_frameworks = 'Products/DYUMobClick.framework'
end
