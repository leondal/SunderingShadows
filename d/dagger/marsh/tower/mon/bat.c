#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit "/std/monster";
 
create() {
    ::create();
    set_name("bat");
    set("id", ({ "bat" }));
    set("short", "%^RESET%^%^RED%^Vampyre bat%^RESET%^");
    set("aggressive", 100);
    set_hd(3,1);
    set("long", "This is a ugly blood sucking vampyre bat."
    );
    set_level(3);
    set_class("fighter");
    set_body_type("mammal");
    set_alignment(9);
    set("race", "bat");
    set_ac(1);
    set_max_hp(18);
    set_hp(18);
    set_exp(100);
}
