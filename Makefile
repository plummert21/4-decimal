NAME_PROJECT = s21_decimal

# FOLDER_TEST_FILES  = $(NAME_PROJECT)_test_files
# FILE_OUT_TESTS = tests.out

FLAG = -Wall -Werror -Wextra -std=c11 -pedantic
GCC = gcc 
# LIBM = -lm
# LIBS = -lcheck $(LIBM) -lsubunit -lgcov
FILES_H = *.h
FILES_C = *.c
FILES_O = *.o
FILE_C = $(NAME_PROJECT).c
FILE_A = $(NAME_PROJECT).a
FILE_FORMATS_FOR_CLEAN = *.a *.o *.out *.gcda *.gcdo *.gcno *.css *.html
# GСOVFLAG = -coverage

# all: $(NAME_PROJECT).a

all: $(NAME_PROJECT).out
	rm -rf *.o

$(NAME_PROJECT).out: $(NAME_PROJECT).o
	$(GCC) $(FILES_O)

# $(NAME_PROJECT).a: $(NAME_PROJECT).o build_lib
# 	rm -rf *.o

# $(NAME_PROJECT).o:
# 	$(GCC) $(FLAG) -c $(FILES_C)

$(NAME_PROJECT).o:
	$(GCC) -c $(FILES_C)


# build_lib:
# 	ar rcs $(FILE_A) $(FILES_O)

# tests.out: $(NAME_PROJECT).a
# 	$(GCC) $(FOLDER_TEST_FILES)/$(FILES_C) $(FILE_C) -L. $(FILE_A) $(GСOVFLAG) $(LIBS) -o $(FILE_OUT_TESTS)

# test: tests.out
# 	./$(FILE_OUT_TESTS)

gcov_report: test
#   GCOVR INSTALL
#	pip install git+https://github.com/gcovr/gcovr.git	
#	~/.local/bin/gcovr -r . --html --html-details -o $(NAME_PROJECT).html
	gcovr -r . --html --html-details -o $(NAME_PROJECT).html
#	/opt/homebrew/bin/gcovr -r . --html --html-details -o $(NAME_PROJECT).html
	
gcov_html: gcov_report
	xdg-open $(NAME_PROJECT).html
#	open $(NAME_PROJECT).html

rebuild: clean all

clean: 
	rm -rf ${FILE_FORMATS_FOR_CLEAN}
	clear

test_all: cpp cl

cpp:
	cppcheck --enable=all --suppress=missingIncludeSystem --std=c11 $(FILES_C)
	cppcheck --enable=all --suppress=missingIncludeSystem --std=c11 $(FOLDER_TEST_FILES)/$(FILES_C)

cl:
	clang-format -n $(FILES_C)
	clang-format -n $(FOLDER_TEST_FILES)/$(FILES_C)
	clang-format -n $(FILES_H)
	clang-format -n $(FOLDER_TEST_FILES)/$(FILES_H)

cl-i:
	clang-format -i $(FILES_C)
	clang-format -i $(FOLDER_TEST_FILES)/$(FILES_C)
	clang-format -i $(FILES_H)
	clang-format -i $(FOLDER_TEST_FILES)/$(FILES_H)

val:
	valgrind --tool=memcheck --leak-check=yes ./$(FILE_OUT_TESTS)