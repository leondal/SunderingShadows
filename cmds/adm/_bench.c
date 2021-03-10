/*
 * bench.c [cmd]
 * description: the benchmarks as posted by Karl
 * Help added by Pallando 93-02-13
 */

#include <std.h>

inherit DAEMON;


int cmd_bench (string arg)
{
    string test;
    
    if (!arg) {
       notify_fail ("usage: bench {1-5 or all}\n");
       return 0;
    }
    test = "test";     
    switch (arg)
    {
        case "1":
	   write ("Empty loop benchmark\n");
	   call_other(this_object(),test + arg);
	   break;
        case "2":
	   write ("Function call benchmark\n");
	   call_other(this_object(),test + arg);
	   break;
        case "3":
	   write ("call_other benchmark\n");
	   call_other(this_object(),test + arg);
	   break;
        case "4":
	   write ("String addition benchmark\n");
	   call_other(this_object(),test + arg);
	   break;
        case "5":
	   write ("array addition benchmark\n");
	   call_other(this_object(),test + arg);
	   break;
	case "all":
	   write ("doing all benchmarks\n");
	   cmd_bench("1");
	   cmd_bench("2");
	   cmd_bench("3");
	   cmd_bench("4");
	   cmd_bench("5");
	   break;
	default:
   write( "You must specify a number between 1 and 5.\n" );
	   break;
   }
   return 1;
}
 
void test1 ()
{
    int i, time;
    mapping r;
    r = rusage();
    time = r["usertime"];
    for (i = 0; i < 10000; i++)
    {
    }
    r = rusage();
    write ("time taken: "+(r["usertime"] - time) + "\n");
}

void yy()
{
}

void test2 ()
{
    int i, time;
    mapping r;
    r = rusage();
    time = r["usertime"];
    for (i = 0; i < 10000; i++)
    {
	yy();
    }
    r = rusage();
    write ("time taken: "+(r["usertime"] - time) + "\n");
}

void test3 ()
{
    int i, time;
    mapping r;
    r = rusage();
    time = r["usertime"];
    for (i = 0; i < 10000; i++)
    {
	this_object()->yy();
    }
    r = rusage();
    write ("time taken: "+(r["usertime"] - time) + "\n");
}

void test4 ()
{
    int i, time;
    mapping r;
    string s;
    r = rusage();
    time = r["usertime"];
    for (i = 0; i < 10000; i++)
    {
	s = "xxxxxx";
	s += s;
    }
    r = rusage();
    write ("time taken: "+(r["usertime"] - time) + "\n");
}

void test5 ()
{
    int i, time;
    mapping r;
    string *s;
    
    r = rusage();
    time = r["usertime"];
    for (i = 0; i < 10000; i++)
    {
	s = allocate(10);
	s += s;
    }
    r = rusage();
    write ("time taken: "+(r["usertime"] - time) + "\n");
}

int help()
{
  write( ""+
"Syntax: bench <arg>\n"+
"Effect: <arg> may be 1-5 or \"all\"\n"+
"        Calculates Karl's Standard Mud Driver Benchmarks.\n"+
"1 - Empty loop\n"+
"2 - Function call\n"+
"3 - call_other\n"+
"4 - String addition\n"+
"5 - Array addition\n"+
  "" );
  return 1;
}
