#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property(  "light" , 2);
    set_property( "indoors" , 1 );
   set_property("no kill",1);
set_short("Elvanta Alchemist Shop");
    set_long(
@MELNMARN
%^BOLD%^You are standing in the shop of an alchemist.%^RESET%^
You can see vials and test tubes every where.
Type <help shop> for information on how to use the shop.
MELNMARN
);

    set_smell("default","You smell the odor of harsh chemicals");
    set_listen("default","You hear the sounds of bubbling liquids.");

set_property("no attack", 1);
    set_items( ([ "tube": "A tube of colorless bubbling liquid",
      "vial": "A glass vial containing some unknown liquid",
      "tubes": "A row of glass tubes containing colorless bubbling liquids",
      "vials": "A row of glass vials containing some unknown liquid" ]) );
    set_exits( ([
"south" : "/d/dagger/Elvanta/forest/room117"
                ]) );
}

void reset()
{
    ::reset();
if(!present("keman"))
new("/d/dagger/Elvanta/forest/mon/keman")->move(this_object());
}
