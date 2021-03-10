#include <std.h>
inherit "/d/deku/plains/road11i";

void create(){
    ::create();
    set_long("%^BOLD%^Forest Road%^RESET%^
Two immense oak doors stand wide open, allowing all to enter the
city of %^RED%^%^BOLD%^Sanctuary%^RESET%^.  High above you looms an iron portcullis,
covered with layers of rust.  The city is surrounded by a high 
gray wall.  The guard tower is located to the east.
    ");
    set_exits(([
        "enter" : "/d/deku/sanctuary/town/roadS3",
        "east" : "/d/deku/sanctuary/town/ghouse1",
        "south" : "/d/deku/plains/road34"
   	]));
}
