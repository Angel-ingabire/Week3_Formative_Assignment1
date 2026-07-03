# Performance Explanation

The pure Python version performs the computation directly in Python by iterating over the list and updating the running total and sum of squares inside the interpreter. This is simple and readable, but it incurs interpreter overhead for every element and arithmetic operation.

The C extension uses the CPython C API to process the same numeric workload in compiled C code. Because the loop is executed in C instead of Python bytecode, it avoids much of the interpreter overhead and usually runs much faster on large datasets.

In the benchmark run, the C extension completed the workload much faster than the pure Python version, showing a clear improvement. The main reason is that the extension executes the computation in native machine code rather than through Python's dynamic runtime.
