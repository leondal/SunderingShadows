#include <std.h>
inherit "/std/comp_vend";

void create(){
	::create();
	set_name("andrei");
	set_short("Andrei Gadalov, proprieter of Empyreal Crystals");
	set_id(({"andrei","Andrei","Andrei Gadalov","Gadalov","gadalov","shopkeeper"}));
	set_long(
         "%^RESET%^%^CYAN%^Appearing to be only in his early "+
         "twenties, Andrei Gadalov seems to have done rather "+
         "well for himself.  His flawless %^RESET%^ivory skin "+
         "%^CYAN%^is covered in a sumptuous %^BOLD%^%^BLUE%^velvet "+
         "robe %^RESET%^%^CYAN%^of %^BOLD%^%^BLUE%^deep blue %^RESET%^"+
         "%^CYAN%^with thickly %^YELLOW%^embroidered bands %^RESET%^"+
         "%^CYAN%^around the cuffs and hem.  The robe is worn open, "+
         "displaying an open-collared %^BOLD%^%^WHITE%^poet shirt "+
         "%^RESET%^%^CYAN%^with voluminous sleeves.  The shirt is "+
         "worn over slender %^BOLD%^%^BLACK%^leather pants %^RESET%^"+
         "%^CYAN%^and is belted at the waist.  Matching %^BOLD%^"+
         "%^BLACK%^leather boots %^RESET%^%^CYAN%^click ever-so-lightly "+
         "on the floor as he moves with impeccable grace.  His "+
         "%^RED%^au%^ORANGE%^b%^RED%^urn hair %^CYAN%^cascades "+
         "to his shoulders in curls, brightened by the intelligent "+
         "%^GREEN%^gli%^WHITE%^m%^GREEN%^mer %^CYAN%^in his "+
         "%^BOLD%^%^GREEN%^eyes%^RESET%^%^CYAN%^.  As he moves to "+
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
