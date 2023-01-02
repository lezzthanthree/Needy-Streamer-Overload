[MeasurePlayer]
OnChangeAction=[!Refresh]

[MeasureTitle]
Measure=NowPlaying
PlayerName=[MeasurePlayer]

[MeasureArtist]
Measure=NowPlaying
PlayerName=[MeasurePlayer]

[MeasureState]
Measure=NowPlaying
PlayerName=[MeasurePlayer]

[MeasureCover]
Measure=NowPlaying
PlayerName=[MeasurePlayer]

[MeasureProgress]
Measure=NowPlaying
PlayerName=[MeasurePlayer]

[MeasurePosition]
Measure=NowPlaying
PlayerName=[MeasurePlayer]

[MeasureDuration]
Measure=NowPlaying
PlayerName=[MeasurePlayer]

[ButtonPlay]
LeftMouseUpAction=[!CommandMeasure MeasurePlayer "Play"]

[ButtonPause]
LeftMouseUpAction=[!CommandMeasure MeasurePlayer "Pause"]

[ButtonPrevious]
LeftMouseUpAction=[!CommandMeasure MeasurePlayer "Previous"]

[ButtonNext]
LeftMouseUpAction=[!CommandMeasure MeasurePlayer "Next"]