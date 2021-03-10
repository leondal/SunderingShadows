#include <std.h>
#include "../piratedefs.h"

inherit ROOM;

void create(){
::create();

set_property("indoors",1);
set_property("light",3);
    set_terrain(WOOD_BUILDING);
    set_travel(DECAYED_FLOOR);

set_short("Private Quarters");

set_long("%^BOLD%^Private Quarters%^RESET%^\n"+
         "You are inside the ship now. "+
         "This area is well lit you can see exits "+
          "to the east, west and south. "+
          "From the south you can hear tremendous belches "+
         "and other disgusting sounds.\n"
        );

set_smell("default","You smell stale and thick air.");
set_listen("default","You can hear the sound of the ship's crew working.");
set_items(([
         ]));

set_exits(([
           "north":CAVES"ship2r2",
           "south":CAVES"ship2r10",
           "east":CAVES"ship2r9",
           "west":CAVES"ship2r8"
          ]));

set_pre_exit_functions(({"south"}),({"stopem"}));

}

void reset(){
   ::reset();
   if(!present("pirate")){
        new(MON+"pirateguard")->move(TO);
}
   if(!present("pirate 2")){
        new(MON+"pirateguard")->move(TO);
}
}

int stopem(){
if(wizardp(TP)) return 1;
    if(present("pirate")){
        if(!TP->query_invis()){
              write("%^MAGENTA%^Pirate says%^RESET%^: What the hell do you want?");
            return 0;
        }else{
            write("You sneak out of the room.");
                return 1;}
}else{
        write("You continue on.");
        return 1;}

}
