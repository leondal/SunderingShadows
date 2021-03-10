#include <std.h>
#include <daemons.h>
inherit DAEMON;

int cmd_which(string str){
    string result;
    if(!str) return identify(TP->query_search_path());
    result = CMD_D->find_cmd(str,TP->query_search_path());
    if(!stringp(result)) return notify_fail("That command is not found.\n");
    write(result);
    return 1;
}


int help(){
   write(
@OLI
	which <command name> 
        returns the path of the command that will be used. Helps when commands exist in mulitple paths.
OLI
    );
    return 1;
}
