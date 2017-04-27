/*
 * Gates.h
 * Creator: George Ferguson
 * Created: Sun Nov 27 14:08:51 2016
 */

#ifndef GATES_H_
#define GATES_H_

#include "Value.h"

typedef struct Gate Gate;

extern Gate** new_Gate_array(int len);

extern void Gate_update(Gate *this);
extern void Gate_print(Gate *this);
extern int Gate_numInputs(Gate* this);
extern Value* Gate_getInput(Gate* this, int index);
extern Value* Gate_getOutput(Gate* this);
extern bool Gate_hasInput(Gate* this, Value* value);
extern bool Gate_feedsInto(Gate* this, Gate* other);

extern Gate* new_Inverter(Value *input);
extern Gate* new_AndGate(Value *input1, Value *input2);
extern Gate* new_OrGate(Value *input1, Value *input2);
extern Gate* new_And3Gate(Value *input1, Value *input2, Value* input3);
extern Gate* new_Or4Gate(Value *input1, Value *input2, Value* input3, Value* input4);

#endif /* GATES_H_ */
