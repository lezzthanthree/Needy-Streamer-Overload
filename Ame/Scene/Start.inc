[Rainmeter]
Update=-1

[Background]
Meter=IMAGE
ImageName=#@#Images\Shared\border\window-ame.png
AntiAlias=1

[WindowTitles]
Meter=STRING
Text="Notice"
FontFace=DinkieBitmap 7px
X=17
Y=7
FontSize=6
FontColor=77,35,207

[Close]
Meter=IMAGE
X=340
Y=5
ImageName=#@#Images\Shared\button\button_close.png
LeftMouseUpAction=[Play "#@#Audio\endHaishin.wav"][!Redraw][!RainmeterDeactivateConfig]

[DarkenBG]
Meter=SHAPE
Shape=Rectangle 4,20,348,227 | Extend FillColor | StrokeWidth 0
FillColor=FillColor 0,0,0,255

[WarningExplanation]
Meter=String
X=180
Y=35
Text=Due to its sprite animation, this skin may cause high CPU usage on low-end machines.#CRLF##CRLF#If you are worried about CPU usage, feel free to close the skin at any time.
clipString = 2
W=340
StringAlign=Center
FontFace=PixelMplus10
FontSize=14
FontColor=228,114,114
AntiAlias=0

[ButtonChromeOpera]
Meter=Image
ImageName=#@#Images\Shared\button\button_warning.png
X=73
Y=190
LeftMouseUpAction=[!WriteKeyValue Variables @Include2 Scene\Ame.inc][Play "#@#Audio\execute.wav"][!RefreshApp]

[StartAme]
Meter=String
X=100r
Y=10r
Text=Start
clipString = 2
W=360
StringAlign=Center
FontFace=PixelMplus10
FontSize=14
FontColor=77,35,207
AntiAlias=0