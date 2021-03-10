//  Made READABLE By FireDragon

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
set_short("The Healers");
set_long("%^ORANGE%^You enter a room reeking of sweat, blood and anitseptic.  Shelves hold jars of salves, potions and bandages.  Patients and waiting individuals lay in rough cots, or sit upon chairs waiting for the healer D'bellin to attend to them.  You can purchase potions here and have D'bellin attend to your wounds.  A list of services and prices is taked upon the wall.");
  set_smell("default", "The strong odor of herbs and balms turns your "
                       "stomach.");
set_listen("default", "You hear occasional moans and groans from D'bellin's"
                        "patients.");
set_items( ([ "list" : "D'bellin offers these services: \n"
                         "cl : cure light wounds for 20 gold \n"
                         "cs : cure serious wounds for 45 gold \n"
                         "cc : cure critical wounds for 100 gold \n"
                         "np : neutralize all poison for 150 gold \n"
                        "bp : buy a healing potion for 30 gold \n"
           ]) );
  set_exits( ([
"out" : PROOM+"room53.c"
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
if(!present("d'bellin"))
new("/d/ptalkin/mon/d'bellin")->move(TO);
}


void cure_light(string str) 
{
  if((int)TP->query_money("gold") < 20) 
   {
     tell_object(TP, "You don't have enough money!");
     return 1;
   }
  TP->add_hp(random(8));
tell_object(TP, "D'bellin applies a balm that heals your wounds.");
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
tell_object(TP, "D'bellin heals and binds your wounds.");
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
tell_object(TP, "D'bellin covers your wounds with a pungent salve.");
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
tell_object(TP,"D'bellin administers an antidote that cures your poisoning.");
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
tell_object(TP, "D'bellin takes your money and gives you a healing potion.");
   TP->add_money("gold", -30);
  return 1;
}
