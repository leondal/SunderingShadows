#include <std.h>
inherit MONSTER;
create() {
        ::create();
set_name("doctor");
set_id( ({ "doctor" }) );
set("race","human");
set_gender("male");
set("short","A doctor");
set_level(14);
set("long","This doctor can help you with anything you may need.");
set_alignment(9);
set("aggressive", 5);
set_hd(10,4);
set_body_type("human");
set_hp(110);
set_exp(900);
 new("/d/shadow/room/castle2/weap/knife.c")->move(this_object());
command("wield knife");
new("/d/shadow/room/castle2/weap/chain.c")->move(this_object());
command("wear chain");
}
