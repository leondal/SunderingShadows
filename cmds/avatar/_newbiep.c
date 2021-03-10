#include <std.h>
#include <daemons.h>
#include <security.h>
#define TS "/daemon/treesave_d.c"

inherit DAEMON;

int cmd_newbiep(string str){
  string who;
  string why;
  string what;
  object ob;

   string posxxx;
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

  if (!str) return notify_fail("Usage: newbiep <who> <on/off> <reason>\n");
  if(sscanf(str,"%s %s %s", who, what, why) != 3) return notify_fail("Usage: newbiep <who> <on/off> <reason>\n");
  ob = find_player(who);
  if(!ob) {
    if(!user_exists(who)) return notify_fail("The player "+who+" does not exist.\n");
    //load the player
  } else {
    if(avatarp(ob)) return notify_fail("No way in heck is that right!\n");
    if(high_mortalp(ob)) return notify_fail("I think you're using the wrong command, boss.\n");
    if(what == "on"){
      seteuid(UID_ADVANCE);
      ob->set_position("newbie");
      seteuid(getuid());
      ob->set_max_mp(2*((int) ob->query_stats("intelligence") + (int)ob->query_stats("wisdom")));
     TS->add_value_to_array("notes",ob->query_name(), capitalize(TP->query_name()) + ", " + ctime(time()) + " - Newbie status added because: " + why + ".");
     //NOTES_D->add_note(ob->query_name(), capitalize(TP->query_name()) + ", " + ctime(time()) + " - Newbie status added because: " + why + ".");
      tell_object(TP,who+" is a newbie now.");
    } else {
      seteuid(UID_ADVANCE);
      ob->set_position("player");
      seteuid(getuid());
      seteuid(UID_LOG);
      ob->update_channels();
      TS->add_value_to_array("notes",ob->query_name(), capitalize(TP->query_name()) + ", " + ctime(time()) + " - Newbie status lost because: " + why + ".");
      tell_object(TP,who+" is no longer a newbie.");
    }
    ob->update_channels();
  }
  return 1;
}
int help(){
  write("Syntax:  newbiep <who> <on/off> <reason>\n");
  return 1;
}
