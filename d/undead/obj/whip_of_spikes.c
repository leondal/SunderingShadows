//Updated Desc and specials submitted by Rubican
//Updated by Cythera 9/05
#include <std.h>
#include <daemons.h>
#include "../undead.h"

inherit CWEAP"whip_dagger.c";

void create() {
    ::create();
    set_name("spiked whip");
    set_id(({"whip","demon whip","demon whip of spikes","whip of spikes", "spiked whip"}));
    set_obvious_short("%^RESET%^%^BOLD%^%^BLACK%^A long b%^RED%^a"+
	"%^BOLD%^%^BLACK%^rbed wh%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^p%^RESET%^");    
    set_short("%^RESET%^%^BOLD%^%^BLACK%^Kelvezu's %^RESET%^%^BLUE%^unh"+
		"%^BOLD%^o%^RESET%^%^BLUE%^ly%^BOLD%^%^BLACK%^ b%^RED%^a"+
		"%^BOLD%^%^BLACK%^rbed wh%^RESET%^%^WHITE%^i"+
		"%^BOLD%^%^BLACK%^p%^RESET%^");
    set_long("%^RESET%^%^BOLD%^%^BLACK%^This is a long b"+
	"%^BOLD%^%^RED%^a%^BLACK%^rbed wh%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^p "+
	"made from the coiled fl%^RED%^e%^BLACK%^sh %^RED%^o%^BLACK%^f ang"+
	"%^BOLD%^%^RED%^e%^BLACK%^ls that has been twisted to %^RESET%^"+
	"%^BLUE%^d%^BOLD%^a%^RESET%^%^BLUE%^rkness%^BOLD%^%^BLACK%^ by "+
	"the utter evil of its creation.  The flesh is laced in a spider "+
	"web of %^RESET%^%^RED%^b%^BOLD%^lo%^RESET%^%^RED%^od r%^BOLD%^"+
	"e%^RESET%^%^RED%^d ve%^BOLD%^i%^RESET%^%^RED%^ns%^BOLD%^%^BLACK%^ "+
	"that seem to pulse with an %^BOLD%^%^RED%^unholy aura%^BLACK%^."+
        "  The %^BOLD%^%^WHITE%^bones of angels%^BLACK%^ have been "+
        "sharpened to fashion %^RED%^demonic barbs%^BOLD%^%^BLACK%^ that "+
        "run the length of this foul weapon.  Its handle is made of tightly"+
        " coiled angel's flesh, ending in a lifelike dark black widow spider "+
        "made of adamantium with an hourglass-shaped %^RED%^ruby"+
        "%^BOLD%^%^BLACK%^ set in its back.%^RESET%^");
    set_property("lore","%^RESET%^%^BOLD%^%^BLACK%^This whip is one of "+
	"many unholy weapons created by the demons of the pits of hell in"+
	" their numerous wars against the holy creatures of the planes. "+
	"Created by the most powerful dark magic of the demonic warlocks "+
	"in unspeakably evil rituals, these weapons turn the power of the "+
	"holy angels they are made from and the anguish of tortured souls "+
	"into unholy weapons of vengeance. It is said that entire choirs of "+
	"angels have fallen to make these weapons, the demons taking the "+
	"most powerful of the angels they slay to be used against their "+
	"brethren in later battles. Usually not seen in the hands of "+
	"anything but demons powerful enough to slay archangels, usually "+
	"the demonic assassins, the Kelvezu, these dark weapons have been "+
	"rumored to be found in the hands of mortals that have made dark "+
	"pacts with the Kelvezu in exchange for one of these powerful "+
	"weapons.");
    set_value(1200);
    set_property("enchantment",3);
    set_wield((: TO,"extra_wield" :));
    set_unwield((: TO,"extra_unwield" :));
    set_hit((: TO,"hit_func" :));
}

