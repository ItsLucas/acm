from cyaron import *

_n = ati([10,20,30,40,10,20,30,40,10,20])
for i in range(1,10):
    test_data = IO(file_prefix="magic",data_id=i)
    n=_n[i]
    test_data.input_writeln(n)
    for j in range(1,n):
        string = String.random(149800,charset="abcdefg123456")
        test_data.input_write(string)
        string = String.random(None,charset=["appppa","helleh","ufghyyhgfu","qwerasdffdsarewq","BjTuTjB","a","b","c","d","A","B","C","D"])
        test_data.input_write(string)
        string = String.random(149800,charset="abcdefg123456")
        test_data.input_writeln(string)
    test_data.output_gen("std.exe")