//gfelemental.c

#include <std.h>

inherit WEAPONLESS;

void create(){
   int num;

   ::create();
   set_name("greater fire elemental");
   set_id(({"fire","fire elemental","elemental","felemental"}));
   set_short("Greater Fire Elemental");
   set_long(
@PEG
  %^BOLD%^%^YELLOW%^This is a Greater Fire Elemental, a gigantic being enshrouded and
completely made of %^RED%^fire%^YELLOW%^.  Its features are defined merely by the
color of the flames and their shape.  In the %^BLUE%^bluish%^YELLOW%^ flames that
serve it as eyes, you can see only a dumb, but potent malice.
PEG
   );
   set_hd(16,1);
   set_hp(128);
   set_exp(10000);
   set_stats("strength",18);
   set_stats("intelligence",7);
   set_stats("dexterity",4);
   set_race("elemental");
   add_limb("torso","torso",50,0,2);
   add_limb("right flame","torso",50,0,2);
   add_limb("left flame","torso",50,0,2);
   add_limb("base","torso",50,0,2);
   set_attack_limbs(({"left flame", "right flame"}));
   set_damage(3,8);
   set_attacks_num(1);
   set_base_damage_type("bludgeoning");
   set_gender("sexless");
   set_overall_ac(0);
   set_property("weapon resistance", 2);
}


