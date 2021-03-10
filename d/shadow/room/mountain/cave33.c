//cave33.c
#include <std.h>
#include "echoes.h"

inherit OGRES;

int items;
object ob, obj;
string str;


void create(){
items = 1;
    ::create();
    set_property("light",2);
    set_long(
      "%^YELLOW%^A Cavern Deep in Echoes Mountains%^RESET%^\n"+
      "The tunnel ends in this once-grand cavern.  Tall, fluted "+
      "%^YELLOW%^columns %^RESET%^form a large circle around an "+
      "imposing %^BOLD%^%^BLUE%^stone table %^RESET%^surrounded by "+
      "many %^ORANGE%^wooden chairs%^RESET%^.  Unlike the other tunnels "+
      "in this level of the cave system, this %^ORANGE%^cavern %^RESET%^has "+
      "well-made, matching %^BOLD%^%^BLACK%^braziers %^RESET%^placed "+
      "at regular intervals along the wall, providing ample light.  "+
      "The large, oval cavern is now covered with %^ORANGE%^rubble %^RESET%^"+
      "in many places, and the columns and stone table look as though "+
      "they are in need of much repair.  Several piles of rubble are "+
      "scattered around the room."+
      "\n"
    );
    add_item("table","A large, rectangular stone table dominates the room, "+
      "surrounded by several wooden chairs.  The table is in need of repair, "+
      "but was obviously once the focal point of this grand meeting hall.");
    add_item("chair","The wooden chairs were once well-made but now many "+
      "stand nearly in shambles.  The wood has splintered, causing the "+
      "seats to sag and the legs to bow.");
    add_item("chairs","The wooden chairs were once well-made but now many "+
      "stand nearly in shambles.  The wood has splintered, causing the "+
      "seats to sag and the legs to bow.");
    add_item("columns","The tall columns go from floor to ceiling.  They "+
      "are partially crumbling now, but they are still elegant.  Their fluted "+
      "bottoms are nearly covered in rubble from the room.");
    add_item("braziers","The tall metal braziers are built to stand around "+
      "four feet tall.  They hold lit torches, brightening the room.");
    add_item("piles","The piles of rubble scattered across the room could "+
      "be hiding something.");
    add_item("piles","The piles of rubble scattered across the room could "+
      "be hiding something.");
    set_search("pile", (: TO, "search_pile" :) );
    set_search("rubble", (: TO, "search_pile" :) );
    set_search("piles", (: TO, "search_pile" :) );
    set_exits(([
        "south" : ROOMS"cave32"
   	]));
}

void reset() {
   object ob;
  ::reset();
  if(!present("giant")) {
    ob = new(MOBS"giant");
    if(!random(3)) {
      new("/d/shadow/obj/clothing/giantrobe")->move(ob);
      ob->force_me("wear robe");
    }
    ob->move(TO);
  }
  if(!present("ogre")) {
    new(MOBS"ogre")->move(TO);
  }
  if(!present("ogre king")) {
    new(MOBS"ogreking")->move(TO);   
  }
        if(random(4))
        if (!items) items=1;

}
void search_pile() 
{
object ob,obj;
  if(present("ogre guard")) {
    if(!present("ogre guard")->id("summoned monster")){
       write("The ogre guard will not let you search that!");
       return;
    }
  }
  if((items > 0)) { 
       switch(random(3)){
                  case 0:
                           ob = new("/d/magic/scroll");
                           ob->set_spell(3);
                           ob->move(TO);
                           break;
                  case 1:
                           obj = new("/std/obj/coins");
                           obj->set_money("gold", random(100)+50);
                           obj->set_money("silver", random(500)+100);
                           obj->move(TO);
                           break;
                  case 2:
                        "/d/common/daemon/randstuff_d.c"->find_stuff(TO,"rand");
                        break;
                }   
           tell_object(TP,"You find something hidden in the rubble!");
           tell_room(ETP,""+TPQCN+" finds something hidden in the rubble!",TP);
           items = 0;
           return;
    }           
    else {
        write("It looks like this has been thoroughly searched recently.");
        }
}
