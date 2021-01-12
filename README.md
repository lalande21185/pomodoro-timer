




# Pomodoro timer for linux

> :information_source:	This was initially a little project for my personal use. Please know what you are doing if you wish to install it. The next step would be to make it more comprehensive and easier to install.

## Features

* 25 minutes
* Pause
* Start
* Reset
* Can be set to always be on top of all windows.


### Compiling

Assuming you are in the directory containing the `main.c`, run the following:

```
gcc-9 `pkg-config --cflags gtk+-3.0` -o main main.c `pkg-config --libs gtk+-3.0` -rdynamic -g -Wall
```

And then, launch the application with:

```
./main
```


### Installing

> :information_source:	Please make sure you understand what you are doing.

Locate the file `src/frontend/frontend.c`, and change the path of the view.glade and style.css files to where they will be moved to on your machine.

For example, on my machine,
`"src/frontend/view.glade"` needs to be changed to `"/usr/local/share/main/view.glade"` and `"src/frontend/style.css"` needs to be changed to `"/usr/local/share/main/style.css"`.

Assuming you are in the directory containing the `main.c`, run the following:

```
./configure
make
sudo make install
```

## Uninstalling

Assuming you are in the directory containing the `main.c`, run the following:

```
make clean
sudo make uninstall
```

## Built With

* C Language
* GNU Compiler
* GTK
* Glade

## Contributing

Contribution of any sort will be really appreciated :slightly_smiling_face:.

## Author

[lalande21185](https://github.com/lalande21185)


## License

Licensed under the GPLv3. See the LICENSE file for details.

Copyright 2021 [lalande21185](https://github.com/lalande21185)

