#include <std.h>

#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create() {
    ::create();
    set_property(  "light" , 2);
    set_property( "indoors" , 1 );
   set_property("no kill",1);
set_short("D'farans Alchemist Shop");
set_long("%^YELLOW%^D'faran waits amid vials, potions and test tubes.  The counter he stands behind is scarred with age and experiments gone wrong.  In one darkened corner of the room you can see tubes, glass bottles and a greenish blue liquid bubbling.  While D'faran looks friendly enough, he also looks a little dazed and is mumbling to himself.  Should you require assistance, <help shop> will help you.");

    set_smell("default","You smell the odor of harsh chemicals");
    set_listen("default","You hear the sounds of bubbling liquids.");

set_property("no attack", 1);
    set_items( ([ "tube": "A tube of colorless bubbling liquid",
      "vial": "A glass vial containing some unknown liquid",
      "tubes": "A row of glass tubes containing colorless bubbling liquids",
      "vials": "A row of glass vials containing some unknown liquid" ]) );
    set_exits( ([
"out" : PROOM+"room55.c"
                ]) );
}

void reset()
{
    ::reset();
if(!present("d'faran"))
new("/d/ptalkin/mon/d'faran")->move(TO);
}
