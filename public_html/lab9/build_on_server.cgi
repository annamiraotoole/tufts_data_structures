#!/bin/sh

printf "Content-Type:  text/plain\r\n\r\n"
exec 2>&1

printf "Compiling on web server\n"

make trie_web
