import subprocess as sp
import time
import os

def Grading(filename, testcase_num = 10, timelimit = 1):
    filepath = f"code/{filename}"
    process = sp.Popen(['g++', '-O2', f"{filepath}.cpp",'-o', filepath], 
    stdout=sp.PIPE, stderr=sp.PIPE, encoding='utf-8')
    output, err = process.communicate()
    if process.returncode != 0:
        # sp.run(f"del {filename}.exe", shell=True, cwd = "code")
        return "\nCompliation Error\n" + err
    
    result = []
    for testcase in range(1, testcase_num+1):
        verdict = ""
        runtime = 0
        start = time.time()
        process = sp.Popen(filepath, stdout=sp.PIPE, stdin=sp.PIPE, stderr=sp.PIPE, encoding='utf-8')
        try:
            with open(f"input/{testcase}.in") as f:
                output, err = process.communicate(timeout=timelimit, input=f.read())
            runtime = time.time() - start
        except sp.TimeoutExpired:
            process.kill()
            verdict = "T"
            runtime = timelimit
            result.append([verdict, runtime])
            continue
        if process.returncode != 0:
            verdict = "X"
            result.append([verdict, runtime])
            continue
        with open(f"solution/{testcase}.sol") as f:
            expect_output = [item for item in f.read().strip().split()]
        user_output = [item for item in output.strip().split()]

        if user_output == expect_output:
            verdict = "P"
        else:
            verdict = "-"
        result.append([verdict, runtime])
    sp.run(f"del {filename}.exe", shell=True, cwd = "code")
    return result

filename = input("I want to CPP: ")
print(Grading(filename))

