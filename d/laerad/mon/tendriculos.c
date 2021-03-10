//Tendriculos for the ruins of Asgard by ~Circe~ 5/27/13
//Loosely based on /d/laerad/mon/titan.c

#include <std.h>
inherit WEAPONLESS;

void create(){
   ::create();
   set_id(({"tentriculos","plant","forestmon"}));
   set_name("Tendriculos");
   set_short("%^RESET%^%^GREEN%^wri%^BOLD%^t%^RESET%^%^GREEN%^hi%^BOLD%^"
      "n%^RESET%^%^GREEN%^g te%^BOLD%^n%^RESET%^%^GREEN%^dri%^YELLOW%^c"
      "%^RESET%^%^GREEN%^ulos%^RESET%^");
   set_long("%^RESET%^%^GREEN%^Looking like a fifteen-foot-tall hillock, "
      "this plant creature exudes a sense of wrongness that causes even "
      "the wildlife to flee.  Covered with vegetation in shades of %^BOLD%^"
      "green%^RESET%^%^GREEN%^, %^ORANGE%^brown%^GREEN%^, and %^BOLD%^"
      "%^BLACK%^gray%^RESET%^%^GREEN%^, the aura of %^BOLD%^%^BLACK%^ma"
      "%^RED%^l%^BLACK%^ice %^RESET%^%^GREEN%^belies its true nature.  "
      "Thick vines sprout from the creature's base, reaching out to haul "
      "in its prey.%^RESET%^");
   set_body_type("human");
   set_property("magic",1);
   set_race("tendriculos");
   set_gender("neuter");
   set_size(4);
   set_alignment(6);
   set_overall_ac(-25);
   set("aggressive",24);
   set_max_level(28);
   set_class("fighter");
   set_property("full attacks",1);
   set_attacks_num(2);
   set_base_damage_type("bludgeoning");
   set_fake_limbs(({"body mass","right vine","left vine"}));
   set_attack_limbs(({"right vine","left vine"}));
   set_damage(3,10);
   set_hd(25,200);
   set_hp(600+random(350));
   set_new_exp(25,"normal");
   set_attack_bonus(4);
   add_money("gold",random(2000)+250);
   add_money("silver",random(2000)+250);
   add_money("copper",random(2000)+250);
   set_func_chance(15);
   set_funcs(({"smash","smash","smash","swallow"}));
   command("message in shambles in");
   command("message out shambles $D");
   set_moving(1);
   set_speed(10);
}

void heart_beat(){
   ::heart_beat();
   if(query_hp() < query_max_hp()){
      add_hp(10);
   }
}

void set_paralyzed(int time,string message){return 1;}

void die(mixed ob){
   object obj;
   if(!random(2)){
      switch(random(12)){
         case 0: obj = new("/d/common/obj/rand/epants");
                 obj->set_property("enchantment",1);
                 obj->move(TO);
                 break;
         case 1: obj = new("/d/common/obj/rand/cloak");
                 obj->set_property("enchantment",2+random(2));
                 obj->move(TO);
                 break;
         case 2: obj = new("/d/common/obj/rand/mage_robes");
                 obj->set_property("enchantment",1);
                 obj->move(TO);
                 break;
         case 3: obj = new("/d/common/obj/rand/menshirt");
                 obj->move(TO);
                 break;
         case 4: obj = new("/d/common/obj/rand/r_helm");
                 obj->move(TO);
                 break;
         case 5: obj = new("/d/common/obj/rand/r_shoes");
                 obj->set_property("enchantment",1);
                 obj->move(TO);
                 break;
         case 6: obj = new("/d/common/obj/rand/rand_chain");
                 obj->set_property("enchantment",1);
                 obj->move(TO);
                 break;
         case 7: obj = new("/d/common/obj/rand/rand_leath_head");
                 obj->move(TO);
                 break;
         case 8: obj = new("/d/common/obj/rand/rand_shirts");
                 obj->set_property("enchantment",1);
                 obj->move(TO);
                 break;
         case 9: obj = new("/d/common/obj/rand/s_curiass");
                 obj->set_property("enchantment",1);
                 obj->move(TO);
                 break;
         case 10: obj = new("/d/common/obj/rand/steelshield");
                 obj->move(TO);
                 break;
         default: obj = new("/d/common/obj/rand/womendress");
                 obj->move(TO);
                 break;
      }
   tell_room(ETO,"%^RESET%^%^GREEN%^As the tendriculous dies, you "
      "catch sight of something in the mess of vines.%^RESET%^");
   }
   ::die(ob);
}

void smash(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   tell_object(targ,"%^BOLD%^%^GREEN%^The thick vines of the tendriculos "
      "slam into you!%^RESET%^");
   tell_room(ETO,"%^BOLD%^%^GREEN%^The thick vines of the tendriculos "
      "slam into "+targ->QCN+"!%^RESET%^",targ);
   targ->do_damage(targ->return_target_limb(),random(10)+30);
   return;
}

void swallow(object targ){
   int dam;
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   tell_object(targ,"%^GREEN%^The tendriculos grabs you, holding you tight as "
      "it begins to drag you toward its body.%^RESET%^");
   tell_object(targ,"%^BOLD%^%^GREEN%^You are swallowed whole!%^RESET%^");
   tell_room(ETO,"%^GREEN%^The tendriculos grabs "+targ->QCN+" and pulls "
      ""+targ->QO+" close before swallowing "+targ->QO+" whole!%^RESET%^",targ);
   dam = (int)targ->query_hp()/2;
   targ->do_damage((string)targ->return_target_limb(),dam);
   targ->set_paralyzed((30+random(30)),"%^BOLD%^You are trying to fight your way out of the tendriculos!%^RESET%^");
   return;
}
