

all: bfs_impl.so dfs

bfs_impl.so: bfs_impl.cc dfs.h
	g++ -shared -fPIC -o $@ bfs_impl.cc

dfs: dfs.cc
	g++ -o $@ $^ -ldl

clean:
	rm -rf bfs_impl.so dfs
