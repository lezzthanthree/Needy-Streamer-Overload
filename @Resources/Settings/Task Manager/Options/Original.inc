[ScreenTimeLabel]
Text="Followers"

[ScreenTime]
Measure=Uptime
Format="%3!02i!"

[MeasureFollowers]
Measure=Calc
Formula=(ScreenTime/3600)*1000
IfCondition = MeasureFollowers < 85
IfTrueAction = [Play "#@#\Audio\boot.wav"] 

[MeterScreenTime]
MeasureName=MeasureFollowers

[ScreenTimeTooltipText]
Text=this shows you how many people are looking at my social media and streams. the more people watch, the more they fulfill my need for approval! our goal is to make this number as big as possible!
Y=130

; ===============

[CPULabel]
Text="Stress"

[CPUTooltipText]
Text=this shows you how much pressure im feeling. i might start acting weird if it gets too high, so watch out! i may even become more scared of the internet by day...
Y=51

; ===============

[MemoryLabel]
Text="Affection"

[MemoryTooltipText]
Text=this displays how much i love you! it'd be sad if i don't love you enough, but if i love you TOO much i might be hard to handle. so try to strike a good balance, ok? <3
Y=124

; ===============

[DiskLabel]
Text="Mental Darkness"

[DiskTooltipText]
Text=this lets you know how im doing mentally. how well i cope with reality will change depending on the numbers. it might have a bigger influence on my future rather than my present state in the game!
Y=197

[DescriptionVisibilityOption]
Measure=Calc
Formula=0