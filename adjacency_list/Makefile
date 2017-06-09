build:
	gcc -D DEBUG -o alTest.run -O3 test.c -lm
	gcc -D DEBUG -o alTestDFS.run -O3 test_dfs.c -lm
	gcc -D DEBUG -o alTestBFS.run -O3 test_bfs.c -lm
run: build
	./alTest.run
