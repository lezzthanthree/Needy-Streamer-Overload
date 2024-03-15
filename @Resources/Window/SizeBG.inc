[Variables]
@Include=WindowColors.inc

[WindowShadow]
Meter=Shape
Shape=Rectangle 0,0,#Width#,#Height# | Fill Color #WindowShadowColor# | StrokeWidth 0
X=5
Y=5

[Background]
Meter=Shape
Shape=Rectangle 1,1,#Width#,#Height# | Fill Color #BackgroundColor# | Stroke Color #StrokeColor# | StrokeWidth 2

; = Title Bar =
[TitleBar]
Meter=Shape
Shape=Rectangle 0,0,(#Width#-12),28 | Fill Color #TitleBarColor# | Stroke Color #StrokeColor# | StrokeWidth 2
X=7
Y=7

[TitleIcon]
Meter=Shape
Shape=Rectangle 0,0,16,16 | Fill Color 77, 35, 207 | StrokeWidth 0
X=13
Y=13

[Title]
Meter=STRING
Text=#TitleText#
FontFace=DinkieBitmap 7px
X=34
Y=14
FontSize=12
FontColor=#FontColor#

[Close]
Meter=IMAGE
X=(#Width#-30)
Y=11
ImageName=#@#Images\button_close.png
LeftMouseUpAction=[Play "#@#\Audio\window_close.wav"][!RainmeterDeactivateConfig]

; = Foreground =
[Foreground]
Meter=Shape
Shape=Rectangle 0,0,(#Width#-12),(#Height#-57) | Fill Color #ForegroundColor# | Stroke Color #StrokeColor# | StrokeWidth 2
X=7
Y=41

; = Buttom Shapes =
[BottomShapeColored]
Meter=Shape
Shape=Rectangle 0,0,34,9 | Fill Color #BottomShapeColor# | Stroke Color #StrokeColor# | StrokeWidth 2
X=7
Y=(#Height#-8)

[BottomShape1]
Meter=Shape
Shape=Rectangle 0,0,5,5 | Fill Color #BackgroundColor# | Stroke Color #StrokeColor# | StrokeWidth 2
X=3R
Y=0r

[BottomShape2]
Meter=Shape
Shape=Rectangle 0,0,5,5 | Fill Color #BackgroundColor# | Stroke Color #StrokeColor# | StrokeWidth 2
X=2R
Y=0r

[BottomShape3]
Meter=Shape
Shape=Rectangle 0,0,5,5 | Fill Color #BackgroundColor# | Stroke Color #StrokeColor# | StrokeWidth 2
X=2R
Y=0r