#include <std.h>
#include <move.h>
#include "../tecqumin.h"


inherit JUNG_ROOM + "jung_base.c";


void create() {
  ::create();
  set_items( ([ ({"tower", "rickety tower"}) : (:TO, "tower_desc":) ]) );
  set_climb_exits(([ "climb" : ({JUNG_ROOM + "tower_top",2,0,100}), ]));  
}


string short_desc(){
  return "%^BOLD%^%^GREEN%^In a %^RESET%^%^GREEN%^thick%^BOLD%^"
           +" %^GREEN%^jungle";
}


string long_desc(){
  string desc;
  desc = base_desc();
  tell_object(TP, desc);
  desc = "%^RESET%^A %^BOLD%^%^YELLOW%^clearing %^RESET%^has been cut"
    +" through the %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng"
    +"%^RESET%^%^GREEN%^l%^BOLD%^e %^RESET%^here, and a tall,%^ORANGE%^"
    +" rickety tower%^RESET%^ constructed in the %^RESET%^space from"
    +" %^ORANGE%^branches %^RESET%^lashed together with%^BOLD%^"
    +" %^GREEN%^l%^RESET%^%^GREEN%^ia%^BOLD%^n%^RESET%^%^GREEN%^a"
    +"%^BOLD%^s%^RESET%^.";
  return desc;
}

string tower_desc(){
  string desc;
  int i, count;
  object room, * critters;
  desc = "%^ORANGE%^The tower is close to the height of the surrounding"
    +" trees, but doesn't quite climb above the"
    +" %^BOLD%^%^GREEN%^canopy%^RESET%^%^GREEN%^ of the %^GREEN%^j"
    +"%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^BOLD%^%^GREEN%^l"
    +"%^RESET%^%^GREEN%^e%^ORANGE%^, but it gets close. It is built"
    +" in a tall pyramid shape, with four main corner struts that"
    +" slowly converge toward a platform near the top. Lots of"
    +" branches criss-cross the structure - presumably for stability,"
    +" but also making it an easy climb. However, the %^GREEN%^l%^BOLD%^"
    +"%^GREEN%^i%^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^"
    +"as%^RESET%^%^ORANGE%^ binding it together are old and the ties"
    +" do not look all that tight, making the whole thing look decidedly"
    +" %^RESET%^shaky%^ORANGE%^.";
  room = find_object_or_load(JUNG_ROOM + "tower_top");
  if (objectp(room)){
    critters = all_living(room);
    count = sizeof(critters);
    if (count >0){
      tell_object(TP, desc);
      tell_object(TP, "%^RESET%^%^GREEN%^You can make out: ");
      for (i=0;i<count;i++){
        desc = "";
        if (i >0 && i==count-1){
          desc += "and ";
        }
        desc += critters[i]->QCN;
      } 
      tell_object(TP, desc);
      desc = "%^RESET%^%^GREEN%^on the %^ORANGE%^platform%^GREEN%^"
        +" at the top.";
    }
  }
  return desc;  
}