#include <std.h>
#define RANDSTUFF "/d/common/daemon/randstuff_d.c"

inherit "/d/deku/open/cave_r3i.c";
int searched;

void create() {
    ::create();
    set_short("Vexia's Cellar");
    set_long(
@KAYLA
At the bottom of the steps, the corridor opens into a 40'x 30' chamber with
a flat stone ceiling 30' overhead.  The chamber is dimly lit, and dark
shapes hang above you in the air.  The shadowy forms of sacks, barrels and 
crates fill the room, stacked high above your head and spider webs hang 
among them.
KAYLA
    );
     set_listen("default","Loud, raucous singing comes from an exit to the north.");
    set_exits(([
       "north" : "/d/deku/open/guard",
       "up" : "/d/deku/open/cave_r7"
    ] ));
    set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
    set_search("web", (: TO, "search_stuff" :) );
    set_items(([
       "shapes" : "The hanging shapes are skinned animal carcasses suspended "
          "from hooks in the ceiling.",
       "meat" : "The meat looks like it has been salted and left to cure, but "
         "it is spoiled.",
       "sacks" : "The few sacks are filled with breads, all covered with "
         "a disgusting mold.",
       ({"barrels", "crates"}): "They are stacked up precariously and don't "
         "appear to have anything useful or still edible in them.",
       ({"web", "spider web", "webs"}) : "Some of the webs look quite strong and "
         "seem to have pieces of bodies or something encased in them.",
    ] ));
}

void reset() {
  ::reset();
  if(!present("spider") && !random(2))   new("/d/deku/monster/spider")->move(TO);
  if(!present("spider 2") && !random(3)) new("/d/deku/monster/spider")->move(TO);
  searched = 0;
}

int GoThroughDoor() {
  if(present("spider")) {
    tell_room(ETP, "The spider spins a web and blocks the northern exit.");
    return 0;
  }
  return 1;
}

void search_stuff(string str) {
   object ob;
   if(searched) {
     write("Apparently someone searched them recently.  There's nothing to find.");
     return;
   }
   if(random(3)) {
      write("You only find decaying pieces of desiccated bodies this time.");
      tell_room(ETP,""+TPQCN+" searches but only finds pieces of desiccated "
        "bodies.", TP);
      searched = 1;
      return;
   }
   switch(random(8)) {
      case 0: RANDSTUFF->find_stuff(TO,"component");             break;
      case 1..2: RANDSTUFF->find_stuff(TO,"kit", random(10)+5);  break;
      case 3: RANDSTUFF->find_stuff(TO,"stuff",1);               break;
      case 4..6:        
        ob = new("/d/magic/scroll");
        ob->set_spell(random(4)+1);        //no break is intentional
      case 7: 
        RANDSTUFF->find_stuff(TO,"coins", random(200)+300);
        if(!random(2)) { 
          tell_room(ETP,"%^BOLD%^%^RED%^Spiders swarm out from the shadows!!!\n");
          new("/d/deku/monster/spider.c")->move(TO); 
          new("/d/deku/monster/spider.c")->move(TO); 
          new("/d/deku/monster/spider.c")->move(TO); 
          if(!random(3))   new("/d/deku/monster/spider.c")->move(TO); 
        }
        break;
   }
   write("%^BOLD%^Something falls out of one of the web casings as you search "
      "the desiccated bodies.");
   tell_room(ETP,"%^BOLD%^Something falls out of one of the web casings "
      "as "+TPQCN+" searches the desiccated bodies in them.", TP);
   searched = 1;
   return;
} 
