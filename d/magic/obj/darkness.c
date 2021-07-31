#include <std.h>
#include <stdprops.h>

inherit OBJECT;

int duration;
int dpower;

void create() {
    ::create();
    set_id( ({ "darkness","globe","globe of darkness"}) );
    set_name("darkness");
    set_short("A globe of darkness");
    set_long("A globe of darkness. It puts off no heat or cold, only a void which sucks in light.  You can <raise> it when you no longer need it.");
    set_property("no drop", 1);
    set_property("no give", 1);
    set_property(NO_PUT, 1);
    set_weight(0);
    set("value", 0);
}
void init() {
    ::init();
    add_action("douse","raise");

}

varargs int move(mixed dest, int power) {
    int x;

    if(!power)
        power = 2;
    dpower = power;
    if (objectp(ETO))
        environment(this_object())->set_property("light", power);
    x = ::move(dest);
    if (objectp(ETO))
        environment(this_object())->set_property("light", -power);
    return x;
}


remove() {
    if (objectp(ETO))
        ETO->set_property("light",dpower);
    tell_room(environment(TO),"A globe has dissipated.");

    return ::remove();
}

int douse(string str) {
    if (str != "darkness") return 0;
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
