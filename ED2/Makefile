abbc:
	@gcc  ./arvores/arvore.c main.c -o abbmain.run -Wall -g -s
	@echo "use abbmain.run"

avlc:
	@gcc ./arvores/AVL_Tree.c main.c -o avlmain.run -Wall -g -s

treemd: # estrutura de arvore da maria adriana
	@gcc -Wall -g -s -c ./arvores/cod_prof/avrbinbusca.c -o avrbinbusca.o
	@gcc -Wall -g -s -c ./arvores/cod_prof/fila.c -o fila.o
	@gcc -Wall -g -s -c ./arvores/cod_prof/main.c -o main.o
	@gcc -Wall -g -s -o treemd.run avrbinbusca.o fila.o main.o
	@echo "use valgrind --leak-check=full ./treemd.run para executar"

clean:
	@rm *.o *.run