#include <std.h>
#include <magic.h>
#include <daemons.h>
#include "../../ud_ruins.h"

#define BOSS_SUMMON ({\
    "%^BOLD%^%^BLACK%^A sharp %^ORANGE%^scream %^BLACK%^rings out from the "\
    "walls around you: %^WHITE%^'%^RED%^No!%^WHITE%^'",\
    "\n\n%^BOLD%^%^BLACK%^You feel a sudden %^CYAN%^chill %^BLACK%^in the air as "\
    "the light around you seems to dim...",\
    "\n\n%^BOLD%^%^BLACK%^The numerous skeletons surrounding you jerk suddenly, and "\
    "a tangible %^RESET%^darkness %^BOLD%^%^BLACK%^begins to surround them...",\
    "\n\n%^BOLD%^%^RED%^A wordless %^ORANGE%^scream %^RED%^pierces the air, "\
    "louder than before!",\
    "\n\n%^BOLD%^%^BLACK%^The exit is suddenly blocked by an "\
    "%^WHITE%^impenetrable %^BLACK%^darkness!",\
    "\n\n%^BOLD%^%^BLACK%^A cacaphony of %^RED%^screaming %^BLACK%^erupts from all "\
    "around you as the darkness coaleses into a large, writhing cloud! It begins "\
    "its advance upon you!"\
})

inherit ROOM;

int boss_summoned;
int summoning_sequence_on;

void create() {
    ::create();
    set_name("before a small altar");
    set_property("indoors",1);
    set_property("light", 0);
    set_terrain(NAT_CAVE);
    set_travel(FRESH_BLAZE);
    set_property("no teleport", 1);
    set_short(
        "%^ORANGE%^before a small altar%^WHITE%^"
    );
    set_long(
        "%^BOLD%^%^BLACK%^At the far back of the shrine sits a small "
        "%^RESET%^%^ORANGE%^altar %^BOLD%^%^BLACK%^of "
        "%^RESET%^%^ORANGE%^granite%^BOLD%^%^BLACK%^, upon which the symbol of a "
        "%^ORANGE%^ring %^BLACK%^has been delicately carved. As in the previous "
        "room, the floor is cluttered with the %^WHITE%^skeletons %^BLACK%^of the "
        "fallen, though some of the bodies here wear the remains of more "
        "%^RESET%^%^ORANGE%^o%^WHITE%^r%^BOLD%^n%^RESET%^%^ORANGE%^a"
        "%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^, "
        "%^RESET%^%^ORANGE%^religious garb%^BOLD%^%^BLACK%^. This portion of "
        "the shrine doesn't seem to be quite as decrepit a state as the rest of "
        "the building - if it weren't for the scene of death and violence "
        "surrounding you, this would likely be the most %^RESET%^%^CYAN%^serene "
        "%^BOLD%^%^BLACK%^locale in all the cavern.%^RESET%^"
    );
    set_smell("default", "The air smells of earth and ash.");
    set_listen("default", "The cavern winds carry a mournful tone through the room.");
    set_exits(([
        "east" : ROOMS"cliff/shrine1",
    ]));
    set_items(([
        "altar" :
            "%^ORANGE%^This altar is set low to the ground, and has been "
            "crafted from finely polished slab of "
            "g%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^a%^BOLD%^%^WHITE%^n"
            "%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^e. In contrast to "
            "much of the shrine, this altar has been painstakingly worked, and is "
            "decorated with a wide variety of "
            "%^WHITE%^e%^BOLD%^n%^RESET%^g%^BOLD%^r%^RESET%^a%^BOLD%^v%^RESET%^i"
            "%^BOLD%^ng%^RESET%^s %^ORANGE%^and "
            "%^BOLD%^%^RED%^g%^RESET%^%^RED%^e%^BOLD%^m%^GREEN%^s%^RED%^t"
            "%^RESET%^%^RED%^o%^BOLD%^n%^CYAN%^e%^RED%^s%^RESET%^%^ORANGE%^. None of the "
            "decorations can match the beauty of the holy symbol that is set "
            "into the base of the altar, howver - its shape is that of a golden ring "
            "cast with a star pattern, and it is inset with a curious kind of "
            "%^BOLD%^g%^RESET%^o%^BOLD%^l%^ORANGE%^d "
            "a%^RESET%^l%^YELLOW%^l%^WHITE%^o%^ORANGE%^y %^RESET%^%^ORANGE%^that "
            "seems to %^BOLD%^shine %^RESET%^%^ORANGE%^brightly regardless of the light "
            "sources around it. Upon the altar itself lies a matching "
            "%^BOLD%^ring %^RESET%^%^ORANGE%^made of the same metal - it would not be "
            "too much trouble to take it, though it appears to have once been "
            "of great importance to the people who lived here.%^WHITE%^",
        ({"skeletons","corpses"}) :
            "The %^BOLD%^skeletal %^RESET%^bodies strewn about the shrine tell a "
            "myriad of different stories, though there is little to identify what "
            "might have ultimately led them to this fate. Broken "
            "%^BOLD%^%^BLACK%^weapons %^RESET%^are discarded next to some "
            "skeletons, who still wear the dried and cracked remains of "
            "%^ORANGE%^leather armor%^WHITE%^, while others are curled up in "
            "corners, with no signs of having put up a resistance. Their "
            "apparent causes of death look to be equally varied - some of the "
            "remains leave no marks behind at all, while other skeletons seem to "
            "have been completely crushed."
        ]));
        boss_summoned = 0;
        summoning_sequence_on = 0;
        set_heart_beat(1);
}

