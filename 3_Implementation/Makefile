# Name of the project
PROJ_NAME = Voting
# Output directory
BUILD_DIR = build

# All include folders with header files
INC_H = -Iinc\
-Iunity\

# All source code files
SRC = voting.c\
src/heading.c\
test/test.c\
unity/unity.c

#To check if the OS is windows or linux and set the executable file extension and delete command accordingly
ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif

TEST_OUTPUT = $(BUILD_DIR)/$(PROJ_NAME).out

all:$(BUILD_DIR)
	gcc $(INC_H) $(SRC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

run: all
	$(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

test:$(BUILD)
	gcc $(INC_H) $(SRC) -o $(TEST_OUTPUT)
	./$(TEST_OUTPUT)

valgrind:$(BUILD)
	valgrind ./$(TEST_OUTPUT)

coverage:$(SRC)
	gcc -fprofile-arcs -ftest-coverage $(SRC) $(INC_H) -o $(TEST_OUTPUT)
	./$(TEST_OUTPUT)
	gcov -a Voting.c


# Remove all the built files, invoke by `make clean`
$(BUILD_DIR):
	mkdir $(BUILD_DIR)

# Remove all the built files, invoke by `make clean`
clean:
	$(RM) $(call FixPath,$(BUILD_DIR)/*)
	rmdir $(BUILD_DIR)
	rm -rf *.gcda *.gcno *.gcov
