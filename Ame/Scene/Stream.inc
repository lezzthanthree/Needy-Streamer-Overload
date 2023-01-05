[Variables]
@Include="#@#\Settings\Ame\Task Manager - Stream.inc"

SpritePath=#@#\Images\Ame\sprites\stream\[Stream]\[Section]

; ===== Window =====

[Background]
Meter=IMAGE
ImageName=#@#Images\Ame\#Width#.png
AntiAlias=1

[WindowTitles]
Meter=STRING
Text="Stream"
FontFace=DinkieBitmap 7px
X=34
Y=14
FontSize=12
FontColor=77,35,207

[Close]
Meter=IMAGE
X=(#Width# - 16)
Y=11
ImageName=#@#Images\button_close.png
LeftMouseUpAction=[!SetOption ImageNumberCalc Formula 0][!SetOption Ame Path "#@#Images\Ame\sprites\"][!WriteKeyValue Variables @Include2 "Scene\Ame.inc"][Play "#@#Audio\endHaishin.wav"][!Redraw][!RainmeterDeactivateConfig]

[Settings]
Meter=IMAGE
X=-24r
Y=11
ImageName=#@#Images\Ame\button_gear.png
LeftMouseUpAction=[!ToggleConfig "Needy Streamer Overload\Ame\Settings" "Settings.ini"]
DynamicVariables=1

[Activities]
Meter=IMAGE
X=-24r
Y=11
ImageName=#@#Images\Ame\button_heart.png
LeftMouseUpAction=[!CommandMeasure EndStream "Execute 1"]
DynamicVariables=1

; ===== Background =====

[BackgroundStream]
Meter=IMAGE
MeasureName=MeasureBackground
X=8
Y=42
DynamicVariables=1
Path=#@#Images\Ame\bg\
W=#Width#
AntiAlias=1

[ScreenSaverRandomizer]
Measure=Calc
Formula=Random
LowBound=0
HighBound=2

[ScreenSaver]
Meter=IMAGE
MeasureName=ScreenSaverRandomizer
X=8
Y=42
Path=#@#Images\Ame\bg_screensaver\
W=#Width#
DynamicVariables=1
AntiAlias=1

; ===== KAngel Animation ===== 

[ImageNumberCalc]
Measure=Calc
Formula=
DynamicVariables=1
AntiAlias=0

[StreamRandomizer]
Measure=Calc
Formula=Random
LowBound=0
HighBound=1
UpdateRandom=1
UpdateDivider=#VarRand#
DynamicVariables=1

[Stream]
Measure=Calc
Formula=[StreamRandomizer]
DynamicVariables=1

[NumberOfSections]
Measure=Calc
Formula=1
DynamicVariables=1

[Section]
Measure=Calc
Formula=##
DynamicVariables=1

[KAngel]
Meter=IMAGE
MeasureName=ImageNumberCalc
DynamicVariables=1
X=8
Y=42
Path=#StreamSpritePath#
W=#Width#
AntiAlias=1

; ===== End Stream =====

[EndStream]
Measure=Plugin
Plugin=ActionTimer
ActionList1= Change | Wait 2000 | Switch
Change=[!SetOption ImageNumberCalc Formula 0][!SetOption KAngel Path "#@#Images\Ame\sprites\stream"][Play "#@#Audio\endHaishin.wav"][!Redraw]
Switch=[!WriteKeyValue Variables @Include2 "Scene\Ame.inc"][!Refresh]