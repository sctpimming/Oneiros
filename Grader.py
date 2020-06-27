import subprocess as sp
import time
import os

def Grading(filename, testcase_num = 10, timelimit = 1):
    process = sp.Popen(['g++', '-O2', f"{filename}.cpp",'-o', filename], 
    stdout=sp.PIPE, stderr=sp.PIPE, encoding='utf-8')
    output, err = process.communicate()
    if process.returncode != 0:
        return "\nCompliation Error\n" + err
    
    result = []
    for testcase in range(1, testcase_num+1):
        verdict = ""
        runtime = 0
        start = time.time()
        process = sp.Popen(filename, stdout=sp.PIPE, stdin=sp.PIPE, stderr=sp.PIPE, encoding='utf-8')
        try:
            with open(f"{testcase}.in") as f:
                output, err = process.communicate(timeout=timelimit, input=f.read())
            runtime = time.time() - start
        except sp.TimeoutExpired:
            verdict = "T"
            runtime = timelimit
            result.append([verdict, runtime])
            continue
        if process.returncode != 0:
            verdict = "X"
            result.append([verdict, runtime])
            continue
        
        with open(f"{testcase}.sol") as f:
            expect_output = [item for item in f.read().strip().split()]
        user_output = [item for item in output.strip().split()]

        if user_output == expect_output:
            verdict = "P"
        else:
            verdict = "-"
        result.append([verdict, runtime])
        
    return result

filename = input("I want to CPP: ")
print(Grading(filename))

