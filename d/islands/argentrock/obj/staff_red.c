// fixing the wield to ETO from TP & inheriting from /d/common *Styx* 12/24/05

#include <std.h>

//inherit WEAPON;
inherit "/d/common/obj/weapon/quarter_staff";

int charges;
string owner;

void init() {
   ::init();
   if(interactive(TP) && TP == environment(TO) && !wizardp(TP) && !owner) {
      owner = TPQN;
      charges = 20 + random((int)TP->query_level() / 3);
   }
}

void create(){
   ::create();
   set_name("red firedoom staff");
   set_id( ({"staff","firedoom","firedoom staff","red firedoom staff"}) );
   set_short("%^RESET%^%^RED%^Firedoom staff%^RESET%^");
   set_long("%^RED%^This is a heavy quarter staff. It is forged from "+
      "some unknow glassy material found on the island of Argentrock. "+
       "Rumours about this powerful yet dangerous staff have already spread "+
      "throughout this realm. Some strange runes are carved in it.");
   set_property("enchantment",3);
   set_wc(2,5);
   set_large_wc(3,5);
   set_wield( (: TO,"more_wield" :) );
   set_hit( (: TO,"more_hit" :) );
//   set_weight(20);
   set_value(1000);
//   set_size(3);
//   set_type("bludgeoning");
//   set_prof_type("pagan staff");
   set_prof_level(40);
   set_ac(1);
}

int more_wield() {
   if( !interactive(ETO) || wizardp(ETO) )
      return 1;
   if( (int)ETO->query_level() < 30 ) {
       write("You are not powerful enough to handle this staff!");
      return 0;
   }
   else {
      if( (string)ETOQN != owner ) {
         write("%^BOLD%^%^BLUE%^The %^RESET%^RED%^Firedoom staff "+
            "%^BOLD%^%^BLUE%^fails bonding with you and vanishes.");
         TO->remove();
         return 0;
      }
      else {
         switch( (int)ETO->query_alignment() ) {
            case 7:
            case 8:
            case 9:
                if (!ETO->query_property("silent_wield")) {
                    tell_room(environment(ETO), "The %^RESET%^%^RED%^Firedoom " +
                        "staff %^RESET%^makes a loud noise as if it cheers.");
                }
               return 1;
               break;
            default:
               tell_room(environment(ETO),"The %^RESET%^%^RED%^Firedoom "+
                  "staff %^RESET%^shakes violently as if it found its "+
                  "prey.");
               ETO->do_damage("torso",20 + random(30));
               ETO->add_attacker(TO);
               ETO->continue_attack();
               ETO->remove_attacker(TO);
               return 0;
         }
      }
   }
}

int more_hit(object victim) {
   int choose,me_int,you_wis,dam,save_roll;
   choose = 1+random(2);
   me_int = (int)ETO->query_stats("intelligence");
   you_wis = (int)victim->query_stats("wisdom");
   dam = 5 + me_int - you_wis;
   if(dam <= 1)
      dam = 1;
   if(charges < 1)
      choose = 1;
   switch(choose) {
      case 1:
         if(random(10))
            return 0;
         message("my_action","The %^RESET%^RED%^Firedoom staff %^RESET%^"+
            "ejects a large %^RED%^red %^RESET%^ball of fire at "+
            victim->query_cap_name()+"'s body.",ETO);
         message("other_action","The %^RESET%^RED%^Firedoom staff "+
            "%^RESET%^wielded by "+ETO->query_cap_name()+" ejects a large "+
            "%^RED%^red %^RESET%^ball of fire at "+victim->query_cap_name()+
            "'s body.",environment(ETO),( ({ETO,victim}) ));
         message("my_action","The %^RESET%^RED%^Firedoom staff %^RESET%^"+
            "wielded by "+ETO->query_cap_name()+" ejects a large %^RED%^red "+
            "%^RESET%^ball of fire at you!",victim);
         set_property("magic",1);
         victim->do_damage(victim->return_target_limb(),roll_dice(2,dam));
         remove_property("magic");
         return 0;
         break;
      case 2:
         if( charges < 1 || random(14) )
            return 0;
         message("my_action","A bolt of lightning shoots from the "+
            "%^RESET%^RED%^Firedoom staff %^RESET%^at "+
            victim->query_cap_name()+"!",ETO);
         message("other_action","A bolt of lightning shoots from the "+
            "%^RESET%^RED%^Firedoom staff %^RESET%^wielded by "+
            ETO->query_cap_name()+" at "+victim->query_cap_name()+"!",
            environment(ETO),( ({ETO,victim}) ));
         message("my_action","A bolt of lightning shoots from the "+
            "%^RESET%^RED%^Firedoom staff %^RESET%^wielded by "+
            ETO->query_cap_name()+" at you!",victim);
         set_property("magic",1);
         victim->do_damage(victim->return_target_limb(),roll_dice(6,dam));
         remove_property("magic");
         charges -= 2;
         return 0;
   }
}
