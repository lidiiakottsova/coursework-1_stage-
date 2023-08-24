**INI файл содержит данные в таком виде:**
```
[group1]
var1=val1
var2=val2
[group2]
var1=val11
var3=val3
```
**В dot-separated формате эта информация записывается так:**
```
group1.var1: val1
group1.var2: val2
group2.var1: val11
group2.var3: var3
```
**Программа преобразует файл в ini формате в файл во втором формате.**

