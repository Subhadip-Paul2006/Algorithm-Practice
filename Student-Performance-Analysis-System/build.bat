@echo off
REM Build and run the Student Performance Analysis (Part04)
g++ Part04.cpp -o analysis.exe
if %errorlevel% neq 0 (
    echo Compilation failed.
    pause
    exit /b %errorlevel%
)

echo Running analysis with sample_input.txt
.
analysis.exe < sample_input.txt

echo.
echo Program finished. Press any key to exit.
pause