#include <std.h>
inherit WEAPONLESS;

void create()
{
   ::create();
   set_name("sheep");
   set_short("A fluffy white sheep");
   set_id(({"sheep","white sheep","fluffy sheep","ewe", "animal"}));
   set_long(
      "This sheep is fairly large and docile.  Her woolen "+
      "coat is fluffy white and looks very soft.  The sheep "+
      "is spotless, save for a darkened muzzle and hooves.  "+
      "She spends most of her time eating grass in the paddocks "+
      "and watching over the lambs."
   );
   set_race("sheep");
   set_body_type("quadruped");
   set_size(1);
   set_gender("female");
   set_alignment(5);
   set("aggressive",0);
   set_hd(1,4);
   set_hp(random(10)+15);
   set_overall_ac(6);
   set_class("fighter");
   set_mlevel("fighter",2);
   set_damage(1,4);
   set_attacks_num(2);
   set_base_damage_type("bludgeoning");
   set_attack_limbs(({"right forepaw","left forepaw","head"}));
   set_exp(25);
   set_emotes(6,({
   "The sheep chews lazily on some grass.",
   "The ewe looks out over the paddock and moves closer to the lambs.",
   }),0);
   set_max_level(5);
}
