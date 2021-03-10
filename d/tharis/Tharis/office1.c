#include <std.h>
inherit ROOM;
int count;      
int count2;
      
void create() {
  ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
   set_property("no teleport",1);
   set_light(2);
   set_indoors(1);
   set_short("The office of the Exchanger general");
   set_long(
@OLI
	This is the office of the exchanger general -- the 
person incharge of the prices various ores are worth. His 
office is cluttered. He is not here presently. You wonder 
if he ever comes in here. There is a large, well-carved desk
in the middle of the room. It is complimented nicely by the 
painting behind the desk. The desk is cluttered with papers.
OLI
     );
   set_smell("default","This room smells as if everything had been just polished.");
   set_listen("default"," ");
   set_search("desk",(:this_object(),"search_desk":));
   set_search("painting",(:this_object(),"search_painting":));
   set_exits(([ "north" : "/d/tharis/Tharis/exchange" ] ));
   set_items(([
	       "desk":"This is a large desk. It would need to be searched to find anything.",
	       "painting":"This painting is of a magestic woodland scene.",
	       ] ));
 }
void reset(){
  object ob;
  ::reset();
  if(ob=present("voucher",TO)) ob->remove();
}

string search_desk(){

    if(count!=1){
      write("You search the desk thoroughly.");
      write("At last your efforts are rewarded.");
      write("You find a voucher for ores of some type.");
      tell_room(environment(TO),TPQCN+" finds a voucher.",TP);
      new("/d/tharis/obj/voucher.c")->move(TO);
      count+=1;
      return " ";
    }
    else {
      write("You find nothing.");
      return " ";
    }
   return " ";
  }
string search_painting() {

    if(count2!=1){
      write("The painting moves easily when touched.");
      write("Behind it you discover a small hole, filled with silver.");
      TP->add_money("silver",30);
      count2 = 1;
      return " ";
    }
    else {
      write("You find nothing.");
      return " ";
    }
}
