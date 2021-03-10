#include <std.h>
inherit MONSTER;
create() {
        ::create();
set_name("sammy");
set_id( ({ "sammy" }) );
set("race", "fighter");
        set_gender("male");
set_short("Sammy the boy");
set_level(3);
set_long("Sammy is a young boy, who likes to make trouble.");
set_alignment(9);
set("aggressive", 5);
set_hd(15,4);
set_body_type("human");
new("/d/shadow/room/maze/weapon/stick.c")->move(this_object());
command("wield stick in left hand and right hand");
}
