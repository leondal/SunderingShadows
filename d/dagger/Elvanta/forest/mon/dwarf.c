
inherit "/std/monster";

create() {
    ::create();
	set_name("dwarf");
set_id(({"dwarf"}));
	set("race", "dwarf");
set_gender("female");
set("short", "dwarf");
set("long", "This dwarf has a deep tan coloured skin, with ruddy cheeks and bright eyes.  Hair is brown and she is wearing earth coloured clothing, with the occaisional bit of bright gem woven into her tunic.  She is about four feet tall and weights about two hundred pounds.  She is armed, and could be considered dangerous.");
set_level(12);
set_hd(15,1);
	set_body_type("human");
  	set("aggressive",1);
  	set_alignment(3);
	set_size(2);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",17);
   	set_stats("charisma",3);
	set_stats("dexterity", 15);
	set_stats("constitution", 17);
	set_exp(1000);
	set_hp(100);
   	set_stats("constitution",17);
   	set_max_mp(0);
   	set_mp(query_max_mp());
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
        new("/d/deku/weapons/axe")->move(this_object());
	command("wield axe in right hand");
	add_money("silver",random(10));
	add_money("copper",random(20));
}
