[Rainmeter]
; Smaller Number, Faster Animation, CPU Usage increase.
; 1000 = saves CPU Usage, slowest animation [1FPS]
; 500 = saves CPU Usage, slow animation [2FPS]
; 250 = moderate CPU Usage, smooth animation [Default] [4FPS]
; 200 = high CPU Usage, smooth animation. [5FPS]
Update=250 

[Variables]
SpritePath=#@#\Images\Ame\sprites\[Stress]\[Affection]\[Darkness]\[Variation]

; Change Ame's Sprite to playing/watching when a program has detected.
@Include=#@#\Settings\Ame\Programs.inc
@Include2=#@#\Settings\Ame\Task Manager.inc

; ===== Window =====

[Background]
Meter=IMAGE
ImageName=#@#Images\Ame\#Width#
AntiAlias=1

[WindowTitles]
Meter=STRING
Text="Webcam"
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
LeftMouseUpAction=[!SetOption ImageNumberCalc Formula 0][!SetOption Ame Path "#@#Images\Ame\sprites\stream"][Play "#@#Audio\endHaishin.wav"][!Redraw][!RainmeterDeactivateConfig]

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
LeftMouseUpAction=[!ShowMeterGroup Activity][Play "#@#\Audio\open.wav"][!Redraw]
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
X=8
Y=42
Path=#SpritePath#
W=#Width#
AntiAlias=1

; ===== Headpat ===== 

[HeadpatHitbox]
Meter=SHAPE
Shape=Rectangle ((#Width#/2) - 30),80,80,50 | Extend FillColor | StrokeWidth 0
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
X=8
Y=42
W=#Width#
Hidden=1
DynamicVariables=1

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
X=50
Y=50
AntiAlias=1
Hidden=1
Group=Activity

[ActivityWindowTitle]
Meter=STRING
Text="Activities"
FontFace=DinkieBitmap 7px
X=84
Y=64
FontSize=12
FontColor=77,35,207
Hidden=1
Group=Activity

[ActivityClose]
Meter=IMAGE
X=522
Y=61
ImageName=#@#Images\button_close.png
LeftMouseUpAction=[!HideMeterGroup Activity][Play "#@#\Audio\close.wav"][!ShowMeter Activities][!Redraw]
Hidden=1
Group=Activity

[ActivitiesText]
Meter=STRING
Text="Activities"
FontFace=Zpix
FontColor=77,35,207
X=180
Y=132
FontSize=18
Hidden=1
Group=Activity

[Game]
Meter=Image
ImageName=#@#Images\Ame\menu\game.png
X=175
Y=180
Hidden=1
LeftMouseUpAction=[Play "#@#Audio\execute.wav"][!HideMeterGroup Activity][!ShowMeter Activities][!HideMeter HeadpatHitbox][!SetVariable SpritePath "#@#Images\Ame\sprites\-1\[*Affection*]\[*Darkness*]\0"][!Redraw]
Group=Activity

[GameLabel]
Meter=STRING
Text="Play Game"
FontFace=DinkieBitmap 7px
X=33r
Y=6R
FontSize=12
FontColor=77,35,207
StringAlign = Center
Hidden=1
Group=Activity

[Movie]
Meter=Image
ImageName=#@#Images\Ame\menu\movie.png
X=270
Y=180
Hidden=1
LeftMouseUpAction=[Play "#@#Audio\execute.wav"][!HideMeterGroup Activity][!ShowMeter Activities][!HideMeter HeadpatHitbox][!SetVariable SpritePath "#@#Images\Ame\sprites\-1\[*Affection*]\[*Darkness*]\1"][!Redraw]
Group=Activity

[MovieLabel]
Meter=STRING
Text="Streaming#CRLF#Service"
FontFace=DinkieBitmap 7px
X=33r
Y=6R
FontSize=12
FontColor=77,35,207
StringAlign = Center
Hidden=1
Group=Activity

; [CheckHour]
; Measure=Time
; Format=%H

; [CheckTime]
; Measure=Calc
; DynamicVariables=1
; Formula=[CheckHour]
; ifCondition = (CheckTime >= 19) || (CheckTime <= 5)
; ifTrueAction = [!SetOption Stream LeftMouseUpAction """[Play "#@#Audio\execute.wav"][!HideMeterGroup Activity][!WriteKeyValue Variables @Include2 "Scene\Transition.inc"][!Refresh]"""][!SetOption Stream Greyscale 0][!UpdateMeter Stream][!Redraw]
; ifFalseAction=[!SetOption Stream Greyscale 1][!SetOption Stream LeftMouseUpAction ""]

[Stream]
Meter=Image
ImageName=#@#Images\Ame\menu\youtube.png
X=365
Y=180
Greyscale=1
Hidden=1
Group=Activity

[StreamLabel]
Meter=STRING
Text="[Soon]"
FontFace=DinkieBitmap 7px
X=33r
Y=6R
FontSize=12
FontColor=77,35,207
StringAlign = Center
Hidden=1
Group=Activity

[Idle]
Meter=Image
ImageName=#@#Images\Ame\menu\ame.png
X=460
Y=180
Hidden=1
LeftMouseUpAction=[Play "#@#Audio\execute.wav"][!HideMeterGroup Activity][!ShowMeter Activities][!ShowMeter HeadpatHitbox][!SetVariable SpritePath "#@#Images\Ame\sprites\[*Stress*]\[*Affection*]\[*Darkness*]\[*Variation*]"][!Redraw]
Group=Activity

[IdleLabel]
Meter=STRING
Text="Idle"
FontFace=DinkieBitmap 7px
X=33r
Y=6R
FontSize=12
FontColor=77,35,207
StringAlign = Center
Hidden=1
Group=Activity
