@echo off
setlocal enabledelayedexpansion

:: ==========================================
:: CONFIGURATION: Change the contest name here
set "CONTEST_NAME=AWC0085"
:: ==========================================

:: Check if main.cpp exists in the current directory
if not exist "main.cpp" (
    echo Error: 'main.cpp' not found in the current directory.
    exit /b 1
)

:: Check if the target directory already exists to prevent overwriting
if exist "%CONTEST_NAME%" (
    echo Error: Directory '%CONTEST_NAME%' already exists. Aborting to prevent overwriting.
    exit /b 1
)

:: Create the contest directory
echo Creating directory: %CONTEST_NAME%
mkdir "%CONTEST_NAME%"
if errorlevel 1 (
    echo Error: Failed to create directory '%CONTEST_NAME%'.
    exit /b 1
)

:: Copy main.cpp to A.cpp through G.cpp
echo Generating files A.cpp to G.cpp...
for %%C in (A B C D E F G) do (
    copy "main.cpp" "%CONTEST_NAME%\%%C.cpp" >nul
    if errorlevel 1 (
        echo Error: Failed to copy main.cpp to %CONTEST_NAME%\%%C.cpp
        exit /b 1
    )
)

echo Success: Setup for %CONTEST_NAME% completed successfully.
endlocal