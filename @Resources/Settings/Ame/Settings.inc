[Variables]
StressToggleValue=0
AffectionToggleValue=1
DarknessToggleValue=0

[DisableCPU]
Measure=Calc
Formula=1
IfCondition=DisableCPU = 1
IfTrueAction=[!DisableMeasure MeasureCPU][!SetOption Stress Formula #StressToggleValue#]
IfCondition2=DisableCPU = 2
IfTrueAction2=[!DisableMeasure MeasureCPU][!SetOption Stress Formula #StressToggleValue#][!EnableMeasure Stressed]

[DisableMemory]
Measure=Calc
Formula=1
IfEqualValue=1
IfEqualAction=[!DisableMeasure MeasureMemoryPercentage][!SetOption Affection Formula #AffectionToggleValue#]

[DisableSpace]
Measure=Calc
Formula=1
IfEqualValue=1
IfEqualAction=[!DisableMeasure MeasureDiskPercentage][!SetOption Darkness Formula #DarknessToggleValue#]
