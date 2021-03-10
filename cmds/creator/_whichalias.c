#include <std.h>

inherit DAEMON;

int cmd_whichalias(string str){

  string who,what;
  object ob;
   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }
     if(!str) return notify_fail("USAGE: whichalias <player> <alias>\n");

    if(sscanf(str,"%s %s",who,what) != 2)
return notify_fail("USAGE: whichalias <player> <alias>\n");
   ob = find_player(who);
   if( !objectp(ob) || (ob->query_invis() && ob->query_highest_level() > TP->query_lowest_level())){
      notify_fail("No such player online.\n");
      }

     write("Alias "+what+" set to "+((mapping)ob->query_aliases())[what]+" in player "+who+".");
    return 1;
}
