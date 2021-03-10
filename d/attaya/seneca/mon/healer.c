#include <std.h>
#include <daemons.h>

inherit NPC;
void create() {
   ::create();
set_name("nurse");
set_id( ({ "nurse", "healer"}) );
set_short("A Nurse");
   set("aggressive", 0);
   set_level(35);
    set_long("
    This young woman is one of many who service the sick and needy at the Seneca Hospital.
");
   set_languages( ({ "common" }) );
   set_gender("female");
   set_alignment(5);
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
   set_nwp("healing",20);
}


