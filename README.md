# A *very* minimal UnitDType implementation used in the SciPy 2022 talk

To run the example, it is necessary to use a main branch version of NumPy
at this time.  (Expect it to outdate fairly quickly, unfortunately.)

The package should be pip installable and support some very basic use-cases.
Note that this is not supposed to be the cleanest code, but rather give
a minimal example showing much of the new possibilities in NumPy DTypes
and also ufuncs.

The following is an example of what is supported:

```python
import numpy as np
from unitdtype import *
```

Create a zeroed array (ones will not work)
```python
>>> arr1 = np.zeros(3, dtype=UnitDType("m"))
array([0.0*m, 0.0*m, 0.0*m], dtype=UnitDType(m))
```

Create two arrays from scalars, then multiply them:
```python
arr1 = np.array([2*m])
arr2 = np.array([3*m])

arr1 * arr2  # or np.multiply
```
Gives ``array([6.0*m**2], dtype=UnitDType(m**2))``.

Of course, we can also cast between different units!
```python
arr = np.array([2*m])

arr.astype(UnitDType("cm"))
```
giving ``array([200.0*cm], dtype=UnitDType(cm))``.

Finally, we of course also need to be able to take out arrays and assign to it:
```
>>> arr[0]
2.0*m
```
and:
```
>>> arr[0] = 300*cm
>>> arr
array([3.0*m], dtype=UnitDType(m))
```


This example is minimal, for a far more extensive one, check
https://github.com/seberg/unitdtype
