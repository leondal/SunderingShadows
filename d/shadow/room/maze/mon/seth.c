#include <std.h>
inherit MONSTER;
create() {
        ::create();
set_name("seth");
set_id( ({ "sharf" }) );
set("race", "fighter");
        set_gender("male");
set("short", "Seth the gladitor");
set_level(12);
set_long("He stands tall above you with super powers.");
set_alignment(9);
set("aggressive", 5);
set_hd(15,4);
set_body_type("human");
new("/d/shadow/room/maze/weapon/twosword.c")->move(this_object());
command("wield sword in left hand and right hand");
}
