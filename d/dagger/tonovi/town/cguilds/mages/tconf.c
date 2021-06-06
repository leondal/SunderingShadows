#include <std.h>

inherit ROOM;

void create()
{
    ::create();
    set_travel(PAVED_ROAD);
    set_terrain(CITY);
    set_name("Assembly Hall, Marble Academy, Tonovi");
    set_short("Assembly Hall, Marble Academy, Tonovi");
    set_long("Generic description for the Assembly Hall, Marble Academy, Tonovi.");
    set_property("light",2);
    set_property("indoors",1);
    set_exits( ([
        "south":"tfloor3"
    ]) );
    set_items(([
/*
       ({"stage","dais"}) : "%^ORANGE%^A wooden dais forms the "+
          "center of the room.  It is rather wide but seems dwarfed "+
          "by the rows of seating rising up around it.  From the dais, "+
          "the speaking magi would command the attention of every "+
          "mage present, and indeed, it is considered rude to speak "+
          "while someone holds the floor.",
       ({"bench","benches","seating","rows"}) : "Rising rows of "+
          "benches provide seating for magi attending a conference "+
          "here.  They are plain pine benches, but are highly "+
          "polished and actually seem rather soft.",
       ({"chair","chairs","padded chairs"}) : "The mahogany chairs "+
          "on the dais have been fitted with %^MAGENTA%^wine padding "+
          "%^RESET%^to allow the distinguished magi speaking a "+
          "comfortable place to sit.",
       ({"podium","wooden podium"}) : "The podium is made of pine and "+
          "features several small shelves inside along with an inclined "+
          "top fitted with a raised lip to allow the speaker to rest "+
          "his notes or spellbook as he speaks, referring to it as "+
          "need be.",
       ({"door","doorway"}) : "The area to the south is the only "+
          "part of the room not dominated by benches.  An arched "+
          "doorway leads to the stairway, and from here the "+
          "attending magi may climb up to their seats."
*/
    ]));
    
    set_smell("default","You smell the charred remains of magical "+
        "demonstrations scattered over the floor.");
    set_listen("default","Any noise in the room appears to be "+
                         "strangely amplified.");
}
