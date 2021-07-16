#include <std.h>
#include "/d/islands/tonerra/areadefs.h"
inherit ROOM;

int corpse, pushed;

void create(){
  ::create();
  set_indoors(1);
  set_light(1);
  set_property("no teleport",1);
  set_property("no pocket space",1);
  set_property("used sticks",1);
  set_short("The God's resting place");
  set_long(
@DESC
   %^BOLD%^%^RED%^The God's resting place%^RESET%^
In the middle of this large room is a stone altar.
On the altar rests a large, wrapped corpse. You can see the
the care taken with this room. Incense burns, and some torches
light the area dimly.
DESC
  );
  set_listen("default","Silence");
  set_smell("default","Nothing, your senses are strangly dead");
  set_exits(([
    "out":LAVA+"temple6",
  ]));
  set_items(([
   "corpse":"This is a finely wrapped corpse. It's preserved marvelously. It's decorated completey except for the face, looking as if it should have a mask or something.",
   "altar":"This is a stone altar, plainly made but bearing an inscription. You also notice a small draft wafting up from cracks below the altar.",
   "inscription":"It reads: The mask must be worn, the mask has the power, place the mask."
   ]));
}

void init(){
   ::init();
   add_action("push","push");
   add_action("place","place");
}


int place(string str){
   object ob;
   string temp;

   if(!str) return notify_fail("place what where?\n");

   if(sscanf(str,"%s on corpse", temp) != 1){
      if(sscanf(str,"%s on face", temp) != 1){
	 return notify_fail("Place what on where?\n");
      }
   }

   if(strsrch(temp,"mask") == -1){
      return notify_fail("Place what on where?\n");
   }

   if(!ob = present("mask of Ibrandul",TP)){
      return notify_fail("You don't have that\n");
   }
   if(corpse){
      return notify_fail("No corpse there.\n");
   }
   ob->remove();
   tell_room(TO,"%^RED%^"+TPQCN+" carefully places the mask on the corpse.",TP);
   write("%^RED%^You carefully place the mask on the corpse.");
   corpse = 1;
   call_out("do_it",5);
   return 1;
}


void do_it(){
   tell_room(TO,"%^YELLOW%^Energy crease through the room.");
   tell_room(TO,"%^BLUE%^The mask and paintings join and then start to move.");
   call_out("do_it2",5);

}

void do_it2(){
   tell_room(TO,"%^RED%^There was movement, The corpse is moving.");
   call_out("do_it3",5);
}

void do_it3(){
   tell_room(TO,"%^GREEN%^The exit behind you slams shut");
   remove_exit("out");
   "/d/islands/tonerra/lava/temple6"->remove_exit("deeper");
   call_out("do_it4",5);

   set_post_exit_functions(({"passage"}),({"quest"}));
}

void do_it4(){
   object *inven;
   int i,j;
   corpse = 2;
   tell_room(TO,"%^RED%^You turn back from the door to realize you are now facing Ibrandul, risen from Shar's failed attempt on his life.");
   inven = all_living(TO);
   j = sizeof(inven);
   for(i=0;i<j;i++){
      if(!objectp(inven[i]))
	 continue;
      if(!userp(inven[i]))
	 continue;
      inven[i]->set_mini_quest("Solved the mystery of Ibrandul",500000,"Solved the mystery of Ibrandul");
   }
   new(MON+"ibrandul")->move(TO);
}

void reset(){
    object *pplz, myroom;
    int flag,i;
    ::reset();
    flag = 0;
    pplz = all_living(TO);
    if(pplz) {
      for(i = 0;i<sizeof(pplz);i++) {
        if(userp(pplz[i]) && !pplz[i]->query_true_invis()) flag = 1;
      }
    }
    myroom = find_object_or_load(LAVA+"temple8");
    pplz = all_living(myroom);
    if(pplz) {
      for(i = 0;i<sizeof(pplz);i++) {
        if(userp(pplz[i]) && !pplz[i]->query_true_invis()) flag = 1;
      }
    }
    if(flag) return; //there are players in the temple room or loot room
    if(!present("ibrandul") && corpse) {
      add_exit(LAVA+"temple6","out");
      "/d/islands/tonerra/lava/temple6"->add_exit(LAVA+"temple7","deeper");
      "/d/islands/tonerra/lava/temple6"->reset_corpses();
      remove_exit("passage");
    }
    corpse = 0;
    pushed = 0;
}

int push(string str){
   if(!str || (str != "alter" && str != "altar"))
      return notify_fail("Push what?\n");

   if(corpse != 2){
      return notify_fail("Not with that corpse up there.\n");
   }

   if(pushed){
      return notify_fail("It appears that its already pushed.\n");

   }
   if(present("ibrandul")){
      return notify_fail("Worry about the god trying to disect you first.\n");
   }

   tell_room(TO,"The altar move easily revealing a passage out.");
   add_exit(LAVA+"temple8","passage");
   pushed = 1;
   return 1;
}

int quest()
{
    if(!objectp(TP)) { return 0; }
    if(!pointerp(TP->query_quests())) { return 0; }

   if(member_array("Finished Shar's failed Deed",TP->query_quests()) == -1){

      TP->set_quest("Finished Shar's failed Deed");
      TP->fix_exp(21000000,TO);
   }
   return 1;
}
