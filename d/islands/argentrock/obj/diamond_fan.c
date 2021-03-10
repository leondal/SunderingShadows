#include <std.h>

inherit "/d/common/obj/weapon/fan.c";
//  object ob2;  // fixing it to be a local variable only *Styx* 12/25/05

void create(){
        ::create();
        set_name("diamond dust fan");
        set_id(({"fan","diamond dust fan","white silk fan"}));
        set_obvious_short("%^BOLD%^%^WHITE%^A s%^YELLOW%^p%^WHITE%^a"+
                "%^BLUE%^r%^WHITE%^k%^MAGENTA%^l%^WHITE%^i%^CYAN%^n"+
                "%^WHITE%^g white silk fan%^RESET%^");
        set_short("%^BOLD%^%^WHITE%^D%^YELLOW%^i%^WHITE%^a%^BLUE%^m%^WHITE%^o"+
                "%^MAGENTA%^n%^WHITE%^d Dust Fan%^RESET%^");
        set_long("%^RESET%^%^MAGENTA%^This fan seems, at first glance, to be"+
                " nothing more than a delicate accessory used by "
                "so many women in hot weather.  A closer look though,"+
                " reveals that it has been designed in just a way to "
                "effectively support the many %^BOLD%^%^WHITE%^"+
                "titanium%^RESET%^%^MAGENTA%^ tines of its frame, so as"+
                " not to break easily under pressure.  The base is also crafted of "
                " %^BOLD%^%^WHITE%^titanium%^RESET%^%^MAGENTA%^, etched "+
                "with diamond shaped patterns.  Covering the ribs is a "+
                "length of thin shimmering %^BOLD%^%^WHITE%^white silk"+
                "%^RESET%^%^MAGENTA%^.  The top border of the fan is "+
                "covered with crushed %^BOLD%^%^WHITE%^diamonds%^RESET%^"+
                "%^MAGENTA%^.  As light falls on the diamond dust sparkles"+
                " of %^YELLOW%^canary yellow%^RESET%^%^MAGENTA%^, "+
                "%^BOLD%^%^BLUE%^deep blue%^RESET%^%^MAGENTA%^, and "+
                "%^BOLD%^vibrant pink%^RESET%^%^MAGENTA%^ can be seen mixed "+
                "in with the glittering %^BOLD%^%^WHITE%^white %^RESET%^"+
                "%^MAGENTA%^dust.  The boarder of diamond dust appears to "+
                "have been magically bonded together, creating a keen edge "+
                "for slashing.  It is almost distracting just to watch it,"+
                " though indeed it is a stunning piece of crafting.\n%^RESET%^");
        set_lore("A relic from the elven kingdom of Selu'havessthor, this weapon "+
                "was brought to the island of Argentrock by the outcast house "+
                "of Heasirretyn, ancestors of the fey'ri.  This fan was crafted "+
                "for the Flame Dancers, an elite group of warrior/dancers who "+
                "helped to patrol the forests.  The Flame Dancers dressed "+
                "lightly, many of them forsaking the use of armor in favor "+
                "of speed.  These battle-dancers were said to be graceful in"+
                " melee, each movement from them looking like a poetic "+
                "expression of dancing.  Though not as famous as the "+
                "bladesingers, the Flame Dancers were still given the "+
                "utmost respect.  When the fey'ri fled their homeland, "+
                "they took these wonderful fans with them, among other things.");
        set_property("lore difficulty",12);
        set_property("enchantment",4);
        set_item_bonus("attack bonus",2);
		set_item_bonus("damage resistance",2);
        set_value(2000);
        set_wield((:TO,"wield_func":));
        set_unwield((:TO,"unwield_func":));
        set_hit((:TO,"hit_func":));
}
int wield_func(string str) {
   if((int)ETO->query_lowest_level() < 25) {
        tell_object(ETO,"%^BOLD%^%^WHITE%^The fan refuses to be wielded by one as weak as
you!");
        return 0;
     }
        tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" smoothly opens the"+
                " fan with a flick of "+ETO->QP+" wrist.",ETO);
        tell_object(ETO,"%^BOLD%^%^WHITE%^You smoothly open the fan with "+
                "a flick of your wrist.%^RESET%^");
        return 1;
}
int unwield_func(string str) {
        tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" closes the fan in "+
                "a single fluid motion.",ETO);
        tell_object(ETO,"%^BOLD%^%^WHITE%^You close the fan in a single"+
                " fluid motion.%^RESET%^");
        return 1;
}
int hit_func(object targ){
        object ob2;
        targ = ETO->query_current_attacker();
        if(!objectp(ETO)) return 1;
        if(!objectp(targ)) return 1;
        if(random(1000) < 225){
        switch(random(50)){
case 0..35:
      tell_object(ETO,"%^BOLD%^%^WHITE%^The diamond dust border of your "+
                "fan slices easily through "+targ->QCN+".");
      tell_object(targ,"%^BOLD%^%^WHITE%^The glittering border of "+
                ""+ETO->QCN+"'s fan slices into you with ease.");
      tell_room(EETO,"%^BOLD%^%^WHITE%^The glittering border "+
                "of "+ETO->QCN+"'s fan slices into "+targ->QCN+" with"+
                " ease.", ({ETO,targ}));
                        set_property("magic",1);
						targ->cause_typed_damage(targ,0,roll_dice(1,6)+4,"slashing");
                        set_property("magic",-1);
        break;
case 36..46:
        tell_object(ETO,"%^BOLD%^%^CYAN%^%^You flick your wrist upwards, dragging"+
                " the diamond edge of the fan across "+targ->QCN+"'s chest.");
      tell_object(targ,"%^BOLD%^%^CYAN%^"+ETO->QCN+" gracefully flicks"+
                " "+ETO->QP+" wrist upwards, dragging the glittering edge"+
                " of "+ETO->QP+" fan across your chest!");
      tell_room(EETO,"%^BOLD%^%^CYAN%^"+ETO->QCN+" gracefully flicks"+
                " "+ETO->QP+" wrist upwards, dragging the glittering edge"+
                " of "+ETO->QP+" fan across "+targ->QCN+"'s chest.", ({ETO,targ}));
				targ->cause_typed_damage(targ,0,roll_dice(2,6)+4,"slashing");
                        ETO->execute_attack();
        break;
case 47..49:
        tell_object(ETO,"%^BOLD%^%^WHITE%^Diamond dust from the fan fuses "+
                "together to create a floating shard.");
      tell_room(EETO,"%^BOLD%^%^WHITE%^Diamond dust from"+
                " "+ETO->QCN+"'s fan fuses together to create a floating"+
                " shard.", ({ETO,targ}));
                ob2=new("/d/islands/argentrock/mon/diamond.c");
                ob2->move(EETO);
                ob2->force_me("protect "+ETO->query_name());
                ETO->add_follower(ob2);
        break;

default:  tell_object(ETO,"Uhoh, you broke it, you bought it.  Please "+
                "bug what you were doing when you got this message.");
        break;
        }
        return 1;
    }
}
