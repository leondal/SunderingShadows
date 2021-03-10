#include "/d/dagger/tonovi/town/short.h"

inherit MAIN;

void create(){
    ::create();
   set_terrain(CITY);
   set_travel(FOOT_PATH);
    set_property("light", 2);
   set_short("Path to officers' quarters");
    set_room_type("street");
    set_long(
   "This is a small but well kept path that leads from the streets of tonovi to the large barracks that serve as the officers' quarters for the army of Tonovi.  The door to the inside of the barracks here lies open, guarded by two rookie guards."
    );
    set_smell("default", "There is not much to smell here.");
    set_listen("default", "You can barely hear some conversation in the distance.");
    set_items( ([
	"path" : "This path is well worn and well kept.  It looks to be travelled quite often.",
      ]) );
    set_exits( ([
	"southwest" : RPATH "street4",
	"north" : RPATH "officer2",
      ]) );
}

void reset() {
   ::reset();
   if(!random(3)) {
     if(sizeof(children("/d/dagger/tonovi/mon/guardcapt")) < 2)
        new("/d/dagger/tonovi/mon/guardcapt")->move(TO);
   }
}