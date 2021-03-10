//I've updated this and the sword - /d/deku/weapons/gray_longsword.c
//to be base +3 and then +4 when used together - since I've been told
//a lot of the stuff on deku now is +3/+4 - and since these
//work together and I think they are quite rarely ever used
//together - it should be good - if anyone has a problem
//or notices one - please let me know, Saide - March 2nd, 2011

#include <std.h>
inherit "/d/common/obj/armour/fullplate.c";

int activated;
object bro;

void do_activate(object ob)
{
	if(!objectp(ETO)) return;
	bro = ob;
	if((int)TO->query_property("enchantment") < 2)
	{
		TO->remove_property("enchantment");
		TO->set_property("enchantment", 2);
	}
	TO->set_property("enchantment", 1);
	tell_object(ETO, "%^BOLD%^%^RED%^A hoarse voice whispers to you:  %^RESET%^"+
	"Well, well, maybe you're not as stupid as I thought "+
	capitalize(ETO->query_name())+".  You've found my arm anyway.....%^RESET%^");
	activated = 1;
}

void do_normal()
{
	if(!objectp(ETO)) return;
	TO->set_property("enchantment", -1);
	tell_object(ETO, "%^BOLD%^%^RED%^A hoarse voice whispers to you:  %^RESET%^"+
	"Tsk, Tsk, "+capitalize(ETO->query_name())+", damn you for seperating "+
	"me from my arm!%^RESET%^");
	bro = 0;
	activated = 0;
}

void create()
{
    ::create();
    set_name("a suit of gray fullplate");
	set_id(({"armor", "full plate", "plate armor",
	"exoskeleton", "eviscerator armor", "eviscerator plate",
	"eviscerator exoskeleton", "evisc_armor_worn", "plate", "fullplate"}));
	set_short("%^BOLD%^%^BLACK%^The E%^BOLD%^%^MAGENTA%^v%^BOLD%^%^BLACK%^"+
	"i%^BOLD%^%^MAGENTA%^sc%^BOLD%^%^BLACK%^e%^BOLD%^%^MAGENTA%^r"+
	"%^BOLD%^%^BLACK%^a%^BOLD%^%^MAGENTA%^t%^BOLD%^%^BLACK%^o"+
	"%^BOLD%^%^BLACK%^r's %^BOLD%^%^YELLOW%^E%^BOLD%^%^BLACK%^"+
	"x%^BOLD%^%^YELLOW%^o%^BOLD%^%^BLACK%^sk%^BOLD%^%^YELLOW%^"+
	"e%^BOLD%^%^BLACK%^l%^BOLD%^%^YELLOW%^e%^BOLD%^%^BLACK%^t"+
	"%^BOLD%^%^YELLOW%^o%^BOLD%^%^BLACK%^n%^RESET%^");
	set_obvious_short("A suit of gray fullplate");
	set_long("%^BOLD%^%^BLACK%^This shiny armor has been forged from a "+
	"mysterious gray metal.  It is thick and heavy, with only a thin, dirty "+
	"padding on the inside to help against chafing.  "+
	"The outside of the armor is riddled with strange "+
	"r%^BOLD%^%^RED%^u"+
	"%^BOLD%^%^BLACK%^n%^BOLD%^%^RED%^e%^BOLD%^%^BLACK%^s that "+
	"seem to pulsate constantly, almost %^BOLD%^%^RED%^v%^BOLD%^%^BLACK%^"+
	"io%^BOLD%^%^RED%^l%^BOLD%^%^BLACK%^e%^BOLD%^%^RED%^ntly%^BOLD%^%^BLACK%^.  "+
	"Apart from these, there are sp%^BOLD%^%^YELLOW%^i%^BOLD%^%^BLACK%^"+
	"k%^BOLD%^%^YELLOW%^e%^BOLD%^%^BLACK%^s that jaunt outward from almost "+
	"every imaginable joint, which serve to only add to the strangness "+
	"that is this armor.  Its maker is unknown, though it is "+
	"definately the work of an expert crafsman, as it would serve its "+
	"purpose in combat with extraordinary ease.%^RESET%^");

	set_lore("This strange fullplate armor is believed to have been "+
	"the work of some long ago forgotten blacksmith.  He somehow "+
	"enchanted in to allow for it to only work when in conjunction "+
	"with a missing piece, which in some legends, has been "+
	"referred to as the arm.  It is believed to be merely a "+
	"key in unlocking the other piece of the puzzle, however, "+
	"some historians believe this armor as well as the other "+
	"part to be cursed by some foul spirit.");

	set_property("lore difficulty", 20);
	set_property("enchantment", 2);
        set_property("no repair", 1);
    set_item_bonus("positive energy resistance", 15);
    set_item_bonus("damage bonus", 2);
	set_value(5000);
	set("no curse", 1);
	set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
}

int wearme()
{
	object *weaps;
	int x;
	tell_object(ETO, "%^BOLD%^%^GREEN%^An eerie chill crawls "+
	"up your spine....%^RESET%^");
	if(ETO->query_highest_level() < 15)
	{
		tell_object(ETO, "%^BOLD%^%^RED%^A hoarse voice whispers to you:%^RESET%^ "+
		"You're far too weak to control me!%^RESET%^");
		if(!ETO->query_invis())
		{
			tell_room(EETO, ETOQCN+"%^BOLD%^%^GREEN%^ seems shaken up as "+
			ETO->QS+"%^BOLD%^%^GREEN%^ looks at "+ETO->QP+"%^BOLD%^%^GREEN%^ "+
			"and decides against wearing it.%^RESET%^", ({ETO}));
		}
		return 0;
	}
	tell_object(ETO, "%^BOLD%^%^RED%^A hoarse voice whispers to you:%^RESET%^ "+
	"yes, I suppose you'll do....%^RESET%^");
	if(!ETO->query_invis())
	{
		tell_room(EETO, ETOQN+"%^BOLD%^%^GREEN%^ seems shaken up as "+
		ETO->QS+"%^BOLD%^%^GREEN%^ looks at "+ETO->QP+"%^BOLD%^%^GREEN%^ "+
		"but decides to wear it anyway.%^RESET%^", ({ETO}));
	}
	weaps = ETO->query_wielded();
	for(x = 0;x < sizeof(weaps);x++)
	{
		if(!objectp(weaps[x])) continue;
		if(weaps[x]->id("evisc_sword_wielded"))
		{
			if((object)weaps[x]->query_wielded() == ETO)
			{
				weaps[x]->do_activate(TO);
				do_activate(weaps[x]);
			}
		}
	}
	return 1;
}

int removeme()
{
	if(activated)
	{
		if(objectp(bro)) bro->do_normal();
		do_normal();
	}
	tell_object(ETO, "%^BOLD%^%^GREEN%^You feel more at ease as your remove "+
	"your armor...%^RESET%^");
	tell_object(ETO, "%^BOLD%^%^RED%^A hoarse voice whispers to you:%^RESET%^ "+
	"you weak, miserable, pathetic worm!! HOW DARE YOU???");

	if(!ETO->query_invis())
	{
		tell_room(EETO, ETOQCN+"%^BOLD%^%^GREEN%^ removes "+ETO->QP+
		"%^BOLD%^%^GREEN%^ armor and appears suddenly startled!%^RESET%^");
	}
	return 1;
}
