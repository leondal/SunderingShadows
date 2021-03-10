//

#include <std.h>

inherit WEAPONLESS;


object owner;

void set_owner(object own){
   owner = own;
}

void create(){
   ::create();

   set_name("Tree");

   set_short("Tree");
   set_long("");
   set_hp(100000);
   set_hd(10,1000);
   set_overall_ac(-6);


   set_attacks_num(1);
}

int move(mixed dest)
{
	if(!objectp(dest)) remove();
	else if(base_name(dest) != "/d/tharis/obj/trunk") remove();
	else return ::move(dest);
}

/*
void init(){
   ::init();
   if(!objectp(TO)) { return; }
   if(!objectp(ETO)) { return; }
   if(base_name(ETO) != "/d/tharis/obj/trunk")
      remove();
}*/

int do_damage(string target,int damage){

   int hold;
   if(!objectp(owner)) { return 0; }
   //if(!objectp(PO)) { return 0; }
   hold =  owner->do_damage("trunk",damage);
   //owner->add_attacker(PO);
   //owner->continue_attack();

   return hold;
}



