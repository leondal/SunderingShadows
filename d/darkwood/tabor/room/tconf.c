//updated by Circe 5/31/04 to be more of an amphitheater with color, etc.
#include <std.h>

inherit ROOM;

void create()
{
    ::create();
    set_travel(PAVED_ROAD);
    set_terrain(CITY);
    set_name("Assembly Hall of the Magi, Tower of the Arcane, Tabor");
    set_short("Assembly Hall of the Magi, Tower of the Arcane, Tabor");
    set_long(
"%^BOLD%^Great Assembly Hall of the Magi in the Tower of the "+
"%^CYAN%^A%^YELLOW%^r%^CYAN%^c%^YELLOW%^a%^CYAN%^n%^YELLOW%^e"+
"%^WHITE%^, Tabor%^RESET%^\n"+
"%^CYAN%^This is an enormous %^BOLD%^%^BLUE%^amphitheater "+
"%^RESET%^%^CYAN%^that takes up this entire level of the tower, "+
"save for the %^BOLD%^%^BLACK%^stairwell %^RESET%^%^CYAN%^leading "+
"to the other levels.  The center of "+
"the room is a %^RESET%^%^ORANGE%^raised dais%^CYAN%^, "+
"upon which stand five %^MAGENTA%^padded mahogany chairs %^CYAN%^"+
"arranged around a %^RESET%^%^ORANGE%^podium%^CYAN%^"+
".  The %^RESET%^%^ORANGE%^podium%^CYAN%^ faces "+
"away from the doorway, and looks upon the rows and rows of "+
"%^RESET%^%^ORANGE%^benches %^CYAN%^rising up toward the "+
"ceiling.  It looks as though the majority of all the %^BOLD%^magi "+
"%^RESET%^%^CYAN%^of the realms could fit into this room at once.  "+
"Adding to the cavernous size is a raised ceiling which reaches "+
"high overhead, a feature which somehow seems to magnify the "+
"speaker's voice.  At many times, you may find this amphitheather "+
"filled with %^BOLD%^magi %^RESET%^%^CYAN%^eagerly discussing the merits "+
"of some new-found spell or detailing uses for an older one.\n"
    );
    set_property("light",2);
    set_property("indoors",1);
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
    set_exits( ([
        "south":"/d/darkwood/tabor/room/tfloor3"
    ]) );
    set_items(([
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
    ]));
    set_smell("default","You smell the charred remains of magical "+
        "demonstrations scattered over the floor.");
    set_listen("default","Any noise in the room appears to be "+
                         "strangely amplified.");
}
