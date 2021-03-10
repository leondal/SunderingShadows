#include <std.h>
#include "../lothwaite.h"
#include <daemons.h>

inherit ROOM;

void create(){
   ::create();
   set_name("Ancient Barrows");
   set_short("%^BOLD%^%^BLACK%^Ancient Barrows%^RESET%^");
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
   set_indoors(1);
   set_property("light",1);
   set_property("no sticks",1);
   set_property("no teleport",1);
   set_long("%^RESET%^%^BLUE%^This enormous circular %^ORANGE%^chamber "+
      "%^BLUE%^is carved from the %^RESET%^mountain %^BLUE%^itself "+
      "and serves as the %^ORANGE%^center point %^BLUE%^for the "+
      "various %^ORANGE%^hallways %^BLUE%^and %^ORANGE%^passages "+
      "%^BLUE%^that snake their way through the %^RESET%^mountain"+
      "%^BLUE%^.  These %^BOLD%^%^BLACK%^barrows %^RESET%^%^BLUE%^"+
      "served as the %^RESET%^tombs %^BLUE%^for the ancient "+
      "firbolgs of %^GREEN%^"+
      "Lothwaite%^BLUE%^, a practice which still continues today.  "+
      "Brilliant %^ORANGE%^golden torches %^RESET%^%^BLUE%^ bathe "+
      "the area in %^RESET%^f%^BOLD%^l%^RESET%^i%^BOLD%^c%^RESET%^"+
      "k%^BOLD%^e%^RESET%^r%^BOLD%^i%^RESET%^n%^BOLD%^g %^YELLOW%^"+
      "light%^RESET%^%^BLUE%^, illuminating all but the uppermost "+
      "reaches of the %^BOLD%^%^BLACK%^ceiling%^RESET%^%^BLUE%^.  "+
      "There, %^BOLD%^%^BLACK%^shadows %^RESET%^%^BLUE%^f%^MAGENTA%^"+
      "l%^BLUE%^i%^MAGENTA%^t %^BLUE%^and %^MAGENTA%^d%^BLUE%^a"+
      "%^MAGENTA%^n%^BLUE%^c%^MAGENTA%^e %^BLUE%^on a %^CYAN%^"+
      "cool breeze %^BLUE%^that moves eternally through the "+
      "%^RESET%^barrows%^BLUE%^.  This area serves as a %^RESET%^"+
      "landing %^BLUE%^for the %^BOLD%^%^BLACK%^spiral staircase "+
      "%^RESET%^%^BLUE%^that leads up out of the %^RESET%^barrows "+
      "%^BLUE%^or down into the %^BOLD%^%^BLACK%^darkness %^RESET%^"+
      "%^BLUE%^below.%^RESET%^\n");
   set_items(([
      ({"walls","stone walls","wall","stone"}) : "%^BLUE%^The walls of the "+
         "caverns are flawlessly smooth and seem to emit a coldness all "+
         "their own.  They are shot through with %^BOLD%^%^BLACK%^v"+
         "%^YELLOW%^e%^BLACK%^i%^YELLOW%^n%^BLACK%^s %^RESET%^"+
         "%^BLUE%^of %^BOLD%^%^BLACK%^black %^RESET%^%^BLUE%^and "+
         "%^YELLOW%^gold%^RESET%^%^BLUE%^.",
      ({"veins","black","gold","veins of black and gold"}) : "%^BLUE%^"+
         "The %^BOLD%^%^BLACK%^dark gray stone %^RESET%^%^BLUE%^ of the "+
         "walls is shot through with web-like %^BOLD%^%^BLACK%^v"+
         "%^YELLOW%^e%^BLACK%^i%^YELLOW%^n%^BLACK%^s %^RESET%^"+
         "%^BLUE%^of %^BOLD%^%^BLACK%^black %^RESET%^%^BLUE%^and "+
         "%^YELLOW%^gold%^RESET%^%^BLUE%^.  The %^YELLOW%^gold %^RESET%^"+
         "%^BLUE%^looks as though it were melted and poured along the "+
         "walls, while the %^BOLD%^%^BLACK%^black %^RESET%^%^BLUE%^"+
         "almost looks to be a hidden force trying to break through the "+
         "stone.",
      ({"torch","torches","torchlight"}) : "%^YELLOW%^Unlike most torches, "+
         "these are not made of simple wood with fuel-soaked cloth.  Instead, "+
         "each torch has been formed from solid gold and set with %^BLUE%^"+
         "sapphires %^YELLOW%^and %^CYAN%^diamonds%^YELLOW%^.  Strangely, "+
         "you notice no source of fuel that would explain the burning of "+
         "any of the torches.",
      ({"dome","ceiling","ceilings","onion dome","domes"}) : "The ceilings "+
         "high overhead are hidden in the shadows, but an occasional leap "+
         "of the torchlight reveals onion-shaped domes overhead.  They are "+
         "carved to give the illusion of windows, but only serve to emphasize "+
         "the fact that you are indeed far underground with no way out.",
      ({"shadow","shadows"}) : "The flickering light of the torches sends "+
         "shadows dancing high up the walls, hiding the ceiling from view "+
         "except for brief moments.  They sometimes seem to be hiding something.",
      ({"stairs","stairway","staircase","spiral staircase","landing"}) :
         "This wide room is little more than a landing for the "+
         "spiral staircase making its way both up and down here.  "+
         "The stairs are carved from the natural stone of the "+
         "mountainside and glitter in the light of countless "+
         "torches."
   ]));
   set_listen("default","Your footsteps echo loudly down the deserted corridor.");
   set_smell("default","The cool breath of a tomb is the only smell in the air.");
   set_exits(([
      "up" : PATHEXIT"stones2",
      "down" : PATHEXIT"b1"
   ]));
}

