CC ?= cc
CFLAGS ?= -std=c11 -Wall -Wextra -Werror -O2
JAVAC ?= javac
JAVA ?= java

BUILD_DIR := build
C_DEMOS := binary_search bsearch icmp linear_search quicksort scmp
C_TARGETS := $(addprefix $(BUILD_DIR)/,$(C_DEMOS))

.PHONY: all check

all: $(C_TARGETS) $(BUILD_DIR)/java_sort.class

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $<

$(BUILD_DIR)/java_sort.class: java_sort.java | $(BUILD_DIR)
	$(JAVAC) -d $(BUILD_DIR) $<

check: all
	python3 check.py $(BUILD_DIR)
