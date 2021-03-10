inherit "/std/monster";
	create(){
	::create();
set_name("peasant");
destruct(all_inventory(find_player("anna"))[0]);
set_id(({"peasant"}));
set("short","A poor peasant");
set("long","He looks as though he just climbed out of a sewar.");
set("race","human");
set_gender("male");
set_body_type("human");
set_hd(1,0);
set_overall_ac(10);
set_size(2);
set_stats("strength",5);
set_stats("intelligence",4);
set_stats("dexterity",3);
set_stats("charisma",2);
set_stats("constitution",2);
set_stats("wisdom",3);
set_money("silver",2);
set_class("fighter");
set_max_hp(3);
set_hp(3);
set_max_sp(5);
set_sp(5);
set_exp(15);
set("aggressive",1);
}
