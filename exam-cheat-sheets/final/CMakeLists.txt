cmake_minimum_required(VERSION 2.8.7)
project (final-exam-cheat-sheet)
include (../UseLATEX.cmake)

add_latex_document (
  final-exam-cheat-sheet.tex MANGLE_TARGET_NAMES
  DEFAULT_PDF
)
