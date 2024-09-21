[Rainmeter]
Update=-1

[Variables]
@Include=#@#\Window\SizeFG.inc
Width=387
Height=(253/387*#Width#)
TitleText="Notice"

[Close]
LeftMouseUpAction=[Play "#@#Audio\endHaishin.wav"][!Redraw][!RainmeterDeactivateConfig]

[DarkenBG]
Meter=SHAPE
Shape=Rectangle 8,42,385,251 | Extend FillColor | StrokeWidth 0
FillColor=FillColor 0,0,0,255

[WarningExplanation]
Meter=String
X=200
Y=100
Text=Trigger Warning #CRLF##CRLF#Do you wish to continue?
clipString = 2
W=360
StringAlign=Center
FontFace=PixelMplus10
FontSize=14
FontColor=228,114,114
AntiAlias=0

[ButtonYes]
Meter=Image
ImageName=#@#Images\Ame\button_half.png
X=55
Y=200
LeftMouseUpAction=[!WriteKeyValue Variables @Include2 Scene\DarkStream.inc][Play "#@#Audio\execute.wav"][!RefreshApp]

[Yes]
Meter=String
X=125
Y=209
Text=Yes
clipString = 2
W=360
StringAlign=Center
FontFace=PixelMplus10
FontSize=14
FontColor=77,35,207
AntiAlias=0

[ButtonNo]
Meter=Image
ImageName=#@#Images\Ame\button_half.png
X=205
Y=200
LeftMouseUpAction=[!WriteKeyValue Variables @Include2 Scene\Stream.inc][Play "#@#Audio\execute.wav"][!RefreshApp]

[No]
Meter=String
X=275
Y=209
Text=No
clipString = 2
W=360
StringAlign=Center
FontFace=PixelMplus10
FontSize=14
FontColor=77,35,207
AntiAlias=0