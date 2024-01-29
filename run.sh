cmake . -B build &&
	cd build &&
	make &&
	ls -la ./bin &&
	cd bin &&
	sudo ./MotionSimulator $1 &&
	cd ../
