//pbat.c

#include <std.h>

inherit WEAPONLESS;

void create(){
   ::create();

   set_name("illusion");
   set_short("an illusion");
   set("not living",1);
   set_long("this is an illusion");
   set_gender("male");
   set_property("no animate",1);
   set_hd(10,1);
   set_stats("dexterity",20);
   set_hp(1);
   set_weight(10000);
   set_attacks_num(1);
   set_size(1);
   set("magic",1);
}

void die(object ob){
   tell_room(ETO,"%^CYAN%^The illusion shimmers and is dispelled.");
   remove();
   return;
}

