#include <std.h>
inherit "/std/psi_comp_vend";

void create(){
	::create();
	set_name("natalia");
	set_short("Natalia Floros, a simple gemcutter");
	set_id(({"natalia","Natalia","Floros","Natalia Floros","gemcutter","gem cutter","cutter","shopkeeper"}));
	set_long(
         "%^RESET%^%^CYAN%^Graced by luxurious %^BOLD%^%^BLACK%^"+
         "raven black hair%^RESET%^%^CYAN%^ that reaches just past "+
         "her waist, Natalia is a woman just out of her youth.  "+
         "Her serene %^BOLD%^%^BLUE%^blue eyes %^RESET%^%^CYAN%^"+
         "are lightly lined at the corners, concealed somewhat by "+
         "the makeup she wears.  She is dressed simply, wearing a "+
         "%^GREEN%^deep green velvet dress %^CYAN%^with a plunging "+
         "neckline trimmed with %^BOLD%^%^BLACK%^black piping%^RESET%^"+
         "%^CYAN%^.  Her feet are clad in simple matching slippers, "+
         "and her slender hands are marked by faint %^RESET%^white "+
         "scars %^CYAN%^caused from years of cutting crystals."
	);
	set_race("human");
	set_gender("female");
	set_hd(30,4);
	set_max_hp(250+random(50));
	set_hp(query_max_hp());
	set_overall_ac(-12);
	set_alignment(4);
	set_class("psion");
	set_class("cleric");
	set_mlevel("psion",30);
	set_mlevel("cleric",30);
	set_level(30);
	set_stats("intelligence",18);
	set_stats("wisdom",18);
	set_stats("charisma",16);
	set_stats("strength",9);
	set_stats("constitution",8);
	set_stats("dexterity",14);
	set_spells(({
	"flame strike",
	"limb attack",
      "mind thrust",
      "breath of the black dragon"
	}));
	set_spell_chance(100);
	set_exp(100);
      set_components(100);
	set("aggressive",0);
	add_money("gold",random(50));
}
