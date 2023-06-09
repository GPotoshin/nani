#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <strings.h> // for bzero


// done
int xor (int a, int b) {
	return (a || b) && !(a && b);
}

// --- Implemantation of matrices --- //

typedef struct Ma



// --- end of imp of matices --- //

// --- Implementation of Neural network --- //

typedef struct {
	int siglen;
	int *sig;

	Matrix **mpp;
} NeuralNetwork;

// done
void destroyNeuralNetwork (NeuralNetwork *nnp) {
	if (!nnp->sig) return;
	free (nnp->sig);
	if (!nnp->mpp) return;
	for (int i = 0; i < nnp->siglen-1; i++) {
		Matrix *mp = nnp->mpp[i];
		if (!mp) return;
		destroyMatrix (mp);
	}
	free (nnp->mpp);
}

// done
NeuralNetwork *createNeuralNetwork (int *sig, int siglen) {
	NeuralNetwork *retval = malloc (sizeof(NeuralNetwork));

	retval->siglen = siglen;
	retval->sig = malloc (sizeof(int)*siglen);

	for (int i = 0; i < siglen; i++) retval->sig[i] = sig[i];

	retval->mpp = malloc (sizeof(Matrix*)*(siglen-1));
	for (int i = 0; i < siglen - 1; i++) {
		retval->mpp[i] = createMatrix (sig[i+1], sig[i]);
	}
	return retval;
}

// done
void printNeuralNetwork (NeuralNetwork const *nnp) {
	for (int i = 0; i < nnp->siglen - 1; i++) {
		Matrix *mp = nnp->mpp[i];
		printf ("level %d, Matrix[%dx%d]:\n", i+1, nnp->sig[i], nnp->sig[i+1]);
		printMatrix (mp);
		putchar ('\n');
	}
}

// not tested yet
float *computeNeuralNetwork (NeuralNetwok const *nnp, float *input) {
	float *res;
	for (int i = 0; i < nnp->siglen-1; i++) {
		res = matrixVectorProduct (nnp->mp[i], input);
		free (input);
		for (int j = 0; j < sig[i+1]; j++) {
			res[j] = sigmoid(res[j]);
		}
		input = res;
	}
	return res;
}

// done 
float sigmoid (float f) {
	return 1 / (1 + exp (-f));
}

// inspired by physics
float phmsq (float *arr, int len) {
	float retval = 0;
	for (int i = 0; i < len; i++) {
		retval += arr[i]*arr[i];
	}
	retval /= len;
	retval /= len - 1;

	retval = sqrt (retval);
	return retval;
}

// --- end of imp of Neural network --- //


void trainNeuralNetwork(NeuralNetwork *nnp, matrix *data, int n) {
	for (int i = 0; i < n; i++) {
		float *dif = {0, 0, 0, 0};
		for (int j = 0; j < data->h; j++) {
			float * input = data->data[j];
			float *res = computeNeuralNetwork (nnp, input);
			dif[0] = *res - 0;
			free (res);

		}
		float e = phmsq (dif, );
	}
}

void setData (matrix * data) {
	(data->data[0])[0] = 0;
	(data->data[0])[1] = 0;
	(data->data[0])[2] = 0;
	(data->data[1])[0] = 0;
	(data->data[1])[1] = 1;
	(data->data[1])[2] = 1;
	(data->data[2])[0] = 1;
	(data->data[2])[1] = 0;
	(data->data[2])[2] = 1;
	(data->data[3])[0] = 1;
	(data->data[3])[1] = 1;
	(data->data[3])[2] = 0;
}

void setNeuralNetwork (NeuralNetwork * nnp) {
	for (int i = 0; i < nnp->siglen-1; i++) {
		matrix * mp = nnp->mpp[i];
		for (int j = 0; j < nnp->sig[i+1]; j++) {
			for (int k = 0; k < npp->sig[i]; k++) {
				(mp[j])[k] = 0.1 * (rand() % 11);
			}
		}
	}
}


// ---- Local Program functions ---- //
int main () {
	srand(time(NULL));
	int sig[3] = {2, 3, 1};
	NeuralNetwork * nnp = createNeuralNetwork (sig, 3);
	Matrix * data = createMatrix (4, 3);
	setData (data);
	setNeuralNetwork (nnp);
	trainNeuralNetwork (nnp, data, 10000);
	printNeuralNetwork (nnp);
	destroyNeuralNetwork ();
	return 0;
}
