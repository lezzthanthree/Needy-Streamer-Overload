[Rainmeter]
OnRefreshAction=[!SetVariable marquee1 0][!SetVariable marquee2 0][!CommandMeasure MeasureActionTimer "Stop 1"][!CommandMeasure MeasureActionTimer "Stop 2"][!CommandMeasure MeasureActionTimer "Execute 1"][!CommandMeasure MeasureActionTimer "Execute 2"]

[Variables]
ProgressAlpha=1
Step=-1
; Marquee settings
animationSpeed=32
marqueeBeginWait=4000
marqueeEndWait=4000
; Dynamic variables - do not change
marquee1=0
marquee2=0

[MeasureTitle]
OnChangeAction=[!SetVariable marquee1 0][!CommandMeasure MeasureActionTimer "Stop 1"][!CommandMeasure MeasureActionTimer "Execute 1"]

[MeasureAction]
OnChangeAction=[!SetVariable marquee2 0][!CommandMeasure MeasureActionTimer "Stop 2"][!CommandMeasure MeasureActionTimer "Execute 2"]

[MeterTitle]
DynamicVariables=1
StringStyle=Normal
StringEffect=None

[MeterArtist]
DynamicVariables=1
StringStyle=Normal
StringEffect=None

[MeasureMarquee1Offset]
Measure=Calc
Formula=max(0,([MeterTitle:W] - [MeterContainer:W]))
DynamicVariables=1

[MeasureMarquee2Offset]
Measure=Calc
Formula=max(0,([MeterArtist:W] - [MeterContainer:W]))
DynamicVariables=1

[MeasureActionTimer]
Measure=Plugin
Plugin=ActionTimer

; Marquee 1
ActionList1=Wait #marqueeBeginWait# | Repeat Move1,#animationSpeed#,[MeasureMarquee1Offset:] | Wait #marqueeEndWait# | Repeat Reverse1,#animationSpeed#,[MeasureMarquee1Offset:] | DoOver1
Reverse1=[!SetVariable marquee1 "(#marquee1# + 1)"][!UpdateMeasure MeasureActionTimer][!UpdateMeter MeterTitle][!Redraw]
Move1=[!SetVariable marquee1 "(#marquee1# - 1)"][!UpdateMeasure MeasureActionTimer][!UpdateMeter MeterTitle][!Redraw]
DoOver1=[!CommandMeasure MeasureActionTimer "Execute 1"]
DynamicVariables=1

; Marquee 2
ActionList2= Wait #marqueeBeginWait# | Repeat Move2,#animationSpeed#,[MeasureMarquee2Offset:] | Wait #marqueeEndWait# | Repeat Reverse2,#animationSpeed#,[MeasureMarquee2Offset:] | DoOver2
Reverse2=[!SetVariable marquee2 "(#marquee2# + 1)"][!UpdateMeasure MeasureActionTimer][!UpdateMeter MeterArtist][!Redraw]
Move2=[!SetVariable marquee2 "(#marquee2# - 1)"][!UpdateMeasure MeasureActionTimer][!UpdateMeter MeterArtist][!Redraw]
DoOver2=[!CommandMeasure MeasureActionTimer "Execute 2"]
DynamicVariables=1

[ScrollingTextEnabled]
Measure=Calc
Formula=1