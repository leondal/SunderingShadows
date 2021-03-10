#include <std.h>
#include "/d/guilds/pack/short.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set_property("no teleport", 1);
    set_property("no steal", 1);
    set_short("%^BOLD%^%^BLUE%^Guild Donation");
    set_long(
@SEETH
%^BOLD%^%^CYAN%^You have entered the Donation room of The Illuminati
%^RESET%^%^CYAN%^The room is just wide enough to contain this 10 foot wide chest perfectly. The room is big enough to have a few people in at the same time to donate items or take out items that they need.
SEETH
    );
    set_items( ([

      ]) );
    set_exits( ([
      "west" : HALL "ghall.c",
      ]) );

    set_smell("default", "The smell of the cast iron chest fills your nose.");
    set_listen("default", "You hear the sounds of shuffling of objects.");

}
void reset(){
 ::reset();
if(!present("chest"))
new(OBJ "chest.c")->move(this_object());
}

void clean_up(){return 1;}
