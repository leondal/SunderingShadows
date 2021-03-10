#include <std.h>

inherit DAEMON;

int cmd_unbind(string str){
   int delay;
   object who;

   if (TP->query_bound()) {
      TP->send_paralyzed_message("info",TP);
      return 1;

   }


   if (!str) {
      return notify_fail("Unbind whom?\n");
   }

   if (sizeof(TP->query_attackers())) {
      return notify_fail("You're too busy right now.\n");
   }


   if (!objectp(present(str,ETP))) {
      return notify_fail("That is not here.\n");
   }

//   if (!(who = present(str, ETP)) || (avatarp(who) && !who->query_disguised())) {
   if (!objectp(who = present(str,ETP))) {
      return notify_fail("That is not here.\n");
   }
   if(!TP->ok_to_kill(who)) return notify_fail("Supernatural forces prevent you from doing that.\n");

   if (!who->query_bound()) {
      return notify_fail("That person is not bound.\n");
   }

   tell_room(ETP,"%^BOLD%^"+TPQCN+" starts to unbind "+who->query_cap_name()+".",({TP,who}));
   tell_object(TP,"%^BOLD%^You start to unbind "+who->query_cap_name()+".");
   if (!who->query_unconscious()) {
      tell_object(who,"%^BOLD%^"+TPQCN+" starts to unbind you.");
   }
   delay = (20 - ((int)TP->query_skill("rope use")/2));
   call_out("unbind",delay, who, TP);

   return 1;

}

void unbind(object who, object tp){
   

   if (environment(who) != environment(tp)) {
      tell_object(tp,"You are no longer in the room with "+who->query_cap_name());
       return;
   }
   
   if (sizeof(tp->query_attackers())) {
      tell_object(tp,"%^BOLD%^You can not unbind "+who->query_cap_name()+" while fighting.");
      return;
   }



   tell_room(environment(tp),"%^BOLD%^"+tp->query_cap_name()+" unbinds "+who->query_cap_name()+".",({tp,who}));
   tell_object(tp,"%^BOLD%^You unbind "+who->query_cap_name()+".");
   if (!who->query_unconscious()) {
      tell_object(who,"%^BOLD%^"+tp->query_cap_name()+" unbinds you.");
   }
   who->set_bound(0);

}

void help(){
   write(
"
%^CYAN%^NAME%^RESET%^

unbind - unbind someone

%^CYAN%^SYNOPSIS%^RESET%^

unbind %^ORANGE%^%^ULINE%^TARGET%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This will free a bound %^ORANGE%^%^ULINE%^TARGET%^RESET%^. Unbinding does take some time.

%^CYAN%^SEE ALSO%^RESET%^

bind, rope use, submit, ungag, unblindfold, drop, strip, pkilling, rules

"       
       );
   return 1;
}
