// new command to call a mount.
#include <std.h>
inherit DAEMON;

int cmd_whistle(string str) {
   object what, mysneak;
   string str2, *currentpets, *activepets;

   if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(TP->query_hidden()) {
     mysneak = present("TSR80",TP);
     if(objectp(mysneak)) mysneak->force_cancel();
   }
   if (TP->query_invis()) return notify_fail("That wouldn't work well when you're invisible!\n");
   if (sizeof((object *)TP->query_attackers())) return notify_fail("You're too busy to do that!\n");

   if (!str) return notify_fail("Whistle for what?\n");
   if(!sscanf(str,"for %s",str2)) return notify_fail("Syntax: whistle for <mount-name>.");

   tell_room(ETP,"%^YELLOW%^"+TP->QCN+" lets out a sharp whistle.%^RESET%^");
   if(ETP->query_property("teleport proof") || ETP->query_property("no teleport") || ETP->query_property("indoors")) {
     tell_object(TP,"You don't think even the best trained of mounts could find its way here.");
     return 1;
   }
   if(TP->add_active_pet(str2)) {
     tell_object(TP,"Your "+str2+" comes brisky to your side.");
     tell_room(ETP,"The "+str2+" comes brisky to "+TP->QCN+"'s side.",TP);
     return 1;
   }
   tell_object(TP,"You don't seem to own a "+str2+".");
   tell_room(ETP,"Nothing happens.",TP);
   return 1;
}

int help(){

   write(
@OLI
   Whistle
   
   Usage: whistle for <mount-name>

   This will call any trained mount that you own to your side. It will not work in places where they are unable to follow you, such as enclosed surroundings or magically warded areas. See <horses> for a list of your current mounts.

   Note: this command will have difficulties calling out more than one of the same type of horse, if you own several of the same kind.

See also:  horses, shoo
OLI
      );
   return 1;
}
