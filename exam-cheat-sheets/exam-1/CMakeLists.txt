cmake_minimum_required(VERSION 2.8.7)
project (exam-1-cheat-sheet)
include (../UseLATEX.cmake)

add_latex_document (
  exam-1-cheat-sheet.tex MANGLE_TARGET_NAMES
  DEFAULT_PDF
)
