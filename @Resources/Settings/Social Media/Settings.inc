[Variables]
SavedImage=87
NumberOfImages=89
@Include=TweetOptions\Hover.inc
@Include2=Slideshow\Disabled.inc
@Include3=Window\Large.inc

[NextImage]
Formula=(#SavedImage# + 1) % #NumberOfImages#

[NextImageOption]
Measure=Calc
Formula=1
