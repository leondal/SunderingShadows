#include <std.h>

inherit MONSTER;
void create() {
   ::create();
set_name("D'bellin, healer");
set_id( ({"D'bellin", "d'bellin", "healer"}) );
set_short("%^GREEN%^D'bellin, healer");
   set("aggressive", 0);
   set_level(19);
set_long("%^ORANGE%^D'bellin, the healer, stands about 4 feet, 8 inches tall.  She has long blonde hair, piled carelessly upon her head.  Her blue eyes take in all her patients as she rushes to attend them.  Her white smock bears marks of old and new blood.  A needle threaded with fine gut is attached to D'bellin's shirt, awaiting use.");
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
"D'bellin asks : Just what do YOU need?",
"D'bellin sighs : Adventurers, warriors, fighters - IDIOTS, the whole lot of them"
}), 0);
}
