# CS152-Project
### Howie Nguyen, Ryan Hernandez, Godfrey Lozada

## Phase 0

#### Language Name
 HRG-Lang

#### Extension
 *.hrg

#### Compiler
HRG-LC

### Basic Features

| Feature | Example |
|---------|---------|
| Integer scalar variables | int x; float y; double z; bool w; char i; |
| One-dimensional arrays of integers | int array[x]; float array[x]; double array[x]; bool array[x]; char string[x]; (x being a fixed number)|
| Assignment statements | int array [] = {1, 0, 1}; , int number = 0; etc.. |
| Arithmetic operators | “+”, “-”, “\*”, “/” |
| Relational operators |  “<”, “==”, “>”, “~=” |
| While loop (including "break" and "continue" loop control statements) | while (is_open){ "do something" continue; if is_open = false: break;} |
| If-then-else statements | if( CONDITION ) { BODY }, else{ BODY } | 
| Read and write statements | INPUT = intake(); defecate(OUTPUT); |
| Comments |"$ This is a comment. $" |
|  Functions (that can take multiple scalar arguments and return a single scalar result) | int func{ return int;} double func { return double;} char func { return char; }  void func{ }|

### More Information
1. Define how comments would look like in your language
* Defined above already. Single line comments start and end with $
* Multi-line comments start with and end with $$

2. Define what would be the valid identifier
* Names can ONLY contain letters and underscores
* Names must begin with a letter or an underscore (_)
* Names are case sensitive (myVar and myvar are different variables)
* Reserved words (like C++ keywords, such as int) cannot be used as names

3. Whether your language is case sensitive or not
* Language will be case sensitive to allow for greater range of character usage.

4. What would be whitespces in your laguage
* Whitespace will be ignorable in our language and only for the purpose of readability for the programmer.
* Semi-colons will be used to determine statements and not whitespace.

### Tokens
#### Variables
| Symbol | Token |
|--------|-------|
| int    | INTEGER |
| dbl    | DOUBLE  |
| flt    | FLOAT   |
| bln    | BOOLEAN |
| chr    | CHAR    |

#### Arithmetic and Comparators
| Symbol | Token |
|--------|-------|
| =      | ASSIGNMENT |
| +      | ADD     |
| -      | SUB     |
| /      | DIV     |
| *      | MUL     |
| mod    | MOD     |
| :=     | EQ      |
| <      | LT      |
| <=     | LTE     |
| >      | GT      |
| >=     | GTE     |

#### Reserved words
| Symbol | Token | 
|--------|-------|
| func   | FUNCTION |
| {      | BEGINSCOPE | 
| }      | ENDSCOPE |
| (      | BEGINPARAM |
| )      | ENDPARAM |
| if     | IF |
| else   | ELSE |
| for    | FOR |
| while  | WHILE | 
| continue | CONTINUE | 
| break  | BREAK |
| true   | TRUE |
| false  | FALSE |
| return | RETURN |
| ~      | NOT |
| void   | VOID |
