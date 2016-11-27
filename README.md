# Text Wrapper
`This tool should make any code slimmer.`

## Features
* Wrap the text.
* Add a few spaces in beginning of the line (like tab).
* I/O: files and(or) standard streams.
* It was made for quick style-fixes in LaTeX files.

## Usage
* For building required CMake and POSIX-compliant C compiler.
* Building:
  1. `cd path/to/project/directory`
  2. `mkdir build && cd build`
  3. `cmake .. && make`

  Done! Now you have binary `wrp` at build directory.
  You can move this standalone binary wherever you want.
* Running:
  `wrp -h` or `wrp --help` for getting help.
* The main usage (for me, of course):
  `wrp -i source.tex -o source_formated.tex`

### Author
Корозевцев Павел<br />
email: paxakor@yandex.ru<br />
[vkontakte](vk.com/paxakor)<br />
[github](github.com/paxakor)
