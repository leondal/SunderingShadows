#include <std.h>

inherit MONSTER;
void create() {
   ::create();
set_name("Jehan");
set_id( ({ "jehan", "healer"}) );
set_short ("Jehan, healer of Elvanta");
   set("aggressive", 0);
   set_level(19);
set_long("He is an old gentleman, who tends to the injured \n"+
"people of Elvanta");
   set_gender("male");
   set_alignment(4);
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


