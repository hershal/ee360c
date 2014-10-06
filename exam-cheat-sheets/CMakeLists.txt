cmake_minimum_required(VERSION 3.0)
project (lab1-doc)
include (UseLATEX.cmake)

 add_latex_document (
   exam-1-cheat-sheet.tex
   DEFAULT_PDF
)