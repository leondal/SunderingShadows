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
    "it actually seems to %^RESET%^sparkle%^RED%^.  A spotless %^BOLD%^%^WHITE%^ashen%^RESET%^"+
    "%^RED%^ colored %^RESET%^stone altar%^RED%^ rises from the floor directly in the center "+
    "of the room.  All of the walls are completely bare, except for the %^CYAN%^southern"+
    "%^RESET%^%^RED%^ one, which is decorated by what looks strikingly similiar to the back "+
    "of a framed %^BLUE%^painting%^RED%^.%^RESET%^\n");	

    set_smell("default","The air here reeks with a strong odor of death and decay.");
    set_listen("default","A loud chanting seems to echo from the very walls.");

    set_items(([
    ({"stone","black stone"}) : "%^BOLD%^%^BLACK%^The room is made entirely out of this "+
    "strange black stone.  It seems to continually sparkle, even in pitch black.%^RESET%^",
    "sparkle" : "The %^BOLD%^%^BLACK%^black stone%^RESET%^ that constructs this room seems "+
    "to continually sparkle and glisten, even in pitch black.",			
    ({"floor"}) : "%^BOLD%^%^BLACK%^The floor here is made from a black stone, it looks like "+
    "it is constantly cleaned and suprisingly it has been kept in remarkably good "+
    "condition.  An %^BOLD%^%^WHITE%^ashen%^BOLD%^%^BLACK%^ colored %^RESET%^stone altar"+
    "%^BOLD%^%^BLACK%^ rises up from the center of the floor.%^RESET%^",
    ({"ceiling"}) : "%^BOLD%^%^BLACK%^The ceiling here is made from a black stone that has "+
    "been kept in remarkably good condition.%^RESET%^",
    ({"framed painting","painting"}) : "%^BLUE%^This decorates the southern wall of the room.  "+
    "It looks like the back of a painting and upon closer inspection you realize that you can "+
    "see right through it.  You could probably even %^RESET%^%^CYAN%^step through%^BLUE%^ it "+
    "if you wanted to.%^RESET%^",
    ({"altar","stone altar","ashen altar","ashen colored altar"}) : "%^BOLD%^%^WHITE%^This "+
    "altar is made from an ashen colored stone.  It rises from the center of the floor and "+
    "is completely spotless, apparently it has never seen a living sacrifice.%^RESET%^",
    ({"walls","wall"}) : "%^BOLD%^%^BLACK%^The walls of this room are made from a strange "+
    "black stone that seems to sparkle and glisten, even in pitch black.  All of them are "+
    "completely bare, except for the southern one.  What appears to be the back of a painting "+
    "decorates it.%^RESET%^",
    ({"south wall","southern wall"}) : "%^BOLD%^%^BLACK%^This wall is decorated by what "+
    "appears to be the back of a %^RESET%^%^BLUE%^painting%^BOLD%^%^BLACK%^.%^RESET%^",
    ] ));
}

void init() {
    ::init();
    add_action("step_action","step");
}

void reset() {
    if(!present("faceless beast") && !random(2)) {
        new(GY_MOBS+"faceless_beast")->move(TO);
    }
}

int step_action(string str) {
    if(!str) { return 0; }
    if(str == "through painting" || str == "painting") {
	    if(!objectp(TP)) return 1;
		tell_object(TP,"%^RED%^You step through the painting and find yourself somewhere "+
        "else!%^RESET%^");
        if(!TP->query_invis()) {
            tell_room(TO,TPQCN+"%^RED%^ steps through the painting!%^RESET%^",TP);
        }
        TP->move_player(find_object_or_load(GY_ROOMS+"chapel6"));
        return 1;
	}
	return 0;
}