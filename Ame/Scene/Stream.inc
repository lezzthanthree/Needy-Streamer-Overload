[Variables]
@Include="#@#\Settings\Ame\Task Manager - Stream.inc"
@Include2=#@#\Plugins\BorderHandler.inc
SpritePath=#@#\Images\Ame\sprites\stream\[Stream]\[Section]

; ===== Window =====

;==================================
;========= Window Handler =========
;==================================

; Modify these values to change window dimensions.
RightX=((#LeftX#) + (#Scale# * 348))
RightY=((#LeftY#) + (#Scale# * 227))
WindowName="Stream"

RightAlign=(#RightX# - #LeftX#)
CenterAlign=((#RightX# - #LeftX#) / 2)
BottomAlign=(#RightY# - #LeftY#)
MiddleAlign=((#RightY# - #LeftY#) / 2)


;==================================
;========= Frame  Buttons =========
;==================================

[Close]
Meter=IMAGE
X=((#RightX#) - (#BorderScale# * 13))
Y=(#BorderScale# * 5)
W=(#BorderScale# * 10)
ImageName=#@#Images\Shared\button\button_close.png
LeftMouseUpAction=[!SetOption ImageNumberCalc Formula 0][!SetOption Ame Path "#@#Images\Ame\sprites\"][!WriteKeyValue Variables @Include2 "Scene\Ame.inc"][Play "#@#Audio\endHaishin.wav"][!Redraw][!RainmeterDeactivateConfig]

[Resize]
Meter=IMAGE
X=(#BorderScale# * -13)r
Y=r
W=(#BorderScale# * 10)
ImageName=#@#Images\Shared\button\button_size.png
LeftMouseUpAction=[!ToggleConfig "Needy Streamer Overload\Ame\Settings" "Scaling.ini"]
DynamicVariables=1

[Settings]
Meter=IMAGE
X=(#BorderScale# * -11)r
Y=r
W=(#BorderScale# * 10)
ImageName=#@#Images\Shared\button\button_gear.png
LeftMouseUpAction=[!ToggleConfig "Needy Streamer Overload\Ame\Settings" "Settings.ini"]
DynamicVariables=1
AntiAlias=0

[Activities]
Meter=IMAGE
X=(#BorderScale# * -11)r
Y=r
W=(#BorderScale# * 10)
ImageName=#@#Images\Shared\button\button_heart.png
LeftMouseUpAction=[!CommandMeasure EndStream "Execute 1"]
DynamicVariables=1

; ===== Background =====

[BackgroundStream]
Meter=IMAGE
MeasureName=MeasureBackground
X=0
Y=0
W=(#Scale# * 348)
DynamicVariables=1
Path=#@#Images\Ame\bg\
AntiAlias=1
Container=MeterContainer

[ScreenSaverRandomizer]
Measure=Calc
Formula=Random
LowBound=0
HighBound=2

[ScreenSaver]
Meter=IMAGE
MeasureName=ScreenSaverRandomizer
X=0
Y=0
W=(#Scale# * 348)
Path=#@#Images\Ame\bg_screensaver\
DynamicVariables=1
AntiAlias=1
Container=MeterContainer

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
X=0
Y=0
W=(#Scale# * 348)
Path=#StreamSpritePath#
AntiAlias=1
Container=MeterContainer

; ===== End Stream =====

[EndStream]
Measure=Plugin
Plugin=ActionTimer
ActionList1= Change | Wait 3000 | Switch
Change=[!SetOption ImageNumberCalc Formula 0][!SetOption KAngel Path "#@#Images\Ame\sprites\stream"][Play "#@#Audio\endHaishin.wav"][!Redraw]
Switch=[!WriteKeyValue Variables @Include2 "Scene\Ame.inc"][!Refresh]