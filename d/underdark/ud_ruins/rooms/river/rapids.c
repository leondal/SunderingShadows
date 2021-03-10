#include <std.h>
#include <magic.h>
#include <daemons.h>
#include "../../ud_ruins.h"

// Boss fight room for Kuo-tao leviathan. Fight takes place while being pulled
// down some underdark river by its strong currents, and also doubles as the path
// out of the area. The fight is timed, lasting 10 rounds before the player
// is spit out into an exit room. If they manage to kill the kuo-toa, its corpse
// will wash up with them.

#define INIT_CUTSCENE ({\
    "%^BOLD%^%^CYAN%^The river's current flows sharply downward, pulling you "\
    "along with it into a tunnel of %^BLACK%^pitch blackness%^CYAN%^!",\
    "\n\n%^BOLD%^%^CYAN%^It is all you can do to keep your head above water!",\
    "\n\n%^CYAN%^Suddenly, you feel an ominous "\
    "%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^mb"\
    "%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^n"\
    "%^BOLD%^%^BLACK%^g %^RESET%^%^CYAN%^from from beneath you. Even moving "\
    "as quickly as you are, it seems as if something is following you...",\
    "\n\n%^BOLD%^%^CYAN%^Just in front of you, a %^GREEN%^massive "\
    "w%^RESET%^%^GREEN%^e%^BOLD%^b%^RESET%^b%^GREEN%^e%^BOLD%^d "\
    "h%^WHITE%^a%^RESET%^n%^BOLD%^%^GREEN%^d %^CYAN%^thrusts up from beneath the "\
    "water's surface! You see an enourmous %^GREEN%^fish's head %^CYAN%^emerge "\
    "shortly after, as it grabs for you!",\
})

inherit ROOM;

void start_battle(int cutscene);
void battle_round();
void end_battle();
int battle_initiated, cur_round;

void create() {
    ::create();
    set_name("caught in the rapids");
    set_property("indoors",1);
    set_property("light", 0);
    set_terrain(NAT_CAVE);
    set_travel(FRESH_BLAZE);
    set_property("no teleport", 1);
    set_short(
        "%^BOLD%^%^CYAN%^caught in the rapids%^RESET%^"
    );
    set_long(
        "%^CYAN%^You are caught within the rapids of a rushing, subterranean "
        "stream! It is too dark to make out much of anything, and the mists "
        "obscure your vision even further. It is about all you can do to stay "
        "afloat and conscious as you are dragged along.%^WHITE%^"
    );
    set_smell("default", "The stench of fish is strong.");
    set_listen("default", "The thundrous current of the river rushes past you.");
    set_property("no peer",1);
    set_peer_message(
        "%^BOLD%^%^BLACK%^You cannot see far down the ravine at all."
    );
    battle_initiated = 0;
    cur_round = 0;
}

void init() {
    ::init();
    if (avatarp(TP)) { return; }
    if (!userp(TP)) { return; }
    if (TP->query_true_invis()) { return; }
    if(!battle_initiated) {
        start_battle(0);
    }
}

void truce_func() {
    object *inv;
    int i,j;
    inv = filter_array(all_inventory(TO),"is_living",FILTERS_D);
    j = sizeof(inv);
    for(i=0; i<j; i++) {
        inv[i]->cease_all_attacks();
    }
}

object *get_players() {
    object *players;
    players = filter_array(all_inventory(TO),"is_non_immortal_player",FILTERS_D);
    return players;
}

void start_battle(int cutscene) {
    battle_initiated = 1;
    cur_round = 0;
    tell_room(TO,
        INIT_CUTSCENE[cutscene]
    );
    cutscene++;
    if (cutscene > 3) {
        object lev;
        object *players;
        int i,j;
        //Spawn in leviathan, start counter.
        lev = new(MON"kuo_toa_leviathan");
        lev->move(TO);
        players = get_players();
        j = sizeof(players);
        for(i=0;i<j;i++) {
            lev->force_me("kill "+players[i]->query_name());
        }
        battle_round();
    }
    else {

        call_out("start_battle",ROUND_LENGTH,cutscene);
    }
}

void battle_round() {
    // Keeps track of the number of rounds the battle has been going on for.
    // If it reaches the max, end the fight and move all players,
    // and items/corpses on ground to the exit area.
    if(cur_round >= 10) {
        end_battle();
    }
    else {
        cur_round++;
        call_out("battle_round",ROUND_LENGTH);
    }
}

void end_battle() {
    object lev, random_player, *objects, *players;
    int i,j;
    cur_round = 0;
    battle_initiated = 0;
    if (lev = present("leviathan",TO)) {
        truce_func();
        lev->move("/d/shadowgate/void");
        lev->remove();
        tell_room(TO, "\n\n"
            "%^BOLD%^%^CYAN%^The current suddenly picks up, pulling you away "
            "from the battle!\n\n"
        );
    }
    else {
        tell_room(TO,"\n\n"
            "%^BOLD%^%^CYAN%^The current suddenly picks up, carrying you away!"
            "\n\n"
        );
    }
    // Move any items in-room (such as the boss corpse, if it is killed) to
    // one of the players after they are deposited outside.
    // Since this can lead to one of three different exits, move the players
    // first, then move the contents of the room to one of the players.

    players = get_players();
    j = sizeof(players);
    if(!j) { return; }
    for(i=0;i<j;i++) {
        players[i]->move_player(ROOMS"river/exit_room_" + random(3));
    }

    objects = filter_array(all_inventory(TO),"is_nonliving",FILTERS_D);
    j = sizeof(objects);
    if (!j) { return; }
    random_player = players[random(sizeof(players))];
    for(i=0;i<j;i++) {
        objects[i]->move(environment(random_player));
    }
    tell_object(random_player,
        "%^BOLD%^%^CYAN%^You lose track of time as the subterranean river "
        "carries you along. ...eventually, you find yourself washed up upon a "
        "softer river shore.\n\n"
    );
    tell_room(environment(random_player),
        "%^YELLOW%^Something seems to have washed up on the shore behind you."
    );
}
