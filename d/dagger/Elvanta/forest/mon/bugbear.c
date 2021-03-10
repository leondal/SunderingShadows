inherit "std/monster";

create() {
    ::create();
	set_name("bugbear");
	set_id( ({ "bugbear" }) );
	set("race", "goblin");
	set_gender("male");
	set("short", "Bugbear");
        set("long","Unlike their smaller cousins, these hairy giant goblins\n"+
                   "operate equally well in bright daylight or great darkness\n"+
                   "The skin is a light yellow, and hair of a lusterless \n"+
                   "tannish brown.  Their eyes are greenish white with red\n"+
                   "pupils.");
set_level(9);
	set_body_type("human");
set_property("swarm", 1);
  	set("aggressive",18);
set_hd(12,8);
  	set_alignment(7);
  	set_size(2);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
set_stats("strength", 20);
   	set_stats("charisma",3);
set_stats("dexterity", 18);
   	set_stats("constitution",7);
	set_hp(50);
   	set_max_mp(0);
   	set_mp(query_max_mp());
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
        new("/d/deku/weapons/club")->move(this_object());
       command("wield club in right hand and left hand");
        set_exp(110);
	add_money("silver",random(10));
	add_money("copper",random(20));
   
}
