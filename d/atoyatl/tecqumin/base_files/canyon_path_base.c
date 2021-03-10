#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit ROOM;

string side;
string long_desc();
string sound_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 0);
  set_terrain(HILLS);
  set_travel(FOOT_PATH);
  set_name("Footpath in the side of a canyon");
  set_short("You are on a narrow footpath, winding its way up the side of"
    +" a river canyon wall.");
  set_long( "The path is cut into the side of the canyon wall. It is narrow"
    +" and uneven, and you are aware of the precipitous drop off to one"
    +" side." );
  set_items( ([({"wall", "canyon wall"}) : "The canyon wall is close on one"
    +" side, and prevents you getting too far away from the edge.",
      ({"river", "fast river", "fast flowing river", "water"}) : "The"
                    +" %^BOLD%^%^BLUE%^river%^RESET%^ is wide, deep and fast"
                    +" flowing at this point, practically impossible to cross.",
      ({"path", "small path"}) : "The path is narrow and uneven, and you are"
                    +" aware of the risks of a stumble or fall. "
    ]) );
  set_smell( "default", "The rush of %^BOLD%^%^CYAN%^w%^BLUE%^a%^CYAN%^ter"
    +"%^RESET%^%^ORANGE%^ and %^BOLD%^%^WHITE%^spray %^RESET%^%^ORANGE%^fills"
    +" your nostrils" );
  set_listen("default",(:TO, "sound_desc":));
}


string sound_desc(){
  object room;
  string desc;
  room = find_object_or_load(JUNG_ROOM + "canyon_riverbank");
  if (objectp(room) && present("unfettered", room)){
    desc = "A %^BOLD%^%^CYAN%^high pitched %^YELLOW%^keening"
      +" %^CYAN%^noise%^RESET%^%^GREEN%^ assaults your ears";
  } else {
    desc = "You can hear the sound of fast flowing %^BOLD%^%^CYAN%^w%^BLUE%^"
      +"a%^CYAN%^ter";
  }
  return desc;
}
