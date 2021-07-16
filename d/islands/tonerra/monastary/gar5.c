//gar5.c

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;

void create(){
   ::create();
   set_terrain(GARDEN);
   set_travel(FOOT_PATH);
   set_short("Center garden");
   set_property("light",2);
   set_property("used sticks",1);

   set_long(
@OLI
   %^BOLD%^%^BLACK%^This is the center room of the garden%^RESET%^
%^RESET%^This is a large area. It's clear of grass, weeds or even twigs.
There is a large %^BOLD%^%^BLACK%^granite %^WHITE%^circle%^RESET%^ embedded in the ground here. In the
center of that circle is another %^BOLD%^%^WHITE%^circle. This is divided by a
%^BOLD%^%^GREEN%^serpentine%^RESET%^ slice down the middle. To the left of the wavy line
the stone is colored all %^BOLD%^%^BLACK%^black%^RESET%^ but for a small circle of %^BOLD%^white%^RESET%^.
The right of the line is %^BOLD%^white%^RESET%^ but for a single %^BOLD%^%^BLACK%^black circle%^RESET%^.
OLI
   );
   set_items(([
      "circle":"This giant religous symbol looks also like a seal.  "
        "You could probably lift it if the monks allowed it."
      ]));

   set_exits(([
      "northwest":MONASTERY +"gar3",
      "southwest":MONASTERY +"gar2",
      "northeast":MONASTERY +"gar4",
      "southeast":MONASTERY +"gar1",
      ]));

}

void reset(){
   ::reset();
   remove_exit("down");
   if(!present("old master")){
      new(MON +"mmonk")->move(TO);
   }
}

void init(){
   ::init();
   add_action("lift","lift");
}


void open_up(object obj)
{
    if(!objectp(obj)) { return; }   
    tell_room(TO,"%^BOLD%^With a groan and a grunt, "+TPQCN+" lifts the great circle "
        "revealing an exit down.",obj);
    tell_object(obj,"%^BOLD%^You slowly lift the circle with effort revealing a downward exit.");
    add_exit(CATACOMBS+"cat1","down");
    return;
}

int quest_check(object obj)
{
    if(!objectp(obj)) { return 0; }
    if(!interactive(obj)) { return 0; }
    if(member_array("Combined wisdom, strength, dexterity and intelligence",(string *)obj->query_mini_quests()) == -1) { return 0; }
    return 1;
}

int lift(string str)
{
   object ob,*inven;
   int i;

   if(!str || str != "circle")
   {
      return notify_fail("Lift what?\n");
   }

   if(ob = present("master monk"))
   {
      if(!quest_check(TP))
      {
        ob->force_me("kill "+TP->query_name());
        return notify_fail("The monk forcibly stops you.\n");
      }
      else
      {
          open_up(TP);
          return 1;
      }
   }

   if(quest_check(TP)) 
   { 
       open_up(TP); 
       return 1;
   }

    if(!"/d/islands/tonerra/monastary/gar1"->query_unlocked()){
      return notify_fail("The power of the monks' intelligence and ingenuity holds the circle firm.\n");
   }
    if(!"/d/islands/tonerra/monastary/gar2"->query_unlocked()){
      return notify_fail("The power of the monks' strength and endurance holds the circle firm.\n");
   }
    if(!"/d/islands/tonerra/monastary/gar3"->query_unlocked()){
      return notify_fail("The power of the monks' wisdom and knowledge holds the circle firm.\n");
   }
    if(!"/d/islands/tonerra/monastary/gar4"->query_unlocked()){
      return notify_fail("The power of the monks' speed and agility holds the circle firm.\n");
   }

    inven = all_living(TO);
    for(i=0;i<sizeof(inven);i++)
    {
        if(objectp(inven[i]))
        {
            inven[i]->set_mini_quest("Combined wisdom, strength, dexterity and "
                "intelligence",2000000,"Combined strength wisdom dexterity and intelligence");
        }
    }
   
   open_up(TP);
   return 1;
}
