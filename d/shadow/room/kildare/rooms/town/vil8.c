//vil8.c
#include <std.h>
#include "../../kildare.h"

inherit ROOM;

int items;
object ob;
string str;

void create()
{
   ::create();
   items = 1;
   set_indoors(1);
   set_property("no sticks",1);
   set_property("light",3);
   set_terrain(BUILT_TUNNEL);
   set_travel(DIRT_ROAD);
   set_short("A Narrow Tunnel");
   set_long(
@CIRCE
%^BOLD%^%^BLACK%^A Tunnel Into the Mountainside
%^RESET%^%^ORANGE%^The small opening on the eastern end of the long 
building twists and turns deeper into the mountain side.  
It seems darker here, though the flickering firelight provides 
enough illumination to see by.  Turning back to the south, the 
tunnel seems to open into a larger cavern just ahead.
CIRCE
   );
   set_items(([
      (({"stone","tunnel","room"})) : "The dark gray stone "+
      "of the surrounding mountainside has been hollowed "+
      "out for this curving tunnel.  The walls are relatively "+
      "smooth and the tunnel seems to be well-built.",
      (({"firelight","light"})) : "The flickering light from the "+
      "fireplaces in the building create shadows that jump "+
      "and dance along the tunnel walls, catching your eye.",
      (({"shadow","shadows"})) : "The shadows on the wall seem "+
      "to shift in and out of existence quickly.  As you watch, "+
      "you think you see a shadowy recess that seems to stay in "+
      "place."
      ]));
   set_smell("default","You smell a peculiar mix of herbs and "+
      "seasonings coming from the cavern.");
   set_listen("default","You hear the sounds of movement from "+
      "the building.");
   set_search("shadows", (: TO, "search_recess" :) );
   set_search("recess", (: TO, "search_recess" :) );
   set_search("shadow", (: TO, "search_recess" :) );

   set_exits(([
      "building" : TROOMS"vil3",
      "south" : TROOMS"vil9"
      ]));
}

void search_recess()
{
  if((items > 0)) { 
        if(random(3) < 2) {
       write("%^BOLD%^%^GREEN%^Looking closer, you see that the recess "+
          "could be hiding something!\n");
       tell_room(ETP,"%^BOLD%^%^GREEN%^"+TPQCN+" feels along the wall in the "+
          "shadows and finds a small hole!\n",TP);
       switch(random(4)){
                  case 0:
                        tell_room(ETP,"%^RESET%^%^GREEN%^Unfortunately, there "+
                           "doesn't seem to be anything in it.");
                        break;
                  case 1:
                        if(random(2) == 0){
                             new(OBJ"headband")->move(TO);
                        }
                        else {
                                object ob;
                                ob = new("/std/obj/coins");
                                ob->set_money("gold", random(75)+5);
                                ob->set_money("silver", random(600)+100);
                                ob->move(TO);
                        }
                                tell_room(ETP,"%^RESET%^%^MAGENTA%^"+TPQCN+" finds "
                                   "something in a small cache in the wall!",TP);
                                write("%^BOLD%^%^MAGENTA%^You find something you might like!\n");
                                break;
                  case 2:
                        new(OBJ"gem")->move(TO);
                        tell_room(ETP,"%^RESET%^%^BLUE%^"+TPQCN+" found something in the hole!",TP);
                        write("%^BOLD%^%^BLUE%^Your hand brushes something onto the floor!");
                        break;
                  case 3:
                      new("/d/shadow/obj/misc/climb_tool")->move(TO);
                        write("%^BOLD%^%^RED%^You found something hidden in the recess.");
                        tell_room(ETP,"%^RESET%^%^RED%^"+TPQCN+" seems to have found something in the recess.",TP);
                        break;
                }       
           items = 0;
           return;
        }
  }           
    else {
        write("It looks like this has been thoroughly searched recently.");
        }
}

void reset() {
        ::reset();
        if(random(4) < 3)
        if (!items) items=1;
}
