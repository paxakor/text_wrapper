#pragma once

// Function 'write_to_buf' copies 'n' bytes from 'buf_in' to 'buf_out'.
// I hope, 'BUFSIZ_OUT' would be greater than 'n'. -_-
size_t write_to_buf(char *const buf_out, size_t buf_out_sz,
  const char *const buf_in, size_t n, size_t BUFSIZ_OUT);

// Function 'find_word' looks for first word in [buf; buf+n).
// The 'word' is separated by delimiters sequence of chars.
// Word should not contain delimiter.
// Functuion returns length of word
//  and sets 'left' and 'rigtht' as pointers to
//  first and last positions in the word.
size_t find_word(const char *const buf, size_t bufsz, char delim,
  size_t *const left,  size_t *const right);
