#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit VAULT;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("altar room");
    set_short("%^BOLD%^%^WHITE%^Altar room of the Ancient Chapel%^RESET%^");
    set_long("%^RED%^You find yourself in the altar room of this %^RESET%^ancient chapel"+
    "%^RED%^.  The walls, floor, and ceiling are made from a %^BOLD%^%^BLACK%^black stone"+
    "%^RESET%^%^RED%^ and have been kept in remarkable condition, so much so that they "+
    "actually seem to %^RESET%^sparkle%^RED%^.  Massive %^RESET%^stone pillars%^RED%^ "+
    "rise from the eastern and western sides of the room to the %^BOLD%^%^BLACK%^ceiling"+
    "%^RESET%^%^RED%^, some twenty feet above.  There is an %^BOLD%^%^WHITE%^ashen%^RESET%^"+
    "%^RED%^ colored %^RESET%^stone altar%^RESET%^%^RED%^ at the northern wall, it seems "+
    "more of an extension of the wall than an independant structure, as it melds into it.  "+
    "The altar is stained with blood, obviously it has been used quite frequently for "+
    "sacrificing living creatures.  To either side of it are %^MAGENTA%^boarded windows"+
    "%^RESET%^%^RED%^, made such to prevent anyone from viewing this room from the outside.  "+
    "There is an %^BLUE%^open doorway%^RED%^ in the eastern and the western wall of this room, "+
    "each covered by a thick %^BOLD%^%^BLACK%^black curtain%^RESET%^%^RED%^.  Inset into the "+
    "center of the southern wall is a %^BOLD%^%^BLACK%^metal door%^RESET%^%^RED%^ that leads "+
    "to the foyer of the chapel.%^RESET%^\n");

    set_exits(([
    "south" : GY_ROOMS + "chapel1",
    "east" : GY_ROOMS + "chapel5",
    "west" : GY_ROOMS + "chapel6"
    ] ));

    set_door("metal door",GY_ROOMS+"chapel1","south","ancient chapel key","lock");
    set_locked("metal door",1,"lock");
    set_lock_description("metal door","lock","%^BOLD%^%^BLACK%^The keyhole of this lock "+
    "is cylindrical in shape.  It awaits a small cylinder rather "+
    "than a key.%^RESET%^");
    set_door_description("metal door","%^BOLD%^%^BLACK%^This metal door is inset directly "+
    "into the center of the southern wall.  It has a lone knob on the left side with a "+
    "cylindrical keyhole in the center of it.  Its made from a simple metal that has been blackened."+
    "%^RESET%^");	
    lock_difficulty("metal door",-5,"lock");
    set_smell("default","The air here reeks with a strong odor of death and decay.");
    set_listen("default","A loud chanting seems to echo from the very walls.");
    set_items(([
    ({"altar","stone altar","ashen altar","ashen stone altar"}) : "%^BOLD%^%^WHITE%^This ashen colored stone altar is stained "+
    "with %^RED%^blood%^BOLD%^%^WHITE%^, an obvious testimony to its purpose.  It rests against "+
    "the northern wall and seems more of an extensive of that wall than an independent "+
    "structure as it appears to meld into it.  Just looking at it gives you the feeling "+
    "that it is awaiting its next %^RED%^sacrifice%^BOLD%^%^WHITE%^, perhaps you could offer "+
    "it?%^RESET%^",
    ({"chapel","ancient chapel"}) : "%^BOLD%^%^WHITE%^This chapel is made entirely out of a "+
    "%^BOLD%^%^BLACK%^black stone%^BOLD%^%^WHITE%^.  The chanting that seems to be echoing "+
    "from the very walls suggests that it may not be so ancient afterall.  It is probably "+
    "even inhabited right now.%^RESET%^",
    ({"stone","black stone"}) : "%^BOLD%^%^BLACK%^This altar room is made entirely out of this "+
    "strange black stone.  It seems to continually sparkle, even in pitch black.%^RESET%^",
    ({"floor"}) : "%^BOLD%^%^BLACK%^The floor here is made from a black stone, it looks like "+
    "it is constantly cleaned and suprisingly it has been kept in remarkably good "+
    "condition.  Two %^RESET%^stone pillars%^BOLD%^%^BLACK%^ rise up from the eastern and "+
    "two from the western side of it.  They meet the ceiling some twenty feet above and "+
    "meld into it.%^RESET%^",
    ({"ceiling"}) : "%^BOLD%^%^BLACK%^The ceiling here is made from a black stone that has "+
    "been kept in remarkably good condition.  Two %^RESET%^stone pillars%^BOLD%^%^BLACK%^"+
    " descend from the eastern and two from the western sides of it.  They meet the floor "+
    "some twenty feet below and meld into it.%^RESET%^",
    ({"walls","wall"}) : "%^BOLD%^%^BLACK%^The walls of this room are made from a black stone "+
    "and have been kept in remarkably good condition.  A metal door is inset into the southern "+
    "one, open doorways are centerened in the eastern and western walls, each covered with "+
    "a thick black curtain.%^RESET%^",
    ({"doorway","open doorway"}) : "%^BLUE%^One of these adorn the eastern and another the "+
    "western wall of this room.  They are each covered with a %^BOLD%^%^BLACK%^thick black"+
    "%^RESET%^%^BLUE%^ curtain.%^RESET%^",
    "sparkle" : "The %^BOLD%^%^BLACK%^black stone%^RESET%^ that constructs this room seems "+
    "to continually sparkle and glisten, even in pitch black.",		
    ({"windows","boarded windows"}) : "%^MAGENTA%^These windows are inset into the wall "+
    "on either side of the %^BOLD%^%^WHITE%^ashen altar%^RESET%^%^MAGENTA%^.  They have been "+
    "boarded up to prevent viewing access from the outside of the building.%^RESET%^",
    ({"pillars","stone pillars","pillar","stone pillar"}) : "These pillars are made from "+
    "an %^BOLD%^%^WHITE%^ashen%^RESET%^ colored stone that shows no sign of aging.  There are "+
    "four of them in all, two on each side of the room.  They rise up from the floor some "+
    "twenty feet and meld into the ceiling.",
    ({"curtain","black curtain","thick curtain","thick black curtain","curtains"}) : "%^BOLD%^"+
    "%^BLACK%^These thick curtains are made from a black cloth.  They cover the open doorways "+
    "that lead from this room.%^RESET%^",
    ] ));
	 
    set_pre_exit_functions(({"east","west"}),({"pushcurtain","pushcurtain"}));
    set_post_exit_functions(({"east","west"}),({"covered","covered"}));
}

