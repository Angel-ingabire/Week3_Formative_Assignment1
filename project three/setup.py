import importlib

try:
    setuptools = importlib.import_module("setuptools")
    Extension = setuptools.Extension
    setup = setuptools.setup
except ModuleNotFoundError:  # pragma: no cover - fallback for minimal environments
    distutils = importlib.import_module("distutils.core")
    Extension = distutils.Extension
    setup = distutils.setup

module = Extension("fast_stats", sources=["fast_stats.c"])

setup(
    name="fast_stats",
    version="1.0.0",
    description="A CPython C extension for fast numeric statistics",
    ext_modules=[module],
)
