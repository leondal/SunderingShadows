#include <std.h>
#include "../dragon.h";

inherit BTOWN;
int items;

void create() {
items = 1;
   ::create();
   set_property("light",0);
   set_property("indoors",1);
   set_short("Ruined building");
   set_long(
      "%^BOLD%^%^BLACK%^This is one of the many buildings destroyed beyond any recognition"+
      " in the town of %^RED%^Sanctuary%^BLACK%^."+
      " The area is covered in rubble from decrepit walls and pieces of the ceiling that"+
      " have caved in on the structure. Whatever happened here must have been horrible."
   );
   set_exits(([
      "north" : TOWN+"roadSW2"
   ] ));
   set_items(([
      "rubble" : "There are rocks and chipped stones everywhere."
   ] ));
   set_search("default","Something catches your eye from within the rubble.");
   set_search("rubble",(: TO, "searching" :) );
}

void searching() {
   object ob;
   if(!items) {
      write("It appears someone was here before you.");
      return;
   }
   switch(random(5)){
      case 0..3:
         ob = new("/std/obj/coins");
         ob->set_money("gold", random(1400)+300);
         ob->move(TO);
         write("You search through the rubble and round up a handful of gold.");
         tell_room(TO,TPQCN+" searches through the rubble and finds some gold.", TP);
         break;
      case 4:   
          write("You find a scroll in the pile of bones!");
          tell_room(TO,""+TPQCN+" finds a scroll in the pile of bones.",TP); 
          ob = new("/d/magic/scroll");
          ob->set_spell(5);
          ob->move(TO);
          break;
        }       
        items = 0;
        return;
          
}
void reset()
{
   ::reset();
   if(random(10) < 4)
      items = 1;
}
