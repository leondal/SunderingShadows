#include <std.h>

#define SAVEFILE "/d/save/assrings"

inherit ARMOUR;

mapping ring_owners;

void create(){
   ::create();
   set_id(({"special_assassin_object", "ring", "assassin ring", "silver ring", "ornate silver ring"}));
   set_short("ornate silver ring");
   set_name("ornate silver ring");
   set_long("This is a finely-crafted ornate silver ring.");
   set_weight(1);
   set_value(100);
   set_type("ring");
   set_ac(1);
   set_property("enchantment",-1);
   set_property("no remove curse",1);
   set_limbs(({"left hand"}));
   set_wear((:TO,"wear_me":));
   set_property("no animate",1);
	restore_object(SAVEFILE);
}

int wear_me(){
   if(interactive(ETO) && ETO->query("is_assassin")){
      set_ac(1);
      set_property("enchantment",-1);
      while(query_property("enchantment") != -1){
         remove_property("enchantment");
         set_property("enchantment",-1);
      }
      tell_object(ETO,"You slide the ring onto your finger and you feel as if it was meant to be there.");
   }
   else{
      set_ac(0);
      if(query_property("enchantment")) remove_property("enchantment");
   }
   return 1;
}

int drop(){
// put, give, and drop all use this
   if(ETO->query_ghost() || !ETO->query("is_assassin"))
      return 0;
   if((object)TO->query_worn() == ETO){
      tell_object(ETO,"The ring tightens almost imperceptibly on your finger and will not come off.");
      return 1;
   }
   else
      return 0;
}

void init(){
//   object ring;
   string who_old, who_new;
   string *key;
   string my_file;
   
   ::init();
   add_action("do_offer","offer");
   add_action("no_remove","remove");
   add_action("no_remove","unwear");
	restore_object(SAVEFILE);
//   ring = present("assassin ring 2",TP);
//   if(ring) call_out("remove",1);
   if(!ring_owners) ring_owners = ([]);
   key = keys(ring_owners);
   my_file = base_name(TO);
   who_new = ETO->query_name();
   if(member_array(my_file, key) != -1){
      who_old = ring_owners[my_file];
      if(who_old != who_new){
         map_delete(ring_owners, my_file);
         if(interactive(ETO)) ring_owners[my_file] = who_new;
      }
   }
   else
      if(interactive(ETO)) ring_owners[my_file] = who_new;
   save_object(SAVEFILE);
}

int no_remove(string str){
   if(present(str,ETO) == TO){
      if(interactive(ETO)){
         if(ETO->query("is_assassin")){
            if((object)TO->query_worn() == ETO){
               tell_object(ETO,"The ring tightens almost imperceptibly on your finger and will not come off.");
               return 1;
            }
            else
               return 0;
         }
         else
            return 0;
      }
      else
         return 0;
   }
   return 0;
}

int do_offer(string str){
   string my_file;
   
   if(present(str,ETO) == TO){
      if(interactive(ETO)){
         if(ETO->query("is_assassin")){
            if((object)TO->query_worn() == ETO){
               tell_object(ETO,"The ring tightens almost imperceptibly on your finger and will not come off.");
               return 1;
            }
            else{
               my_file = base_name(TO);
               if(member_array(my_file, keys(ring_owners)) != -1)
                  map_delete(ring_owners, my_file);
               return 0;
            }
         }
         else
            return 0;
      }
   }
}

mapping query_ring_owners(){
   return ring_owners;
}
