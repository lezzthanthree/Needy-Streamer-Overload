[Rainmeter]
AccurateText=1

[Variables]

;==================================
;========= Window Handler =========
;==================================

ErrorLeftX=(#BorderScale# * 4)
ErrorLeftY=(#BorderScale# * 20)

ErrorRightAlign=(#ErrorRightX# - #ErrorLeftX#)
ErrorCenterAlign=((#ErrorRightX# - #ErrorLeftX#) / 2)
ErrorBottomAlign=(#ErrorRightY# - #ErrorLeftY#)
ErrorMiddleAlign=((#ErrorRightY# - #ErrorLeftY#) / 2)

; The following values shouldn't need to be modified.
; Handle the drawing of the frame automatically around the content window:

[ErrorDarkenWindow]
Meter=SHAPE
Shape=Rectangle 0,0,(#RightX# + (#LeftX# * 2 / 3)),(#RightY# + (#BorderScale#) * 9) | Extend FillColor | StrokeWidth 0
FillColor=FillColor 0,0,0,64
Hidden=1
Group=Error


[ErrorFrameTopLeft]
Meter=IMAGE
ImageName=#@#Images\Shared\border\windowtopleft.png
X=#ErrorXOffset#
Y=#ErrorYOffset#
W=(#BorderScale# * 20)
AntiAlias=0
Hidden=1
Group=Error
[ErrorFrameTop]
Meter=IMAGE
ImageName=#@#Images\Shared\border\windowtop.png
X=((#ErrorLeftX#) + (#BorderScale# * 16) + #ErrorXOffset#)
Y=#ErrorYOffset#
W=((#ErrorRightX#) - (#ErrorLeftX#) - (#BorderScale# * 30))
H=(#BorderScale# * 20)
AntiAlias=0
Hidden=1
Group=Error
[ErrorFrameTopRight]
Meter=IMAGE
ImageName=#@#Images\Shared\border\windowtopright.png
X=((#ErrorRightX#) - (#BorderScale# * 14) + #ErrorXOffset#)
Y=#ErrorYOffset#
W=(#BorderScale# * 20)
AntiAlias=0
Hidden=1
Group=Error
[ErrorFrameLeft]
Meter=IMAGE
ImageName=#@#Images\Shared\border\windowleft.png
X=#ErrorXOffset#
Y=(#ErrorLeftY# + #ErrorYOffset#)
W=(#BorderScale# * 4)
H=((#ErrorRightY#) - (#ErrorLeftY#))
AntiAlias=0
Hidden=1
Group=Error
[ErrorFrameRight]
Meter=IMAGE
ImageName=#@#Images\Shared\border\windowright.png
X=(#ErrorRightX# + #ErrorXOffset#)
Y=(#ErrorLeftY# + #ErrorYOffset#)
W=(#BorderScale# * 6)
H=((#ErrorRightY#) - (#ErrorLeftY#))
AntiAlias=0
Hidden=1
Group=Error
[ErrorFrameBottomLeft]
Meter=IMAGE
ImageName=#@#Images\Shared\border\windowbottomleft.png
X=#ErrorXOffset#
Y=(#ErrorRightY# + #ErrorYOffset#)
W=(#BorderScale# * 36)
H=(#BorderScale# * 11)
AntiAlias=0
Hidden=1
Group=Error
[ErrorFrameBottom]
Meter=IMAGE
ImageName=#@#Images\Shared\border\windowbottom.png
X=((#BorderScale# * 36) + #ErrorXOffset#)
Y=(#ErrorRightY# + #ErrorYOffset#)
W=((#ErrorRightX#) - (#BorderScale# * 36))
H=(#BorderScale# * 11)
AntiAlias=0
Hidden=1
Group=Error
[ErrorFrameBottomRight]
Meter=IMAGE
ImageName=#@#Images\Shared\border\windowbottomright.png
X=(#ErrorRightX# + #ErrorXOffset#)
Y=(#ErrorRightY# + #ErrorYOffset#)
W=(#BorderScale# * 6)
H=(#BorderScale# * 11)
AntiAlias=0
Hidden=1
Group=Error

[ErrorWindowTitles]
Meter=STRING
Text=#ErrorWindowName#
FontFace=DinkieBitmap 7px
X=((#BorderScale# * 17) + #ErrorXOffset#)
Y=((#BorderScale# * 7) + #ErrorYOffset#)
W=((#ErrorRightX#) - (#ErrorLeftX#) - (#BorderScale# * 26))
ClipString=1
FontSize=(#BorderScale# * 6)
FontColor=77,35,207
Hidden=1
Group=Error
AntiAlias=0


[ErrorContainer]
Meter=Image
SolidColor=255,255,255
X=(#ErrorLeftX# + #ErrorXOffset#)
Y=(#ErrorLeftY# + #ErrorYOffset#)
W=(#ErrorRightAlign#)
H=(#ErrorBottomAlign#)
Group=Error
[ErrorBackground]
Meter=Shape
Shape=Rectangle 0,0,(#ErrorRightAlign#),(#ErrorBottomAlign#) | Fill Color 252,241,255 | StrokeWidth 0
Container=ErrorContainer
Hidden=1
Group=Error
[ErrorClose]
Meter=IMAGE
X=((#ErrorRightX#) - (#BorderScale# * 13) + #ErrorXOffset#)
Y=((#BorderScale# * 5) + #ErrorYOffset#)
W=(#BorderScale# * 10)
ImageName=#@#Images\Shared\button\button_close.png
Hidden=1
Group=Error
LeftMouseUpAction=[Play "#@#\Audio\close.wav"][!HideMeterGroup Error][!Refreshapp]
