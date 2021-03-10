#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit CORRIDOR;

string long_desc();

void create() {
  
  ::create();
  set_short("small stone wall");
  set_smell("default","The musty air cloggs your nose with the"
                     +" dust of ages long past");
  set_listen("default","Hardly a sound makes it inside here. All is"
                      +" still");
  set_exits( ([ "west" : ROOMS + "corridor1" ])  );
  set_items (([ ({"chair"}): "A small hardwood chair with no cushion. It is very old and riddled with woodworm, but somehow remains in one piece.",
                ({"desk", "reading desk"}) : "The desk has a sloped work surface for easier reading and writing, with an inkwell and tray for quills",
                ({"cot", "small cot"}) : "The hardwood cot has suffered greatly from the ravages of time, and is in a number of pieces, having succumbed to rot and  insect damage."    ]) );
 set_door("door",ROOMS+"corridor1","west",0); 
  set_door_description("door","A heavy stone door.");
}


void reset(){
  object jont, * jonts, room;
  int i, count;
  ::reset();
  if (!present("jontar", TO)){
    jonts = children(MOB + "jontar");
    count = sizeof(jonts);
    if (count>0){
      for (i=count-1;i>=0;i--){
        if (!objectp(jonts[i])){
          jonts -= ({jonts[i]});
          continue;
        }
        room = environment(jonts[i]);
        if (!objectp(room)){
          jonts -= ({jonts[i]});
          continue;
        }
      }
    }
    if (sizeof(jonts)<1){
      jont = new (MOB + "jontar");
      jont->move(TO);
      tell_room(ETO, "The air %^BOLD%^%^CYAN%^fl%^WHITE%^i%^CYAN%^ck"
        +"%^WHITE%^e%^CYAN%^r%^WHITE%^s%^RESET%^ and a %^CYAN%^spirit"
        +"%^RESET%^ appears");
    }
  } 
}

string long_desc(){
    return "This simple stone room is about 10 feet wide and 15 feet long."
      +" It contains a chair, a reading desk and a small wooden cot. A thick"
      +" layer of dust covers all the surfaces, sugesting that nothing"
      +" living has moved here for an age.";
}
