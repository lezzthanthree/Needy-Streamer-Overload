[Variables]
Zero1=-1
Zero2=-1

[DebugBG]
Meter=SHAPE
Shape=Rectangle 415,17,200,300 | Fill Color 155,155,155,255 | StrokeWidth 0
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
MeasureName16=PlayingGame
MeasureName17=MeasureState
MeasureName18=Stressed

FontFace=zpix
FontSize=8
FontColor=77,33,203
AntiAlias=1
X=480
Y=37
StringAlign=Left
Text="SysVitals: %1 %2 %3 #CRLF#UpdatesIn: %4/#SystemInfoUpdate# #CRLF#Frame: %5 #CRLF#Variation: %6 #CRLF#IdleFolder: %7/%8/%9/%6 #CRLF#CurrentFolder: (Hover) #CRLF#RandomizesIn: %10/#VarRand# #CRLF#ScreenTime: %11 #CRLF#Hours: %12 #CRLF#Background: %13 #CRLF#ScreenSaver: %14  #CRLF#Headpats: %15 #CRLF#PlayingGame: %16 #CRLF#MusicState: %17 #CRLF#Stressed: %18"
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
ifCondition2 = (Affection > 2) && (Stress = 0)
ifTrueAction2 = [!SetOption Affection Formula 0]
ifCondition3 = (Affection > 2) && (Stress = 1)
ifTrueAction3 = [!SetOption Affection Formula -1][!SetOption Darkness Formula -1]
ifCondition4 = Darkness > 2 && (Stress = 0)
ifTrueAction4 = [!SetOption Darkness Formula 0]
ifCondition5 = Darkness > 2 && (Stress = 1)
ifTrueAction5 = [!SetOption Affection Formula -1][!SetOption Darkness Formula -1]
ifCondition6 = ScreenHours > 1200
ifTrueAction6 = [!SetOption ScreenHours Formula 0]
ifCondition7 = (Variation > 1) && (Stress <> -1)
ifTrueAction7 = [!SetOption Variation Formula 0]
ifCondition8 = (Variation > 1) && (Stress = -1)
ifTrueAction8 = [!SetOption Variation Formula 0]
ifCondition9 = ScreenSaverRandomizer > 2
ifTrueAction9 = [!SetOption ScreenSaverRandomizer Formula 0]
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
Y=210
Group=Debug
ToolTipText=Open the current sprite location.
DynamicVariables=1

[VariationChange]
Meter=Image
ImageName=#@#Images\Media Player\Next.png
LeftMouseDownAction=[!DisableMeasure VariationRandomizer][!DisableMeasure VariationChangeClock][!SetOption Variation Formula [Variation]+1]
X=430
Y=282
ToolTipText=Change the Variation of the Sprite.
Group=Debug

[HeadpatHitboxShow]
Meter=Image
ImageName=#@#Images\Desktop Icons\Icons\hearts.png
LeftMouseDownAction=[!SetOption HeadpatHitbox FillColor "FillColor 0,0,0,100"]
X=530
Y=210
ToolTipText=Show the Headpat Hitbox
Group=Debug

[Edit]
Meter=Image
ImageName=#@#Images\Desktop Icons\Icons\icon_gear.png
LeftMouseDownAction=[!EditSkin]
X=480
Y=250
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
Y=292
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
Y=292
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
Y=292
Group=Debug
Hidden=1