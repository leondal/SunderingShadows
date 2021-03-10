#include <std.h>
#include "../dagger.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("A ruined shop");
    set_short("%^BOLD%^%^BLACK%^A ruined shop%^RESET%^"); 
    set_long("%^BOLD%^%^BLACK%^You have entered a room that is absolutely destroyed. Bottles and pots have "
"been smashed all over the room, cots and bedding slashed and scattered, supplies strewn all over the place. "
"The contents and remains of those items have mixed with what was once a huge %^RESET%^%^RED%^pool of blood "
"%^BOLD%^%^BLACK%^and the smell is atrocious.  There is still a list on the wall of what once was served here, "
"but it is too covered in grime and blood to be legible.%^RESET%^");
    set_smell("default","An acrid, burnt smell fills the air.");
    set_listen("default","It is deathly quiet here.");
    set_exits( ([
      "south" : STREETS"street24",
    ] ));
}
