#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("small room");
    set_short("%^BOLD%^%^BLACK%^Small room%^RESET%^");
    set_long("%^RED%^This square room is very small and made from a %^BOLD%^%^BLACK%^black "+
    "stone%^RESET%^%^RED%^ that has been kept in remarkably good condition, so much so that "+
    "it actually seems to %^RESET%^sparkle%^RED%^.  The western wall of this room is littered "+
    "with %^BLUE%^windows%^RED%^ that have been boarded up to prevent anyone from seeing into "+
    "this room from the outside.  Strangely this room seems out of proportion to the "+
    "other rooms of this chapel, almost like half of it is missing.  A lone %^BLUE%^painting"+
    "%^RED%^ decorates the northern wall of this room.  There is an %^BLUE%^open doorway"+
    "%^RED%^ in the eastern wall of this room that has been covered with a %^BOLD%^%^BLACK%^"+
    "thick black curtain%^RESET%^%^RED%^.%^RESET%^");

    set_exits(([
    "east" : GY_ROOMS +"chapel4",
    ] ));
 
    set_smell("default","The air here reeks with a strong odor of death and decay.");
    set_listen("default","A loud chanting seems to echo from the very walls.");

    set_items(([
    ({"stone","black stone"}) : "%^BOLD%^%^BLACK%^The room is made entirely out of this "+
    "strange black stone.  It seems to continually sparkle, even in pitch black.%^RESET%^",
    ({"doorway","open doorway"}) : "%^BLUE%^This doorway is set into the eastern wall of the "+
    "room.  It is covered with a %^BOLD%^%^BLACK%^thick black curtain%^RESET%^%^BLUE%^"+
    ".%^RESET%^",
    "sparkle" : "The %^BOLD%^%^BLACK%^black stone%^RESET%^ that constructs this room seems "+
    "to continually sparkle and glisten, even in pitch black.",			
    ({"windows","boarded windows"}) : "%^MAGENTA%^These windows litter the western "+
    "wall of the room.  All of them have been boarded up to prevent anyone from seeing into "+
    "this room from the outside.%^RESET%^",
    ({"floor"}) : "%^BOLD%^%^BLACK%^The floor here is made from a black stone, it looks like "+
    "it is constantly cleaned and suprisingly it has been kept in remarkably good "+
    "condition.%^RESET%^",
    ({"ceiling"}) : "%^BOLD%^%^BLACK%^The ceiling here is made from a black stone that has "+
    "been kept in remarkably good condition.%^RESET%^",
    ({"curtain","thick curtain","black curtain","thick black curtain"}) : "%^BOLD%^%^BLACK%^"+
    "This curtain is made from a thick black cloth.  It is covering the %^BLUE%^open doorway"+
    "%^BOLD%^%^BLACK%^ in the eastern wall of this room.%^RESET%^",
    ({"painting","lone painting"}) : "%^BLUE%^This lone painting decorates the northern wall.  "+
    "It shows a man, most likely a human, laying himself down on an %^BOLD%^%^WHITE%^ashen"+
    "%^RESET%^%^BLUE%^ colored %^RESET%^stone%^BLUE%^ altar.  You notice several large "+
    "%^RESET%^stone pillars%^BLUE%^ rising from the floor in the room surrounding the altar.  "+
    "Just looking at the painting sends chills down your spine.%^RESET%^",
    ] ));
    set_pre_exit_functions(({"east"}),({"GoThroughDoor"}));
    set_post_exit_functions(({"east"}),({"covered"}));
}

void covered() {
    tell_room(TO,"%^BOLD%^%^BLACK%^The curtain falls back into place over the %^BLUE%^open "+
    "doorway%^BOLD%^%^BLACK%^.");
}

int GoThroughDoor(){
    tell_object(TP,"%^BOLD%^%^BLACK%^You push the curtain out of the way and step through the "+
    "%^BLUE%^open doorway%^BOLD%^%^BLACK%^.%^RESET%^");
    tell_room(TO,TPQCN+"%^BOLD%^%^BLACK%^ pushes the curtain out of the way and steps through "+
    "the %^BLUE%^open doorway%^BOLD%^%^BLACK%^.%^RESET%^",TP);
    return 1;
}

void reset() {
    ::reset();

    if(!present("priest")) {
        if(random(4) >= 2) {
            new("/d/deku/monster/priest")->move(TO);
        }
    }

    if(!present("antipaladin")) {
        if(random(4) >= 2) {
            new("/d/deku/monster/antipaladin")->move(TO);
        }
    }
}