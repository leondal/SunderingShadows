#include <std.h>
inherit DAEMON;

object current_room, obj;

int cmd_hide_in_shadows()
{
   int myskill;
   object ob;
   if(!objectp(TP)) { return 0; }
   if(!objectp(ETP)) { return 0; }

/*   if(!TP->is_class("thief")) {
      notify_fail("You can't do that!\n");
      return 0;
   }*/

   if (TP->query_bound() || TP->query_tripped()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }

   if((string *)TP->query_attackers() != ({})) {
      notify_fail("You are too busy to hide right now!\n");
      return 0;
   }
   TP->set_paralyzed(1,"You are trying to hide");
   if((int)this_player()->query_magic_invis()) {
      notify_fail("You attempt to hide in the shadows.\n");
      return 0;
   }
   myskill = TP->query_skill("stealth") + roll_dice(1,20);
   if((int)TP->query_property("chameleoned") > 0){
      myskill += (int)TP->query_property("chameleoned");
//      tell_object(TP,"Chameleon skin bonus = "+(int)TP->query_property("chameleoned")+".");
   }

   if(sizeof(TP->query_armour("torso"))) myskill += TP->skill_armor_mod(TP->query_armour("torso"));
   if(sizeof(TP->query_armour("left foot"))) myskill += TP->skill_armor_mod(TP->query_armour("left foot"));
   if(sizeof(TP->query_armour("right foot"))) myskill += TP->skill_armor_mod(TP->query_armour("right foot"));
   if(TP->query_in_vehicle()){
     write("You can't hide while you're riding.");
     return 1;
   }
   if(myskill >= 20) {
      write("You attempt to hide in the shadows.");
      TP->set_hidden(1);
      } else {
      if(ob = present("TSR80",TP)) ob->dest_fun();
      write("You attempt to hide in the shadows.");
      tell_room(environment(TP),"You see "+TPQCN+" attempt to hide in the shadows.",TP);
      return 1;
   }
   seteuid(getuid());
   obj = new("/cmds/mortal/hide.c");
   obj->set_player(TP);
   obj->move(TP);
   return 1;
}

void help() {
   write(
"
%^CYAN%^NAME%^RESET%^

hide_in_shadows - try to hide in plain sight

%^CYAN%^DESCRIPTION%^RESET%^

This command will let you attempt to hide in plain sight, making you invisible to other beings. You won't be able to tell if you're hidden, though. Success of this command will depend on your stealth skill.

To become visible again, use %^ORANGE%^<step>%^RESET%^ to step out of shadows.

%^CYAN%^SEE ALSO%^RESET%^

sneak, flee, stealth, stab, eavesdrop, spy
"
        );
}
