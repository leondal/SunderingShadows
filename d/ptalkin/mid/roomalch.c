//rooms by the House of Svaha
#include <std.h>

#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create() {
    ::create();
    set_property(  "light" , 2);
    set_property( "indoors" , 1 );
   set_property("no kill",1);
set_short("%^RED%^F'leens Alchemist Shop");
set_long("%^RED%^F'leens Alchemist Shop is a place of wonder and awe.  You
wonder how he can find anything in the mess and smoke and you stand in awe
of the sylvan elfs appearance.  There is a sign bolted to the wall, scarred
by explosions, fumes and the gods know what else thats says :

To those who don't want their spells to flop
Please utter the magic words <help shop>");
    set_smell("default","You smell the odor of harsh chemicals");
    set_listen("default","You hear the sounds of bubbling liquids.");

set_property("no attack", 1);
    set_items( ([ "tube": "A tube of colorless bubbling liquid",
      "vial": "A glass vial containing some unknown liquid",
      "tubes": "A row of glass tubes containing colorless bubbling liquids",
      "vials": "A row of glass vials containing some unknown liquid" ]) );
    set_exits( ([
"out" : PMID+"room78.c"
                ]) );
}

void reset()
{
    ::reset();
if(!present("f'leen"))
new("/d/ptalkin/mon/f'leen")->move(TO);
}
