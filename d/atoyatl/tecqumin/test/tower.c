#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit ROOM;

int collapsed;
string long_desc();

void create() {
  ::create();
  collapsed = 0;
  set_indoors(0);
  set_property("light", 2);
  set_terrain(JUNGLE);
  set_travel(FOOT_PATH);
  set_name("In a thick jungle");
  set_short("%^BOLD%^%^GREEN%^In a %^RESET%^%^GREEN%^thick%^BOLD%^"
           +" %^GREEN%^jungle");
  set_long( "The close growing %^GREEN%^j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^"
    +"ng%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^e t%^BOLD%^%^GREEN%^r%^RESET%^"
    +"%^GREEN%^ees%^RESET%^ suddenly part, revealing the remains of a stone"
    +" tower. It seems isolated in its own little clearing, with neither"
    +" paths leading to it nor fences surrounding it. It is perhaps three"
    +" storeys high, but mostly ruined. The rest of the life of the %^GREEN%^"
    +"j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^BOLD%^%^GREEN%^l%^RESET%^"
    +"%^GREEN%^e%^RESET%^ appears to carry on as normal all around it." );
  set_items(([({"tower", "stone tower"}) : "About three storeys high, the "
    +"tower is dwarfed by the trees that surround it, including a mighty"
    +" %^ORANGE%^higurion%^RESET%^ tree that grows close alongside. The"
    +" tower's condition is very poor, with many cracks and faults in the"
    +" stonework. There appears to be no roof, and most of one of the walls"
    +" on the upper level has collapsed. ",
          ({"tree", "trees"}) : "The trees grow high here, just as in the rest"
    +" of the %^GREEN%^j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^BOLD%^"
    +"%^GREEN%^l%^RESET%^%^GREEN%^e%^RESET%^. One mighty %^ORANGE%^higurion%^RESET%^"
    +" tree stands next to the tower, its canopy spreading over the top of the"
    +" ruined structure.",
                ({"higurion", "higurion tree"}) : "The %^ORANGE%^higurion"
    +"%^RESET%^ tree is characterised by a thick bole, supporting strong, near"
    +"-horizontal branches that begin fairly low to the ground, making it easy"
    +" to climb. Its upper canopy spreads above the tower, and one or two of"
    +" the middle branches poke through the holes in the tower's stone walls." 
        ]));
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life");
  set_listen("default","The calls and cries of various forms of bird and animal"
   +" life bring the jungle to life.");
  set_exits( ([ "down" : TEST + "start" ]) );
}
void init() {
   ::init();
   add_action("climb", "climb");
   add_action("jump", "jump");
}

int climb(string str){
  if (str == "into tower" || str == "tree into tower"|| str == "higurion tree into tower" || str == "climb into the tower"){
    if (collapsed ==1){
      tell_object(TP, "The tower is no longer standing. You can't climb into it.");
      return 1;
    }
    tell_object (TP, "You climb up the %^ORANGE%^higurion%^RESET%^ tree and drop into the tower");
    tell_room(TO, TPQCN + "climbs up the branches of the %^ORANGE%^higurion%^RESET%^ tree and drops into the tower.", TP);
    TP->move(ROOMS + "upper_floor");
    TP->force_me("look");
    return 1;
  }
  if (str == "tree" || str == "higurion tree" || str == "the tree"|| str == "the higurion tree"){
    tell_object(TP, "You climb into the branches of the %^ORANGE%^higurion%^RESET%^ tree.");
    if (collapsed == 0){
      tell_object(TP, "You could probably jump down into the tower from here.");
    }
    tell_room(TO, TPQCN +" climbs into the brances of the %^ORANGE%^higurion%^RESET%^ tree.");
    TP->force_me("pose climbing the higurion tree");
    return 1;
  }
  if (collapsed ==0){
    return notify_fail("Do you want to climb into the tower, or climb the higurion tree?");
  } else {
    return notify_fail("Do you want to climb the higurion tree?");
  }
}

int collapse_tower(){
  object upper_floor, ground_floor;
  if (collapsed ==0){ 
    return 0;
  }
  upper_floor = find_object_or_load(ROOMS + "upper_floor");
  ground_floor = find_object_or_load(JUNG_ROOM + "ground_floor");
  tell_room(TO, "With a series of loud %^BOLD%^%^CYAN%^CRASHES%^RESET%^, first one then another"
   +" of the uper walls of the tower collapse. Then, there is a series of further crashes inside"
   +" the tower, then finally the remaining walls collapse inwards, leaving nothing more than a"
   +" huge pile of jumbled stones.");
  set_long( "The close growing %^GREEN%^j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^"
    +"ng%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^e t%^BOLD%^%^GREEN%^r%^RESET%^"
    +"%^GREEN%^ees%^RESET%^ suddenly part, revealing a huge pile of stones"
    +" that may once have been a tower. It seems isolated in its own little clearing, with neither"
    +" paths leading to it nor fences surrounding it. It is completely ruined; nothing remains"
    +" beyond this pile of rubble. The rest of the life of the %^GREEN%^j%^BOLD%^%^GREEN%^u"
    +"%^RESET%^%^GREEN%^ng%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^e%^RESET%^ appears to carry on"
    +" as normal all around it." );
  remove_item(({"tower", "stone tower", "tree", "trees", "higurion tree"}));
  set_items(([({"tower", "stone tower", "pile", "pile of stones", "stones"}) : 
    "The huge pile of stones look old, but there are some signs that the final collapse may have"
    +" been fairly recent. Fresh breaks show in many of the stones, and there is some damage to"
    +" the massive higurion tree that stands next to the rubble. The haze of dust that hangs"
    +" over the rubble is a bit of a clue, too.",
          ({"tree", "trees"}) : "The trees grow high here, just as in the rest"
    +" of the %^GREEN%^j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^BOLD%^"
    +"%^GREEN%^l%^RESET%^%^GREEN%^e%^RESET%^. One mighty %^ORANGE%^higurion%^RESET%^"
    +" tree stands next to huge pile of stones",
                ({"higurion", "higurion tree"}) : "The %^ORANGE%^higurion"
    +"%^RESET%^ tree is characterised by a thick bole, supporting strong, near"
    +"-horizontal branches that begin fairly low to the ground, making it easy"
    +" to climb." 
        ]));
  if (objectp(upper_floor)){
    upper_floor->collapse();
  }
  if (objectp(ground_floor)){   
    ground_floor->collapse();  
  }
  collapsed = 1;
  
}
int jump (string str){
  if ((string)TP->query_property("posed") != "climbing the higurion tree"){
     return 0;
  }
  if (str == "into tower" || str == "down into tower" || str == "down into the tower" || str == "into the tower"){
    if (collapsed == 0){
      tell_object(TP, "You jump carefully down from your perch in the %^ORANGE%^higurion%^RESET%^ tree, into the upper level of the tower.");
      tell_room(TPQCN + "jumps carefully down from " + TP->QP + " perch in the %^ORANGE%^higurion%^RESET%^ tree, into the upper level of the tower.", TP);
      TP->move (ROOMS + "upper_floor");
      TP->force_me("look");
      return 1;
    } else {
      tell_object(TP, "The tower is no longer standing. You will have to jump down.");
      return 1;
    }
  }
  if (str == "down" || str == "down from tree" || str == "down from the tree" || str == "to the ground" || str == "down to the ground"){
    tell_object(TP, "You jump back down to the ground");
    tell_room(TO, TPQCN + " jumps down from the tree", TP);
    TP->force_me("pose clear");
    return 1;
  }
  return notify_fail("Do you want to jump down to the ground, or into the tower?");
}
