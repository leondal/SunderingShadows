#include <std.h>
#include "../dragon.h";

inherit BTOWER;

int items;

void create() {
items = 1;
   ::create();
   set_long(
      "%^RESET%^This large library has obviously been well taken care of"+
      " because of the care that has gone into maintaining its cleanliness."+
      " Small tables sit inside that each have a small stack of papers, obviously"+
      " things that the owners of the tower were working on. Bookshelves cover each"+
      " wall of this room and the door into it has been carved out of one, leaving"+
      " books surrounding the door frame. A massive fireplace sits on the far end"+
      " of the room that lets off a warm glow."
   );
   set_items( ([
      "books" : "Many titles of almost every subject matter. This is a fine collection.",
      "tables" : "Each table has one small chair next to it, they are obviously for studying.",
      "stacks" : "Various papers and such. Nothing out of the ordinary, but perhaps if you look closer.",
      "fireplace" : "The marble fireplace seems to be burning wood constantly, probably controlled my magic."  
   ]) );
   set_exits( ([
      "west" : TOWER+"lobby",
   ]) );
   set_search("stacks", (: TO, "searching" :) );
}

void searching () {
object ob;
   if(!items) {
      write("You find nothing.");
      return;
   }
   if(present("everardus")) {
      write("The mage is too close to the stacks for you to look without being seen.");
      return;
   }
   write("%^BOLD%^%^YELLOW%^You find a collection of scrolls!");
   tell_room(ETP,"%^BOLD%^%^YELLOW%^"+TPQCN+" finds several scrolls in the stack.",TP);
   ob = new("/d/magic/scroll");
   ob->set_spell(9);
   ob->move(TO);
   ob = new("/d/magic/scroll");
   ob->set_spell(9);
   ob->move(TO);
   ob = new("/d/magic/scroll");
   ob->set_spell(9);
   ob->move(TO);
   ob = new("/d/magic/scroll");
   ob->set_spell(8);
   ob->move(TO);
   ob = new("/d/magic/scroll");
   ob->set_spell(8);
   ob->move(TO);
   items = 0;
   return;
}

void reset() {
   ::reset();
   if(!present("everardus")) {
      new(MON+"everardus")->move(TO);
   }
}
