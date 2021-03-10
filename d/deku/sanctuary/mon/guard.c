#include <std.h>
#include "../dragon.h";

inherit WEAPONLESS;

void create(){
   ::create();
   set_name("animated guard");
   set_id(({"guard","animated guard"}));
   set_short("Animated guard");
   set_long(
      "This is a large suit of armor that has been magically enchanted"+
      " to move as if filled by some invisible wearer."
   );
   set_class("fighter");
   set_guild_level("fighter",20);
   set_gender("neuter");
   set_race("armor");
   set_hd(20,10);
   set_alignment(5);
   set_max_hp(400);
   set_hp(400);
   set_overall_ac(-6);
   set_mob_magic_resistance("average");
   set_property("no poison", 1);
   set_size(3);
   set("aggressive",30);
   set_exp(20000);
   add_limb("right fist", "right arm", 0, 0, 0);
   add_limb("left fist", "left arm", 0, 0, 0);
   set_wielding_limbs(({"right fist","left fist"}));
   set_attack_limbs(({"right fist","left fist"}));
   set_base_damage_type("bludgeoning");
   set_attacks_num(2);
   set_damage(1,10);
   set_stats("strength",17);
   set_stats("dexterity",18);
   set_max_level(23);
}
