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
  if(closed == 1)
{
  set_open("out", 0);
  set_locked("out", 1);

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
  set_door("door", "/d/koenig/town/tower1.c", "door", "dungeon key");
  set_open("door", 0);
  set_locked("door", 1);
  set_property("magic hold", 40);
  set_string("door","open","%^RED%^As you open the door you are almost blinded by the light on the other side leading into the tower.\n");
  set_property("no teleport",1);
  set_property("no magic",1);
  set_property("light", 0);
  set_property("indoors", 1);
  set_short("The Tower's Dungeon");
  set_long("%^RESET%^%^ORANGE%^Well adventurer, looks like you picked the wrong way to shove that statue... you'll just have to find a way out of this mess is all. The %^BOLD%^%^BLACK%^dungeon%^RESET%^%^ORANGE%^ is rather large and looks to have been occupied by many at one time. There are %^RESET%^bones%^RESET%^%^ORANGE%^ strung about and in piles, along with %^GREEN%^rags%^RESET%^%^ORANGE%^ of clothing. There are %^BOLD%^%^BLACK%^shackles%^RESET%^%^ORANGE%^ in the walls and some in the %^RESET%^pillars%^RESET%^%^ORANGE%^ that appear to support the roof of this dismal place. Barely noticable is a %^BOLD%^door%^RESET%^%^ORANGE%^ here.\n");
  set_smell("default", "You can smell decay and feces and something else.");
  set_listen("default", "You can hear some stirrings about the dungeon but cant determine their origin.");
  set_exits( ([
     "north" : "/d/koenig/town/dungeon2",
     "door" : "/d/koenig/town/tower1.c",
     "west" : "/d/koenig/town/dungeon4"
]) );
  set_items( ([
     "door" : "The door is made of stonewood and 3 feet thick.",
     "bones" : "They are bleached white, and appear to have been here for a LONG time.",
     "rags" : "They are torn and shredded by rats for their beds.",
     "shackles" : "They are made of steel and seem to have an aura of magic about them. It may be a good idea to stay away from them.",
     "pillars" : "They are tall, smooth, and HUGE, with a few cracks here and there."
]) );
}