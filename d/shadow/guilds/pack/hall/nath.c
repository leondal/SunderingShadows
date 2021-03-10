#include <std.h>
inherit MONSTER;
void create() {
   ::create();
set_name("nathanial");
set_id( ({ "nathanial", "healer"}) );
set_short("Nathanial Cleaver, Shades of Death healer.");
   set("aggressive", 0);
   set_level(19);
set_long("He is a healer of grand renown comitted to the Shades of Death and it's survival.");
   set_languages( ({ "common" }) );
   set_gender("male");
   set_alignment(9);
   set("race", "human");
   add_money("gold", random(500));
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(19,3);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
}


