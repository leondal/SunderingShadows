//psion bane
#include <std.h>

inherit "/d/common/obj/weapon/fauchard.c";

void create() {
    ::create();
    set_name("psibane");
    set_id(({"fauchard","psion bane","psionslayer","psibane","polearm","bane"}));
    set_obvious_short("%^CYAN%^A m%^WHITE%^an%^CYAN%^y-ge%^WHITE%^mm%^CYAN%^ed fauchard%^RESET%^");
    set_short("%^CYAN%^ps%^WHITE%^i%^CYAN%^on harvester");

    set_long("%^CYAN%^This eight foot iron shaft holds "+
	"a massive %^RESET%^curved blade%^CYAN%^ at its end. "+
	" The blade is like a scythe but "+
	"has been mounted straight rather"+
	" than from the side.  The weapon "+
	"seems to have suffered from some "+
	"form of %^WHITE%^crystallization%^CYAN%^.  Many transparent"+
	" %^RESET%^crystals%^CYAN%^ have formed all over the "+
	"shaft and the blade.  There is a %^RED%^red "+
	"banner%^CYAN%^ hanging from the end of the "+
	"weapon that has a human with an insect"+
	" eating it's brain drawn on it.%^RESET%^");
    
    set_language("giant");
    set_read("May all psions be fed to me.");
    set_property("lore difficulty",17);
    set_lore("This weapon was created "+
	"by a tenative alliance between drow "+
	"and ogre-mages.  The evil races "+
	"feared the powers of the psions "+
	"and used arcane magic to bind a "+
	"thought eater's soul into this "+
	"weapon to use against the new threat."+
	"  It is said that those who studied"+
	" under a master ogre-mage receive "+
	"this as a gift for completing their studies.");
    set_value(250);
    set_property("enchantment",2);
    set_hit( (: this_object(), "weapon_hit" :) );
   
    set_wield((:TO,"wield_me":));
    set_unwield("You release the weapon, careful not to cut yourself on the crystals.");
        set_hit((:TO,"weapon_hit":));
}




int wield_me() {
  if(ETO->query_highest_level() < 10) {
    tell_object(ETO,"The magic of this weapon is beyond "+
    "you!");
    return 0;
  }
  tell_object(ETO,"%^RED%^Your whole being hungers for the "+
  "minds of psions!");
  return 1;
}   


int weapon_hit(object targ) {
  if(!objectp(targ)) return 1;
  if(!targ->is_class("psion"))  return 1;
  
  if((string)targ->return_target_limb()=="head") {
    tell_room(EETO,"%^CYAN%^"+ETO->QCN+"%^RED%^Slices the blade into "
	+targ->QCN+"'s head and crystals burrow into "+ETO->QP+" skull."
	,({ETO,targ}));
	tell_object(ETO,"%^RED%^You slice the weapon into "+
	targ->QCN+"'s head and crystals burrow into "+ETO->QP+"'s skull.");
	tell_object(targ,"%^CYAN%^"+ETO->QCN+" slices you in the"+
	" head and crystals burrow into your skull.  "+
	"Your brain feels like it's being eaten.");
	if(!"/daemon/saving_throw_d.c"->will_save(targ,-10))
	  targ->add_stat_bonus("intelligence",-1);
  }

  if(!random(3)) 
   
     switch(random(200)) {
        case 0..100:
            tell_room(EETO,"%^CYAN%^"+ETO->QCN+"%^RED%^ strikes "+
            targ->QCN+" with "+ETO->QP+ " fauchard "+
            "and "+targ->QCN+" is flung to the ground"+
            "!",({targ,ETO}));
     
            tell_object(ETO,"%^RED%^You swipe "+targ->QCN+" "+
            "with your fauchard and "+targ->QS+ " is flung "+
            "to the ground!");
         
            tell_object(targ,"%^RED%^"+ETO->QCN+" strikes you with "+ETO->QP+
            " fauchard you are flung to the ground");
            
   
            targ->set_tripped(1,"%^GREEN%^You struggle to get up.");
            return roll_dice(1,8)+2;
        case 101..199:
            tell_room(EETO,"%^RED%^"+ETO->QCN+" screams "+
            "loudly and slashes "+ETO->QP+" fauchard deep "+
            "into "+targ->QCN+", leaving a gaping wound. "
           ,({targ,ETO}));

            tell_object(ETO,"%^RED%^An intense anger wells up "+
            "in you as you slash into "+targ->QCN+", "+
            "leaving a gaping wound.");

            tell_object(targ,"%^RED%^"+ETO->QCN+" screams loudly "+
            "and slashes "+ETO->QP+" fauchard deep "+
            "into you, leaving a gaping wound!");
            return roll_dice(1,8) + 5;
            
        }
   
  
  
}
