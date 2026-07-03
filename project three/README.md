# Project Three: Python Performance Extension

This project compares a pure Python implementation with a CPython C extension for heavy numeric computation.

## Files

- `fast_stats.c` - the C extension implementation using the CPython API
- `benchmark.py` - a benchmark that compares Python vs. C extension performance
- `setup.py` - build instructions for the extension

## How to run

1. Build the extension:
   ```bash
   python setup.py build_ext --inplace
   ```
2. Run the benchmark:
   ```bash
   python benchmark.py
   ```

## Expected outcome

The C extension should be noticeably faster because the computation is performed in compiled C code instead of Python bytecode.
