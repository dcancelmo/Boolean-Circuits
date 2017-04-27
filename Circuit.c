/*
 * Circuit.c
 * Creator: George Ferguson
 * Created: Sun Nov 27 14:08:51 2016
 */
#include <stdio.h>
#include <stdlib.h>
#include "Circuit.h"

typedef struct Circuit {
	int numInputs;
	Value** inputs;
	int numOutputs;
	Value** outputs;
	int numGates;
	Gate** gates;
} Circuit;

/**
 * Topologically sort the given array of gates using the condition that if
 * the output of gate i feeds an input of gate j, then i < j.
 * Destructively modifies the given array (could be otherwise with some work).
 * @see https://en.wikipedia.org/wiki/Topological_sorting
 */
static Gate** topsort(int ngates, Gate** gates) {
	// Insertion sort good enough for us...
	for (int i=1; i < ngates-1; i++) {
		int j = i;
		while (j > 0 && Gate_feedsInto(gates[j], gates[j-1])) {
			Gate *tmp = gates[j];
			gates[j] = gates[j-1];
			gates[j-1] = tmp;
			j = j - 1;
		}
	}
	return gates;
}

Circuit *new_Circuit(int numInputs, Value** inputs, int numOutputs, Value** outputs, int numGates, Gate** gates) {
	Circuit* this = (Circuit*)malloc(sizeof(Circuit));
	this->numInputs = numInputs;
	this->inputs = inputs;
	this->numOutputs = numOutputs;
	this->outputs = outputs;
	this->numGates = numGates;
	this->gates = topsort(numGates, gates);
	return this;
}

void Circuit_update(Circuit* this) {
	for (int i=0; i < this->numGates; i++) {
		Gate_update(this->gates[i]);
	}
}

int Circuit_numInputs(Circuit* this) {
	return this->numInputs;
}

Value** Circuit_getInputs(Circuit* this) {
	return this->inputs;
}

void Circuit_setInput(Circuit* this, int index, bool value) {
	Value_setValue(this->inputs[index], value);
}

int Circuit_numOutputs(Circuit* this) {
	return this->numOutputs;
}

Value** Circuit_getOutputs(Circuit* this) {
	return this->outputs;
}

bool Circuit_getOutput(Circuit* this, int index) {
	return Value_getValue(this->outputs[index]);
}

int Circuit_numGates(Circuit* this) {
	return this->numGates;
}

void Circuit_dump(Circuit* this) {
	printf("Gates:\n");
	for (int i=0; i < this->numGates; i++) {
		printf("  %d: ", i);
		Gate_print(this->gates[i]);
		printf("\n");
	}
	printf("Inputs:\n");
	for (int i=0; i < this->numInputs; i++) {
		printf("  %d: ", i);
		Value_print(this->inputs[i]);
		printf("\n");
	}
	printf("Outputs:\n");
	for (int i=0; i < this->numOutputs; i++) {
		printf("  %d: ", i);
		Value_print(this->outputs[i]);
		printf("\n");
	}
}
