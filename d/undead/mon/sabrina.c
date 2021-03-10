#include <std.h>
#include "../undead.h"
inherit NPC;

void create() {
    ::create();
    set_name("Sabrina");
    set_id(({"sabrina", "healer","Sabrina"}));
    set_short("Sabrina, an elderly mystic");
    set("aggressive", 0);
    set_level(19);
    set_long("%^RESET%^%^CYAN%^Sabrina is an ancient woman with %^BOLD%^"
"%^WHITE%^white hair %^RESET%^%^CYAN%^that hangs all the way down to her frail "
"thighs.  Her face is creased with lines, and her lips are always pulled into "
"what could be best described as a grandmotherly scowl. Her calm %^RESET%^gray "
"eyes %^CYAN%^show an incredible wisdom, and rarely miss anything that happens "
"within her parlor.");
    set_gender("female");
    set_alignment(4);
    set_race("human");
    add_money("gold", random(500));
    set_body_type("human");
    set_hd(19,3);
    set_max_hp(query_hp());
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    set_mp(random(500));
    set_max_mp(query_mp());
}


