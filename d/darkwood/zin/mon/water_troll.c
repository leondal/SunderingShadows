#include <std.h>
#include "../zin.h"

inherit MONSTER;

void create() {
    ::create();
    seteuid(getuid());
    set_name("Nestark");
    set("id", ({"troll", "water troll", "nestark"}) );
    set("short", "A young water troll");
    set("long", "Your looking at a young water troll.  More to come. ");
    set("race", "troll");
    set_gender("female");
    set_body_type("human");
    set_hd(1,4);
    set_overall_ac(3);
    set_size(1);
    new(OBJ_DIR+"stone")->move(this_object());
}
