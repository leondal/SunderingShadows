//Octothorpe (12/30/16)
//Shadow, Sewer Inherit

#include <std.h>
#include "../defs.h"
inherit CROOM;
int searched;

void create(){
      switch(random(15)){
         case 0..5:
            set_monsters(({MON"rat.c"}),({2}));
         break;
         case 6..10:
            set_monsters(({MON"snake.c"}),({1}));
         break;
      }
   set_repop(40);
   
   ::create();
   set_property("indoors",1);
   set_property("light",0);
   set_travel(DECAYED_FLOOR);
   set_terrain(BUILT_TUNNEL);
   set_climate("temperate");
   set_name("Inside the fetid sewers below Shadow");
   set_short("%^BLUE%^Inside the f%^GREEN%^e%^BLUE%^t%^GREEN%^i"+
      "%^BLUE%^d sewers below %^BOLD%^%^BLACK%^Shadow%^RESET%^");
   set_long("%^BLUE%^Inside the f%^GREEN%^e%^BLUE%^t%^GREEN%^i"+
      "%^BLUE%^d sewers below %^BOLD%^%^BLACK%^Shadow%^RESET%^\n%^ORANGE%^This %^BOLD%^%^BLACK%^dank tunnel %^RESET%^%^ORANGE%^is "+ 
   "constructed out of ancient stout bricks that are covered in a patina of "+ 
   "%^BOLD%^%^GREEN%^f%^RESET%^%^GREEN%^i%^BOLD%^l%^BLACK%^t%^RESET%^%^GREEN%^h "+ 
   "%^ORANGE%^and %^BOLD%^%^GREEN%^sl%^BLACK%^i%^RESET%^%^GREEN%^m%^BOLD%^e%^RESET%^%^ORANGE%^. "+ 
   "The tunnel is roughly half-circular in shape, measuring twenty feet across, "+ 
   "and almost twenty feet high at its apex. There are five foot wide walkways "+ 
   "on either side, allowing access all the way down the tunnel. Running down "+ 
   "the middle of the tunnel in between the walkways, is a %^BOLD%^%^BLACK%^culvert "+ 
   "%^RESET%^%^ORANGE%^containing the city's "+ 
   "%^BOLD%^%^BLACK%^w%^RESET%^%^ORANGE%^a%^GREEN%^s%^BOLD%^%^BLACK%^tewa%^RESET%^%^GREEN%^t%^ORANGE%^e%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^, "+ 
   "and who knows what else. Periodically, small pipes jut out of the walls of the tunnel "+ 
   "and hang over the edge of the culvert, allowing wastewater to drain. Access over "+ 
   "the culvert is offered by %^WHITE%^bridges %^ORANGE%^constructed "+ 
   "haphazardly out of wooden boards.%^WHITE%^\n");
   set_smell("default","You smell the disgusting confluence of refuse "+
      "and excrement wafting all about you.");
   set_listen("default","You hear flowing water echoing throughout "+
      "the tunnel.");
   set_items(([
      ({"tunnel","sewer","walls","bricks"}) : "%^RESET%^%^GREEN%^Layer upon layer of %^BOLD%^filth%^RESET%^%^GREEN%^ "+
	  "and %^BOLD%^slime%^RESET%^%^GREEN%^ cover the walls, the scent of it "+ 
	  "purely putrid and nauseating.",
      ({"culvert","wastewater","water"}) : "%^BOLD%^%^BLACK%^You are in the bowels of sewer tunnels beneath a bustling city. "+
	  "It smells like crap, literally. The %^RESET%^%^ORANGE%^'water'%^BOLD%^%^BLACK%^ is everything you imagined it would be.%^RESET%^",
      ({"bridges","bridge","wooden boards","boards"}) : "%^RESET%^%^ORANGE%^Caution is advised if you plan on trying to cross this precarious planking.%^RESET%^",
      ({"walkway","walkways"}) : "%^RESET%^%^GREEN%^The walkways are terribly slick and every step is a step closer to finding yourself carried away in decades worth of sewerage.%^RESET%^",
   ]));   
    set_search("default", "%^ORANGE%^Perhaps you might try searching a bit in the raw sewage?%^RESET%^");
    set_search("sewage", (: TO, "search_pile" :) );
    set_search("filth", (: TO, "search_pile" :) );
    set_search("water", (: TO, "search_pile" :) );
    set_search("pipes", (: TO, "search_pile" :) );
}

void search_pile() {
   object ob;
   if(searched <= 0) {               
	tell_object(TP,"It looks like this area has been searched already.");
      return ;
   }
   if (searched == 1) {  
      switch(random(99)){
         case 0..3:
            write("You found a ratty old headband in the muck!\n");
            tell_room(TO,""+TPQCN+" pulls and old headband from the muck.", TP);
            new(OBJ"headband.c")->move(TO);
            searched = 0;
            break;
         case 4..7:
            write("You found a dented old top hat in the muck!\n");
            tell_room(TO,""+TPQCN+" pulls and old dented hat from the muck.", TP);
			new(OBJ"hat.c")->move(TO);
            searched = 0;
            break;
		 case 8..11:
            write("You found a pretty string of pearls in the muck!\n");
            tell_room(TO,""+TPQCN+" pulls a pretty string of pearls from the muck.", TP);
			new(OBJ"pearls.c")->move(TO);
            searched = 0;
            break;
		 case 12..15:
            write("You found a nice cravat in the muck!\n");
            tell_room(TO,""+TPQCN+" pulls a nice cravat from the muck.", TP);
			new(OBJ"cravat.c")->move(TO);
            searched = 0;
            break;
		 case 16..19:
            write("You found an old bow in the muck!\n");
            tell_room(TO,""+TPQCN+" pulls an old bow from the muck.", TP);
			new(OBJ"agedbow.c")->move(TO);
            searched = 0;
            break;
		 case 20..24:
            write("You found a leather belt in the muck!\n");
            tell_room(TO,""+TPQCN+" pulls a leather belt from the muck.", TP);
			new(OBJ"belt.c")->move(TO);
            searched = 0;
            break;
         case 25..45:
            write("The water boils and bubbles as a swarm of leeches rises to the surface!");
            new(MON"leeches.c")->move(TO);
            searched = 0;
            break;
		 case 46..55:
			write("You dig out some filth-covered coins!");
			tell_room(TO,""+TPQCN+" digs out some filthy coins.",TP);
			ob = new("/std/obj/coins");
			ob->set_money("gold", random(500)+500);
			ob->move(TO);
			searched = 0;
			break;
		 case 56..60:
			write("You find a curious vial.");
			tell_room(TO,""+TPQCN+" finds a vial.",TP);
			ob = new("d/common/obj/potion/cure_poison.c");
			ob->move(TO);
			searched = 0;
			break;
         case 61..99:
            write("You don't seem to find anything.");
            tell_room(TO, ""+TPQCN+" doesn't seem to find anything.", TP);
            searched = 0;
            break;
      }
   }
}

void reset() {
   ::reset();
   searched = 1 ;
}