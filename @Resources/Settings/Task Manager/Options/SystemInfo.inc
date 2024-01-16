[ScreenTimeLabel]
Text="Screen Time"

[MeasureScreenTime]
Measure=Uptime
AddDaysToHours=1
Format="%3!02i!:%2!02i!"
IfCondition = MeasureScreenTime < 300
IfTrueAction = [Play "#@#\Audio\boot.wav"]

[MeterScreenTime]
MeasureName=MeasureScreenTime

[ScreenTimeTooltipText]
Text=screen time measures the time since your last restart of your computer. #CRLF#the longer you stay on your computer, #CRLF#the longer the screen time, so go outside!
Y=138

; ===============

[CPULabel]
Text="CPU"

[CPUTooltipText]
Text=your CPU is what makes your computer alive. it helps your pc perform actions in such a fast rate. your pc temperature also depends on your CPU so keep it cool.
Y=57

; ===============

[MemoryLabel]
Text="Memory"

[MemoryTooltipText]
Text=your RAM is a memory that stores temporary data on it. your applications need memory to work properly. be careful as your apps may run slow when the number is too high!
Y=130

; ===============

[DiskLabel]
Text=Used Space (#DiskLocation#:)

[DiskTooltipText]
Text=your used space shows how much of your files have occupied your disk. if you keep this high, ame would be overwhelmed by organizing your messy files.
Y=203

