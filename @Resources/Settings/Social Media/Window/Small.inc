[Variables]
TweeterButtonsHeight=15

[Close]
X=282
Y=11

[Right]
X=258
Y=11

[Gear]
X=234
Y=11

[HeightImage]
IfCondition=(HeightImage >= 0) && (HeightImage < 342)
IfTrueAction=[!WriteKeyValue Variables Height 177][!SetOption Image H 177][!SetVariable Height 177][!UpdateMeter Background][!UpdateMeter Image][!Redraw]
IfCondition2=(HeightImage >= 342)
IfTrueAction2=[!WriteKeyValue Variables Height 342][!SetOption Image H 342][!SetVariable Height 342][!UpdateMeter Background][!UpdateMeter Image][!Redraw]

[Failsafe]
X=(298/2)-7
Y=(#Height#/2)+26

[Image]
W=298

[Tweet]
FontSize=7
W=([Image:W]-10)
Padding=5,5,5,5

[Retweet]
X=([Background:W]*0.22)
W=10

[RetweetValue]
FontSize=6

[Like]
X=([Background:W]*0.60)
W=8

[LikeValue]
FontSize=6

[UserIcon]
W=12.5

[UserName]
FontSize=7

[ViewTweet]
Y=0r
FontSize=6