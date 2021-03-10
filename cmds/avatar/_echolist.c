#include <std.h>
#include <security.h>
inherit DAEMON;

void help();

int cmd_echolist(string str)
{
    string targs, line, nme, *names;
    object * targets=({ }), current;
    int iter;

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
    names=explode(targs," ");
    for (iter=0;iter < sizeof(names); iter++) {
//      write(iter); write(names[iter]);
	if(!current = find_player(names[iter])) {
	      write("There is no player named "+names[iter]+" that you can see online!");
	  } else {
	      targets += ({ current });
	  }
      }
	seteuid(UID_LOG);
	seteuid(getuid());
	line = replace_string(line,"%^NL%^","\n");
	message("echo",line,targets);
	message("echo","You echolist "+targs+":\n"+line+"",TP);
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
