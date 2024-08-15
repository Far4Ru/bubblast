# Game

## Build and run
- Linux
> make
- Windows (bash)
> mingw32-make

## Game rules
The user controls a character trapped in the arena. Enemies of several types come endlessly (or in several waves) from outside the arena and attack the character. The player can shoot at them by aiming with the mouse, and move around to avoid damage. The field may contain shelters. For each defeated opponent, the player is awarded points. As soon as the player loses all lives, or the opponents run out, the game ends and the number of points scored during the game is displayed on the screen. The top 10 results are stored in a file and displayed on the screen at the user's request.

## Screens

![screen](presentation/screen.gif)


## SDL2
### Windows
[SDL2 download](https://github.com/libsdl-org/SDL/releases)

- <...-w64-mingw32>/include -> \<project>/SDL2/include  
- <...-w64-mingw32>/lib -> \<project>/SDL2/lib  
- <...-w64-mingw32>/bin/SDL2.dll -> \<project>/SDL2.dll

- mixer-devel-2.8.0-mingw (i686-w64-mingw32)
- image-devel-2.8.2-mingw (i686-w64-mingw32)
- ttf-devel-2.22.0-mingw (i686-w64-mingw32)