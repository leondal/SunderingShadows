#include <std.h>
inherit "/d/common/obj/weapon/mace";
create(){
    ::create();
    set_id(({"mace of doom","doom","mace"}));
    set_name("%^RESET%^%^BLUE%^Mace of Doom%^RESET%^");
    set_short("%^RESET%^%^BLUE%^Mace of Doom%^RESET%^");
    set_obvious_short("A black mace");
    set_long(
      "%^BLUE%^This mace is made from the very stuff of "+
       "blackness.  Your skin feels frigid while it touches "+
      "this %^BOLD%^%^BLACK%^weapon%^RESET%^%^BLUE%^ you can it feel willing "+
      "you to commit acts of such hatred that Xvim will "+
      "take heed and recognize you as one of his own. "+
      "%^RESET%^"
    );
    set_property("enchantment",2);
    set("value",500);
    set_wield((:TO,"wield_func":));
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
	  "mace.%^RESET%^");
	tell_room(environment(TP),
	  "%^BLUE%^"+TPQCN+"'s eyes begin to %^RED%^ glow "+
       "%^BLUE%^as "+TP->query_subjective()+" wields the mace of doom.%^RESET%^",TP);
	return 1;
    }else{
	write("Your diety would not approve of that!");
	return 0;
    }
}

int extra_hit(object victem){
if(!random(4)) {
  if((int)victem->query_alignment() == 1
    || (int)victem->query_alignment() == 4
    || (int)victem->query_alignment() == 7){
  tell_object(ETO,
	  "%^BLUE%^Your mace %^BOLD%^glows "+
	  "%^RESET%^%^BLUE%^ as you smite the "+
	  "forces of good!%^RESET%^"
	);
	tell_object(victem,
     "%^BLUE%^Your soul cries out "+
  "as you are stuck by "+ETO->query_cap_name()+"'s "+
      "mace of doom.");
  message("other_action","%^BLUE%^"+ETO->query_cap_name()+" stikes "+
	  ""+victem->query_cap_name()+" with a mace "+
      "of doom and "+victem->query_subjective()+" "+
      "cries out in agony!%^RESET%^" 
  "",environment(victem),(({ETO,victem})));
	return (roll_dice(2,4));
    }else 
	return 0;
 }
}
