#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject *compute_statistics(PyObject *self, PyObject *args)
{
    PyObject *sequence;
    if (!PyArg_ParseTuple(args, "O", &sequence))
    {
        return NULL;
    }

    PyObject *fast_seq = PySequence_Fast(sequence, "expected a sequence of numbers");
    if (!fast_seq)
    {
        return NULL;
    }

    Py_ssize_t n = PySequence_Fast_GET_SIZE(fast_seq);
    double total = 0.0;
    double sumsq = 0.0;

    for (Py_ssize_t i = 0; i < n; ++i)
    {
        PyObject *item = PySequence_Fast_GET_ITEM(fast_seq, i);
        double value = PyFloat_AsDouble(item);
        if (PyErr_Occurred())
        {
            Py_DECREF(fast_seq);
            return NULL;
        }

        total += value;
        sumsq += value * value;
    }

    double mean = n > 0 ? total / n : 0.0;
    double variance = n > 0 ? (sumsq / n) - (mean * mean) : 0.0;
    Py_DECREF(fast_seq);

    return Py_BuildValue("ddd", total, mean, variance);
}

static PyMethodDef FastStatsMethods[] = {
    {"compute_statistics", compute_statistics, METH_VARARGS, "Compute total, mean and variance for a numeric sequence."},
    {NULL, NULL, 0, NULL}};

static struct PyModuleDef fast_statsmodule = {
    PyModuleDef_HEAD_INIT,
    "fast_stats",
    "A small CPython C extension for numeric computation.",
    -1,
    FastStatsMethods,
    NULL,
    NULL,
    NULL,
    NULL};

PyMODINIT_FUNC PyInit_fast_stats(void)
{
    return PyModule_Create(&fast_statsmodule);
}
