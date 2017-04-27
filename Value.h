/*
 * Value.h
 * Creator: George Ferguson
 * Created: Sun Nov 27 14:08:51 2016
 */

#ifndef VALUE_H_
#define VALUE_H_

#include <stdbool.h>

/**
 * A Value represents a mutable boolean value.
 *
 */

typedef struct Value Value;

extern Value* new_Value(bool value);
extern Value** new_Value_array(int len);

extern bool Value_getValue(Value* this);
extern void Value_setValue(Value* this, bool b);
extern void Value_print(Value* this);

#endif /* VALUE_H_ */
