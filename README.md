# Gentoc

`gentoc` is a simple command-line tool written in C for generating a Table of Contents (ToC) for markdown files. It processes the markdown headers in the file and generates corresponding ToC entries.

## Features

- Parses markdown headers.
- Generates ToC entries in markdown format.
- Converts headers to lowercase and replaces spaces with hyphens for link compatibility.
- Supports a variety of Latin characters and converts them appropriately. (WIP)

## Usage

To use `gentoc`, compile the source code and run the executable with a markdown file as an argument.

### Compilation

A Makefile is provided for convenience. Ensure you have make and a C compiler (such as gcc) installed. You can compile the code using:

```sh
make
```

This will create an executable named `gentoc` on Linux or `gentoc.exe` on Windows.

### Running

Once compiled, you can run `gentoc` with a markdown file as follows:

```sh
./gentoc [file]
```

For example:

```sh
./gentoc example.md
```

This will output the Table of Contents for `example.md`.

## Example

Given a markdown file `example.md` with the following content:

```markdown
# Main Title

## Introduction

## Usage

### Installation

### Running the Application

## Contributing

## License
```

Running `./gentoc example.md` will produce:

```markdown
- [Introduction](#introduction)
- [Usage](#usage)
  - [Installation](#installation)
  - [Running the Application](#running-the-application)
- [Contributing](#contributing)
- [License](#license)
```

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request for any improvements or bug fixes.

## License

This project is licensed under the MIT License. See the [`LICENSE`](LICENSE) file for details.
