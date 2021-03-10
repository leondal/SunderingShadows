#include <std.h>
inherit MONSTER;
create() {
        ::create();
set_name("freddy");
set_id(({ "freddy"}));
set("race", "fighter");
        set_gender("male");
set_short("Freddy the child");
set_level(3);
set_long("Freddy is Sammy's best bud.");
set_alignment(9);
set("aggressive", 5);
set_hd(15,4);
set_body_type("human");
new("/d/shadow/room/maze/weapon/stick.c")->move(this_object());
command("wield stick in left hand and right hand");
}
