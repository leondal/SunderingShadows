#include <std.h>
#include "/realms/grendel/grendel.h"
inherit DAEMON;

int cmd_channels(string str) {
   string *channels;
   int i;
   object ob;
   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }
   if(!str || str == "me") str=(string)TP->query_name();
   if(!ob = find_player(str)){
      notify_fail(capitalize(str)+" is not in our reality.\n");
      return 0;
   }
   write("%^BOLD%^%^RED%^"+capitalize(str)+" has the following lines:%^RESET%^");
   channels = distinct_array((string *)ob->query_channels());
    sort(channels);
   for(i=0; i<sizeof(channels); i++) {
      if(ob->query_blocked(channels[i]))
         message("info","%^BOLD%^"+channels[i]+"%^RESET%^ is %^RED%^OFF%^RESET%^.",TP);
      else
         message("info","%^BOLD%^"+channels[i]+"%^RESET%^ is %^GREEN%^ON%^RESET%^.",TP);
   }
   return 1;
}

void help() {
   write(
@HELP
Syntax: channels <name>

This will list the staus of the lines of player <name>.
HELP
   );
   return;
}

