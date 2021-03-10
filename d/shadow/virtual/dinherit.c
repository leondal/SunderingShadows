//dinherit.c

#include <std.h>

inherit ROOM;

void pop_critters();
void check_critters();
int smallmax;

void create(){
   ::create();
   set_name("Underground ruins");
   set_property("no teleport",1);
   set_property("indoors",1);
   set_property("no sticks",1);
   set_terrain(BUILT_CAVE);
   set_travel(DIRT_ROAD);
}

void reset(){
   int i,j;
   ::reset();
   if(base_name(TO) == "/d/shadow/virtual/dinherit")  check_critters();
   if(present("small thing"))                         return;
   if(smallmax)                                       return;
   if(!random(15))                                    pop_critters();
}

void check_critters() {
   if(sizeof(children("/d/shadow/virtual/smallu")) > 50)
      smallmax = 1;
}

void pop_critters() {
    int i, j;
    i = random(5)-0;
    for(j=0;j<i;j++){
       new("/d/shadow/virtual/mon/smallu")->move(TO);
    } 
}

void init(){
   ::init();

   if(TP->query_true_invis()) return;
   if(!interactive(TP)) return;
// This is just unfair to keep players out. They can get headaches like the rest :P
/*   if((int)TP->query_size() == 3){
      write("You simply don't fit in there!");
      TP->move(TP->query_last_location());
   } */
   if((int)TP->query_size() > 1){
      write("You knock your head on the ceiling here.");
        tell_room(TO,TPQCN+" knocks "+TP->query_possessive()+" head on the ceiling.",TP);
      TP->do_damage("torso",roll_dice(1,4));
   }
   TP->add_attacker(TO);
   TP->continue_attack();
   TP->remove_attacker(TO);
}
