Steps to commit code -

git init
git add .
git commit -m "first commit" 
git branch -M main 
git remote add origin https://github.com/kar3798/TCPClient_QtCreator.git 
git push -u origin main --force

How to make windows.exe Steps -

Add the path, where windeployqt is installed in your PC, under system variables in the edit environment variables menu. 
Open CMD Open the directory where you .exe release is present (C:\Qt\Projects\TCPClient\build\Desktop_Qt_6_7_3_MinGW_64_bit-Release\release). 
Run the command $ windeployqt <Program.exe> (windeployqt TCPClient.exe) This creates a executable with all the libraries linked.
