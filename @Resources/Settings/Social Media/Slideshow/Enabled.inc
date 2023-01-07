[SlideshowStart]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Wait 60000 | New | DoOver
New=[!WriteKeyValue Variables SavedImage [NextImage] "#@#Settings\Social Media\Settings.inc"][!Refresh]
DoOver=[!CommandMeasure SlideshowStart "Execute 1"]

[SlideshowOption]
Measure=Calc
Formula=1
