[Rainmeter]
Update=-1
AccurateText=1
OnRefreshAction=[!CommandMeasure Animation "Execute 1"]

[Metadata]
Name=Needy Streamer Overload - Ame
Author=Smilie Pop (@lezzthanthree)
Information=Ame wants some headpats.
Version=4.0.0
License=Creative Commons Attribution - Non - Commercial - Share Alike 3.0

[Variables]
Zero=-1
@Include=#@#\Plugins\BorderHandler.inc

;==================================
;========= Window Handler =========
;==================================

; Modify these values to change window dimensions.
RightX=((#LeftX#) + (#Scale# * 360))
RightY=((#LeftY#) + (#Scale# * 270))
WindowName="Transform!"

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
LeftMouseUpAction=[!CommandMeasure ActionTimer "Stop 1"][Play "#@#\Audio\open.wav"][!WriteKeyValue Variables @Include2 "Scene\Stream.inc"][!Refresh]

; ===== Transition Animation =====

[ImageNumberCalc]
Measure=Calc
Formula=(#Zero# + 1)
DynamicVariables = 1

[Transformation]
Meter=Image
MeasureName=ImageNumberCalc
X=0
Y=0
LeftMouseUpAction=[!CommandMeasure ActionTimer "Stop 1"][Play "#@#\Audio\open.wav"][!WriteKeyValue Variables @Include2 "Scene\Stream.inc"][!Refresh]
Path=#@#\Images\Ame\transformation
W=(#Scale# * 360)
DynamicVariables=1
AntiAlias=1
Container=MeterContainer

[Animation]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Wait 500 | Play | Repeat Animate, 75, 190 | Close
Play=[Play "#@#\Audio\bank.wav"]
Animate=[!SetVariable Zero "[ImageNumberCalc]"][!UpdateMeasure ImageNumberCalc][!UpdateMeter Transformation][!UpdateMeter Frame][!Redraw]
Close=[!CommandMeasure ActionTimer "Stop 1"][!WriteKeyValue Variables @Include2 "Scene\Stream.inc"][!Refresh]