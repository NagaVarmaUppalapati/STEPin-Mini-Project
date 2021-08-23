# Name of the project
PROJECT_NAME = dvd

# Output directory
BUILD = build

# All source code files
SRC = dvdmain.c

# All test source files
TEST_SRC = src/dvd.c test/test.c unity/unity.c

TEST_OUTPUT = $(BUILD)/Test_$(PROJECT_NAME).exe

# All include folders with header files

INC	= -Iinc\

TEST_INC	= -Iinc\
-Iunity\

#To check if the OS is Windows or Linux and set the executable file extension and delete command accordingly
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
# Run the target even if the matching name exists

all:$(BUILD_DIR)
	gcc $(INC) $(SRC) -o $(call FixPath,$(BUILD)/$(PROJECT_NAME).$(EXEC))

# Call `make run` to run the application

run: all
	$(call FixPath,$(BUILD)/$(PROJECT_NAME).$(EXEC))



# Build and run the unit tests
test:$(BUILD)
	gcc $(TEST_SRC) $(TEST_INC) -o $(TEST_OUTPUT)
	./$(TEST_OUTPUT)
#Coverage
coverageCheck:${PROJECT_NAME} $(BUILD)
	gcc -fprofile-arcs -ftest-coverage -fPIC  $(TEST_SRC) $(INC) -o $(TEST_OUTPUT)
	./$(TEST_OUTPUT)
	gcov -a $(SRC) -o .

# Remove all the built files, invoke by `make clean`
clean:
	$(RM) $(BUILD)
	$(RM) *.gcda 
	$(RM) *.gcno
	$(RM) *.gcov

# Create new build folder if not present
$(BUILD):
	mkdir build