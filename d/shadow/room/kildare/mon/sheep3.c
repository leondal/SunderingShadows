#include <std.h>
inherit WEAPONLESS;

void create()
{
   ::create();
   set_name("sheep");
   set_short("A horned ram");
   set_id(({"sheep","horned sheep","ram","horned ram", "animal"}));
   set_long(
      "This large sheep is darker in color than the rest, his "+
      "wool being a deep gray.  He has long horns that curve "+
      "back over his head, and he seems stouter than the ewes "+
      "and lambs.  He stands protectively over the other sheep and "+
      "would probably not like you messing with them."
   );
   set_race("sheep");
   set_body_type("quadruped");
   set_size(1);
   set_gender("male");
   set_alignment(5);
   set("aggressive",0);
   set_hd(3,4);
   set_hp(random(10)+35);
   set_overall_ac(4);
   set_class("fighter");
   set_mlevel("fighter",6);
   set_damage(1,4);
   set_attacks_num(2);
   set_base_damage_type("bludgeoning");
   set_attack_limbs(({"right forepaw","left forepaw","head"}));
   set_exp(50);
   set_emotes(6,({
   "The ram paws at the ground and lowers his horns.",
   "The ram takes off at a sprint and headbutts a rocky outcropping.",
   "The ram bleats loudly as he watches the paddock."
   }),0);
   set_max_level(5);
}
