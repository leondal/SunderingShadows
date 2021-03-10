#include <std.h>

inherit ROOM;


void create(){
      object ob;
      string where;
      ::create();
	set_property("light",3);
	set_property("indoors",0);
	set_terrain(ROCKY);
	set_travel(FRESH_BLAZE);
       set_short("%^RED%^The rugged terrain of %^WHITE%^A%^BOLD%^%^RED%^r%^BLACK%^a%^WHITE%^m%^RED%^a%^RESET%^n%^RED%^t%^BOLD%^h %^RESET%^%^RED%^I%^BOLD%^s%^WHITE%^l%^BLACK%^a%^RESET%^n%^BOLD%^%^BLACK%^d%^RESET%^.");
        set_long("%^RED%^The rugged terrain of %^WHITE%^A%^BOLD%^%^RED%^r%^BLACK%^a%^WHITE%^m%^RED%^a%^RESET%^n%^RED%^t%^BOLD%^h %^RESET%^%^RED%^I%^BOLD%^s%^WHITE%^l%^BLACK%^a%^RESET%^n%^BOLD%^%^BLACK%^d%^RESET%^.
%^ORANGE%^You stand at the base of an enormous cliff. A %^RED%^ladder%^ORANGE%^ has been lowered over the side and seems to be the only way up to a large plateau that is nearly as high as this entire island is wide. %^ORANGE%^The beach continues to the west and forms a point in the distance. Coarse sand at your feet is mixed with gravel-like fragments and large stones alike. %^BLUE%^The ocean meets the land to the south and northwest.
");
   set_listen("default", "Waves break against the rocky beach with a crash.");
       set_exits(([
   "north" : "/d/shadow/virtual/sea/aramanth.dock",
   "up" : "/d/islands/common/aramanth/room5",
       "west" : "/d/islands/common/aramanth/room2",
]));
       set_items(([
    "formations" : "Jagged formations of natural rock tower all around you.",
    "netting" : "It is heavily rusted and was probably a heavy duty cargo net of some kind.",
    "rocks" : "The rocks here are very jagged.",
    "formation" : "It looks almost perfectly like a sobbing boy if you look at it from just the right angle.",
    "shale" : "Tiny sharp rock fragments and dust cover the ground.",
    "ground" : "Tiny sharp rock fragments and dust cover the ground."
]));
   ob = new("/d/islands/common/mon/uwarrior_sp");
   where = find_object_or_load("/d/islands/common/aramanth/room"+(random(30)+5));
   ob->move(where);
}
void init() {
  ::init();
  do_random_encounters(({"/d/islands/common/mon/rwyvern.c", "/d/islands/common/mon/skeleton.c", "/d/islands/common/mon/uwarrior.c", "/d/islands/common/mon/spiritdancer.c", "/d/islands/common/mon/crab.c"}),30,3);
}
