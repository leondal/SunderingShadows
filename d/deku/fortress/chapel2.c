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
    set_long("%^RED%^This small square room is made from a %^BOLD%^%^BLACK%^black stone%^RESET%^"+
    "%^RED%^ that has been kept in remarkably good condition, so much so that it actually "+
    "seems to %^RESET%^sparkle%^RED%^.  The eastern wall of this room is littered with %^BLUE%^"+
    "windows%^RED%^ that have been boarded up to prevent anyone from seeing into this room "+
    "from the outside.  Directly in the center of this room is an %^BOLD%^%^WHITE%^ashen"+
    "%^RESET%^%^RED%^ colored stone %^BOLD%^%^WHITE%^altar%^RESET%^%^RED%^, which melds into "+
    "the very floor of the room.  Suprisingly it is not blood stained, as if it has never saw a "+
    "sacrifice, at least not a living one.  An %^BLUE%^open doorway%^RED%^ in the western wall "+
    "of this room leads back to the foyer.%^RESET%^\n");
 
    set_exits(([
        "west" : GY_ROOMS +"chapel1",
    ] ));
 
    set_smell("default","The air here reeks with a strong odor of death and decay.");
    set_listen("default","A loud chanting seems to echo from the very walls.");

    set_items(([
    ({"ashen altar","ash alatar","altar","stone altar", "ashen stone altar"}) : "%^BOLD%^%^WHITE%^This small altar "+
    "is made from an ashen colored stone.  It looks as if it has never seen a living sacrifice, "+
    "as it has no crimson spots.  It rests directly in the center of the room and melds into "+
    "the floor.%^RESET%^",
    ({"stone","black stone"}) : "%^BOLD%^%^BLACK%^The room is made entirely out of this "+
    "strange black stone.  It seems to continually sparkle, even in pitch black.%^RESET%^",
    ({"doorway","open doorway"}) : "%^BLUE%^This doorway is set into the western wall of the "+
    "room.  It leads back into the foyer of the chapel.%^RESET%^",
    "sparkle" : "The %^BOLD%^%^BLACK%^black stone%^RESET%^ that constructs this room seems "+
    "to continually sparkle and glisten, even in pitch black.",			
    ({"windows","boarded windows"}) : "%^MAGENTA%^These windows litter the eastern "+
    "wall of the room.  All of them have been boarded up to prevent anyone from seeing into "+
    "this room from the outside.%^RESET%^",
    ({"floor"}) : "%^BOLD%^%^BLACK%^The floor here is made from a black stone, it looks like "+
    "it is constantly cleaned and suprisingly it has been kept in remarkably good "+
    "condition.  An %^BOLD%^%^WHITE%^ashen%^BOLD%^%^BLACK%^ colored %^BOLD%^%^WHITE%^stone "+
    "altar%^BOLD%^%^BLACK%^ rises up from the very center of it.%^RESET%^",
    ({"ceiling"}) : "%^BOLD%^%^BLACK%^The ceiling here is made from a black stone that has "+
    "been kept in remarkably good condition.%^RESET%^",
    ] ));
}

void reset() {
    object ob,ob2;
    ::reset();

    if(!present("priest")) {
        if(random(10) >= 8) {
            ob = new("/d/deku/monster/priest");
            ob->move(TO);
            ob2 = new(GY_OBJS+"ancientchapelkey");
            ob2->move(ob);
        }
    }

    if(!present("antipaladin")) {
        if(random(4) >= 2) {
            new("/d/deku/monster/antipaladin")->move(TO);
        }
    }
}