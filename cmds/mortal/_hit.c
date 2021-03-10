#include <std.h>

inherit DAEMON;

int cmd_hit(string str){

   object who;


   if (TP->query_bound()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }

   if (!str) {
      return notify_fail("Hit whom?\n");
   }


   if (!objectp(present(str,ETP))) {
      return notify_fail("That is not here.\n");
   }

   if (!who = present(str,ETP) || (avatarp(who) && !who->query_disguised())) {
      return notify_fail("That is not here.\n");
   }

   if( (!userp(who)) && (!who->is_townsman()) && (!who->is_npc())) {
     if (who->query_hp() > 0)
      return notify_fail("He's not quite dead yet.\n");
     who->cease_all_attacks();
     tell_room(ETP,"%^BOLD%^"+TPQCN+" takes a vicious swing at "+who->query_cap_name()+".",({TP,who}));
     tell_object(TP,"%^BOLD%^You take a vicious swing at "+who->query_cap_name()+".");
    who->add_attacker(TP);
     who->die(TP);
//     who->remove_attacker(TP);
     return 1;
   }
   

   if (sizeof(TP->query_attackers())) {
      return notify_fail("You're busy trying to avoid those other folks' hits.\n");
   }

   if (!TP->ok_to_kill(who)) {
      return notify_fail("Supernatural forces prevent your attack.\n");
   }

   tell_room(ETP,"%^BOLD%^"+TPQCN+" takes a vicious swing at "+who->query_cap_name()+".",({TP,who}));
   tell_object(TP,"%^BOLD%^You take a vicious swing at "+who->query_cap_name()+".");
   if (!who->query_unconscious()) {
      tell_object(who,"%^BOLD%^"+TPQCN+" takes a vicious swing at you.");
   }
   if (who->query_unconscious() || who->query_bound()) {     
      TP->add_attacker(who);
      who->set_property("to die",1);
      TP->execute_attack();
      who->continue_attack();
   if(!objectp(who)) return 1;
      //who->remove_property("to die");
   } else {
      TP->kill_ob(who,1);
      who->set_property("to die",1);
      TP->execute_attack();
      //who->remove_property("to die");
   }

   TP->set_disabled(1);
   return 1;

   
   
}

void help(){
   write(
"
%^CYAN%^NAME%^RESET%^

hit - end a being

%^CYAN%^SYNOPSIS%^RESET%^

hit %^ORANGE%^%^ULINE%^TARGET%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This will end existence of a %^ORANGE%^%^ULINE%^TARGET%^RESET%^ and will turn them into a corpse if their hp is below 0, effectively killing them.

Playes go unconcious if their hp goes below 0, so use this command to make them dead.

%^CYAN%^SEE ALSO%^RESET%^

kill, pkilling, rules
"
      );
}
