#include <std.h>
#include "forest.h"
#include <daemons.h>

inherit DAEMON;

int place_trap(object room) {
    object *exs;
    string dir;

    if(!pointerp(room->query_exits())) return 0;
    if(!sizeof(room->query_exits())) return 0;
    exs = room->query_exits();
    dir = exs[random(sizeof(exs))];
    room->set_trap_functions(({dir}),({"/d/deku/inherits/fire_traps_d.c->fried()"}),({dir}));
    return 1;
}

int fried(){
    string verb;
    object *alive;
    int x;
    alive = all_living(TO);
    alive -= ({TP});
    verb = TP->query_verb();

    TO->toggle_trap(verb,verb);
    tell_object(TP,"TEST!");
    return 1;
}
