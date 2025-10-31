typedef int vertex; // Define o tipo vertex como int
class Graph {
	private:
	 int V;
	 int A;
	public:
	 int **adj;
	 int **dist;
	 int *grau;
	 Graph(); // Método construtor da classe Graph
	 ~Graph(); // Método destrutor da classe Graph
	 void Gera_Matriz_Adj (int l, int c, int **m);
	 void NArestas (int l, int c);
	 int Ent_Grafo (int **Md,char Arq[30]);
 	 void Insere_Arco (int v, int w, int pe);
 	 void Remove_Arco (int v, int w);
	 void Mostra_Grafo();
	 void Imprime_Matriz (int n, int tipo);
	 int Menu_Grafo();
	 void GrauG(int n);
	 void MostraGrauG(int n);
	 int **Aloca_MatrizInt(int l, int c, int **m); //função auxiliar

 };
 
 	 



