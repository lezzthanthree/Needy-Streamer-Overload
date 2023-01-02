[MeasureStatus]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Status

[MeasureTitle]
Measure=Plugin
Plugin=WebNowPlaying
UpdateDivider=5

[MeasureArtist]
Measure=Plugin
Plugin=WebNowPlaying
UpdateDivider=5

[MeasureState]
Measure=Plugin
Plugin=WebNowPlaying

[MeasureCover]
Measure=Plugin
Plugin=WebNowPlaying
DefaultPath=#@#Images\Media Player\nothing.png
CoverPath=#@#Images\Media Player\cover.png
UpdateDivider = 5

[MeasureAlbumArtAddress]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=CoverWebAddress
UpdateDivider=5

[MeasureProgress]
Measure=Plugin
Plugin=WebNowPlaying

[MeasurePosition]
Measure=Plugin
Plugin=WebNowPlaying
UpdateDivider=5

[MeasureDuration]
Measure=Plugin
Plugin=WebNowPlaying
UpdateDivider=5

[MeterCover]
PreserveAspectRatio=2

[ButtonPlay]
LeftMouseUpAction=[!CommandMeasure MeasureWebPlayer "PlayPause"]

[ButtonPause]
LeftMouseUpAction=[!CommandMeasure MeasureWebPlayer "PlayPause"]

[ButtonPrevious]
LeftMouseUpAction=[!CommandMeasure MeasureWebPlayer "Previous"]

[ButtonNext]
LeftMouseUpAction=[!CommandMeasure MeasureWebPlayer "Next"]