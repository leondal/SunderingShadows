//  Made READABLE By FireDragon

// rooms by the House of Svaha

#include "/d/ptalkin/ptalkin.h"
#include <std.h>
#include <objects.h>
#include <money.h>

inherit ROOM;


void create() 
{
  room::create();
  set_light(3);
  set_property("no attack", 1);
  set_indoors(1);
set_short("%^GREEN%^Healer F'larions Shop");
set_long("%^GREEN%^A large hearth takes up the whole wall on the east side
of the room.  Several large pots hang from hooks within the vast cavern of
heat.  Noxious fumes rise into the air along with smoke of many colours.
The west wall is taken up by shelves loaded with rolled bandages,
ointments, ungents and other unknown things.");

  set_smell("default", "The strong odor of herbs and balms turns your "
                       "stomach.");
set_listen("default", "You hear moans and groans from F'larion's "
                        "patients.");
set_items( (["list" : "F'larion offers these services: \n"
                         "cl : cure light wounds for 20 gold \n"
                         "cs : cure serious wounds for 45 gold \n"
                         "cc : cure critical wounds for 100 gold \n"
                         "np : neutralize all poison for 150 gold \n"
                        "bp : buy a healing potion for 30 gold \n"
           ]) );
  set_exits( ([
"out" : "/d/ptalkin/mid/room78"
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
if(!present("f'larion"))
new("/d/ptalkin/mon/f'larion")->move(TO);
}


void cure_light(string str) 
{
  if((int)TP->query_money("gold") < 20) 
   {
     tell_object(TP, "You don't have enough money!");
     return 1;
   }
  TP->add_hp(random(8));
tell_object(TP, "F'larion applies a balm that heals your wounds");
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
tell_object(TP, "F'larion heals and binds your wounds");
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
tell_object(TP, "F'larion covers your wonds with a pungent salve");
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
tell_object(TP,"F'larion administers an antidote that cures your poisoning");
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
  new("/realms/tristan/healing.c")->move(TP);
tell_object(TP, "F'larion takes your money and gives you a healing potion");
   TP->add_money("gold", -30);
  return 1;
}
