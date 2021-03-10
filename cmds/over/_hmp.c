#include <std.h>
#include <daemons.h>
#include <security.h>
#define TS "/daemon/treesave_d.c"

inherit DAEMON;

int help();
int cmd_hmp(string str){
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

  if (!str) return notify_fail("Usage: hmp <who> <on/off> <reason>\n");
  if (sscanf(str,"%s %s %s", who, what, why) != 3) return notify_fail("Usage: hmp <who> <on/off> <reason>\n");
  ob = find_player(who);
  if (!ob) {
    if (!user_exists(who)) return notify_fail("The player "+who+" does not exist.\n");
    //load the player
  } else {
    switch (what) {
    case "on":
      seteuid(UID_ADVANCE);
      ob->set_position("high mortal");
      seteuid(getuid());
      ob->add_search_path("/cmds/hm");
      ob->set("no advance",0);
//added to get rid of levelcap to stop the problem of HMs still being capped.
//Circe 11/20/04
      message("info","All hail "+capitalize(ob->query_name())+" the new high mortal!\n",users());
      CASTLE_D->enable_high_mortal(ob);
      TS->add_value_to_array("notes",ob->query_name(), capitalize(TP->query_name()) + ", " + ctime(time()) + " - recieved HM status because: "+why);
      ob->set_max_mp(2*((int) ob->query_stats("intelligence") + (int)ob->query_stats("wisdom")));
      tell_object(TP,who+" is a high mortal now.");
      break;
    case "off":
    case "demote":

      seteuid(UID_ADVANCE);
      ob->set_position("player");
      seteuid(getuid());
      ob->remove_search_path("/cmds/hm");
      // message("info",capitalize(ob->query_name())+" has lost "+ob->query_possessive()+" hm status.",users());
      seteuid(UID_LOG);
      TS->add_value_to_array("notes",ob->query_name(), capitalize(TP->query_name()) + ", " + ctime(time()) + " - lost HM status because: "+why);
      ob->disable_high_mortal(ob);
      ob->update_channels();
      tell_object(TP,who+" is no longer a high mortal.");
      break;
    default:
      help();
      break;
    }
    ob->update_channels();
  }
  return 1;
}

int help(){
  write("Syntax:  hmp <who> <on/off> <reason>\n");
  return 1;
}
