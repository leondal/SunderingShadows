//marid.c

#include <std.h>
inherit WEAPONLESS;

void create(){
   ::create();
   set_name("efreeti");
   set_id(({"efreeti","Efreeti","genie"}));
   set_short("Efreeti");
   set_long(
@DESC
The efreet are creatures of the elemental plane of
fire. They are made of bronze, basalt, and solid
flames.
DESC
   );
   set_race("genie");
   set_body_type("humanoid");
   set_gender("male");
   set_class("fighter");
   set_mlevel("fighter",15);
   set_class("mage");
   set_mlevel("mage",15);
   set_guild_level("mage",15);
   set_hd(15,1);
   set_hp(150);
   set_exp(1);
   set_overall_ac(-1);
   set_alignment(8);
   set_base_damage_type("bludgeoning");
   set_attack_limbs(({"right hand","left hand"}));
   set_damage(3,8);
   set_attacks_num(1);
   set_spells(({"wall of fire","burning hands","fireball"}));
   set_spell_chance(20);
}

