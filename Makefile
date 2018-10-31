f_debug := -g

f_base := -Wall \
			-Wextra \
			-pedantic \
			-lcheck

f_suggest := -Wsuggest-attribute=pure \
					-Wsuggest-attribute=const \
					-Wsuggest-attribute=noreturn \
					-Wsuggest-attribute=format

f_std := -std=c99

f_sec := -Wformat-security \
			-Wstack-protector

GCC := gcc $(f_debug) $(f_base) $(f_suggest) $(f_std) $(f_sec)

h_name := bsa
t_name := check_bsa
o_name := test

test:
	@$(GCC) -o $(o_name).out $(t_name).c
	@./$(o_name).out
