typedef struct poly *Poly;// handle ¾ä±ú
struct poly { int N; int *a; };
void POLYshow(Poly);
Poly POLYterm(int, int);
Poly POLYadd(Poly, Poly);
Poly POLYmult(Poly, Poly);
