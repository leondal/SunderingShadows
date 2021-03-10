#include <std.h>
inherit OBJECT;
void create() {
    ::create();
    set_id(({"stone","tombstone"}));
    set_short("Tombstone of Darius");
    set_long(
    "This stone appears to be made of some kind of black ice, but it "
    "doesn't seem to be melting. You think magic must have some part "
    "in the creation of it. There is an inscription on it. "
    );
    set_weight(1000000);
    set_value(500);
}
void init() {
    ::init();
    add_action("read_fun","read");
}
    int read_fun(string str) {
    if(str !="inscription" && str !="stone" && str !="tombstone")
    return 0;
    tell_object(TP,"It says: Darius the Evil Magic User shall rot in hell for the pain he has caused.");
    tell_room(environment(TP),TPQCN +" reads the inscription.",TP);
    return 1;
}


