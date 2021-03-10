inherit "/std/vendor";

create() {
    ::create();
    set_nwp("armorsmithing", 10, 500);
    set_name("gake");
    set_id( ({ "Gake", "gake", "armorer", "dwarf"}) );
    set_short("%^RESET%^%^ORANGE%^Gake Rockbottom");
    set("aggressive", 0);
    set_level(19);
    set_exp(10);
    set_long("%^RESET%^%^ORANGE%^He keeps his s%^BOLD%^%^BLACK%^abl%^RESET%^%^ORANGE%^e hair long and pulled back into a"
			 " %^BOLD%^ponytail %^RESET%^%^ORANGE%^that drags the fl%^BOLD%^oo%^RESET%^%^ORANGE%^r. His b%^RED%^ea%^ORANG"
			 "E%^rd is equally as %^BOLD%^%^GREEN%^impressive %^RESET%^%^ORANGE%^with it dragging the floor too and %^BO"
			 "LD%^%^MAGENTA%^sparkling %^RESET%^%^ORANGE%^with g%^BOLD%^o%^RESET%^%^ORANGE%^l%^BOLD%^d%^RESET%^%^ORANGE%"
			 "^e%^BOLD%^n %^RESET%^%^ORANGE%^undertones when hit by direct s%^BOLD%^un%^RESET%^%^ORANGE%^li%^BOLD%^g%^RE"
			 "SET%^%^ORANGE%^ht. He is %^CYAN%^caked %^ORANGE%^in %^BOLD%^%^BLACK%^s%^RESET%^%^RED%^oo%^BOLD%^%^BLACK%^t"
			 " %^RESET%^%^ORANGE%^and %^BOLD%^%^BLACK%^a%^WHITE%^s%^BLACK%^h%^WHITE%^es %^RESET%^%^ORANGE%^from the %^BOL"
			 "D%^%^RED%^f%^RESET%^%^RED%^o%^BOLD%^rg%^RESET%^%^RED%^e %^ORANGE%^with his hair seeming to have grown immu"
			 "ne to %^RED%^f%^BOLD%^i%^RESET%^%^RED%^ery %^BOLD%^c%^RESET%^%^RED%^i%^BOLD%^nders %^RESET%^%^ORANGE%^flyi"
			 "ng about. %^CYAN%^H%^ORANGE%^a%^CYAN%^z%^ORANGE%^e%^CYAN%^l %^ORANGE%^e%^CYAN%^y%^ORANGE%^es %^BOLD%^%^MAG"
			 "ENTA%^gle%^RESET%^%^MAGENTA%^a%^BOLD%^m %^RESET%^%^ORANGE%^with %^BOLD%^%^CYAN%^c%^WHITE%^o%^CYAN%^n%^WHIT"
			 "E%^f%^CYAN%^i%^WHITE%^d%^CYAN%^ence %^RESET%^%^ORANGE%^and %^BOLD%^%^RED%^d%^ORANGE%^e%^RED%^t%^ORANGE%^e%"
			 "^RED%^rm%^ORANGE%^i%^RED%^n%^ORANGE%^a%^RED%^t%^ORANGE%^i%^RED%^on %^RESET%^%^ORANGE%^below %^BOLD%^bushy eyebrows%^RESET%^%^ORANGE%^");
    set_gender("male");
    set_alignment(1);
	set_diety("grumbar");
    set("race", "dwarf");
    add_money("gold", random(500));
    set_body_type("human");
    set_hd(19,3);
    set_max_hp(query_hp());
    set_mp(random(500));
    set_stats("strength", 18);
    set_stats("constitution", 17);
    set_stats("dexterity", 16);
    set_stats("wisdom", 10);
    set_stats("intelligence", 14);
    set_hp(159);
    set_storage_room("/d/dagger/kinaro/storage/a_storage.c");
    set_items_allowed("armor");
    set_class("fighter");
    remove_std_db();
    remove_dbs( ({"/d/db/armors", "/d/db/vendor"}) );
    remove_random_act_dbs(({"/d/db/armorsrandom"}));
}
