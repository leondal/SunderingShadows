#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",-1);
    set_property("indoors",1);
    set_short("Sanctuary Sewers");
    set_long("%^RED%^%^BOLD%^
These are the disgusting sewers under the city of Sanctuary.  They are
filled with many strange but interesting objects.  The tunnel bends
here, continuing to the south, and back toward the east.  The walls
are dark and covered with human and demihuman waste from the many
decades of sewage that flowed within these dark tunnels.
    ");
    set_exits(([
       "east" : "/d/dragon/sewer/sewer22",
       "south" : "/d/dragon/sewer/sewer24"
    ] ));
    set_items(([
       "sewers":"The disgusting tunnels of waste under Sanctuary."
    ] ));
    set_smell("default","The smell of human and demi-human waste is becoming overwhelming.");
}
