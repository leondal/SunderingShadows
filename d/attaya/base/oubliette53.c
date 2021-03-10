inherit "/std/room";

#include <std.h>
void create() {
     ::create();
     set_light(2);
     set_indoors(1);
     set_travel(DIRT_ROAD);
     set_terrain(STONE_BUILDING);
     set_short("Escape from the oubliette");
     set_long("
    %^BLUE%^
    This is the portal that can carry you from the horrible oubliette!
    The stone walls and ceiling seem to drop away into a black void that warps inward to form a portal out of thin air!
%^BOLD%^%^BLUE%^A Mysterious Portal is here.
");
     set_items(([
      "walls" : "The walls are made from fitted stone bricks that fade into a portal before you!",
     "portal" : "It crackles with energy and forme from the nothingness behind the walls and ceiling!",
]));
    set_listen("default" ,"The portal snaps and crackles with energy and makes a roar like the ocean as it pours like a vortex into a bright blue core!");
}
void init() {
  ::init();
  add_action("enter", "enter");
}

int enter(string str) {
  write("%^CYAN%^You enter the mysterious portal.\n");
  say((string)this_player()->query_cap_name()+" enters the mysterious portal.\n");
  this_player()->move_player("/d/attaya/cliff45");
  return 1;
}
