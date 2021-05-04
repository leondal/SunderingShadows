//      _give.c
//      Mostly the _give.c from the TMI distribution mudlib.
//      Written by Sulam 12.12.91
//      Help added 1.28.92 by Brian
//      Fixed for the Nightmare monetary system by Descartes of Borg 
//      31 October 1992
// Light checking added by Hanse 4/11/92  :P

#include "move.h"
#include <std.h>

inherit DAEMON;

int
help();

cmd_give(string str) {
   object ob, to;
   string what, who, type;
   int i, amount;
   int dummy;
   object *inv;

   if(!stringp(str)) return help();

   if (TP->query_bound()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
//   dummy =effective_light(this_player());
//   if(dummy + TP->query_sight_bonus() < -1) {
   dummy = TP->light_blind(-1);
   if(dummy) {
  write(TP->light_blind_fail_message(dummy));
      return 1;
   }
   if(sscanf(str,"%s to %s", what, who) != 2) {
      return help();
   }
   to = present(who, environment(this_player()));
   if(!to) {
      notify_fail("Give "+what+" to who?\n");
      return 0;
   }
  if(to == TP) return notify_fail("Just keep it.\n");
   ob = present(what, this_player());
   if(!ob) {
      ob = parse_objects(this_player(), what);
      if(!ob) {
         if(sscanf(what, "%d %s coins", amount, type) !=2) {
            notify_fail("You must have an object to give it away!\n");
            return 0;
         }
         if(amount<0) {
            notify_fail("Yeah, right.\n");
            return 0;
         }
         if(amount > (int)this_player()->query_money(type)) {
            notify_fail("You don't have that much!\n");
            return 0;
         }
         write("You give " + amount + " " + type + " coins to " +
               to->query_cap_name() + ".");
         tell_room(environment(this_player()), this_player()->query_cap_name()
                   + " gives some money to " + to->query_cap_name() + ".", ({ this_player(), to}) );
         tell_object(to, this_player()->query_cap_name() +
                     " gives you " + amount + " " + type + " coins.");
         this_player()->add_money(type, -amount);
         to->add_money(type, amount);
         return 1;
      }
   }
   if(!living(to)) {
      notify_fail("Only living objects can accept items.\n");
      return 0;
   }
   if(to->query_ghost()) {
      notify_fail(to->query_cap_name()+" is unable to hold anything in that state!\n");
      return 0;
   }
   if(ob->drop()) {
      notify_fail("You cannot give that away!\n");
      return 0;
   }

   if(!ob->get()) {
      notify_fail("You cannot give that away!\n");
      return 0;
   }
   
    if(member_array(to, this_player()->query_attackers()) >= 0)
        return notify_fail("You cannot give items to someone you're fighting!\n");
    
   i = (int) ob->move(to);
   switch(i) {
   case MOVE_OK: {
         write("You give " + ob->query_short() + " to " +
               to->query_cap_name() + ".");
         tell_room(ETP,this_player()->query_cap_name()+" gives "+ob->query_short()+
                   " to " + to->query_cap_name() + ".",({TP,to}));
         tell_object(to,this_player()->query_cap_name()+" gives you "+
                     ob->query_short() + ".");
                       to->receive_given_item(ob);

         return 1;
      }
   case MOVE_NO_ROOM: {
       tell_object(TP,to->query_short()+" can't carry any more.\n");
         return 1;
      }
   default: {
         notify_fail("Oops, can't do that.\n");
         return 0;
      }
   }
}

int
help() {
   write("
%^CYAN%^NAME%^RESET%^

give - give something to someone

%^CYAN%^SYNOPSIS%^RESET%^

give %^ORANGE%^%^ULINE%^ITEM%^RESET%^ to %^ORANGE%^%^ULINE%^TARGET%^RESET%^
give %^ORANGE%^%^ULINE%^AMOUNT%^RESET%^ %^ORANGE%^%^ULINE%^TYPE%^RESET%^ coins to %^ORANGE%^%^ULINE%^TARGET%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This command will attempt to move an item from your inventory to %^ORANGE%^%^ULINE%^TARGET%^RESET%^'s inventory. It might fail if target already has too much on them.

To give money, for example, use %^ORANGE%^<give 10 gold coins to Alice>%^RESET%^.

%^CYAN%^SEE ALSO%^RESET%^

get, look, glance, spy, steal, pp
");
   return 1;
}
