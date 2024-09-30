# QCom

## Example: Creating a bell state:

```c++
Circuit c (2);

c.Add(new Hadamard(0));
c.Add(new CNOT(0, 1));

c.Run();
c.Observe(10);

std::cout << c << std::endl;
```