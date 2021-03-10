#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",-1);
    set_property("indoors",1);
    set_short("Passage End");
    set_long(
@KAYLA
This is where the large passage way in the mine ends.  The railing
continues to the north, but the rails are too thin for you to simply
walk on, and the railway is elevated over a 100 foot tall chasm. 
You cannot even see the bottom.  Perhaps you should find another
way to get across.
KAYLA
    );
    set_exits(([
       "southwest" : "minee2"
    ] ));
    set_items(([
       "railway" : "The railing is sturdy but thin; you could never walk across it.",
       "chasm" : "A huge gorge in the middle of the mine.  You can hear various sounds coming from the bottom, though."
    ] ));
}
