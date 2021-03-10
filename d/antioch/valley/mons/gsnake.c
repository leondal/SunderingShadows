//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
inherit WEAPONLESS;

void create(){
   ::create();
   set_name("grass snake");
   set_short("%^BOLD%^%^GREEN%^A bright green snake%^RED%^");
   set_id(({"snake","grass snake","green snake","bright green snake"}));
   set_long("%^BOLD%^%^GREEN%^The snake before you is only about four"+
   " feet in length and is covered in bright green scales. A few"+
   " %^YELLOW%^cream stripes%^GREEN%^ run down either side of the"+
   " creature. A %^RED%^red%^GREEN%^ forked tongue slides out every"+
   " now and then to test the air. It slithers slowly through the"+
   " grass, content to search for insects and mice.");
   set_gender("neuter");
   set_race("snake");
   set_body_type("snake");
   set_hd(6,9);
   set_level(6);
   set_class("fighter");
   set_mlevel("fighter",6);
   set_size(1);
   add_limb("fangs","mouth",0,0,0);
   set_attack_limbs(({"fangs"}));
   set_attacks_num(2);
   set_base_damage_type("piercing");
   set_damage(1,6);
   set_overall_ac(0);
	set_max_hp(random(20)+50);
	set_hp(query_max_hp());
//   set_exp(450);
	set_new_exp(6,"normal");
   set_max_level(15);
	set_property("swarm",1);
   set_funcs(({"coil"}));
   set_func_chance(10);
}

int coil(object targ)
{
   if(targ->query_stats("dexterity") < random(20)) {
      tell_object(targ,"%^GREEN%^You step to the side as the grass"+
      " snake lunges towards you.");
      tell_room(ETO,"%^GREEN%^"+targ->query_cap_name()+" steps to the"+
      " side as the grass snake lunges towards "+targ->query_objective()+".",targ);
      return 1;
   }
   tell_object(targ,"%^BOLD%^%^GREEN%^The grass snake coils itself"+
   " around your feet, causing you to fall!");
   tell_room(ETO,"%^BOLD%^%^GREEN%^The grass snake coils around"+
   " "+targ->query_cap_name()+", causing "+targ->query_objective()+" to"+
   " fall!",targ);
   targ->set_tripped(3,"You're still getting your footing!");
   targ->do_damage("torso",random(4)+5);
   return 1;
}
