[Rainmeter]
Update=-1

[Variables]
@Include=#@#\Settings\Ame\Settings.inc

[Background]
Meter=IMAGE
ImageName=#@#Images\Shared\border\window-ame.png
AntiAlias=0

[WindowTitles]
Meter=STRING
Text="Notice"
FontFace=DinkieBitmap 7px
X=(#Scale# * 17)
Y=(#Scale# * 7)
FontSize=(#Scale# * 6)
FontColor=77,35,207

[Close]
Meter=IMAGE
X=(#Scale# * 340)
Y=(#Scale# * 5)
W=(#Scale# * 10)
ImageName=#@#Images\Shared\button\button_close.png
LeftMouseUpAction=[Play "#@#Audio\endHaishin.wav"][!Redraw][!RainmeterDeactivateConfig]

[DarkenBG]
Meter=SHAPE
Shape=Rectangle (#Scale# * 4),(#Scale# * 20),(#Scale# * 348),(#Scale# * 227) | Extend FillColor | StrokeWidth 0
FillColor=FillColor 0,0,0,255

[WarningExplanation]
Meter=String
X=(#Scale# * 180)
Y=(#Scale# * 35)
Text=Due to its sprite animation, this skin may cause high CPU usage on low-end machines.#CRLF##CRLF#If you are worried about CPU usage, feel free to close the skin at any time.
clipString = 2
W=(#Scale# * 340)
StringAlign=Center
FontFace=PixelMplus10
FontSize=(#Scale# * 14)
FontColor=228,114,114
AntiAlias=0

[ButtonChromeOpera]
Meter=Image
ImageName=#@#Images\Shared\button\button_up.png
X=(#Scale# * 73)
Y=(#Scale# * 190)
W=(#Scale# * 200)
LeftMouseUpAction=[!WriteKeyValue Variables @Include2 Scene\Ame.inc][Play "#@#Audio\execute.wav"][!RefreshApp]
AntiAlias=0

[StartAme]
Meter=String
X=(#Scale# * 100)r
Y=(#Scale# * 10)r
Text=Start
clipString = 2
W=(#Scale# * 360)
StringAlign=Center
FontFace=PixelMplus10
FontSize=(#Scale# * 14)
FontColor=77,35,207
AntiAlias=0