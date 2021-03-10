//updated by Circe with color, expanded desc, etc. 5/30/04
// Wizard's Way, Tabor
// Thorn@ShadowGate
// 010205
// Tabor
// way3.c

#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create() {
	room::create();
	set_terrain(CITY);
	set_travel(DIRT_ROAD);
	set_light(2);
	set_name("Wizard's Way, Tabor");
	set_short("Wizard's Way, Tabor");
	set_long(
@TABOR
%^BOLD%^Wizard's Way, Tabor%^RESET%^
You stand before a tall tower made of %^BOLD%^white marble%^RESET%^.  Strangely, the
tower reminds you of a place you may have seen at some point, or at 
least heard about in your travels.  An active wall of what appears to be
%^YELLOW%^lightning %^RESET%^rings the tower, blocking your passage to the entrance.  
Strangely, there is no apparent way to cross it.  The tower is built 
on a %^ORANGE%^rocky outcropping %^RESET%^that looks to have vertical, 
magically smoothed faces on all sides except facing the road you are on. 

%^CYAN%^Wizard's Way %^RESET%^continues to the north and south.
TABOR
	);
	set_exits(([
		"south" : ROOMDIR+"way2",
		"north" : ROOMDIR+"tgate"
	]));
	set_smell("default","There is a strong scent of ozone that "+
         "makes you think of lightning.");
	set_listen("default","You hear rumbles of thunder.");
	set_items( ([
		({"tower","mage tower","high tower"}):"The tower looms high "+
			"above you, reaching towards the dark clouds that loom "+
			"over it.  The tower is made out of fine white marble "+
			"blocks, and shimmers with ancient energy.",
		({"lightning","wall of lightning","wall","bolts"}) : "The wall "+
			"looks as if "+
			"it could burn you very badly, but you may be able to "+
			"survive getting through it quickly...",
		({"entrance","tower entrance"}):"The entrance is large, but "+
			"not enough so you could see anything in the tower.  "+
			"It's merely a carved gate in the shimmering white "+
			"marble of the tower wall."
	]) );
	set_pre_exit_functions( ({"north"}),	({"GoThroughDoor"}) );
}

void reset(){
  ::reset();
  if(!present("street_light",TO))
    new("/d/common/obj/misc/street_light")->move(TO);
}


void init()
{
    ::init();
    add_action("leaping","jump");
    add_action("leaping","leap");
    add_action("sneak","sneak");
}

void sneak(string str){
	if(!str) return 0;
	if(str != "north" && str != "tower" && str != "wall" && str != "n")
		return 0;
	write("You decide not to try that.");
	return 1;
}

int leaping() {
	if((int)TP->query_hp() < 30) {
		tell_object(TP, "%^RED%^You wouldn't survive the jolt.");
		return 1;
	}
	tell_object(TP, "%^YELLOW%^As you leap through the lightning barrier, you can "
		"feel your skin sizzle and your muscles convulse in exquisite pain."
	);
	TP->move_player("/d/darkwood/tabor/room/tgate.c");
	tell_room(TO,"%^YELLOW%^"+TPQCN+" leaps through the energy, screaming in "
		"pain as the bolts burns "+TP->QP+" flesh!", TP);
	tell_room(ETP, "%^YELLOW%^"+TPQCN+" jumps through the wall of lightning to collapse "
		"on the ground, shivering in pain.", TP);
	TP->set_hp(1+random(20));
	TP->do_damage("torso", 1);
	return 1;
}

int GoThroughDoor() {
    if(!TP->is_class("mage") && !TP->is_class("sorcerer") && !avatarp(TP)) {
        tell_object(TP,"%^ORANGE%^As you through the lightning, you wince "+
            "from a jolt of electricity - a warning you don't belong inside.");
         tell_room(TO,"%^ORANGE%^"+TPQCN+" walks up to the barrier "+
            "and winces "+TP->QS+" receives a small jolt of electricty.",TP);
	TP->do_damage("torso", 5);
        return 1;
    }
    tell_object(TP, "%^CYAN%^You attune your aura to allow the energy to flow "
	"around you and confidently walk through the wall of lightning.");
    if(TP->query_invis()) return 1;
    tell_room(ETP,"%^CYAN%^"+TPQCN+" walks carelessly over to the lightning wall, and "
    	"simply walks through it, the energy seeming to have no effect.", 
    TP);
    return 1;
}
