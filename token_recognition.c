#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Returns 'true' if the character is a DELIMITER.
bool isDelimiterHA(char character)
{
    // Check for single-character delimiters
    if (character == ' ' || character == '+' || character == '-' || character == '*' ||
        character == '/' || character == ',' || character == ';'
        || character == '>' || character == '<' || character == '='
        || character == '(' || character == ')' || character == '[' ||
        character == ']' || character == '{' || character == '}' ||
        character == ':')  // Added ':' as a delimiter
        return (true);
    return (false);
}

// Returns 'true' if the string is a multi-character DELIMITER.
bool isMultiCharDelimiterHA(const char* str)
{
    // Check for multi-character delimiters
    if (strcmp(str, ":") == 0)  // Check for ':'
        return true;
    return false;
}

// Returns 'true' if the character is an OPERATOR.
bool isOperatorHA(char character)
{
    if (character == '+' || character == '-' || character == '*' ||
        character == '/' || character == '>' || character == '<' ||
        character == '=')
        return (true);
    return (false);
}

const char* getDelimiterType(char delimiter)
{
    switch (delimiter)
    {
    case ' ':
        return "SPACE";
    case '+':
        return "PLUS";
    case '-':
        return "MINUS";
    case '*':
        return "TIMES";
    case '/':
        return "DIVIDE";
    case ',':
        return "COMMA";
    case ';':
        return "SEMICOLON";
    case '>':
        return "GREATER_THAN";
    case '<':
        return "LESS_THAN";
    case '=':
        return "EQUALS";
    case '(':
        return "LEFT_PAREN";
    case ')':
        return "RIGHT_PAREN";
    case '[':
        return "LEFT_BRACKET";
    case ']':
        return "RIGHT_BRACKET";
    case '{':
        return "LEFT_BRACE";
    case '}':
        return "RIGHT_BRACE";
    case ':':
        return "COLON";
    default:
        return "UNKNOWN";
    }
}

// Returns 'true' if the string is a VALID IDENTIFIER.
bool isValidIdentifierHA(char* string)
{
    if (string[0] == '0' || string[0] == '1' || string[0] == '2' ||
        string[0] == '3' || string[0] == '4' || string[0] == '5' ||
        string[0] == '6' || string[0] == '7' || string[0] == '8' ||
        string[0] == '9' || isDelimiterHA(string[0]) == true)
        return (false);
    return (true);
}

// Returns 'true' if the string is a KEYWORD.
bool isKeywordHA(char* string)
{
    if (!strcmp(string, "if") || !strcmp(string, "else") ||
        !strcmp(string, "while") || !strcmp(string, "do") ||
        !strcmp(string, "break") ||
        !strcmp(string, "continue") || !strcmp(string, "int")
        || !strcmp(string, "double") || !strcmp(string, "float")
        || !strcmp(string, "return") || !strcmp(string, "char")
        || !strcmp(string, "case") || !strcmp(string, "char")
        || !strcmp(string, "sizeof") || !strcmp(string, "long")
        || !strcmp(string, "short") || !strcmp(string, "typedef")
        || !strcmp(string, "switch") || !strcmp(string, "unsigned")
        || !strcmp(string, "void") || !strcmp(string, "static")
        || !strcmp(string, "struct") || !strcmp(string, "goto"))
        return (true);
    return (false);
}

// Returns 'true' if the string is an INTEGER.
bool isIntegerHA(char* string)
{
    int i, len = strlen(string);

    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (string[i] != '0' && string[i] != '1' && string[i] != '2'
            && string[i] != '3' && string[i] != '4' && string[i] != '5'
            && string[i] != '6' && string[i] != '7' && string[i] != '8'
            && string[i] != '9' || (string[i] == '-' && i > 0))
            return (false);
    }
    return (true);
}

// Returns 'true' if the string is a REAL NUMBER.
bool isRealNumberHA(char* string)
{
    int i, len = strlen(string);
    bool hasDecimal = false;

    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (string[i] != '0' && string[i] != '1' && string[i] != '2'
            && string[i] != '3' && string[i] != '4' && string[i] != '5'
            && string[i] != '6' && string[i] != '7' && string[i] != '8'
            && string[i] != '9' && string[i] != '.' ||
            (string[i] == '-' && i > 0))
            return (false);
        if (string[i] == '.')
            hasDecimal = true;
    }
    return (hasDecimal);
}

// Extracts the SUBSTRING.
char* extractSubstringHA(char* string, int left, int right)
{
    int i;
    char* subString = (char*)malloc(
        sizeof(char) * (right - left + 2));

    for (i = left; i <= right; i++)
        subString[i - left] = string[i];
    subString[right - left + 1] = '\0';
    return (subString);
}

// Parsing the input STRING.
void parseInputStringHA(char* string)
{
    int left = 0, right = 0;
    int len = strlen(string);

    while (right <= len && left <= right) {
        if (isDelimiterHA(string[right]) == false)
            right++;

        if (isDelimiterHA(string[right]) == true && left == right) {
            if (isOperatorHA(string[right]) == true)
                printf("'%c'%s", string[right], getDelimiterType(string[right]));
            else if (isMultiCharDelimiterHA(&string[right])) {
                printf("'%s'%s", extractSubstringHA(string, right, right + 1), getDelimiterType(':'));
                right++;  // Move the index an extra step for multi-character delimiter
            }
            else
                printf("'%c'%s ", string[right], getDelimiterType(string[right]));
            right++;
            left = right;
        }
        else if (isDelimiterHA(string[right]) == true && left != right
            || (right == len && left != right)) {
            char* subString = extractSubstringHA(string, left, right - 1);

            if (isKeywordHA(subString) == true)
                printf("'%s'KEYWORD ", subString);

            else if (isIntegerHA(subString) == true)
                printf("'%s'INTLIT ", subString);

            else if (isRealNumberHA(subString) == true)
                printf("'%s'REAL NUMBER ", subString);

            else if (isValidIdentifierHA(subString) == true
                && isDelimiterHA(string[right - 1]) == false)
                printf("'%s'IDENT ", subString);

            else if (isValidIdentifierHA(subString) == false
                && isDelimiterHA(string[right - 1]) == false)
                printf("'%s'NOTIDENT ", subString);
            left = right;
        }
    }
    return;
}

// DRIVER FUNCTION
int main()
{
    // maximum length of string is 100 here
    char inputString[100];
    char* input = fgets(inputString, sizeof(inputString), stdin);

    // Check if fgets was successful in reading the input
    if (input != NULL) {
        input[strcspn(input, "\n")] = '\0';
        parseInputStringHA(input);
    } else {
        printf("Error reading input\n");
    }

    return (0);
}
