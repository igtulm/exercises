SHELL := /bin/bash
BIN ?= $(shell pwd)/bin

.PHONY: test clean cbench
all: build test

clean:
	@rm -rf $(BIN)/*

build:
	@cd c_binsearch && gcc -O3 -o $(BIN)/c_binsearch.o -c c_binsearch.c
	@cd $(BIN) && ar q libc_binsearch.a c_binsearch.o
	go build -o $(BIN)/go_binsearch

run:
	@$(BIN)/go_binsearch

cbench:
	@cd c_binsearch && gcc -O3 -o $(BIN)/cbench c_bench_binsearch.c c_binsearch.c && cd ..
	@printf "Benchmark from C:\n"
	@$(BIN)/cbench
	@rm -rf $(BIN)/cbench	

gobench:
	@printf "Benchmark from Go:\n"
	@go test -bench=. -benchmem

test: cbench gobench
