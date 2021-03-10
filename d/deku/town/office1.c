#include <std.h>
inherit "/std/room";
int count;      
int count2;
      
void create() {
  ::create();
  set_light(2);
  set_indoors(1);
  set_terrain(WOOD_BUILDING);
  set_travel(DIRT_ROAD);
  set_short("Exchange Teller's office");
  set_long(
@OLI
This is the office of the exchange teller, the person who
is in charge of pricing the various resources worth.  His
office is cluttered with papers.  There is a large, ornately
carved desk in the middle of the room and is complimented
nicely by the painting behind the desk.
OLI
     );
 set_smell("default","This room smells as if everything has been just polished.");
  set_exits(([ "south" : "/d/deku/town/exchange" ] ));
      set_items(([
       "desk":"This is a large desk.  It would need to be searched to find anything.",
       "painting":"This painting is of a majestic woodland scene.",
          ] ));
  }
 void reset(){
	object ob;
   ::reset();
	if(ob=present("voucher",TO)) ob->remove();
}
void init(){
	::init();
	add_action("search_room","search");
}
int search_room(string str){
	switch (str) {
                  case "desk":
		if(count!=1){
		write("You search the desk thoroughly.");
		write("At last your efforts are rewarded.");
		write("You find a voucher for ores of some type.");
		tell_room(ETO,TPQCN+" finds a voucher.",TP);
		new("/d/tharis/obj/voucher.c")->move(TO);
 		count+=1;
		return 1;
		}
		else {
		write("You find nothing.");
		return 1;
		}
		break;
 		case "painting":
		if(count2!=1){
		write("The painting moves easily when touched.");
		write("Behind it you discover a small hole, filled with silver.");
		TP->add_money("silver",30);
		count2 = 1;
		return 1;
		}
		else {
		write("You find nothing.");
		return 1;
		}
		break;
		default:
		return 0;
		break;
	}
}
