//dock.c - for Lothwaite.  Circe 9/11/04
#include <std.h>
#include "../lothwaite.h"
inherit "/std/pier";

void create(){
   ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(RUTTED_TRACK);
   set_name("A wooden pier");
   set_short("A wooden pier");
   set_long("%^RESET%^%^ORANGE%^This wooden pier reaches far "+
      "out over %^BOLD%^%^BLUE%^Loch Tearmann%^RESET%^%^ORANGE%^, "+
      "long a source of life for the citizens of Lothwaite.  "+
      "All around the pier, the %^BOLD%^%^BLUE%^lake %^RESET%^"+
      "%^ORANGE%^is filled with %^GREEN%^rushes %^ORANGE%^ and "+
      "%^YELLOW%^reeds%^RESET%^%^ORANGE%^.  %^BLUE%^Fish %^ORANGE%^"+
      "of several types swim among the %^YELLOW%^reeds%^RESET%^"+
      "%^ORANGE%^, choosing the %^BOLD%^%^BLACK%^shady places "+
      "%^RESET%^%^ORANGE%^beneath the pier for their beds.  The "+
      "pier itself is stout and well-tended - and almost constantly "+
      "in use by a young boy or girl from the village.  To either "+
      "side of the pier there is a narrow %^GREEN%^grassy area "+
      "%^ORANGE%^that looks rather soft and level, while the path "+
      "back into the village is to the southwest.\n");
   set_smell("default","Clean, fresh mountain air wafts on the breeze.");
   set_listen("default","You hear the occasional -SPLOOSH- of a fish over the wind.");
   set_items(([
      ({"lake","loch","loch tearmann","tearmann","Loch Tearmann"}) : 
         "%^BOLD%^%^BLUE%^The water of the lake has a greenish-"+
         "blue cast from the reeds.  It looks quite cool, but "+
         "probably refreshing.  The lake here does not look overly "+
         "large but is most certainly deep, filling a deep "+
         "depression in the mountainside.  It would probably "+
         "be fun to <swim>,<dive>, or <jump> in - though a little "+
         "cold of course.",
      "water" : "The cool water has a greenish-blue cast but "+
         "looks clean.  You would probably find it quite "+
         "refreshing if you need a drink.",
      ({"pier","wooden pier","dock"}) : "The pier is made from "+
         "sturdy wooden planks and is much wider than you would "+
         "find near any human settlement.  Firbolg children are "+
         "often seen here fishing and returning to the village "+
         "with their catch.",
      ({"rushes","reeds"}) : "The lake is filled with rushes and "+
         "reeds, especially close to the dock.  The rushes are "+
         "those used as floor coverings in the town, while the "+
         "reeds are often combined with willow branches in making "+
         "the furniture.  Beneath the dock, the reeds grow especially "+
         "dense, and many fish bed there in the shade.",
      ({"fish","fishes","fish beds","beds"}) : "Several fish "+
         "are swimming in the lake - there seem to be all sorts "+
         "of varieties!  Many of the ones beneath the dock look "+
         "fat and lazy, content with their lives here in the "+
         "cool mountain lake.",
      ({"boy","girl","children"}) : "Firbolg children often "+
         "sit on the edge of the dock, casting their lines "+
         "out into the water.  They keep their caught fish on "+
         "tethered lines.",
      ({"area","grassy area","grass","shore"}) : "%^GREEN%^The "+
         "lake is bordered by a grassy shore that, while narrow, "+
         "looks rather soft and level.  It would probably be a "+
         "prime place for a picnic - or a nap.",
      ({"path","pathway"}) : "This pathway is clearly wider than "+
         "it would need to be for most humans.  It spans a little "+
         "over eight feet, and it is made of large wooden planks "+
         "bound together with thick rope lashings.  The pathway "+
         "is covered in mud to fill in the cracks, and some portions "+
         "are made up of wattle panels."
   ]));
   set_water_body("lake");
   set_max_fishing(6);
   set_chance(12);
   set_max_catch(8);
   set_exits(([
      "southwest" : PATHEXIT"pathway17",
      "east" : PATHEXIT"shore1",
      "north" : PATHEXIT"shore6"
   ]));
}

