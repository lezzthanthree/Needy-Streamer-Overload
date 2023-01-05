[Variables]
StressToggleValue=0
AffectionToggleValue=0
DarknessToggleValue=0

[DisableCPU]
Measure=Calc
Formula=0
IfCondition=DisableCPU = 1
IfTrueAction=[!DisableMeasure MeasureCPU][!SetOption Stress Formula #StressToggleValue#]
IfCondition2=DisableCPU = 2
IfTrueAction2=[!DisableMeasure MeasureCPU][!SetOption Stress Formula #StressToggleValue#][!EnableMeasure Stressed]

[DisableMemory]
Measure=Calc
Formula=0
IfEqualValue=1
IfEqualAction=[!DisableMeasure MeasureMemoryPercentage][!SetOption Affection Formula #AffectionToggleValue#]

[DisableSpace]
Measure=Calc
Formula=0
IfEqualValue=1
IfEqualAction=[!DisableMeasure MeasureDiskPercentage][!SetOption Darkness Formula #DarknessToggleValue#]
