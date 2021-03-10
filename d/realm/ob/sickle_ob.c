#include <std.h>
inherit OBJECT;
object wpn, owned;
int hs, wtype;

string gone_msg, own_msg;

void start_spinning();
void gone();
void set_owned(object who);
void set_wpn(object ob);
void do_hit(object targ);
mixed only_present(object *vics);

void create() 
{
	::create();
    	set_name("orb");
     	set_value(50);
    	set_weight(1);
	hs = 1 + random(2);
}

int query_wtype()
{
	return wtype;
}

void set_which_type(int x)
{
	if(!x) x = 1;
	if(x != 1 && x != 2) x = 1;
	wtype = x;
	if(wtype == 1)
	{
		set_id(({"orb", "tiny orb", "tiny glowing orb", "glowing orb"}));
    		set_short("%^BOLD%^%^CYAN%^a tiny glowing orb (%^BOLD%^%^WHITE%^spinning wildly "+
		"in midair%^BOLD%^%^CYAN%^)%^RESET%^");
    		set_long("%^BOLD%^%^CYAN%^This tiny glowing sphere is spinning wildly here.  "+
		"The substance from which it is formed is undeterminable and it looks "+
		"highly unstable, as tiny cracks are forming all across its surface.%^RESET%^");
		
		gone_msg = "%^BOLD%^%^WHITE%^The %^BOLD%^%^CYAN%^tiny glowing "+
		"orb%^BOLD%^%^WHITE%^ winks out of existence!%^RESET%^";
		
		own_msg = "%^BOLD%^%^CYAN%^The orb suddenly reappears "+
		"on the blade of your sickle!%^RESET%^";
		return;
	}
	if(wtype == 2)
	{
		set_id(({"orb", "tiny orb", "tiny pulsating orb", "pulsating orb", 
		"brilliant orb"}));
		set_short("%^BOLD%^%^YELLOW%^a brilliant orb (%^BOLD%^%^WHITE%^"+
		"pulsating rapidly in midair%^BOLD%^%^YELLOW%^)%^RESET%^");
		set_long("%^BOLD%^%^WHITE%^This tiny brilliant orb is pulsating rapidly here.  "+
		"The substance from which it is formed is undeterminable and it looks "+
		"highly unstable, as tiny cracks are forming all across its surface.%^RESET%^");

		gone_msg = "%^BOLD%^%^YELLOW%^The %^BOLD%^%^WHITE%^tiny pulsating "+
		"orb%^BOLD%^%^YELLOW%^ winks out of existence!%^RESET%^";
		
		own_msg = "%^BOLD%^%^YELLOW%^The orb suddenly reappears "+
		"on the blade of your sickle!%^RESET%^";
		return;
	}
}

void set_wpn(object ob)
{
	if(!objectp(ob)) return;
	wpn = ob;
}

void set_owned(object who)
{
	if(!objectp(who)) return;
	owned = who;
}

void gone()
{
	if(!objectp(TO)) return;
	if(!objectp(ETO)) 
	{
		TO->remove();
		return;
	}
	if(!objectp(wpn)) 
	{	
		TO->remove();
		return;
	}
	if(!objectp(owned)) 
	{
		TO->remove();
		return;
	}
	tell_room(ETO, gone_msg);
	tell_object(owned, own_msg);
	wpn->set_bolt_pos(0);
	TO->remove();	
}