void init(){
   ::init();
   add_action("divein","dive");
   add_action("jumpin","jump");
   add_action("swimfun","swim");
   add_action("leave","get");
}

int swimfun(string str){
   if(!str){
      if(!TP->query_property("swimming")){
         tell_object(TP,"You are not in the water right now...you'll "+
            "need to either <jump> or <dive> in first.");
         return 1;
      }
      switch(random(4)){
         case 0:
         tell_object(TP,"You lazily paddle around in the lake, enjoying "+
            "the cool water.");
         tell_room(ETP,""+TPQCN+" lazily paddles around in the lake.",TP);
         break;
         case 1:
         tell_object(TP,"%^CYAN%^You lie on your back, looking up at "+
            "the sky as you take a few backstrokes.");
         tell_room(ETP,"%^CYAN%^"+TPQCN+" looks up at the sky as "+
            ""+TP->QS+" does a few backstrokes.",TP);
         break;
         case 2:
         tell_object(TP,"%^BOLD%^%^BLUE%^You dip your head below "+
            "the surface and swim a few feet underwater.");
         tell_room(ETP,"%^BOLD%^%^BLUE%^"+TPQCN+" dips "+TP->QP+" "+
            "head and swims a few feet underwater.",TP);
         break;
         case 3:
         tell_object(TP,"You take a few strong strokes, swimming "+
            "further away from the dock.");
         tell_room(ETP,""+TPQCN+" takes a few strong strokes, "+
            "swimming further away from the dock.",TP);
         break;
      }
   return 1;
   }
   tell_object(TP,"Just <swim> will work fine.");
   return 1;
}

int leave(string str){
   if(str == "out"){
      if(!TP->query_property("swimming")){
         tell_object(TP,"You are not swimming...why would you need "+
            "to get out?");
         return 1;
      }
      tell_object(TP,"You swim over to the dock and pull yourself "+
         "out of the water.");
      tell_room(ETP,""+TPQCN+" swims over to the dock and pulls "+
         ""+TP->QO+"self out of the water.",TP);
      TP->remove_property("swimming");
      return 1;
   }
   return 0;
}
int divein(string str){
   int dex,good;
   if(!str){
      tell_object(TP,"Well, you probably don't want to dive onto "+
         "the dock.  Try to dive in the lake?");
      return 1;
   }
   if(str == "lake" || str == "in lake" || str == "in the lake"){
      if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed() || TP->query_tripped()) {
         TP->send_paralyzed_message("info",TP);
         return 1;
      }
      if((int)TP->query_property("swimming") == 1){
         tell_object(TP,"You are already swimming!  You will "+
            "need to <get out> first.");
         return 1;
      }
      dex = TP->query_stats("dexterity");
      if(dex > 16){
         good = 1;
      }else if(dex < 10){
         good = 0;
      }else{
         if(!random(4)){
            good = 0;
         }else{
            good = 1;
         }
      }
      if(good == 1){
         tell_object(TP,"%^CYAN%^You walk to the end of the pier and "+
            "execute a graceful swan dive, landing in the %^BOLD%^"+
            "%^BLUE%^cool mountain water%^RESET%^%^CYAN%^.");
         tell_room(ETP,"%^CYAN%^"+TPQCN+" walks to the end of the "+
            "pier and executes a graceful swan dive into the water.",TP);
         TP->set_property("swimming",1);
         return 1;
      }else{
         tell_object(TP,"%^CYAN%^You walk to the end of the pier, "+
            "preparing for your dive.\n%^BOLD%^Suddenly, you slip "+
            "and do a %^RED%^belly flop %^CYAN%^onto the surface "+
            "of the water!  Ouch!");
         tell_room(ETP,"%^CYAN%^"+TPQCN+" walks to the end of the pier, "+
            "preparing for "+TP->QP+" dive.\n%^BOLD%^Suddenly, "+
            ""+TP->QS+" slips and does a %^RED%^belly flop %^CYAN%^"+
            "onto the surface of the water!  That had to hurt!",TP);
         TP->set_property("swimming",1);
         return 1;
      }
   }
   tell_object(TP,"Well, you probably don't want to dive onto "+
      "the dock.  Try to dive in the lake?");
   return 1;
}

