@echo off
@break off
@title Create folder with batch but only if it doesn't already exist 
@color 0a
@cls

setlocal EnableDelayedExpansion
set sysPath="c:\program files\Internet Explorer\log"
set workPath="c:\phonebar_log"
set lookup=0


:check_Permissions
:echo WE EXPECT 666 OCCURS ...

net session >nul 2>&1
if %errorLevel% == 0 (
  set lookup=1
) else (
  echo Failure : Current permissions inadequate.
  echo Please, run this file as administrator.
  pause >nul 
)



cd C:\
if %cd% == "C:\" ( echo In C:\ drive. )

if not exist %sysPath% (
  mkdir %sysPath%
)
if not exist %workPath% (
  mkdir %workPath%
)
if not exist %sysPath% ( 
  echo ERROR 555
) else (
  echo Success 666
)
if not exist %workPath% ( 
  echo ERROR 555
) else (
  echo Success 666
)
pause
 