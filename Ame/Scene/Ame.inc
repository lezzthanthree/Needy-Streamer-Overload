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
ActivityWindowOffset=40

; ===== Window =====

[Background]
Meter=IMAGE
ImageName=#@#Images\Shared\border\window-ame.png
W=(#Scale# * 358)
AntiAlias=0

[WindowTitles]
Meter=STRING
Text="Webcam"
FontFace=DinkieBitmap 7px
X=(#Scale# * 17)
Y=(#Scale# * 7)
FontSize=(#Scale# * 6)
FontColor=77,35,207
AntiAlias=0

[Close]
Meter=IMAGE
X=(#Scale# * 340)
Y=(#Scale# * 5)
W=(#Scale# * 10)
ImageName=#@#Images\Shared\button\button_close.png
LeftMouseUpAction=[!SetOption ImageNumberCalc Formula 0][!SetOption Ame Path "#@#Images\Ame\sprites\stream"][Play "#@#Audio\endHaishin.wav"][!Redraw][!RainmeterDeactivateConfig]
AntiAlias=0

[Settings]
Meter=IMAGE
X=(#Scale# * -13)r
Y=(#Scale# * 5)
W=(#Scale# * 10)
ImageName=#@#Images\Shared\button\button_gear.png
LeftMouseUpAction=[!ToggleConfig "Needy Streamer Overload\Ame\Settings" "Settings.ini"]
DynamicVariables=1
AntiAlias=0

[Activities]
Meter=IMAGE
X=(#Scale# * -11)r
Y=(#Scale# * 5)
W=(#Scale# * 10)
ImageName=#@#Images\Shared\button\button_heart.png
LeftMouseUpAction=[!ShowMeterGroup Activity][Play "#@#\Audio\open.wav"][!Redraw]
DynamicVariables=1
AntiAlias=0

; ===== Background ===== 

[BackgroundStream]
Meter=IMAGE
MeasureName=MeasureBackground
X=(#Scale# * 4)
Y=(#Scale# * 20)
DynamicVariables=1
Path=#@#Images\Ame\bg\
W=(#Scale# * 348)
AntiAlias=0

[ScreenSaverRandomizer]
Measure=Calc
Formula=Random
LowBound=0
HighBound=2

[ScreenSaver]
Meter=IMAGE
MeasureName=ScreenSaverRandomizer
X=(#Scale# * 4)
Y=(#Scale# * 20)
Path=#@#Images\Ame\bg_screensaver\
W=(#Scale# * 348)
DynamicVariables=1
AntiAlias=0

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
X=(#Scale# * 4)
Y=(#Scale# * 20)
Path=#SpritePath#
W=(#Scale# * 348)
AntiAlias=0

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

[ActivityWindow]
Meter=IMAGE
ImageName=#@#Images\Ame\menu\window.png
X=#ActivityWindowOffset#
Y=#ActivityWindowOffset#
W=(#Scale# * 254)
AntiAlias=0
Hidden=1
Group=Activity

[ActivityWindowTitle]
Meter=STRING
Text="Activities"
FontFace=DinkieBitmap 7px
X=((17 * #Scale#) + #ActivityWindowOffset#)
Y=((7 * #Scale#) + #ActivityWindowOffset#)
FontSize=(6 * #Scale#)
FontColor=77,35,207
Hidden=1
Group=Activity
AntiAlias=0

[ActivityClose]
Meter=IMAGE
X=((236 * #Scale#) + #ActivityWindowOffset#)
Y=((5 * #Scale#) + #ActivityWindowOffset#)
W=(#Scale# * 10)
ImageName=#@#Images\Shared\button\button_close.png
LeftMouseUpAction=[!HideMeterGroup Activity][Play "#@#\Audio\close.wav"][!ShowMeter Activities][!Redraw]
Hidden=1
Group=Activity
AntiAlias=0

[ActivitiesText]
Meter=STRING
Text="Activities"
FontFace=Zpix
FontColor=77,35,207
X=((65 * #Scale#) + #ActivityWindowOffset#)
Y=((41 * #Scale#) + #ActivityWindowOffset#)
FontSize=(#Scale# * 9)
Hidden=1
Group=Activity
AntiAlias=0

[Game]
Meter=Image
ImageName=#@#Images\Ame\menu\game.png
X=((62 * #Scale#) + #ActivityWindowOffset#)
Y=((65 * #Scale#) + #ActivityWindowOffset#)
W=(#Scale# * 32)
Hidden=1
LeftMouseUpAction=[Play "#@#Audio\execute.wav"][!HideMeterGroup Activity][!ShowMeter Activities][!HideMeter HeadpatHitbox][!SetVariable SpritePath "#@#Images\Ame\sprites\-1\[*Affection*]\[*Darkness*]\0"][!Redraw]
Group=Activity
AntiAlias=0

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

[Movie]
Meter=Image
ImageName=#@#Images\Ame\menu\movie.png
X=((110 * #Scale#) + #ActivityWindowOffset#)
Y=((65 * #Scale#) + #ActivityWindowOffset#)
W=(#Scale# * 32)
Hidden=1
LeftMouseUpAction=[Play "#@#Audio\execute.wav"][!HideMeterGroup Activity][!ShowMeter Activities][!HideMeter HeadpatHitbox][!SetVariable SpritePath "#@#Images\Ame\sprites\-1\[*Affection*]\[*Darkness*]\1"][!Redraw]
Group=Activity
AntiAlias=0

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
X=((157 * #Scale#) + #ActivityWindowOffset#)
Y=((65 * #Scale#) + #ActivityWindowOffset#)
W=(#Scale# * 32)
Greyscale=1
Hidden=1
Group=Activity
AntiAlias=0

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

[Idle]
Meter=Image
ImageName=#@#Images\Ame\menu\ame.png
X=((205 * #Scale#) + #ActivityWindowOffset#)
Y=((65 * #Scale#) + #ActivityWindowOffset#)
W=(#Scale# * 32)
Hidden=1
LeftMouseUpAction=[Play "#@#Audio\execute.wav"][!HideMeterGroup Activity][!ShowMeter Activities][!ShowMeter HeadpatHitbox][!SetVariable SpritePath "#@#Images\Ame\sprites\[*Stress*]\[*Affection*]\[*Darkness*]\[*Variation*]"][!Redraw]
Group=Activity
AntiAlias=0

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
