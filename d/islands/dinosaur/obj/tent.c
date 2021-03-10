#include <std.h>
#include "/d/islands/dinosaur/short.h"

inherit OBJECT;

void create(){
    ::create();
    set_name("tent");
    set_short("Large canvas tent");
    set_id( ({"tent", "canvas tent", "large tent"}) );
    set_property("no animate", 1);
    set_long(
      "This large tent looks to house someone.  Perhaps you can enter it."
    );
    set_weight(10000);
    set_value(2);
}

void init(){
    ::init();
    add_action("enter", "enter");
}

int enter(string str){
    if(!str) return notify_fail("enter what?\n");
    if(str != "tent") notify_fail("enter what?\n");

    if(!TP->query_invis()) tell_room(ETP, ""+TPQCN+" enters the tent.", TP);
    TP->move_player("/d/islands/dinosaur/healer.c");
    return 1;
}
