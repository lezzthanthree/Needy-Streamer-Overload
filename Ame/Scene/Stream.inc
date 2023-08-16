[Rainmeter]
; Smaller Number, Faster Animation, CPU Usage increase.
; 1000 = saves CPU Usage, slowest animation [1FPS]
; 500 = saves CPU Usage, slow animation [2FPS]
; 250 = moderate CPU Usage, smooth animation [Default] [4FPS]
; 200 = high CPU Usage, smooth animation. [5FPS]
Update=250 
OnRefreshAction=[!CommandMeasure "Script" "NewStream()"][!CommandMeasure Animation "Execute 1"]

[Variables]
@Include="#@#\Settings\Ame\Task Manager - Stream.inc"

SpritePath=#@#Images\Ame\sprites\stream\[Stream]\[Section]

Frame = -1

NumberOfStreams = 58 ; ZERO-BASED INDEXING.

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
Formula=(#Frame# + 1)
DynamicVariables=1
AntiAlias=0

[Stream]
Measure=Calc
Formula=Random
LowBound=0
HighBound=#NumberOfStreams#
DynamicVariables=1
UpdateDivider=-1

[NumberOfSections]
Measure=Plugin
Plugin=FolderInfo
Folder=#@#\Images\Ame\sprites\stream\[Stream]\
InfoType=FolderCount
DynamicVariables=1

[Section]
Measure=Calc
Formula=0
DynamicVariables=1
ifConditionMode=1
ifCondition=Section >= NumberOfSections
ifTrueAction=[!UpdateMeasure Stream][!SetOption Section Formula 0][!Redraw][!CommandMeasure Animation "Execute 1"]
ifFalseAction=[!CommandMeasure Animation "Execute 1"]

[NumberOfFrames]
Measure=Plugin
Plugin=FolderInfo
Folder=#SpritePath#
InfoType=FileCount
DynamicVariables=1

[NumberOfFramesZero]
Measure=Calc
Formula=NumberOfFrames-1

[KAngel]
Meter=IMAGE
MeasureName=ImageNumberCalc
DynamicVariables=1
X=8
Y=42
Path=#SpritePath#
W=#Width#
AntiAlias=1

[Animation]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Wait 250 | Repeat Animate, 250, [NumberOfFramesZero] | Wait 7000 | NextSection
Animate=[!SetVariable Frame "[ImageNumberCalc]"][!UpdateMeasure ImageNumberCalc][!Redraw]
NextSection=[!SetVariable Frame -1][!SetOption Section Formula [Section]+1][!UpdateMeasure Section][!UpdateMeasure ImageNumberCalc][!Redraw]
DynamicVariables=1

; ===== End Stream =====

[EndStream]
Measure=Plugin
Plugin=ActionTimer
ActionList1= Change | Wait 2000 | Switch
Change=[!SetOption ImageNumberCalc Formula 0][!SetOption KAngel Path "#@#Images\Ame\sprites\stream"][Play "#@#Audio\endHaishin.wav"][!Redraw]
Switch=[!WriteKeyValue Variables @Include2 "Scene\Ame.inc"][!Refresh]