int extra_wield() 
{
     if(ALIGN->is_good(ETO)) {
                tell_object(ETO,"The whip rejects one with your pure nature!");
                return 0;
        }
        if((int)ETO->query_lowest_level() < 20) {
                tell_object(ETO,"The whip seems to want one more experienced"+
                " than yourself.");
                return 0;
        }
     if(ETO->query_property("good item")) {
      tell_object(ETO,"The whip refuses to be wielded while you have "+
		"such goodly items!");
      return 0;
     }
    tell_object(ETO,"%^BOLD%^%^BLACK%^You soul is filled with the"+
		" %^RED%^anguish%^BOLD%^%^BLACK%^ of souls long dead!%^RESET%^");
    tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" grins an anguished "+
		"filled smile as "+ETO->QP+" fingers wrap around the handle"+
		" of the whip.%^RESET%^",ETO);
	 	ETO->set_property("evil item",1);
    return 1;
}

int extra_unwield() {
    tell_object(ETO,"%^BOLD%^%^BLACK%^You feel the souls' anguish"+
		" %^BLUE%^slither%^BOLD%^%^BLACK%^ free of your soul.");
    tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" less grim and morose"+
		" as "+ETO->QP+" fingers slip from the handle of "+
		"the whip.%^RESET%^",ETO);
    	ETO->set_property("evil item",-1);
	return 1;
}

int hit_func(object victim) 
{
   	if(!objectp(TO)) return 1;
   	if(!objectp(ETO)) return 1;
   	if(!objectp(victim)) return 1;
   	if(random(1000) < 150)
    {
        switch(random(50))
        {
	
        case 0..34:
              tell_object(ETO,"%^RED%^You coil the whip around "+victim->QCN+","+
                " imbedding the spikes into "+victim->QP+" flesh.");
              tell_object(victim,"%^RED%^"+ETO->QCN+" coils "+ETO->QP+" around"+
                " you, imbedding the spikes deep into your flesh.",);
              tell_room(environment(ETO),"%^RED%^"+ETO->QCN+" coils"+
                " "+ETO->QP+" whip around "+victim->QCN+", imbedding"+
                " the spikes into "+victim->QP+" flesh.",({ETO,victim}));
                    victim->do_damage("torso",random(6)+3);
            break;
        case 35..40:
            tell_object(ETO,"%^BOLD%^%^BLACK%^You crack your whip at"
                " "+victim->QCN+", stunning "+victim->QO+" long "+
                "enough for you to come through with a second attack.");
            tell_object(victim,"%^BOLD%^%^BLACK%^"+ETO->QCN+" cracks"+
                " "+ETO->QP+" at you swiftly, the sound stuns you "+
                "for a brief moment, opening your guard up to a "+
                "second attack!");
            tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+" "+
                "cracks "+ETO->QP+" whip at "+victim->QCN+", "+
                "stunning "+victim->QO+" for a brief moment.\n"+
                ""+ETO->QCN+" follows through with a second attack, "+
                "snapping "+ETO->QP+" whip at "+victim->QCN+".",({ETO,victim}));
                    ETO->execute_attack();
            break;
        case 41..49:
            tell_object(ETO,"%^BOLD%^%^RED%^You snap the tip of your whip"+
                " into "+victim->QCN+"'s groin.\n"+victim->QCN+" lets "+
                "out a whimpering cry as "+victim->QS+" is overcome with pain.");
            tell_object(victim,"%^BOLD%^%^RED%^"+ETO->QCN+" snaps the tip of"+
                " "+ETO->QP+" whip into your groin!\n%^B_RED%^%^BOLD%^%^RED%^OH "+
                "THE PAIN!!!!%^RESET%^",);
            tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->QCN+" snaps"+
                " the tip of "+ETO->QCN+" whip into "+victim->QCN+"'s "+
                "groin.\n"+victim->QCN+" lets out a whimerping cry as"+
                " "+victim->QS+" is overcome with pain.",({ETO,victim}));
                    victim->do_damage("torso",random(5)+5);
                    victim->set_tripped(1,"%^RED%^You're still in pain right now!");
            break;

        default:  tell_object(ETO,"%^BOLD%^%^RED%^Congrats, Turbo.  You get"+
            " the special screwed up message.  Please bug report this"+
            " and what you were doing/fighting when you got this message.");
            break;
        }
    }
    
    return 1;
}

