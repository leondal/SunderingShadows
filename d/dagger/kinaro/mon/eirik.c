#include <std.h>
inherit TOWNSMAN;

void create() {
    ::create();
    set_name("eirik");
    set_id( ({"eirik", "Eirik", "healer"}) );
    set_short("%^BOLD%^%^BLACK%^E%^RESET%^i%^BOLD%^%^BLACK%^r%^RESET%^i%^BOLD%^%^BLACK%^k%^RESET%^,"
			  " %^BOLD%^%^RED%^Healer %^RESET%^of %^ORANGE%^Kinaro%^WHITE%^ ");
    set("aggressive", 0);
    set_level(19);
    set_exp(10);
    set_long("%^BOLD%^%^BLACK%^Eirik %^RESET%^%^ORANGE%^is a %^BOLD%^%^CYAN%^legend"
			 " %^RESET%^%^ORANGE%^amongst the %^RED%^dwarven %^ORANGE%^community. H"
			 "e was once a %^BOLD%^%^CYAN%^famous %^RESET%^%^ORANGE%^Gr%^BOLD%^%^BL"
			 "ACK%^u%^RESET%^%^ORANGE%^m%^BOLD%^%^BLACK%^b%^RESET%^%^ORANGE%^ar%^BO"
			 "LD%^%^BLACK%^i%^RESET%^%^ORANGE%^an B%^BOLD%^%^BLACK%^a%^RESET%^%^ORA"
			 "NGE%^s%^BOLD%^%^BLACK%^ti%^RESET%^%^ORANGE%^on, who helped %^CYAN%^de"
			 "fend %^ORANGE%^a %^RED%^dwarven %^YELLOW%^kingdom %^RESET%^%^ORANGE%^"
			 "from a large %^BOLD%^%^BLACK%^drow %^RESET%^%^CYAN%^invasion%^ORANGE%^"
			 ". These days he is %^WHITE%^Kinaro's %^BOLD%^%^RED%^healer%^RESET%^%^O"
			 "RANGE%^, and darn good at his job. He wears %^WHITE%^practical %^ORANG"
			 "E%^clothes in %^BOLD%^%^BLACK%^black%^RESET%^%^ORANGE%^, as %^BOLD%^%^"
			 "RED%^blood %^RESET%^%^ORANGE%^don't show so easily on %^BOLD%^%^BLACK%"
			 "^black%^RESET%^%^ORANGE%^. He is %^WHITE%^bald%^ORANGE%^, but with lar"
			 "ge %^WHITE%^bushy %^ORANGE%^eyesbrows, and a %^CYAN%^hawkish nose %^OR"
			 "ANGE%^that looks slightly %^WHITE%^crooked%^ORANGE%^. His frame is %^C"
			 "YAN%^lean, %^ORANGE%^and %^CYAN%^slightly %^WHITE%^bend %^ORANGE%^over"
			 " from %^RED%^age%^ORANGE%^, but there is a still %^BOLD%^%^RED%^streng"
			 "th%^RESET%^%^ORANGE%^, in his %^GREEN%^e%^BOLD%^m%^RESET%^%^GREEN%^e%^B"
			 "OLD%^r%^RESET%^%^GREEN%^a%^BOLD%^l%^RESET%^%^GREEN%^d%^BOLD%^-co%^RESE"
			 "T%^%^GREEN%^l%^BOLD%^o%^RESET%^%^GREEN%^r%^BOLD%^e%^RESET%^%^GREEN%^d "
			 "%^ORANGE%^eyes.");
    set_gender("male");
    set_alignment(2);
	set_diety("grumbar");
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


