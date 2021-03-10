#include <std.h>

inherit OBJECT;

int duration;

void create() {
    ::create();
    set_id( ({ "light","ball","ball of light"}) );
    set_name("light");
    set_short("A tiny ball of bright light");
    set_long("A tiny ball of bright light. It puts off no heat, only a bright light which can light your way.  You can <darken> it when you no longer need it.");
    set_weight(0);
    set("value", 0);
}
void init() {
    ::init();
    add_action("douse","darken");

}

int move(mixed dest) {
    int x;

    if (objectp(ETO))
        environment(this_object())->set_property("light", -2);
    x = ::move(dest);
    if (objectp(ETO))
        environment(this_object())->set_property("light", 2);
    return x;
}


remove() {
    if (objectp(ETO))
        ETO->set_property("light",-2);
    tell_room(environment(TO),"A light source has gone out.");

    return ::remove();
}

int douse(string str) {
    if (str != "light") return 0;
    if(query_property("spell"))
        query_property("spell")->dest_effect();
    else
        remove();
    return 1;
}

int save_me(string file) {
    return 1;
}
// Hack to get around imperfect implementation of detect magic in /std/Object.c
int isMagic() { return 2;}
