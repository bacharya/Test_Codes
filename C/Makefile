CFLAGS =-g
LDLIBS =-lm

tree: b_tree.o tree.h b_tree.h avl_tree.h tree.c avl_tree.c 
	cc -g -o tree b_tree.o avl_tree.o tree.c $(LDLIBS)

avl: avl_tree.o tree.h b_tree.h avl_tree.h tree.c avl_tree.c
avl_clean:
	rm avl_tree.o

tree_clean:
	rm tree b_tree.o

queue: queue.o queue.h queue.c
	cc -g -o queue queue.o queue_main.c
queue_clean:
	rm queue queue.o

stack: stack.o stack.h stack.c
	cc -g -o stack stack.o
stack_clean:
	rm stack stack.o

timer: test_timer.o test_timer.h test_timer.c
	cc -g -o timer test_timer.o
timer_clean:
	rm timer test_timer.o

heap: heap.o heap.c
	cc -g -o heap heap.o
heap_clean:
	rm heap heap.o

hash: hash.o hash.h hash.c
	cc -g -o hash hash.o prime.o
hash_clean:
	rm hash hash.o

prime: prime.o prime.h prime.c
	cc -g -o prime prime.o
prime_clean:
	rm prime prime.o
