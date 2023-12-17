

| Feature                       | Bash                                 | C                                                     |
|-------------------------------|--------------------------------------|-------------------------------------------------------|
| **Shebang**                   | `#!/bin/bash`                        | Not applicable                                        |
| **Variables**                 | `variable=value` (no type)           | `type variable = value;`                              |
| **Echo/Print**                | `echo "Hello"`                       | `printf("Hello\n");`                                  |
| **Comments**                  | `# This is a comment`                | `// This is a comment` or `/* Multi-line comment */`  |
| **Conditional Statements**    | `if [ condition ]; then ... fi`      | `if (condition) { ... }`                              |
| **Looping (for)**             | `for i in {1..5}; do ... done`       | `for(int i = 1; i <= 5; i++) { ... }`                 |
| **Looping (while)**           | `while [ condition ]; do ... done`   | `while (condition) { ... }`                           |
| **Functions**                 | `function_name() { ... }`            | `return_type function_name(parameters) { ... }`       |
| **Arithmetic Operators**      | `$((a + b))`, `$((a * b))`, etc.     | `a + b`, `a * b`, etc.                                |
| **String Concatenation**      | `result="$str1$str2"`                | Use functions like `strcat` or combine with `printf`  |
| **Command Substitution**      | `result=$(command)`                  | Use `system("command")`                               |
| **Array Declaration**         | `arr=(1 2 3)`                        | `int arr[] = {1, 2, 3};`                              |
| **Array Access**              | `${arr[0]}`                          | `arr[0]`                                              |
| **Input**                     | `read variable`                      | `scanf("%d", &variable)`                              |
| **Output**                    | `echo "Value is: $variable"`         | `printf("Value is: %d\n", variable)`                  |
| **Exit**                      | `exit`                               | `exit(0)`                                             |
| **Conditional Ternary Optr**  | Not directly available               | `condition ? expr_if_true : expr_if_false`            |

