#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit CROOM;


void create() {
  int i;
  object tabaxi;
  ::create();
  set_short("Inside the stockade");
  set_long("You are in the middle of the %^ORANGE%^stockade%^RESET%^. A few tabaxi wander round,"
          +" engaged in their own business. From here, you can see what looks like a%^BOLD%^%^BLACK%^"
          +" smithy%^RESET%^ and a small healer's hut. You can also see the modest hut occupied by"
          +" the tabaxi elder.");
  set_exits( ([ "south" : TABAXROOM + "stockade" ,
               "west": TABAXROOM + "west_section",
               "east": TABAXROOM + "east_section",
              "north": TABAXROOM + "north_section", 
             "healer": TABAXROOM + "healer",
              "smithy": TABAXROOM + "smithy",
             "hut": TABAXROOM + "elder"
             ]) );
  set_items(([ ({"hut", "elder's hut", "modest hut"}): "A modest looking circular wooden hut raised"
                       +" on stilts, with a thatched roof and a small veranda." ,
             ({ "smithy", "blacksmith", "blacksmith's"}) : "The most solid looking building within"
                  +" the stockade, the smithy is made from wattle and daub, and is large enough to"
                  +" contain the furnace, anvils and other accoutrements of the blacksmith's craft.",
             ({"healer", "healer's"}) : "A small hut set aside for the tending of the sick and"
                  +" injured"
            ]));
      set_monsters(({MOB +"tabaxi"}), ({random(2) + 1})); 
      set_repop(50);
}

void init(){
  ::init();
  set_had_players(3);
}

string query_granary_dir(){
  return "east";
}
