#include <std.h>
#include <objects.h>
      
inherit ROOM;
      
void create() {
  room::create();
  set_light(2);
  set_indoors(1);
  set_short("Sanctuary's magical store");
  set_long("%^BLUE%^%^BOLD%^
This is an old run down magic store.  The valuable components of the
mage's spells are sold here.  Along the walls are strange and some-
times wonderful items whose purposes are only understood by mages
and occasionally bards.  This store feels no need to garnish in the
fashions of the other stores, but could use a good restoring.
    ");
  set_smell("default","The room is filled with mingled smells of various herbs and
concotions.");
    set_exits((["north":"/d/dragon/town/roadW3",
                "west":"/d/dragon/town/roadSW1"]));
      set_items(([
"shelves":"These shelves are stacked with the components so vital to the mage."
        ] ));
  }
void reset(){
  ::reset();
  if(!present("vaxalt")) {
    new("/d/dragon/mon/vaxalt")->move(this_object());
  }
}
