inherit "/std/monster";

create() {
    ::create();
	set_name("goblin");
	set_id( ({ "goblin", "captain"," goblin captain" }) );
	set("race", "goblin");
	set_gender("male");
	set("short", "A goblin captain");
	set("long", "A very crude and stinky goblin captain.\n");
	set_level(5);
	set_body_type("human");
  	set("aggressive",5);
  	set_alignment(3);
  	set_size(2);
        set_hd(6,2);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",13);
   	set_stats("charisma",3);
   	set_stats("dexterity",12);
   	set_stats("constitution",7);
        set_hp(random(15)+36);
        set_exp(75);
	set_max_hp(query_hp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
   new("/d/deku/weapons/longsword1")->move(this_object());
      	command("wield sword");
	add_money("silver",random(5));
	add_money("copper",random(10));
	add_money("electrum",random(5));
}
