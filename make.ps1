$name = "server.exe"
& gcc main.c renderfile.c -o $name -lws2_32
if ($LASTEXITCODE -eq 0) {
    Write-Host "`nmake.ps1-> copilation succecfully, running execultable...`n"
    & .\$name
}