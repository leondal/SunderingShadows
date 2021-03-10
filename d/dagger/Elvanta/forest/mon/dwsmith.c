
inherit "/std/monster";

create() {
    ::create();
	set_name("dwarf");
set_id(({"dwarf", "dwarf silversmith", "dwarf smith"}));
	set("race", "dwarf");
set_gender("male");
set("short", "dwarf");
set("long", "%^BOLD%^CYAN%^This silversmith dwarf, stands about four and a half feet tall, and has arms like small trees.  His hair is brown and he is wearing a smock of leather, and a jerkin to match.  Considering the size of his hands it is quite surprising to see the delicate necklaces which come from his fingers, like glistening cobwebs, so fine the work.  He wears a grim countenance as he is totally involved in his work and hates to be disturbed.%^RESET%^");
set_level(15);
	set_body_type("human");
  	set("aggressive",1);
  	set_alignment(3);
set_size(2);
set_hd(18,1);
set_hp(75);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",17);
   	set_stats("charisma",3);
        set_stats("dexterity", 15);
        set_exp(750);
       set_hp(82);
   	set_stats("constitution",17);
   	set_max_mp(0);
   	set_mp(query_max_mp());
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
set_wielding_limbs( ({"right hand", "left hand", "torso"}) );
        new("/d/deku/weapons/axe")->move(this_object());
	command("wield axe in left hand");
new("/d/dagger/Elvanta/forest/items/armor/leather")->move(this_object());
command("wear armor");
	add_money("silver",random(10));
	add_money("copper",random(20));
}
