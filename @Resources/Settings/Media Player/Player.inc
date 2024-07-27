[Variables]
@Include=Players\WebPlayer.inc

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
Formula=4
ifEqualValue = 0
ifEqualAction = [!SetOption MeterTitle Text "Click the gear icon and select a player!"]
