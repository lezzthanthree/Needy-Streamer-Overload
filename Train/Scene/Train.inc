[Rainmeter]
MiddleMouseUpAction=[!Refresh]
OnRefreshAction=[!CommandMeasure MeasureActionTimer "Execute 1"][!CommandMeasure MeasureActionTimer "Execute 2"][!CommandMeasure MeasureActionTimer "Execute 3"]
AccurateText=1
Update=12

[Variables]
; Dynamic variables - do not change
marquee1=0
marquee2=0
trainframe=0
;trainspeed=20
TrainPath=#@#Images\Train\Train\[MeasureTimeOfDay]\
@Include=#@#\Settings\Train\TrainSettings.inc

; ===================

;==================================
;========= Window Handler =========
;==================================

LeftX=(#BorderScale# * 4)
LeftY=(#BorderScale# * 20)

; Modify these values to change window dimensions.
RightX=((#LeftX#) + (#Scale# * 252))
RightY=((#LeftY#) + (#Scale# * 159))
WindowName="Train"

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
LeftMouseUpAction=[Play "#@#\Audio\window_close.wav"][!DeactivateConfig]

[Resize]
Meter=IMAGE
X=(#BorderScale# * -13)r
Y=r
W=(#BorderScale# * 10)
ImageName=#@#Images\Shared\button\button_size.png
LeftMouseUpAction=[!ToggleConfig "Needy Streamer Overload\Train\Settings" "Scaling.ini"]
DynamicVariables=1
; =====

; Train animation - not good math but it's functional and doesn't error out after a few minutes
[ImageNumberCalc]
Measure=Calc
Formula=(((Counter % 30) / 15))
DynamicVariables=1
AntiAlias=0

; == associated with
;[ImageNumberCalc]
;Measure=Calc
;Formula=#trainframe#
;DynamicVariables=1
;AntiAlias=0

; Time of day

[MeasureHour]
Measure=Time
Format=%H

[MeasureTimeOfDay]
Measure=Calc
DynamicVariables=1

; Changes assets based on time of day. 
; 1 = day
; 2 = dusk
; 3 = night

Formula=[MeasureHour] > 18 ? 3 : ([MeasureHour] > 17 ? 2 : ([MeasureHour] > 5 ? 1 : 3))

;Marquee formulas borrowed from raiguard on the Rainmeter forums 
[MeasureActionTimer]
Measure=Plugin
Plugin=ActionTimer
; Cloud marquee
ActionList1=Repeat Move1,1000,262 | Reset1 | DoOver1
Reset1=[!SetVariable marquee1 0][!UpdateMeasure MeasureActionTimer][!Redraw]
Move1=[!SetVariable marquee1 "(#marquee1# + 1)"][!UpdateMeasure MeasureActionTimer][!Redraw]
DoOver1=[!CommandMeasure MeasureActionTimer "Execute 1"]
; Ground marquee
ActionList2=Repeat Move2,5,540 | Wait #marqueeEndWait# | Reset2 | Wait #marqueeBeginWait# | DoOver2
Reset2=[!SetVariable marquee2 0][!UpdateMeasure MeasureActionTimer][!Redraw]
Move2=[!SetVariable marquee2 "(#marquee2# + 1)"][!UpdateMeasure MeasureActionTimer][!Redraw]
DoOver2=[!CommandMeasure MeasureActionTimer "Execute 2"]
; == Train animation, this is supposed to be here for modularity but it
;ActionList3=Repeat Move3,5,1 | Wait 200 | Reset3 | Wait 200 | DoOver3
;Reset3=[!SetVariable trainframe 0][!UpdateMeasure MeasureActionTimer][!Redraw]
;Move3=[!SetVariable trainframe "(#trainframe# + 1)"][!UpdateMeasure MeasureActionTimer][!Redraw]
;DoOver3=[!CommandMeasure MeasureActionTimer "Execute 3"]

; Animation test
DynamicVariables=1




	[BG]
	Meter=Image
	MeasureName=MeasureTimeOfDay
	Path=#@#Images\Train\bg\
	X=0
	Y=0
	W=(#Scale# * 262)
	DynamicVariables=0
	Container=MeterContainer

	[City]
	Meter=Image
	MeasureName=MeasureTimeOfDay
	Path=#@#Images\Train\city\
	X=(#Scale# * (#marquee1# - 40))
	Y=(#Scale# * 114)
	W=(#Scale# * 98)
	DynamicVariables=0
	Container=MeterContainer
	[Mountain]
	Meter=Image
	MeasureName=MeasureTimeOfDay
	Path=#@#Images\Train\mountain\
	X=(#Scale# * (#marquee1# + 211))
	Y=(#Scale# * 124)
	W=(#Scale# * 41)
	DynamicVariables=0
	Container=MeterContainer

	[Clouds1]
	Meter=Image
	MeasureName=MeasureTimeOfDay
	Path=#@#Images\Train\clouds\
	X=(#Scale# * #marquee1#)
	Y=0
	W=(#Scale# * 262)
	DynamicVariables=1
	Container=MeterContainer
	[Clouds2]
	Meter=Image
	MeasureName=MeasureTimeOfDay
	Path=#@#Images\Train\clouds\
	X=(#Scale# * (#marquee1# - 262))
	Y=0
	W=(#Scale# * 262)
	DynamicVariables=1
	Container=MeterContainer

	[Ground1]
	Meter=Image
	MeasureName=MeasureTimeOfDay
	Path=#@#Images\Train\ground\
	X=(#Scale# * (#marquee2#))
	Y=(#Scale# * 137)
	W=(#Scale# * 270)
	DynamicVariables=1
	Container=MeterContainer
	[Ground2]
	Meter=Image
	MeasureName=MeasureTimeOfDay
	Path=#@#Images\Train\ground\
	X=((#Scale# * (#marquee2#)) - (#Scale# * 270))
	Y=r
	W=(#Scale# * 270)
	DynamicVariables=1
	Container=MeterContainer
	[Ground3]
	Meter=Image
	MeasureName=MeasureTimeOfDay
	Path=#@#Images\Train\ground\
	X=((#Scale# * #marquee2#) - (#Scale# * 540))
	Y=r
	W=(#Scale# * 270)
	DynamicVariables=1
	Container=MeterContainer
	[Ground4]
	Meter=Image
	MeasureName=MeasureTimeOfDay
	Path=#@#Images\Train\ground\
	X=((#Scale# * #marquee2#) - (#Scale# * 810))
	Y=r
	W=(#Scale# * 270)
	DynamicVariables=1
	Container=MeterContainer

		[Train]
		Meter=Image
		MeasureName=ImageNumberCalc
		DynamicVariables=1
		X=(#CenterAlign# - (#Scale# * 82))
		Y=(#Scale# * 103)
		W=(#Scale# * 165)
		Path=#TrainPath#
		Container=MeterContainer
		AntiAlias=0

;		[Train]
;		Meter=Image
;		MeasureName=ImageNumberCalc
;		DynamicVariables=1
;		X=42
;		Y=103
;		Path=#@#Images\Train\Train\
;		Container=MeterContainer
;		AntiAlias=0

	[Catenary Pole]
	Meter=Image
	MeasureName=MeasureTimeOfDay
	Path=#@#Images\Train\pole\
	X=((#Scale# * #marquee2#) - (#Scale# * 135))
	Y=(#Scale# * 72)
	W=(#Scale# * 15)
	DynamicVariables=1
	Container=MeterContainer
	[Fence]
	Meter=Image
	MeasureName=MeasureTimeOfDay
	Path=#@#Images\Train\fence\
	X=((#Scale# * #marquee2# - (#Scale# * 125)))
	Y=(#Scale# * 139)
	DynamicVariables=1
	Container=MeterContainer
	[Catenary Wire]
	Meter=Image
	MeasureName=MeasureTimeOfDay
	Path=#@#Images\Train\wire\
	X=0
	Y=(#Scale# * 103)
	W=(#RightAlign#)
	Container=MeterContainer


