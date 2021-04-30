whole:= main.o heap.o merge.o quick.o side_function.o
CFLAG:=-Wall -g -fsanitize=undefined -fsanitize=address -fsanitize=leak
all: $(whole) 				#Quickly check if all file are up to date
	@echo "gcc $(whole) -o main\n"
	@gcc $(CFLAG) $(whole) -o main 

main.o: main.c sorting.h
	@echo "gcc -c main.c\n"
	@gcc -c $(CFLAG) main.c
heap.o: heap.c sorting.h
	@echo "gcc -c heap.c\n"
	@gcc -c $(CFLAG) heap.c
merge.o: merge.c sorting.h
	@echo "gcc -c merge.c\n"
	@gcc -c $(CFLAG) merge.c
quick.o: quick.c sorting.h
	@echo "gcc -c quick.c\n"
	@gcc -c $(CFLAG) quick.c
side_function: sidefunction.c sorting.h
	@echo "gcc -c side_function.c\n"
	@gcc -c $(CFLAG) side_function.c

.PHONY = clean
clean:
	-rm -f $(whole) main 
#	'-' 在開頭表示，就算後面出錯，這樣執行這行指令
#	'@' 在開頭表示不想是這樣指令

#	$?：代表已被更新的 dependencies 的值。
#		也就是 dependencies 中，比 targets 還新的值。
#	$@：代表 targets 的值。
#	$<：代表第一個 dependencies 的值。
#	$* :代表 targets 所指定的檔案，但不包含副檔名。
