/*
 * File: main.c
 * Creator: George Ferguson
 * Created: Mon Nov 28 14:11:17 2016
 * Time-stamp: <Mon Nov 28 14:22:27 EST 2016 ferguson>
 */
#include <stdio.h>
#include <stdlib.h>
#include "Circuit.h"

/**
 * Two AND gates connected to make a 3-input AND circuit.
 */
static Circuit* Circuits_and3() {
	Value* in0 = new_Value(false);
	Value* in1 = new_Value(false);
	Value* in2 = new_Value(false);
	Gate* and0 = new_AndGate(in0, in1);
	Gate* and1 = new_AndGate(Gate_getOutput(and0), in2);

	Value** inputs = new_Value_array(3);
	inputs[0] = in0;
	inputs[1] = in1;
	inputs[2] = in2;
	Value** outputs = new_Value_array(1);
	outputs[0] = Gate_getOutput(and1);
	Gate** gates = new_Gate_array(2);
	gates[0] = and0;
	gates[1] = and1;
	return new_Circuit(3, inputs, 1, outputs, 2, gates);
}

static Circuit* Circuit_a() {
    Value* inx = new_Value(false);
    Value* iny = new_Value(false);
    Value* inz = new_Value(false);
    
    Value** inputs = new_Value_array(3);
    inputs[0] = inx;
    inputs[1] = iny;
    inputs[2] = inz;
    
    Gate* not0 = new_Inverter(iny);
    Gate* and0 = new_AndGate(inx, Gate_getOutput(not0));
    Gate* and1 = new_AndGate(iny, inz);
    Gate* or0 = new_OrGate(Gate_getOutput(and0), Gate_getOutput(and1));
    
    Value** outputs = new_Value_array(1);
    outputs[0] = Gate_getOutput(or0);
    
    Gate** gates = new_Gate_array(4);
    gates[0] = not0;
    gates[1] = and0;
    gates[2] = and1;
    gates[3] = or0;
    return new_Circuit(3, inputs, 1, ouputs, 4, gates);
}

static Circuit* Circuit_b() {
    Value* inx = new_Value(false);
    Value* iny = new_Value(false);
    Value* inz = new_Value(false);
    
    Value** inputs = new_Value_array(3);
    inputs[0] = inx;
    inputs[1] = iny;
    inputs[2] = inz;
    
    Gate* not0 = new_Inverter(iny);
    Gate* and0 = new_AndGate(inx, Gate_getOutput(not0));
    Gate* not1 = new_Inverter(Gate_getOutput(and0));
    Gate* and1 = new_AndGate(iny, inz);
    Gate* not2 = new_Inverter(Gate_getOutput(and1));
    Gate* or0 = new_OrGate(Gate_getOutput(not1), Gate_getOutput(not2));
    Gate* not3 = new_Inverter(Gate_getOutput(or0));
    
    Value** outputs = new_Value_array(1);
    outputs[0] = Gate_getOutput(not3);
    
    Gate** gates = new_Gate_array(7);
    gates[0] = not0;
    gates[1] = and0;
    gates[2] = not1;
    gates[3] = and1;
    gates[4] = not2;
    gates[5] = or0;
    gates[6] = not3;
    
    return new_Circuit(3, inputs, 1, ouputs, 7, gates);
}

static Circuit* Circuit_c() {
    Value* inx = new_Value(false);
    Value* iny = new_Value(false);
    Value* inz = new_Value(false);
    
    Value** inputs = new_Value_array(2);
    inputs[0] = inx;
    inputs[1] = iny;
    
    Gate* and0 = new_AndGate(inx, iny);
    Gate* not0 = new_Inverter(inx);
    Gate* not1 = new_Inverter(iny);
    Gate* and1 = new_AndGate(Gate_getOutput(not0), Gate_getOutput(not1));
    Gate* or0 = new_OrGate(Gate_getOutput(and0), Gate_getOutput(and1));
    
    Value** outputs = new_Value_array(1);
    outputs[0] = Gate_getOutput(or0);
    
    Gate** gates = new_Gate_array(5);
    gates[0] = and0;
    gates[1] = not0;
    gates[2] = not1;
    gates[3] = and1;
    gates[4] = or0;
    
    return new_Circuit(2, inputs, 1, ouputs, 5, gates);
}

static char* b2s(bool b) {
	return b ? "T" : "F";
}

static void test3In1Out(Circuit* circuit, bool in0, bool in1, bool in2) {
	Circuit_setInput(circuit, 0, in0);
	Circuit_setInput(circuit, 1, in1);
	Circuit_setInput(circuit, 2, in2);
	//Circuit_dump(circuit);
	Circuit_update(circuit);
	bool out0 = Circuit_getOutput(circuit, 0);
	printf("%s %s %s -> %s\n", b2s(in0), b2s(in1), b2s(in2), b2s(out0));
}


int main(int argc, char **argv) {
	Circuit* c = Circuits_and3();
	printf("Some input(s) false: should be false\n");
	test3In1Out(c, true, true, false);
	printf("All inputs true: should be true\n");
	test3In1Out(c, true, true, true);
}
