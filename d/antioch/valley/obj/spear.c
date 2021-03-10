//Added lore, gave an inherit and short - Cythera 4/05\\
#include <std.h>
#include "../valley.h"
inherit "/d/common/obj/weapon/spear_lg.c";

void create()
{
	::create();
	set_name("large spear");
	set_id(({"spear","large spear","long spear","wooden spear", "bloodstained spear","bloodbath spear"}));
	set_obvious_short("%^RED%^A bloodstained long spear%^RESET%^");
	set_short("%^RESET%^%^RED%^Bloodbath Spear%^RESET%^");
	set_long("%^ORANGE%^This is a very long wooden spear. The wood looks strong"+
   		" and heavy, it would not break easily. The spear tip"+
		" joins smoothly with the shaft and is made out of some"+
		" strong metal. It looks quite sharp and deadly in the"+
		" right hands.  The wood and metal are covered with"+
		" %^RED%^blood%^ORANGE%^ stains.");
	//set_size(3);
	//set_type("pierce");
	//set_prof_type("large spear");
	//set_wc(1,6);
	//set_large_wc(1,8);
	//set_weight(5);
	set_property("enchantment",2+random(2));
	set_hit((:TO, "hitme":));
	set_value(180);
	set_wield((:TO, "wieldme":));
}

int wieldme()
{
	if(ETO->query_level() < 10) {
		tell_object(ETO,"You are not experienced enough to use such a weapon.");
		return 0;
	}
	else {
		return 1;
	}
}


int hitme(object targ)
{
	if(!objectp(targ)) return 1;

	if(!random(6)) {
		tell_room(environment(query_wielded()),
		"%^ORANGE%^"+ETO->QCN+" lands a crushing blow on"+
		" "+targ->QCN+".",({ETO,targ}));
		tell_object(ETO, "%^ORANGE%^You land a crushing blow on "+targ->QCN+".");
		tell_object(targ,
		"%^ORANGE%^"+ETO->QCN+" lands a crushing blow on you.");
		targ->do_damage("torso",random(4)+1);

	return 3;
	}
	if(!random(10)) {
		tell_room(environment(query_wielded()),
		"%^RED%^"+ETO->QCN+" slams "+ETO->QP+""+
		" spear into "+targ->QCN+" stomach.",({ETO,targ}));
		tell_object(ETO, "%^RED%^You slam your spear into"+
		" "+targ->QCN+"'s stomach.");
		tell_object(targ,
		"%^RED%^"+ETO->QCN+" slams "+ETO->QP+""+
		" spear into your stomach.");
		targ->do_damage("torso",random(6)+2);
		return 6;
	}
	if(!random(15)) {
		tell_room(environment(query_wielded()),
		"%^RED%^"+ETO->QCN+" streaks"+
		" "+ETO->QP+" spear out lightning fast"+
		" and slips it under "+targ->QCN+"'s guard"+
		" to land a crushing on "+targ->QP+".",({ETO,targ}));
		tell_object(ETO, "%^RED%^The spear almost seems to guide"+
		" your hand out incredibly fast, slipping itself under"+
		" "+targ->QCN+"'s guard to score a crushing"+
		" blow.");
		tell_object(targ, "%^RED%^"+ETO->QCN+""+
		" streaks "+ETO->query_possessive()+" spear out"+
		" lightning fast to slip it under your guard and score"+
		" a crushing blow against you.");
		targ->do_damage("torso",random(5)+5);
	}
}
