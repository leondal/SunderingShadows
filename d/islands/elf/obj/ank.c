// anchor for underwater monster
#include <std.h>
inherit "/d/common/obj/weapon/hammer_lg";

void create() {
    ::create();
   set_id(({"anchor","barnacled anchorr","depth's anchor"}));
   set_name("Anchor");
   set_obvious_short("%^RESET%^%^BLUE%^barnacled Anchor%^RESET%^");
   set_short("%^RESET%^%^BLUE%^Depth's Anchor%^RESET%^");
   set_long("This is a barnacled anchor.   It is black "+
   "and brown with rust.   Dark barnacles are stuck to"+
   " it.   They seem to be dead.  The anchor gives off"+
   " an aura of resentment. ");
   set_lore("This looks to be the work of a lost city."+
   "  When an ancient war between humans and elves "+
   "lead to high magic that sunk a huge part of the"+
   " world to protect the remaining elves.  Many "+
   "people died and the land was mostly destroyed.");
   set_property("lore difficulty",35);
   set_value(9000);
   set_property("enchantment",4+random(2));
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set_hit((:TO,"hit_func":));
   set_item_bonus("survival",2);
   set_special_material_type("cold iron");
}

int wield_func(){
      tell_room(EETO,"%^BLUE^The barnacles on "
           +ETOQCN+"'s weapon glows drip a black fluid.",ETO);
      tell_object(ETO,"%^BLUE%^The barnacles on the anchor drip a black fluid.");
      return 1;
}
int unwield_func(){
   tell_room(EETO,"The anchor of "+ETOQCN+
   " stops giving off an aura of hatred.",ETO);
   tell_object(ETO,"The anchor's aura of resentment dims when unwielded.");
   return 1;
}
int hit_func(object target) {
   if(!objectp(target)) return 0;
   if(!objectp(ETO)) return 0;
   if(!objectp(EETO)) return 0;
   if(random(1000) < 400){
     switch(random(7)){
      case 0..3:
        tell_room(EETO,"%^BLUE%^"+ETOQCN+"'s anchor smashes into "
                  +target->QCN+".",({target,ETO}));
        tell_object(ETO,"%^BLUE%^Your anchor smashes "+target->query_cap_name()+
            ".",target);
        tell_object(target, "%^BLUE%^"
         +ETO->QCN+"'s anchor penetrates into"+
         " you.");
         return roll_dice(2,8)+5;

     case 4:
            tell_room(EETO,"%^BLUE%^"+ETOQCN+" bashes the anchor into "
			+target->QCN+" and quickly execute a second attack."
                         ,({target,ETO}));
            tell_object(ETO,"%^BLUE%^You smash the anchor into "+target->QCN+
			"and quickly execute a second attack.",target);
            tell_object(target, "%^BLUE%^"+ETOQCN+" bashes "+ETO->QP+
			" anchor into you and quickly execute a second attack.");
            ETO->execute_attack();
            return roll_dice(1,8)+1;
	  case 5:
            tell_room(EETO,"%^BLUE%^"+ETO->QCN+" strikes"+target->QCN+
			" in the head with the anchor and it lets out a sickening thud."
                         ,({target,ETO}));
            tell_object(ETO,"%^BLUE%^You strike "+target->QCN+" in the head with"+
			" the head and it lets out a sickening thud.");
			tell_object(target,"%^BLUE%^"+ETO->QCN+
			  " strikes you in the head with the anchor and it lets out a sickening thud.");
			target->set_paralyzed(5+random(5),"All you see are stars.");
			return roll_dice(1,8)+1;
		case 6:

            tell_object(ETO,"%^BLUE%^As you bash into"+target->QCN+
			" words to a spell enter your head..");
			new("/cmds/spells/d/_doom")->use_spell(ETO,target,40,100,"cleric");
			return roll_dice(1,4)+1;
      }
   }
}
