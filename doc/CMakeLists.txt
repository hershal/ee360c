cmake_minimum_required (VERSION 2.8)
project (ee460n-manual)
include (UseLATEX.cmake)
add_latex_document (writeup.tex # ee460n-manual.tex
  USE_GLOSSARY
  DEFAULT_PDF
)