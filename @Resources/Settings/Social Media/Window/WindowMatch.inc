[Variables]
TweeterButtonsHeight=25

[Close]
X=369
Y=11

[Right]
X=345
Y=11

[Gear]
X=321
Y=11

[HeightImage]
IfCondition=(HeightImage >= 0) && (HeightImage < 440)
IfTrueAction=[!WriteKeyValue Variables Height 228][!SetOption Image H 228][!SetVariable Height 228][!UpdateMeter Background][!UpdateMeter Image][!Redraw]
IfCondition2=(HeightImage >= 440)
IfTrueAction2=[!WriteKeyValue Variables Height 440][!SetOption Image H 440][!SetVariable Height 440][!UpdateMeter Background][!UpdateMeter Image][!Redraw]

[Failsafe]
X=(385/2)-7
Y=(#Height#/2)+26

[Image]
W=385

[Tweet]
FontSize=10
W=([Image:W]-16)
Padding=8, 7.7, 8, 7.7
AntiAlias=1

[Retweet]
X=([Background:W]*0.22)
W=14

[RetweetValue]
FontSize=9

[Like]
X=([Background:W]*0.60)
W=12

[LikeValue]
FontSize=9

[UserIcon]
W=20

[UserName]
FontSize=10

[ViewTweet]
Y=3r
FontSize=9