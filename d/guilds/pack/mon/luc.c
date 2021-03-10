#include <std.h>
inherit MONSTER;
void create() {
   ::create();
set_name("lucifer");
set_id(( {"lucifer","Lucifer","healer"} ));
set_short("%^BOLD%^%^RED%^Lucifer%^RESET%^%^RED%^, Healer of the Illuminati");
   set("aggressive", 0);
   set_level(19);
set_long(
@SEETH
%^RED%^Lucifer stand before you with his wings wrapped around him like a cloak. He waits to serve his masters with his healing abilities.
SEETH
);
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


