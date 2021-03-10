#include <std.h>
#include "../ruins.h"
inherit "/d/common/obj/armour/scale.c";

string owner;

void create()
{
	::create();
	set_name("serpent scales");
	set_obvious_short("%^BOLD%^%^BLUE%^A suit of serpent scales%^RESET%^");
	set_short("%^BOLD%^%^BLUE%^S%^CYAN%^e%^RESET%^%^BLUE%^r%^BOLD%^p"+
		"%^CYAN%^e%^RESET%^%^BLUE%^n%^BOLD%^t%^CYAN%^ Scale Mail");
	set_id(({"serpent scales","scale mail","suit of serpent scales","+
		""suit of scales","scales","serpent_mail"}));
	set_long("%^CYAN%^This suit of armor looks very regal with its"+
		" deep %^BLUE%^blue coloring%^CYAN%^.  The scale mail "+
		"armor looks as if it would keep the wearer well "+
		"protected.  Large scales, which have been well "+
		"polished and cared for have been shaped to form "+
		"the cuirass of the armor.  Scaled short sleeves "+
		"have been attached to the cuirass.  A high outward"+
		" curved collar of scaled leather offers protection"+
		" to ones neck.   Curved shoulder plates stand out from"+
		" the sides of the plate, shaped from larger scales.  "+
		"A %^BLUE%^%^BOLD%^blue%^RESET%^%^CYAN%^ leather shirt"+
		" lines the inside of the armor, to cushion the blows.  "+
		"The long sleeve shirt also offers protection to the arms."+
		"  A skirt of%^BLUE%^ scaled leather%^CYAN%^ offers protection"+
		" to ones legs.  Skirts are not an uncommon theme in armor, "+
		"for both sexes, because of the added protection and the "+
		"freedom of movement.  A kite shaped scaled %^BLUE%^loincloth"+
		"%^CYAN%^ reinforces the split skirt over the groin.  The scales"+
		" on the armor clink together in a %^BOLD%^melodic%^RESET%^%^CYAN%^"+
		" fashion.%^RESET%^\n"	);
	set_lore("The Serpent Scale Plate is rumored of have been crafted"+
		" from the scales of the Immortal Serpent, Svrrl.  Rumors say"+
		" that Svrrl is a creature from another plane traped in this "+
		"world by an wizard of Old Antioch.  With the fall of the city,"+
		" it is said that Svrrl found herself trapped here.  Rumors "+
		"whisper that each night Svrrl is restored to life and healthy,"+
		" not that many ever get the chance to kill such a deadly creature."+
		"  To have armor made from her scales is a glorious feat indeed!");
	set_property("lore",13);
	set_property("enchantment",3);
	set_item_bonus("magic resistance",7);
	set_value(12000);
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
	set_struck((:TO,"strikeme":));
}

int wearme()
{
	if(owner != (string)TPQN) {
		tell_object(ETO,"This armor was made for "+owner+" and does not fit you.");
		return 0;
	}
	tell_object(ETO,"%^BOLD%^%^CYAN%^The scales clink together musically as"+
		" you don the armor.");
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^The scales clink together in"+
		" a musical fashion as "+ETO->QCN+" dons the scale mail.",ETO);
	return 1;
}

int removeme()
{
	tell_object(ETO,"%^BOLD%^%^BLUE%^You remove the scales with reluctance, they"+
		" kept you cool and protected during battle.");
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^With some reluctance "+ETO->QCN+""+
		" removes "+ETO->QP+" scale mail.",ETO);
	return 1;
}

int strikeme(int damage, object what, object who)
{
	if(objectp(what)) {
		tell_object(ETO,"%^BLUE%^The serpent scales clink together as they"+
		" are struck by the "+what->query_name()+".");
	}
	if(!random(5)) {
		tell_object(ETO,"%^CYAN%^The serpent scales ring musically as "+who->QCN+""+
		" strikes them.");
		tell_object(who,"%^CYAN%^The serpent scales ring musically as you"+
		" strike them.");
		tell_room(environment(ETO),"%^CYAN%^The serpent scales ring musically"+
		" as "+who->QCN+" hits them ineffectively.",({who,ETO}));
		return (-1)*(damage);
	}
	return 1;
}

void set_owner(string str)
{
	owner = str;
}
