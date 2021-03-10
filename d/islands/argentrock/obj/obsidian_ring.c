// fixing TP to properly use ETO in unwear, etc. to prevent bugs *Styx*  12/25/05

#include <std.h>

inherit "/d/common/obj/jewelry/ring.c";

int used,max_uses,ok_to_use,current_hp;

void create(){
   ::create();
   set_id( ({"ring","obsidian","obsidian ring"}) );
   set_name("obsidian ring of counter damage");
   set("short","Obsidian ring");
   set("long","This is a glassy black ring. It is made of volcanic glass "+
       "hardly seen in this realm. A small aura of magic radiates from the "+
      "ring. A small inscription is carved inside the band.");
   set_limbs( ({"left hand","right hand"}) );
   set_value(6000);
   set_wear( (: TO,"more_wear" :) );
   set_remove( (: TO,"more_remove" :) );
   set_property("magic",1);
   set_heart_beat(0);
   ok_to_use = 0;
   used = 0;
   call_out("set_max_uses",1);
   set_item_bonus("empowered",2);
}

void set_max_uses() {
   if( !objectp(TO) || !objectp(ETO) )
      return;
   max_uses = ( (int)TP->query_stats("intelligence")/3 ) + ( random(5) );
}

void query_used() {
   return used;
}

void query_max_uses() {
   return max_uses;
}

int more_wear() {
   write("%^RED%^You wear the ring and feel confident about the coming "+
      "battles.");
   say("%^RED%^"+ETOQCN+" wears the ring and appears to be a much tougher "+
      "opponent.");
   return 1;
}

int more_remove() {
   switch(ok_to_use) {
      case 1:
         write("%^BLUE%^You see the magic aura ceases as you remove the ring.");
         say("%^BLUE%^You see the magic aura of the ring worn by "+
            ETO->QCN+" cease as "+ETO->query_subjective()+
            " removes the ring.");
         set_heart_beat(0);
         ok_to_use = 0;
         break;
      case 0:
   }
    write("%^BLUE%^Your fear of death is clogging your mind now.");
    say("%^BLUE%^An expression of fear passes "+ETOQCN+"'s face.");
   return 1;
}

int read_ins(string str){
   if(!str) {
      notify_fail("Read what?\n");
      return 0;
   }
   if(str != "inscription")
      return 0;
   write("This is a ring of counter damage. It helps you a lot during "+
      "combat for a very limited number of uses.  You should %^BOLD%^"+
      "enable %^RESET%^and %^BOLD%^disable %^RESET%^the ring, although "+
      "it will be disabled automatically after a short period of time.");
   return 1;
}

int enable_ring(string str) {
   if(!str) {
      notify_fail("Enable what?\n");
      return 0;
   }
   if(str != "ring") {
      notify_fail("You cannot enable that!\n");
      return 0;
   }
   if( !TO->query_worn() ) {
      notify_fail("You have to wear it first!\n");
      return 0;
   }
   if(used > max_uses) {
      write("%^BOLD%^WHITE%^The ring has aided you enough and decided to "+
          "seek out a new master.");
      notify_fail("The ring is out of charges!\n");
      TO->remove();
      return 0;
   }
   if(ok_to_use) {
      notify_fail("The ring has been enabled already.\n");
      return 0;
   }
   set_heart_beat(1);
    write("%^RED%^You see the magic aura radiating out of the ring "+
      "intensifies.");
    say("%^RED%^You see the magic aura radiating out of the ring "+
      "worn by "+ETO->query_cap_name()+" intensifies.");
   current_hp = (int)ETO->query_hp();
   ok_to_use = 1;
   call_out("auto_disable",180);
   used++;
   return 1;
}

int disable_ring(string str) {
   if(!str) {
      notify_fail("Disable what?\n");
      return 0;
   }
   if(str != "ring") {
      notify_fail("You cannot disable that!\n");
      return 0;
   }
   if( !TO->query_worn() ) {
      notify_fail("It has been already disabled!\n");
      return 0;
   }
   if(!ok_to_use) {
      notify_fail("The ring is not functioning right now!\n");
      return 0;
   }
   set_heart_beat(0);
   write("%^BLUE%^You see the magic aura cease as you disable it.");
   say("%^BLUE%^You see the magic aura of the ring worn by "+
      ETO->QCN+" cease.");
   remove_call_out("auto_disable");
   ok_to_use = 0;
   return 1;
}

int auto_disable() {
    tell_object(ETO,"%^BLUE%^You see the magic aura that radiates out of "+
       "the ring gradually fade.");
    message("my_action","%^BLUE%^You see the magic aura that radiates "+
      "out of the ring worn by "+ETO->query_cap_name()+" gradually "+
       "fade.",environment(ETO),ETO);
   set_heart_beat(0);
   ok_to_use = 0;
   return 1;
}

void heart_beat() {
//   ::heart_beat();   // added just to be safe *Styx* 3/22/03
   object *attackers;
   int total_dam,rest_dam,each_dam,attacker_num,i;
   if( !objectp(ETO) || !objectp(TO) )
      return;
   total_dam = current_hp - (int)ETO->query_hp();
   attackers = (object *)ETO->query_attackers();
   attacker_num = sizeof(attackers);
   if(total_dam <= 0)
      return;
   if(!attacker_num)   // added to squash divide by zero error *Styx*  3/22/03
      return;
//the following code has been modified to reduce the original damage
//deal on opponents which is based on an idea of even distribution
//on everyone involved in battle which gives an obvious advantage to
//the ring wearer. -- Obsidian.
   if(attacker_num == 1)
      rest_dam = total_dam / 4;
   else if(attacker_num == 2)
      rest_dam = total_dam / 3;
   else
      rest_dam = total_dam / 2;
   each_dam = rest_dam / attacker_num;
   for(i = 0;i < attacker_num;i++) {
      tell_object(attackers[i],"%^CYAN%^You feel your lifeforce being "+
         "sucked away as you see the ring worn by "+
         ETO->query_cap_name()+" glow!");
      attackers[i]->do_damage("torso",each_dam);
   }
   ETO->do_damage( "torso",-(rest_dam) );
   tell_object(ETO,"%^CYAN%^As the ring glows, it heals you a bit.");
   tell_object(ETO,"%^CYAN%^The ring glows as it deals damage "+
       "to your opponent!");
   current_hp = (int)ETO->query_hp();
}

void init() {
   ::init();
   if( !objectp(ETO) )
      return;
   add_action("read_ins","read");
   add_action("enable_ring","enable");
   add_action("disable_ring","disable");
   call_out("check_it",1);
}

void check_it() {
   object *inven,*oring;
   int i;
   oring = ({});
   inven = deep_inventory(ETO);
   for(i = 0;i < sizeof(inven);i++) {
      if( (string)inven[i]->query_name() ==
         "obsidian ring of counter damage" )
         oring += ({inven[i]});
   }
   if( sizeof(oring) > 1 ) {
      tell_object(ETO,"%^BOLD%^%^BLUE%^The obsidian ring senses its "+
         "own kind and refuses to stay with you!");
      TO->remove();
   }
}
