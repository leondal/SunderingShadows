//updated by Circe 1/1/05 with new desc, lore, etc.
#include <std.h>
inherit "/d/common/obj/weapon/mace";

void create() {
    ::create();
    set_id(({"dark mace","mace","darkmace","blunt","iron mace","ironmace"}));
    set_name("dark mace");
    set_obvious_short("an iron mace");
    set_short("%^BOLD%^%^BLACK%^Dark Mace%^RESET%^");
    set_long(
       "%^BLUE%^This mace is crafted from an unusual blue-black "+
       "metal that looks and feels much like %^BOLD%^%^BLACK%^"+
       "iron%^RESET%^%^BLUE%^.  The heavy head is covered in "+
       "%^RESET%^mithril spikes %^BLUE%^of varying lengths, "+
       "all of which are crusted with %^RED%^dried blood %^BLUE%^"+
       "that never seems to wash away.  The iron handle is "+
       "molded to fit the wielder's hand, providing a sturdy - "+
       "if uncomfortable - grip.  %^CYAN%^Runes %^BLUE%^have "+
       "been carved into the exposed iron between the handle "+
       "and the head and %^BOLD%^glow %^RESET%^%^BLUE%^with "+
       "a dark magic at times.%^RESET%^"
    );
    set_lore("This mace is made of cold iron twisted by the evil "+
       "arts of the Kinnesaruda.  Maces such as this are wielded "+
       "by the elite knights chosen to serve the Intruder as "+
       "guards.  The magic has been lost to the realms, but relics "+
       "such as this one are still wielded by those dread knights.  "+
       "A few dark clerics have chosen this weapon as their own "+
       "as well, though those of good hearts tend to shun them.");
    set_value(1000);
    set_wc(1,8);
    set_large_wc(1,12);
    set_property("enchantment",5);
    set_wield((:TO,"to_hit":));
    set_unwield((:TO,"to_remove":));
    set_hit((:TO,"hit_em":));
}


int to_hit(){
   int align;
   if(living(ETO)) align = ETO->query_alignment();
    if((int)ETO->query_level() < 19){
	tell_object(ETO,"%^BOLD%^This is too difficult a weapon to "+
         "master for someone with your skills!");
	return 0;
    }
    if(align == 3 || align == 6 || align == 9){
       tell_object(ETO,"%^BOLD%^%^BLACK%^You feel power surge through "+
          "your veins as you grip the mace.");
       set_item_bonus("attack bonus",1);
       set_item_bonus("damage bonus",1);
       return 1;
    }
    else {
       set_item_bonus("attack bonus",0);
       set_item_bonus("damage bonus",0);
    }
    tell_object(ETO,"%^BLUE%^You feel a strange evil in the mace as "+
       "you wield it.");
    return 1;
}

int to_remove(){
   int align;
   if(living(ETO)) align = ETO->query_alignment();
    if(align == 3 || align == 6 || align == 9){
       tell_object(ETO,"%^BOLD%^%^BLACK%^You feel the power drain "+
          "as you put the mace aside.");
       return 1;
    }else{
       tell_object(ETO,"%^BLUE%^You gladly unwield the mace.");
       return 1;
    }
}

int hit_em(object targ){
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   if(random(4)) return random(4)+1;
   if(!random(6)){
      tell_object(ETO,"%^BLUE%^The runes begin to %^BOLD%^glow %^RESET%^"+
         "%^BLUE%^as the mace strikes "+targ->QCN+"!");
      tell_object(targ,"%^BLUE%^You feel an evil will invade your body as "+
         "the mace strikes you!");
      tell_room(EETO,"%^BLUE%^The runes on the mace held by "+ETOQCN+" "+
         "begin to %^BOLD%^glow %^RESET%^%^BLUE%^as it strikes "+
         ""+targ->QCN+"!",({ETO,targ}));
      return roll_dice(2,6);
   }
   return 0;
}