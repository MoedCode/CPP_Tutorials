# commands.gdb
break 23
break 26
run
print i
print a
continue
define pai
    printf "i = %i ,a =  %i\n", i, a
end
define ab
    printf "a = %i ,b =  %i\n", a, b