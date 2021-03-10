//Coded by Lujke


#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("wicker screen");
    set_id( ({"screen","wicker screen" }) );
    set_short("%^ORANGE%^wicker screen%^RESET%^");
    set_weight(4);
    set_long("%^ORANGE%^A screen, about four feet by six feet, made from a"
            +" strange, unruly form of wicker in which the individual"
            +" strands wind around one another in a disorderly, organic"
            +" fashion");
}

void init(){
  ::init();
}
