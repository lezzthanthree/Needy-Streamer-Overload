[Variables]
Zero1=-1
Zero2=-1

[DebugBG]
Meter=SHAPE
Shape=Rectangle 415,17,200,290 | Fill Color 155,155,155,255 | StrokeWidth 0
Group=Debug

[DebugTitle]
Meter=STRING
Text=Debugger
FontFace=DinkieBitmap 7px
X=420
Y=22
FontSize=12
FontColor=77,35,207
Group=Debug

[DebugMeter]
Meter=String
MeasureName=MeasureCPU
MeasureName2=MeasureMemoryPercentage
MeasureName3=MeasureDiskPercentage
MeasureName4=SystemInfoClock
MeasureName5=ImageNumberCalc
MeasureName6=Variation
MeasureName7=Stress
MeasureName8=Affection
MeasureName9=Darkness
MeasureName10=VariationChangeClock
MeasureName11=MeasureScreenTime
MeasureName12=ScreenHours
MeasureName13=MeasureBackground
MeasureName14=ScreenSaverRandomizer
MeasureName15=HeadpatCount

FontFace=zpix
FontSize=8
FontColor=77,33,203
AntiAlias=1
X=480
Y=42
StringAlign=Left
Text="Stress: %1 #CRLF#Affection: %2 #CRLF#Darkness: %3 #CRLF#UpdatesIn: %4/#SystemInfoUpdate# #CRLF#Frame: %5 #CRLF#Variation: %6 #CRLF#IdleFolder: %7/%8/%9/%6 #CRLF#CurrentFolder: (Hover) #CRLF#RandomizesIn: %10/#VarRand# #CRLF#ScreenTime: %11 #CRLF#Hours: %12 #CRLF#Background: %13 #CRLF#ScreenSaver: %14  #CRLF#Headpats: %15 #CRLF#"
ToolTipText=#SpritePath#
clipString = 1
Group=Debug
DynamicVariables=1

[SystemInfoClock]
Measure = Calc
Formula = ((#Zero1# + 1) % #SystemInfoUpdate#)
OnUpdateAction=[!SetVariable Zero1 "[SystemInfoClock]"]
DynamicVariables=1
Group=Debug

[VariationChangeClock]
Measure = Calc
Formula = ((#Zero2# + 1) % #VarRand#)
OnUpdateAction=[!SetVariable Zero2 "[VariationChangeClock]"]
DynamicVariables=1
Group=Debug

[Clock]
Measure = Calc
Formula = Counter % 1
ifCondition = Stress > 1
ifTrueAction = [!SetOption Stress Formula -1]
ifCondition2 = Affection > 2
ifTrueAction2 = [!SetOption Affection Formula 0]
ifCondition3 = Darkness > 2
ifTrueAction3 = [!SetOption Darkness Formula 0]
ifCondition4 = ScreenHours > 1200
ifTrueAction4 = [!SetOption ScreenHours Formula 0]
ifCondition5 = (Variation > 1) && (Stress <> -1)
ifTrueAction5 = [!SetOption Variation Formula 0]
ifCondition6 = (Variation > 1) && (Stress = -1)
ifTrueAction6 = [!SetOption Variation Formula 0]
ifCondition7 = ScreenSaverRandomizer > 2
ifTrueAction7 = [!SetOption ScreenSaverRandomizer Formula 0]
DynamicVariables=1
Group=Debug

[StressIncrease]
Meter=Image
ImageName=#@#Images\Task Manager\icon_status_stress.png
LeftMouseDownAction=[!SetOption Stress Formula [Stress]+1][!DisableMeasure MeasureCPU]
X=420
Y=42
ToolTipText=Increase Stress
Group=Debug

[AffectionIncrease]
Meter=Image
ImageName=#@#Images\Task Manager\icon_status_love.png
LeftMouseDownAction=[!SetOption Affection Formula [Affection]+1][!DisableMeasure MeasureMemoryPercentage]
X=420
Y=102
ToolTipText=Increase Affection
Group=Debug

[DarknessIncrease]
Meter=Image
ImageName=#@#Images\Task Manager\icon_status_yami.png
LeftMouseDownAction=[!SetOption Darkness Formula [Darkness]+1][!DisableMeasure MeasureDiskPercentage]
X=420
Y=162
ToolTipText=Increase Darkness
Group=Debug

[HourIncrease]
Meter=Image
ImageName=#@#Images\Task Manager\icon_status_follower.png
LeftMouseDownAction=[!SetOption ScreenHours Formula [ScreenHours]+50]
X=420
Y=222
ToolTipText=Increase ScreenTime Hours by 50
Group=Debug

[OpenSprite]
Meter=Image
ImageName=#@#Images\Desktop Icons\Icons\icon_picture.png
LeftMouseDownAction=["#SpritePath#"]
X=480
Y=200
Group=Debug
ToolTipText=Open the current sprite location.
DynamicVariables=1

[VariationChange]
Meter=Image
ImageName=#@#Images\Media Player\Next.png
LeftMouseDownAction=[!DisableMeasure VariationRandomizer][!DisableMeasure VariationChangeClock][!SetOption Variation Formula [Variation]+1]
X=430
Y=272
ToolTipText=Change the Variation of the Sprite.
Group=Debug

[HeadpatHitboxShow]
Meter=Image
ImageName=#@#Images\Desktop Icons\Icons\hearts.png
LeftMouseDownAction=[!SetOption HeadpatHitbox FillColor "FillColor 0,0,0,100"]
X=530
Y=200
ToolTipText=Show the Headpat Hitbox
Group=Debug

[Edit]
Meter=Image
ImageName=#@#Images\Desktop Icons\Icons\icon_gear.png
LeftMouseDownAction=[!EditSkin]
X=480
Y=240
ToolTipText=Edit the Ame.ini skin
Group=Debug

[RefreshSkin]
Meter=String
Text=Refresh
FontFace=zpix
FontSize=8
FontColor=77,33,203
fontWeight = 700   
LeftMouseDownAction=[!RainmeterRefresh]
X=480
Y=282
Group=Debug

[GroupHide]
Meter=String
Text=Hide
FontFace=zpix
FontSize=8
FontColor=77,33,203
fontWeight=700   
LeftMouseDownAction=[!HideMeterGroup Debug][!ShowMeter GroupShow]
X=550
Y=282
Group=Debug

[GroupShow]
Meter=String
Text=Show
FontFace=zpix
FontSize=8
FontColor=77,33,203
fontWeight=700   
LeftMouseDownAction=[!ShowMeterGroup Debug][!HideMeter GroupShow]
X=550
Y=282
Group=Debug
Hidden=1