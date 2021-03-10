#include <std.h>
#include "../inherits/area_stuff.h"
inherit MONSTER;
int flag;

void create() 
{
   	object ob1, ob2;
   	::create();
	set_name("a forlorn ghost");
   	set_id(({"ghost", "human", "forlorn ghost"}));

   	set_short("%^BOLD%^%^WHITE%^A forlorn human ghost%^RESET%^");

   	set_long("%^BOLD%^%^WHITE%^This pitiful being emanates a "+
	"vast and tremendous sorrow.  It was obviously once human and "+
	"has somehow been trapped in a place between life and "+
	"final rest.  In life its features were fair and simple, "+
	"perhaps it was a peasant or some other low class member of "+
	"its civilization.  You can tell that its death was not a peaceful "+
	"one, as vicious and crude scars crisscross all of its nude body, "+
	"some of them in odd angles, perhaps as a result of long term "+
	"inhumane torture.  There are now strange and %^BOLD%^%^CYAN%^"+
	"glowing runes%^BOLD%^%^WHITE%^ etched all over its body "+
	"with a giant pentagram emblazoned upon its forehead, which "+
	"pulses constantly.  With each pulse this being flinches, "+
	"apparently in tremendous and excruciating pain.  "+
	"The look of sorrow on its face is one more reminder "+
	"of the powerful forlorn aura radiating out from it.%^RESET%^");

   	set_race("human");
   	set_body_type("human");
   	set_gender("male");
   	set_size(2);
   	set_alignment(4);
     	set_hd(1,1);
	set_class("fighter");
	set_level(1);
	set_guild_level("fighter", 1);
	set_mlevel("fighter", 1);
   	set_max_hp(50);
   	set_hp(query_max_hp());
	set_exp(50);   	
	set_new_exp(5, "very low");
}

void do_random_emote()
{
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	switch(random(4)) 
	{
		case 0:
			TO->force_me("emote wails miserably...");
			break;
		case 1:
			TO->force_me("emote seems to be trying to speak, but can form no words...");
			break;
		case 2:
			TO->force_me("emote wobbles and almost falls to the floor, seeming suddenly "+
			"as if he is about to simply cease to exist");
			break;
		case 3:
			TO->force_me("emote flails his arms and legs about wildly, seemingly "+
			"angry at this place");
			break;
		default:
			TO->force_me("emote shrieks loudly and begins wailing helplessly...");
			break;
	}
	flag++;
	if(flag < 4)
	{
		call_out("do_random_emote", 12);
	}
	else
	{
		call_out("die", 12);
	}
	return;
}


void init()
{		
	::init();
	if(!objectp(TO)) return;
	if(!objectp(TP)) return;
	if(TP->query_true_invis()) return;
	if(!userp(TP)) return;
	if(flag) return;
	flag = 1;
	do_random_emote();
	return;
}

void die(object ob)
{
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	tell_room(ETO, TOQCN+" %^BOLD%^%^RED%^screams in agony as a "+
	"sudden strike of %^BOLD%^%^YELLOW%^lightning%^BOLD%^%^RED%^ "+
	"explodes its head!%^RESET%^");
	ETO->remove_property("wild magic");
	ETO->set_property("wild magic", 15 + random(15));
	tell_room(ETO, TOQCN +"%^BOLD%^%^WHITE%^ slowly fades away into "+
	"nothingness.... %^RESET%^");
	TO->move("/d/shadowgate/void");
	::die(ob);
}


