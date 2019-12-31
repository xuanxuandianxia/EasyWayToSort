CC = g++ -o
all:
	$(CC)  random random.cpp
	$(CC)  sort sort.cpp
clean:
	rm random sort random_num.txt Sorted_num.txt
