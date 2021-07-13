#include <std.h>
#include <move.h>
#include <daemons.h>
#include "../../tecqumin.h"

inherit ROOM;
int burned;
string entry_method;

void create(){
  ::create();
  set_property("indoors", 1);
  set_property("light", 2);
  DESTINATIONS_D->add_waystation( file_name(TO), file_name(TO), 1);
  DESTINATIONS_D->add_waystation( file_name(TO), TABAXROOM + "northeast_corner", 2);
  DESTINATIONS_D->add_waystation( file_name(TO), TABAXROOM + "northwest_corner", 2);
  DESTINATIONS_D->add_waystation( file_name(TO), TABAXROOM + "southeast_corner", 2);
  DESTINATIONS_D->add_waystation( file_name(TO), TABAXROOM + "southwest_corner", 2);
  burned = 0;
  set_short("Granary");
  set_long((: TO, "long_desc" :) );
  set_items(([ ({"store", "stores", "grain", "grain store"}): (:TO, "grain_desc" :) ,
             ({ "stairs", "stairway", "steps"}) : "A narrow set of stone steps lead up to the surface"
            ]));
  set_exits( ([ "up" : TABAXROOM + "northeast_corner" ,
             ]) );
  entry_method = "seems like no orog did this thing!";
}

void init(){
  ::init();
  add_action ("burn_me", "burn");
  add_action ("burn_me", "light");
  add_action ("burn_me", "set");
  add_action ("burn_me", "start");
  set_had_players(3);
}

int query_burned(){
  return burned;
}

void clean_up(){
  int burn;
  string meth;
  meth = entry_method;
  burn = burned;
  ::clean_up();
  burned = burn;
  entry_method = meth;
}

void set_entry_method(string str){  
  entry_method = str;
}

string query_entry_method(){
  return entry_method;
}

string grain_desc(){
  string desc;
  switch (burned){
  case 7:
     desc = "A number of large %^ORANGE%^grain stores%^RESET%^ have been built in the%^BLUE%^"
          +" underground cool%^RESET%^ of this chamber. They are shaped something like%^MAGENTA%^"
          +" tulip flowers%^RESET%^, with narrow stems rising a few feet from the ground to support"
          +" bulb-shaped storage sections. The whole area has been %^RED%^burned%^RESET%^ and the"
          +" grain stores are %^BOLD%^%^BLACK%^ruined%^RESET%^. The sides of them are"
          +" %^BOLD%^%^BLACK%^blackened with soot%^RESET%^ and have %^ORANGE%^cracked%^RESET%^ in the"
          +" heat. The thatch covers have burned away and the grain inside is ruined.";
    break;
  case 1..6:
    desc = "The grain stores are on %^BOLD%^%^RED%^F%^YELLOW%^I%^RED%^RE!%^RESET%^ Statcks of wood"
           +" have been piled up around them and lit. The whole place is %^RED%^b%^BOLD%^%^RED%^u"
           +"%^RESET%^%^RED%^rn%^BOLD%^%^YELLOW%^i%^RED%^n%^RESET%^%^RED%^g%^RESET%^! The grain stores"
           +" themselves are shaped something like%^MAGENTA%^"
          +" tulip flowers%^RESET%^, with narrow stems rising a few feet from the ground to support"
          +" bulb-shaped storage sections. The tops are covered with %^ORANGE%^thatch%^RESET%^, which"
          +" is %^BOLD%^%^RED%^bl%^RESET%^%^RED%^a%^BOLD%^%^RED%^zing%^RESET%^ away merrily at the"
          +" moment.";
    break;
  default:
    desc = "A number of large %^ORANGE%^grain stores%^RESET%^ have been built in the%^BLUE%^"
          +" underground cool%^RESET%^ of this chamber. They are shaped something like%^MAGENTA%^"
          +" tulip flowers%^RESET%^, with narrow stems rising a few feet from the ground to support"
          +" bulb-shaped storage sections, which are covered with %^ORANGE%^thatch%^RESET%^ to keep"
          +" any %^CYAN%^moisture%^RESET%^ from dripping into the grain. Each of the%^ORANGE%^"
          +" earthenware%^RESET%^ stores has an access hole near the top, through which grain can be"
          +" poured in, or extracted with a scoop";
    if (present("firewood", TO) || present ("wood", TO)){
      desc += ". %^ORANGE%^Firewood%^RESET%^ has been placed in the room, ready to burn.";    
    }
  }
  return desc;
}

