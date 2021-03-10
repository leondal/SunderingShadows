/*basic dwarf file - inherit and change whatever is needed.  Be sure to add treasure, weapons, and equipment, as well as adjust levels and exp if needed. */

#include <std.h>
inherit MONSTER;

void create() {
    ::create();
	set_name("dwarf");
	set_id(({"dwarf","monster"}));
	set_race("dwarf");
	set_gender("male");
      set_short("Dwarf");
      set_long("This stout dwarf stands just under four feet tall "+
         "and nearly as broad.  His leathery face is a deep, ruddy brown "+
         "weathered with age, but his blue eyes are bright and clear.  "+
         "His long, chestnut brown hair is pulled back in a thick braid "+
         "that matches his beard, which is tucked into belt.  His clothes "+
         "are practical and colored in earth-tones, and he looks quite "+
         "capable of defending himself with the weapon in his hands.");
	set_level(8);
	set_body_type("human");
  	set("aggressive",1);
  	set_alignment(1);
  	set_size(1);
      set_hd(6,1);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",17);
   	set_stats("charisma",3);
      set_stats("dexterity", 15);
      set_exp(250);
      set_hp(75+random(15));
   	set_stats("constitution",17);
	set_max_hp(query_hp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
}