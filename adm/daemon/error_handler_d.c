/*
fluffos documentation related to error handling

This function allows the mudlib to handle errors instead of the driver.
The contents of the 'error' mapping are:

([
"error"   : string,     // the error
"program" : string,     // the program
"object"  : object,     // the current object
"line"    : int,        // the line number
"trace"   : mapping*    // a trace back
])

Each line of traceback is a mapping containing the following:

([
"function"  : string,   // the function name
"program"   : string,   // the program
"object"    : object,   // the object
"file"      : string,   // the file to which the line number refers
"line"      : int       // the line number
])
The 'caught' flag is 1 if the error was trapped by catch().
*/
#include <std.h>
#include <daemons.h>
#include <conf.h>
#include <security.h>

inherit DAEMON;


void create()
{
    ::create();
}



string format_verbose_error(mapping map)
{
    string obj,error,file,program,func;
    mixed *args=({}),*locals=({});
    int line,i,j;
    mapping *trace,tmp;
    
    string str = ""+ctime(time()) + "\n";
    
    obj = base_name(map["object"]);
    error = map["error"];
    line = map["line"];
    file = map["file"];
    program = map["program"];
    trace = map["trace"];
    
    str += ""+error + " ** line: "+line+"\n";
    str += "Object:  "+obj+"\n";
    str += "File:    "+file+"\n";
    str += "Program: "+program+"\n\n";
    
    if(sizeof(trace))
    {
        for(i=0;i<sizeof(trace);i++)
        {
            tmp     = trace[i];
            obj     = base_name(tmp["object"]);
            func    = tmp["function"];
            line    = tmp["line"];
            file    = tmp["file"];
            program = tmp["program"];
            args    = tmp["arguments"];
            locals  = tmp["locals"];
            
            
            str += "  TRACE# "    +(i+1)+"\n";
            str += "  Object: "   +obj+"\n";
            str += "  File: "     +file+"\n";
            str += "  Program: "  +program+"\n";
            str += "  Line: "     +line+"\n";
            str += "  Function: " +func+"\n";
            
            if(sizeof(args))
            {
                str += "    Arguments: \n";
                for(j=0;j<sizeof(args);j++)
                {
                    str += "      Arg# "+(j+1)+" "+identify(args[j])+"\n";
                }                
            }
            
            if(sizeof(locals))
            {
                str += "    Locals: \n";
                for(j=0;j<sizeof(locals);j++)
                {
                    str += "      Local# "+(j+1)+" "+identify(locals[j])+"\n";
                }                
            }
            
            str += "\n";
            
        }
    }
    
    str += "\n";
    
    return str;    
    
}


string format_light_error(string error, string file, int line)
{
    string str = "*"+ctime(time());
    
    str += ": "+ file +" line "+ line +": "+ error;
    return str;   
}


void process_error(mapping map, int num)
{
    string lite_log,verbose_log;
    
    lite_log    = format_light_error(map["error"],base_name(map["object"]),map["line"]);
    verbose_log = format_verbose_error(map);
    
    seteuid(UID_LOG);
    
    catch(write_file("/log/debug.log",lite_log));
    if(file_size("/log/debug.log") > (MAX_LOG_SIZE * 5))
    {
        rm("/log/debug.log.old");
        rename("/log/debug.log","/log/debug.log.old");
    }
    
    catch(write_file("/log/debug.heavy",verbose_log));
    if(file_size("/log/debug.heavy") > (MAX_LOG_SIZE * 10))
    {
        rm("/log/debug.heavy.old");
        rename("/log/debug.heavy","/log/debug.heavy.old");
    }    
}
