<p align="center">
   <img width="100" src="https://github.com/mcombeau/mcombeau/blob/main/42_badges/get_next_linee.png">
</p>

# 42-Get_next_line
Reading a line from a fd is way too tedious.


## 📝 Summary

The `get_next_line` project is a part of the 42 curriculum that involves implementing a function to read a line from a file descriptor efficiently. 
The function provides flexibility in handling files and standard input while ensuring optimal performance through static variables.


## 📚 Learning Objectives

+ Develop a reusable function to read lines from file descriptors.
+ Learn and apply the concept of static variables in C programming.


## 🚀 Features

+ Reads one line at a time from a file descriptor.
+ Returns the line, including the terminating `\n` (if present).
+ Manages memory dynamically and avoids leaks.
+ Support for multiple file descriptors simultaneously.
+ Use only one static variable for implementation.


## 🧩 Project Structure

Mandatory files:

```bash
├── get_next_line.h                  # Header file
├── get_next_line.c                  # Core implementation
└── get_next_line_utils.c            # Helper functions
```

Bonus files:

```bash
├── get_next_line_bonus.h            # Header file
├── get_next_line_bonus.c            # Core implementation
└── get_next_line_utils_bonus.c      # Helper functions
```

Other files:

```bash
├── example.txt                      # Example text
└── README.md                        # Project documentation
```

## 🎴 Main Function

Include this `main` function in the `get_next_line.c` file.
```c
int main(void)
{
    char   *line;
    int    fd;
    int    i;

    fd = open("example.txt", O_RDONLY);
    line = get_next_line(fd);
    i = 1;
    while (line != NULL)
    {
        printf("Line [%d] : %s ", i, line);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    close(fd);
    return 0;
}
```

## 🛠 Compilation

1. Clone this repository.
   ```bash
   git clone https://github.com/alianad/42-Get_next_line.git
   cd 42-Get_next_line

2. Compile.
   ```bash
   cc -Wall -Wextra -Werror -D BUFFER_SIZE=<size> get_next_line.c get_next_line_utils.c
   
Replace `<size>` with your desired buffer size.


## ⚙️ Testing

  + https://github.com/Tripouille/gnlTester.git
  + https://github.com/kodpe/gnl-station-tester.git

