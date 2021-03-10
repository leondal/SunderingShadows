#include <std.h>
#include "../gantioch.h"

inherit MONSTER;

create() {
   ::create();
   set("aggressive",0);
   set_name("Brother Torin");
   set_level(20);
   set_alignment(1);
   set_languages( ({ "common" }) );
   command("speak common");
   set_property("swarm",0);
   set_id( ({"brother","healer","torin","brother torin"}) );
   set_short("Brother Torin");
   set_long("%^RESET%^Brother Torin is a well-built young man with %^BOLD%^%^BLACK%^black hair%^RESET%^"+
		" and %^RESET%^%^BLUE%^blue %^RESET%^eyes. He is wearing a long, simple robe made of %^BOLD%^%^YELLOW%^yellow"+
        " silk %^RESET%^which flows down to the floor. He seems to be tending to some things in the back, and"+
        " looks fairly busy, but judging from his calmness, seems willing to help.");
   set_race("human");
   set_hd(20,10);
   add_money("gold",random(100));
   set_body_type("human");
   set_size( 2 );
   set_property("no attack", 1);
   set_hp(243);
   set_max_hp(243);
   set_exp(400);
}
