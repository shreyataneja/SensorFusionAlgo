CC=g++
CFLAGS = -c -std=c99
CUNIT = -lcunit

#CREATE BIN AND BUILD FOLDERS TO SAVE THE COMPILED FILES DURING RUNTIME
bin_folder := $(shell mkdir -p bin)
build_folder := $(shell mkdir -p build)

#TARGET TO COMPILE ALL THE TESTS TOGETHER 

test_main.o: src/test_main.c
	$(CC) -g -c  src/test_main.c -o build/test_main.o $(CUNIT)
	
test_sensor_fusion.o: src/test_sensor_fusion.c
	$(CC) -g -c src/test_sensor_fusion.c -o build/test_sensor_fusion.o $(CUNIT)


tests: test_main.o test_sensor_fusion.o
		$(CC) -g -o bin/TEST_MAIN build/test_main.o build/test_sensor_fusion.o  $(CUNIT) 

	
#TARGET TO COMPILE EVERYTHING
all: tests

#CLEAN COMMANDS
clean: 
	rm -f bin/* build/*