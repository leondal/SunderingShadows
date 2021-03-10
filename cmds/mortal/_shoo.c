// new command to dismiss mounts.
#include <std.h>
inherit DAEMON;

int cmd_shoo(string str) {
   object what, mysneak;

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

   if (!str) return notify_fail("Shoo what?\n");
   if (!what = present(str, ETP)) return notify_fail("That is not here.\n");

   if(TP != (object)what->query_owner()) {
     tell_object(TP,"The "+what->query_name()+" just ignores you.");
     tell_room(ETP,"%^YELLOW%^"+TP->QCN+" attempts to chase the "+what->query_name()+" away, but it ignores "+TP->QP+" efforts.%^RESET%^");
     return 1;
   }

   tell_object(TP,"You shoo the "+what->query_name()+" away.");
   tell_room(ETP,"%^YELLOW%^"+TP->QCN+" shoos the "+what->query_name()+" away.%^RESET%^",TP);
   TP->remove_active_pet(what);
   tell_room(ETP,"The "+what->query_name()+" takes the hint and makes itself scarce.");
   what->move("/d/shadowgate/void");
   what->remove();
   return 1;
}

int help(){

   write(
@OLI
%^CYAN%^NAME%^RESET%^

shoo - shoo a thing

%^CYAN%^SYNOPSIS%^RESET%^

shoo MOUNT

%^CYAN%^DESCRIPTION%^RESET%^

This will chase away any mount you may have near you, to prevent them getting into a dangerous situation. It will not work in places where they have nowhere to go, such as enclosed surroundings or magically warded areas.

%^CYAN%^SEE ALSO%^RESET%^

whistle, horses
OLI
      );
   return 1;
}
