[Variables]
TweeterButtonsHeight=30

[Close]
X=580
Y=11

[Right]
X=556
Y=11

[Gear]
X=532
Y=11

[HeightImage]
IfCondition=(HeightImage >= 0) && (HeightImage < 684)
IfTrueAction=[!WriteKeyValue Variables Height 354][!SetOption Image H 354][!SetVariable Height 354][!UpdateMeter Background][!Redraw]
IfCondition2=(HeightImage >= 684)
IfTrueAction2=[!WriteKeyValue Variables Height 684][!SetOption Image H 684][!SetVariable Height 684][!UpdateMeter Background][!Redraw]


[Failsafe]
X=(596/2)-7
Y=(#Height#/2)+26

[Image]
W=596

[Tweet]
FontSize=14
W=([Image:W]-20)
Padding=10,10,10,10

[Retweet]
X=([Background:W]*0.22)

[RetweetValue]
FontSize=12

[Like]
X=([Background:W]*0.60)

[LikeValue]
FontSize=12

[UserIcon]
W=25

[UserName]
FontSize=14

[ViewTweet]
Y=4r
FontSize=12