inherit "/std/vendor";
create() {
    ::create();
    set_name("stegg");
    set_id( ({ "Stegg", "stegg", "clerk", "shopkeeper"}) );
    set_short("%^BOLD%^%^BLACK%^St%^RESET%^e%^BOLD%^%^BLACK%^gg, the %^RESET%^%^CYAN%^shop owner%^WHITE%^ ");
    set("aggressive", 0);
    set_level(19);
    set_exp(10);
    set_long("%^ORANGE%^This %^BOLD%^%^WHITE%^elderly %^RESET%^%^RED%^dwarf%^ORANGE%^, has a %^WHITE%^wispy gray"
			 " %^ORANGE%^beard and totters around the shop on a %^BOLD%^%^BLACK%^wooden crutch%^RESET%^%^ORANGE%^," 
			 " his left leg seems %^WHITE%^withered %^ORANGE%^and %^WHITE%^useless%^ORANGE%^. Anyone asking %^BOLD%^%^"
			 "BLACK%^Stegg %^RESET%^%^ORANGE%^about his %^WHITE%^leg %^ORANGE%^gets told an %^CYAN%^elaborate %^GRE"
			 "EN%^tale %^ORANGE%^of an encounter with a %^BOLD%^mummy%^RESET%^%^ORANGE%^, yet the %^CYAN%^rumour %^OR"
			 "ANGE%^in %^BOLD%^%^WHITE%^town %^RESET%^%^ORANGE%^has it that he hurt himself many years ago trying to"
			 " %^BOLD%^%^BLACK%^rob %^RESET%^%^ORANGE%^a %^BOLD%^%^RED%^burning %^BLACK%^warehouse%^RESET%^%^ORANGE%^"
			 " on %^GREEN%^Graez%^ORANGE%^. He has a big %^BOLD%^%^WHITE%^smile %^RESET%^%^ORANGE%^on his face as he"
			 " %^GREEN%^haggles prices%^ORANGE%^ and %^BOLD%^money %^RESET%^%^ORANGE%^exchanges hands.%^WHITE%^");
    set_gender("male");
    set_items_allowed("misc");
	set_diety("shaundakul");
    set_alignment(4);
    set("race", "dwarf");
    add_money("gold", random(500));
    set_body_type("human");
    set_hd(19,3);
    set_max_hp(query_hp());
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    set_mp(random(500));
    set_max_mp(query_mp());
    set_storage_room("/d/dagger/kinaro/storage/gs_storage");
    remove_std_db();
    remove_dbs( ({"/d/db/miscvendors","/d/db/vendor" }) );
}
