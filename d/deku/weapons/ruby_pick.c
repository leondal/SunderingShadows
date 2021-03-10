#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/pick";

int charges, perm;

void create(){
	::create();
	set_name("ruby pick");
	set_id(({ "pick", "ruby pick" }));
	set_short("%^BOLD%^%^RED%^J%^YELLOW%^a%^BOLD%^%^RED%^v"+
	"%^YELLOW%^ii%^BOLD%^%^RED%^s%^YELLOW%^ee%^BOLD%^%^RED%^s's R%^YELLOW%^u"+
	"%^BOLD%^%^RED%^by p%^YELLOW%^i%^BOLD%^%^RED%^ck%^RESET%^");
	set_obvious_short("A ruby pick");
	
	set_long("%^BOLD%^%^RED%^This small pick has been forged from a "+
	"pure and almost translucent r%^YELLOW%^u%^BOLD%^%^RED%^by.  Its "+
	"entire length is a little more than one foot and most of that is "+
	"composed of a v%^YELLOW%^i%^BOLD%^%^RED%^c%^YELLOW%^iou%^BOLD%^%^RED%^s "+
        "and apparently very sh%^YELLOW%^a%^BOLD%^%^RED%^rp blade.  "+
	"The blade splits at the end, forming two r%^YELLOW%^a%^BOLD%^%^RED%^z"+
	"%^YELLOW%^o%^BOLD%^%^RED%^r sh%^YELLOW%^a%^BOLD%^%^RED%^rp points, "+
	"each giving off a faint gl%^BOLD%^%^CYAN%^o%^BOLD%^%^RED%^w.  "+
	"The handle, which is only big enough for a hand and only then "+
	"if held carefully, "+
	"is likewise made from r%^YELLOW%^u%^BOLD%^%^RED%^by, however, it "+
	"has retained more of a natural look, though it has been "+
	"smoothed enough to serve its purpose.%^RESET%^");

	set_value(2500);
	set_lore("This pick was created several decades ago by "+
	"a mysterious and private magi, known only as Kinorda.  He forged "+
	"it from ruby and enchanted it with magic known only to him.  Since it "+
	"was the preferred weapon of one of his generals, Javiisees, Kinorda "+
	"bestowed it upon him after a particularly gruesome battle in which "+
	"the general danced about the battlefield wearing only the busted head "+
	"of one of their enemies as a loin cloth.  Its exact nature is unknown, "+
	"but it is believed to grant the wielder some method "+
	"of inflicting more damage than normal.");
	set_item_bonus("damage bonus", 2);
    set_item_bonus("fire resistance", 5);
	set_property("lore difficulty",10);
	set_property("enchantment",2 + random(3));
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func()
{
	tell_object(ETO, "%^BOLD%^%^RED%^You carefully grip the r%^YELLOW%^u%^BOLD%^%^RED%^"+
	"by handle of your p%^YELLOW%^i%^BOLD%^%^RED%^ck.%^RESET%^");
	if(!ETO->query_invis()) 
	{
		tell_room(EETO, ETOQCN+"%^BOLD%^%^RED%^ carefully grips the "+
		"r%^YELLOW%^u%^BOLD%^%^RED%^"+
		"by handle of "+ETO->query_possessive()+
		" %^BOLD%^%^RED%^p%^YELLOW%^i%^BOLD%^%^RED%^ck.%^RESET%^", ({ETO}));
	}
	return 1;
}

int unwield_func()
{
	tell_object(ETO, "%^BOLD%^%^RED%^You carefully release your grip on the "+
	"r%^YELLOW%^u%^BOLD%^%^RED%^by handle of your p%^YELLOW%^i%^BOLD%^%^RED%^ck.%^RESET%^");
	if(!ETO->query_invis())
	{
		tell_room(EETO, ETOQCN+" %^BOLD%^%^RED%^carefully releases the grip on "+
		"the r%^YELLOW%^u%^BOLD%^%^RED%^by handle of "+ETO->query_possessive()+
		" %^BOLD%^%^RED%^p%^YELLOW%^i%^BOLD%^%^RED%^ck.%^RESET%^", ({ETO}));
	}
	return 1;
}

int hit_func(object targ)
{
	if(!objectp(ETO)) return 0;
	if(!objectp(EETO)) return 0;
	if(!objectp(targ)) return 0;
	if(random(4)) return 0;
	switch(random(20))
	{
		case 0..12:
			tell_object(ETO, "%^BOLD%^%^RED%^A violent vibrating "+
			"shoots up your arm as you strike "+targ->QCN+"!%^RESET%^");

			tell_object(targ, "%^BOLD%^%^RED%^A jolt of energy "+
			"shoots through your body as "+ETOQCN + "%^BOLD%^%^RED%^ "+
			"jabs "+ETO->QP + "%^BOLD%^%^RED%^ pick into you!%^RESET%^");

			tell_room(EETO, ETOQCN +"%^BOLD%^%^RED%^'s arm shakes "+
			"violently as "+ETO->QS + "%^BOLD%^%^RED%^ jabs "+
			ETO->QP+"%^BOLD%^%^RED%^ into "+targ->QCN+ "%^BOLD%^%^RED%^"+
			"!%^RESET%^", ({targ, ETO}));
			return roll_dice(1, 6);
			break;
		case 13..18:
			tell_object(ETO, "%^BOLD%^%^CYAN%^A %^BOLD%^%^RED%^SCREAM"+
			"%^BOLD%^%^CYAN%^ of %^BOLD%^%^RED%^RAGE%^BOLD%^%^CYAN%^ "+
			"echoes inside your head as your pick sinks into "+targ->QCN+
			"%^BOLD%^%^CYAN%^'s flesh!%^RESET%^");
			
			tell_object(targ, ETOQCN+"%^BOLD%^%^CYAN%^ sinks "+ETO->QP+
			"%^BOLD%^%^CYAN%^ pick into your flesh with an enormouse "+
			"force!%^RESET%^");
			
			tell_room(EETO, ETOQCN+"%^BOLD%^%^CYAN%^ suddenly looks "+
			"%^BOLD%^%^RED%^ENRAGED%^BOLD%^%^CYAN%^ as "+ETO->QS+
			" %^BOLD%^%^CYAN%^sinks "+ETO->QP+"%^BOLD%^%^CYAN%^ pick into "+
			targ->QCN+"%^BOLD%^%^CYAN%^'s flesh!%^RESET%^", ({targ, ETO}));
		
			return roll_dice(1, 6) + random(3);
			break;
		case 19:
			tell_object(ETO, "%^BOLD%^%^YELLOW%^You begin chanting in "+
			"a strange language as you swing your pick wildly and your mind "+
			"is temporarily filled with an %^BOLD%^%^RED%^ANGER%^BOLD%^"+
			"%^YELLOW%^ that threatens to overwhelm "+
			"you!%^RESET%^");
			
			tell_room(EETO, ETOQCN+"%^BOLD%^%^YELLOW%^ begins chanting in "+
			"some strange language, swinging "+ETO->QP+"%^BOLD%^%^YELLOW%^ "+
			"pick widly!%^RESET%^", ({ETO}));
			ETO->execute_attack();
			return 0;
			break;
	}	

}
