# ![1] Serrarien ![2]
Serrarien is a 2D survival game inspired by Terraria. It is open-source
and entirely made in C++17.

## How to compile
Compiling is pretty simple thanks to cmake. Just clone the repo, go to
the newly created folder and launch the following command:
```shell
cmake -B build && cmake --build build
```
You can then launch the game with `./build/Serrarien`

## Third party
OpenGL is used for all the rendering and GLFW to get a window.

STB is used to load PNG images.

GLM is used for all the computation on matrices and mathematical
vectors.

The Noto Sans Light bitmap font has been generated with CBFG.

## Licensing
This project is distributed under the MIT License. See
[LICENSE](LICENSE) for further details.

**Noto is a trademark of Google Inc.** Noto fonts are open source. All
Noto fonts are published under the
[SIL Open Font License, Version 1.1][3].

[1]: res/images/cursor_dirt.png
[2]: res/images/blocks/dirt_block.png
[3]: http://scripts.sil.org/cms/scripts/page.php?site_id=nrsi&id=OFL