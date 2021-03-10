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
     "floor" : "%^RESET%^You notice that there are other %^BOLD%^footprints%^RESET%^ here other then your own.",
     "footprints" : "The other set of footprints appear to be heading south."
]) );
  set_pre_exit_functions( ({"south"}),({"go_south"}) );
  set_exits( ([
     "down" : "/d/koenig/town/tower16",
     "south" : "/d/koenig/town/tower18.c",
]) );
  set_invis_exits( ({"south"}) );
}

void reset()
{
  ::reset();
if(!present("knight"))new("/d/koenig/town/mon/knight.c")->move(this_object());
}

int go_south() 
{
    if(present("knight")) {
    write("%^RED%^The Dark Knight blocks your path.%^RESET%^");
    say("%^RED%^The Dark Knight blocks "+TPQCN+"'s path.%^RESET%^");
    return 0;
}
    return 1;
}
