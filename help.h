#pragma once

const char* help_msg_ru = 
"Эта программа разбивает текст на строки длины не более заданной.\n\
В основном, предназначается для форматирования исходных файлов LaTeX.\n\
Использование: wrp [options]\n\
Options:       Description                           Default value\n\
  -h, --help   print this message and exit\n\
  -i <File>    set File as input                     stdin\n\
  -o <File>    set File as output                    stdout\n\
  -d <Symbol>  set Symbol as delimeter               ' ' (space, 32)\n\
  -l <Number>  set Number as max length of the line  80\n\
  -t <Number>  set Number as tab size                0\n";
