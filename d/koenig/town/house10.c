#include <std.h>
inherit VAULT;

void create() {
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("no sticks", 1);
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("A Bedroom");
  set_long("%^RESET%^%^CYAN%^Upon entering this room you get the impression "
    "that each of the sisters is as different as night is to day from one "
    "another. This room is %^MAGENTA%^lavishly%^RESET%^%^CYAN%^ decorated and surprisingly normal "
    "looking (almost makes you wonder what is hidden beneath the surface). "
    "There is a large %^ORANGE%^bed%^RESET%^%^CYAN%^ that hangs suspended from the ceiling in the middle "
    "of the room, a %^ORANGE%^dresser %^RESET%^%^CYAN%^along the far wall, and a %^ORANGE%^closet%^RESET%^%^CYAN%^.");
  set_smell("default", "The smell of incense is very strong here.\n");
  set_listen("default", "You can hear chanting but are not yet sure of its origin.");
  set_listen("chanting", "You can hear the chanting more clearly in here... it is coming from the closet!");
  set_items( ([
     "bed" : "The bed is suspended from the ceiling by thick chains and is swinging gently as if there were a gentle breeze in here.",
     "dresser" : "The dresser is large and intricately carved. On its surface are the sorts of things you would expect to find, including a jewelry box.",
     "closet" : "The closet door is intricately carved, matching the carvings on the dresser. Oddly, it seems that the chanting might be coming from within."
]) );
  set_exits( ([
     "east" : "/d/koenig/town/house8",
     "closet" : "/d/koenig/town/closet"
]) );
  set_pre_exit_functions( ({"closet"}),({"go_closet"}) );
  set_door("closet door", "/d/koenig/town/closet", "closet");
  set_open("closet door", 0);
  "/d/koenig/town/closet"->set_open("door", 0);
  set_invis_exits( ({"closet"}) );
}

int go_closet() {
   tell_room(ETP,"%^CYAN%^"+TPQCN+" disappears into the closet.",TP);
return 1;
}

void reset() {
  ::reset();
  if(!present("jewelry box"))
  new("/d/koenig/town/items/jewelbx2.c")->move(this_object());
  if(!present("mirror"))
  new("/d/koenig/town/items/mirror.c")->move(this_object());
}
