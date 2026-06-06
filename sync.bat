@echo off
setlocal enabledelayedexpansion

:: Check if the current directory is a git repository
git rev-parse --is-inside-work-tree >nul 2>&1
if errorlevel 1 (
    echo Error: Not a git repository.
    exit /b 1
)

echo Fetching remote updates...
git fetch >nul 2>&1

:: Initialize variables
set "LOCAL="
set "REMOTE="
set "BASE="

:: Get commit hashes
for /f "delims=" %%i in ('git rev-parse @ 2^>nul') do set "LOCAL=%%i"
for /f "delims=" %%i in ('git rev-parse @{u} 2^>nul') do set "REMOTE=%%i"
for /f "delims=" %%i in ('git merge-base @ @{u} 2^>nul') do set "BASE=%%i"

:: Check for potential conflicts
if defined REMOTE (
    if "!LOCAL!"=="!BASE!" (
        if not "!LOCAL!"=="!REMOTE!" (
            echo Error: Local branch is behind remote. Aborting to prevent conflicts.
            exit /b 1
        )
    )
    if not "!LOCAL!"=="!REMOTE!" (
        if not "!REMOTE!"=="!BASE!" (
            echo Error: Local and remote branches have diverged. Aborting to prevent conflicts.
            exit /b 1
        )
    )
) else (
    echo Warning: No upstream branch set. Make sure to set it on your first push.
)

:: Check if there are any changes to commit
git status --porcelain | findstr "." >nul
if errorlevel 1 (
    echo Info: No changes to commit.
    exit /b 0
)

:: Get timestamp safely using PowerShell
for /f "delims=" %%i in ('powershell -NoProfile -Command "Get-Date -Format 'yyyy-MM-dd HH:mm:ss'"') do set "TIMESTAMP=%%i"

echo Adding and committing changes...
git add .
git commit -m "!TIMESTAMP!" >nul

echo Pushing to remote...
git push
if errorlevel 1 (
    echo Error: Git push failed.
    exit /b 1
) else (
    echo Success: Sync completed!
)

endlocal