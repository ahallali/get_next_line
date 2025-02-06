# GET Next Line Project (C Language)

This project implements the functionality to read lines from one or more files in C. The `get_next_line` function is mandatory for reading from a single file, and bonus functionality is included for reading lines from multiple files.

## Features

- **Mandatory:** The project includes a core functionality to read the next line from a single file using the `get_next_line` function.
- **Bonus:** The project includes the ability to process multiple files, reading the next line from each file sequentially.

## Requirements

- C compiler (e.g., GCC)
- Basic knowledge of C programming and file handling

## Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/ahallali/get_next_line
    ```

2. Navigate to the project directory:
    ```bash
    cd get_next_line
    ```

## Mandatory

### File Structure for Mandatory

- **`get_next_line.c`**: Contains the core functionality for reading from a single file.
- **`get_next_line.h`**: Header file for the mandatory functionality.
- **`get_next_line_utils.c`**: Utility functions for the mandatory functionality.
- **`text.txt`**: A sample text file to read from for the mandatory functionality.

Command to Run (Mandatory)
After compiling, you can run the program to read from the text.txt file:

bash
Copier
Modifier
./a.out
This will read and print the next line from text.txt.

## Bonus

### File Structure for Bonus

- **`get_next_line_bonus.c`**: Contains the bonus functionality to read from multiple files.
- **`get_next_line_bonus.h`**: Header file for the bonus functionality.
- **`get_next_line_utils_bonus.c`**: Utility functions for the bonus functionality.
- **`file1.txt`**: A sample text file for the bonus functionality.
- **`file2.txt`**: Another sample text file for the bonus functionality.

### Command to Compile (Bonus)

To compile the bonus part of the project, run the following command:

```bash
gcc -Wall -Werror -Wextra get_next_line_bonus.c get_next_line_bonus.h get_next_line_utils_bonus.c -o next_line_bonus
```
Command to Run (Bonus)
After compiling, you can run the program to read from multiple files (file1.txt and file2.txt):

```bash
./next_line_bonus
```
## Summary of Changes:

- Added specific files (`text.txt` for mandatory and `file1.txt`, `file2.txt` for bonus).
- Provided detailed compile and run commands for both the mandatory and bonus parts:
    - **Mandatory**: `gcc -Wall -Werror -Wextra get_next_line.c get_next_line.h get_next_line_utils.c`
    - **Bonus**: `gcc -Wall -Werror -Wextra get_next_line_bonus.c get_next_line_bonus.h get_next_line_utils_bonus.c`
- Instructions for running the compiled programs to process either one or multiple files.

