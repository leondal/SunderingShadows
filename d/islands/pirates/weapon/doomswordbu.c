#include <std.h>
inherit "/std/weapon";
create(){
    ::create();
    set_id(({"sword of doom","doom","sword"}));
    set_name("%^RESET%^%^BLUE%^Sword of Doom%^RESET%^");
    set_short("%^RESET%^%^BLUE%^Sword of Doom%^RESET%^");
    set_long(
      "%^BLUE%^This sword is made from the very stuff of "+
       "blackness.  Your skin feels frigid while it touches "+
      "this %^BOLD%^%^BLACK%^weapon%^RESET%^%^BLUE%^ you can it feel willing "+
      "you to commit acts of such hatred that Xvim will "+
      "take heed and recognize you as one of his own. "+
      "%^RESET%^"
    );
    set_wc(1,6);
    set_large_wc(1,6);
    set_weight(7);
    set_size(1);
    set_property("enchantment",2);
    set("value",500);
    set_wield((:TO,"wield_func":));
    set_hit((: TO,"extra_hit" :));
    set_type("slashing");
    set_prof_type("small blades");
}

int wield_func(string str){
    string wieldergod=TP->query_diety();
    int wielderalignment=TP->query_alignment();

    if(wielderalignment==1||wielderalignment==4||wielderalignment==7){
    write("You would never wield that evil thing!\n");
	return 0;
    }

    if(wieldergod=="xvim"||wieldergod=="none"){
	tell_object(TP,
	  "%^BLUE%^You feel your soul wrench "+
	  "as you wield the evil "+
	  "sword.%^RESET%^");
	tell_room(environment(TP),
	  "%^BLUE%^"+TPQCN+"'s eyes begin to %^RED%^ glow "+
       "%^BLUE%^as "+TP->query_subjective()+" wields the sword of doom.%^RESET%^",TP);
	return 1;
    }else{
    write("Your deity would not approve of that!");
	return 0;
    }
}

int extra_hit(object victem){

    int victemalignment;
    victem=TP->query_current_attacker();

    victemalignment=victem->query_alignment();

 if(!random(4)) {
    if(victemalignment==1||victemalignment==4||victemalignment==7){
	tell_object(TP,
	  "%^BLUE%^Your mace %^BOLD%^glows "+
	  "%^RESET%^%^BLUE%^ as you smite the "+
	  "forces of good!%^RESET%^"
	);
    tell_object(victem,
      "%^BLUE%^Your soul cries out "+
	  "as you are stuck by "+TPQCN+"'s "+
      "sword of doom.");
	message("other_action","%^BLUE%^"+TPQCN+" stikes "+
	  ""+victem->query_cap_name()+" with a sword "+
      "of doom and "+victem->query_subjective()+" "+
      "cries out in agony!%^RESET%^" 
     "",environment(victem),(({ETO,victem})));
         victem->do_damage("torso", (roll_dice(3,5)));
        return 0;
    }
   else {
   }
	return 0;
 }
}
