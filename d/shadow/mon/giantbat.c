//giantbat.c - updated to current code by Circe - 8/25/03
#include <std.h>
inherit MONSTER;

void create() {
   ::create();
   set_name("bat");
   set_id(({"giantbat","bat","giant bat","monster"}));
   set_short("A giant bat");
   set_level(6);
   set_long("This gargantuan bat is many times larger than his smaller, "+
      "insectivorous kin.  The rabid look on his strangely human face "+
      "suggests that this particular bat might eat anything that crosses "+
      "his path.  His impressive wings are black and seem made of leather, "+
      "and his face is scarred from many previous battles.  His eyes glow "+
      "a fiery red, making him visible even in the darkness.");
   set_gender("male");
   set_race("bat");
   set_body_type("fowl");
   remove_limb("beak");
   set_alignment(2);
   set_hd(6,0);
   set("aggressive",20);
   set_size(2);
   set_overall_ac(6);
   set_stats("intelligence",6);
   set_stats("wisdom",4);
   set_stats("strength",6);
   set_stats("charisma",3);
   set_stats("dexterity",20);
   set_stats("constitution",7);
   set_max_hp(query_hp());
   add_money("copper",random(2));
   set_max_level(10);
   set_hp(random(10)+40);
   //set_exp(125);
   set_exp(500);
}
