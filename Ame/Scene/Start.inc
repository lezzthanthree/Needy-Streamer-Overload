[Rainmeter]
Update=-1

[Variables]
@Include=#@#\Settings\Ame\AmeSettings.inc
@Include2=#@#\Plugins\BorderHandler.inc

;==================================
;========= Window Handler =========
;==================================

; Modify these values to change window dimensions.
; NOTE: This version supports custom dimensions! Experiment!
RightX=((#LeftX#) + (#Scale# * 360))
RightY=((#LeftY#) + (#Scale# * 200))
WindowName="JINE"

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
LeftMouseUpAction=[Play "#@#Audio\endHaishin.wav"][!Redraw][!RainmeterDeactivateConfig]

[DarkenBG]
Meter=SHAPE
Shape=Rectangle 0,0,(#RightX#),(#RightY#) | Extend FillColor | StrokeWidth 0
FillColor=FillColor 0,0,0,255
Container=MeterContainer

[WarningExplanation]
Meter=String
X=(#CenterAlign#)
Y=(#Scale# * 20)
Text=Due to its sprite animation, this skin may cause high CPU usage on low-end machines.#CRLF##CRLF#If you are worried about CPU usage, feel free to close the window.
clipString = 2
W=(#Scale# * 340)
StringAlign=Center
FontFace=PixelMplus10
FontSize=(#Scale# * 14)
FontColor=228,114,114
AntiAlias=0
Container=MeterContainer


[OK]
Meter=IMAGE
X=((#CenterAlign#) + (#Scale# * 8))
Y=((#BottomAlign#) - (#Scale# * 38))
W=(#Scale# * 100)
ImageName=#@#Images\Shared\button\button_up.png
LeftMouseDownAction=[!ShowMeter OKDown][!Redraw]
LeftMouseUpAction=[!HideMeter OKDown][!WriteKeyValue Variables @Include2 Scene\Ame.inc][Play "#@#\Audio\execute.wav"][!RefreshApp]
DynamicVariables=1
Container=MeterContainer

[OKDown]
Meter=IMAGE
X=r
Y=r
W=(#Scale# * 100)
ImageName=#@#Images\Shared\button\button_down.png
MouseLeaveAction=[!HideMeter OKDown][!Redraw]
Hidden=1
Container=MeterContainer
[OKText]
Meter=IMAGE
X=(#Scale# * 45)r
Y=(#Scale# * 7)r
W=(#Scale# * 9)
ImageName=#@#Images\Shared\button\text_OK.png
DynamicVariables=1
Container=MeterContainer


[Cancel]
Meter=IMAGE
X=((#CenterAlign#) - (#Scale# * 108))
Y=((#BottomAlign#) - (#Scale# * 38))
W=(#Scale# * 100)
ImageName=#@#Images\Shared\button\button_up.png
LeftMouseDownAction=[!ShowMeter CancelDown][!Redraw]
LeftMouseUpAction=[!HideMeter CancelDown][Play "#@#\Audio\window_close.wav"][!DeactivateConfig]
DynamicVariables=1
Container=MeterContainer

[CancelDown]
Meter=IMAGE
X=r
Y=r
W=(#Scale# * 100)
ImageName=#@#Images\Shared\button\button_down.png
MouseLeaveAction=[!HideMeter CancelDown][!Redraw]
Hidden=1
Container=MeterContainer

[CancelText]
Meter=IMAGE
X=(#Scale# * 35)r
Y=(#Scale# * 7)r
W=(#Scale# * 29)
ImageName=#@#Images\Shared\button\text_cancel.png
DynamicVariables=1
Container=MeterContainer