#include <std.h>
#include "../dragon.h";

inherit WEAPONLESS;

void create() {
   ::create();
   set_name("skeleton");
   set_id(({"skeleton","sanctmob"}));
   set_short("Skeleton");
   set_long(
      "This skeletal framed creature seems to walk upon its own."+
      " It smells of corrosion and death. Its lifeless eyes glaze over the"+
      " scene with no apparent interest in anything but the living."
   );
   set_race("undead");
   set_gender("neuter");
   set_hd(15,8);
   set_class("fighter");
   set_guild_level("fighter",15);
   set_alignment(9);
   set_max_hp(189);
   set_hp(189);
   set_overall_ac(-2);
   set_property("magic resistance", 5);
   set_size(2);
   set("aggressive",30);
   set_exp(14000);
   set_attacks_num(2);
   add_limb("right fist", "right arm", 0, 0, 0);
   add_limb("left fist", "left arm", 0, 0, 0);
   set_attack_limbs(({"right fist","left fist"}));
   set_base_damage_type("bludgeoning");
   set_damage(1,12);
   set_stats("strength",20);
   set_stats("dexterity",15);
   set_max_level(23);
}
void init() {
   ::init();
   if(TP->query_invis() && !avatarp(TP)) {
      tell_object(TP,"The skeleton looks right at you.");
      TO->force_me("kill "+TP->query_name()+"");
   }
}
