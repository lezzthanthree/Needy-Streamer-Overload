[Variables]
@Include=Players\Normal.inc

[MeasureParent]
Measure=Plugin
Plugin=Plugins\NowPlaying.dll

[MeasurePlayer]
Measure=NowPlaying
PlayerName=CAD

[MeasureWebPlayer]
Measure=Plugin
Plugin=WebNowPlaying

[ChosenPlayer]
Measure=Calc
Formula=2
ifEqualValue = 0
ifEqualAction = [!SetOption MeterTitle Text "Click the gear icon and select a player!"]
