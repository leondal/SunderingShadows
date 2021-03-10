//bat.c - updated to current code by Circe 8/25/03
#include <std.h>
inherit MONSTER;

void create() {
   ::create();
   set_name("bat");
   set_id(({"bat","monster"}));
   set_short("A big bat");
   set_long("This large bat has brownish-black leathery skin and beady "+
      "eyes that glow red in the darkness.  His wings are very thin, revealing "+
      "veins just below the surface of the skin.  His clawed feet would probably "+
      "make formidable weapons, especially around the delicate tissue of his "+
      "victim's face.");
   set_gender("male");
   set_race("bat");
   set_body_type("fowl");
   remove_limb("beak");
   set_level(1);
   set_alignment(2);
   set("aggressive",20);
   set_size(1);
   set_overall_ac(10);
   set_stats("intelligence",6);
   set_stats("wisdom",4);
   set_stats("strength",3);
   set_stats("charisma",3);
   set_stats("dexterity",8);
   set_stats("constitution",7);
   set_hd(1,1);
   set_max_hp(query_hp());
   set_max_hp(query_hp());
   add_money("copper",random(2));
   set_max_level(10);

}

