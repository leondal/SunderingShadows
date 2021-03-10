#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit CROOM;

void create() {
  ::create();
  set_indoors(1);
  set_property("light", 2);
  set_terrain(STONE_BUILDING);
  set_travel(DECAYED_FLOOR);
  set_name("A ruined apothecary");
  set_short( "%^CYAN%^A %^ORANGE%^ruined %^CYAN%^apothecary" );
  set_long( "%^BLUE%^Dusty %^ORANGE%^shelves%^BLUE%^ groaning with"
    +" %^RESET%^stone%^BLUE%^ and %^RED%^earthenware%^BLUE%^ pots line"
    +" the walls of the interior of this large circular building. A large"
    +" %^ORANGE%^workbench%^BLUE%^ in the centre of the space carries"
    +" mixing bowls, cutting tools and pestle and mortar sets."
    +" %^BOLD%^%^GREEN%^V%^RESET%^%^GREEN%^eg%^BOLD%^%^GREEN%^e"
    +"%^RESET%^%^GREEN%^t%^ORANGE%^at%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^"
    +"on%^BLUE%^ has crept in through the cracks and gaps in the walls,"
    +" but the %^BOLD%^%^BLACK%^lack of l%^RESET%^i%^BOLD%^%^BLACK%^ght"
    +" %^RESET%^%^BLUE%^has stopped it growing far. A few"
    +" %^BOLD%^%^WHITE%^m%^RESET%^us%^BOLD%^%^WHITE%^hr%^RESET%^oo"
    +"%^BOLD%^%^WHITE%^ms%^RESET%^BLUE%^ have sprouted under the"
    +" shelves here and there. At the back of the room, the staircase has"
    +" collapsed into ruin." );
  set_items(([  ({"pots", "earthenware pots", "stone pots"}) : "The"
    +" stone and earthenware pots are in various shapes and sizes. Most"
    +" are cracked, broken and empty, but a few retain cork stoppers or"
    +" wax sealant." ,
                ({"workbench"}) : "The workbench is stained from long"
    +" use, and has been left in some disarray, as though abandoned"
    +" mid-apothecarying" ]));
  set_search("pots",("There are all sorts of pots and vessels here. Are"
    +" you looking for something particular?"));
  set_search("for mushroom cup", (:TO, "cup_search":));
  set_search("mushroom cup", (:TO, "cup_search":));
  set_search("mushroom pot", (:TO, "cup_search":));
  set_search("mushroom vessel", (:TO, "cup_search":));
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life.\n");
  set_listen("default","There is the constant hum of insect activity, the"
                     +" bustle and shrill calls of exotic birds. Small"
                     +" animals can be heard scurrying in the undergrowth"
                     +" and larger creatures are occasionally heard"
                     +" further in the distance.\n");
  set_exits((["out" : CITY_ROOM + "grand_hut02"]));
}

void init(){
  ::init();
  add_action("cup_look", "look");
}

void reset(){
  ::reset();
  
  setup_tracks();
}

void setup_tracks(){
  object * jaguars, jaguar, room;
  string * tracks;
  int i, count;
  tracks = TO->query_tracks();
  if (sizeof(tracks)>0 && member_array("jaguar&tell story&grabbed something from a shelf", tracks) !=-1){
    return;
  }
  jaguars = children(MOB + "werejag");
  count = sizeof(jaguars);
  if (count>0){
    for (i=count-1;i>=0; i--){
      if (!objectp(jaguars[i])){
        continue;
      }
      room = environment(jaguars[i]);
      if (objectp(room)){
        tell_room(room, jaguars[i]->QCN + " slips away to another part of the jungle");
        room->add_tracks( jaguars[i], "tell story", "slipped away to another part of the jungle");
      }
      jaguars[i]->move("/d/shadowgate/void");
    }
  }
  jaguar = new (MOB + "werejag");
  add_tracks(jaguar, "tell story", "grabbed something from a shelf");
  add_tracks(jaguar, "left", "out");
  room = find_object_or_load(CITY_ROOM + "grand_hut02");
  room->add_tracks(jaguar, "left", "north");
  room = find_object_or_load(CITY_ROOM + "grand_ruin03");
  room->add_tracks(jaguar, "left", "north");
  room = find_object_or_load(CITY_ROOM + "city_jung11");
  room->add_tracks(jaguar, "left", "north");
  room = find_object_or_load(CITY_ROOM + "grand_ruin03");
  room->add_tracks(jaguar, "left", "west");
  room = find_object_or_load(CITY_ROOM + "city_jung13");
  room->add_tracks(jaguar, "left", "northwest");
  room = find_object_or_load(JUNG_ROOM4 + "city_jung14");
  jaguar->move(room);
  tell_room(room, jaguar->QCN + " arrives");
  jaguar->reach_destination(); 
}

string cup_search(){
  object ghost, werejag;
  ghost = present("apothecary", TO);
  if (objectp("ghost")){
    return;
  }
  ghost = find_object_or_load(MOB + "apothecary");
  if (objectp(ghost)){
    tell_room(TO, ghost->QCN + " suddenly coalesces from the air");
    ghost->move(TO);
  }
  ghost->force_me("say %^CYAN%^Ah! You are looking for something,"
    +" something special. But it is gone!");
  werejag = new(MOB + "werejag");
  
}

int cup_look(string str){
  if (str == "cup" || str == "for cup"){
    tell_object(TP, "What sort of cup are you looking for?");
    return 1;
  }
  if (str == "mushroom cup"||str == "mushroom pot" || 
      str == "for mushroom cup" || str == "for mushroom pot" ||
      str == "mushroom vessel" || str =="for mushroom vessel"){
    cup_search();
    return 1;
  }
  return 0;
}

