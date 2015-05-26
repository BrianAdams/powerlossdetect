powerdown: powerdown.cpp Makefile
	g++ powerdown.cpp -o powerdown ` pkg-config glib-2.0  --cflags --libs`
