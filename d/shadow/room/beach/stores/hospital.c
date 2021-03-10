

#include <std.h>
#include <objects.h>
#include <money.h>

inherit ROOM;


void create() 
{
  room::create();
  set_light(2);
  set_property("no attack", 1);
  set_indoors(1);
  set_short("Beach Hospital");
  set_long("You are in a large hospital full of clerics.  "
           "There are many things around the room as you start to open your eyes.  "
           "The hospital is very clean and well lit.  "
           "Many people are pacing around the room.  "
           "A list is hanging on the wall.");
  set_smell("default", "You smell the sent of potions "
                       "in the air.");
  set_listen("default", "You hear people sighing after they are helped "
                        "by doctors.");
  set_items( ([ "list" : "Hospital services: \n"
                         "cl : cure light wounds for 20 gold \n"
                         "cs : cure serious wounds for 45 gold \n"
                         "cc : cure critical wounds for 100 gold \n"
                         "np : neutralize all poison for 150 gold \n"
                        "bp : buy a healing potion for 30 gold \n"
           ]) );
  set_exits( ([
	"out" : "/d/shadow/room/beach/park1"
           ] ));
}


void init() 
{
  ::init();
  add_action("cure_light", "cl");
  add_action("cure_serious", "cs");
  add_action("cure_critical", "cc");
  add_action("neut_poison", "np");
  add_action("buy_potion", "bp");
}


void reset()
{
  ::reset();
    if(!present("doctor")) 
      new("/d/shadow/room/beach/mon/doctor.c")->move(TO);
}


void cure_light(string str) 
{
  if((int)TP->query_money("gold") < 20) 
   {
     tell_object(TP, "You don't have enough money!");
     return 1;
   }
  TP->add_hp(random(8));
  tell_object(TP, "The doctor applies a balm that heals your wounds.");
  TP->add_money("gold", -20);
  return 1;
}

void cure_serious(string str) 
{
  if((int)TP->query_money("gold") < 45) 
   {
     tell_object(TP, "You don't have enough money!");
     return 1;
   }
  TP->add_hp(roll_dice(2,8)+1);
  tell_object(TP, "The doctor heals and binds your wounds.");
  TP->add_money("gold", -45);
  return 1;
}


void cure_critical(string str) 
{
  if((int)TP->query_money("gold") < 100) 
   {
     tell_object(TP, "You don't have enough money!");
     return 1;
   }
  TP->add_hp(roll_dice(3,8)+3);
  tell_object(TP, "The doctor covers your wounds with a pungent salve.");
  TP->add_money("gold", -100);
  return 1;
}


void neut_poison(string str) 
{
  if((int)TP->query_money("gold") < 150) 
   {
     tell_object(TP, "You don't have enough money!");
     return 1;
   }
  TP->add_poisoning(-(int)TP->query_poisoning());
  tell_object(TP,"The doctor administers an antidote that cures your poisoning.");
  TP->add_money("gold", -150);
  return 1;
}


void buy_potion(string str) 
{
  if((int)TP->query_money("gold") < 30)
   {
     tell_object(TP, "You don't have enough money!");
     return 1;
   }
  new("/d/shadow/room/beach/obj/healing.c")->move(TP);
  tell_object(TP, "The doctor takes your money and give you a healing potion.");
   TP->add_money("gold", -30);
  return 1;
}
