COMPILER := gcc
COVERAGE := gcov

DEBUG_FLAGS := -std=c99 -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -g3 --coverage
RELEASE_FLAGS := -std=c99 -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -O3
SAN_FLAGS := -std=c99 -Weverything -fcolor-diagnostics -Wno-used-but-marked-unused -Wno-declaration-after-statement -Wno-missing-prototypes
CHECK_FLAGS := -lcheck -lpthread -lrt

APP := app.exe
UNIT := unit_tests.exe
UNIT_TESTS_PATH := ../lab_10_03_common
SOURCE_PATH := .
HEADERS_PATH := ../lab_10_03_common

SHELL := /bin/sh
OUT := out
$(shell mkdir -p $(OUT))

OBJECT_FILES := $(OUT)/associative_array_impl_1.o
CHECK_OBJECT_FILES := $(OUT)/check_main.o $(OUT)/check_insert.o $(OUT)/check_find.o $(OUT)/check_remove.o $(OUT)/check_clear.o $(OUT)/check_each.o $(OUT)/check_min.o $(OUT)/check_max.o $(OUT)/associative_array_impl_1.o


# BUILD

$(APP): $(OBJECT_FILES)
	$(COMPILER) $(OBJECT_FILES) -o $@ -lm $(COMPILER_FLAGS)

$(OUT)/%.o: $(SOURCE_PATH)/%.c $(HEADERS_PATH)/associative_array.h
	$(COMPILER) -I $(HEADERS_PATH) -c $< -o $@ $(COMPILER_FLAGS)


# UNIT TESTING

.PHONY: unit unit2

unit: unit.lastbuildstate | $(UNIT)
	./$(UNIT)

unit2: CHECK_FLAGS += -lsubunit
unit2: unit.lastbuildstate | $(UNIT)
	valgrind --leak-check=yes --track-origins=yes -q ./$(UNIT)

$(UNIT): COMPILER_FLAGS := $(DEBUG_FLAGS)
$(UNIT): $(CHECK_OBJECT_FILES)
	$(COMPILER) $(CHECK_OBJECT_FILES) -I $(HEADERS_PATH) -o $@ $(CHECK_FLAGS) -lm $(COMPILER_FLAGS)

$(OUT)/check_%.o: $(UNIT_TESTS_PATH)/check_%.c
	$(COMPILER) -I $(HEADERS_PATH) -c $< -o $@ $(COMPILER_FLAGS)


# CLEAN

.PHONY: clean

clean:
	rm -rf *.o *.exe *.gcno *.gcda *.gcov *.lastbuildstate tmp.txt
	rm -rf $(OUT)


# BUILD STATE

.NOTPARALLEL: *.lastbuildstate

%.lastbuildstate:
	rm -rf *.lastbuildstate tmp.txt
	touch $@
