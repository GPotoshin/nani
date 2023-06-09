#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix_s NaniMatrix;

void naniDestroyMatrix (NaniMatrix *mp);
NaniMatrix *naniCreateMatrix (int h, int w);
void NaniPrintMatrix (NaniMatrix const *mp);
float NaniGetMatrixValue (NaniMatrix *mp, int x, int y);
void NaniSetMatrixValue (NaniMatrix *mp, int x, int y, float f);
float *NaniMatrixVectorProduct (NaniMatrix const *mp, float *fp);

#endif /* MATRIX_H */
