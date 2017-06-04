cd ..

call "%VS120COMNTOOLS%/vsvars32.bat"

qmake -tp vc

rd /s /q debug release
pause