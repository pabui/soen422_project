# soen422_project

## Compile code
Should be a makefile but I'm not famaliar with c and need to focus on other things.

### VM on Host
`gcc ./src/admin.c ./src/out.c  ./src/vm.c ./src/vmstack.c  ./src/hal.c  ./src/_cout.c ./src/_console.c ./src/_xtoa.c -o cm`

### A unit
`gcc a_unit.c -o a_unit`

## Testing on host
To run the precompiled tests do:
`./test_vm.bat`

### Failed tests
Note: the test programs and need to be in the same directory, the vm does not handle file paths.
Some tests are failing, looking at the code the test is failing because the expected result is wrong. I'm not sure why the expected result is nonsense, need to check with teacher...

For exmaple T01.exe
```
Test 01: Value Types (Literals)
-128|127|127|127|000DECAF|0000AB8D|0|9|a|A|10|10|10|10|10|false|true
-128|127|127|127|DECAF|AB8D|0|9|a|A|10|10|10|10|10|F|T
```

Notice how the generated hex values are padded and generated booleans are true/false.
Now if we look at the code:
```c
static void COut_PutB(bool b)        { printf("%s", b ? "true" : "false"); }
static void COut_PutX(u32  u)        { printf("%08lX", u); } // To make hex output always aligned to 8 hex digits.
```
The code acts as expted, padding the hex values and priting true/false.

## Other files
The *other_files* directory has random files that were included in an anouncement about the miderm "Midterm Exam Correction completed + Files for today's lecture",
the files for the **lecture** have the precompiled test code. There are also other files, not sure why they are there or why it was not included in the original source code. So

