inherit "std/monster";

create() {
    ::create();
set_name("mudpuppy");
set_id(({"mudpuppy"}));
set("race", "fairy");
set_gender("female");
set_short("a mudpuppy");
set_long("%^ORANGE%^The mudpuppy looks at you with great, soulful eyes.  It is short and long with a vaguely beaverlike face, and has great floppy ears and a lizard's tail.  It is splay-footed with broad, webbed feet and its body is coloured in various shades of brown.  Its main purpose in life is to clean up after the forest creatures, and is happiest when doing so.  Perhaps that is why it likes the Sloridge Gnomes so much.");
set_level(9);
set_body_type("quadruped");
set_property("swarm", 1);
  	set("aggressive",18);
set("wimpy", 75);
set_hd(12,8);
set_alignment(4);
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
        set_exp(110);
	add_money("silver",random(10));
	add_money("copper",random(20));
   
}
