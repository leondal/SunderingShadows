/******NOTE - Eastern exit off path near beginning of DD Caves******/
//cavern1.c
#include <std.h>
#include "../cave.h"
#include "ddcaves.h"

inherit CROOM;

int searched;
void pick_critters();

void create(){
    pick_critters();
    ::create();
    set_repop(75);
    set_property("light" , 1);
    set_indoors(1);
    set_property("no sticks", 1);
    set_terrain(NAT_CAVE);
    set_travel(RUBBLE);
    set_name("Dragon's Den Caverns");
    set_short("Dragon's Den Caverns");
    set_long(
      "%^BOLD%^You are in the Dragon's Den Caverns.%^RESET%^\n"+
      "This large %^BLUE%^cavern %^RESET%^off the main tunnel seems to be the lair of "+
      "a large group of %^RED%^rats%^RESET%^.  Through the dark, damp air, you can see "+
      "filthy %^ORANGE%^rats' nests %^RESET%^filled with bits of straw and parchment, along "+
      "with other, less-savory things.  The naturally carved cavern appears "+
      "to have been made by an %^BLUE%^underground river %^RESET%^originally, and a small %^CYAN%^pool "+
      "%^RESET%^still covers the center of the floor.  A %^BOLD%^pile %^RESET%^of broken rocks and other "+
      "rubble has formed along the eastern wall, furthest from the opening leading "+
      "back to the tunnel."+
      "\n"
);
    set_smell("default","You can smell the stale air.");
    set_listen("default","You can hear scurrying rats and dripping water.");
    set_exits(([
	"west" : CAVEDIR+"cave6"
    ]));
    set_items(([
      (({"cavern","cave","lair"})) : "The large, dreary cavern has been naturally carved "+
         "by an underground river.  It has now been taken over by a large group of rats.", 
      "rats" : "The disgusting rodents scurry around everywhere, filling the air with "+
         "their stench and squeaks.",
      (({"nests","rats' nests","rats nests","nest"})) : "The rats' nests are damp and molding "+
         "from the moisture in the air and along the floor of the cavern.  They seem to be "+
         "made from all manner of shredded material, from paper to leaves and twigs.",
      (({"pool","puddle","water"})) : "The small pool of water in the center is dark and "+
         "dreary.  Rat droppings can be seen floating in it, making it quite dark even "+
         "against the gray stone of the cavern floor.",
      (({"pile","rubble","rocks"})) : "The small pile of rocks and other rubble seems "+
         "upon closer inspection to have originally been a rat's nest that was buried "+
         "by a miniature rockslide in this portion of the cave.  It might be hiding something."
    ]));
    set_search("default","That pile of rubble looks worth further searching.");
    set_search("rubble", (: "search_rubble" :) );
    set_search("pile", (: "search_rubble" :) );
    set_search("rocks", (: "search_rubble" :) );
}
/*
void init(){
    ::init();
	do_random_encounters(({MONDIR+"rat"}),80,10);

}
*/
void search_rubble(string str) {
   if(present("cave kobold")) {
      write("The kobold seems to be in the way of your searching!");
      return;
   }
   if(searched) {
     write("The rubble has been scattered around already.");
     return;
   }
   switch(random(9)) {
      case 0: new(DDOBJ"electrumring")->move(TO);  break;
      case 1: new(DDOBJ"leatherring")->move(TO);  break;
      case 2: new(DDOBJ"lightningring")->move(TO);  break;
      case 3: new(DDOBJ"glassmedallion")->move(TO);  break;
      case 4: new(DDOBJ"rosemedallion")->move(TO);  break;
      case 5: new(DDOBJ"lavamedallion")->move(TO);  break;
      case 6: new(DDOBJ"platinumwand")->move(TO);  break;
      case 7: new(DDOBJ"granitewand")->move(TO);  break;
      case 8: new(DDOBJ"stormwand")->move(TO);  break;
   }
   write("%^BOLD%^You uncover something worthwhile in the rubble.\n");
   tell_room(ETP,"%^BOLD%^"+TPQCN+" uncovers something in the rubble.", TP);
   searched = 1;
   return;
} 

void reset() {
   int active;
   active = has_mobs();
   if(!active){
     if(mons)  mons = ([]);
     pick_critters();
   }
	::reset();
	if(!random(3)) searched = 0;
}

void pick_critters(){
     switch(random(15)){
        case 0..2:  break;
        case 3:  set_monsters( ({MONDIR+"koboldchild"}),({1}));
                 break;
        case 4:  set_monsters( ({MONDIR+"kobold"}),({1}));
                 break;
        case 5:  set_monsters( ({MONDIR+"koboldcaptain"}),({1}));
                 break;
        case 6:  set_monsters( ({MONDIR+"koboldmage"}),({1}));
                 break;
        case 7:  set_monsters( ({MONDIR+"koboldthief"}),({1}));
                 break;
        case 8:  set_monsters( ({MONDIR+"koboldchild",MONDIR+"kobold"}),({1,random(1)+1}));
                 break;
        case 9:  set_monsters( ({MONDIR+"koboldcaptain",MONDIR+"koboldthief"}),({1,1}));
                 break;
        case 10:  set_monsters( ({MONDIR+"koboldchild",MONDIR+"koboldthief"}),({1,random(2)+1}));
                 break;
        case 11:  set_monsters( ({MONDIR+"koboldchild",MONDIR+"koboldthief",MONDIR+"koboldmage"}),({1,1,1}));
                 break;
        case 12:  set_monsters( ({MONDIR+"koboldcaptain",MONDIR+"kobold"}),({1,random(3)+2}));
                 break;
        case 13:  set_monsters( ({MONDIR+"koboldchild"}),({random(3)+2}));
                 break;
        case 14:  set_monsters( ({MONDIR+"koboldmage",MONDIR+"koboldthief"}),({random(2),random(3)}));
                 break;
      }
}