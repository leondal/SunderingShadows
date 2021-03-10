#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",-50);
    set_property("indoors",0);
    set_short("");
    set_long("");
     set_listen("default","You hear parts of the ship crack");
}
void init()
{
  ::init();
write("%^BOLD%^BLUE%^Since you are the caption, and captions allways go down with the ship,  You do not try to save yourself.\nYou see water fill the ship, and soon you are under the water./nYou take your last breath, and slip away from life as you know it.\n %^RESET%^");
TP->add_hp(-1000000));
}



