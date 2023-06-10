[Rainmeter]
; Smaller Number, Faster Animation, CPU Usage increase.
; 1000 = saves CPU Usage, slowest animation [1FPS]
; 500 = saves CPU Usage, slow animation [2FPS]
; 250 = moderate CPU Usage, smooth animation [Default] [4FPS]
; 200 = high CPU Usage, smooth animation. [5FPS]
; 100 = higher CPU Usage, game-accurate animation. [5FPS]
Update=100 

[Variables]
SpritePath=#@#\Images\Ame\sprites\[Stress]\[Affection]\[Darkness]\[Variation]

; Change Ame's Sprite to playing/watching when a program has detected.
@Include=#@#\Settings\Ame\Programs.inc
@Include2=#@#\Settings\Ame\Task Manager.inc
@Include3=#@#\Plugins\BorderHandler.inc
ActivityXOffset=(#Scale# * 40)
ActivityYOffset=(#Scale# * 40)
ActivityLeftX=(#LeftX# + #ActivityXOffset#)
ActivityLeftY=(#LeftY# + #ActivityYOffset#)
ActivityRightX=((#LeftX#) + (#Scale# * 244))
ActivityRightY=((#LeftY#) + (#Scale# * 115))
;==================================
;========= Window Handler =========
;==================================

; Modify these values to change window dimensions.
; NOTE: This version supports custom dimensions! Experiment!
RightX=((#LeftX#) + (#Scale# * 348))
RightY=((#LeftY#) + (#Scale# * 227))
WindowName="Webcam"

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
LeftMouseUpAction=[!SetOption ImageNumberCalc Formula 0][!SetOption Ame Path "#@#Images\Ame\sprites\stream"][Play "#@#Audio\endHaishin.wav"][!Redraw][!DeactivateConfig]
AntiAlias=0

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
LeftMouseUpAction=[!ShowMeterGroup Activity][!HideMeter HeadpatHitbox][Play "#@#\Audio\open.wav"][!Redraw]
DynamicVariables=1
AntiAlias=0

; ===== Background ===== 

[BackgroundStream]
Meter=IMAGE
MeasureName=MeasureBackground
X=0
Y=0
DynamicVariables=1
Path=#@#Images\Ame\bg\
W=(#Scale# * 348)
AntiAlias=0
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
Path=#@#Images\Ame\bg_screensaver\
W=(#Scale# * 348)
DynamicVariables=1
AntiAlias=0
Container=MeterContainer

; ===== Ame Animation ===== 

[ImageNumberCalc]
Measure=Calc
Formula=Counter % 20
DynamicVariables=1
AntiAlias=0

[VariationRandomizer]
Measure=Calc
Formula=Random
LowBound=0
HighBound=1
UpdateRandom=1
UpdateDivider=#VarRand#
DynamicVariables=1

[Variation]
Measure=Calc
Formula=[VariationRandomizer]
DynamicVariables=1

[Ame]
Meter=IMAGE
MeasureName=ImageNumberCalc
DynamicVariables=1
X=0
Y=0
Path=#SpritePath#
W=(#Scale# * 348)
AntiAlias=0
Container=MeterContainer

; ===== Headpat ===== 

[HeadpatHitbox]
Meter=SHAPE
Shape=Rectangle (((#Scale#*348)/2) - (#Scale# * 30)),(#Scale# * 50),(#Scale# * 80),(#Scale# * 50) | Extend FillColor | StrokeWidth 0
FillColor=FillColor 0,0,0,0
MouseOverAction=[!ShowMeter HeadpatDialogue][!SetOption HeadpatStatus Formula 0][!SetVariable SpritePath  "#@#Images\Ame\sprites\0\[*Affection*]\[*Darkness*]\1"][!Redraw]
MouseLeaveAction=[!HideMeter HeadpatDialogue][!SetOption HeadpatStatus Formula 0][!SetVariable SpritePath  "#@#Images\Ame\sprites\[*Stress*]\[*Affection*]\[*Darkness*]\[*Variation*]"][!Redraw]
LeftMouseDownAction=[!SetOption HeadpatStatus Formula 1][Play "#@#\Audio\nadenade_1.wav"][!SetOption HeadpatCount Formula [HeadpatCount]+1][!ShowMeter HeadpatDialogue][!Redraw]
MouseActionCursorName=HAND.cur

[HeadpatStatus]
Measure=Calc
Formula=0
LowBound-0
HighBound=4

[HeadpatDialogue]
Meter=Image
MeasureName=HeadpatStatus
Path=#@#Images\Ame\dialogue\
X=(#Scale# * 4)
Y=(#Scale# * 20)
W=(#Scale# * 348)
Hidden=1
DynamicVariables=1
AntiAlias=0

[HeadpatCount]
Measure=Calc
Formula=-1

[NadenadeSound]
Measure=Calc
Formula=HeadpatCount % 3
IfEqualValue = 0
IfEqualAction = [Play "#@#\Audio\nadenade_2.wav"][!SetOption HeadpatStatus Formula Random][!Redraw]

; ===== Activity ===== 



[ActivityFrameTopLeft]
Meter=IMAGE
ImageName=#@#Images\Shared\border\windowtopleft.png
X=#ActivityXOffset#
Y=#ActivityYOffset#
W=(#BorderScale# * 20)
AntiAlias=0
Hidden=1
Group=Activity
[ActivityFrameTop]
Meter=IMAGE
ImageName=#@#Images\Shared\border\windowtop.png
X=((#ActivityLeftX#) + (#BorderScale# * 16))
Y=#ActivityYOffset#
W=((#ActivityRightX#) - (#LeftX#) - (#BorderScale# * 30))
H=(#BorderScale# * 20)
AntiAlias=0
Hidden=1
Group=Activity
[ActivityFrameTopRight]
Meter=IMAGE
ImageName=#@#Images\Shared\border\windowtopright.png
X=((#ActivityRightX#) - (#BorderScale# * 14) + #ActivityXOffset#)
Y=#ActivityYOffset#
W=(#BorderScale# * 20)
AntiAlias=0
Hidden=1
Group=Activity
[ActivityFrameLeft]
Meter=IMAGE
ImageName=#@#Images\Shared\border\windowleft.png
X=#ActivityXOffset#
Y=(#ActivityLeftY#)
W=(#BorderScale# * 4)
H=((#ActivityRightY#) - (#LeftY#))
AntiAlias=0
Hidden=1
Group=Activity
[ActivityFrameRight]
Meter=IMAGE
ImageName=#@#Images\Shared\border\windowright.png
X=(#ActivityRightX# + #ActivityXOffset#)
Y=(#ActivityLeftY#)
W=(#BorderScale# * 6)
H=((#ActivityRightY#) - (#LeftY#))
AntiAlias=0
Hidden=1
Group=Activity
[ActivityFrameBottomLeft]
Meter=IMAGE
ImageName=#@#Images\Shared\border\windowbottomleft.png
X=#ActivityXOffset#
Y=(#ActivityRightY# + #ActivityYOffset#)
W=(#BorderScale# * 36)
H=(#BorderScale# * 11)
AntiAlias=0
Hidden=1
Group=Activity
[ActivityFrameBottom]
Meter=IMAGE
ImageName=#@#Images\Shared\border\windowbottom.png
X=((#BorderScale# * 36) + #ActivityXOffset#)
Y=(#ActivityRightY# + #ActivityYOffset#)
W=((#ActivityRightX#) - (#BorderScale# * 36))
H=(#BorderScale# * 11)
AntiAlias=0
Hidden=1
Group=Activity
[ActivityFrameBottomRight]
Meter=IMAGE
ImageName=#@#Images\Shared\border\windowbottomright.png
X=(#ActivityRightX# + #ActivityXOffset#)
Y=(#ActivityRightY# + #ActivityYOffset#)
W=(#BorderScale# * 6)
H=(#BorderScale# * 11)
AntiAlias=0
Hidden=1
Group=Activity

[ActivityContainer]
Meter=Image
SolidColor=255,255,255
X=(#LeftX# + #ActivityXOffset#)
Y=(#LeftY# + #ActivityYOffset#)
W=(#Scale# * 244)
H=(#Scale# * 115)

[ActivityWindowTitle]
Meter=STRING
Text="Activities"
FontFace=DinkieBitmap 7px
X=((17 * #BorderScale#) + #ActivityXOffset#)
Y=((7 * #BorderScale#) + #ActivityYOffset#)
FontSize=(6 * #BorderScale#)
FontColor=77,35,207
Hidden=1
Group=Activity
AntiAlias=0

[ActivityClose]
Meter=IMAGE
X=(((#ActivityRightX#) - (#BorderScale# * 13)) + #ActivityXOffset#)
Y=((5 * #BorderScale#) + #ActivityYOffset#)
W=(#BorderScale# * 10)
ImageName=#@#Images\Shared\button\button_close.png
LeftMouseUpAction=[!HideMeterGroup Activity][Play "#@#\Audio\close.wav"][!ShowMeter HeadpatHitbox][!Redraw]
Hidden=1
Group=Activity
AntiAlias=0

[ActivityBackground]
Meter=Shape
Shape=Rectangle 0,0,(#Scale# * 244),(#Scale# * 115) | Fill Color 252,241,255 | StrokeWidth 0
Hidden=1
Group=Activity
AntiAlias=0
Container=ActivityContainer

[LineRule]
Meter=SHAPE
Shape=Rectangle (53 * #Scale#),(35 * #Scale#),(#Scale# * 180),(#Scale# * 1) | Extend FillColor | StrokeWidth 0
FillColor=FillColor 222,223,220,255
Hidden=1
Group=Activity
AntiAlias=0
Container=ActivityContainer

[ActivityIcon]
Meter=Image
ImageName=#@#Images\Ame\menu\activityicon.png
X=(6 * #Scale#)
Y=(6 * #Scale#)
W=(#Scale# * 48)
Hidden=1
Group=Activity
AntiAlias=0
Container=ActivityContainer

[ActivitiesText]
Meter=STRING
Text="Activities"
FontFace=Zpix
FontColor=77,35,207
X=(61 * #Scale#)
Y=(21 * #Scale#)
FontSize=(#Scale# * 9)
Hidden=1
Group=Activity
AntiAlias=0
Container=ActivityContainer

[Game]
Meter=Image
ImageName=#@#Images\Ame\menu\game.png
X=(58 * #Scale#)
Y=(45 * #Scale#)
W=(#Scale# * 32)
Hidden=1
LeftMouseUpAction=[Play "#@#Audio\execute.wav"][!HideMeterGroup Activity][!ShowMeter HeadpatHitbox][!HideMeter HeadpatHitbox][!SetVariable SpritePath "#@#Images\Ame\sprites\-1\[*Affection*]\[*Darkness*]\0"][!Redraw]
Group=Activity
AntiAlias=0
Container=ActivityContainer

[GameLabel]
Meter=STRING
Text="Play Game"
FontFace=DinkieBitmap 7px
X=(16 * #Scale#)r
Y=(3 * #Scale#)R
FontSize=(6 * #Scale#)
FontColor=77,35,207
StringAlign = Center
Hidden=1
Group=Activity
AntiAlias=0
Container=ActivityContainer

[Movie]
Meter=Image
ImageName=#@#Images\Ame\menu\movie.png
X=(106 * #Scale#)
Y=(45 * #Scale#)
W=(#Scale# * 32)
Hidden=1
LeftMouseUpAction=[Play "#@#Audio\execute.wav"][!HideMeterGroup Activity][!ShowMeter HeadpatHitbox][!HideMeter HeadpatHitbox][!SetVariable SpritePath "#@#Images\Ame\sprites\-1\[*Affection*]\[*Darkness*]\1"][!Redraw]
Group=Activity
AntiAlias=0
Container=ActivityContainer

[MovieLabel]
Meter=STRING
Text="Streaming#CRLF#Service"
FontFace=DinkieBitmap 7px
X=(15 * #Scale#)r
Y=(3 * #Scale#)R
FontSize=(6 * #Scale#)
FontColor=77,35,207
StringAlign = Center
Hidden=1
Group=Activity
AntiAlias=0
Container=ActivityContainer

[CheckHour]
Measure=Time
Format=%H

[CheckTime]
Measure=Calc
DynamicVariables=1
Formula=[CheckHour]
ifCondition = (CheckTime >= 0) || (CheckTime <= 23)
ifTrueAction = [!SetOption Stream LeftMouseUpAction """[Play "#@#Audio\execute.wav"][!HideMeterGroup Activity][!WriteKeyValue Variables @Include2 "Scene\Transition.inc"][!Refresh]"""][!SetOption Stream Greyscale 0][!UpdateMeter Stream][!Redraw]
ifFalseAction=[!SetOption Stream Greyscale 1][!SetOption Stream LeftMouseUpAction ""]

[Stream]
Meter=Image
ImageName=#@#Images\Ame\menu\youtube.png
X=(153 * #Scale#)
Y=(45 * #Scale#)
W=(#Scale# * 32)
Greyscale=1
Hidden=1
Group=Activity
AntiAlias=0
Container=ActivityContainer

[StreamLabel]
Meter=STRING
Text="Stream"
FontFace=DinkieBitmap 7px
X=(16 * #Scale#)r
Y=(3 * #Scale#)R
FontSize=(6 * #Scale#)
FontColor=77,35,207
StringAlign = Center
Hidden=1
Group=Activity
AntiAlias=0
Container=ActivityContainer

[Idle]
Meter=Image
ImageName=#@#Images\Ame\menu\ame.png
X=(201 * #Scale#)
Y=(45 * #Scale#)
W=(#Scale# * 32)
Hidden=1
LeftMouseUpAction=[Play "#@#Audio\execute.wav"][!HideMeterGroup Activity][!ShowMeter HeadpatHitbox][!SetVariable SpritePath "#@#Images\Ame\sprites\[*Stress*]\[*Affection*]\[*Darkness*]\[*Variation*]"][!Redraw]
Group=Activity
AntiAlias=0
Container=ActivityContainer

[IdleLabel]
Meter=STRING
Text="Idle"
FontFace=DinkieBitmap 7px
X=(17 * #Scale#)r
Y=(3 * #Scale#)R
FontSize=(6 * #Scale#)
FontColor=77,35,207
StringAlign = Center
Hidden=1
Group=Activity
AntiAlias=0
Container=ActivityContainer
