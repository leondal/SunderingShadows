#include <std.h>
#include "../piratedefs.h"
inherit ROOM;

int found,body;

void create(){
   ::create();
   set_property("light",2);
   set_property("indoors",0);
   set_terrain(DESERT_DUNES);
   set_travel(FOOT_PATH);
   set_name("Canyon Mouth");
   set_short("Canyon Mouth");
   set_long("You are standing at the entrance to a small canyon.  You can see the canyon winding down into "
"darkness, and you wonder what could be down there.  The canyon walls here are almost hidden by the sand "
"dunes.  You have two choices, you can either keep going south into the canyons or you can turn back north.  "
"There is a short path leading to the west.\n");
   set_smell("default","It smells damp");
   set_listen("default","You can hear the desert wind whistling through the canyons.");

   set_items(([
     ({"dunes", "sand dunes"}):"The dunes are piled high against the canyon wall.  As you inspect them more "
"closely you notice the tip of something sticking out of the sand.",
     "south":"You strain your eyes trying to see where this dark canyon goes.",
     "north":"You look north back into the vast desert you came from. The thought of returning there empty "
"handed sickens you.",
     ({"canyon walls","walls"}):"You look at the weathered granite and notice the fine shapes that many "
"years of blowing sand has created.",
     "tip":"There is definitely something there to be found, maybe you could sift through the sand and find "
"out just what it is."
   ]));

   set_exits(([
     "west":"/d/player_houses/tigger/tigger1",
     "south":CAVES"canyon2",
     "north":"/d/shadow/virtual/desert/49,49.desert"
   ]));
   set_search("corpse",(:TO,"search_fun":));
}

void init(){
   ::init();
   add_action("sift","sift");
}

int sift(string str){
   object equipment;
   if(str != "sand" || body == 1) return 0;
   tell_object(TP,"You find a dried up corpse!");
   tell_room(ETP,TPQCN+" sifts through the sand and finds a dried up corpse.",TP);
   equipment = new(OBJ"driedcorpse")->move(TO);
   body=1;
   return 1;
}

int search_fun(string str){
   object equipment;
   if((!present("dried") || found == 1)) return 0;
   equipment = new(OBJ"darkring")->move(TO);
   tell_object(TP,"You find a %^BLACK%^%^BOLD%^black%^RESET%^ ring!");
   tell_room(ETP,TPQCN+" finds something on the corpse.",TP);
   found=1;
   return 1;
}

void reset(){
   object ob;
   ::reset();
   if(ob= present("dried")) ob->remove();
   found=0;
   body=0;
}
