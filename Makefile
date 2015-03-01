all: 
	g++ led-clock.cpp -o example -F/Library/Frameworks -framework Phidget21 -I/Library/Frameworks/Phidget21.framework/Headers