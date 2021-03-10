//  Made READABLE By FireDragon
//

#include <std.h>
#include <objects.h>
#include <money.h>
#include <move.h>

inherit ROOM;


void create() 
{
  room::create();
  set_property("no attack", 1);
  set_property("no teleport",1);
   set_property("training",1);
    set_property("light",1);
    set_property("indoors",1);
  set_short("%^RED%^Shades of Death Place of Wellness");
set_long(
@PACK
%^RED%^You have entered the Shades of Death's Place of Wellness.%^RESET%^
Here you can find healing for your wounds. There are many bottles containing healing balms, waters, and oils on the shelves. This room is spotless as the proprietor belives cleanliness is as important as evilness. You can see other Pack members lying on cots around you, and old veterans dying next to them. Nathanial, the proprietor, scurries around to assist all who becon him. A list of services are posted on the wall.
PACK
);
set_smell("default", "You can smell death and healing herbs here.");
set_listen("default", "The sound of people moaning in pain and soft whispers can be heard here.");
  set_items( ([ "list" : "Nathanial offers these services: \n"
                         "cl : cure light wounds for 20 gold \n"
                         "cs : cure serious wounds for 45 gold \n"
                         "cc : cure critical wounds for 100 gold \n"
                         "np : neutralize all poison for 150 gold \n"
                        "bp : buy a healing potion for 30 gold \n"
           ]) );
  set_exits( ([
"up" : "/d/shadow/guilds/pack/hall/pack4.c"
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
    if(!present("nathanial")) 
      new("/d/shadow/guilds/pack/hall/nath.c")->move(TO);
}


void cure_light(string str) 
{
  if((int)TP->query_money("gold") < 20) 
   {
     tell_object(TP, "You don't have enough money!");
     return 1;
   }
  TP->add_hp(random(8));
  tell_object(TP, "Nathanial applies a healing potion that heals your wounds.");
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
  tell_object(TP, "Nathanial heals and binds your wounds.");
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
  tell_object(TP, "Nathanial covers your wounds with a pungent salve.");
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
  tell_object(TP,"Nathanial administers an antidote that cures your poisoning.");
  TP->add_money("gold", -150);
  return 1;
}


void buy_potion(string str) 
{
object ob;
  int num;
   if(!str) return notify_fail("bp <amount>\n");
    if(sscanf(str,"%d",num) != 1)
     return notify_fail("bp <amount>\n");
    if((int)TP->query_money("gold") < 30 * num)
   {
     tell_object(TP, "You don't have enough money!");
     return 1;
   }
TP->set_paralyzed(1);
  ob = new("/realms/tristan/healing.c");
   ob->set_uses(num);
  if((string)ob->move(TP) == MOVE_OK){
  tell_object(TP, "Nathanial takes your money and give you a healing potion.");
      TP->add_money("gold",-30*num);
  return 1;
}
write("You can't carry any more!");
return 1;
}
