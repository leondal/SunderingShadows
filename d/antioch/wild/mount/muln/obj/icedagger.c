//Coded by Bane//
//Add new desc, lore, and updated older code - Cythera 3/27/05
#include <std.h>
inherit "/d/common/obj/weapon/dagger.c";
void create(){
    	::create();
    	set_id(({"dagger","ice dagger"}));
    	set_name("Ice Dagger");
    	set_obvious_short("%^BOLD%^%^WHITE%^An i%^CYAN%^c%^WHITE%^e da%^CYAN%^gg%^WHITE%^er%^RESET%^");
	set_short("%^BOLD%^%^WHITE%^Da%^CYAN%^gg%^WHITE%^er of I%^CYAN%^c%^WHITE%^e%^RESET%^");
    	set_long("%^BOLD%^%^WHITE%^Shaped from a solid piece of "+
		"%^CYAN%^ice%^WHITE%^, this serrated dagger looks "+
		"vicious and deadly.  The shards of ice are formed "+
		"in a way to rip open the flesh while the cold "+
		"dagger freezes the blood.  The thick ice is "+
		"cloudy, hiding what may be hidden within the "+
		"ice.  Though clouds of condensation rise off the"+
		" dagger, it does not seem to melt.  White silk "+
		"strips are wound around the hilt of the dagger, "+
		"to protect ones hand from frostbite.  The patterned"+
		" silk features images of %^CYAN%^snowflakes%^WHITE%^"+
		" stitched into the cloth.%^RESET%^\n");
	set_lore("Created by Jansark the White Ghost, an assassin "+
		"of The Frost Maiden, these icy daggers served to "+
		"bring the might of the winter to the rogue's targets."+
		"  Each winter it was said that Jansark traveled to the"+
		" north to collect perfect sections of ice to create his"+
		" daggers.  Enchanted to resist heat and melting, these"+
		" daggers have been found in the backs of countless people"+
		" throughout the ages.");
	set_property("lore difficulty",8);
    set_value(2000);
    set_large_wc(1,4)+1;
    set_property("enchantment",4);
    set_item_bonus("cold resistance",25);
    set_item_bonus("damage bonus",2);
	set_wield("%^BOLD%^%^CYAN%^Clouds of vapor rise off the dagger as you wield it.");
   	set_unwield("%^BOLD%^%^CYAN%^You find a safe and secure place to stash the dagger.");
      set_hit( (:TO,"extra_hit":) );
}
int extra_hit(object ob){
    int roll, roll2, roll3;
    if(!objectp(ob)) return 0;
    roll=random(100)+1;
    roll2=random(20)+1;
    roll3=random(10)+1;
    if(roll > 70){
	if(roll > 70 && roll < 80){
		tell_object(ETO,"%^BOLD%^%^BLUE%^An aura of arctic"+
			" cold surrounds your dagger as you slice into"+
			" "+ob->QCN+".");
		tell_object(ob,"%^BOLD%^BLUE%^"+ETOQCN+"'s dagger"+
			" slices into you with an arctic chill!");
         	tell_room(environment(ETO),"%^BOLD%^BLUE%^"+ETOQCN+"'s "+
			"dagger glows a brilliant blue as it cuts into"+
			" "+ob->QCN+"!",({ob,ETO}));
				ETO->cause_typed_damage(ETO, 0, roll_dice(1, 4), "cold");
	    	return 1;
	}
	if(roll > 79 && roll < 90){
	    if(roll3 > 5){
	    tell_object(ob,"%^BOLD%^CYAN%^A terrible chill overcomes"+
			" you as the dagger slices through you!");
         	tell_room(environment(ETO),"%^BOLD%^CYAN%^"+ob->QCN+" "+
			"shivers terribly as "+ETOQCN+"'s dagger slices "+
			"through "+ob->QO+"!",({ob,ETO}));
		tell_object(ETO,"%^BOLD%^%^CYAN%^You slice into "+
			""+ob->QCN+", chilling "+ob->QO+" to the core"+
			" with your dagger.");
				ob->set_paralyzed(20,"You are too cold to move.");
	    return 1;
	    }
	return 1;
	}
    	if(roll > 89){
	    if(roll2 > 19){
		tell_object(ob,"%^BOLD%^You are impaled by "+ETOQCN+"'s "+
			"ice dagger.  The dagger shatters, covering you with"+
			" a layer of frost!");
		tell_room(environment(ETO),"%^BOLD%^"+ob->QCN+" is impaled"+
			" by "+ETOQCN+"'s dagger and it shatters, "+
			"covering "+ob->QO+" with a layer of frost!",({ob,ETO}));
		tell_object(ETO,"%^BOLD%^You impale "+ob->QCN+" with your"+
			" dagger.  The dagger shatters into countless "+
			"shards and coats "+ob->QO+" with a layer of "+
			"frost.");
				ETO->cause_typed_damage(ETO, 0, roll_dice(10, 4), "cold");
				TO->remove();
		return 1;
	    }
	return 1;
	}
    return 0;
    }
}
