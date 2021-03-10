#include "std.h"

inherit TOWNSMAN;
void create() {
   ::create();
   set_name("Heldien");
   set_id( ({ "heldien", "healer"}) );
   set_property("no attack",1);
   set_short("Heldien the underground healer");
   set("aggressive", 0);
   set_level(19);
   set_long(
@OLI
   This is the dwarven cleric that heals the somewhat unlucky and unfortunate 
of the Tharis society. Although most of his clients are thieves and thugs he has sworn to never let anyone suffer longer than they must.  He is short as is common to his race. His beard is slightly matted and has a smattering of blood. His white garb is stained. Many of the once red stains are bleached to a very light brown. 
OLI
   );
   set_gender("male");
   set_class("cleric");
   set_alignment(7);
   set("race", "dwarf");
   add_money("gold", random(500));
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(19,3);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
   set_exp(1);
}

int should_interact(object ob){
   return 1;
}


