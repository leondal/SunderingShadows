/// Rise of the Mists by LoKi - August 2017
/// ----------------------------------------

#include <std.h>

//what type of weapon!
inherit "/d/common/obj/weapon/fan";

void create() 
{
    ::create();
    set_name("%^RESET%^%^CYAN%^Ri%^RESET%^s%^BLACK%^%^BOLD%^e %^RESET%^%^CYAN%^of "+
	"M%^RESET%^i%^RESET%^%^CYAN%^s%^BLACK%^%^BOLD%^t%^RESET%^%^CYAN%^s%^RESET%^");
    set_id(({"fan", "metal fan", "dark painted fan", "rise of mists"}));

//describes
    set_obvious_short("%^RESET%^%^CYAN%^dar%^BLACK%^%^BOLD%^k%^RESET%^%^CYAN%^ly "+
	"pa%^RESET%^i%^RESET%^%^CYAN%^nted %^BLACK%^%^BOLD%^f%^RESET%^%^CYAN%^an%^RESET%^");
    set_short("%^RESET%^%^CYAN%^Ri%^RESET%^s%^BLACK%^%^BOLD%^e %^RESET%^%^CYAN%^of "+
	"M%^RESET%^i%^RESET%^%^CYAN%^s%^BLACK%^%^BOLD%^t%^RESET%^%^CYAN%^s%^RESET%^");
    set_long("%^RESET%^%^CYAN%^This small fan is metal through its entire construction. "+
	"The frame is a %^BLACK%^%^BOLD%^black alloy%^RESET%^%^CYAN%^ of unknown origin "+
	"that is strong, almost %^RESET%^%^BOLD%^glossy%^RESET%^%^CYAN%^ in its finish. "+
	"When the fan is collapsed the %^BLACK%^%^BOLD%^frame %^RESET%^%^CYAN%^itself "+
	"becomes its protective case and is easy to hold in one hand. There is a small "+
	"%^RESET%^%^ORANGE%^spring %^RESET%^%^CYAN%^mechanism so that with a flick of "+
	"the wrist the fan expands and small %^RESET%^metal sections%^RESET%^%^CYAN%^ "+
	"click into place until the fan is a razor sharp semi circle. The surface of the "+
	"fan has been hand painted with a relief of a %^ORANGE%^mountaintop%^RESET%^%^CYAN%^ "+
	"obscured by %^RESET%^%^BOLD%^cloud%^RESET%^%^CYAN%^. The painting itself is a "+
	"masterpeice and it is hard to know if this is a weapon, or if it is art.%^RESET%^");
//lore
    set_lore("%^RESET%^%^MAGENTA%^There was a time when relations between the White "+
	"Fortress and the Ogre-magi were almost friendly, and some even learned of the "+
	"ogre-magi's culture and powers. Namely among them were the Sisters of Dusk, a "+
	"semi monastic order of rogues that had spent time learning in the far mountains. "+
	"When the darkness fell on the Night of Betrayal the Sisters of Dusk learned about "+
	"it far in advance. They were the first to Karon'dale, and the first to "+
	"fall.\n %^WHITE%^%^BOLD%^- From the history of Karon'dale, Our Shared Shame%^RESET%^");
    set_property("lore difficulty", 25);

//wields and unwields
    set_wield((:TP,"wieldme":));
    set_unwield((:TO,"unwieldme":));
    set_hit((:TO,"hit_special":));
//bonuses	
    set_item_bonus("dexterity", 6);
    set_item_bonus("perception", 6);
	set_property("enchantment",7);	
//other stuff
    set_value(4500);
}

int wieldme(){
	//message to player
    tell_object(ETO, "%^RESET%^%^CYAN%^You flick your wrist and the fan flows "+
	"into shape%^RESET%^");

	//message to room ETOCQN=name, ETO->QS= sex, 
    tell_room(EETO, ETOQCN +"%^RESET%^%^CYAN%^ flicks open the fan.%^RESET%^", ETO);
    return 1;
}

