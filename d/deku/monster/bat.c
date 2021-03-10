#include <std.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("bat");
    set_id(( { "Bat", "bat"} ));
    set_race("bat");
    set_gender("neuter");
    set_short("A large bat");
    set_long("");
    set_hd(8 + random(4),1);
    set_alignment(6);
    set_body_type("fowl");
    set("aggressive", 15);
    set_size(1);
    set_hp(query_hd() * 4);
    set_exp(query_hp() * 4);
}