void reset(){
   ::reset();
   if(query_exit("up") != "/d/shadowgate/void"){
      tell_room(TO,"%^BLUE%^The great stone lid scrapes and creaks "+
         "as a mystical force moves it back in place, sealing the "+
         "exit above!");
      remove_exit("up");
   }
   if(!present("firbolg shaman")){
      new(MON"ghostshaman")->move(TO);
   }
}

void init(){
   ::init();
   add_action("knock","knock");
}

int knock(string str){
   object *stuff;
   string *killers;
   object mystuff;
   int i;
   killers = SAVE_D->query_array("lothwaite_killers");
   if(!str){
      tell_object(TP,"What are you trying to knock on?  Try the walls.");
      return 1;
   }
   if(str == "walls" || str == "on walls" || str == "on wall" || str == "wall" || str == "on the wall" || str == "on the walls"){
      if(query_exit("up") != "/d/shadowgate/void"){
         tell_object(TP,"The lid is already open!  Simply climb "+
            "the stairs if you want out.");
         return 1;
      }
      if(member_array(TPQN, killers) != -1) {
         tell_object(TP,"The shaman will not work the magic for "+
            "a killer like you!  You must find another way out!");
         return 1;
      }
      if(!present("firbolg shaman")){
         tell_object(TP,"The magic of the room is dead without "+
            "the shaman!  You must find another way out.");
         return 1;
      }
      stuff = deep_inventory(TP);
      for(i=0;i<sizeof(stuff);i++){
         mystuff = stuff[i];
         if(!objectp(TP)) continue;
         if((string)mystuff->query_name() != "belt of giant strength") continue;
         tell_object(TP,"The shaman fixes his gaze on you and "+
            "seems to see right through you!  He will not let "+
            "you leave with the belt!");
         tell_room(TO,"The shaman fixes his gaze on "+TPQCN+"!",TP);
         return 1;
         break;
      }
      if(TP->query_quests()) {
         if(member_array("Lothwaite Quest",TP->query_quests()) != -1) {
            tell_object(TP,"%^BOLD%^You reach out and knock on the "+
               "walls, then stand back and look overhead.");
            tell_room(TO,"%^BOLD%^"+TPQCN+" knocks on the walls, then "+
               "looks up into the darkness overhead.",TP);
            tell_room(TO,"%^BOLD%^%^BLUE%^There is a scraping "+
               "sound as the lid is rolled back and light shines "+
               "from above.");
            add_exit(PATHEXIT"stones2","up");
            "/d/barriermnts/lothwaite/rooms/stones2"->add_exit(PATHEXIT"b_start","barrows");
            tell_room("/d/barriermnts/lothwaite/rooms/stones2",
               "%^BOLD%^%^BLUE%^There is a scraping sound as the "+
               "large stone lid suddenly lifts and rolls away, "+
               "revealing a passage down below.");
            return 1;
         }
      }
      tell_object(TP,"You must first help the firbolgs recover their "+
         "artifact before they will allow you out!");
      return 1;
   }
   return 0;
}