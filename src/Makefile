CC = gcc
CCFLAGS = -Wall -Wextra -std=c11
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
LDFLAGS = -lcheck -lsubunit -lm
RM = rm -rf

# Используйте LCOV для генерации отчетов
LCOV = $(shell which lcov || echo ~/.local/bin/lcov)
GCOV_REPORT_GEN = $(shell which genhtml || echo ~/.local/bin/genhtml)

# имя библиотеки
LIB_NAME = s21_matrix.a
# имя тестового файла
TEST_NAME = s21_matrix_test
# имя тестового файла c тестами покрытия кода gcovr
TESTS_LCOV_NAME = s21_matrix_gcov


# файлы и директории функций библиотек
DIR = ./
HEADER_NAME = s21_matrix.h
SOURCES = $(wildcard $(DIR)*.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))

# файлы и директории тестов
TEST_DIR = tests/
TEST_HEADER_NAME = $(TEST_DIR)s21_test.h
TEST_SRC = $(wildcard $(TEST_DIR)*.c)
TEST_OBJ = $(patsubst %.c, %.o, $(TEST_SRC))
COVDIR = test_info
COV_INFO = test.info
COV_REPORT_DIR = report


all:$(LIB_NAME)

$(LIB_NAME):$(OBJECTS)
	ar rc $@ $^
	ranlib $@

%.o:%.c
	$(CC) $(CCFLAGS) -c $< -o $@

test: clean $(TEST_NAME)
	./$(TEST_NAME)

$(TEST_NAME): $(TEST_OBJ) $(LIB_NAME)
	$(CC) $(CCFLAGS) $(OBJECTS) $(TEST_OBJ) -L. -l:$(LIB_NAME) -o $@ $(LDFLAGS)

gcov_report: clean
	$(CC) $(CCFLAGS) $(GCOV_FLAGS) $(TEST_SRC) $(SOURCES) $(LDFLAGS) -o $(TESTS_LCOV_NAME)
	./$(TESTS_LCOV_NAME)
	$(LCOV) -t "$(TESTS_LCOV_NAME)" -o $(COV_INFO) -c -d .
	$(LCOV) --remove $(COV_INFO) '*/tests/*' --output-file $(COV_INFO)
	$(GCOV_REPORT_GEN) -o $(COV_REPORT_DIR) $(COV_INFO)

clean: clean_report
	$(RM) $(TESTS_LCOV_NAME)
	$(RM) $(TEST_NAME)
	$(RM) $(LIB_NAME)
	$(RM) $(OBJECTS)
	$(RM) $(TEST_OBJ)

clean_report:
	$(RM) $(COV_REPORT_DIR)
	$(RM) *.gcda *.gcno
	$(RM) $(TEST_DIR)*.gcda $(TEST_DIR)*.gcno
	$(RM) $(COV_INFO)
	
clang:
	cp ../materials/linters/.clang-format ./
	clang-format -n $(DIR)*.c *.h
	clang-format -n $(TEST_DIR)*.c $(TEST_DIR)*.h
	$(RM) .clang-format

clangi:
	cp ../materials/linters/.clang-format ./
	clang-format -i $(DIR)*.c *.h
	clang-format -i $(TEST_DIR)*.c $(TEST_DIR)*.h
	$(RM) .clang-format

val: clean $(TEST_NAME)
	valgrind --tool=memcheck --leak-check=yes --quiet ./$(TEST_NAME)

cpp:
	cppcheck --enable=all --check-config --suppress=missingIncludeSystem $(shell find . -name "*.c")
	cppcheck --enable=all --check-config --suppress=missingIncludeSystem $(shell find . -name "*.h")
