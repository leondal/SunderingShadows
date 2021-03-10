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
The passageway here stops abruptly at a huge gaping chasm.  The
way to the north is only accessible by a small bridge on which the
railing for the mine cars runs.  You could never step across that
bridge on foot.  You must find another way.
KAYLA
    );
    set_exits(([
       "southeast" : "minew2"
    ] ));
    set_items(([
       "railway" : "The railing is sturdy but thin; you could never walk across it.",
       "chasm" : "A huge gorge in the middle of the mine.  You can hear various sounds coming from the bottom, though."
    ] ));
}