void init() {
    ::init();
    add_action("sacrifice_action","sacrifice");
}

void reset() {
    object ob,ob2;
    ::reset();

    if(!present("priest")) {
        ob = new("/d/deku/monster/priest_l");
        ob->move(TO);
        ob2 = new(GY_OBJS+"ancientchapelkey");
        ob2->move(ob);
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

void sacrifice_stuff(object what, int step) {
    if(interactive(what)) {
        switch(step) {
		    case 0:
                tell_object(what,"%^BOLD%^%^BLACK%^You've completely laid down on the %^RESET%^stone "+
                "altar%^BOLD%^%^BLACK%^ and your surroundings begin to %^YELLOW%^blur%^BOLD%^"+
                "%^BLACK%^!%^RESET%^");
                tell_room(TO,"%^BOLD%^%^BLACK%^A darkness seeps upward from the %^RESET%^stone altar"+
                "%^BOLD%^%^BLACK%^ and covers "+what->QCN+"%^BOLD%^%^BLACK%^!",what);
                break;
            case 1:
                tell_object(what,"%^BOLD%^%^BLACK%^You're completely disoriented and cannot see!%^RESET%^");
                tell_room(TO,"%^BOLD%^%^BLACK%^The darkness has completely covered "+what->QCN+
                "%^BOLD%^%^BLACK%^!%^RESET%^",what);
                what->set_temporary_blinded(2,"%^BOLD%^%^BLACK%^You are disoriented and cannot "+
                "see!%^RESET%^");
                break;
            case 2:
                what->move_player(GY_ROOMS+"chapel7");
                tell_object(what,"%^BOLD%^%^BLACK%^You sit up on the altar and struggle to see!%^RESET%^");
                tell_room(TO,"%^BOLD%^%^BLACK%^The darkness suddenly vanishes, as quickly as it came, and "+
                what->QCN+" is gone!%^RESET%^",what);
                if(!what->query_invis()) {
                    tell_room(environment(what),what->QCN+"%^BOLD%^%^BLACK%^ appears on the %^RESET%^stone "+
                    "altar%^BOLD%^%^BLACK%^!%^RESET%^",what);
			    }
                what->set_paralyzed(0,"%^RED%^Your sacrifice has been completed!%^RESET%^");
                break;		
        }
    }
    if(!interactive(what)) {
        switch(step) {
        case 0:
            if(present(what,TO)) {
            tell_room(TO,"%^BOLD%^%^BLACK%^A darkness seeps up from the %^RESET%^stone altar%^BOLD%^"+
            "%^BLACK%^ and consumes "+what->query_short()+"%^BOLD%^%^BLACK%^!%^RESET%^");
            what->move(GY_ROOMS+"chapel7");
            tell_room(GY_ROOMS+"chapel7",what->query_short()+"%^BOLD%^%^BLACK%^"+
            " appears on the %^RESET%^stone altar%^BOLD%^%^BLACK%^!%^RESET%^");
            }
            step = 2;
            break;
        }
    }
    if(step < 2) {
        step++;
        call_out("sacrifice_stuff",4,what,step);
    }
}

int sacrifice_action(string str) {
    object ob;
    string what, *ids;
    if(TP->query_bound() || TP->query_unconscious()) {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    if(!str) {
        tell_object(TP,"%^RED%^What do you want to try to sacrifice?  An item?  "+
        "Perhaps yourself?%^RESET%^");
        return 1;
    }
    if(str == "me" || str == (string)TPQN || str == (string)TPQCN || str == "myself") {
        if(!TP->query_invis()) {
            tell_room(TO,TPQCN+"%^BOLD%^%^BLACK%^ lays down on the %^RESET%^stone altar%^BOLD%^"+
            "%^BLACK%^!%^RESET%^",TP);
        }
        tell_object(TP,"%^BOLD%^%^BLACK%^You lay down on the %^RESET%^stone altar%^BOLD%^"+
        "%^BLACK%^!%^RESET%^");
        TP->set_paralyzed(50,"%^RED%^You are sacrificing yourself!%^RESET%^");
        call_out("sacrifice_stuff",4,TP,0);
        return 1;
    }

    if(ob = present(str,TP)) {
        if(ob->query_property("enchantment") < 0 && (
            ob->query_worn() || ob->query_wielded())) {
            tell_object(TP,"%^RED%^You cannot sacrifice something that is magically held to you!"+
            "%^RESET%^");
            return 1;
        }
        ob->move(ETP);
        if(ob->query_short()) {
            what = ob->query_short();
        }
        if(!ob->query_short()) {
            what = ob->query_name();
        }
        if(!TP->query_invis()) {
            tell_room(TO,TPQCN+"%^BOLD%^%^BLACK%^ lays "+what+
            "%^BOLD%^%^BLACK%^ down on the %^RESET%^stone "+
            "altar%^BOLD%^%^BLACK%^!%^RESET%^",TP);
        }
        tell_object(TP,"%^BOLD%^%^BLACK%^You lay "+what+
        "%^BOLD%^%^BLACK%^ down on the %^RESET%^stone "+
        "altar%^BOLD%^%^BLACK%^!%^RESET%^");
        call_out("sacrifice_stuff",4,ob,0);
        return 1;
    }
    tell_object(TP,"%^RED%^You can only sacrifice something that you have in your "+
    "possession!%^RESET%^");
    return 1;

}

void covered() {
    tell_room(TO,"%^BOLD%^%^BLACK%^The curtain falls back into place over the %^BLUE%^open "+
    "doorway%^BOLD%^%^BLACK%^.");
}

int pushcurtain(){
    tell_object(TP,"%^BOLD%^%^BLACK%^You push the curtain out of the way and step through the "+
    "%^BLUE%^open doorway%^BOLD%^%^BLACK%^.%^RESET%^");
    tell_room(TO,TPQCN+"%^BOLD%^%^BLACK%^ pushes the curtain out of the way and steps through "+
    "the %^BLUE%^open doorway%^BOLD%^%^BLACK%^.%^RESET%^",TP);
    return 1;
}