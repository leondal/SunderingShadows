#include <std.h>
inherit "/std/comp_vend";

void create(){
	::create();
	set_name("melkior");
	set_short("Melkior Rashlavok, crystal store proprieter");
	set_id(({"melkior","Melkior","Melkior Rashlavok","Rashlavok","rashlavok","shopkeeper"}));
	set_long(
         "%^RESET%^%^CYAN%^A middle-aged man of apparent affluence, "+
         "Melkior has %^ORANGE%^coffee-brown skin %^CYAN%^shrouded in "
         "a sumptuous velvet robe of %^BOLD%^%^BLACK%^midnight black "+
         "%^RESET%^%^CYAN%^with thickly %^RED%^embroidered bands "+
         "%^CYAN%^around the cuffs and hem.  The robe is high-collared"+
         ", brushing his cheeks as he peers over it at you.  Fine-quality "+
         "shoes of %^ORANGE%^soft leather %^CYAN%^brush their way across "+
         "the crystalline floor as he moves about.  His thinning "+
         "%^BOLD%^%^BLACK%^sab%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^e hair "+
         "%^RESET%^%^CYAN%^is cropped into a short, severe cut that just "+
         "whispers across the tips of his ears.  His %^BLUE%^dark eyes "+
         "%^CYAN%^bear a cold, calculating intelligence that seems to "+
         "measure every newcomer to the store.  As he moves to "+
         "help customers with their orders, his slender fingers "+
         "%^BOLD%^gl%^WHITE%^i%^CYAN%^tt%^WHITE%^e%^CYAN%^r "+
         "%^RESET%^%^CYAN%^with rings.");
	set_race("human");
	set_gender("male");
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
    set_shop_type("psion");
    set_components(100);
	set("aggressive",0);
	add_money("gold",random(50));
}
