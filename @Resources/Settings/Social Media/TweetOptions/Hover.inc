[Rainmeter]
OnUpdateAction=[!CommandMeasure HideTweeter "Execute 1"]

[Image]
MouseOverAction=[!CommandMeasure HideTweeter "Stop 1"][!ShowMeterGroup Tweeter][!Redraw]
MouseLeaveAction=[!CommandMeasure HideTweeter "Execute 1"][!Redraw]

[HideTweeter]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Wait 5000 | Hide
Hide=[!HideMeterGroup Tweeter][!Redraw]

[TweeterVisibilityOption]
Measure=Calc
Formula=1