//cut exp. from 750 to 250 - way too much comparing to difficulty  Styx 8/3/01
#include <std.h>
inherit "/std/monster";

create() {
    ::create();
	set_name("dwarf");
	set_id( ({ "dwarf","guard","mountain dwarf" }) );
	set_race("dwarf");
	set_gender("male");
    set("short","Mountain dwarf");
    set_long("This is a mountain dwarf guard.  He protects the caverns\n"+
    "from all invaders.  He looks pretty muscular.");
	set("aggressive",1);
  	set_alignment(3);
  	set_hd(8,1);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",17);
   	set_stats("charisma",3);
    set_stats("dexterity", 15);
    set_exp(250);
    set_hp(82);
   	set_stats("constitution",17);
   	new("/d/common/obj/weapon/battle_axe")->move(TO);
    command("wield axe");
	add_money("silver",random(10));
	add_money("copper",random(20));
    set_emotes(10, ({"%^MAGENTA%^Dwarf says%^RESET%^: No one may adventure the caverns of Echoes Mountains safely.",
    "%^MAGENTA%^Dwarf says%^RESET%^: Return to the surface before you die."}), 0);
  
}
