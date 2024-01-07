COMPILER := gcc
COVERAGE := gcov

DEBUG_FLAGS := -std=c99 -Werror -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -g3
RELEASE_FLAGS := -std=c99 -Werror -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -O3
SAN_FLAGS := -std=c99 -Weverything -fcolor-diagnostics -Wno-used-but-marked-unused -Wno-declaration-after-statement -Wno-missing-prototypes
CHECK_FLAGS := -lcheck -lpthread -lrt

APP := app.exe
UNIT := unit_tests.exe
FUNC_TESTS_PATH := func_tests
UNIT_TESTS_PATH := unit_tests
SOURCE_PATH := src
HEADERS_PATH := inc

SHELL := /bin/sh
OUT := out
$(shell mkdir -p $(OUT))

LIB_FILES := libarray.so
CHECK_OBJECT_FILES := $(OUT)/check_main.o $(OUT)/check_array.o


# BUILD

.PHONY: release debug san

release: COMPILER_FLAGS := $(RELEASE_FLAGS)
release: release.lastbuildstate | $(APP)

debug: COMPILER_FLAGS := $(DEBUG_FLAGS)
debug: debug.lastbuildstate | $(APP)

san: COMPILER := clang
san: COMPILER_FLAGS := $(SAN_FLAGS)
san: san.lastbuildstate | $(APP)

$(APP): $(OUT)/main.o $(LIB_FILES)
	$(COMPILER) $^ -L. -Wl,-rpath,. -o $@ -lm $(COMPILER_FLAGS)

lib%.so: $(OUT)/%.o
	$(COMPILER) -shared -o $@ $<

$(OUT)/main.o: $(SOURCE_PATH)/main.c
	$(COMPILER) -I $(HEADERS_PATH) -c $< -o $(OUT)/main.o $(COMPILER_FLAGS)

$(OUT)/%.o: $(SOURCE_PATH)/%.c $(HEADERS_PATH)/%.h
	$(COMPILER) -I $(HEADERS_PATH) -c -fPIC $< -o $@ $(COMPILER_FLAGS)


# FUNC TESTING

.PHONY: func func2 check-scripts

func: debug
	$(FUNC_TESTS_PATH)/scripts/func_tests.sh

func2: debug
	$(FUNC_TESTS_PATH)/scripts/func_tests.sh --memcheck -v

check-scripts:
	shellcheck $(FUNC_TESTS_PATH)/scripts/*.sh


# UNIT TESTING

.PHONY: unit unit2

unit: unit.lastbuildstate | $(UNIT)
	./$(UNIT)

unit2: CHECK_FLAGS += -lsubunit
unit2: unit.lastbuildstate | $(UNIT)
	valgrind --leak-check=yes --track-origins=yes -q ./$(UNIT)

$(UNIT): COMPILER_FLAGS := $(DEBUG_FLAGS)
$(UNIT): $(CHECK_OBJECT_FILES) $(LIB_FILES)
	$(COMPILER) $^ -L. -Wl,-rpath,. -o $@ $(CHECK_FLAGS) -lm $(COMPILER_FLAGS)

$(OUT)/check_%.o: $(UNIT_TESTS_PATH)/check_%.c
	$(COMPILER) -I $(HEADERS_PATH) -c $< -o $@ $(COMPILER_FLAGS)


# CLEAN

.PHONY: clean

clean:
	rm -rf *.o *.exe *.so *.gcno *.gcda *.gcov *.lastbuildstate tmp.txt
	rm -rf $(OUT)


# BUILD STATE

.NOTPARALLEL: *.lastbuildstate

%.lastbuildstate:
	rm -rf $(OUT)/* *.lastbuildstate tmp.txt
	touch $@
