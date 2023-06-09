// Later I'll do optimisation by charging graphic card to do calculus with Vulcan

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <limits.h>
#include "nani_matrix.h"

#define SLOG_OUT logging_file
#include "../slog/slog.h"

extern FILE* logging_file;

struct matrix_s {
	float **pp;
	int h, w;
};

// Verified
void naniDestroyMatrix (NaniMatrix *mp) {
	if (!mp) return;
	for (int i = 0; i < mp->h; i++) {
		if (!mp->pp[i]) break;

		free (mp->pp[i]);
	}

	free (mp);
	mp = NULL;
}

// Verified
NaniMatrix *naniCreateMatrix (int h, int w) {
	NaniMatrix *retval = malloc (sizeof(NaniMatrix));
	if (!retval) goto _bailout;

	retval->h = h;
	retval->w = w;

	retval->pp = malloc (h*sizeof(float*));
	if (!retval->pp) goto _bailout;
	bzero (retval->pp, h*sizeof(float*));

	for (int i = 0; i < h; i++) {
		retval->pp[i] = malloc (w*sizeof(float));
		if (!retval->pp[i]) goto _bailout;
		bzero (retval->pp[i], w*sizeof(float));
	}

	return retval;

_bailout:
	naniDestroyMatrix (retval);
	return NULL;
}

// Verified
void naniPrintMatrix (NaniMatrix const *mp) {
	if (!mp) {
		printf ("Matrix is not allocated!\n");
		return;
	}

	for (int i = 0; i < mp->h; i++) {
		float *p = mp->pp[i];
		if (!p) {
			printf ("row %d is not allocated!\n", i);
			return;
		}
		putchar ('|');
		for (int j = 0; j < mp->w; j++) {
			printf ("%.2f ", p[j]);
	}
		printf ("|\n");
	}
}

// Verified
float naniGetMatrixValue (NaniMatrix *mp, int x, int y) {
	if (x >= mp->w || y >= mp->h) return INT_MIN;
	return (mp->pp[y])[x];
}

// Verified
void naniSetMatrixValue (NaniMatrix *mp, int x, int y, float f) {
	if (x >= mp->w || y >= mp->h) return;
	(mp->pp[y])[x] = f;
}

// Verified
float *naniMatrixVectorProduct (NaniMatrix const *mp, float *fp) {
	const int size = sizeof(float)*mp->h;
	float *retval = malloc (size);
	if (!retval) {
		goto _bailout;
	}
	bzero (retval, size);
	for (int i = 0; i < mp->h; i++) {
		for (int j = 0; j < mp->w; j++) {
			retval[i] += (mp->pp[i])[j] * fp[j];
		}
	}

_bailout:
	return retval;
}

NaniMatrix *naniMatricesProduct (NaniMatrix m1, NaniMatrix m2) {
	NaniMatrix *mp = malloc (sizeof(float)*m1->h*m2->w);
	bzero
}
