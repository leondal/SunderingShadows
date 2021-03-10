//Coded by Bruenor. Updated by Uriel to increase probability of meeting Geilfuss 17 Nov 2019
//All standard rooms can search shadows. 1 in 3 chance of meeting Geilfuss on search.
#include <std.h>
#include "areadefs.h"
inherit CROOM;
int FLAG;

void create()
{
    ::create();
    FLAG = 0;
    set_terrain(BUILT_TUNNEL);
    set_travel(PAVED_ROAD);
    set_property("indoors", 1);
    set_property("no teleport",1);
    set_property("light",2);
    set_name("Underground Passage");
    set_short("Underground Passage");
    set_long(
@BRUENOR
%^BOLD%^%^CYAN%^An Underground Passage%^RESET%^
You are wandering down a very worn passageway. The passageway drags on with
basically no landmarks to mark where you are other then bends and forks
every now and then. You begin to notice strange %^MAGENTA%^runes%^RESET%^ carved
on the cramped walls every 30 feet or so. The ceiling is rather low and 
appears unremarkable. Fortunately a couple of %^ORANGE%^torches%^RESET%^ on the
wall provide a little bit of illumination in this otherwise dark hallway.
The floor has an old %^RED%^red carpet%^RESET%^ stretching down all the passageways.
It appears rather well used. %^BOLD%^%^BLACK%^Shadows%^RESET%^ engulf most of the hall.
BRUENOR
    );
    set_items( ([ "walls": "The wall is a sheet of solid stone.",
       "carpet": "The carpet is a rather nice red felt carpet.",
       "torches": "The torches burn dimly in the dark. They do not "+
       "seem to be burning away the wood though.",
       "ceiling": "The ceiling is rather low and is carved out of "+
       "the rock itself.",
       "runes": "The purpose of these runes is not clear but obviously "+
       "must be the work of some sort of wizard or priest.",
       "shadows": "The shadows in the hall cover a large portion "+
       "of the wall. If something was hiding there you would "+
       "not be able to see it at all." ]) );
    set_smell("default","No abnormal odor is present here.");
    set_listen("default","It is deathly quiet.");
    set_search("default", "It seems as though something or someone could "+
    "be hiding in the shadows.");
    set_search("shadows"||"shadow", (: TO, "search_shadow" :) );
}


void reset()
{
   ::reset();
   FLAG = 0;
   if(present("assassin") || present("assassinfight") || present("assassinrang"),TO) return;
   if(random(4)) return;
   switch(random(5)) {
      case 0:
         new(MON+"assassin")->move(TO);
         if(!random(2))
         {
             new(MON+"assassinmage")->move(TO);
         }
         break;
      case 1:
         new(MON+"assassinfight")->move(TO);
         if(!random(2))
         {
             new(MON+"assassinmage")->move(TO);
         }
         break;
      case 2:
         new(MON+"assassinrang")->move(TO);
         if(!random(2))
         {
             new(MON+"assassinmage")->move(TO);
         }
         break;
      case 3:
         new(MON+"assassin")->move(TO);
         new(MON+"assassin")->move(TO);
         if(!random(2))
         {
             new(MON+"assassinmage")->move(TO);
         }
         break;
      case 4:
         new(MON+"assassinfight")->move(TO);
         new(MON+"assassin")->move(TO);
         new(MON+"assassinrang")->move(TO);
         if(!random(2))
         {
             new(MON+"assassinmage")->move(TO);
         }
         break;
   }

}
int search_shadow()
{
    object ob;

    if(FLAG==0) {
      FLAG = 1;
      switch(random(3))
      {
        case 0:
         tell_object(TP,"The shadows appear empty.");
         tell_room(TO,TPQCN+" does not seem to find anything.",TP);
         return 1;
        case 1:
         tell_object(TP, "%^BLUE%^As you peer into the shadows two "+
         "assassins jump out at you!");
         tell_room(TO,"As "+TPQCN+" peers into the shadows, two "+
         "assassins jump out daggers drawn!",TP);
         new(MON+"assassin")->move(TO);
         new(MON+"assassin")->move(TO);
         break;
        case 2:
         tell_object(TP,"As you examine a shadowy section of the "+
         "wall you realize there is a weapon hanging on it. After"+
         " some searching around you find a two handed sword.");
         tell_room(ETP,""+TPQCN+" searches the shadows "+
                     "and finds a large sword.",TP);
         tell_object(TP, "%^BOLD%^%^RED%^Suddenly someone jumps from the shadows "+
         "and grabs the sword from you!");
         tell_room(TO, "%^BOLD%^%^RED%^Assassins suddenly materialize from the "+
         "shadows and grab the sword from "+TPQCN+"!",TP);
         tell_object(TP, "%^BLUE%^As you peer into the shadows two assassins "+
         "jump out at you!");
         tell_room(TO,"As "+TPQCN+" peers into the shadows, two "+
         "assassins jump out weapons drawn!",TP);

          ob = new(MON+"geilfuss");
          ob->move(TO);
          ob->force_me("stab "+TPQCN);
          ob->force_me("scramble "+TPQCN);
          ob->force_me("say %^BOLD%^%^RED%^Greetings. I am Geilfuss. "+
          "You all shall perish here.");

          ob = new(MON+"assassinfight");
          ob->move(TO);
          ob->force_me("kill "+TPQCN);
          ob->force_me("rush "+TPQCN);
          ob->force_me("say That sword is Gambrill's. "+
          "He hangs it as a display of his power. "+
          "How dare you try and steal it!");
          new(MON+"assassinrang")->move(TO);
          ob->move(TO);
          ob->force_me("kill "+TPQCN);
          ob = new(MON+"assassin");
          ob->move(TO);
          ob->force_me("stab "+TPQCN);
          ob->force_me("kill "+TPQCN);
          ob = new(MON+"assassinmage");
          ob->move(TO);
          ob->force_me("kill "+TPQCN);
     }
   return 1;
   } 
   else
   {
      tell_object(TP,"The shadows appear empty.");
      tell_room(TO,TPQCN+"does not seem to find anything.",TP);
      return 1;
   }    
return 1;
}

