typedef struct poly *Poly;// handle ¾ä±ú
void POLYshow(Poly);
Poly POLYterm(int, int);
Poly POLYadd(Poly, Poly);
Poly POLYmult(Poly, Poly);
float POLYeval(Poly, float); 