int unwieldme(){
	//message to player
    tell_object(ETO, "%^RESET%^%^CYAN%^With a flick of your wrist collapse the "+
	"fan.");
	//message to room ETOCQN=name, ETO->QS= sex, ETO->QP = posessive
    tell_room(EETO, ETOQCN +"%^RESET%^%^CYAN%^ turns "+ETO->QP+"%^RESET%^%^CYAN%^ "+
	"wrist and the fan collapses into itself.", ETO);
    return 1;
}

int hit_special(object targ){
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    if(!objectp(targ)) return 0;
    //special chance %
    if(random(1000) < 250)
    {
        switch(random(10))
        {
            case 0..5:
			// damage
                tell_object(ETO, "%^RESET%^%^RED%^With a quick step forward you slash "+
				"the %^BLACK%^%^BOLD%^razor sharp%^RESET%^%^RED%^ edge of the fan "+
				"along "+targ->QP+"%^RESET%^%^RED%^'s flesh. Blood streams from the "+
				"wound!%^RESET%^");
				tell_object(targ, ETOQCN +"%^RESET%^%^RED%^ quickly steps forward "+
				"and before you can react they slash their fan across your body%^RESET%^");
				tell_room(EETO, ETOQCN+"%^RESET%^%^RED%^ quickly steps forward towards "+targ->QCN+"%^RESET%^%^RED%^ "+
				"and slashes them with "+ETO->QP+"%^RESET%^%^RED%^ fan.", ({targ, ETO}));
	            targ->cause_typed_damage(targ, "head", roll_dice(3,10) + 5,"slashing");
			break;
			
			case 6..8:
			// trip
                tell_object(ETO, "%^RESET%^%^CYAN%^Holding the fan in front of you, "+
				"your vision %^RESET%^swims%^RESET%^%^CYAN%^ and ancient words come "+
				"unbidden to you. Whispering them you call forth a %^RESET%^%^BOLD%^mighty "+
				"torrent%^RESET%^%^CYAN%^ of wind from the %^ORANGE%^mountaintop%^RESET%^%^CYAN%^ "+
				"that drops "+targ->QCN+"%^RESET%^%^CYAN%^ to the ground!");
				tell_object(targ, ETOQCN +"%^RESET%^%^CYAN%^ Holds out a fan in front "+
				"of you and as their lips silently work a giant %^RESET%^%^BOLD%^rush "+
				"of air%^RESET%^%^CYAN%^ rushes out of the fan and knocks you to your knees!");
				tell_room(EETO, ETOQCN+"%^RESET%^%^CYAN%^ holds their fan in front of "+
				"them facing "+targ->QCN+" and whispers something. Suddenly a "+
				"%^RESET%^%^BOLD%^rush of air%^RESET%^%^CYAN%^ flows out of the fan, "+
				"knocking "+targ->QCN+" to the ground", ({targ, ETO}));
                targ->cause_typed_damage(targ, "head", roll_dice(6,10) + 10,"sonic");
                targ->set_tripped(1,"%^RESET%^%^BOLD%^You are still trying to catch "+
				"your breath.%^RESET%^");				
            break;
			
			case 9:
			// heal
                tell_object(ETO, "%^RESET%^%^MAGENTA%^You feel a rush of something "+
				"from the fan, you hear voices %^CYAN%^singing%^RESET%^%^MAGENTA%^, "+
				"and a %^RESET%^trail of mist%^RESET%^%^MAGENTA%^ escapes the "+
				"painting and trails around you binding your %^RED%^wounds%^RESET%^%^MAGENTA%^!%^RESET%^");
				tell_room(EETO, ETOQCN+"%^RESET%^%^MAGENTA%^ is suddenly envolped "+
				"in a %^RESET%^fine wet mist%^RESET%^%^MAGENTA%^! In a heartbeat "+
				"though the mist has cleared and they look refreshed!%^RESET%^", ({targ, ETO}));
                ETO->cause_typed_damage(ETO,"torso",(random(10)-30), "positive energy");
			break;
		}

}
}
