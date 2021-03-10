#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    object ob;
 
    room::create();
    set_properties( ([ "light": 2, "indoors": 1 ]) );
    set_short("Entryway to the mines");
    set_long(
@ZEEK
You are standing in front of a large entrance to a fairly well lit
mine.  This mine has been the source of income for the city of Shadowgate
for several centuries, thus is very well kept up and also well guarded.
The ground here is significantly more rocky than to the south, but
strangely, there is no mountain ahead of you.
ZEEK
    );
    set_exits(([
                "south" : "roadoutoftown",
                "north" : "mine1"
    ]) );
set_items( ([
      "mine" :
@ZEEK
The mine is a large operation, taking many of the residents of Shadowgate
as employees to work in the mines.  However, the sheer magnitude of
the cash the mine produces tends to influence you into thinking that there
are more workers here than you may think.
ZEEK
]) );
}
