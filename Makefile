f_debug := -g

f_base := -Wall \
			-Wconversion \
			-Wextra \
			-pedantic \
			-pedantic-errors \
			-Wpedantic \
			-Wformat=2 \
			-lcheck

f_suggest := -Wsuggest-attribute=pure \
					-Wsuggest-attribute=const \
					-Wsuggest-attribute=noreturn \
					-Wsuggest-attribute=format

f_std := -std=c99

GCC := gcc $(f_debug) $(f_base) $(f_suggest) $(f_std)

h_name := bsa
t_name := check_bsa
o_name := test

test:
	@$(GCC) -o $(o_name).out $(t_name).c $(h_name).c
	@./$(o_name).out
