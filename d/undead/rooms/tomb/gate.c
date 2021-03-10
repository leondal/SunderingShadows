#include <std.h>
#include "../../undead.h"

inherit VAULT;

void create() 
{
  ::create();

    set_name("Tomb Road");
    set_terrain(STONE_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("indoors", 1);
    set_property("light", 2);
    set_climate("desert");

    set_short("The gate before the tomb.");

    set("day long","%^RED%^The Tomb of Kartakass looms tall and ominous above you.  "
        "As you gaze upon the cast iron gates a shiver runs up your back.  "
        "Each door must weigh several tons on its own, and whatever creature  "
        "put them in to place such a long time ago, you hope does not still "
        "exist.");
  
    set("night long","%^BLUE%^You stand at the threshold of Kartakass's realm.\n"
        "As night descends upon the realm it is now clear that you have "
        "journeyed into the very heart of darkness, for good could never "
        "have constructed such a demonic construct. Which can only mean "
        "that within this hellhole somewhere lies the Master of all of "
        "this evil, Kartakass himself!");
  
    set_smell("default","You can almost smell the age of this place.");
    set_listen("default","You can hear nothing here, for nothing would dare live here.");
    set_exits(([ 
        "south"     :HALL+"temproad4",
        "gate"      :HALL+"hall"
             ]));

    set_smell("default","You catch the rotten stench of death.");
    set_listen("default","You hear the faint sound of whailing in the distance.");
      
    set_door("gate",HALL"hall","gate","no_key","lock");
    set_open("gate",0);
    set_string("gate","open","The massive gates squeak and grind as "
        "they slowly open.");
    set_string("gate","close","The gates slowly close, the thundering "
        "reverberations sending trickles of sand off the walls.");
    set_door_description("gate","Each gate is made of the strongest iron "
        "and stands approximately twenty feet tall.  At the center of "
        "these plain yet powerfull barriers lies an equally large "
        "golden knocker, with a very realistic face carved into it.");
    set_locked("gate",1,"lock");
    lock_difficulty("gate",-1000,"lock");

}

void init() 
{
  ::init();
    add_action("knock","knock");
}

int knock(string str) 
{
  if (str != "on gate"){
    tell_object(TP, "Maybe you should try <<knock on gate>>\n");
    return 1;
  }
  
    tell_room(ETP,"You see "+TP->QCN+" step up to the great gates and begin knocking "
        "with one of the knockers.",TP);
    tell_object(TP,"You step up to the great gates and begin to knock with "
                 "one of the knockers.");

    if(!present("knocker")) { new(MON+"knocker")->move(TO); return 1;}
    else { tell_room(ETP, "The Knocker glares at you and mutters to itself."); return 1; }
    return 0;
}
