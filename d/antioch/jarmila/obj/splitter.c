/// splitter of mountains by LoKi - August 2017
/// ----------------------------------------

#include <std.h>

//what type of weapon!
inherit "/d/common/obj/weapon/spear_lg";

void create() 
{
    ::create();
    set_name("%^BLACK%^%^BOLD%^Spli%^RESET%^t%^BLACK%^%^BOLD%^ter "+
	"of Mou%^RESET%^%^ORANGE%^n%^BLACK%^%^BOLD%^tai%^RESET%^"+
	"%^ORANGE%^ns%^BLACK%^%^BOLD%^");
    set_id(({"spear", "diamond spear", "splitter of mountains","Splitter of Mountains"}));

//describes
    set_obvious_short("%^BLACK%^%^BOLD%^dia%^RESET%^%^BOLD%^m%^BLACK%^%^BOLD%^ond "+
	"s%^RESET%^%^BOLD%^p%^BLACK%^%^BOLD%^ear%^RESET%^");
    set_short("%^BLACK%^%^BOLD%^Spli%^RESET%^t%^BLACK%^%^BOLD%^ter of Mou%^RESET%^%^ORANGE%^n"+
	"%^BLACK%^%^BOLD%^tai%^RESET%^%^ORANGE%^ns%^BLACK%^%^BOLD%^");
    set_long("%^BLACK%^%^BOLD%^This spear, with a handle over two inches in diameter and "+
	"long enough that it would take a man two hands to wield it properly, is a sight to "+
	"behold. The shaft is carved from a %^RESET%^pitch black wood%^BLACK%^%^BOLD%^ engraved "+
	"with tribal markings and notches that shimmer in the light. Along several "+
	"lengths %^RESET%^%^RED%^dark red leather%^BLACK%^%^BOLD%^ has been wrapped for "+
	"grip and a cord ties half way adorned with small rocks. The tip of the spear is "+
	"an unpolished %^RESET%^%^BOLD%^diamond shard%^BLACK%^%^BOLD%^ a foot in length. The "+
	"shard itself is wickedly sharp and hasthe same odd glint in the "+
	"%^RESET%^light%^BLACK%^%^BOLD%^. The worth of the diamond should "+
	"it have been polished for jewelry would be immense, but its value "+
	"for death even more.%^RESET%^");
//lore
    set_lore("%^RED%^%^BOLD%^The Wemic tribes northwest of the Red Fortress are relentless. "+
	"The waves of their warriors against the walls is a constant threat and your mercenary "+
	"company hired to defend it do not seem up to the task. The wemics obviously see the "+
	"wall as a challege and will stop at nothing to remove it, and Karon'dale. Redouble "+
	"your efforts Commander Kava.\n %^RESET%^%^BOLD%^- Missive from Chancellor %^RESET%^"+
	"Ichibod Cosette%^RESET%^");
    set_property("lore difficulty", 25);

//wields and unwields
    set_wield((:TP,"wieldme":));
    set_unwield((:TO,"unwieldme":));
    set_hit((:TO,"hit_special":));
//bonuses	
    set_item_bonus("strength", 6);
    set_item_bonus("endurance", 6);
	set_property("enchantment",7);
	
//other stuff
    set_value(4500);
}

int wieldme(){
	//message to player
    tell_object(ETO, "%^RESET%^%^RED%^You heft the spear and feel your body rush with "+
	"energy. Your blood boils and you can almost taste battle!%^RESET%^");

	//message to room ETOCQN=name, ETO->QS= sex, 
    tell_room(EETO, ETOQCN +" %^RESET%^%^RED%^seems to stand taller "+
	"as "+ETO->QS+"%^RESET%^%^RED%^ grips the spear!%^RESET%^", ETO);
    return 1;
}

int unwieldme(){
	//message to player
    tell_object(ETO, "%^RESET%^%^RED%^As you let go of the spear you feel drained.%^RESET%^");
	//message to room ETOCQN=name, ETO->QS= sex, ETO->QP = posessive
    tell_room(EETO, ETOQCN +" %^RESET%^%^RED%^slumps as they let go of the spear.%^RESET%^", ETO);
    return 1;
}

int hit_special(object targ){
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    if(!objectp(targ)) return 0;
    //special chance %
    if(random(1000) < 275)
    {
        switch(random(10))
        {
            case 0..8:
                tell_object(ETO, "%^BLACK%^%^BOLD%^You take the shaft of the spear "+
				"and slam it against "+targ->QP+"%^BLACK%^%^BOLD%^'s body with all your strength!%^RESET%^");
				tell_object(targ, "%^BLACK%^%^BOLD%^You reel for a moment as "+ETO->QCN+" %^BLACK%^%^BOLD%^slams "+
				"the shaft of their spear against you!%^RESET%^");
				tell_room(EETO, ETOQCN+" %^BLACK%^%^BOLD%^turns their body and with all their strength "+
				"slams the shaft of the spear against "+targ->QCN+"%^BLACK%^%^BOLD%^!%^RESET%^", ({targ, ETO}));
				targ->cause_typed_damage(targ, "torso", roll_dice(6, 10) + 10,"bludgeoning");
			break;

			case 9:
                tell_object(ETO, "%^RED%^%^BOLD%^With a mighty %^YELLOW%^scream%^RED%^%^BOLD%^ you thrust "+
				"the diamond tip right through "+targ->QP+"%^RED%^%^BOLD%^'s body pinning them to the ground!%^RESET%^");
				tell_object(targ, "%^RED%^%^BOLD%^You look over in time to "+
				"see "+ETO->QCN+" %^RED%^%^BOLD%^impale you against the ground with their spear!%^RESET%^");
				tell_room(EETO, ETOQCN+" %^RED%^%^BOLD%^impales "+targ->QCN+" %^RED%^%^BOLD%^against "+
				"the ground with their diamond spear!%^RESET%^", ({targ, ETO}));
				targ->cause_typed_damage(targ, "torso", roll_dice(8, 10) + 12,"piercing");
				targ->set_tripped(2,"%^RESET%^%^ORANGE%^You are still pinned to the ground.%^RESET%^");
			break;
		}

}
}
