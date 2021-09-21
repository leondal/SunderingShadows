/// eater of light by LoKi - August 2017
/// ----------------------------------------

#include <std.h>

//what type of weapon!
inherit "/d/common/obj/weapon/lance";

void create() 
{
    ::create();
    set_name("Eater of Light");
    set_id(({"lance", "black metal lance", "Eater of Light"}));

//describes
    set_obvious_short("%^BLACK%^%^BOLD%^black met%^RESET%^a%^BLACK%^%^BOLD%^l la%^RESET%^n%^BLACK%^%^BOLD%^ce%^RESET%^");
    set_short("%^BLACK%^%^BOLD%^Eat%^RESET%^e%^BLACK%^%^BOLD%^r of Li%^RESET%^%^MAGENTA%^g%^BLACK%^%^BOLD%^ht%^RESET%^");
    set_long("%^BLACK%^%^BOLD%^This heavy lance, at least ten feet in length, "+
	"is %^RESET%^%^MAGENTA%^death%^BLACK%^%^BOLD%^ in metal form. It has been "+
	"%^RESET%^forged%^BLACK%^%^BOLD%^ from some black metal that has no "+
	"%^RESET%^%^BOLD%^shine%^BLACK%^%^BOLD%^ or %^RESET%^sheen%^BLACK%^%^BOLD%^ "+
	"or %^RESET%^%^RED%^machine marks%^BLACK%^%^BOLD%^ on it. The entire tapered "+
	"length is devoid of decoration and even as you watch it, it seems to suck in "+
	"the %^RESET%^%^BOLD%^light%^BLACK%^%^BOLD%^ around it creating a %^RESET%^hazy "+
	"effect%^BLACK%^%^BOLD%^. The tip of the lance is sharp enough that you cannot "+
	"discern where exactly the tip is and running a hand along it is a "+
	"guarenteed %^RED%^cut%^BLACK%^%^BOLD%^. The lance lapers to a large guard "+
	"for protecting the wielder in a charge and a long handle is wrapped in "+
	"%^RESET%^%^ORANGE%^firm leather%^BLACK%^%^BOLD%^ for a proper grip.%^RESET%^%^RESET%^");
//lore
    set_lore("%^RED%^%^BOLD%^The worst of mankind are not those who serve the mercenary "+
	"companies, or the bandit groups, or even the murderers in the alleys. The worst "+
	"bent the knee to the Oni of the southern forests and serve them as thralls. "+
	"Those are lost souls now, and could never hope to be saved. Even when Erik Kathor "+
	"came he admitted that he was powerless over the effect the Oni have on the "+
	"Shadowed Knights.\n %^RESET%^%^BOLD%^- Excerpt from 'The Oni March' %^RESET%^"+
	"Ichibod Cosette%^RESET%^");
    set_property("lore difficulty", 25);
	set_item_bonus("attack bonus",4);
    set_item_bonus("damage bonus",4);

//wields and unwields
    set_wield((:TP,"wieldme":));
    set_unwield((:TO,"unwieldme":));
    set_hit((:TO,"hit_special":));
//bonuses	
        set_property("enchantment",7);
	
//other stuff
    set_value(4500);
}

int wieldme(){
	//message to player
    tell_object(ETO, "%^BLACK%^%^BOLD%^As you wield the lance you feel it pull against you and shudder!%^RESET%^");

	//message to room ETOCQN=name, ETO->QS= sex, 
    tell_room(EETO, ETOQCN +" %^RESET%^%^RED%^The air around"+
	" "+ETO->QP+"%^RESET%^%^RED%^ seems to darken as they wield the lance!%^RESET%^", ETO);
    return 1;
}

int unwieldme(){
	//message to player
    tell_object(ETO, "%^BLACK%^%^BOLD%^As you let go of the lance light seems to return to the room.%^RESET%^");
	//message to room ETOCQN=name, ETO->QS= sex, ETO->QP = posessive
    tell_room(EETO, ETOQCN +" can be seen clearer as they let go of the lance.%^RESET%^", ETO);
    return 1;
}

int hit_special(object targ){
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    if(!objectp(targ)) return 0;
    //special chance %
    if(random(1000) < 200)
    {
        switch(random(10))
        {
            case 0..8:
                tell_object(ETO, "%^BLACK%^%^BOLD%^The whole of the lance shudders and a stream of black light pours out "+
				"to slam against "+targ->QP+"%^BLACK%^%^BOLD%^'s body tearing them apart!%^RESET%^");
				tell_object(targ, "%^BLACK%^%^BOLD%^You reel for a moment as "+ETO->QCN+" %^BLACK%^%^BOLD%^'s "+
				"lance erupts in a shaft of black light against you!%^RESET%^");
				tell_room(EETO, ETOQCN+" %^BLACK%^%^BOLD%^ shoots a shaft of black light from their "+
				"lance that tears into "+targ->QCN+"%^BLACK%^%^BOLD%^!%^RESET%^", ({targ, ETO}));
				targ->cause_typed_damage(targ, "torso", roll_dice(2,6),"piercing");
			break;

			case 9:
                tell_object(ETO, "%^RED%^%^BOLD%^With a mighty %^YELLOW%^scream%^RED%^%^BOLD%^ you thrust "+
				"the lance through "+targ->QP+"%^RED%^%^BOLD%^'s body pinning them to the ground!%^RESET%^");
				tell_object(targ, "%^RED%^%^BOLD%^You look over in time to "+
				"see "+ETO->QCN+" %^RED%^%^BOLD%^impale you against the ground with their lance!%^RESET%^");
				tell_room(EETO, ETOQCN+" %^RED%^%^BOLD%^impales "+targ->QCN+" %^RED%^%^BOLD%^against "+
				"the ground with their lance!%^RESET%^", ({targ, ETO}));
				targ->cause_typed_damage(targ, "torso", roll_dice(5,6),"piercing");
				targ->set_tripped(2,"%^RESET%^%^ORANGE%^You are still pinned to the ground.%^RESET%^");
			break;
		}

}
}
