all:
	gcc -D DEBUG -o build/alTest.run -O3 test/test.c -lm -I src/
	gcc -D DEBUG -o build/alTestDFS.run -O3 test/test_dfs.c -lm -I src/
	gcc -D DEBUG -o build/alTestBFS.run -O3 test/test_bfs.c -lm -I src/
	gcc -D DEBUG -o build/alTestQueue.run -O3 test/test_queue.c -lm -I src/
run:
	./build/alTest.run 
	./build/alTestDFS.run 
	./build/alTestBFS.run 
	./build/alTestQueue.run
