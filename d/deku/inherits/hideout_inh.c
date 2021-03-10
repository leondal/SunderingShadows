#include <std.h>
#include "deku.h"
#define SD "/d/common/daemon/randstuff_d"
inherit VAULT;
int searched;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_terrain(WOOD_BUILDING);
    set_travel(DECAYED_FLOOR);
    set_name("A wooden room");
    set_short("A wooden room");
    
    set_long("%^YELLOW%^You find yourself in a room that is almost "+
    "completely square and made entirely from slabs of %^RED%^crimson "+
    "stained %^BOLD%^%^GREEN%^oak%^YELLOW%^.  The %^RED%^floor"+
    "%^YELLOW%^ of this room is littered with various types of "+
    "%^RED%^debris%^YELLOW%^ and a thick layer of %^BOLD%^%^WHITE%^"+
    "dust%^YELLOW%^ has settled over it, splotched with various "+
    "%^BLUE%^tracks.%^YELLOW%^  The room is exceptionally well lit, "+
    "thanks entirely to the %^RESET%^torches%^YELLOW%^ that are held "+
    "by %^BOLD%^%^WHITE%^silver brackets%^YELLOW%^ in each "+
    "%^RED%^corner%^YELLOW%^.  The %^RED%^ceiling%^YELLOW%^ overhead "+
    "is some dozen feet up and does not appear to be very sturdy."+
    "%^RESET%^");
    
    set_items(([
    ({"oak","stained oak","crimson stained oak"}) : "%^BOLD%^%^GREEN%^"+
    "The thick oak boards that have been carefully pieced together to "+
    "construct this room are stained with %^RED%^crimson%^BOLD%^"+
    "%^GREEN%^.%^RESET%^",
    ({"stains","crimson stains"}) : "%^RED%^These stains adorn "+
    "the floor, walls, and even ceiling of this room.  They could "+
    "very well be the last remaining evidence of some massive "+
    "slaughter.%^RESET%^",
    ({"floor","oak floor","stained floor"}) : "%^RED%^The floor of "+
    "this room is made from the same solid and crimson stained oak "+
    "that constructs the rest of this room.  However, the floor "+
    "is littered with debris and covered with a thick layer of dust "+
    "that is splotched with various tracks.%^RESET%^",
    ({"tracks","prints"}) : "%^BLUE%^These tracks splotch the "+
    "thick layer of dust that has settled over the floor.  They "+
    "appear to be from average sized creatures with covered feet."+
    "%^RESET%^",
    ({"dust","thick dust"}) : "%^BOLD%^%^WHITE%^This thick layer of "+
    "dust has settled uneasily over the floor.  It is splotched by "+
    "many tracks that suggest frequent movement of some sort in and "+
    "through this room.%^RESET%^",
    "ceiling" : "%^RED%^The ceiling here is some dozen feet overhead "+
    "and made from the same crimson stained oak.  Unfortunately, "+
    "unlike the rest of the room, it does not appear to be very "+
    "sturdy.%^RESET%^",
    ({"torch","torches"}) : "One of these torches is held by a "+
    "%^BOLD%^%^WHITE%^silver bracket%^RESET%^ in each corner of the "+
    "room.",
    ({"brackets","silver brackets","bracket",
    "silver bracket"}) : "%^BOLD%^%^WHITE%^One of these has been "+
    "attached half-way up the wall at each corner of the room.  Each "+
    "now proudly displays a lit torch that bathes this room with its "+
    "light.%^RESET%^",
    ({"corner","corners"}) : "%^RED%^A silver bracket has been "+
    "attached half-way up the wall at each corner of the room.  A lit "+
    "torch rests in each bracket, bathing the room with light."+
    "%^RESET%^",
    "debris" : "%^RED%^The debris that litter this floor are a mixture "+
    "of bones, wood, leaves, and some torn articles of clothing.  "+
    "In some places the piles have gathered enough so that they might "+
    "actually conceal something of value.%^RESET%^",
    ]));
    set_search("default","%^RED%^The debris could easily conceal "+
    "something of value.%^RESET%^");
    set_search("debris",(:TO,"debris_search":));
    set_listen("default","The floor above creaks and sounds echo off the walls.");
    set_smell("default","You smell leather and lantern oil.");
}

void reset() {
  int i;
  ::reset();
  if(!present("bandit") && random(5) >= 3 && base_name(TO) != "/d/deku/inherits/hideout_inh") {
    for(i = 0;i < random(2) + 1;i++) {
      new("/d/deku/monster/bandit.c")->move(TO);
    }
  }
  if(random(20) >= 15) {
    searched = 0;
   }
}

void caught_searching(object targ, object ob) {
  if(!objectp(targ) || !objectp(ob)) return;
  tell_object(targ,"You attempt to sort through the debris but "+
   "catch the attention of one the bandits instead!");
  
  tell_room(TO,targ->QCN+" looks carefully at the debris and catches "+
      "the attention of one of the bandits!%^RESET%^",targ);
  
  ob->force_me("say what do you think you're doing?? DIE YOU SCUM!");
  ob->force_me("stab "+targ->query_name());
  ob->force_me("scramble");
 
}

int debris_search() {
  object ob;

  if(ob = present("bandit")) {
   if(present(ob)) {
    if(!TP->query_invis()) {
       caught_searching(TP,ob);
       return 1;
     }
     if(TP->query_invis() && !TP->query_true_invis() && !random(30)) {
       caught_searching(TP,ob);
       return 1;
     }
   }       
  }
  
  tell_room(TO,TPQCN+"%^RED%^ digs carefully through a pile of "+
  "debris.%^RESET%^", TP);
  if(searched == 0) {
     if(random(100) >= 92) {
        tell_object(TP,"%^RED%^You dig through the debris and uncover "+
        "something of value!%^RESET%^");
        searched = 1;
        SD->find_stuff(TO,"random");
        return 1;
     }
     tell_object(TP,"%^RED%^You dig through the debris but find "+
     "nothing of interest.%^RESET%^");
     searched = 1;
     return 1;
   }
   tell_object(TP,"%^RED%^You dig through the debris but find nothing "+
   "of interest.%^RESET%^");
   return 1;
}

  