void reset_exit() {
    if(query_exit("east") == "/d/shadowgate/void") {
        tell_room(TO,
            "%^BOLD%^%^BLACK%^The darkness blocking the exit dissipates."
        );
        add_exit(ROOMS"cliff/shrine1","east");
    }
    find_object_or_load(ROOMS"cliff/shrine1")->unblock_west();
}

void reset_boss() {
    boss_summoned = 0;
    summoning_sequence_on = 0;
}

void reset() {
    reset_boss();
    ::reset();
}

void init() {
    ::init();
    add_action("take_func","take");
}

void do_boss_intro(int stage) {
    object *players;
    players = filter_array(all_inventory(TO),"is_non_immortal_player",FILTERS_D);
    if(!sizeof(players)){
        summoning_sequence_on = 0;
        return;
    }
    summoning_sequence_on = 1;
    tell_room(TO,BOSS_SUMMON[stage]);
    if (stage == 4) {
        remove_exit("east");
        find_object_or_load(ROOMS"cliff/shrine1")->block_west();
    }
    if(stage >= 5) {
        object caller;
        int i,j;
        boss_summoned = 1;
        summoning_sequence_on = 0;
        caller = new(MON"caller_in_darkness");
        caller->move(TO);
        j = sizeof(players);
        for(i=0;i<j;i++) {
            caller->kill_ob(players[i],0);
        }
    }
    else {
        call_out("do_boss_intro",ROUND_LENGTH,stage + 1);
    }
}

int take_func(string str) {
    if(!str) {
        return notify_fail("Take what?");
    }
    if(str != "ring") {
        return 0;
    }
    tell_object(TP,
        "%^BOLD%^%^BLACK%^The ring is somehow too heavy to lift, and "
        "%^CYAN%^ice cold %^BLACK%^to the touch."
    );
    tell_room(TP,
        "%^BOLD%^%^BLACK%^+TP->QCN+ attempts to pry the %^ORANGE%^golden ring "
        "%^BLACK%^from the altar's surface, to no avail..."
    ,({TP}));
    if(boss_summoned || summoning_sequence_on) {
        return 1;
    }
    else {
        do_boss_intro(0);
        return 1;
    }
}

void heart_beat() {
    ::heart_beat();
    if(!objectp(TO)) { return; }
    if(!boss_summoned) { return; }
    if (!present("caller in darkness", TO)) {
        reset_exit();
    }
}
