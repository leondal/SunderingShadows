#include <std.h>
inherit VAULT;

int blocked;
  int sealed;
  int closed;

void init()
{
  ::init();
  closed = query_open("out");
  sealed = query_locked("out");
  if(closed ==1)
{
  set_open("out",0);
  set_locked("out",1);
  "/d/koenig/town/tower1"->set_open("door",0);
  "/d/koenig/town/tower1"->set_locked("door",1);
  return 1;
  }
}
void create()
{
  ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("no teleport", 1);
  set_property("magic hold", 1);
  set_property("light", 1);
  set_property("indoors", 1);
  set_door("door", "/d/koenig/town/dungeon1", "door", "dungeon key");
  set_open("door", 1);
  set_locked("door", 0);
  set_string("door", "open", "%^BOLD%^%^WHITE%^You open the door and are blasted in the face with the smell of stale air and decay.%^RESET%^");
  set_short("Standing before a Door");
  set_long("%^BOLD%^%^WHITE%^Good choice, you slid the statue in the right direction! "
           "You are near the %^RESET%^%^ORANGE%^door%^BOLD%^%^WHITE%^ to the dungeon. It is well lit here and you "
           "notice that you can only go north, or through the door. Alas - you "
       "may not go back the way you came, but by now you should have expected "
           "this huh? I wish you luck, adventurer, for you have entered the "
           "most %^BOLD%^%^BLACK%^dangerous%^BOLD%^%^WHITE%^ place of all in Muileann.%^RESET%^\n");
  set_smell("default", "You can smell horrible things on the air from behind the door.");
  set_listen("default", "You can hear something or somethings stirring about beyond the door.");
  set_exits( ([
     "door" : "/d/koenig/town/dungeon1.c",
     "north" : "/d/koenig/town/tower2"
]) );
}
