# This is a powershell comment huh?

$sourceFiles = Get-ChildItem -Path . -Filter *.c -Name

$gccCommand = "gcc"

Write-Host $sourceFiles
