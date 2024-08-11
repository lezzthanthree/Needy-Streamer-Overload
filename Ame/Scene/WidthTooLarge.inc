[Rainmeter]
Update=-1

[Variables]
@Include=#@#\Window\SizeFG.inc
Width=387
Height=(253/387*#Width#)
TitleText="Notice"

[Close]
LeftMouseUpAction=[Play "#@#Audio\endHaishin.wav"][!Redraw][!RainmeterDeactivateConfig]

[Settings]
Meter=IMAGE
X=-24r
Y=11
ImageName=#@#Images\Ame\button_gear.png
LeftMouseUpAction=[!ToggleConfig "Needy Streamer Overload\Ame\Settings" "WidthSettingsSpecial.ini"]
DynamicVariables=1

[DarkenBG]
Meter=SHAPE
Shape=Rectangle 8,42,385,251 | Extend FillColor | StrokeWidth 0
FillColor=FillColor 0,0,0,255

[WarningExplanation]
Meter=String
X=200
Y=65
Text=This skin's width is more than a third of the screen. To prevent Rainmeter from crashing, a manual prompt is needed every time you reload this.#CRLF##CRLF#If you think your PC can handle it, you can disable this prompt.
clipString = 2
W=360
StringAlign=Center
FontFace=PixelMplus10
FontSize=14
FontColor=228,114,114
AntiAlias=0

[ButtonStartAme]
Meter=Image
ImageName=#@#Images\Ame\button_half.png
X=55
Y=230
LeftMouseUpAction=[!WriteKeyValue Variables @Include2 Scene\Ame.inc][Play "#@#Audio\execute.wav"][!RefreshApp]

[StartAme]
Meter=String
X=125
Y=239
Text=Start Ame
clipString = 2
W=360
StringAlign=Center
FontFace=PixelMplus10
FontSize=14
FontColor=77,35,207
AntiAlias=0

[ButtonDisablePrompt]
Meter=Image
ImageName=#@#Images\Ame\button_half.png
X=205
Y=230
LeftMouseUpAction=[!WriteKeyValue Variables @Include2 Scene\Ame.inc][!WriteKeyValue WidthCaution IfTrueAction "[Play #@#/Audio/jine_send_stamp.wav]"][Play "#@#Audio\execute.wav"][!RefreshApp]

[DisablePrompt]
Meter=String
X=275
Y=239
Text=Disable
clipString = 2
W=360
StringAlign=Center
FontFace=PixelMplus10
FontSize=14
FontColor=77,35,207
AntiAlias=0