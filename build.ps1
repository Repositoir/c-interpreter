# This is a powershell comment huh?

$sourceFiles = Get-ChildItem -Path . -Filter *.c -Name

$gccCommand = "gcc"

# TODO: Write a valid powershell code to execute compilation using MinGW gcc

Write-Host $sourceFiles
