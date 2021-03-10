#include <std.h>
inherit ROOM;

void create()
{
  ::create();
  set_property("light", 2);
  set_short("The Treetop.");
  set("day long",
@GIL
%^GREEN%^You are the top of a huge oak tree that grows beside
the Dagger Sea coast road. The view is incredible.
Theres a sign here tacked to the trunk.
You can only go down.
GIL
);
  set("night long",
@GIL
%^CYAN%^You are at the top of a huge oak tree that grows beside
the Dagger Sea coast road. The sky above you is alight with bright stars.
You can't see far in the dark.
You can only go down.
GIL
);
set_smell("default", "%^BOLD%^%^GREEN%^You can smell the fresh smell of oak leaves.");
set_listen("default", "You can hear the wind in the leaves.");
  set_items(([
"leaves" : "The leaves are dark green and full of life.",
"tree" : "This huge oak grows beside the road.",
"sign" : "Lookout Oak: Look in any direction. (i.e. look north)"
]));

  set_exits(([
     "down" : "/d/dagger/westroad/tree1",
     ]));
}

void init()
{
::init();
add_action("look_north","look");
add_action("look_south","look");
add_action("look_east","look");
add_action("look_west","look");

}

int look_north(string str)
{

if ((str=="north") || (str=="n"))
{
write("%^BOLD%^%^BLUE%^As you peer North you see the road following the coastline Northeast.
Along the road north you can see a beach, marsh and forest.
Far to the Northeast you can see the spires of Castle Torm.");
return 1;
}
return 0;

}
int look_south(string str)
{

if ((str=="south") || (str=="s"))
{
write("%^BOLD%^%^BLUE%^Peering south you see the road following the coastline Southwest.
Along the road you see the cliffs and forest.
Far too the Southwest you can see Muileann's tower.");
return 1;
}
return 0;
}

int look_east(string str)
{

if ((str=="east") || (str=="e"))
{
write("%^BOLD%^%^BLUE%^Peering to the East you can see out over the blue waters of the Dagger Sea.
You catch a fleeting glimpce of a tiny white sail far out in the haze.");
return 1;
}
return 0;
}

int look_west(string str)
{

if ((str=="west") || (str=="w"))
{
write("%^BOLD%^%^BLUE%^Staring West you can see the miles of deep forest stretching all
the way to the Tormal mountain range.
Even from here the size of the range is enormous and takes away your breath.");
return 1;
}
return 0;
}

