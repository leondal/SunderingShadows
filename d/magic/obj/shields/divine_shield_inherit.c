// Updated by ~Circe~ 8/18/15 to scale properly with the new system
// and to use the shield inherit.
// divine shieli inherit for spells

#include <std.h>
//inherit ARMOUR;
inherit "/d/common/obj/armour/shield.c";
string owner;

void create(){
    ::create();
    	set_name("divineshield");
    	set_short("a shiney divine shield");
    	set_long("This is a magical shield that you can't quite"+
		" discern its purpose.  If you can see this shield,"+
		" something is broken, contact a wiz!");
    	set_id(({"divineshield"}));
    	set_type("shield");
    	set_weight(0);
    	set_value(0);
	set("no curse",1);
     	set_size(2);
      set_ac(1);
      set_limbs(({ "right hand" }));
    	set_wield((:TO, "extra_wield":));
    	set_unwield((:TO,"extra_unwield":));
}

int wearable() { return 1; }


void init(){
    int clevel;

   ::init();
   if(stringp(owner)) return;
  if(interactive(ETO) && ETO == ETO){
         owner = ETOQCN;
   }
/*
Moving this to the spell so that it plays nicely with the various classes that can cast it. ~Circe~ 
   clevel = ETO->query_guild_level("cleric");
  set_property("enchantment",clevel/7);
   while((int)(query_property("enchantment")) < 0){
      remove_property("enchantment");
  set_property("enchantment",clevel/7);
   }
      if((int)(query_property("enchantment")) > 4 ) {
    remove_property("enchantment");
     set_property("enchantment",4);
   }
*/
}

int extra_wield(){
    if(interactive(TP) && owner != (string)TPQN){ 
        tell_object(TP,"You are not allowed to use this shield.");
        return 0;
    }
    return 1;
}

int extra_unwield(){
    return 1;
}

int drop(){
    tell_object(TP,"The shield will not leave your arm!");
    return 1;
}

int save_me(string file){ return 1;}
