compile:
	@gcc -Wall src/linked_list/pure.c src/linked_list/typed.c src/main.c -o out

run: compile
	@./out