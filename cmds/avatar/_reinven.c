// _inven.c simplified and improved version of scan for avatar use
// added to show enchantments, AC, and dir origin - Styx 4/21/02

#include <std.h>
#include <move.h>

inherit DAEMON;

int tab, *place, flag;
string ret;

void printaallin(object ob, int num);
void printascan(object ob, int num);
object obj;

int cmd_reinven(string str){
   string junk, heading;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

   if(!str || str == "") {
        str = TP->query_name();
   }
      flag = 0;
      obj = find_player(str);
   if(!obj) return notify_fail("Failed to find that player.\n");
   if(wizardp(obj) && obj->query_level() > TP->query_level()) return 0;
   printaallin(obj,0);
//   write(ret);
//  TP->more(explode(ret,"\n"));
   tell_object(obj, "Inventory Updated.");
   return 1;
}

void printaallin(object ob, int num){
   int i;
   mixed *inv;
   tab += 2;
   inv = all_inventory(ob);
//   place[num] = 0;
   for(i=0;i<sizeof(inv);i++){
      if(1) printaallin(inv[i], num + 1);
      printascan(inv[i], num);
   }
   tab -= 2;
}

void printascan(object ob, int num){
   int ench, ac, value, i;
   string short, long, ob_short, tmp;
   mapping tempmap;
   object ob2, env;
   object *insides;
   string *identifiers;
   if(!ob){ write("No object."); return; }
    if (base_name(ob) == "/std/obj/wed_ring") return;
    if (base_name(ob) == "/d/magic/spellbook") return;
    if (base_name(ob) == "/d/magic/comp_bag") return;
    if (base_name(ob) == "/d/magic/psi_comp_bag") return;
    if (base_name(ob) == "/d/magic/psicrystal") return;
   ob2=new(base_name(ob));
   if(!ob2){ write("Error cloning object: "+ob->query_name()+"."); return; }
   identifiers=ob->query_identified();
   if (tmp=ob->query("alterby")) {
     ob2->set("alterby",tmp);
     short = ob->query_short();
     ob2->set_short(short);
     ob_short=ob->query_obvious_short();
     ob2->set_obvious_short(ob_short);
     long = ob->query_long();
     ob2->set_long(long);
     value = ob->query_value();
     ob2->set_value(value);
     value=ob->query_weight();
     ob2->set_weight(value);
   } else {
     if (!ob2->query_short() && ob->query_short()) ob2->set_short(ob->query_short());
     if (!ob2->query_obvious_short() && ob->query_obvious_short()) ob2->set_obvious_short(ob->query_obvious_short());
     if (!ob2->query_long() && ob->query_long()) ob2->set_long(ob->query_long());
     if (!ob2->query_value() && ob->query_value()) ob2->set_value(ob->query_value());
     if (!ob2->query_weight() && ob->query_weight()) ob2->set_weight(ob->query_weight());
   }
  ac = ob->query_ac();
  if ((int)ob2->query_ac() != ac) ob2->set_ac(ac);
   
  ench = ob->query_property("enchantment");
  while((int)ob2->query_property("enchantment") != ench) {
    ob2->remove_property("enchantment");
    ob2->set_property("enchantment",ench);
  }
  
  identifiers=ob->query_identified();
  for (i=0;i< sizeof(identifiers); i++) {
    tmp=identifiers[i];
    ob2->add_identified(tmp);
  }
  identifiers=ob->query("id");
  for (i=0;i< sizeof(identifiers); i++) {
    tmp=identifiers[i];
    if (!ob2->id(tmp))
      ob2->add_id(tmp);
  }
  identifiers=ob->query_studied();
  for (i=0;i< sizeof(identifiers); i++) {
    tmp=identifiers[i];
    ob2->add_studied(tmp);
  }
  tempmap = ob->query_studied_failed();
  identifiers=keys(tempmap);
  for (i=0;i< sizeof(identifiers); i++) {
    tmp=identifiers[i];
    ob2->add_studied_failed(tmp,tempmap[tmp]);
  }
  if (tmp=(string)ob->query_property("creator"))  ob2->set_property("creator",tmp);
  if (tmp=(string)ob->query_property("quality"))  ob2->set_property("quality",tmp);
  if(i=(int)ob->query_property("curseditem")) ob2->set_property("curseditem",i);
  if(i=(int)ob->query_property("no offer")) ob2->set_property("no offer",i);
  if(i=(int)ob->query_property("death remove")) ob2->set_property("death remove",i);
  if(i=(int)ob->query_property("death keep")) ob2->set_property("death keep",i);
  if(i=(int)ob->query_property("plot_item")) ob2->set_property("plot_item",i);
  if(i=(int)ob->query_property("no_profit")) ob2->set_property("no_profit",i);
  if(i=(int)ob->query("strbonus")) ob2->set("strbonus",i);
  if(i=(int)ob->query("dexbonus")) ob2->set("dexbonus",i);
  if(i=(int)ob->query("conbonus")) ob2->set("conbonus",i);
  if(i=(int)ob->query("intbonus")) ob2->set("intbonus",i);
  if(i=(int)ob->query("wisbonus")) ob2->set("wisbonus",i);
  if(i=(int)ob->query("chabonus")) ob2->set("chabonus",i);
  if(i=(int)ob->query_size()) ob2->set_size(i);
  
  env=environment(ob);
  if (ob->move("/d/dagger/wiz_store2") != MOVE_OK) {
    write("problem moving item to wiz storeroom...");
  }
  if (ob2->move(env) != MOVE_OK) {
    write("problem moving item to the player... dropping it at their feet/");
    tell_object(obj, "Problem moving your item back in it's place. Placing at your feet.");
    ob2->move(environment(obj));
    
  }

  insides=all_inventory(ob);
  for (i=0; i<sizeof(insides) ; i++) {
    
    if (insides[i]->move(ob2) != MOVE_OK) {
      tell_object(obj, "Problem moving your item back in it's sack. Placing at your feet.");
      insides[i]->move(environment(obj));
    }
  }
}


void help(){
   write("Syntax: reinven [player]\n"+
      "This command refrehses the inventory of a player.\n"+
      "Example: reinven valas\n"
	 );
}
