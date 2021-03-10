#include <std.h>
inherit "std/monster";

create() {
    ::create();
	set_name("bugbear");
 set_id(({"bugbear","guard"}));
 set_race("bugbear");
	set_gender("male");
	set_short("Bugbear");
 set_long("Unlike their smaller goblin cousins, these hairy giant bugbears\n"+
           "operate equally well in bright daylight or great darkness.\n"+
           "Their skin is a light yellow, and hair is a lusterless \n"+
           "tannish brown.  Their eyes are greenish white with red pupils.");
	set_body_type("human");
 set("aggressive",18);
 set_hd(6,1);
 set_alignment(7);
 set_size(2);
 set_stats("intelligence",6);
 set_stats("wisdom",4);
 set_stats("strength",16);
 set_stats("charisma",3);
 set_stats("dexterity",14);
 set_stats("constitution",7);
 set_hp(50);
 set_max_hp(query_hp());
	new("/d/common/obj/weapon/halberd")->move(TO);
 command("wield halberd");
 set_exp(500);
	add_money("silver",random(10));
	add_money("copper",random(20));
   
}
