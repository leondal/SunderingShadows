#include <std.h>
inherit "/std/monster";

create() {
    ::create();
	set_name("drunk");
	set_id( ({ "drunk","old drunk" }) );
	set_race("dwarf");
	set_gender("male");
    set_short("Old dwarven drunk");
    set_long("This is an old drunk who has lived his life in the town\n"+
                   "of Solace.  This dwarf is insane.");
	set("aggressive",1);
  	set_alignment(3);
  	set_hd(2,1);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",13);
   	set_stats("charisma",3);
    set_exp(40);
    set_hp(25);
   	set_stats("dexterity",8);
   	set_stats("constitution",7);
   	new("/d/common/obj/weapon/dagger")->move(TO);
    command("wield dagger");
	add_money("silver",random(10));
	add_money("copper",random(20));
    set_emotes(5, ({"Drunk says: It's a fine day today.",
        "Drunk says: You are a funny looking person.",
        "Drunk says: Your boots are untied.",
        "Drunk says: The northern castle is haunted don't ever go there.",
        "Drunk says: Could you buy me a alcoholic drink?",
        "Drunk says: Do you have any extra silver I could have?"}), 0);
}
