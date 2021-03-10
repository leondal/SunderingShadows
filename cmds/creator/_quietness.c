//      /cmds/creator/_quietness.c
//      Created by Pator@ShadowGate
//      Dec 19th 1996

#include <std.h>

inherit DAEMON;

varargs int cmd_quietness(string str)
{
int val;
   if (!wizardp(TP)) { return 0; }
   val = (int)TP->query_quietness();
   if (!str) {
   if (!val) { tell_object(TP,"%^BOLD%^%^RED%^You are not in quietness !%^RESET%^");
		    return 1; }
          else   { tell_object(TP,"%^BOLD%^%^CYAN%^You are in quietness !%^RESET%^");
                    return 1; }
   }
   if ( str == "on" || str == "ON" ) {
	if (!val) { TP->set_quietness();
               tell_object(TP,"%^BOLD%^%^BLUE%^You are in quietness now!%^RESET%^");
		    return 1; }
       else   { tell_object(TP,"%^BOLD%^%^BLUE%^You are in quietness already !%^RESET%^");
		    return 1; }
   }
   if ( str == "off" || str == "OFF" ) {
   if (!val) { tell_object(TP,"%^BOLD%^%^RED%^You were out of quietness allready !");
		    return 1; }
           else   { TP->set_quietness();
               tell_object(TP,"%^BOLD%^%^GREEN%^You are now out of quietness !%^RESET%^");
		    return 1; }
   }
	return 0;
}


int help()
{
  write( @EndText
Syntax: quietness [on || off]
Effect: Quietness will make the wizard 'invisable' for the mortals.
        He won't show up on 'who' and the 'tells' and 'replies' wont
        reach him.
	The command with no argument will make it show your current
        state of quietness.
EndText
  );
  return 1;
}
