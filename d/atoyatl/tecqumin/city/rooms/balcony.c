#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit VAULT;

void create() {
  ::create();
  set_indoors(1);
  set_property("light", 2);
  set_terrain(STONE_BUILDING);
  set_travel(DECAYED_FLOOR);
  set_name( "A balcony overlooking the plaza" );
  set_short("A %^CYAN%^balcony%^RESET%^ overlooking the"
    +" %^BOLD%^%^WHITE%^plaza%^RESET%^");
  set_long( "This semicircular %^CYAN%^balcony%^RESET%^ looks"
    +" out over the %^BOLD%^%^WHITE%^plaza%^RESET%^, to the"
    +" huge %^ORANGE%^ziggurat%^RESET%^ beyond. A quick"
    +" assessment reveals that it is placed atop the head of"
    +" the %^ORANGE%^j%^BOLD%^%^BLACK%^u%^ORANGE%^ng"
    +"%^BOLD%^%^BLACK%^l%^ORANGE%^e"
    +" %^BOLD%^%^YELLOW%^c%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^t"
    +"%^RESET%^ the building is modelled upon. It is bounded by"
    +" a rail, which incorporates the ears of the beast. The"
    +" view across the %^BOLD%^%^WHITE%^plaza%^RESET%^ and to"
    +" the city beyond must once have been breathtaking, though"
    +" its scope is now somewhat reduced by the encroachment of"
    +" the %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng"
    +"%^RESET%^%^GREEN%^l%^BOLD%^e%^RESET%^." );
  set_items(     ([ ({"plaza"}): (:TO, "view_plaza":),
     ({"ziggurat", "pyramid"}) :  "The massive ziggurat located"
    +" to the south of the plaza takes the form of a stepped"
    +" stone pyramid, with four sides. Each of the sides you"
    +" can see has a broad central stairway, leading up to what"
    +" looks like a covered ceremonial altar at the top." ,
     ({"ear", "ears", "railing"}) : "The sculpted ears of the"
    +" jungle cat divide the"
    +" railing into approximately equal thirds. Standing in"
    +" between them, it would be possible to see, and address,"
    +" the plaza and much of the city beyond."  ]) );
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life.\n");
  set_listen("default","There is the constant hum of insect activity, the"
                     +" bustle and shrill calls of exotic birds. Small"
                     +" animals can be heard scurrying in the undergrowth"
                     +" and larger creatures are occasionally heard"
                     +" further in the distance.\n");
  set_exits((["down"   : CITY_ROOM + "throne_room"    ]));
}

void init() {
   ::init();
   add_action("address", "address");
   add_action("address_city", "say");
} 

int address(string str){
  tell_object(TP, "From here, you just need to speak normally to address the city");
  return 1;
}

int address_me(string str){
  string * files, speech_start, speech_end, alias_keys, alias;
  mapping aliases;
  int i, count, num;
  object room;
  files = get_dir(CITY); 
  count = sizeof(files);
  if (count<1){
    return 0;
  }
  speech_start = "none";
  speech_end = "none";
  aliases = TP->query_aliases();
  if (sizeof(aliases) >0){
    alias_keys = keys(aliases);
    if (member_array("say", alias_keys)!= -1){
      alias = aliases["say"];
      num = sscanf(str, "%s $* %s", speech_start, speech_end);
    }
  } 
  if (speech_start = "none"){ 
    speech_start = "";
  }
  if (speech_end == "none"){
    speech_end = "";
  }
  for (i=0;i<count;i++){
    room = find_object(CITY + files[i]);
    if (objectp(room)){
      if (base_name(room) == CITY + "balcony"){
        continue;
      }
      tell_room(room, TPQCN + "'s %^RESET%^%^CYAN%^voice carries out from the balcony above the plaza");
      tell_room(speech_start + str + speech_end);
    }
  }
  return 0;
}

string view_plaza(){
  tell_object(TP, "%^BLUE%^You cast your eyes out over the plaza.");
  TP->move(CITY_ROOM + "plaza");
  TP->force_me("look");
  TP->move(TO);
  return "";
}
