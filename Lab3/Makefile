.PHONY: build

build:
	g++ ./cmd_parse_app.cpp -o parse_app

default_goal: build def 
.PHONY: def
def:
	./parse_app -h -v -l -d -c -b -V1000


.DEFAULT_GOAL:=default_goal
