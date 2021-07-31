#include <std.h>
#include <stdprops.h>

inherit OBJECT;

int duration;
int lpower;

void create() {
    ::create();
    set_id( ({ "light","ball","ball of light"}) );
    set_name("light");
    set_short("A tiny ball of bright light");
    set_long("A tiny ball of bright light. It puts off no heat, only a bright light which can light your way.  You can <darken> it when you no longer need it.");
    set_weight(0);
    set_property("no drop", 1);
    set_property("no give", 1);
    set_property(NO_PUT, 1);
    set("value", 0);
}
void init() {
    ::init();
    add_action("douse","darken");

}
//added living(ETO) and ETO->is_room() because of strange 
//bugs with lights put into containers.  If we find another fix, 
//we can probably take it out.  Circe 2/6/04
int move(mixed dest, int power) {
    int x;
    
    lpower = power;

    if (objectp(ETO)){
        if(living(ETO) || ETO->is_room())
        environment(this_object())->set_property("light", -power);
    }
    x = ::move(dest);
    if (objectp(ETO)){
        if(living(ETO) || ETO->is_room())
        environment(this_object())->set_property("light", power);
    }
    return x;
}


remove() {
    if (objectp(ETO))
        ETO->set_property("light",-lpower);
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
