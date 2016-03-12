# Text Wrapper
`This tool should make any code more beautiful.`

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

## Why I use C?
Basically, I don't know. But there are a few reasons.
* I don't like high-level programming languages.
* For a long time I had a wish: write something in pure C.
* C allows read and write buffered.
  It means that `wrp` don't load all file in RAM and works fast.
* In my opinion, C is better than C++.
