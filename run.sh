cmake . -B build  -DCMAKE_EXPORT_COMPILE_COMMANDS=ON &&
	cd build &&
	make &&
	cd bin &&
	sudo ./MotionSimulator $1 $2 &&
	cd ../
