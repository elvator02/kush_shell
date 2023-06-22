
# Kush Shell

This is a simple Linux Shell program written in C with the command line interface and few builtin commands.  


## Features

- Implemented 10 Builtin Commands ->
    - help: Display help information for the shell or specific builtin commands.
    - cd: Change the current working directory.
    - alias: Set aliases for commands.
    - unalias:  Unset aliases for commands.
    - type: Display the type of a command (builtin or external).
    - builtin: execute custom builtin functions.
    - color: Change the color of the shell prompt.
    - echo: Display text.
    - history: View and execute previously entered commands.   
    - exit: Exit the shell.

- Command Execution: The shell can execute external commands by forking a child process.
- Command History: The shell maintains a history of previously entered commands.
- Alias Support: The shell allows you to set and use command aliases using the alias command.
- Alias Removal: The shell provides the unalias command to remove previously set aliases.
- Command color: To give colors to shell easily by using the color codes.
- Also used emojis, but it only supports in few terminals. VS Code supports it so you can execute the shell in vscode to get full features of shell.


## Getting Started

- This will work in a Linux distro as it is based on Linux Shell.
- If you don't have any Linux distro then use [WSL](https://learn.microsoft.com/en-us/windows/wsl/install) on windows.
- Also make sure to have [gcc](https://code.visualstudio.com/docs/cpp/config-wsl) to Compile the program and [git](https://learn.microsoft.com/en-us/windows/wsl/tutorials/wsl-git) to clone the program.

Then, Clone the project

```bash
  git clone https://github.com/your-username/kush_shell.git
```

Go to the project directory

```bash
  cd kush_shell
```

Compile the Source code

```bash
  gcc -o shell shell.c
```

Run the shell

```bash
  ./shell
```
- Also alternatively you can use makefile 
Clone the project

```bash
  git clone https://github.com/your-username/kush_shell.git
```
Go to the project directory

```bash
  cd kush_shell
```

Run the makefile

```bash
  make
```
Run the shell

```bash
  make run
``` 
to delete shell

```bash
  make clean
``` 


## Usage

Once you have started the Kush Shell, you can enter commands at the prompt. The shell will execute the built-in commands or external commands based on your input.

Built-in commands
- alias: Set an alias for a command. Usage: alias <alias_name> <command>.
- unalias: Remove an alias. Usage: unalias <alias_name>.
- cd: Change the current working directory. Usage: cd <directory>.
- echo: Display text. Usage: echo <text>.
- exit: Exit the shell. Usage: exit.
- type: Display the type of a command (builtin or external). Usage: type <command>.
- history: Gives a list of previously entered commands. Usage: history.
- help: Display help information for the shell. Usage: help.
- builtin: Executes custom builtin function which can be customized in kush_builtin header file.Usage: builtin <builtin_command>.
- color: Gives color to shell. If want an emoji use this. Usage: color <color_or_emoji_name>.
  - available colours are- blue, yellow, red, cyan, green, reset.
  - available emoji - heart.
## Acknowledgements

 - This project was made under ACM projects [ACM IITR](https://iitr.acm.org/#/)
 - Also found this good resource to get start with this project  [Shell in C](https://brennan.io/2015/01/16/write-a-shell-in-c/)
 - to implement more emojis go to this [link](https://apps.timwhitlock.info/emoji/tables/unicode)

