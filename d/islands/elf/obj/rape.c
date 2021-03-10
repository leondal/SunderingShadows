// fancy fan for blade songstress
#include <std.h>
inherit "/d/common/obj/weapon/rapier";

void create() {
    ::create();
   set_id(({"rapier","gleaming rapier","guiding light"}));
   set_name("guiding light");
   set_obvious_short("%^RESET%^%^BOLD%^gleaming rapier%^RESET%^");
   set_short("%^RESET%^%^BOLD%^guiding light%^RESET%^");
   set_long("This is a bright rapier that seems to beam"+
   " with magic.  The blade is made from finely polished"+
   " mithril with silver etched runes upon the slender"+
   " metal.  The hilt is wrapped in fine gold dyed silk"+
   " with a gleaming pearl used as a counter weight. ");
   set_lore("This is an ancient blade passed down from"+
   " blade singers amongst elven heroes.  It is an "+
   "artifact created with high magic back when elves"+
   " were abundant in the lands.  The style appears to"+
   " be that of the gold elven tribes.  The blade "+
   "itself seems like the moonblades of legend but"+
   " likely was created as an alternative to the royal"+
   " artifacts that favored the moon elves.");
   set_property("lore difficulty",35);
   set_value(9000);
   set_property("enchantment",5);
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set_hit((:TO,"hit_func":));
   set_item_bonus("sight bonus",2);
   set_special_material_type("silver");
   set_property("able to cast",1);
}

int wield_func(){

      tell_room(EETO,"%^BOLD^The pearl on "
           +ETOQCN+"'s weapon glows brightly.",ETO);
      tell_object(ETO,"%^BOLD%^The pearl on the rapier flashes brightly.");
      return 1;
}
int unwield_func(){

   tell_room(EETO,"The rapier of "+ETOQCN+
   " dims.",ETO);
   tell_object(ETO,"The rapier dims when unwielded.");
   return 1;
}
int hit_func(object target) {
   if(!objectp(target)) return 0;
   if(!objectp(ETO)) return 0;
   if(!objectp(EETO)) return 0;
   if(random(1000) < 400){
     switch(random(7)){
      case 0..3:
        tell_room(EETO,"%^BOLD%^"+ETOQCN+"'s blade shines with a bright light as it pierces "
                  +target->QCN+".",({target,ETO}));
        tell_object(ETO,"%^BOLD%^You blade shines as it pierces "+target->query_cap_name()+
            ".",target);
        tell_object(target, "%^BOLD%^"
         +ETO->QCN+"'s  penetrates into"+
         " you as it shines with a bright light.");
         return roll_dice(2,8)+2;

     case 4:
            tell_room(EETO,"%^BOLD%^"+ETOQCN+" sinks the blade into "
			+target->QCN+" and quickly execute a second attack."
                         ,({target,ETO}));
            tell_object(ETO,"%^BOLD%^You sink the blade into "+target->QCN+
			"and quickly execute a second attack.",target);
            tell_object(target, "%^BOLD%^"+ETOQCN+" sinks "+ETO->QP+
			" blade into you and quickly execute a second attack.");
            ETO->execute_attack();
            return roll_dice(1,4)+1;
	  case 5:
            tell_room(EETO,"%^BOLD%^"+ETO->QCN+" strikes"+target->QCN+
			" in the head with the blade and it lets out a deafening ring."
                         ,({target,ETO}));
            tell_object(ETO,"%^BOLD%^You strike "+target->QCN+" in the head with"+
			" the blade and it lets out a deafening ring..");
			tell_object(target,"%^CYAN%^"+ETO->QCN+
			  " strikes you in the head with the blade and it lets out a deafening ring.");
			target->set_paralyzed(5+random(5),"Your ears are ringing.");
			return roll_dice(1,4)+1;
		case 6:

            tell_object(ETO,"%^BOLD%^As you pierce into"+target->QCN+
			" words to a spell enter your head..");
			new("/cmds/spells/s/_searing_light")->use_spell(ETO,target,15,100,"cleric");
			return roll_dice(1,4)+1;
      }
   }
}
