#include <std.h>
#include "../../newbie.h"

inherit INH"townmove.c";

void create(){
	::create();
	set_travel(PAVED_ROAD);
	set_terrain(CITY);
	set_light(2);
	set_indoors(1);
	set_name("A Comfortable Lounge");
	set_short("A Comfortable Lounge");
	set_long(
"%^BOLD%^A Comfortable Lounge%^RESET%^\n"+
"Elaborately embroidered tapestries line the cream colored "+
"walls of this small, comfortable lounge.  Narrow divans "+
"covered with plush fabrics in shades of blue, mulberry, and "+
"gray are placed around the room along with ottomans of all "+
"shapes.  It seems this place is a gathering hall for the psions "+
"of the area, and it is often occupied by at least a few people.  "+
"A small bookshelf rests along the western wall, its shelves "+
"filled with books and its top covered with various crystals.\n"
	);
	set_smell("default","A clean scent is in the air here.");
	set_listen("default","The hum of conversation buzzes in the room.");
	set_items( ([
       ({"divan","divans","couches","ottoman","ottomans"}) : "The "+
          "divans look rather comfortable, swathed in soft plush "+
          "fabrics atop cushions.  The wooden portions seem to be "+
          "a dark wood, perhaps mahogany.  The ottomans are made "+
          "in oval and round shapes to mimic the curving lines of "+
          "the divans.",
       ({"tapestry","tapestries"}) : "The tapestries feature various "+
          "scenes of psionic people at work.  A telepath sits before "+
          "a woman, his eyes closed as he communicates the woman's "+
          "message to a distant relative.  Near by, a shaper "+
          "calls forth a massive swarm of crystals, while a seer "+
          "gazes into the depths of a crystal ball.  On the opposite "+
          "wall, a nomad opens up a rift, giving a glimpse into the "+
          "Astral Plane beyond.  A kineticist is depicted disrupting "+
          "the ranks of an army as he opens up a vortex over their "+
          "heads, while finally, an egoist is shown standing perfectly "+
          "still, his body beginning to blend in with his surroundings.",
       ({"bookshelf","bookshelves","shelves","books","crystals"}) : "The "+
          "bound leather tomes on the bookshelf feature names such as "+
          "'Gems of Mystique' and 'Magickal Properties of Crystals'.  "+
          "All of them seem related to alchemy or the physical "+
          "properties of gems, and some of them take it a step "+
          "further, applying this knowledge to the use of "+
          "psionic abilities.  Atop the bookshelves are various "+
          "crystals of the most common varieties used by psions."
    ]) );
    set_exits(([
        "south" : MAINTOWN"psifoyer"
    ]) );
}