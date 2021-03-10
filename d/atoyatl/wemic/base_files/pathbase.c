#include <std.h>
#include <move.h>
#include "../wemic.h"

inherit ROOM;

string long_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_terrain(JUNGLE);
  set_travel(FOOT_PATH);
  set_name("village footpath");
  set_short("village footpath");
  set_long( (:TO, "long_desc":) );
  set("night long",(:TO, "night_desc":));

  set_items(([  ]));
  set_smell("default","The smells of the jungle reach you. There's also a"
                     +" faint but nonetheless unmistakable scent of damp"
                     +" lion fur.");
  set_listen("default","The sounds of the jungle can still be heard above"
                      +" the quiet murmurings of the village.");
}
void init() {
   ::init();
}

string long_desc(){
return "A simple dirt path leads through the %^ORANGE%^Wemic%^RESET%^"
      +" village, winding its way between %^ORANGE%^hide covered tents"
      +"%^RESET%^ and %^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^ea%^BOLD%^"
      +"%^GREEN%^fy trees%^RESET%^. A few of the villagers are about.";
}

string night_desc(){
  return "%^BLUE%^A simple %^RESET%^dirt path%^BLUE%^ leads through the"
        +" %^ORANGE%^Wemic%^BLUE%^ village, winding its way between"
        +" %^ORANGE%^hide covered tents%^BLUE%^ and"
        +" %^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^ea%^BOLD%^%^GREEN%^fy trees"
        +"%^RESET%^%^BLUE%^. There are few people about, other than the"
        +" occasional hunter on the way to or from a nighttime foray.";
}

