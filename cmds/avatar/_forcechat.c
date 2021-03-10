#include <std.h>
#include <security.h>
inherit DAEMON;

void help();

int cmd_forcechat(string str)
{
    string targs, line, nme, *names;
    object target, current;
    int x;

   string posxxx;
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

    if(!str) return help();
    if(sscanf(str,"%s=%s", targs, line) != 2) return help();
     if (objectp(target=present(targs))) {
	      write("There is no object named "+targs+" that you can see online!");
	  } else {
             targs = lower_case(targs);
	  }
	seteuid(UID_LOG);
	seteuid(getuid());
        names = explode(line," ");
        nme=names[0];
        line=implode(names[1..sizeof(names)]," ");

        if (strsrch(nme,"emote") != -1) {
           x=1;
        }
	line = replace_string(line,"%^NL%^","\n");
        "/daemon/chat"->force_chat(target,nme,line,x);
	return 1;
    }

    void help()
    {
        write("Syntax: echolist <player list>=<message>\n\n"+
	  "The echo will only be seen by the players you have"+
	  " specified. So drive them insane, make them think"+
	  " they're hearing voices, and have fun.");
	return 1;
    }
