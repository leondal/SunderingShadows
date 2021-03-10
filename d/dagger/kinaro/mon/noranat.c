inherit TOWNSMAN;

create() {
    ::create();
    set_name("Noranat");
    set_id( ({ "noranat", "Noranat", "leadarm", "Leadarm", "noranat leadarm", "Noranat Leadarm"}) );
    set_short("%^RESET%^%^ORANGE%^Noranat Leadarm ");
    set("aggressive", 0);
    set_level(10);
    set_long("%^ORANGE%^This is %^WHITE%^Kinaro's %^ORANGE%^head %^BOLD%^tax collector%^RESET%^%^ORANGE%^."
			 " This %^RED%^surly%^ORANGE%^, %^BOLD%^%^BLACK%^bitter %^RESET%^%^ORANGE%^dwarf is an %^BOLD%^"
			 "%^CYAN%^ex-adventurer %^RESET%^%^ORANGE%^who lost his %^BOLD%^%^WHITE%^comrades %^RESET%^%^ORAN"
			 "GE%^in an %^RED%^encounter %^ORANGE%^with %^BOLD%^%^WHITE%^giants %^RESET%^%^ORANGE%^in the hill"
			 "s near %^BOLD%^%^CYAN%^Torm %^RESET%^%^ORANGE%^years ago. %^BOLD%^%^BLACK%^Noranat %^RESET%^%^ORA"
			 "NGE%^makes it his %^BOLD%^%^WHITE%^personal quest %^RESET%^%^ORANGE%^to squeeze every %^BOLD%^copp"
			 "er %^RESET%^Kinaro %^ORANGE%^is owed out of both resident and visiting %^BOLD%^%^CYAN%^merchants%^R"
			 "ESET%^%^ORANGE%^, and as such he holds a fair bit of %^BOLD%^%^WHITE%^responsibility %^RESET%^%^OR"
			 "ANGE%^towards the amount of %^BOLD%^wealth %^RESET%^Kinaro %^ORANGE%^has been spending on %^BOLD%^%^BL"
			 "ACK%^reinforcing %^RESET%^%^ORANGE%^the %^BOLD%^%^RED%^defenses %^RESET%^%^ORANGE%^of their trade outpost as of late.");
    set_gender("male");
    set_alignment(5);
	set_diety("shaundakul");
    set("race", "dwarf");
    set_hd(10,0);
    set_exp(10);
    set_max_hp(query_hp());
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    set_mp(random(250));
    set_max_mp(query_mp());
    add_money("gold", random(20000));
    set_skill("melee",90);
    set_body_type("human");
}