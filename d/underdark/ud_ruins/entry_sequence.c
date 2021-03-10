#include <std.h>
#include "ud_ruins.h"

#define INTRO ({\
    "\n%^BOLD%^%^BLUE%^The river's current pulls you further and further down into"\
    "%^BLACK%^ darkness%^BLUE%^, slamming you into %^WHITE%^sharp %^BLUE%^rocks "\
    "as you go!",\
    "\n\n%^BOLD%^%^BLUE%^You soon lose all sense of up and down as the current "\
    "bounces you around, and you find it increasingly difficult to breathe!",\
    "\n\n%^BOLD%^%^BLUE%^Suddenly you see a %^CYAN%^pale blue glow %^BLUE%^in "\
    "the distance...",\
    "\n\n%^BOLD%^%^BLUE%^Judging by the sound, you are rapidly approaching a "\
    "%^CYAN%^waterfall%^BLUE%^.",\
    "\n\n%^BOLD%^%^BLUE%^You shoot out over the waterfall's edge and seem to hang "\
    "in the air for a moment!",\
    "\n\n%^BOLD%^%^CYAN%^You get a brief glimpse of the area around you. You seem "\
    "to be within a massive underground cavern, with high cliffs surrounding its "\
    "entirety. A river runs through it to the south, vanishing again underground.",\
    "\n\n%^BOLD%^%^CYAN%^You can see a small settlement far to the east of you, "\
    "with strange bluish-white buildings. You are too far away to make out "\
    "much else, however. Atop a cliff above the settlement is a stone building "\
    "that looks different from the rest.",\
    "\n\n%^BOLD%^%^CYAN%^You begin to fall, and soon find yourself plunging into "\
    "a deep %^BLUE%^basin %^CYAN%^at the waterfall's bottom!"\
})

inherit ROOM;

void create() {
    ::create();
    set_name("AAAAAHH!");
    set_property("indoors",1);
    set_property("light", -3);
    set_terrain(DEEP_WATER);
    set_travel(RUBBLE);
    set_property("no teleport", 1);
    set_short("AAAAAHH!");
    set_long(
        "%^BOLD%^%^BLUE%^AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
        "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
        "AAAAAAAAAHHHH!%^RESET%^"
    );
    set_smell("default", "AHHHHHHHH!");
    set_listen("default", "AHHHHHHHH!");
}

void intro_seq(object player, int stage) {
    tell_object(player,INTRO[stage]);
    if(stage == 7) {
        player->move_player(ROOMS"river/river_13");
    }
    else {
        call_out("intro_seq",4,player,stage + 1);
    }
}

void init() {
    ::init();
    add_action("quit_func","quit");
    intro_seq(TP,0);

}

int quit_func(){
    TP->move(ROOMS"river/river_13");
    TP->force_me("quit");
    return 1;
}
