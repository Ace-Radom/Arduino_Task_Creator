# ===============================================
# ===============================================
# *\src\OSRead.ps1
# ===============================================
# ===============================================
#
# read OS details (OS version, CPU, physic RAM and powershell version)
# ported from project Win_HashCheck_Master
# start time: 2022.10.10
#
# 2022.10.11 delete "[OS]>" before each print line, change cache path
# 2022.10.12 set this file to "usused" status
#            function Print_SystemInfo is no longer using this script (in header .\include\collectinfo.h)

# print different color in one line
function Write-Color( [String[]]$Text , 
                      [ConsoleColor[]]$Color = "White" , 
                      [int]$StartTab = 0 , [int] $LinesBefore = 0 , [int] $LinesAfter = 0 , 
                      [string] $LogFile = "" , $TimeFormat = "yyyy-MM-dd HH:mm:ss" ){
    $DefaultColor = $Color[0]
    if ( $LinesBefore -ne 0 ) 
    { 
        for ( $i = 0 ; $i -lt $LinesBefore ; $i++ ) 
        { 
            Write-Host "`n" -NoNewline 
        } 
    } 
    # Add empty line before
    if ( $StartTab -ne 0 ) 
    { 
        for ( $i = 0 ; $i -lt $StartTab ; $i++ )
        { 
            Write-Host "`t" -NoNewLine 
        }
    } 
    # Add TABS before text
    if ( $Color.Count -ge $Text.Count )
    {
        for ( $i = 0 ; $i -lt $Text.Length ; $i++ )
        { 
            Write-Host $Text[$i] -ForegroundColor $Color[$i] -NoNewLine 
        }
    } 
    else
    {
        for ( $i = 0 ; $i -lt $Color.Length ; $i++ ) 
        {
            Write-Host $Text[$i] -ForegroundColor $Color[$i] -NoNewLine
        }
        for ( $i = $Color.Length ; $i -lt $Text.Length ; $i++ )
        {
            Write-Host $Text[$i] -ForegroundColor $DefaultColor -NoNewLine
        }
    }
    Write-Host
        if ( $LinesAfter -ne 0 ) 
        { 
            for ( $i = 0 ; $i -lt $LinesAfter ; $i++ )
            {
                Write-Host "`n"
            }
        } 
        # Add empty line after
        if ( $LogFile -ne "" )
        {
            $TextToFile = ""
            for ( $i = 0 ; $i -lt $Text.Length ; $i++ )
            {
                $TextToFile += $Text[$i]
            }
            Write-Output "[$([datetime]::Now.ToString($TimeFormat))]$TextToFile" | Out-File $LogFile -Encoding unicode -Append
        }
}

$logPath = "$PSScriptRoot\OSRead_Cache"
# create cache

Get-CimInstance -ClassName Win32_OperatingSystem | Select-Object -property Version | Out-file $logPath
Write-Color -Text "OS Version: " , $( ( Get-Content $logPath -Tail 3 )[-3] ) -Color white , yellow
# get OS version

Get-CimInstance -ClassName Win32_Processor | Select-Object -property Name | Out-file $logPath
Write-Color -Text "CPU: " , $( ( Get-Content $logPath -Tail 3 )[-3] ) -Color white , yellow
# get CPU name

$RAMinTotal = ( ( Get-CimInstance Win32_PhysicalMemory | Measure-Object -Property capacity -Sum ).sum / 1gb )
Write-Color -Text "Physic RAM: " , $RAMinTotal , "GB" -Color white , yellow , yellow
# get physic RAM

$host | Select-Object -property Version | Out-file $logPath
Write-Color -Text "Powershell Version: " , $( ( Get-Content $logPath -Tail 3 )[-3] ) -Color white , yellow
# get powershell version

Remove-Item $logPath
# delete cache