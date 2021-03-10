#include <std.h>
inherit "/std/comp_vend";

void create(){
	::create();
        set_name("cassandra");
        set_short("Cassandra, crystal collector");
        set_id(({"cassandra","Cassandra","collector","crystal collector"}));
        set_long("%^CYAN%^Cassandra is an older woman, clad in what look to "
"be quite expensive garments.  Traceries of %^YELLOW%^go%^RESET%^%^ORANGE%^"
"ld%^YELLOW%^en %^RESET%^%^CYAN%^thread line the hems and cuffs of the "
"flowing robe she wears, accentuated by ornate jewelry that drape about her "
"neck and encircle her fingers.  A particularly striking raw %^BOLD%^%^WHITE%^"
"c%^CYAN%^r%^WHITE%^yst%^YELLOW%^a%^WHITE%^l %^RESET%^%^CYAN%^is suspended "
"from a slender chain at her throat.  More gem-set pins hold her %^ORANGE%^"
"curled brown hair %^CYAN%^away from her face, which is plain but not "
"unpleasant.  The only striking feature there is her eyes, which glitter like "
"%^GREEN%^eme%^BOLD%^ra%^RESET%^%^GREEN%^lds %^CYAN%^as she surveys visitors "
"to her shop.  She has a quiet, almost haughty demeanor, and her entire "
"appearance leads you to think that she is probably quite well off.%^RESET%^");
	set_race("human");
        set_gender("female");
	set_hd(20,4);
	set_max_hp(150+random(50));
	set_hp(query_max_hp());
	set_overall_ac(-12);
        set_alignment(5);
	set_class("psion");
	set_class("cleric");
	set_mlevel("psion",20);
	set_mlevel("cleric",20);
	set_level(20);
	set_stats("intelligence",18);
	set_stats("wisdom",18);
	set_stats("charisma",16);
	set_stats("strength",9);
	set_stats("constitution",8);
	set_stats("dexterity",14);
	set_spells(({
         "mind thrust","mind thrust","call crystals","energy bolt","energy bolt","ultrablast"
	}));
	set_spell_chance(60);
	set_exp(100);
	set("aggressive",0);
	add_money("gold",random(50));
    set_shop_type("psion");
    set_components(100);
}
