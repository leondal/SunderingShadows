#include <std.h>
#include "../../gantioch.h"
#include <daemons.h>
#include "/d/common/common.h"

inherit ROOM;

void capt(object targ, int num);
int pile;
int step1;

void create(){
    pile = 1;
    ::create();

    set_name("treasureroom");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_short("%^BOLD%^%^YELLOW%^Inside a Treasure Room%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This fairly small chamber looks very non-descript for the most part"+
             " with nothing on the ceiling or wall. The ground looks well-maintained and this is obviously"+
             " a place where people do not move in and out of too often."+
             " \n\n%^BOLD%^%^YELLOW%^In the center of the room is a pile of %^BOLD%^%^CYAN%^treasure"+
             " %^BOLD%^%^YELLOW%^that has various things in it. Perhaps if you search the %^BOLD%^%^RED%^pile %^BOLD%^%^YELLOW%^of treasure"+
             " you may find something worth all of this trouble?");

    set_smell("default","\n%^BOLD%^%^BLACK%^The various items can be smelt here.%^RESET%^");
    set_listen("default","%^RESET%^%^RED%^You hear occasional yips and barks from back down hall.%^RESET%^");
    set_search("pile",(:TO,"searching":));
    set_exits(([
		"west" : MOUND"mound14",
	]));
    set_items(([
      "treasure" : "%^RESET%^%^ORANGE%^This pile of treasure looks like a fairly sizable haul for this clan of gnolls.",
]) );
}
void searching() {
   object ob;
if(!pile) {
      write("%^BOLD%^%^BLACK%^You realize everything has been rummaged through.");
      return;
   }
   else{
 write("%^BOLD%^%^YELLOW%^You search through the pile excitedly!");
         tell_room(TO,"%^BOLD%^%^YELLOW%^"+TPQCN+" searches through the pile of treasure!%^RESET%^",TP);
         ob = new("/std/obj/coins");
         ob->set_money("gold", random(10000)+5000);
         ob->move(TO);
         ob = new("/std/obj/coins");
         ob->set_money("platinum", random(1000)+1000);
         ob->move(TO);
         ob = new("/std/obj/coins");
         ob->set_money("copper", random(30000)+5000);
         ob->move(TO);
         ob = new("/std/obj/coins");
         ob->set_money("silver", random(30000)+5000);
         ob->move(TO);
         ob = new(OBJ+"widebrimgray");
         ob->move(TO);
         RANDTREAS->find_stuff(TO,"highscroll",1);
         RANDTREAS->find_stuff(TO,"highscroll",1);
         RANDTREAS->find_stuff(TO,"highscroll",1);
         RANDTREAS->find_stuff(TO,"midscroll",1);
         RANDTREAS->find_stuff(TO,"midscroll",1);
         RANDTREAS->find_stuff(TO,"midscroll",1);
         RANDTREAS->find_stuff(TO,"kit",2);
         RANDTREAS->find_stuff(TO,"stuff",1);
         RANDTREAS->find_stuff(TO,"stuff",1);
         RANDTREAS->find_stuff(TO,"stuff",1);
         RANDTREAS->find_stuff(TO,"stuff",1);
      }
      pile = 0;
}
/*
void init(){
  ::init();
  call_out("capt",10,TP,0);
}
void capt(object targ, int num)
{
  object ob;

  if(!objectp(TP)) { return; }
  if(!objectp(targ)) { return; }
  if (step1 == 1){return; }
  //if(member_array("Rescued the Missing Wife",TP->query_mini_quests())!=-1) return;

 // step1=1;

  switch(num){
  case(0):
  tell_object(targ,
  "\n\n\n"
  "%^BOLD%^%^%^WHITE%^Your feel the sense of being groped at and pulled around. Your vision comes to and you see gnolls tossing your equipment around to each other. You turn your head slightly and see the %^RESET%^%^RED%^evil %^BOLD%^%^WHITE%^grin of a gnoll, looking at you. Everything goes %^BOLD%^%^BLACK%^black%^BOLD%^%^WHITE%^."
  );
  break;
  case(1):
  tell_object(targ,
  "\n\n\n"
  "%^BOLD%^%^WHITE%^You feel yourself getting tossed to the side and moved dragged by another gnoll. You look around briefly to see your things %^BOLD%^%^RED%^argued %^BOLD%^%^WHITE%^over. You feel a claw grab you and everything goes %^BOLD%^%^BLACK%^black%^BOLD%^%^WHITE%^."
  );
  break;
  case(2):
  TO->force_me("drop all");
  tell_object(targ,
  "\n\n\n"
  "%^BOLD%^%^GREEN%^You hear a large %^BOLD%^%^YELLOW%^CLANG %^BOLD%^%^GREEN%^jarring you, as if a door of some sort was shut .... everything %^BOLD%^%^BLACK%^fades%^BOLD%^%^GREEN%^..."
  );
  break;
  case(3):
  tell_object(targ,
  "\n\n\n"
  "%^BOLD%^%^BLUE%^You look around groggily and see that you are stuck in a %^BOLD%^%^RED%^cage%^BOLD%^%^BLUE%^. You look around and see others in the cages around you...what is this place?"
  );
  break;
  case(4):
  tell_object(targ,
  "\n\n\n"
  "%^BOLD%^%^WHITE%^A male elf in %^BOLD%^%^BLACK%^rags %^BOLD%^%^WHITE%^walks over and begins messing with the lock on your cage. '%^BOLD%^%^YELLOW%^It's time for you to prepare...I hope you are ready for what is coming...'"
  );
  break;
  case(5):
  tell_object(targ,
  "\n\n\n"
  "%^BOLD%^%^RED%^You hear the %^BOLD%^%^CYAN%^clink %^BOLD%^%^RED%^as the cage is unlocked. You stumble out of the cage, looking about and realize there are many things strung about on the floor..."
  );
  /*TP->add_money("gold",-2000000);
  TP->add_money("platinum",-2000000);
  TP->add_money("electrum",-2000000);
  TP->add_money("silver",-2000000);
  TP->add_money("copper",-2000000);
  if(TP->query_invis(1)) TP->set_invis(0);
  TP->move(MOUND"mound13");
 return;

  if(!random(1)){
  object *capture;
  int i,j;
  capture=all_living(TO);
  capture=filter_array(capture, "is_non_immortal",FILTERS_D);
  j=sizeof(capture);
  for(i=0;i<j;i++){
  if((!TP->query_paralyzed()) || (!TP->query_bound()) || (!TP->query_unconscious())){
  if((int)capture[i]->query_highest_level()>10){
  capture[i]->force_me("drop all");
  capture[i]->add_money("gold",-2000000);
  capture[i]->add_money("platinum",-2000000);
  capture[i]->add_money("electrum",-2000000);
  capture[i]->add_money("silver",-2000000);
  capture[i]->add_money("copper",-2000000);
  if(TP->query_invis(1)) TP->set_invis(0);
  capture[i]->move(MOUND"mound13");
  //step1==1;
}}}
 return;}

  else{}
  num++;
  if(!objectp(targ)) { return; }
  if(!present(targ,TO)) return;
  call_out("capt",10,targ,num);
 return;
}



}
*/
