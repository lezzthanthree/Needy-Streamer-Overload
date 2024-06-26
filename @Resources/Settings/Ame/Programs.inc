; Game Lists
; https://gist.githubusercontent.com/Cynosphere/c1e77f77f0e565ddaac2822977961e76/raw/52d1f2d31be7168a0486a3a355e06a2d751bdc44/gameslist.json
; https://discord.com/api/v8/applications/detectable

[PlayingGame]
Measure=Calc
Formula=0
IfCondition = PlayingGame = 1
IfTrueAction = [!SetVariable SpritePath "#@#Images\Ame\sprites\-1\[*Affection*]\[*Darkness*]\0"][!HideMeter HeadpatHitbox]
IfFalseAction = [!SetVariable SpritePath  "#@#Images\Ame\sprites\[*Stress*]\[*Affection*]\[*Darkness*]\[*Variation*]"][!ShowMeter HeadpatHitbox]
DynamicVariables = 1

[Watching]
Measure=Calc
Formula=0
IfCondition = Watching = 1
IfTrueAction = [!SetVariable SpritePath "#@#Images\Ame\sprites\-1\[*Affection*]\[*Darkness*]\1"][!HideMeter HeadpatHitbox]
IfFalseAction = [!SetVariable SpritePath  "#@#Images\Ame\sprites\[*Stress*]\[*Affection*]\[*Darkness*]\[*Variation*]"][!ShowMeter HeadpatHitbox]
DynamicVariables = 1

; Needy Streamer Overload/Needy Girl Overdose
[DetectWindose]
Measure=Process
ProcessName=Windose.exe
IfCondition = DetectWindose = 1
IfTrueAction = [!SetOption PlayingGame Formula 1]
IfFalseAction = [!SetOption PlayingGame Formula 0]
UpdateDivider = #SystemInfoUpdate#

; VLC
[DetectVLC]
Measure=Process
ProcessName=vlc.exe
IfCondition = DetectVLC = 1
IfTrueAction = [!SetOption Watching Formula 1]
IfFalseAction = [!SetOption Watching Formula 0]
UpdateDivider = #SystemInfoUpdate#

; osu!
[DetectOSU]
Measure=Process
ProcessName=osu!.exe
IfCondition = DetectOSU = 1
IfTrueAction = [!SetOption PlayingGame Formula 1]
IfFalseAction = [!SetOption PlayingGame Formula 0]
UpdateDivider = #SystemInfoUpdate#

; Genshin Impact
[DetectGenshin]
Measure=Process
ProcessName=GenshinImpact.exe
IfCondition = DetectGenshin = 1
IfTrueAction = [!SetOption PlayingGame Formula 1]
IfFalseAction = [!SetOption PlayingGame Formula 0]
UpdateDivider = #SystemInfoUpdate#

; Valorant
[DetectValorant]
Measure=Process
ProcessName=VALORANT.exe
IfCondition = DetectValorant = 1
IfTrueAction = [!SetOption PlayingGame Formula 1]
IfFalseAction = [!SetOption PlayingGame Formula 0]
UpdateDivider = #SystemInfoUpdate#

; Apex Legends
[DetectApex]
Measure=Process
ProcessName=r5apex.exe
IfCondition = DetectApex = 1
IfTrueAction = [!SetOption PlayingGame Formula 1]
IfFalseAction = [!SetOption PlayingGame Formula 0]
UpdateDivider = #SystemInfoUpdate#

; Minecraft (Java)
[DetectMinecraft]
Measure=Process
ProcessName=javaw.exe
IfCondition = DetectMinecraft = 1
IfTrueAction = [!SetOption PlayingGame Formula 1]
IfFalseAction = [!SetOption PlayingGame Formula 0]
UpdateDivider = #SystemInfoUpdate#

; League of Legends
[DetectLoL]
Measure=Process
ProcessName=leagueclientux.exe
IfCondition = DetectLoL = 1
IfTrueAction = [!SetOption PlayingGame Formula 1]
IfFalseAction = [!SetOption PlayingGame Formula 0]
UpdateDivider = #SystemInfoUpdate#

; Doki Doki Literature Club
[DetectDDLC]
Measure=Process
ProcessName=DDLC.exe
IfCondition = DetectDDLC = 1
IfTrueAction = [!SetOption PlayingGame Formula 1][!SetOption MeasureBackground Formula 3654][!SetOption ScreenSaverRandomizer Formula -1][!UpdateMeter ScreenSaver]
IfFalseAction = [!SetOption PlayingGame Formula 0]
UpdateDivider = #SystemInfoUpdate#

; OMORI
[DetectOMORI]
Measure=Process
ProcessName=OMORI.exe
IfCondition = DetectOMORI = 1
IfTrueAction = [!SetOption PlayingGame Formula 1][!SetOption MeasureBackground Formula 143][!SetOption ScreenSaverRandomizer Formula -1][!UpdateMeter ScreenSaver]
IfFalseAction = [!SetOption PlayingGame Formula 0]
UpdateDivider = #SystemInfoUpdate#