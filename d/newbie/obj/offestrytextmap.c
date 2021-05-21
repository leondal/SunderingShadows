//Titania 1/20/2020
// Text Only map of Offestry

#include <std.h>

inherit OBJECT;

void init(){
  ::init();
  add_action("read_map","read");
}

void create() {
  ::create();
  set_id( ({"map", "offestry map", "text map" }) );
  set_name("map");
  set_short("A map of Offestry");
  set_long("This is a descriptive map of the city of Offestry, written on high quality
parchment "+
     "that has been weather-proofed so it will not run. All of the "+
     "major locations of the city are on here. You should read it.\\Note: The Offestry square has an ascii map which might override the text-only version in your inventory. Please type <read my map> to access the one in your inventory.");
  set_weight(0);
  set_value(0);
}

int read_map(string str){
  if(!str) notify_fail("Read what?");
  if (present(str, ETO) != TO) {
            return 0;
  }
  TP->more("/d/newbie/obj/offestry_text_map");
  return 1;
}