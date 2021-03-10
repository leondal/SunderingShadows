//nest.c
#include <std.h>
#include "../kildare.h"

inherit ROOM;
int items;
object ob;
string str;

void create(){
items = 1;
   ::create();
   set_indoors(1);
   set_property("light",0);
   set_terrain(ROCKY);
   set_travel(FOOT_PATH);
   set_name("A large nest");
   set_short("A large cave");
   set_long(
      "This large %^ORANGE%^cave %^RESET%^seems dwarfed by the massive pile of "+
      "%^ORANGE%^branches %^RESET%^and %^GREEN%^pine needles %^RESET%^"+
      "in the center.  What can only be a %^RED%^beastial nest "+
      "%^RESET%^is truly an amazing creation.  "+
      "The %^ORANGE%^branches %^RESET%^have been bent and formed into an almost "+
      "perfect circle, just as tiny %^ORANGE%^twigs %^RESET%^are molded for a normal "+
      "%^BOLD%^%^BLUE%^bird's nest%^RESET%^.  The cave has no other adornments or features, "+
      "although large %^BOLD%^%^GREEN%^green%^RESET%^-%^BOLD%^%^BLACK%^"+
      "black %^GREEN%^f%^BLACK%^e%^GREEN%^a%^BLACK%^t%^GREEN%^h%^BLACK%^"+
      "e%^GREEN%^r%^BLACK%^s %^RESET%^are scattered among "+
      "the rather messy large %^BOLD%^bird d%^RESET%^%^ORANGE%^r%^BOLD%^"+
      "%^WHITE%^oppings%^RESET%^.\n"
      );
   set_smell("default","The acrid smell of bird droppings lingers here.");
   set_listen("default","The cave is silent after the buffeting wind outdoors.");
   set_items(([
      (({"branches","pile","nest","pine needles"})) : "Large branches "+
         "have been molded and formed together to build a gigantic "+
         "nest.  Pine needles have been cleverly used to fill in the "+
         "gaps, making the interior of the nest warm and soft.  Looking "+
         "closer, it seems as though the nest is lumpy in places.",
      (({"feathers","green feathers","green-black feathers"})) : "%^GREEN%^Large, "+
         "soft feathers of a green so deep they are nearly black line the "+
         "floor and are scattered around the nest.  Several of the feathers "+
         "are soft and downy, probably belonging to the beastial bird's young.",
      (({"droppings","bird droppings"})) : "Disgusting white bird droppings "+
         "tinged with black are streaked down the walls.  Several small puddles "+
         "have formed on the floor as well.  Given the amount of droppings "+
         "and the size of the nest, either the bird that lives here is the "+
         "size of a dragon or several of the same type of creature live here."
   ]));
   set_search("nest", (: TO, "search_nest" :) );
   set_search("branches", (: TO, "search_nest" :) );
}

void search_nest() 
{
  if((items > 0)) { 
       if(random(3) < 2) {
       write("%^BOLD%^%^RED%^As you rifle through the nest, several tiny birds begin chirping!\n"          
"%^BOLD%^%^RED%^Suddenly, a large peryton swoops in from the cave opening!\n");
       tell_room(ETP,"%^BOLD%^%^RED%^"+TPQCN+" searches the nest, causing birds to "+
          "chirp and bringing in a large peryton!\n",TP);
       new(MON"peryton")->move(TO);
       switch(random(26)){
                  case 0:
                        tell_room(ETP,"%^GREEN%^Thankfully there seems to be only one of them.\n");
                        break;
                  case 1:
                        new(MON"peryton")->move(TO);
                        tell_room(ETP,"%^BOLD%^%^RED%^ARGH!!  Another peryton flies "+
                           "in to protect the young ones!");
                        break;
                  case 2:
                        tell_room(ETP,"%^GREEN%^Thankfully there seems to be only one "+
                           "of them and something shimmers in the nest too!");
                        new(OBJ"gem")->move(TO);
                        break;
                  case 3:
                        tell_room(ETP,"%^GREEN%^There seems to be only one of them "+
                           "and something clinks within the nest.");
                                ob = new("/std/obj/coins");
                                ob->set_money("gold", random(100)+15);
                                ob->set_money("electrum", random(250)+100);
                                ob->move(TO);
                                break;
                  case 4:
                        tell_room(ETP,"%^GREEN%^Thankfully there seems to be only "+
                           "one of them and there is something else in the nest too.");
                                new(OBJ"earthjerkin")->move(TO);
                                break;
                  case 5:
                        tell_room(ETP,"%^GREEN%^Thankfully there seems to be only "+
                           "one of them and there is something else in the nest too.");
                                new(OBJ"forge")->move(TO);
                                break;
                  case 6..7:
                        tell_room(ETP,"%^GREEN%^Thankfully there seems to be only "+
                           "one of them and there is something else in the nest too.");
                                new(OBJ"harvestmoon")->move(TO);
                                break;
                  case 8:
                        tell_room(ETP,"%^GREEN%^Thankfully there seems to be only "+
                           "one of them and there is something else in the nest too.");
                                new(OBJ"hunterhatchet")->move(TO);
                                break;
                  case 9..10:
                        tell_room(ETP,"%^GREEN%^Thankfully there seems to be only "+
                           "one of them and there is something else in the nest too.");
                                new(OBJ"ironhat")->move(TO);
                                break;
                  case 11..12:
                        tell_room(ETP,"%^GREEN%^Thankfully there seems to be only "+
                           "one of them and there is something else in the nest too.");
                                new(OBJ"purifyring")->move(TO);
                                break;
                  case 13:
                        tell_room(ETP,"%^GREEN%^Thankfully there seems to be only "+
                           "one of them and there is something else in the nest too.");
                                new(OBJ"quiltedjacket")->move(TO);
                                break;
                  case 14..15:
                        tell_room(ETP,"%^GREEN%^Thankfully there seems to be only "+
                           "one of them and there is something else in the nest too.");
                                new(OBJ"refreshring")->move(TO);
                                break;
                  case 16..17:
                        tell_room(ETP,"%^GREEN%^Thankfully there seems to be only "+
                           "one of them and there is something else in the nest too.");
                                new(OBJ"shockgrain")->move(TO);
                                break;
                  case 18:
                        tell_room(ETP,"%^GREEN%^Thankfully there seems to be only "+
                           "one of them and there is something else in the nest too.");
                                new(OBJ"skullcap")->move(TO);
                                break;
                  case 19..20:
                        tell_room(ETP,"%^GREEN%^Thankfully there seems to be only "+
                           "one of them and there is something else in the nest too.");
                                new(OBJ"insectbane")->move(TO);
                                break;
                  case 21..22:
                        tell_room(ETP,"%^GREEN%^Thankfully there seems to be only "+
                           "one of them and there is something else in the nest too.");
                                new(OBJ"reapingwhirlwind")->move(TO);
                                break;
                  case 23..25:
                        tell_room(ETP,"%^GREEN%^Thankfully there seems to be only "+
                           "one of them and there is something else in the nest too.");
                                new(OBJ"reapingwhirlwind_lg")->move(TO);
                                break;
                   default:  break;
                }       
           items = 0;
           return;
        }
       else {
         write("You find only feathers and broken eggshells.");
         tell_room(ETP,""+TPQCN+" seems to be disappointed from searching
the nest.",TP);
         items = 0;
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
