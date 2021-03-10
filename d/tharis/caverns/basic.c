//Coded by Bane//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("Tharis caverns");
    set_short("A dark cavern");
    set_long(
    );
    set_property("light",2);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_exits( ([
    ]) );
}