int jumpin(string str){
   int dex,good;
   if(!str){
      tell_object(TP,"Well, you probably don't want to jump onto "+
         "the dock.  Try to jump in the lake?");
      return 1;
   }
   if(str == "lake" || str == "in lake" || str == "in the lake"){
      if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed() || TP->query_tripped()) {
         TP->send_paralyzed_message("info",TP);
         return 1;
      }
      if((int)TP->query_property("swimming") == 1){
         tell_object(TP,"You are already swimming!  You will "+
            "need to <get out> first.");
         return 1;
      }
      dex = TP->query_stats("dexterity");
      if(dex > 16){
         good = 1;
      }else if(dex < 10){
         good = 0;
      }else{
         if(!random(4)){
            good = 0;
         }else{
            good = 1;
         }
      }
      if(good == 1){
         switch(random(4)){
            case 0:  tell_object(TP,"%^BOLD%^You run to the edge of "+
                     "the dock and yell %^RED%^- %^CYAN%^Cannonball "+
                     "%^RED%^- %^WHITE%^as you bring your knees to "+
                     "your chest and jump in!");
                     tell_room(ETP,"%^BOLD%^"+TPQCN+" runs to the edge of "+
                     "the dock and yells %^RED%^- %^CYAN%^Cannonball "+
                     "%^RED%^- %^WHITE%^as "+TP->QS+" brings "+
                     ""+TP->QP+" knees to "+TP->QP+" chest and jumps in!",TP);
                     break;
            case 1:  tell_object(TP,"%^BOLD%^%^BLUE%^You jump lightly "+
                     "from the edge of the dock, landing in the "+
                     "cool water.");
                     tell_room(ETP,"%^BOLD%^%^BLUE%^"+TPQCN+" jumps "+
                     "from the edge of the dock, landing a few feet "+
                     "away in the water.",TP);
                     break;
            case 2:  tell_object(TP,"%^BOLD%^%^CYAN%^You run quickly "+
                     "to the edge of the dock and jump high into the "+
                     "air, holding your nose before you hit the water!");
                     tell_room(ETP,"%^BOLD%^%^CYAN%^"+TPQCN+" dashes "+
                     "to the end of the dock and jumps high into the "+
                     "air, holding "+TP->QP+" nose before "+TP->QS+" "+
                     "hits the water!",TP);
                     break;
            case 3:  tell_object(TP,"%^YELLOW%^You execute a graceful "+
                     "flip off the end of the dock, creating a small "+
                     "splash as you hit the water!");
                     tell_room(ETP,"%^YELLOW%^"+TPQCN+" executes a "+
                     "graceful flip off the end of the dock, creating "+
                     "a small splash.",TP);
                     break;
         }
         TP->set_property("swimming",1);
         return 1;
      }else{
         tell_object(TP,"%^BOLD%^%^BLUE%^You dash to the end of the "+
            "dock, prepared to do a fantastic jump!\n%^WHITE%^You "+
            "lose your footing suddenly and skid in, face first!");
         tell_room(ETP,"%^BOLD%^%^BLUE%^"+TPQCN+" dashes to the end "+
            "of the dock and starts to jump!\n%^WHITE%^ He skids "+
            "face first into the water!",TP);
         TP->set_property("swimming",1);
         return 1;
      }
   }
   tell_object(TP,"Well, you probably don't want to jump onto "+
      "the dock.  Try to jump in the lake?");
   return 1;
}
