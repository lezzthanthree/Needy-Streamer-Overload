[Rainmeter]
Update=-1

[Variables]
@Include=#@#\Window\SizeFG.inc
Height=(253/387*#Width#)
TitleText="Webcam"

[Close]
LeftMouseUpAction=[Play "#@#Audio\endHaishin.wav"][!Redraw][!RainmeterDeactivateConfig]

[DarkenBG]
Meter=SHAPE
Shape=Rectangle 8,42,385,251 | Extend FillColor | StrokeWidth 0
FillColor=FillColor 0,0,0,255

[WarningExplanation]
Meter=String
X=200
Y=65
Text=Due to its sprite animation, this skin may cause high CPU usage on low-end machines.#CRLF##CRLF#If you are worried about CPU Usage, feel free to close the skin at any time.
clipString = 2
W=360
StringAlign=Center
FontFace=PixelMplus10
FontSize=14
FontColor=228,114,114
AntiAlias=0

[ButtonChromeOpera]
Meter=Image
ImageName=#@#Images\Ame\button.png
X=103
Y=230
LeftMouseUpAction=[!WriteKeyValue Variables @Include2 Scene\Ame.inc][Play "#@#Audio\execute.wav"][!RefreshApp]

[StartAme]
Meter=String
X=202
Y=239
Text=Start Ame
clipString = 2
W=360
StringAlign=Center
FontFace=PixelMplus10
FontSize=14
FontColor=77,35,207
AntiAlias=0