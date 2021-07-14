PROJ_NAME = Voting
BUILD_DIR = build
INC_H = -Iinc\
-Iunity\

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

coverageCheck:$(BUILD)
	gcc -fprofile-arcs -ftest-coverage -fPIC -O0  $(INC_H) $(SRC) -o $(TEST_OUTPUT)
	./$(TEST_OUTPUT)



$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
	$(RM) $(call FixPath,$(BUILD_DIR)/*)
	rmdir $(BUILD_DIR)