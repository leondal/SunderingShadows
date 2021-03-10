#include <std.h>
inherit ROOM;

void create() {
    ::create();
   set_terrain(SCRUB_LANDS);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("Path to Torm");
    set_long(
  "%^CYAN%^"
  "You are approaching the great Dagger seaport of Torm."
  "  To the southeast you can see the great town on the solid land, with its boardwalk along the ocean leading to the docks."
  "  Many boats are in several stages of movement, from docking to waiting to leaving for the great open waters."
   "  The dark forest lies to the west and you hope you don't have to pass too close to it."
    );
    set_items(([
	"boardwalk" : "It is long and, well, wooden.",
//  "brambles":"Thorny and dangerous looking.  They're blocking the road to Torm and you'll have to wait for the merchant lord of Torm to clear them before you can travel through.",
	"boats" : "They are those things that hold people and float on water.",
      ]));

    set_exits(([
  "west":"/d/dagger/Torm/road/path3",
  "southeast":"/d/dagger/Torm/road/path7",
      ]));

  set_smell("default","A slight breeze brings you the scent of sea air.");
  //set_pre_exit_functions(({"southeast"}),({"brambles"}));
   set_listen("default","The forests are quiet.");
}
int brambles(){
  if(present("guard")){
  write("%^MAGENTA%^Torm guardsman says:%^RESET%^ The path has been overgrown.  You must wait and in time it will be cleared.");
  say("%^MAGENTA%^Torm guardsman says:%^RESET%^ The path has been overgrown.  You must wait and in time it will be cleared.");
  return 0;
  }
  write("The brambles block your path.  You'll have to wait till the merchant lord of Torm clears them.");
  say(""+TPQCN+" tries to pass the brambles but can't get through them.");
  return 0;
}
void reset(){
  object mon;
  ::reset();
  if(!present("guard")){
  new("/d/dagger/Torm/mon/guard1")->move(TO);
  new("/d/dagger/Torm/mon/guard1")->move(TO);
  new("/d/dagger/Torm/mon/guardsl")->move(TO);
 }
}
