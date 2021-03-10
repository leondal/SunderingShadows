#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_MAZE;


void create() {
  string filename, room_num;
  ::create();
  filename = file_name(TO);
  room_num = filename[strlen(filename)-1..strlen(filename)-1];
  set_items( ([ ({"fence", "wall", "stockade fence", "wooden fence"}) : "The %^ORANGE%^stockade fence"
                      +"%^RESET%^ here is %^GREEN%^green%^RESET%^ and %^CYAN%^slick%^RESET%^ with"
                      +" %^GREEN%^moss%^RESET%^ and %^BOLD%^%^BLACK%^m%^RESET%^i%^BOLD%^%^BLACK%^ld"
                      +"%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^w%^RESET%^, as a result of its proximity"
                      +" to the humid jungle to the north. It's really yucky." ]) );
  set_climb_exits(([
    "climb":({TABAXROOM + "battlement" + room_num,2,0, 30}),
  ]));
}

void init(){
  ::init();
  add_action("climb", "climb");
  set_had_players(3);
}

string long_desc(){
  string desc;
  desc = "%^GREEN%^You are standing in the %^RESET%^gap %^GREEN%^between the %^RESET%^north wall"
        +" %^GREEN%^of the %^ORANGE%^stockade%^GREEN%^ and the"
        +" %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^un%^BOLD%^%^GREEN%^gl%^RESET%^%^GREEN%^e to the north."
        +" ";
  return desc;
}

int climb(string str){
  if (!stringp(str)){
    tell_object (TP, "Climb what?");
    return 1;
  }
  if (str == "wall" || str == "stockade" || str == "fence" || str == "stockade fence"){
    tell_object(TP, "The fence here is all green and slippery with moss and mildew from its proximity"
                   +" to the edge of the jungle. It would be near impossible to climb. It would be"
                   +" easier to head north and climb one of the trees");
    return 1;
  }
  tell_object(TP, "You can't climb " + str);
  return 1;
}