
#se nao tiver o wine previamente instalado, descomentar as linhas

#sudo dpkg --add-architecture i386
#wget -nc https://dl.winehq.org/wine-builds/winehq.key | sudo apt-key add -
#sudo apt-add-repository https://dl.winehq.org/wine-builds/ubuntu/
#sudo apt-add-repository 'deb https://dl.winehq.org/wine-builds/ubuntu/ artful main'
#sudo apt-get update
#sudo apt-get install --install-recommends winehq-stable
#sudo apt-get install --install-recommends winehq-devel

# Instalador wine para usuários Arch Linux 
# sudo pacman -Syu
# pacman -S wine winetricks

WINEARCH=win32 WINEPREFIX=~/.wine-circuitmaker winetricks -q gdiplus corefonts riched20 mdac28 msxml6 dotnet40
curl http://web.archive.org/web/20160129053851/http://download.microsoft.com/download/E/6/A/E6A04295-D2A8-40D0-A0C5-241BFECD095E/W2KSP4_EN.EXE -o ~/.cache/winetricks/win2ksp4/W2KSP4_EN.EXE

curl https://docentes.ifrn.edu.br/leonardoteixeira/links/instalador-do-circuitmaker-student/at_download/file -0 ~/Downloads/circuitmaker_student.exe

WINEPREFIX=~/.wine-circuitmaker wine ~/Downloads/circuitmaker_student.exe
echo -e "\n\nInstalado com sucesso! Desce o follow ai pra ajudar"
circuitmaker

# caso dê errado, entre nesse link <https://docente.ifrn.edu.br/leonardoteixeira/links/instalador-do-circuitmaker-student/view>, baixe manualmente e execute