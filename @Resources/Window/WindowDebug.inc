[WindowDebugger]
Meter=String
MeasureName=Width
MeasureName2=Height
MeasureName3=ContentWidth
MeasureName4=ContentHeight
Text="SetSize:#Width# x #Height# #CRLF#WindowSize: %1 x %2#CRLF#ContentSize: %3 x %4"
X=(#Width#+20)
Y=15
FontFace=zpix
FontSize=8
FontColor=77,33,203

[Width]
Measure=Calc
Formula=[Background:W]
DynamicVariables=1

[Height]
Measure=Calc
Formula=[Background:H]
DynamicVariables=1

[ContentWidth]
Measure=Calc
Formula=[Foreground:W]
DynamicVariables=1

[ContentHeight]
Measure=Calc
Formula=[Foreground:H]
DynamicVariables=1