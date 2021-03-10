#include <std.h>
inherit "/d/common/obj/weapon/shortsword";
int attacked;
create(){
    ::create();
    set_id(({"sword of doom","doom","sword","short sword",
    "short"}));
    set_name("%^RESET%^%^BLUE%^Sword of Doom%^RESET%^");
    set_short("%^RESET%^%^BLUE%^Sword of Doom%^RESET%^");
    set_obvious_short("A black short sword");
    set_long(
      "%^BLUE%^This sword is made from the very stuff of "+
       "blackness.  Your skin feels frigid while it touches "+
      "this %^BOLD%^%^BLACK%^weapon%^RESET%^%^BLUE%^ you can it feel willing "+
      "you to commit acts of such hatred that Xvim will "+
      "take heed and recognize you as one of his own. "+
      "%^RESET%^"
    );
    set_property("enchantment",2);
    set("value",500);
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_hit((: TO,"extra_hit" :));
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


int unwield_func(string str){
if(attacked==0){
tell_object(ETO,"%^BOLD%^%^RED%^You cannot, you are too consumed with "
"hatred to let your weapon go!%^RESET%^");
 tell_room(environment(query_wielded()),"%^RED%^"+ETO->query_cap_name()+" tries to release "+ETO->query_possessive()+" sword but cannot.%^RESET%^",ETO);
return 0;
}else{
tell_object(ETO,"%^BLUE%^You release your sword...its bloodlust sated");
attacked=0;
return 1;
}
}
int extra_hit(object victem){

    int victemalignment;

    victemalignment=victem->query_alignment();

   if(!random(4)) {
    if(victemalignment==1||victemalignment==4||victemalignment==7){
attacked=1;
	tell_object(ETO,
	  "%^BLUE%^Your sword %^BOLD%^glows "+
	  "%^RESET%^%^BLUE%^ as you smite the "+
	  "forces of good!%^RESET%^"
	);
	tell_object(victem,
      "%^BLUE%^Your soul cries out "+
	  "as you are stuck by "+ETO->query_cap_name()+"'s "+
      "sword of doom.");
	message("other_action","%^BLUE%^"+ETO->query_cap_name()+" stikes "+
	  ""+victem->query_cap_name()+" with a sword "+
      "of doom and "+victem->query_subjective()+" "+
      "cries out in agony!%^RESET%^" 
	  "",environment(victem),(({ETO,victem})));
victem->do_damage("torso", (roll_dice(1,8)));
        return 0;
    }else 
	return 0;
 }
}
