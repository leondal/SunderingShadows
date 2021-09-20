#include <std.h>
#include <daemons.h>

inherit ROOM;

void create()
{   
    ::create();
    set_property("indoors",0);
    set_property("light",2);
    set_property("no sticks",1);
    //set_no_clean(1);

    set_short("Entrance to the Demiplanes");
    set_long("Entrance to the Demiplanes.");

    set_smell("default","The air is full of a strange scent.");
    set_listen("default","You hear nothing but your own thoughts.");
}
