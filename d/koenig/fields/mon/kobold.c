#include <std.h>
#include <daemons.h>
inherit MONSTER;

create() {
    	::create();
   	set_name("kobold");
   	set_short("a Kobold");
   	set("aggressive", 0);
   	set_body_type("human");
   	set_level(4);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",13);
   	set_stats("charisma",3);
   	set_stats("dexterity",8);
   	set_stats("constitution",7);
   	set_max_mp(0);
   	set_mp(query_max_mp());
   	set_hd(4,0);
   	set_long(
@KAYLA
This is a short, wretched Kobold.  He stands about three feet tall,
and wears tattered clothes around his greenish slimey skin.
KAYLA
	);
   	set_alignment(7);  //lawful neutral
   	set_race("kobold");
   	set_gender("male");
   	set_id( ({ "man", "kobold", "ugly"}) );
   	new("/d/koenig/fields/arm/kobold_clothes")->move(TO);
   		command("wear clothes");
   	new("/d/koenig/fields/weap/sword")->move(TO);
   		command("wield sword");
   	add_money("silver",random(50));
   	set_exp(150);
}
