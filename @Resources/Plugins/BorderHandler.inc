[Rainmeter]
AccurateText=1

[Variables]

;==================================
;========= Window Handler =========
;==================================

LeftX=(#BorderScale# * 4)
LeftY=(#BorderScale# * 20)

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

