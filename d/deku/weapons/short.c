#include <std.h>
inherit "/std/weapon";

create() {
    ::create();
    set_id(({"sword", "shortsword"}));
    set_name("shortsword");
    set_short("Shortsword");
    set_long(
            "This is an adamantite shortsword."
            );
    set_weight(5);
    set_size(1);
    set("value", 20);
    set_wc(1,6);
    set_large_wc(1,8);
    set_type("slashing");
    set_wield("You grip a fine crafted sword.");
    set_hit("You slice through your opponent!");
    set("read", "Made by Drugnar?");
    set_property("monsterweapon",1);
}