string long_desc(){
  string desc;
  switch(burned){
  case 7:
    desc = "%^BOLD%^%^BLACK%^You are in a large, cool %^RESET%^%^BLUE%^underground%^BOLD%^%^BLACK%^"
          +" chamber, filled with a number of %^RESET%^%^ORANGE%^earthenware%^BOLD%^%^BLACK%^ grain"
          +" stores. The chamber appears to be a natural fissure, which has been enlarged and adapted."
          +" The whole place has been %^RESET%^%^RED%^burned%^BOLD%^%^BLACK%^ recently. The grain"
          +" stores are ruined.";
    break;
  case 0:
    desc = "%^BOLD%^%^BLACK%^You are in a large, cool %^RESET%^%^BLUE%^underground%^BOLD%^%^BLACK%^"
          +" chamber, filled with a number of %^RESET%^%^ORANGE%^earthenware%^BOLD%^%^BLACK%^ grain"
          +" stores. The chamber appears to be a natural fissure, which has been enlarged and adapted."
          +" A little %^RESET%^%^ORANGE%^l%^BOLD%^%^WHITE%^i%^RESET%^%^ORANGE%^ght%^BOLD%^%^BLACK%^"
          +" filters down from the stairway leading back up to the surface.";
    break;
  default:
    desc = "%^BOLD%^%^RED%^You are in the middle of a fire! The large undergound chamber you are in is"
          +" on fire! The chamber is filled with a number of %^RESET%^%^ORANGE%^earthenware%^BOLD%^"
          +"%^RED%^ grain stores, all of which are %^RESET%^%^RED%^burning%^BOLD%^%^RED%^. It would be"
          +" a really good idea to leave via the %^RESET%^%^ORANGE%^stairway%^BOLD%^%^RED%^ leading"
          +" back up to the surface.";
  }
  return desc;
}

int burn_me(string str){
  string verb, what, which;
  object wood;
  verb = query_verb();
  if (!stringp(str) || strlen(str)<1){
    notify_fail(verb + " what?");
    return 0;
  }
  str= lower_case(str);
//  str = FILTERS_D->strip_colors(str);
  if (verb == "burn"){
    wood = present(str, TO);
    if (!objectp(wood)){
      if (str== "grain" || str == "grain store"|| str == "grain stores" || str == "stores"){
        notify_fail("That won't burn on its own. You'll need some fuel");
        return 0;
      }
      notify_fail("There is no " + str + " here to burn");
      return 0;
    }
    if (!wood->id("wood") && !wood->id("firewood")){
      notify_fail("You can't burn that here");
      return 0;
    }
  } else {
    if (str == "fire"){
      wood = present("wood", TO);
      if (!objectp(wood)){
        wood= present("firewood", TO);
      }
      if (!objectp(wood)){
        notify_fail("There's nothing suitable to burn here");
        return 0;
      }
    } else {
      notify_fail ("Try '" + verb +" fire'" );
      return 0;
    }
  }
  if (burned > 0){
    tell_object(TP, "A fire has already been lit here!");
    return 1;
  }
  tell_object(TP, "%^BOLD%^%^RED%^You start a fire in the granary. Probably a good time to leave!");
  tell_room(TO, "%^BOLD%^%^RED%^" + TPQCN + " %^BOLD%^%^RED%^starts a fire in the granary. This would"
               +" probably be a good time to leave!", TP);
  burned = 1;
  if ((string)TP->query_race()=="orog"){
    entry_method = (string)TP->query_entry_method();
  }
  call_out("burn", 3);
  return 1;
}

