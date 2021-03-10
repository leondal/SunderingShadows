// added same paralyze delay as binding uses *Styx*  6/24/02

#include <std.h>
#include <move.h>

inherit DAEMON;

int cmd_drag(string str){
   object who;
   object drag,prev;
   int res;

   if (TP->query_bound()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }

   if (!str) {
      return notify_fail("drag whom?\n");
   }

   if (sizeof(TP->query_attackers())) {
      return notify_fail("You're too busy right now.\n");
   }
  who = present(str, ETP);
//  if (!objectp(who) || (avatarp(who) && !who->query_disguised())) {
  if(!objectp(who) || !living(who)) {
// changing so it can pass through to a local command if needed *Styx*  11/14/04
//      return notify_fail("That is not here.\n");
	write("If you get a 'What?' next, there isn't a "+str+" here that you can drag.");
	return 0;
   }
     if(!TP->ok_to_kill(who)) return notify_fail("Supernatural forces prevent you from doing that.\n");
//   if(!living(who)) return notify_fail("You cannot do that.\n"); see above change 11/14/04

   if (!who->query_bound() && !who->query_unconscious()) {
      return notify_fail("That person is not bound.\n");
   }

   if (prev = who->query_property("draggee")) {
      if (objectp(prev)) {
         if (present(environment(prev),ETP)) {
            write(who->query_cap_name()+" is already being dragged by "+environment(prev)->query_cap_name()+".\n");
            return 1;
         }
      }
   }

   TP->set_draggee(who);
   who->set_property("draggee", TP);

   tell_room(ETP,"%^BOLD%^%^GREEN%^"+TPQCN+" heaves "+who->query_cap_name()+" up and starts to drag "+who->query_objective()+".",({who,TP}));
   tell_object(TP,"%^BOLD%^%^GREEN%^You heave "+who->query_cap_name()+" up and start to drag "+who->query_objective()+".");
   if (!who->query_unconscious()) {
      tell_object(who,"%^BOLD%^%^GREEN%^"+TPQCN+" heaves you up and starts to "
          "drag you.");
   }
   TP->set_paralyzed(5,"You are busy trying to get a good enough hold of "
      +who->query_cap_name()+" to drag "+who->query_objective()+".");
   return 1;
}

int help(){
   write(
@OLI
%^CYAN%^NAME%^RESET%^

drag - drag something

%^CYAN%^SYNOPSIS%^RESET%^

drag %^ORANGE%^%^ULINE%^TARGET%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This allows you to pick and drag someone. They must be unconscious or bound. You can use either race or recognized name for the target.

%^CYAN%^SEE ALSO%^RESET%^

drop, bind, unbind, gag, ungag, pkilling, submit
OLI
      );
   return 1;
}
