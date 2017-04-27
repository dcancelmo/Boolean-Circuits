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

//Circuit a - Dan Cancelmo
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
    return new_Circuit(3, inputs, 1, outputs, 4, gates);
}

//Circuit b - Dan Cancelmo
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
    
    return new_Circuit(3, inputs, 1, outputs, 7, gates);
}

//Circuit c - Dan Cancelmo
static Circuit* Circuit_c() {
    Value* inx = new_Value(false);
    Value* iny = new_Value(false);
    
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
    
    return new_Circuit(2, inputs, 1, outputs, 5, gates);
}

//Circuit one-bit adder - Dan Cancelmo
static Circuit* Circuit_one_bit_adder() {
    Value* inx = new_Value(false);
    Value* iny = new_Value(false);
    Value* inc = new_Value(false);
    
    Value** inputs = new_Value_array(3);
    inputs[0] = inx;
    inputs[1] = iny;
    inputs[2] = inc;
    
    Gate* notx = new_Inverter(inx);
    Gate* noty = new_Inverter(iny);
    Gate* notc = new_Inverter(inc);
    
    Gate* and1a = new_AndGate(Gate_getOutput(notx), Gate_getOutput(noty));
    Gate* and1 = new_AndGate(Gate_getOutput(and1a), inc);
    Gate* and2a = new_AndGate(Gate_getOutput(notx), Gate_getOutput(notc));
    Gate* and2 = new_AndGate(Gate_getOutput(and2a), iny);
    Gate* and3a = new_AndGate(Gate_getOutput(notx), inc);
    Gate* and3 = new_AndGate(Gate_getOutput(and3a), iny);
    Gate* and4a = new_AndGate(inx, Gate_getOutput(noty));
    Gate* and4 = new_AndGate(Gate_getOutput(and4a), Gate_getOutput(notc));
    Gate* and5a = new_AndGate(inx, Gate_getOutput(noty));
    Gate* and5 = new_AndGate(Gate_getOutput(and5a), inc);
    Gate* and6a = new_AndGate(inx, iny);
    Gate* and6 = new_AndGate(Gate_getOutput(and6a), Gate_getOutput(notc));
    Gate* and7a = new_AndGate(inx, iny);
    Gate* and7 = new_AndGate(Gate_getOutput(and7a), inc);
    
    Gate* orZa = new_OrGate(Gate_getOutput(and1), Gate_getOutput(and2));
    Gate* orZb = new_OrGate(Gate_getOutput(and4), Gate_getOutput(and7));
    Gate* orZ = new_OrGate(Gate_getOutput(orZa), Gate_getOutput(orZb));

    Gate* orDa = new_OrGate(Gate_getOutput(and3), Gate_getOutput(and5));
    Gate* orDb = new_OrGate(Gate_getOutput(and6), Gate_getOutput(and7));
    Gate* orD = new_OrGate(Gate_getOutput(orDa), Gate_getOutput(orDb));
    
    Value** outputs = new_Value_array(2);
    outputs[0] = Gate_getOutput(orZ);
    outputs[1] = Gate_getOutput(orD);
    
    Gate** gates = new_Gate_array(23);
    gates[0] = notx;
    gates[1] = noty;
    gates[2] = notc;
    gates[3] = and1a;
    gates[4] = and1;
    gates[5] = and2a;
    gates[6] = and2;
    gates[7] = and3a;
    gates[8] = and3;
    gates[9] = and4a;
    gates[10] = and4;
    gates[11] = and5a;
    gates[12] = and5;
    gates[13] = and6a;
    gates[14] = and6;
    gates[15] = and7a;
    gates[16] = and7;
    gates[17] = orZa;
    gates[18] = orZb;
    gates[19] = orZ;
    gates[20] = orDa;
    gates[21] = orDb;
    gates[22] = orD;
    
    return new_Circuit(3, inputs, 2, outputs, 23, gates);
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

//Circuit test 2 inputs 1 outputs - Dan Cancelmo
static void test2In1Out(Circuit* circuit, bool in0, bool in1) {
    Circuit_setInput(circuit, 0, in0);
    Circuit_setInput(circuit, 1, in1);
    //Circuit_dump(circuit);
    Circuit_update(circuit);
    bool out0 = Circuit_getOutput(circuit, 0);
    printf("%s %s -> %s\n", b2s(in0), b2s(in1), b2s(out0));
}

//Circuit test 3 inputs 2 outputs - Dan Cancelmo
static void test3In2Out(Circuit* circuit, bool in0, bool in1, bool in2) {
    Circuit_setInput(circuit, 0, in0);
    Circuit_setInput(circuit, 1, in1);
    Circuit_setInput(circuit, 2, in2);
    //Circuit_dump(circuit);
    Circuit_update(circuit);
    bool out0 = Circuit_getOutput(circuit, 0);
    bool out1 = Circuit_getOutput(circuit, 1);
    printf("x:%s y:%s c:%s -> z:%s d:%s\n", b2s(in0), b2s(in1), b2s(in2), b2s(out0), b2s(out1));
}

//Main method - Dan Cancelmo
int main(int argc, char **argv) {
//	Circuit* c = Circuits_and3();
//	printf("Some input(s) false: should be false\n");
//	test3In1Out(c, true, true, false);
//	printf("All inputs true: should be true\n");
//	test3In1Out(c, true, true, true);
    //Testing Circuit A
    Circuit* c = Circuit_a();
    printf("\n_______Testing circuit a with the following inputs:_______\n");
    printf("True, true, true should be true\n");
    test3In1Out(c, true, true, true);
    printf("False, true, true should be true\n");
    test3In1Out(c, false, true, true);
    printf("True, false, true should be true\n");
    test3In1Out(c, true, false, true);
    printf("True, true, false should be false\n");
    test3In1Out(c, true, true, false);
    printf("False, false, true should be false\n");
    test3In1Out(c, false, false, true);
    printf("True, false, false should be true\n");
    test3In1Out(c, true, false, false);
    printf("False, true, false should be false\n");
    test3In1Out(c, false, true, false);
    printf("False, false, false should be false\n");
    test3In1Out(c, false, false, false);
    
    //Testing Circuit B
    c = Circuit_b();
    printf("\n_______Testing circuit b with the following inputs:_______\n");
    printf("True, true, true should be false\n");
    test3In1Out(c, true, true, true);
    printf("False, true, true should be false\n");
    test3In1Out(c, false, true, true);
    printf("True, false, true should be false\n");
    test3In1Out(c, true, false, true);
    printf("True, true, false should be false\n");
    test3In1Out(c, true, true, false);
    printf("False, false, true should be false\n");
    test3In1Out(c, false, false, true);
    printf("True, false, false should be false\n");
    test3In1Out(c, true, false, false);
    printf("False, true, false should be false\n");
    test3In1Out(c, false, true, false);
    printf("False, false, false should be false\n");
    test3In1Out(c, false, false, false);
    
    c = Circuit_c();
    printf("\n_______Testing circuit c with the following inputs:_______\n");
    printf("True, true should be true\n");
    test2In1Out(c, true, true);
    printf("False, true should be false\n");
    test2In1Out(c, false, true);
    printf("True, false should be false\n");
    test2In1Out(c, true, false);
    printf("False, false should be true\n");
    test2In1Out(c, false, false);
    
    //Testing one-bit adder
    c = Circuit_one_bit_adder();
    printf("\n_______Testing one-bit adder with the following inputs:_______\n");
    printf("True, true, true should be true and true\n");
    test3In2Out(c, true, true, true);
    printf("False, true, true should be false and true\n");
    test3In2Out(c, false, true, true);
    printf("True, false, true should be false and true\n");
    test3In2Out(c, true, false, true);
    printf("True, true, false should be false and true\n");
    test3In2Out(c, true, true, false);
    printf("False, false, true should be true and false\n");
    test3In2Out(c, false, false, true);
    printf("True, false, false should be true and false\n");
    test3In2Out(c, true, false, false);
    printf("False, true, false should be true and false\n");
    test3In2Out(c, false, true, false);
    printf("False, false, false should be false and false\n");
    test3In2Out(c, false, false, false);
    printf("\n");
}
