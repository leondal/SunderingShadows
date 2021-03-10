#include <std.h>
#include <move.h>
#include <daemons.h>
#include "../../tecqumin.h"

inherit ROOM;

int query_screened();
int query_staked();
string long_desc();
string plat_desc();
void add_critters();

int screened;
int staked;

string long_desc();

void create() {
  ::create();
  screened = 0;
  staked = 0;
  set_indoors(0);
  set_property("light", 2);
  set_terrain(JUNGLE);
  set_travel(GAME_TRACK);
  set_name("A jungle clearing");
  set_short("%^GREEN%^A %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^"
           +"%^GREEN%^ng%^RESET%^%^GREENl%^BOLD%^%^GREEN%^e%^RESET%^"
           +" %^GREEN%^clearing%^RESET%^");
  set_long( (:TO, "long_desc":) );
  set_items(([ ({"platform", "wooden platform"}): "Slender branches wind"
        +" and weave around the lower limbs of the"
        +" tree, creating an organic effect of living wicker, which forms"
        +" a stable platform around the massive trunk of the higureon"
        +" tree."]));
   set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life.");
  set_listen("default","There is the constant hum of insect activity, the"
                     +" bustle and shrill calls of exotic birds. Small"
                     +" animals can be heard scurrying in the undergrowth"
                     +" and larger creatures are occasionally heard"
                     +" further in the distance.");
  set_climb_exits(([
    "climb":({ROOMS  + "t_house_middle",2,0, 30}),
  ]));
  add_critters();
}
void init() {
   ::init();
   add_action("erect_screens", "erect");
   add_action("fix_stakes", "fix");
}

void reset(){
  ::reset();
  add_critters();
}

void add_critters(){
  int num, i;
  object sprite;
  sprite = present("sprite", TO);
  if (objectp(sprite)){return;}
  num = random(3)+ random(1);
  if (num>0){
    for (i=0;i<num;i++){
      sprite = new(MOB + "sprite");
      sprite->move(TO);
    }
  }
}

string long_desc(){
  string desc;
  desc =  "%^ORANGE%^You are on a platform constructed around the trunk of"
         +" an enormous tree, about thirty feet above the ground. The tree"
         +" rises high overhead, with branches radiating from the trunk on"
         +" all sides.\n";
  if ((string)TO->query_exit("down") != "/d/shadowgate/void"){
    desc += "%^RESET%^A small hatch is open in the platform, and a rope"
         +" ladder is swinging down.\n";
  }
  return desc;
}

int query_screened(){
  return screened;
}

int query_staked(){
  return staked;
}

int set_screened(int screen){
  screened = screen;
}

int set_staked(int stake){
  staked = stake;
}

int erect_screens(string str){
  object * stuff, * rooms, room, screen;
  string * exits, roomname;
  int i;
  if (str != "screen" && str != "screens"){
    tell_object(TP, "You can't erect that here");
    return 1;
  }
  stuff = all_inventory(TP);
  if (sizeof(stuff)>0){
    for (i=0;i<sizeof(stuff);i++){
      if (stuff[i]->id("wicker screen")){
        screen = stuff[i];
        break;
      }
    }
    if (!objectp(screen)){
      tell_object(TP, "You don't have any screens to erect");
      return 1;
    }
  }
  tell_object(TP, "You fix your screen to the railing at the edge of the"
                 +" platform");
  rooms = ({TO});
  exits = query_exits();
  if (sizeof(exits)>0){
    for (i=0;i<sizeof(exits);i++){
      roomname = query_exit(rooms[i]);
      room = find_object_or_load(roomname);
      if (objectp(room)){
        rooms += ({room});
      }
    }
  }
  room = find_object_or_load(TREEHOUSE + "/rooms/" + "crowsnest");
  if (objectp(room)){
    rooms += ({room});
  }
  room = find_object_or_load(TREEHOUSE + "/rooms/" + "t_house_base");
  if (objectp(room)){
    rooms += ({room});
  }
  for (i=0;i<sizeof(rooms);i++){
    tell_room(rooms[i], TPQCN + " erects a screen along the railing of the"
                       +" platform", TP);
  }
  screened = 1;
  screen->remove();
  return 1;
}

int fix_stakes(string str){
  object * stuff, * rooms, room, stake;
  string * exits, roomname;
  int i;
  if (str != "screen" && str != "screens"){
    tell_object(TP, "You can't fix that here");
    return 1;
  }
  stuff = all_inventory(TP);
  if (sizeof(stuff)>0){
    for (i=0;i<sizeof(stuff);i++){
      if (stuff[i]->id("wooden stakes")){
        stake = stuff[i];
        break;
      }
    }
    if (!objectp(stake)){
      tell_object(TP, "You don't have any stakes to erect");
      return 1;
    }
  }
  if (screened == 0){
    tell_object(TP, "There's no obvious place to fix the stakes to here at"
                   +" the moment.");
    return 1;
  }
  tell_object(TP, "You fix the stakes through the wicker screens, bracing"
                 +" them on the platform floor. The end result is a"
                 +" defensive barricade bristling with spikes on the"
                 +" outside, like a porcupine");
  rooms = ({TO});
  exits = query_exits();
  if (sizeof(exits)>0){
    for (i=0;i<sizeof(exits);i++){
      roomname = query_exit(rooms[i]);
      room = find_object_or_load(roomname);
      if (objectp(room)){
        rooms += ({room});
      }
    }
  }
  room = find_object_or_load(ROOMS + "crowsnest");
  if (objectp(room)){
    rooms += ({room});
  }
  room = find_object_or_load(ROOMS + "t_house_base");
  if (objectp(room)){
    rooms += ({room});
  }
  for (i=0;i<sizeof(rooms);i++){
    tell_room(rooms[i], TPQCN + " pushes a number of stakes through a"
       +" wicker screen fixed to the platform railing, forming a defensive"
       +" barrier of outward-facing spikes", TP);
  }
  staked = 1;
  stake->remove();
  return 1;
}

