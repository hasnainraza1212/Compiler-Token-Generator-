# Code Analysis and Token Recognition

This C program performs token recognition and analysis on a given input string. It identifies various elements such as operators, keywords, integers, real numbers, and valid identifiers in the input.

## Table of Contents
- [Introduction](#introduction)
- [Functions](#functions)
- [Usage](#usage)
- [How it Works](#how-it-works)
- [License](#license)

## Introduction
The program consists of functions for identifying different types of tokens in a C-style input string. These tokens include delimiters, operators, keywords, integers, real numbers, and valid identifiers.

## Functions
1. `isDelimiterHA`: Checks if a character is a delimiter.
2. `isOperatorHA`: Checks if a character is an operator.
3. `isValidIdentifierHA`: Checks if a string is a valid identifier.
4. `isKeywordHA`: Checks if a string is a keyword.
5. `isIntegerHA`: Checks if a string is an integer.
6. `isRealNumberHA`: Checks if a string is a real number.
7. `extractSubstringHA`: Extracts a substring from a given string.
8. `parseInputStringHA`: Parses the input string and identifies tokens.
9. `main`: The main function reads an input string, calls the parsing function, and displays the identified tokens.

## Usage
To use this program, follow these steps:
1. Copy the provided code.
2. Paste it into a C compiler or an online C compiler such as [OnlineGDB](https://www.onlinegdb.com/online_c_compiler).
3. Compile and run the program.
4. Enter a C-style input string when prompted.

## How it Works
- The program reads an input string using `fgets`.
- The `parseInputStringHA` function iterates through the characters of the input string, identifying and printing tokens such as operators, keywords, integers, real numbers, and valid identifiers.
- The program demonstrates basic token recognition and is intended for educational purposes.

## License
This program is released under the [MIT License](LICENSE). Feel free to modify and use it for educational and non-commercial purposes.

---

**Note:** This README provides a brief overview of the code. For more detailed information, refer to the comments within the code itself.
