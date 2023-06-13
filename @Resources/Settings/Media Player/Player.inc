[Variables]
@Include=Players\Normal.inc
Scale=2
BorderScale=2
SelectedScaleOption=3
SelectedBorderScaleOption=3

[MeasureParent]
Measure=Plugin
Plugin=Plugins\NowPlaying.dll

[MeasurePlayer]
Measure=NowPlaying
PlayerName=

[MeasureWebPlayer]
Measure=Plugin
Plugin=WebNowPlaying

[ChosenPlayer]
Measure=Calc
Formula=0
ifEqualValue = 0
ifEqualAction = [!SetOption MeterTitle Text "Click the gear icon! ^"]
