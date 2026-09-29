"""Run every Chapter 2 demo and compare its observable output."""

import subprocess
import sys
from pathlib import Path


build = Path(sys.argv[1]).resolve()
expected = {
    "binary_search": "Index: 2\n",
    "bsearch": "Index: 2\nMissing: -1\n",
    "icmp": "2\n3\n5\n10\n",
    "linear_search": "Index of none: -1\n",
    "quicksort": "1\n3\n5\n5\n7\n18\n29\n32\n45\n",
    "scmp": "a\nb\nc\nd\n",
}

for name, output in expected.items():
    result = subprocess.run([build / name], check=True, capture_output=True, text=True)
    assert result.stdout == output, f"{name}: {result.stdout!r} != {output!r}"
    assert not result.stderr, f"{name}: unexpected stderr {result.stderr!r}"

result = subprocess.run(
    ["java", "-cp", str(build), "java_sort"],
    check=True,
    capture_output=True,
    text=True,
)
assert result.stdout == "[Dog, Cat, Turkey, Hippo]\n[Cat, Dog, Hippo, Turkey]\n"
assert not result.stderr, f"java_sort: unexpected stderr {result.stderr!r}"

print("7 Chapter 2 demos passed")
