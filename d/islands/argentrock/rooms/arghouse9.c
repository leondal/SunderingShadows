#include <std.h>
#include "/d/islands/argentrock/argabbr.h"

inherit ROOM;

int web_here,spider_avai,swept,lifted;

void create() 
{
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   set("short","%^BOLD%^%^RED%^The kitchen");
   set("long","%^BOLD%^%^RED%^The kitchen
%^RESET%^%^CYAN%^You have entered a cooking place. The %^BOLD%^%^CYAN%^floor%^RESET%^%^CYAN%^ is %^BOLD%^%^CYAN%^cov%^BLUE%^e%^CYAN%^red%^RESET%^%^CYAN%^ by a lot of dust. Quite obviously, no one has used this room for a while. Many cooking utensils are placed neatly near the wash %^BOLD%^%^CYAN%^basin. %^WHITE%^Kniv%^BOLD%^%^WHITE%^e%^RESET%^%^WHITE%^s%^CYAN%^ and %^WHITE%^fork%^BOLD%^%^WHITE%^s%^RESET%^%^CYAN%^ are there in two seperate %^ORANGE%^bask%^BOLD%^%^ORANGE%^e%^RESET%^%^ORANGE%^ts. %^BOLD%^%^WHITE%^P%^RESET%^%^WHITE%^lates%^CYAN%^ and dishes stack up according to their sizes. A %^RED%^s%^ORANGE%^t%^ORANGE%^o%^RED%^ve%^CYAN%^ made of bricks is under the %^BOLD%^%^CYAN%^win%^BLUE%^d%^CYAN%^ow.%^RESET%^%^CYAN%^ A %^ORANGE%^br%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^om%^CYAN%^ and a %^ORANGE%^dustp%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^n%^RESET%^%^CYAN%^ sit next to the %^BOLD%^%^CYAN%^wall.%^RESET%^%^RESET%^
");
   set_property("indoors",1);
    set_property("no teleport",1);
   set_property("light",2);
    set_listen("default","You hear the sounds of the forest coming from "+
      "outside the window.");
   set_smell("default","You smell food.");
   set_items( (["utensils":"Pots, pans ... all kinds of utensils used "+
       "in the kitchen area can be seen.",
      "floor": (: TO, "floor_desc" :),
      "basin":"A simple wash basin.",
      "baskets":"You see forks and knives in them.",
      ({"knives","forks"}):"You eat with these.",
      ({"plates","dishes"}):"All kinds of dishes and plates are here.",
      "stove":"A stove which people use to cook things. It is made of "+
      "brick and is under the window.",
      "window":"Outside the window, you see the dense forest of "+
      "Argentrock.",
      ({"broom","dustpan"}):"A broom and dustpan. You utilize them to "+
      "sweep the floor.",
       "wall":"The wall is made of wood. Not much can been seen hanging on "+
       "it.",
      "cover": (: TO, "cover_desc" :) ]) );
   set_exits( (["door":PATH+"arghouse8"]) );
   set_search("stove", (: TO, "search_stove" :) );
    set_search("floor","Too much dust here.");
   spider_avai = 1;
   web_here = 1;
   swept = 0;
   lifted = 0;
}

int search_stove(string str) 
{
    object spider;
    if(!objectp(TP)) return 0;
    switch(web_here) 
    {
        case 0:
            tell_object(TP, "You find nothing in the stove.");
            break;
        case 1:
            switch(spider_avai) 
            {
                case 0:
                    if(!present("giant spider")) 
                    {   
                        tell_object(TP, "You find a large spider web!");
                        tell_room(ETP, TPQCN+" finds something in the stove!", TP);
                        new(OBJ+"spiderweb")->move(TP);
                        web_here = 0;                    
                        break;
                    }
                    tell_object(TP, "The spider won't allow you!");
                    tell_room(ETP, "The giant spider forbids "+TPQCN+" from "+
                    "searching the stove anymore!", TP);
                    break;
                case 1:
                    tell_object(TP, "As you search the stove, a monster crawls out "+
                    "of it!\nYou really hate such a dirty place.");
                    tell_room(ETP, "As "+TPQCN+" searches the stove, a monster "+
                    "crawls out of it!", TP);
                    new(MON+"gspider")->move(TO);
                    if( spider = present("giant spider",TO) )
                    spider->kill_ob(this_player(),1);
                    spider_avai = 0;
                    break;
            }
    }
    return 1;
}

void init() {
   ::init();
   add_action("sweep_floor","sweep");
   add_action("lift_cover","lift");
}

int sweep_floor(string str) {
   switch(str) {
      case "floor with broom":
         if(swept == 0) {
            write("You pick up the broom and sweep off the dust into "+
               "the dustpan.\nAs you sweep across the floor, "+
               "suddenly you noticed a small cover in the floor!");
            say(TPQCN+" picks up the broom and sweeps off the dust "+
               "into the dustpan.\nAs "+TP->query_subjective()+
               "sweeps across the floor, "+TP->query_subjective()+" notices something.");
            remove_search("floor");
            swept = 1;
            return 1;
         }
         else notify_fail("The floor is already clean!\n");
         return 0;
         break;
      default:
         notify_fail("Sweep what with what?\n");
         return 0;
   }
}

int lift_cover(string str) {
   switch(str) {
      case "cover":
         switch(swept) {
            case 0:
               notify_fail("You don't see a cover here!\n");
               return 0;
               break;
            case 1:
               switch(lifted) {
                  case 0:
                     write("You lift the cover and discover a black "+
                        "pearl within the small chamber in the floor!");
                     say(TPQCN+" lifts the cover and discovers "+
                         "something in it!");
                     new(OBJ+"blackpearl")->move(TP);
                     lifted = 1;
                     return 1;
                     break;
                  case 1:
                     notify_fail("It has been already lifted up!\n");
                     return 0;
               }
               return 1;
         }
         break;
      default:
         notify_fail("You don't see that here!\n");
         return 0;
   }
}

void floor_desc() {
   switch(swept) {
      case 0:
          write("So much dust here prevents you from seeing the floor "+
            "clearly.");
         break;
      case 1:
         write("The floor is clean and you see a small cover in it.");
   }
}

string cover_desc() {
   switch(swept) {
      case 0:
         return "What cover?";
         break;
      case 1:
         switch(lifted) {
            case 0:
               return "You wonder what is hidden here. Maybe you "+
                  "should lift it up?";
               break;
            case 1:
               return "It has been lifted up and you see a small "+
                  "chamber here.";
         }
   }
}

void spider() {
   spider_avai = 1;
   web_here = 1;
}

void reset() {
   ::reset();
   spider();
   swept = 0;
}
