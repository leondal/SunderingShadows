//Coded by Lujke

#include <std.h>
#include <security.h>
#include "../../tecqumin.h"
inherit "/std/obj/map_maker.c";

void create() {
    ::create();
    set_name("sheet of parchment");
    set_id( ({"sheet","parchment", "parchment sheet", "sheet of parchment", "map", "parchment map" }) );
    set_short("%^RESET%^%^ORANGE%^sheet of parchment%^RESET%^");
    set_weight(1);
    set_long( (:TO, "long_desc":) );
    if (interact("greater", base_name(TO))) detect_invis_exits = 1;
    set_lore("The %^ORANGE%^t%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^b%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^x%^BOLD%^%^BLACK%^i%^RESET%^ people of %^BOLD%^%^GREEN%^Atoyatl Tepexitl%^RESET%^ are gifted, or cursed, with great curiousity. Some play it down, preferring to live sequested in their quiet villages, far from other races. Others give in to the trait, becoming great scouts, pathfinders and explorers. At some point in their history, a tribal shaman developed a way to bind the %^CYAN%^spirits%^RESET%^ of their %^ORANGE%^ancestors%^RESET%^ to these explorers' maps, enabling them to see ahead and plan their routes while remembering the lands they have passed through already. Most such maps are blessed by minor spirits, bound to the continent of their birth. A few, though, are rumoured to have the blessings of major ancestral ghosts, which are able to pass into the world beyond the shores of %^BOLD%^%^GREEN%^Atoyatl Tepexitl%^RESET%^.");
   set_property("lore_difficulty",45);
}

void init(){
  ::init();
  set_long( (:TO, "long_desc":) );
}

int map_me(string str){
  if (!objectp(ETO)) return;
  if (!userp(ETO)) return notify_fail("You have to be holding the map to do that");
  if (!objectp(EETO)) return notify_fail("There seems to be a problem with the room you are in. Please make a bug report");
  if (!interact("greater", base_name(TO)) && !interact ("atoyatl", base_name(EETO)))
  {
    tell_object(TP, "The spirits of this map are not strong enough to act so far away from home.");
    return 1;
  }
  tell_object(TP, "You sit down and concentrate on the map, watching in wonder as it begins to fill itself in.");
  tell_room(EETO, TPQCN + " sits down and concentrates on a piece of parchment " + TP->QS + " is holding.", TP);
  working_message = ("More of the map fills itself in...");
  end_message = ("Finally, the your map is complete");
  TP->set_paralyzed(5, "Your mind is taken up with the map you are concentrating on");
  return ::map_me(str);
}

void map_next_step(string * next_rooms, string * mapped_rooms, string * broken_rooms, int stage, int max_stage, int delay){
  TP->set_paralyzed(5, "Your mind is taken up with the map you are concentrating on");
  ::map_next_step( next_rooms,  mapped_rooms, broken_rooms, stage, max_stage, delay);
  tell_object(TP, show_basic_map(TP));
}

string long_desc(){
  string desc, filename;
  int pits;
  object room;
  desc = "%^ORANGE%^This sheet of parchment is yellowed with age and %^BOLD%^%^BLACK%^blackened%^RESET%^%^ORANGE%^ at the edges.%^RESET%^";
//  tell_object(TP, desc);

  if (sizeof(query_locations()) > 0)
  {
    desc += "\n" + show_basic_map(TP);
    desc += show_key(TP);
  } else {
    desc += "\n\n\n\n\n\n\n\n\nThe %^ORANGE%^parchment%^RESET%^ is blank\n"
      +"To use the map, you can <trace #>, # is the number of steps you want to trace out."
      +" This takes some time and concentration, during which you will not be able"
      +" to act.";  
  } 
  return desc;
} 
