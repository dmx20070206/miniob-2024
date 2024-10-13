BUILD_DIR:= build_debug
SRC_DIR := src


all: fmt
	@echo "Building..."
	@bash build.sh --make -j20

run: all
	@echo "Running..."
	@cd $(BUILD_DIR) && ./bin/observer -f ../etc/observer.ini -P cli

clean:
	@echo "Cleaning..."
	@rm -rf $(BUILD_DIR)

fmt:
	@echo "Formatting source files..."
	@find $(SRC_DIR) \( -name '*.c' -o -name '*.h' -o -name '*.cpp' -o -name '*.hpp' \) \
		-not \( -name 'lex_sql*' -o -name 'yacc_sql*' \) \
		-print0 | xargs -0 clang-format -i
	@echo "Formatting complete."

.PHONY: all run clean fmt