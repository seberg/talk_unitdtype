#ifndef _NPY_DTYPE_H
#define _NPY_DTYPE_H


typedef struct {
    PyArray_Descr base;
    PyObject *unit;
} UnitDTypeObject;

int
UnitConverter(PyObject *obj, PyObject **unit);

extern PyArray_DTypeMeta UnitDType;
extern PyObject *QuantityScalar_Type;

UnitDTypeObject *
new_unitdtype_instance(PyObject *unit);

int
init_unit_dtype(void);

#endif  /*_NPY_DTYPE_H*/
