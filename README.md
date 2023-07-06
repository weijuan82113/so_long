# so_long

## Overview
Use minilibx to design a 2D game

## Requirement
- MacOSX (AppKit) Xcode 14.1
- OpenGL `$ brew install glfw`
- Xquartz(2.8.3) `$ brew xquartz`

## Usage
- clone
```
git clone {url} so_long
cd so_long
```
- make mandatory part(without enemy movement)
```
make
./so_long ./maps/ok_12x8.ber`
```
- make bonus part(add BSF to let enemy movement)
```
make bonus
./so_long_bonus ./maps/ok_12x8.ber
```

## Feature
- Graphic management
- Use BSF algorithm to confirm the validation check of the input map
- Use graph to let the item move automatically

## Reference
>https://harm-smits.github.io/42docs/libs/minilibx
>https://www.programiz.com/dsa/graph-dfs

## Author
Weijuan Chen



