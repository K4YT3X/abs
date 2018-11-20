# abs

A tiny Linux command line tool that will display the absolute path of a file (or directory and etc.).

## Usages

Run `abs` followed by the target file, and `abs` will print the full absolute path of the target file.

```bash
$ abs [file]
```

## Screenshots

This should look pretty intuitive.

![abs](https://user-images.githubusercontent.com/21986859/48755901-0ab0a180-ec65-11e8-8874-9a64926fa020.png)

## Build It Yourself

Since this program doesn't have any dependencies, you can simply run a `cmake` command to compile the program.

The following example compiles `abs` into the current directory.

```bash
$ cmake .
```

And then you can move the abs binary into `/usr/bin`.

```bash
$ sudo mv abs /usr/bin/abs
```
