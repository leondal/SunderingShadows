//      /bin/dev/_elog.c
//      from the Nightmare Mudlib
//      tails error logs
//      created by Descartes of Borg 930813

#include <std.h>
#include <dirs.h>

inherit DAEMON;

int cmd_elog(string str) 
{
    string elogs;
    if(!str) str = DIR_ERROR_LOGS+"/"+geteuid(previous_object());
    else str = DIR_ERROR_LOGS+"/"+str;

    write(str+":\n");
    
    if(!tail(str)) 
    {
        if(pointerp(get_dir("/log/errors/")))
        {
            elogs = implode(get_dir("/log/errors/"),", ");
        }
        write("No errors in "+str+".\nTry /log/debug.log.\n");
        write("Elogs exist for the following areas: "+elogs+"\n");
    }
    
    return 1;
}

void help() {
    write("Syntax: <elog ([error log])>\n\n"
      "This will tail your personal error log if issued without any\n"
      "arguements.  If an argument is given, it searches for a file\n"
      "by that name in the mud's error log directory.\n\nSee also:\n"
      "log, replog\n"
    );
}
