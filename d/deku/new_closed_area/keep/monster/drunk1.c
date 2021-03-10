#include <std.h>
inherit "/std/monster";

create() {
    ::create();
	set_name("drunk");
	set_id( ({ "drunk","old drunk" }) );
	set("race", "orc");
	set_gender("male");
        set("short","Old drunk");
       set("long","This old drunk is an old drunken guard of Keep Blacktongue.\n"+
                  "He is useless now, so he turned to the life of a drunk.\n");
	set_level(2);
	set_body_type("human");
  	set("aggressive",1);
  	set_alignment(6);
  	set_size(1);
        set_hd(2,1);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",13);
   	set_stats("charisma",3);
        set_exp(10);
       set_hp(42);
   	set_stats("dexterity",8);
   	set_stats("constitution",7);
	set_max_hp(query_hp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
   set_emotes(2, ({"Drunk says: It's a fine day today.",
                 "Drunk says: You are a funny looking person.",
                 "Drunk says: Your boots are untied.",
                 "Drunk says: Could you buy me a alcoholic drink.",
                 "Drunk says: Do you have any extra silver I could have."}), 0);
   
}
