#include <std.h>

inherit "/d/common/obj/weapon/shortsword.c";

void create() {
    ::create();
    set_name("black sword");
    set_id( ({"sword","serrated", "black sword", "black", "serrated sword"}) );
   set_short("%^BOLD%^%^BLUE%^Serrated sword%^RESET%^");
    set_long(
      "This sword is made of a strange metal, colored of the purest black from hilt to tip of the blade.  It has a long curved blade on one edge, and the other is serrated, with barbs all over it to rip your flesh from your body.  It is eternally stained with the blood of those it has slain."
    );
    set_weight(6);
    set_value(1000);
    //set_wc(2,4);
    //set_large_wc(2,5);
    //set_size(1);
	//set_prof("short blades");
    set_type("slashing");
    set_property("enchantment",3);
    set_hit( (:this_object(), "extra_hit":) );
   set_wield((:TO,"wieldme":));
   set_unwield((:TO,"removeme":));
}

int wieldme() {
   if( (int)ETO->query_highest_level() < 20 && interactive(TP)) {
     tell_object(ETO,"You are not experienced enough to be worthy of such power.");
     return 0;
   }
   ETO->set_property("evil item",1);
   return 1;
}

int removeme() {
   ETO->set_property("evil item",-1);
   return 1;
}

int extra_hit(object ob)  {
    if(!objectp(ob)) return 1;
    if(random(15) < 2) {
	tell_object(ETO, "%^BLUE%^The serrated edge of the blade slices deep into your opponent, ripping gobs of flesh away on its poisoned edge.%^RESET%^");
	tell_object(ob, "%^BLUE%^"+ETO->query_cap_name()+" slashes you with the poisoned and serrated edge of his blade, ripping the flesh from your body and driving poison into your wounds!%^RESET%^");
	tell_room(environment(query_wielded()), "%^BLUE%^The serrated edge rips the flesh from "+ob->query_cap_name()+"'s body and poisons "+ob->query_objective()+".%^RESET%^", ({ob, ETO}) );

	ob->add_poisoning(10);
	return(5+random(10));
    }
}