void burn(){
  object * things, wood;
  int i, hp;
  burned ++;
  switch(burned){
  case 2:
    tell_room(TO, "The %^BOLD%^%^RED%^fire%^RESET%^ begins to take hold! You get"
                 +" %^RED%^burned%^RESET%^!");
    break;
  case 7:
    tell_room(TO, "The %^BOLD%^%^RED%^fire%^RESET%^ in the room begins to burn out. You get"
                 +" %^RED%^burned%^RESET%^ all the same!");
    wood = present("wood", TO);
    if (!objectp(wood)){
       wood = present("firewood", TO);
    }
    while(objectp(wood)){
      wood->remove();
      wood = present("wood", TO);
      if (!objectp(wood)){
         wood = present("firewood", TO);
      }
    }
    call_out("end_fire", 3);
    break;
  default:
    tell_room(TO, "The %^BOLD%^%^RED%^fire%^RESET%^ in the room burns fiercely! You get"
                 +" %^RED%^burned%^RESET%^!");
  }
  things = all_living(TO);
  if (sizeof(things)>0){
    for(i=0;i<sizeof(things);i++) {
      hp = (int)things[i]->query_max_hp()/3;
      if (avatarp(things[i])){
        tell_object(things[i],"Your mighty immortalness spares you any damage that would have"
                             +" occured");
        continue;
      }
      things[i]->do_damage(things[i]->return_target_limb(),random(hp));
      things[i]->add_attacker(TO);
      things[i]->continue_attack();
      if(objectp(things[i]))    things[i]->remove_attacker(TO);
    }
  }
  if (burned < 7){
    call_out("burn", 3);
  }
  else{
    call_out("end_fire", 3);
  }
}


void end_fire(){
  object * battlers, * rooms, * orogs, * squads, stockade, room;
  int i, num;
  string * dests, whereto;
  rooms = ({TABAXROOM + "battlement1", TABAXROOM + "battlement2", TABAXROOM + "battlement3",
            TABAXROOM + "battlement4", TABAXROOM + "battlement5", TABAXROOM + "battlement6", 
            TABAXROOM + "battlement7", TABAXROOM + "battlement8", TABAXROOM + "watchtower", 
            TABAXROOM + "centre", TABAXROOM + "east_section", TABAXROOM + "foodhall", 
            TABAXROOM + "granary", TABAXROOM + "kitchen", TABAXROOM + "north_section", 
            TABAXROOM + "northeast_corner", TABAXROOM + "northwest_corner", 
            TABAXROOM + "smithy", TABAXROOM + "southeast_corner", 
            TABAXROOM + "southwest_corner", TABAXROOM + "stockade", TABAXROOM + "training", 
            TABAXROOM + "west_section"});
  battlers = children(TABAXOBJ + "tabaxi_battler");
  num = sizeof(battlers);
  if (num>0){
    for (i=0;i<num;i++){
      if (objectp(battlers[i])){
        battlers[i]->set_meth(entry_method);
        battlers[i]->end_attack();
      }
    }
  }
  for (i=0;i<sizeof(rooms);i++){
    room = find_object_or_load(rooms[i]);
    if (!objectp(room)){ continue;}
    tell_room(find_object_or_load("/realms/lujke/workroom"), "Sending message to: " + base_name(room));
    tell_room(room, "%^BOLD%^%^GREEN%^Disaster strikes the Tabaxi!%^RESET%^ The settlement"
                       +" %^ORANGE%^grain stores%^RESET%^ have been %^RED%^burned!%^RESET%^"
                       +" There is a real risk of starvation!");
  }
  squads = children(MOB + "orog_squad");
  num = sizeof(squads);
  if (num>0){
    for (i=0;i<num;i++){
      squads[i]->move("/d/shadowgate/void");
    }
  }
  squads = children(MOB + "archer_squad");
  num = sizeof(squads);
  if (num>0){
    for (i=0;i<num;i++){
      squads[i]->move("/d/shadowgate/void");
    }
  }
  stockade = find_object_or_load(TABAXROOM + "stockade");
  if ((string)stockade->query_exit("south")=="/d/shadowgate/void"){
    whereto = TABAXROOM + "stockade";
  } else {
    whereto = TABAXROOM + "orog_entry";
  }
  dests = DESTINATIONS_D->query_waystations(whereto);
  if (sizeof(dests)<1){
    DESTINATIONS_D->generate_waystations(whereto,4, 3);
  }
  orogs = children(MOB + "orog");
  num = sizeof(orogs);
  if (num>0){
    for (i=0;i<num;i++){
      orogs[i]->start_walking(whereto);
    }
    orogs[0]->force_me("tell lujke walking to " + whereto);
  }
  orogs = children(MOB + "orog_archer");
  num = sizeof(orogs);
  if (num>0){
    for (i=0;i<num;i++){
      orogs[i]->start_walking(whereto);
    }
  }
}
