#include <std.h>
#include "../dragon.h";

inherit TVAULT;

int items;

void create() {
items = 1;
   ::create();
   set_long(
      "%^RESET%^This laboratory has many tables covered with"+
      " various sets of beakers, contraptions and cylinders of"+
      " untold substances bubbling forth from them. The room is"+
      " loud from the boiling and popping sounds that emit from"+
      " all around. Vials with lables are stacked in racks on the"+
      " side and a small shelf with smeared books sits on the far"+
      " side of the room. Though it is cluttered, everything seems"+
      " to be kept in a state of repair so as nothing is broken or"+
      " damaged. One table is covered with weapons."
   );
   set_items( ([
      "beakers" : "Sets of glass beakers.",
      "vials" : "These vials are all labeled for the various components used to make whatever is inside of them.",
      "shelf" : "This shelf contains a few smeared tomes inside.",
      "books" : "The books looks like manuals which give directions on how to make various potions. They are incredibly hard to read because they are smeared.",
      "table" : "This table is covered with weapons, some look finer than others.",
   ]) );
   set_exits( ([
      "east" : TOWER+"hall01",
   ]) );
   set_door("oak door",TOWER+"hall01","oak door","tower key");
   set_search("table", (: TO, "searching" :) );
}

void searching() {
object ob;
   if(!items) {
      write("You find nothing else special.");
      return;
   }
   switch(random(4)) {
      case 0:
      write("%^BOLD%^%^RED%^You find a rod!");
      tell_room(ETP,"%^BOLD%^%^RED%^"+TPQCN+" finds a rod!",TP);
      ob = new(OBJ+"flamerod")->move(TO);
      break;
      case 1:
      write("%^BOLD%^%^CYAN%^You find a rod!");
      tell_room(ETP,"%^BOLD%^%^CYAN%^"+TPQCN+" finds a rod!",TP);
      ob = new(OBJ+"frostrod")->move(TO);
      break;
      case 2:
      write("%^BOLD%^%^YELLOW%^You find a rod!");
      tell_room(ETP,"%^BOLD%^%^YELLOW%^"+TPQCN+" finds a rod!",TP);
      ob = new(OBJ+"lightningrod")->move(TO);
      break;
      case 3:
      write("%^BOLD%^%^WHITE%^You find a rod!");
      tell_room(ETP,"%^BOLD%^%^WHITE%^"+TPQCN+" finds a rod!",TP);
      ob = new(OBJ+"stonerod")->move(TO);
      break;
   }
   items = 0;
   return;
}

void reset() {
   ::reset();
   if(!present("apprentice")) {
      new(MON+"apprentice")->move(TO);
      new(MON+"apprentice")->move(TO);
   }
}
