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

[Background]
Meter=IMAGE
ImageName=#@#Images\Shared\border\window-golive.png
W=(#Scale# * 370)
AntiAlias=0

[WindowTitles]
Meter=STRING
Text="Transform!"
FontFace=DinkieBitmap 7px
LeftMouseUpAction=[!SetOption Transformation Path "#@#\Images\Ame\transformation_dark"][!Redraw]
X=(#Scale# * 17)
Y=(#Scale# * 7)
FontSize=(#Scale# * 6)
FontColor=77,35,207

[Close]
Meter=IMAGE
X=(#Scale# * 360)
Y=(#Scale# * 5)
W=(#Scale# * 10)
ImageName=#@#Images\Shared\border\button_close.png
LeftMouseUpAction=[!SetOption ImageNumberCalc Formula 0][!SetOption Ame Path "#@#Images\Ame\sprites\"][!WriteKeyValue Variables @Include2 "Scene\Ame.inc"][Play "#@#Audio\endHaishin.wav"][!Redraw][!RainmeterDeactivateConfig]

; ===== Transition Animation =====

[ImageNumberCalc]
Measure=Calc
Formula=(#Zero# + 1)
DynamicVariables = 1

[Transformation]
Meter=Image
MeasureName=ImageNumberCalc
X=(#Scale# * 4)
Y=(#Scale# * 20)
LeftMouseUpAction=[!CommandMeasure ActionTimer "Stop 1"][Play "#@#\Audio\open.wav"][!WriteKeyValue Variables @Include2 "Scene\Stream.inc"][!Refresh]
Path=#@#\Images\Ame\transformation
W=(#Scale# * 360)
DynamicVariables=1
AntiAlias=1

[Animation]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Wait 500 | Play | Repeat Animate, 75, 190 | Close
Play=[Play "#@#\Audio\bank.wav"]
Animate=[!SetVariable Zero "[ImageNumberCalc]"][!UpdateMeasure ImageNumberCalc][!UpdateMeter Transformation][!UpdateMeter Frame][!Redraw]
Close=[!CommandMeasure ActionTimer "Stop 1"][!WriteKeyValue Variables @Include2 "Scene\Stream.inc"][!Refresh]