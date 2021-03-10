#include <std.h>
inherit TOWNSMAN;

void create() {
    ::create();
    set_name("dulag");
    set_id( ({"dulag", "Dulag", "Dulag Goldspinner","dulag goldspinner","trade master","Trade Master","dwarf"}) );
    set_short("%^YELLOW%^D%^RESET%^%^ORANGE%^u%^BOLD%^l%^RESET%^%^ORANGE%^a%^BOLD%^g"
			  " G%^RESET%^%^ORANGE%^o%^BOLD%^ld%^RESET%^%^ORANGE%^s%^BOLD%^pi%^RESET"
			  "%^%^ORANGE%^n%^BOLD%^n%^RESET%^%^ORANGE%^e%^BOLD%^r%^RESET%^, %^BOLD%"
			  "^%^CYAN%^Tr%^RESET%^%^CYAN%^a%^BOLD%^d%^RESET%^%^CYAN%^e %^BOLD%^Ma%^"
			  "RESET%^%^CYAN%^s%^BOLD%^t%^RESET%^%^CYAN%^e%^BOLD%^r %^RESET%^of %^OR"
			  "ANGE%^Kinaro%^WHITE%^");
    set("aggressive", 0);
    set_level(19);
    set_exp(10);
    set_long("%^ORANGE%^This %^WHITE%^frail %^ORANGE%^and %^BOLD%^%^WHITE%^elderly %^RESET%^%^RED%^dwarf" 
			 " %^ORANGE%^is %^WHITE%^bald%^ORANGE%^, with a long %^BOLD%^%^WHITE%^cotton white %^BLACK%^b"
			 "eard%^RESET%^%^ORANGE%^, and clear %^BOLD%^%^CYAN%^sky-blue %^RESET%^%^ORANGE%^eyes. He we"
			 "ars an %^BOLD%^%^MAGENTA%^elaborate %^RESET%^%^ORANGE%^and %^BOLD%^%^CYAN%^exquisitely %^R"
			 "ESET%^%^ORANGE%^crafted %^BOLD%^%^BLACK%^robe %^RESET%^%^ORANGE%^of %^BOLD%^%^WHITE%^offic"
			 "e%^RESET%^%^ORANGE%^. He is the %^BOLD%^%^WHITE%^official %^CYAN%^trade master %^RESET%^%^"
			 "ORANGE%^and %^CYAN%^arbitrator %^ORANGE%^of the %^BOLD%^%^CYAN%^trade %^RESET%^%^ORANGE%^"
			 " %^BOLD%^%^CYAN%^guilds%^RESET%^%^ORANGE%^, he oversees all business going through %^WHITE%^"
			 "Kinaro%^ORANGE%^. %^BOLD%^Dulag %^RESET%^%^ORANGE%^is known for being a rapidly %^BOLD%^%^"
			 "WHITE%^conservative %^RESET%^%^RED%^dwarf %^ORANGE%^who gladly voices his opinions on the"
			 " %^BOLD%^%^BLACK%^inferiority %^RESET%^%^ORANGE%^of %^WHITE%^non-dwarves %^ORANGE%^and the"
			 " goods they produce. He is a %^CYAN%^staunch %^ORANGE%^believer in %^RED%^dwarven superior"
			 "ity%^ORANGE%^, and yet he is known to show absolutely no %^GREEN%^favoritism%^ORANGE%^, when"
			 " it comes to arbitrating %^BOLD%^%^CYAN%^trade %^RESET%^%^ORANGE%^deals.%^WHITE%^");
    set_gender("male");
    set_alignment(5);
	set_diety("shaundakul");
    set("race", "dwarf");
    add_money("gold", random(500));
    set_body_type("human");
    set_property("no attack", 1);
    set_hd(19,3);
    set_max_hp(query_hp());
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    set_mp(random(500));
    set_max_mp(query_mp());
}


