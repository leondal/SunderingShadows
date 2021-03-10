//Cleaned up owner code Octothorpe 5/28/09
//Added Lore - Cythera 4/05
#include <std.h>
#include "../ruins.h"
inherit "/d/common/obj/armour/fullplate.c";

string my_owner;

void create()
{
	::create();
	set_name("%^BOLD%^%^BLACK%^Armor of Ebony%^RESET%^");
	set_short("%^BOLD%^%^BLACK%^Armor of Ebony%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A suit of ebony black full plate%^RESET%^");
	set_id(({"armor of ebony","plate","ebony plate","armour","Armor of Ebony","full plate","ebony armor","armor"}));
	set_long(
	"%^BOLD%^%^BLACK%^This full plate has been crafted from black steel, it is"+
	" so dark in color that it has been called ebony. The workmanship of the"+
	" armor is flawless, there is not a seam out of place. There are also no"+
	" scratches or dents in the beautiful armor. A black steel tasset is "+
        "attached around the middle section of the armor, with stylish etchings"+
        " running deep into the metal.  Three black leather strips run down the"+
        " front of the tasset, with the center one falling longer.  The leather"+
        " strips are studded with darksteel accents.  Black steel shoulder guards"+
        " connect to the breastplate with spiraling spikes rising forth from the metal."+
        "It is truly a masterpiece, fit for nobility. %^RESET%^"
	);
	set_lore("Commissioned for Holy Inquisitor Barethel Del'Forez , "+
		"the Ebony Armor was a gift present from the church of "+
		"torture.  Sir Barethel had a successful career in spreading"+
		" the fear and pain of his Mistress to those in the lands.  "+
		"With his barbed lance, Sir Barethel delighted in charging "+
		"into combat, usually against peasant folk that he called "+
		"'animals'.  The arrogant noble son helped develop a few "+
		"creative means of torture that the faith still"+
		" practices to this day.");
	set_property("lore",13);  
	set_value(15000);
	set_property("enchantment",2);
	set_item_bonus("damage resistance",1);
	set_item_bonus("sight bonus",1);
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
	set_struck((:TO,"strikeme":));
}

void init()
{
   ::init();
   if(stringp(owner)) return;
   if(interactive(TP) && TP == ETO){
      my_owner = TPQN;
   }
}

int wearme()
{
   if(!userp(ETO) && (string)ETO->query_name() == "Vakloshx") return 1;
   if(interactive(TP) && my_owner != (string)TPQN){
		tell_object(ETO,"%^BLUE%^As you attempt to slip the armor on, your"+
		" body feels as though it is encased in liquid ice!");
		tell_room(environment(ETO),"%^BLUE%^"+ETO->QCN+" howls"+
		" in pain as "+ETO->QS+" tries to slip on the armor.",ETO);
		set_property("magic",1);
		ETO->do_damage("torso",random(20)+30);
		ETO->add_attacker(TO);
		ETO->continue_attack();
		ETO->remove_attacker(TO);
		remove_property("magic");
		return 0;
	}
   if((int)ETO->query_base_stats("charisma") < 13) {
		tell_object(ETO,"The armor rejects you!");
		return 0;
	}
   if(ETO->query_property("good item")) {
      tell_object(ETO,"The ebony armor refuses to be worn while you're using such goodly items!");
      return 0;
   }else{
	tell_object(ETO,"%^BOLD%^%^BLACK%^You can't help but feel rather arrogant"+
	" as you slip this lovely armor on.");
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+""+
	" holds "+ETO->QP+" head up high as "+ETO->QS+""+
	" slips into the ebony armor.",ETO);
   ETO->set_property("evil item",1);
	return 1;
   }
}

int removeme()
{
	tell_object(ETO,"%^MAGENTA%^You reluctantly slip out of the fine armor,"+
	" feeling not quite as regal as before.");
   ETO->set_property("evil item",-1);
	return 1;
}

int strikeme(int damage, object what, object who)
{
	if(!random(5)) {
		if(objectp(what)) {
			tell_object(ETO,"%^BOLD%^%^BLUE%^The Armor of Ebony deflects"+
			" the "+what->query_name()+" harmlessly.");
                        return (-1)*(damage/4);
		}
		tell_object(ETO,"%^BOLD%^%^BLACK%^The Armor of Ebony seems to cool"+
		" you down, easily deflecting "+who->QCN+"'s pathetic"+
		" blows against you.");
		tell_object(who,"%^BOLD%^%^BLACK%^"+ETO->QCN+" seems"+
		" unperturbed as your blows deflect harmlessly off "+ETO->QP+""+
		" armor.");
		tell_room(environment(query_worn()),"%^BOLD%^%^BLACK%^"+ETO->QCN+""+
		" seems unperturbed as "+who->QCN+"'s blows deflect"+
		" harmlessly off "+ETO->QP+" armor.",({ETO,who}));
                return (-1)*(damage);
	}
	return 1;
}