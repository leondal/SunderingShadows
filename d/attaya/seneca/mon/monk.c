#include <std.h>

inherit MONSTER;
void create() {
   ::create();
set_name("monk");
set_id( ({ "monk", "healer"}) );
set_short("A hooded monk");
   set("aggressive", 0);
   set_level(1000);
    set_long("
    This is a hooded monk of the Altherian Order.  He heals those who enter the arena and guides the spirits out after the battle.
    You get the feeling that he is most powerful.
");
   set_languages( ({ "common" }) );
   set_gender("male");
   set_alignment(9);
   set("race", "human");
   add_money("gold", random(500));
   set_body_type("human");
   set_property("no attack", 1);
   set_property("no death",1);
    set_class("fighter");
    set_guild_level("fighter",1000);
  set_property("full attacks",1);
   set_hd(1000,8);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
}


