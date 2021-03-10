#include <std.h>
inherit MONSTER;
create() {
        ::create();
set_name("sharf");
set_id( ({ "sharf" }) );
set("race", "fighter");
        set_gender("male");
set("short","A sharf.");
set_level(8);
set("long","He likes his days long, but with the time, he doesn't look like he is happy.");
set_alignment(9);
set("aggressive", 5);
set_hd(15,4);
set_body_type("human");
new("/d/shadow/room/maze/weapon/knife.c")->move(this_object());
command("wield knife in right hand");
}
