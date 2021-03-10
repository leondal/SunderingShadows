#include <std.h>

/*
 *  Pator@ShadowGate
 *	August 17, 2003
 */
 
inherit DAEMON;
string temp;

int
cmd_chpw(string junk) {
   	string *str, dir;
	int i, num;
	
	dir = "";
    str = explode(base_name(environment(this_player())),"/");
    num = sizeof(str) - 1;
    
    for (i=0; i < num; i++) {
	    dir += "/"+str[i];
	}
    
    write(dir);
    
    this_player()->set_path(dir);
// above doesn't seem to work, let's try this *Styx* 11/20/06
   TP->command("cd "+dir);
    seteuid(getuid());
    write( (string)this_player()->get_path() + ":");
    return 1;
}

int
help() {
  write("Command: chpw\nSyntax: chpw"
        "This command changes your current directory to the"
        "directory of the room you are currently in.\n");
  return 1;
}
