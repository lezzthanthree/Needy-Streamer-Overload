[Rainmeter]
OnRefreshAction=[!KeepOnScreen 0][Play "#@#\Audio\Dialog.wav"]
Update=-1


[Variables]
@Include=#@#\Settings\Train\TrainSettings.inc

;==================================
;========= Window Handler =========
;==================================

LeftX=(#BorderScale# * 4)
LeftY=(#BorderScale# * 20)

; Modify these values to change window dimensions.
RightX=((#LeftX#) + (#Scale# * 360))
RightY=((#LeftY#) + (#Scale# * 200))
WindowName="Notice"

RightAlign=(#RightX# - #LeftX#)
CenterAlign=((#RightX# - #LeftX#) / 2)
BottomAlign=(#RightY# - #LeftY#)
MiddleAlign=((#RightY# - #LeftY#) / 2)

; The following values shouldn't need to be modified.
; Handle the drawing of the frame automatically around the content window:
[FrameTopLeft]
Meter=IMAGE
ImageName=#@#Images\Shared\border\windowtopleft.png
X=0
Y=0
W=(#BorderScale# * 20)
AntiAlias=0
[FrameTop]
Meter=IMAGE
ImageName=#@#Images\Shared\border\windowtop.png
X=((#LeftX#) + (#BorderScale# * 16))
Y=0
W=((#RightX#) - (#LeftX#) - (#BorderScale# * 30))
H=(#BorderScale# * 20)
AntiAlias=0
[FrameTopRight]
Meter=IMAGE
ImageName=#@#Images\Shared\border\windowtopright.png
X=((#RightX#) - (#BorderScale# * 14))
Y=0
W=(#BorderScale# * 20)
AntiAlias=0
[FrameLeft]
Meter=IMAGE
ImageName=#@#Images\Shared\border\windowleft.png
X=0
Y=(#LeftY#)
W=(#BorderScale# * 4)
H=((#RightY#) - (#LeftY#))
AntiAlias=0
[FrameRight]
Meter=IMAGE
ImageName=#@#Images\Shared\border\windowright.png
X=(#RightX#)
Y=(#LeftY#)
W=(#BorderScale# * 6)
H=((#RightY#) - (#LeftY#))
AntiAlias=0
[FrameBottomLeft]
Meter=IMAGE
ImageName=#@#Images\Shared\border\windowbottomleft.png
X=0
Y=(#RightY#)
W=(#BorderScale# * 35)
H=(#BorderScale# * 11)
AntiAlias=0
[FrameBottom]
Meter=IMAGE
ImageName=#@#Images\Shared\border\windowbottom.png
X=(#BorderScale# * 35)
Y=(#RightY#)
W=((#RightX#) - (#BorderScale# * 35))
H=(#BorderScale# * 11)
[FrameBottomRight]
Meter=IMAGE
ImageName=#@#Images\Shared\border\windowbottomright.png
X=(#RightX#)
Y=(#RightY#)
W=(#BorderScale# * 6)
H=(#BorderScale# * 11)
AntiAlias=0

[WindowTitles]
Meter=STRING
Text=#WindowName#
FontFace=DinkieBitmap 7px
X=(#BorderScale# * 17)
Y=(#BorderScale# * 7)
W=((#RightX#) - (#LeftX#) - (#BorderScale# * 26))
ClipString=1
FontSize=(#BorderScale# * 6)
FontColor=77,35,207
AntiAlias=0
DynamicVariables=1

[MeterContainer]
Meter=Image
SolidColor=255,255,255,255
X=(#LeftX#)
Y=(#LeftY#)
W=(#RightX# - #LeftX#)
H=(#RightY# - #LeftY#)


;==================================
;========= Frame  Buttons =========
;==================================


[Close]
Meter=IMAGE
X=((#RightX#) - (#BorderScale# * 13))
Y=(#BorderScale# * 5)
W=(#BorderScale# * 10)
ImageName=#@#Images\Shared\button\button_close.png
LeftMouseUpAction=[Play "#@#\Audio\window_close.wav"][!RainmeterDeactivateConfig]

[DarkenBG]
Meter=SHAPE
Shape=Rectangle 0,0,(#RightX#),(#RightY#) | Extend FillColor | StrokeWidth 0
FillColor=FillColor 0,0,0,255
Container=MeterContainer

[WarningExplanation]
Meter=String
X=(#CenterAlign#)
Y=(#Scale# * 15)
Text=Due to heavy use of animation, this window causes high CPU usage.#CRLF##CRLF#If you are worried about CPU usage, feel free to close it at any time.
clipString = 2
W=(#Scale# * 350)
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
LeftMouseUpAction=[!HideMeter OKDown][!WriteKeyValue Variables @Include2 Scene\Train.inc][Play "#@#\Audio\execute.wav"][!RefreshApp]
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
LeftMouseUpAction=[!HideMeter CancelDown][Play "#@#\Audio\window_close.wav"][!RainmeterDeactivateConfig]
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
