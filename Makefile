NAME_PROJECT = s21_decimal

FOLDER_TEST_FILES  = tests

# FLAG = -Wall -Werror -Wextra -std=c11 -pedantic
GCC = gcc 
LIBS = -lcheck -lsubunit -lgcov -lm
FILES_H = *.h
FILES_C = *.c
FILES_O = *.o
TEST_FILES := $(wildcard $(FOLDER_TEST_FILES)/s21_test_*.c)
FILE_C = $(NAME_PROJECT).c
FILE_A = $(NAME_PROJECT).a
FILE_FORMATS_FOR_CLEAN = *.a *.o *.out *.gcda *.gcdo *.gcno *.css *.html
GСOVFLAG = -coverage

#all: $(NAME_PROJECT).a
all: gcov_html
# all:
# 	gcc *.c
# 	./a.out
# 	rm a.out

$(NAME_PROJECT).a: $(NAME_PROJECT).o build_lib
	rm -rf *.o

$(NAME_PROJECT).o:
	$(GCC) $(FLAG) -c $(FILES_C)

build_lib:
	ar rcs $(FILE_A) $(FILES_O)

tests.out: $(NAME_PROJECT).a
	$(foreach test_file, $(TEST_FILES), \
		$(GCC) $(basename $(test_file)).c $(FILES_C) -L. $(FILE_A) $(GСOVFLAG) $(LIBS) -o $(basename $(test_file)).out;)

test: tests.out
	$(foreach test_file, $(TEST_FILES), \
		./$(basename $(test_file)).out;)

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
	$(foreach file_format, $(FILE_FORMATS_FOR_CLEAN), \
		rm -rf $(FOLDER_TEST_FILES)/${file_format};)	
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
	$(foreach test_file, $(TEST_FILES), \
		valgrind --tool=memcheck --leak-check=yes ./$(basename $(test_file)).out;)