#include <std.h>

inherit OBJECT;

void set_color(string str);
string color;

void create(){
    ::create();
    set_color("grey");
    set_weight(2);
    set_value(20);
}

void init(){
    ::init();
    add_action("throw", "throw");
}

void set_color(string str){
    color = "grey";
    set_name(str+" stone");
    set_short("A small "+str+" stone");
    set_id( ({"stone", str+" stone", "small "+str+" stone"}) );
    set_long(
      "This small rounded "+str+" stone shines slightly when you look at it."
    );
}

int throw(string str){

    if(!str || str != "stone") return notify_fail("throw what?\n");

    tell_object(TP, "You smash the small "+color+" rock into pieces on the ground.");
    tell_room(ETP, TPQCN+" smashes the small "+color+" rock into pieces on the ground.");
    TO->remove();
    return 1;
}
