import time
from pathlib import Path

try:
    import fast_stats
except ImportError as exc:
    raise SystemExit(
        "The C extension has not been built yet. Run 'python setup.py build_ext --inplace' first."
    ) from exc


def python_compute(values):
    total = 0.0
    sumsq = 0.0
    for value in values:
        total += value
        sumsq += value * value
    mean = total / len(values)
    variance = (sumsq / len(values)) - (mean * mean)
    return total, mean, variance


def build_input(size):
    values = []
    for i in range(size):
        values.append(((i % 251) - 125) / 17.0 + ((i % 19) * 0.01))
    return values


def benchmark():
    size = 1_500_000
    values = build_input(size)

    for label, func in [("Python", python_compute), ("C extension", lambda seq: fast_stats.compute_statistics(seq))]:
        start = time.perf_counter()
        for _ in range(3):
            func(values)
        elapsed = time.perf_counter() - start
        print(f"{label}: {elapsed:.4f} seconds for 3 runs")

    py_time = None
    c_time = None
    # Re-run once more for a clean comparison
    start = time.perf_counter()
    python_compute(values)
    py_time = time.perf_counter() - start

    start = time.perf_counter()
    fast_stats.compute_statistics(values)
    c_time = time.perf_counter() - start

    print(f"Single-run Python: {py_time:.6f} seconds")
    print(f"Single-run C extension: {c_time:.6f} seconds")
    print(f"Speedup: {py_time / c_time:.2f}x")

    report = Path(__file__).with_name("benchmark_results.txt")
    report.write_text(
        "Performance benchmark\n"
        "=====================\n"
        f"Input size: {size} values\n"
        f"Single-run Python: {py_time:.6f} seconds\n"
        f"Single-run C extension: {c_time:.6f} seconds\n"
        f"Speedup: {py_time / c_time:.2f}x\n",
        encoding="utf-8",
    )
    print(f"Saved benchmark results to {report}")


if __name__ == "__main__":
    benchmark()
