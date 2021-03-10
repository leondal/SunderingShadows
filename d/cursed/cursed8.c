#include <std.h>

inherit ROOM;

void create()
{
        ::create();
                set_property("outdoors",1);
                set_property("light",1);
                set_short("Southern most part of Cursed Lands.");
                set_long(

@STOP
You are at the southern most part of the Cursed Lands.
It is extremly eerie here.  The entire area looks inhabitable,
but yet you have this strange fealing as though you are
being watched.  You don't notice any forms of life around you.
Towards the southwest, you barely take notice of a %^GREEN%^fortress
%^RESET%^of some type.  You can sense the presence of evil transpiring
from it.


STOP
);
       set_smell("default","You smell the stinch of %^RED%^%^BOLD%^DEATH!%^RESET%^");
       set_listen("default","You hear whimpering cries for help all around you.");
       set_exits((["east":"/d/cursed/cursed7.c",
                   "southwest":"/d/cursed/cursed9.c"]));
                  
}

