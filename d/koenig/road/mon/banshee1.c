#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;

create(){
  	::create();
  	set_name("banshee");
  	set_id( ({"banshee", "a banshee", "the banshee"}) );
  	set_short("a banshee");
  	set_long("This spirit looks almost beautiful if not for the fact that "+
  		"its face is twisted into a mask of eternal pain and anger, her "+
  		"hair unkept, and her eyes (that burn like red coals) are full of "+
  		"hatred and ire. You can almost see the landscape through her and "+
  		"what clothing she wears is tattered and torn.");
  	set_race("elf");
  	set_gender("female");
  	set_body_type("human");
  	set_hd(7);
  	set_overall_ac(0);
  	set_property("strength", "magic");
  	set_alignment(9);
  	set_size(2);
  	set_max_hp(120);
  	set_hp(120);
  	set_exp(2000);
  	add_money("gold", 500 + random(1000));
  	set_wimpy(20);
  	set_wimpydir("north");
  	set_emotes(5, ({
  		"%^BOLD%^The Banshee wails horribly, freezing you to the spot!", 		"%^BOLD%^%^BLACK%^WWWWWWWWWAAAAAAIIIIIIIILLLLLLLLLLLLLLL!!!!!!!!!!"
	}) );
  	set_achats(5, ({
  		"The Banshee gives the %^BOLD%^%^BLACK%^Death Wail",
  		"%^BOLD%^%^BLACK%^The Banshee says: %^RESET%^%^BOLD%^Foolish "+
  			"Mortal you shall not escape me!!"
  	}) );
}
