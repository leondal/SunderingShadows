//house2.c - Updated by Circe 11/8/03 to new code and changed to reflect new environment for Koenig.
#include <std.h>
#include "../koenig.h"

inherit ROOM;

void create() {
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("light",2);
    set_property("indoors",1);
    set_short("A small, quaint house");
    set_name("A small, quaint house");
    set_long(
      "This small house was once a quaint home to someone.  However, it has "+
      "been burned beyond recognition.  All the %^RED%^furniture %^RESET%^inside the house - "+
      "even the %^YELLOW%^large oak bed%^RESET%^ - has been %^BOLD%^%^BLACK%^"+
      "destroyed%^RESET%^.  Long, strange %^RED%^clawmarks%^RESET%^ "+
      "mar every surface.  %^BOLD%^%^RED%^Blood %^RESET%^is spattered on the walls and all along "+
      "the floor, causing the dust and %^BOLD%^%^BLACK%^soot %^RESET%^to "+
      "stick to the %^ORANGE%^wooden floor beams%^RESET%^.  "+
      "The only thing that seems to have avoided the destruction is a single wooden "+
      "%^ORANGE%^desk%^RESET%^."+
      "\n"
    );
    set_smell("default","The acrid smell of soot and ash lingers in the air.");
    set_listen("default","All is quiet except the wind.");
    set_exits(([
     "southwest" : VILROOMS"k_road11"
    ] ));
    set_items(([
      ({"furniture","bed"}) : "All the furniture in the room has been demolished.  "+
        "Charred ruins are all that now furnishes the house.  The only thing that "+
        "seems to have survived somewhat intact is the desk with a small, unsteady "+
        "wooden chair.",
      ({"desk","chair","wooden desk"}) : "A small, rickety wooden chair sits "+
        "before a desk that seems quite undisturbed amid the carnage of the room.  "+
        "A small bloodstain near the bottom of the desk is the only thing that suggests "+
        "the desk was here when the massacre took place.  A leather-bound journal is "+
        "open on top of the desk, its pages lifting in the wind.",
      ({"diary","journal","book"}) : ({"The leather-bound journal is filled with writing "+
        "in a hasty, sprawling script.  Perhaps you could read it.",
"%^RESET%^You sit down and read the diary.\nThe diary seems to have been written by a native of the village. It reads:\n"+
"   %^BOLD%^%^RED%^The orcs have come!  They are destroying the village as\n"+
"   %^BOLD%^%^RED%^I write...Save us, Light save us!  Their raids have\n"+
"   %^BOLD%^%^RED%^turned to all out invasions.  They must be stopped!\n"+
"   %^BOLD%^%^RED%^We think they must be coming from the cav...\n"+
"%^RESET%^The writing ends abruptly, and you close the diary and stand once more.","common"	}),
      ({"marks","clawmarks","blood"}) : "Every surface in the room is covered with strange "+
        "clawmarks and red-black blood.  Only the desk seems to have escaped.",
      ({"soot","ash"}) : "A fine layer of soot covers most of the room.  Charred "+
        "ruins are all that is left of most of the furniture.  The wind through the "+
        "windows causes the ash to rise into the air."
    ] ));
}

void init() {
  ::init();
}

//This will be moved as soon as I have a chance to look at the hm quest.  Circe 11/27/03
void reset(){
  int r;
  ::reset();
  if(!present("chest")){
    r = random(2);
   if(r==0) new("/d/hm_quest/chests/chest1")->move(TO);
    else new("/d/hm_quest/chests/chest30")->move(TO);
  }
}
