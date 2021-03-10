#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(MARSH);
   set_travel(RUTTED_TRACK);
  set_property("light", 1);
  set_short("The Marsh Path");
  set("day long",
@GIL
%^ORANGE%^This is a path in the Deep, Dark Marsh.
Looking North, West and Southeast the path leads onward.
Here the path splits into 3 directions.
The trail of clawed footprints you were following becomes hard
to see now, you might try searching.
GIL
);
  set("night long",
@GIL
%^CYAN%^This is a path in the Deep, Dark Marsh.
North, West and Southeast of you are long dark paths.
Here the path splits into 3 directions.
The trail of clawed footprints you were following putters out,
you might try searching.
GIL
);
set_smell("default", "%^GREEN%^You can smell the scent of the marsh, it stinks like rotting vegetation.");
set_listen("default", "%^BOLD%^%^BLUE%^You can hear loud frogs chirping and croaking all around.");
  set_items(([
"path" : "It looks wet and muddy and rarely traveled, no human footprints can be seen.",
"marsh" : "It looks deep and evil, monsters probably abound here in droves.",
"trees" : "Many Oaks and Willow trees dot the murky waters all around you.",
"footprints" : "They are definitely NOT human.",
"turtle" : "He must weigh 50 lbs at least, you wouldn't want him to bite you. They say they won't let go till lightning flashes.",
"bullfrog" : "Whoa he's big...must be a lot of insects around.",
]));

  set_exits(([
     "west":"/d/dagger/marsh/swamp/rooms/m_p009_n009",
     "north" : "/d/dagger/marsh/path8",
     "southeast" : "/d/dagger/marsh/path6",
]));
}
void init() {
  ::init();
  add_action("search_for_footprints", "search");
}

int search_for_footprints(string str) {
  tell_object(this_player(),"You search the path for footprints and find that the ones to the west are fresher. \n");
  tell_room(environment(TP),TPQCN+" searches the path for footprints.",TP);
     return 1;
}
