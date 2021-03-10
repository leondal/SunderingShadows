/*changed by Circe 10/21/03.  Per a bug report, the sewer grate looks like it should be openable, but isn't.  I'm not sure why the sewers are closed, but I changed the grate for now.  We can always change it back if/when the sewers open. */
#include <std.h>
inherit ROOM;

void create(){
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
set_property("light", 2);
  set_short("A Street in Daggerdale.");
  set("day long",
@GIL
%^ORANGE%^You are on East Justice Avenue.
The street runs East and West from here.
A metal pole holds an unlit lantern aloft here.
The backside of a building lies to the South of the street.
The high city wall lies to the North of the street.
A metal grate is in the middle of the street here.
GIL
);
  set("night long",
@GIL
%^YELLOW%^You are on East Justice Avenue.
The street runs East and West from here.
A metal pole here holds a lit lantern aloft and brightens the night.
The backside of a building lies to the South.
The high city wall lies to the North of the street.
A metal grate is in the middle of the street here.
GIL
);
set_smell("default", "You catch the scent of garbage.");
set_listen("default", "You can hear the sounds of villagers.");
  set_items(([
"pole" : "It's made of steel and holds a lantern to light the darkness",
"street" : "It's made of clean polished cobblestones.",
"lantern" : "It's a large oil lantern with crystal glass windows.",
"building" : "It's made of perfectly carved granite blocks, it's Dwarven stone work.",
"wall" : "It's 50 foot tall and made from huge polished granite blocks.",
"grate" : "The metal grate is sturdy and strong.  From below, you can see and smell "+
   "the reeking sewage of the city."
/*
"grate" : "It's a metal sewer grate, the rainwater goes down here and you can be sure that nasty, filthy, things live down there. It looks broken, perhaps you can open it?",
Changed the description of the grate since the sewers are no longer open.  Circe 10/21/03
*/
]));

  set_exits(([
"west" : "/d/dagger/Daggerdale/streets/street40",
"east" : "/d/dagger/Daggerdale/streets/street42",
     ]));
}
void reset(){
::reset();
  if(query_exit("down")) {remove_exit("down");}
if(!present("lantern pole")){
new("/d/dagger/Daggerdale/streets/items/objs/lantern_pole.c")->move(TO);
}
}
/*
void init() {
  :: init();
add_action("open","open"); }

int open(string str){
if (str == "grate") {
tell_object(this_player(),"%^BOLD%^You pull on the grate and it slowly creaks open.");
say ("%^BOLD%^"+this_player()->query_cap_name()+" opens a sewer grate in the middle of the street.");
add_exit("/d/dagger/Daggerdale/sewers/level1/sewer2", "down");
}
return 1;
}
*/
