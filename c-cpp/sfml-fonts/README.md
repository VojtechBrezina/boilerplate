# SFML system font detection

## How to use

Just copy the files into a project using SFML (intended for SFML 3, but should
work with SFML 2 as well). The code is easy enough to understand, so modifying
it to load different families should not be a problem.

## How it works

This only works on unix systems with
[Fontonfig](https://www.freedesktop.org/wiki/Software/fontconfig/). It uses the
`fc-match` program for now, because I couldn't get the C library to work before
I lost interest.

## TODO

Look into using the library instead of the CLI utility and making this choice
configurable. (The font config C interface is quite complicated, so this change
will take some reading up front.)
