#include <std.h>
#include <objects.h>
#include <money.h>
#include <move.h>

inherit HEALER;


void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_light(3);
   set_property("training",1);
   set_indoors(1);
   set_short("Seneca Hospital");
   set_long(
@DESC
This room is well lit by skylights and the walls are 
covered in white paneling. A few benches line the walls 
in this lobby and there is a small step to the south 
where the service desk is located. The %^CYAN%^Seneca Hospital%^RESET%^ 
is a modern place of medicine. Charts and graphs cover 
the walls behind a large desk. People seeking preventive 
medicine or minor treatments such as the removal of 
poison can be treated at this main desk. A surgery lies 
beyond but is restricted to hostpital staff. A list on 
the wall offers healing choices and services.
DESC
   );
   set_smell("default", "A hint of medicinal alcohol flavors the air.");
   set_listen("default", "You can hear mumbling from the surgery and the clanking of instruments but you cannot make out the words being spoken. ");
/*   set_items( ([ "list" : "%^BOLD%^The following simple transactions are availiable at this desk: \n"
                 "cl : cure light wounds for 20 gold \n"
                 "cs : cure serious wounds for 45 gold \n"
                 "cc : cure critical wounds for 100 gold \n"
                 "np : neutralize all poison for 150 gold \n"
                 "bp : buy a healing potion for 25 gold \n"
//                 "ba : buy an advanced vial for 50 gold \n"
               ]) );
*/
   set_exits( ([
      "out" : "/d/attaya/seneca/healyard",
   ]));
   set_name("nurse");
}

void init() {
   ::init();
/*
   add_action("cure_light", "cl");
   add_action("cure_serious", "cs");
   add_action("cure_critical", "cc");
   add_action("neut_poison", "np");
   add_action("buy_potion", "bp");
//   add_action("buy_advanced", "ba");
*/
}

void reset() {
   ::reset();
   if(!present("healer"))
      new("/d/attaya/seneca/mon/healer")->move(TO);
}

/*void cure_light(string str) {
   if(!TP->query_funds("gold",20)) {
      tell_object(TP, "You don't have enough money!");
      return 1;
   }
   TP->add_hp(random(8));
   tell_object(TP, "The nurse bandages your minor injuries.");
   TP->use_funds("gold", 20);
   return 1;
}

void cure_serious(string str) {
   if(!TP->query_funds("gold",45)) {
      tell_object(TP, "You don't have enough money!");
      return 1;
   }
   TP->add_hp(roll_dice(2,8)+1);
   tell_object(TP, "The nurse tends to your injuries.");
   TP->use_funds("gold", 45);
   return 1;
}

void cure_critical(string str) {
   if(!TP->query_funds("gold",100)) {
      tell_object(TP, "You don't have enough money!");
      return 1;
   }
   TP->add_hp(roll_dice(3,8)+3);
   tell_object(TP, "The nurse pours a numbing blue liquid over your lacerations and sews them up.");
   TP->use_funds("gold", 100);
   return 1;
}

void neut_poison(string str) {
   if(!TP->query_funds("gold",150)) {
      tell_object(TP, "You don't have enough money!");
      return 1;
   }
   TP->add_poisoning(-(int)TP->query_poisoning());
   tell_object(TP,"The nurse mixes some chemicals in a flask and pours the antidote over the affected area.");
   TP->use_funds("gold", 150);
   return 1;
}

void buy_potion(string str) {
   object ob;
   int num;
   if(!str) return notify_fail("bp <amount>\n");
   if(sscanf(str,"%d",num) != 1)
      return notify_fail("bp <amount>\n");
   if(!TP->query_funds("gold",25*num)) {
      tell_object(TP, "You don't have enough money!");
      return 1;}
   TP->set_paralyzed(1);
   ob = new("/d/common/obj/potion/healing");
   ob->set_uses(num);
   if((string)ob->move(TP) == MOVE_OK) {
      tell_object(TP, "The nurse takes your money and gives you a healing potion.");
      TP->use_funds("gold",25*num);
      return 1;
   }
   write("You can't carry any more!");
   return 1;
}

void buy_advanced(string str) {
   object ob;
   int num;
   if(!str) return notify_fail("bf <amount>\n");
   if(sscanf(str,"%d",num) != 1)
      return notify_fail("bf <amount>\n");
   if(!TP->query_funds("gold",50*num)) {
      tell_object(TP, "You don't have enough money!");
      return 1;}
   TP->set_paralyzed(1);
   ob = new("/d/attaya/seneca/obj/medic");
   ob->set_uses(num);
   if((string)ob->move(TP) == MOVE_OK) {
      tell_object(TP, "The nurse takes your money and gives you an advanced S1 vial.");
      TP->use_funds("gold",50*num);
      return 1;
   }
   write("You can't carry any more!");
   return 1;
}

*/
