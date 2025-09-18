CC=g++
CFLAGS= -Wshadow \
		-Winit-self \
		-Wredundant-decls \
		-Wcast-align \
		-Wundef \
		-Wfloat-equal \
		-Winline \
		-Wunreachable-code \
		-Wmissing-declarations \
		-Wmissing-include-dirs \
		-Wswitch-enum\
		-Wswitch-default \
		-Weffc++ \
		-Wmain \
		-Wextra \
		-Wall \
		-g \
		-pipe \
		-fexceptions \
		-Wcast-qual \
		-Wconversion \
		-Wctor-dtor-privacy \
		-Wempty-body \
		-Wformat-security \
		-Wformat=2 \
		-Wignored-qualifiers \
		-Wlogical-op \
		-Wno-missing-field-initializers \
		-Wnon-virtual-dtor \
		-Woverloaded-virtual \
		-Wpointer-arith \
		-Wsign-promo \
		-Wstack-usage=8192 \
		-Wstrict-aliasing \
		-Wstrict-null-sentinel \
		-Wtype-limits \
		-Wwrite-strings \
		-Werror=vla \
		-D_EJUDGE_CLIENT_SIDE \
		-I.

INCL = -IC:/Users/bossb/OneDrive/Desktop/ded/TXLib-master \
		-IC:/Users/bossb/CLionProjects/Onegin/src \
		-IC:/Users/bossb/CLionProjects/Onegin/src/sorter \
		-IC:/Users/bossb/CLionProjects/Onegin/src/tests \
		-IC:/Users/bossb/CLionProjects/Onegin/src/sorter/pointer_array \
		-IC:/Users/bossb/CLionProjects/Onegin/src/sorter/pointer_array/buffer_version \
		-IC:/Users/bossb/CLionProjects/Onegin/src/sorter/square_array \
		-IC:/Users/bossb/CLionProjects/Onegin/src/reader

DEPS =  src/sorter/sorter.h \
        src/tests/tests.h \
		src/reader/line_reader.h \
		src/sorter/pointer_array/buffer_version/pointer_array_buf.h \
		src/sorter/square_array/square_array.h

SRC = src/reader/line_reader.cpp \
	  src/tests/tests.cpp \
	  src/sorter/sorter.cpp \
	  src/sorter/pointer_array/pointer_array.cpp \
	  src/sorter/pointer_array/buffer_version/pointer_array_buf.cpp \
	  src/sorter/square_array/square_array.cpp \
	  src/main.cpp

test: $(SRC)
	$(CC) -o make_output/$@ $(CFLAGS) $(INCL) $^ -DDEBUG -DTESTS

build: $(SRC)
	$(CC) -o make_output/$@ $(INCL) -w $^

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $(CFLAGS) $<
