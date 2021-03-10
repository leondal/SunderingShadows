#include <std.h>
#include <move.h>
#include <daemons.h>
#include "../tecqumin.h"

inherit ROOM;
string long_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_terrain(JUNGLE);
  set_travel(GAME_TRACK);
  set_name("A crowsnest");
  set_short("%^ORANGE%^A crowsnest");
  set_long( (:TO, "long_desc":) );
  set_items(([({"platform", "wooden platform"}): "The platform circles the"
         +" treetrunk, some distance below you. It is constructed"
         +" from %^ORANGE%^living wood%^RESET%^ that appears to have been"
         +" woven together, rather than cut and hammered into shape. There"
         +" is a railing around the side.",
              ({"clearing", "jungle clearing"}): "The area below the"
         +" higureon tree is clear, to a radius of about sixty yards."
         ]));
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life.");
  set_listen("default","The wind makes a near constant rustling sound in"
                      +" the leaves of the upper canopy here.");
  set_climb_exits(([
    "descend":({ROOMS  + "t_house_middle",2,0, 30}),
  ]));
}
void init() {
   ::init();
   add_action("fix_nets","fix");
}


string long_desc(){
  string desc;
  desc =  "%^GREEN%^A small %^ORANGE%^lookout post%^GREEN%^ has been built"
         +" at the top of the higureon tree. From here, you can see the"
         +" %^RESET%^clearing %^GREEN%^below, the rest of the tree and the"
         +" %^ORANGE%^platform %^GREEN%^around the trunk.";
  return desc;
}

int fix_nets(string str){
  object * stuff, net, * rooms, room;
  int i;
  stuff = all_inventory(TP);
  if (str != "net"){
    tell_object(TP, "About all you could usefully fix here would be a net"
                   +" to the outer branches");
    return 1;
  }
  if (sizeof(stuff)>0){
    for (i=0;i<sizeof(stuff);i++){
      if (stuff[i]->id("xxairnetxx")){
        net = stuff[i];
        break;
      }
    }
  }
  if (!objectp(net)){
    net = present("net", TP);
    if (!objectp(net)){
      tell_object(TP, "You don't have a net");
      return 1;
    } else {
      tell_object(TP, "Your net isn't really big enough to make much"
                     +" difference here");
      return 1;
    }
  }
  tell_object(TP, "Taking your swathe of netting, you carefully arrange it"
                 +" over and around the outer branches of the canopy");
  rooms = ({});
  rooms += ({TO});
  room = find_object_or_load(ROOMS + "crowsnest");
  if (objectp(room)){
    rooms += ({room});
  }
  room = find_object_or_load(ROOMS + "t_house_base");
  if (objectp(room)){
    rooms += ({room});
  }
  if (sizeof(rooms)>0){
    for (i=0;i<sizeof(rooms);i++){
      tell_room(rooms[i], TPQCN +" drapes huge swathes of netting over the"
               +" outer branches of the higureon tree", TP);
    }
  }
  return 1;
}