#include <std.h>
#include <daemons.h>

inherit ROOM;
inherit "/std/virtual/compile";

int is_virtual() { return 1; }

void create()
{   
    ::create();
    set_property("indoors",0);
    set_property("light",2);
    set_property("no sticks",1);
    //set_no_clean(1);

    set_short("Plane of Shadows");
    set_long("You are lost in the Plane of Shadow.");

    set_smell("default","The air is full of a strange scent.");
    set_listen("default","You hear nothing but your own thoughts.");
}

void remove()
{
    object *inv;
    
    inv = all_inventory(this_object());
    
    tell_room(this_object(), "The plane collapses and you are whisked away just in time!");
    
    foreach(object ob in inv)
    {
        if(playerp(ob))
            move_player(ob, (object)"/d/common/obj/daily/entrance");
    }
    
    ::remove();
}
