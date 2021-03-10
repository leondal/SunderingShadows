#include <std.h>
inherit WEAPONLESS;

void create()
{
   ::create();
   set_name("sheep");
   set_short("A small spotted lamb");
   set_id(({"sheep","spotted sheep","fluffy sheep","lamb","small lamb","spotted lamb", "animal"}));
   set_long(
      "The small lamb has a thick woolen coat that is spotted black "+
      "and white.  Not quite as handsome as his parents, the lamb is "+
      "nonetheless quite cute with fluffy fur flowing everywhere.  "+
      "His face has a distinctive spot in the center of his forehead, "+
      "and he watches everything with a curious expression."
   );
   set_race("sheep");
   set_body_type("quadruped");
   set_size(1);
   set_gender("male");
   set_alignment(5);
   set("aggressive",0);
   set_hd(1,4);
   set_hp(random(10)+15);
   set_overall_ac(8);
   set_class("fighter");
   set_mlevel("fighter",2);
   set_damage(1,4);
   set_attacks_num(2);
   set_base_damage_type("bludgeoning");
   set_attack_limbs(({"right forepaw","left forepaw","head"}));
   set_exp(15);
   set_emotes(6,({
   "The lamb bounds over a rocky outcropping.",
   "The lamb pauses and nuzzles the ground, eating a bit of grass.",
   "The lamb wrinkles his nose and bleats loudly."
   }),0);
   set_max_level(5);
}
