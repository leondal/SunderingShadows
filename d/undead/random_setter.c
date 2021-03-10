// Sticking this into it's own object to hopefully eleminate recursion errors -Ares
#include <std.h>
#include "undead.h"

inherit OBJECT;

void place_tomb();

int SET;
object room1, room2;

void create()
{
    if(SET) { /* tell_object(find_player("ares"),""+base_name(room1)+" "+base_name(room2)+""); */ /* Debug */ return; }
    ::create();
    SET = 1;
    place_tomb();
    return;
}

void place_tomb() // Probably more error checks than it needs, but I'm tired of the bugs
{
    object place,road;
    string path,*rooms;
    
    road = find_object_or_load(OBJ"temproad");
    // room1 = road; // Debug
    road->set_no_clean(1);
    if(!objectp(road)) { return error(""+OBJ+"temproad not a valid object."); }
    
    rooms = get_dir(DES);
    if(!pointerp(rooms)) { return error("Invalid room array."); }

    path = rooms[random(sizeof(rooms))];
    
    place = find_object_or_load(DES+path);
    // room2 = place; // Debug
    if(!objectp(place)) { return error(""+DES+path+" not a valid object."); }

    place->set_no_clean(1);
    place->add_exit(base_name(road),"hole");
    road->add_exit(base_name(place),"up");

    //tell_object(find_player("ares"),""+base_name(room1)+" "+base_name(room2)+""); // Debug
    return;
}


