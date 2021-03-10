
//monsters by the House of Svaha
#include <std.h>

inherit MONSTER;
void create() {
   ::create();
set_name("F'larion, healer");
set_id( ({"F'larion", "f'larion", "healer"}) );

set_short("%^GREEN%^F'larion, the Healer");
set_long(
@DESC
%^GREEN%^F'larion, a sylvan elf stands about 5'4" tall. Her long
brown hair is tucked under a wimple type of affair, and her deep green 
eyes seem to echo all the pain she has seen over the years.  She looks up
wearily from a prone patient as you enter.  Her forest green tunic and
trousers bear russet brown and scarlet red stains of both old and new
wounds.  Her smile is warm and welcoming, yet the edges droop slightly,
in remembered sorrow.
DESC
);

set_gender("female");
   set_alignment(4);
set("race", "elf");
set_size(2);
   add_money("gold", random(500));
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(19,3);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
set_emotes(2, ({
"F'larion looks up and smiles : How can I help you?",
"F'larion sighs : And what is wrong with YOU?"
}), 0);
}
