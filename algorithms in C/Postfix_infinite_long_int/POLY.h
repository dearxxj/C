typedef struct poly *Poly;// handle ���
struct poly { int N; int *a; };
void POLYshow(Poly);
Poly POLYterm(int, int);
Poly POLYadd(Poly, Poly);
Poly POLYmult(Poly, Poly);
