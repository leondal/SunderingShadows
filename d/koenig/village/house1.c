//added note to hint for DD quest & different random stuff  *Styx* 11/10/01.  Updated and moved 10/25/03 by Circe

#include <std.h>
#include "../koenig.h"

inherit CROOM;
int items;
int note;

void create() {
    set_repop(75);
    set_monsters( ({KMON"orc",MONDIR"rat"}),({random(2), random(3)}) );
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    items = 3;
    set_property("light",2);
    set_property("indoors",1);
    set_short("A small, quaint house");
    set_name("A small, quaint house");
    set_long(
      "This small, quaint house is nestled among the %^GREEN%^trees %^RESET%^of the Quiet Forest "+
      "in the town of Koenig.  Obviously once home to a family with a small child, "+
      "it now stands as a reminder of some past tragedy.  A large %^ORANGE%^bed frame %^RESET%^marred "+
      "by %^RED%^gory, bloody scratch marks %^RESET%^supports a mattress that has been ripped to "+
      "shreds, leaving %^BOLD%^feathers %^RESET%^stuck to the floor and occasionally floating on a "+
      "breeze through the %^CYAN%^broken windows%^RESET%^.  A small %^ORANGE%^wooden crib %^RESET%^"
      "stands near one window, eerily empty with the small %^BOLD%^%^BLUE%^blue sheets %^RESET%^"+
      "undisturbed.  Most of the wood is burned and blackened, leaving trails of soot and ash "+
      "that has been hardened and rubbed into the wood by the rain and wind.  A large %^ORANGE%^heap "+
      "%^RESET%^of cloth and torn clothes lies in the northeastern corner of the room."+
      "\n"
    );
    set_exits(([
       "west" : VILROOMS"k_road08"
    ] ));
    set_items(([
      ({"furniture","furnishings"}) : "All the furnishings of the room are burned to a crisp.",
      ({"small bed","baby bed","babybed","crib"}) : "The wooden crib standing near the window "+
         "in the northern wall seems strangely undisturbed compared with the chaos around it.  "+
         "The blue sheets are pulled back, and scorch marks climb the legs of the crib, but "+
         "it seems to have remained largely untouched.",
      ({"bed","frame","bed frame"}) : "The large bed frame supports what was once a feather-filled "+
         "mattress.  Now, however, the mattress has been shredded, and the frame itself is marred "+
         "with claw marks interspersed with soot and ash.",
      ({"feather","feathers"}) : "White feathers grayed by ash are stuck to the blood on the floor.  "+
         "Some are also floating on the breeze through the window, the beauty of their movements "+
         "making the carnage of this tragedy surreal.",
      ({"blood","stains","bloodstains","blood stains"}) : "Blood stains, deep red and black, cover "+
         "most every surface of this small house.",
      ({"heap","clothes","cloth","heap of clothes"}) : "It seems everything discarded by those "+
         "who slaughtered this family has been piled in the northeastern corner.  Obviously there "+
         "is nothing there left of value."
    ] ));
    set_search("default","On second thought, you think you catch a glimpse of something hidden within the heap.");
    set_search("clothes", (:TO, "search_heap" :) );
    set_search("heap", (:TO, "search_heap" :) );
    set_listen("default","The occasional scurrying of rats reaches your ears.");
    set_smell("default","The acrid scent of charred wood masks other smells.");
}

void init() {
  ::init();
}

void reset() {
   int active;
   active = has_mobs();  
   if(!active) { 
      if(mons)  mons = ([]);  
      switch(random(4)) {
        case 0..1:  break;
        case 2:  set_monsters( ({KMON"orc"}),({random(2)}) );
                 break;
        case 3:  set_monsters( ({MONDIR"rat", MONDIR"giantrat"}),({random(2), 1}));
                 break;
      }
   }
  ::reset();
  items = random(3);
  note = 0;
}

int search_heap(){
  object ob;
  string temp;
  if(present("monster")){
      tell_object(TP,"You don't really think they're going to let you search that, do you?");
      return 1;
  }
  if(!note) {
    tell_object(TP,"You find a crumpled note under the heap of clothes!\n");
    tell_room(ETP, TPQCN+" uncovers a crumpled note in the heap of clothes.",TP);
    note = 1;
    new("/d/shadow/obj/note_koenig_DD")->move(TO);
    return 1;
  }
  if((items > 0) && (random(20) > 5)) {
    items--;
    switch(random(20)) {
      case 0..3:    temp = "/d/common/obj/misc/bullseye";          break;
      case 4..6:    temp = "/d/common/obj/weapon/flail";           break;
      case 7..9:    temp = "/d/common/obj/armour/leather";         break;
      case 10..12:  temp = "/d/common/obj/armour/splint";          break; 
      case 13..15:  temp = "/d/common/obj/misc/bullseye";          break;
      case 16..18:  temp = "/d/common/obj/weapon/two_hand_sword";  break;
      case 19:      temp = "/d/shadow/obj/clothing/raggedcloak";   break;
    }
    ob = new(temp);
    ob->move(TO);
    tell_object(TP,"You dig out "+ob->query_short()+" from the heap!");
    tell_room(ETP,""+TPQCN+" digs out "+ob->query_short()+" from the heap.",TP);
    return 1;
  }
  if( (items < 1) && !random(3) ) {
    write("It seems there is nothing more to find.");
    return 1;
  }
  write("You find nothing useful.");
  return 1;  
}
