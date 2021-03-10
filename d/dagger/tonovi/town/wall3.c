#include "/d/dagger/tonovi/town/short.h"

inherit MAIN;

void create(){
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_room_type("walls");
    set_short("In the walls of Tonovi");
    set_long(
      "%^CYAN%^You are in the passageways that lead through the walls of Tonovi. In some places you can see where the outer walls have been attacked and repaired, but the city itself has withstood great sieges. The walls themselves are made of %^CYAN%^s%^BOLD%^%^BLACK%^tone%^RESET%^%^CYAN%^ with wooden %^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^lanks%^CYAN%^ above your head for the archers to walk on when patrolling the area. To the east are the main %^BOLD%^%^BLACK%^gates%^RESET%^%^CYAN%^ of the town, to the north and southeast are 2 guard towers, and to the west the passage continues."
    );
    set_smell("default", "The smells of old refuse and the stench of the city sit on the dead air.");
    set_listen("default", "You hear the wail of orphaned children as they beg for alms.");

    set_items( ([
	({"stone", "stones"}) : "The stones here range in size and weight, but they all look as if they must have come from a great distance.",
	"planks" : "These wooden planks rest on crossbeams in the walls and allow the guards and archers to patrol the tops of the walls.",
	"gates" : "The great gates stand open ready to be closed in an instant to defend the city.",
	({"tower", "towers"}) : "The two towers here stand ready to repel attackers.  The strangest thing is that one of the towers is actually inside the city walls.",
      ]) );

    set_exits( ([
	"east" : RPATH "maingate",
	"southeast" : RPATH "tower3",
	"north" : RPATH "tower4",
	"west" : RPATH "wall4",
      ]) );

}
