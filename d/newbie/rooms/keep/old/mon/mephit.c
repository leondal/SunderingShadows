#include <std.h>
inherit WEAPONLESS;

void create()
{
   ::create();
   set_name("steam mephit");
   set_short("A steam mephit");
   set_id(({"mephit","imp","steam mephit"}));
   set_long(
   "The imp is small and cruel looking and has scalding steam rising out of"+
   " its pores. Hardened black claws can be found on each hand. It has a"+
   " long, hooked nose and pointed ears, with a large chin. Its wide face"+
   " is grinning in delight as it attacks you."
   );
   set_gender("neuter");
   set_race("imp");
   set_body_type("humanoid");
   set_size(1);
   set_hd(8,6);
   set_level(8);
   set_class("mage");
   set_mlevel("mage",8);
   set_alignment(3);
   set_overall_ac(6);
   set_hp(random(20)+50);
   add_limb("right claw","right hand",0,0,0);
   add_limb("left claw","left hand",0,0,0);
   set_damage(1,5);
   set_attacks_num(2);
   set_base_damage_type("slashing");
   set_attack_limbs(({"mouth","left claw","right claw"}));
   set_hit_funcs((["mouth" : (:TO,"breath":) ]));
   set_property("swarm",1);
   set("aggressive",25);
   set_exp(1000);
   set_funcs(({"cloud"}));
   set_func_chance(10);
}

void init()
{
   ::init();
   if(avatarp(TP) && TP->query_invis()) return;
   if((string)TP->query_name() == "steam mephit") return;
   force_me("kill "+TPQCN+"");
}

int breath(object targ)
{
   tell_object(targ,"%^BOLD%^The mephit breathes a cloud of scalding steam at you!");
   tell_room(ETO,"%^BOLD%^The mephit breathes a cloud of scalding steam at "+targ->query_cap_name()+"!",targ);
   if(!random(2)) {
      targ->set_paralyzed(2,"You're recovering from the steam!");
   }
   return 3;
}

void cloud(object targ)
{
   int i, j;
   object *inven;

   inven = all_living(ETO);
   j = sizeof(inven);

   tell_room(ETO,"%^BOLD%^%^CYAN%^The mephit creates a storm of boiling steam!");
   for(i=0;i<j;i++) {
      if(!objectp(inven[i])) continue;
      if(inven[i]->query_true_invis()) continue;
      if(inven[i] == TO) continue;
      if((string)inven[i]->query_name() == "steam mephit") continue;
      tell_object(inven[i],"%^YELLOW%^The steam scalds your flesh!");
      inven[i]->do_damage("torso",random(11)+2);
      return;
   }
   return;
}
