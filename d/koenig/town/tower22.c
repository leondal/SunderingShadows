#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("A Dirty Room");
  set_long("%^BOLD%^%^WHITE%^There is something very odd about this floor of the tower. It appears there "+
"are no other exits but the one through which you entered. You also notice that "+
"the %^RESET%^floor%^BOLD%^%^WHITE%^ is covered in %^RESET%^%^ORANGE%^dirt%^BOLD%^%^WHITE%^ and %^RESET%^%^GREEN%^grime%^BOLD%^%^WHITE%^.%^RESET%^\n");
  set_smell("default", "It smells of dirt and grime... yuck.");
  set_listen("default", "You hear the dirt and grime grind beneath your boots as you walk across the floor.");
  set_items( ([
     "floor" : "You notice another set of footprints other then your own here.",
     "footprints" : "The other set of footprints appear to stop dead, at the foot of some stairs leading up."
]) );
  set_pre_exit_functions( ({"up"}),({"go_up"}) );
  set_exits( ([
     "west" : "/d/koenig/town/tower21",
     "up" : "/d/koenig/town/tower23.c"
]) );
  set_invis_exits( ({"up"}) );
}

void reset()
{
  ::reset();
if(!present("knight"))new("/d/koenig/town/mon/knight.c")->move(this_object());
}

int go_up()
{
    if(present("knight")) {
    write("%^RED%^The Dark Knight blocks your path.%^RESET%^");
    say("%^RED%^The Dark Knight blocks "+TPQCN+"'s path.%^RESET%^");
    return 0;
}
    return 1;
}
