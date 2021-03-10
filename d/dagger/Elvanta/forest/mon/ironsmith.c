
inherit "/std/monster";

create() {
    ::create();
	set_name("dwarf");
set_id(({"dwarf"}));
	set("race", "dwarf");
set_gender("male");
set("short", "dwarf");
set("long", "This dwarf is one of the many ironsmiths working here, in this room.  He has deep tan coloured skin, with ruddy cheeks and bright eyes.  He is wearing an earth coloured tunic and trousers.  His arms and hands draw your eyes, as the years of working the iron has made them strong and powerful.  Just one of his forearms is the size of a normal beings thigh.  He is NOT an individual you would want to annoy.");
	set_level(20);
	set_body_type("human");
  	set("aggressive",1);
  	set_alignment(3);
set_size(2);
set_hd(24,1);
set_stats("intelligence", 14);
set_stats("wisdom", 14);
	set_stats("strength",23);
set_stats("charisma", 12);
	set_stats("dexterity",20);
        set_exp(750);
	set_hp(100);
   	set_stats("constitution",17);
   	set_max_mp(0);
   	set_mp(query_max_mp());
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
set_wielding_limbs(({"right hand", "left hand", "torso"}));
new("/d/dagger/Elvanta/forest/items/armor/leather")->move(this_object());
command("wear armor");
        new("/d/deku/weapons/axe")->move(this_object());
command("wield axe in right hand");
	add_money("silver",random(10));
	add_money("copper",random(20));
}
