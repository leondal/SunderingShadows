#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_short("Graveyard of Sanctuary");
    set_long("%^BOLD%^%^RED%^
You are within the city's graveyard.  Old tombstones are strewn about in 
a haphazard fashion.  Most were placed here ages ago, and only a few still
now have writing or dates that can be made out.  It seems unusually dark
and gloomly here, because of the overwhelming shadow of the church.  To
the south you see the back entrance to the Temple of Alphonsus, and to
the east is a large iron fence dividing the graveyard from the city.");
    set_exits(([
       "south" : "/d/dragon/town/church"
    ] ));
    set_items(([
    ] ));
    new("/d/dragon/obj/misc/tstone1")->move(this_object());
}
