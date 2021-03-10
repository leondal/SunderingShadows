#include <std.h>
#include "../ud_ruins.h"
inherit CROOM;

void find_obj(object player);
void find_nothing(object player);
int do_chwidencha(object victim);
void set_pop();
int searched = 0;

void create() {
    set_repop(30);
    set_pop();
    ::create();
    set_name("a narrow cavern passage");
    set_property("indoors",1);
    set_property("light", 0);
    set_terrain(NAT_CAVE);
    set_travel(FRESH_BLAZE);
    set_property("no teleport", 1);
    set_short(
        "%^CYAN%^a %^BOLD%^%^WHITE%^narrow %^RESET%^%^CYAN%^cavern "
        "passage%^WHITE%^"
    );
    set_long(
        "%^BOLD%^%^BLACK%^You are within a narrow set of twisting narrow "
        "tunnels. The earth beneath you is unusually soft here, made up of "
        "%^RESET%^%^ORANGE%^l%^BOLD%^%^WHITE%^o%^RESET%^o%^BOLD%^%^BLACK%^s"
        "%^RESET%^%^ORANGE%^e "
        "g%^BOLD%^%^WHITE%^r%^RESET%^a%^ORANGE%^v%^BOLD%^%^BLACK%^e"
        "%^RESET%^%^ORANGE%^l %^BOLD%^%^BLACK%^and "
        "%^RESET%^%^ORANGE%^dirt%^BOLD%^%^BLACK%^, and the walls tower up "
        "above you, reaching so high that it is difficult to see the cavern"
        "ceiling. Much of the terrain is covered with strange coarse "
        "%^RESET%^spiderwebs%^BOLD%^%^BLACK%^."
    );
    set_smell("default", "You can smell the soft earth below.");
    set_listen("default", "A faint clattering echoes down the tunnel's length.");
    set_exits(([
    ]));
    set_items(([
        ({"walls","tunnels"}) :
            "%^BOLD%^%^BLACK%^The walls here are surprisingly smooth, looking "
            "to have been eroded away over the centuries. Taken with its high "
            "walls and the large deposits of loose sediment underfoot, it is "
            "likely that these tunnels were once part of some "
            "%^RESET%^%^CYAN%^subterranean river%^BOLD%^%^BLACK%^.",
        "spiderwebs" :
            "These spiderwebs are far thicker and coarser than that of an "
            "average spider, and some of the fresher-looking strands are "
            "slightly %^BOLD%^ac%^GREEN%^i%^WHITE%^dic %^RESET%^to the touch.",
        ({"ground","dirt","gravel","floor","earth"}) :
            "%^ORANGE%^The loose gravel and dirt underfoot seems to be made up "
            "of sediment from an origin other than these tunnels, and were "
            "likely carried here from some other location. If one had enough "
            "time, they could likely search through the gravel for something "
            "useful."
        ]));
    set_search("ground",(:TO, "search_func":));
}

void init() {
    ::init();
}

void search_func() {
    if (!objectp(TP)) { return 0; }
    if (searched) {
        tell_object(TP,
            "%^ORANGE%^The ground here is already disturbed - if there was "
            "something of value here, it has already been found."
        );
        return;
    }
    if(do_chwidencha(TP)) { return; }
    if(!random(3)) {
        find_obj(TP);
    }
    else {
        find_nothing(TP);
    }
    searched = 1;
}

void find_obj(object player) {
    tell_object(player,
        "%^ORANGE%^Digging around in the gravel, you manage to locate something"
        " forgotten amidst the sediment."
    );
    tell_room(TO,
        "%^ORANGE%^"+player->QCN+" digs around in the gravel for a while, and "
        "seems to find something."
    ,({player}));
    switch(random(3)) {
        case 0:
            "/d/common/daemon/randstuff_d"->find_stuff(TO,"component",random(20));
            break;
        case 1:
            "/d/common/daemon/randstuff_d"->find_stuff(TO,"psi_component",random(20));
            break;
        case 2:
            "/d/common/daemon/randstuff_d"->find_stuff(TO,"potion",random(20));
            break;
    }
}

void find_nothing(object player) {
    tell_object(player,
        "%^ORANGE%^You dig around in the gravel for a while, but don't seem to "
        "find anything."
    );
    tell_room(TO,
        "%^ORANGE%^+player->QCN+ digs around in the gravel for a while."
    ,({player}));
}

int do_chwidencha(object victim) {
    // If the victim does not have the "c_stalked" property, add it and do nothing.
    // Otherwise, spawn in a chwidencha and make it attack the target, removing
    // the property. Returns 1 if an attack is imminent.
    int stalked_stage;
    stalked_stage = victim->query_property("c_stalked");
    if (!stalked_stage) {
        victim->set_property("c_stalked", 1);
        return 0;
    }
    stalked_stage++;
    if(stalked_stage == 3) {
        tell_room(TO,
            "%^ORANGE%^You feel a faint %^BOLD%^%^BLACK%^tremor "
            "%^RESET%^%^ORANGE%^from underneath the earth..."
        );
    }
    else if (stalked_stage >= 4 + random(3)) {
        object mon;
        tell_room(TO,
            "%^YELLOW%^The ground erupts in an explosion of rock and dust! A "
            "%^RED%^h%^WHITE%^o%^RED%^rr%^RESET%^i%^BOLD%^%^RED%^f%^RESET%^y"
            "%^BOLD%^%^GREEN%^i%^RED%^ng "
            "%^BLACK%^a%^RED%^b%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^m%^RED%^i"
            "%^RESET%^n%^BOLD%^%^BLACK%^a%^WHITE%^t%^RESET%^i%^BOLD%^%^RED%^o"
            "%^BLACK%^n %^ORANGE%^with dozens of %^WHITE%^razor-sharp legs "
            "%^ORANGE%^is suddenly upon you!"
        );
        victim->remove_property("c_stalked");
        mon = new(MON"chwidencha");
        mon->move(TO);
        mon->frenzy();
        return 1;
    }
    victim->set_property("c_stalked",1);
    return 0;
}

void set_pop() {
    // Sword spiders should spawn in groups of 1-2, in roughly every other room.
    if (base_name(TO) == STORAGE"_lair_base") { return; }
    if(!random(2)) {
        set_monsters(({MON"sword_spider"}),({random(2) + 1}));
    }
}