void do_hit(object targ)
{
	object where;
	string limb, dam_desc, rmsg, tmsg, omsg, targname;
	int dam, mod;
	if(!objectp(TO)) return;
	if(!objectp(ETO)) 
	{
		TO->remove();
		return;
	}
	if(!objectp(wpn)) 
	{	
		TO->remove();
		return;
	}
	if(!objectp(owned)) 
	{
		TO->remove();
		return;
	}
	hs = hs - 1;
	if(!objectp(targ)) 
	{
		start_spinning();
		return;
	}
	where = environment(targ);
	if(!objectp(where)) 
	{
		start_spinning();
		return;
	}
	if(where != environment(owned)) 
	{
		start_spinning();
		return;
	}
	limb = targ->return_target_limb();
	targname = targ->QCN;

	switch(wtype) 
	{
		case 1:
			mod = -10;
			dam = roll_dice(12, 6);
			break;
		case 2:
			dam = roll_dice(10, 6);
			mod = -20;
			break;
		default:
			mod = -10;
			dam = roll_dice(12, 6);
			break;
	}

	if(!"/daemon/saving_throw_d.c"->reflex_save(targ, mod)) 
	{
		if(wtype == 1) 
		{
			dam_desc = "%^BOLD%^%^RED%^SEARS%^RESET%^";
		}	
		if(wtype == 2)
		{
			dam_desc = "%^BOLD%^%^YELLOW%^ENGULFS%^RESET%^";
		}
	}
	else
	{
		dam = dam / 2;
		if(wtype == 1)
		{		
			dam_desc = "%^BOLD%^%^MAGENTA%^SINGES%^RESET%^";
		}
		if(wtype == 2)
		{
			dam_desc = "%^BOLD%^%^MAGENTA%^LEECHES INTO%^RESET%^";
		}
	}

	switch(wtype)
	{
		case 1:
		
			tell_room(where, "%^BOLD%^%^YELLOW%^A bolt of lightning "+
			"blasts forth from the %^BOLD%^%^CYAN%^"+
			"tiny glowing orb%^BOLD%^%^YELLOW%^ and streaks "+
			"toward "+ targname +"%^BOLD%^%^YELLOW%^!%^RESET%^", ({targ}));

			tell_object(targ, "%^BOLD%^%^YELLOW%^A bolt of lightning "+
			"blasts forth from the %^BOLD%^%^CYAN%^"+
			"tiny glowing orb%^BOLD%^%^YELLOW%^ and streaks "+
			"toward you!%^RESET%^");	
		
		
			tell_room(where, "%^BOLD%^%^YELLOW%^The bolt of "+
			"lightning "+dam_desc + "%^BOLD%^%^YELLOW%^ "+ targname +
			"%^BOLD%^%^YELLOW%^'s "+limb+"!%^RESET%^", ({targ}));	

			tell_object(targ, "%^BOLD%^%^YELLOW%^The bolt of "+
			"lightning "+dam_desc+"%^BOLD%^%^YELLOW%^ "+
			"your "+limb+"!%^RESET%^");
			targ->cause_typed_damage(targ, limb, dam, "electricity");
			break;
		case 2:

			tell_room(where, "%^BOLD%^%^BLACK%^A bolt of "+
			"pure shadow erupts from the "+
			"%^BOLD%^%^WHITE%^brilliant orb%^BOLD%^%^BLACK%^"+
			" and zaps toward "+ targname +"%^BOLD%^"+
			"%^BLACK%^!%^RESET%^", ({targ}));
			
			tell_object(targ, "%^BOLD%^%^BLACK%^A bolt of "+
			"pure shadow erupts from the %^BOLD%^%^WHITE%^"+
			"brilliant orb%^BOLD%^%^%^BLACK%^ and zaps toward "+
			"you!%^RESET%^");

			tell_room(where, "%^BOLD%^%^BLACK%^The bolt of "+
			"shadow "+dam_desc+" %^BOLD%^%^BLACK%^"+ targname +
			"%^BOLD%^%^BLACK%^'s "+limb+"!%^RESET%^", ({targ}));

			tell_object(targ, "%^BOLD%^%^BLACK%^The bolt of "+
			"shadow "+dam_desc+ "%^BOLD%^%^BLACK%^ your "+limb+"!%^RESET%^");
			targ->cause_typed_damage(targ, limb, dam, "negative energy");
			break;
	}
	start_spinning();
	return;

}

mixed only_present(object *vics)
{
	int x;
	object *res = ({});
	if(!objectp(TO)) return;
	if(!objectp(ETO)) 
	{
		TO->remove();
		return;
	}
	if(!objectp(wpn)) 
	{	
		TO->remove();
		return;
	}
	if(!objectp(owned)) 
	{
		TO->remove();
		return;
	}
	if(!sizeof(vics)) return ({});
	for(x = 0;x < sizeof(vics);x++)
	{
		if(!present(vics[x], environment(owned))) continue;
		res += ({vics[x]});
	}
	return res;
}
	
void start_spinning()
{
	int fs;
	object vic, *vics;
	if(!objectp(ETO)) 
	{
		TO->remove();
		return;
	}

	if(!objectp(wpn)) 
	{	
		TO->remove();
		return;
	}

	if(!objectp(owned)) 
	{
		TO->remove();
		return;
	}
	if(!present(owned, ETO))
	{
		gone();
		return;
	}
	if(hs < 1) 
	{
		gone();
		return;
	}
	vics = filter_array(owned->query_attackers(), "only_present", TO);
	if(!sizeof(vics)) 
	{
		gone();
		return;
	}
	while(!objectp(vic = vics[random(sizeof(vics))])) 
	{
		fs++;
		if(fs > 2) 
		{
			gone();
			return;
		}
	}
	call_out("do_hit", 5, vic);
	return;		
}

int get() { return 0; }