#include <std.h>

inherit MONSTER;
void create() {
   ::create();
set_name("Hettman");
set_id( ({ "hettman", "healer"}) );
set_short("Hettman Tsurin, healer of Shadow.");
   set("aggressive", 0);
   set_level(19);
set_long("He is an old gentleman, who tends to the injured \n"+
   "people of Shadow.");
   set_languages( ({ "common" }) );
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


