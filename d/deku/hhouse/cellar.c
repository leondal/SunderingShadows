#include <std.h>
#include "/d/deku/inherits/deku.h"
#define H1 "/d/deku/hhouse/hideout1.c"
inherit ROOM;

int open;


void query_open_state() {
    return open;
}

void remote_opened(int x) {
    if(x == 1) {
        open = x;
        tell_room(TO,"%^RED%^A section of the south walls slides to "+
        "the side!%^RESET%^");
        TO->add_exit(BH_ROOMS+"hideout1","south");
    }
    if(x == 0) {
        open = x;
        tell_room(TO,"%^RED%^A section of wood slides into place "+
        "over the south doorway!%^RESET%^");
        TO->remove_exit("south");
    }
}

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_short("Haunted House");
    set_long( (:TO, "long_desc" :) );
    set_smell("default","There is a strong vile odor coming from this abandoned cellar.");
    set_listen("default","An eerie silence penetrates the air here.");
    set_exits(([
       "up" : HH_ROOMS+"scullery"
    ] ));
    set_items(([
       "racks" : "%^ORANGE%^These are wooden bottle racks.  They appear to "
          "hold only broken bottles but sometimes looks are deceiving.",
       "bottles" : "They appear to be worthless but you see fingerprints in "
          "the dust on some of them in the racks."
    ] ));
    open = 0;
}

void init() {
  ::init();
  add_action("search","search");
  add_action("retrieve","retrieve");
}

int search(string str) {
  if(!str) {
    write("Search what?");
    return 1;
  }
  if(present("bandit")) {
    write("Not with someone watching it!");
    return 1;
  }
  if(str != "racks" && str != "bottle racks" && str != "bottles" ) {
    write("You search and find nothing there!");
    return 1;
  }
  write("You search the racks and find that there is one bottle within");
  write("that looks out of place.  Maybe if you could retrieve the bottle");
  write("you'll find something worthwhile.");
  say(TPQCN+" searches the racks and seems to notice something.");
  return 1;
}

int retrieve(string str) {
  if(!str) {
    write("Retrieve what?");
    return 1;
  }
  if(present("bandit")) {
    write("Not with someone watching it!");
    return 1;
  }
  if(str != "bottle from racks") {
    write("Maybe you should try to retrieve item from place.");
    return 1;
  }
  if (open) {
    write("The bottle has already been removed and the door has been revealed.");
    return 1;
  }
  open = 1;
  write("You retrieve the bottle from the racks and suddenly a section of the "+
  "south wall slides to the side!%^RESET%^");
  say(TPQCN+" removes a bottle from the wooden racks and a secret door opens on the south wall.");
  TO->add_exit(BH_ROOMS+"hideout1","south");
  if((int)H1->query_open_state() == 0) {
        H1->remote_opened(1);
  }
  return 1;
}

void reset() {
  ::reset();
  if(!random(2) && !present("bandit")) new("/d/deku/monster/bandit")->move(TO);
  if(member_array("south",query_exits()) != -1) {
    remote_opened(0);
  }
  if((int)H1->query_open_state() == 1) {
    H1->remote_opened(0);
  }
}

string long_desc(string str) {
  if(!open) {
    return( "This was obviously a wine cellar.  %^ORANGE%^Wooden bottle "
     "racks%^RESET%^ line the north and west walls to a height of 6 ft.  There "
     "appear to be no intact bottles left in the racks though there are several "
     "with broken necks.  Broken bottles cover the floor beneath and near the "
     "racks.  Against the east wall, at the foot of the stairs, are two large "
     "metal storage bins which are empty.");
  }
  return("This was obviously a wine cellar.  %^ORANGE%^Wooden bottle "
    "racks%^RESET%^ line the north and west walls to a height of 6 ft.  There "
    "appear to be no intact bottles left in the racks though there are several "
    "with broken necks.  Broken bottles cover the floor beneath and near the "
    "racks.  Against the east wall, at the foot of the stairs, are two large "
    "metal storage bins which are empty.\n%^BOLD%^%^RED%^There is secret door "
    "opened in the south wall.");
}

