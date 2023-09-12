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
MeasureName=MeasureBackground
MeasureName2=ScreenHours
MeasureName3=ScreenSaverRandomizer
MeasureName4=Stream
MeasureName5=NumberOfSectionsZero
MeasureName6=Section
MeasureName7=NumberOfFramesZero
MeasureName8=ImageNumberCalc
FontFace=zpix
FontSize=8
FontColor=77,33,203
AntiAlias=1
X=480
Y=37
StringAlign=Left
Text="Background: %1 #CRLF#Hours: %2 #CRLF#ScreenSaver: %3 #CRLF#Stream: %4 #CRLF#NumOfSections: %5 #CRLF#Section: %6 #CRLF#NumOfFrames: %7 #CRLF#Frame: %8"
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
ifCondition = (Stream > 58) && (Stream <> 99999)
ifTrueAction = [!SetOption Stream Formula 0][!UpdateMeasure Stream][!SetOption Section Formula 0][!SetVariable Frame -1][!Redraw][!CommandMeasure Animation "Execute 1"]
DynamicVariables=1
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
LeftMouseDownAction=[!CommandMeasure Animation "Stop 1"][!SetOption Stream Formula [Stream]+1][!UpdateMeasure Stream][!SetOption Section Formula 0][!SetVariable Frame -1][!Redraw][!CommandMeasure Animation "Execute 1"]
X=430
Y=282
ToolTipText=Change the Variation of the Sprite.
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

[SwitchDebug]
Meter=String
Text=Switch
FontFace=zpix
FontSize=8
FontColor=77,33,203
fontWeight=700   
LeftMouseDownAction=[!WriteKeyValue Variables @Include3 "Debug.inc"][!WriteKeyValue Variables @Include2 "Scene\Ame.inc"][!Refresh]
X=550
Y=302
Group=Debug