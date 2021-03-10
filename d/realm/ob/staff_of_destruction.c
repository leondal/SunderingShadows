#include <std.h>
//Staff of destruction - can cast meteor swarm, prismatic spray
//or fireball on a target - random which one, most
//commonly it will be fireball - only responds
//to cleric/mage/psion/sorcerer/bard - Saide

inherit "/d/common/obj/weapon/quarter_staff";
int charges;

void query_charges();
void set_charges(int x);
void adj_charges(int x);

void create()
{
	::create();
	set_name("staff");
	
	set_id(({ "staff", "staff of destruction", 
	"destruction staff", "ashen staff", "ash staff"}));
    
	set_obvious_short("%^BOLD%^%^BLACK%^A long twisted ashen "+
	"staff%^RESET%^");
	
    	set_short("%^BOLD%^%^BLACK%^Staff of D%^RED%^"+
	"e%^BLACK%^s%^RED%^t%^BLACK%^r%^RED%^u"+
	"%^BLACK%^c%^RED%^t%^BLACK%^i%^RED%^o"+
	"%^BLACK%^n%^RESET%^");
	
	set_long("%^BOLD%^%^BLACK%^This staff extends "+
	"nearly five feet in length.  It has been carved from a "+
	"piece of %^BOLD%^%^WHITE%^ancient ashen wood%^BOLD%^"+
	"%^BLACK%^ that has swirls of %^RESET%^%^BLUE%^"+
	"dusky blue%^BOLD%^%^BLACK%^ throughout it.  "+
	"It is very %^BOLD%^%^WHITE%^twisted%^BOLD%^%^BLACK%^"+
	" and has bulbous %^BOLD%^%^GREEN%^knots%^BOLD%^"+
	"%^BLACK%^ all along its shaft.  The "+
	"top of the staff has three %^BOLD%^%^CYAN%^"+
	"orbs%^BOLD%^%^BLACK%^ inset into it, "+
	"they each %^BOLD%^%^YELLOW%^glow brightly "+
	"%^BOLD%^%^BLACK%^with a brilliant "+
	"%^BOLD%^%^RED%^red%^BOLD%^%^BLACK%^ light.  "+
	"An inscription has been carved into the opposite "+
	"end of the staff.%^RESET%^");

    	set_read("%^BOLD%^%^RED%^Absorb%^BOLD%^%^BLACK%^ "+
	"the power from other items to replenish the staff.\n\n "+
	"%^RED%^Destroy%^BOLD%^%^BLACK%^ those who "+
	"stand against you!%^RESET%^");
        
    	set_lore("%^BOLD%^%^BLACK%^Created many centuries ago "+
	"by Ao'rus Devar, this staff was given as a gift from "+
	"him to a mage known only as 'Bry'.  It is said that "+
	"he imbued it with the ability to steal magic from "+
	"other items in order to replenish itself, should "+
	"'Bry' find himself out in the world with no other "+
	"choice he could draw energy from his other equipment.  "+
	"Several duplicates are known to exists and perhaps "+
	"that is all this is, as the original was rumored "+
	"to be immensely powerful and is probably "+
	"still in the possession of 'Bry'.%^RESET%^");

    	set_property("lore difficulty",40);
    	set_language("common");	
    	set_value(8000);
	set_property("enchantment",5);
   	charges = 10;
    	set_wield((:TO,"wield_me":));
    	set_unwield((:TO,"unwield_me":));
	set_property("empowered", 4);
}

int wield_me() 
{
    if(ETO->query_highest_level() < 30) 
	{
        tell_object(ETO, "%^BOLD%^%^RED%^The staff refuses "+
		"to be controlled by someone as weak as you!%^RESET%^");
		return 0;
    }
	if (!ETO->query_property("silent_wield")) {
		tell_object(ETO, "%^BOLD%^%^BLACK%^You feel empowered by the " +
			"staff.%^RESET%^");
	}
    return 1;
}

int unwield_me() 
{
	if (!ETO->query_property("silent_wield")) {
		tell_object(ETO, "%^BOLD%^%^BLACK%^You feel the empowerment " +
			"granted to you by the staff fade away.%^RESET%^");
	}
    return 1;
}

int query_charges() 
{
	return charges;
}

void set_charges(int x) 
{
	charges = x;
}

void adj_charges(int x) 
{
	charges = charges + x;
}

void init()
{
	::init();
	add_action("absorb", "absorb");
    add_action("destroy", "destroy");
}

void failure() 
{
	write("The staff fails to respond to your command.");
    	return 1;
}

int absorb(string str)
{
	object ob;
	int x;
	if(!str) return 0;
	if(ETO->query_unconscious() || ETO->query_bound()
    	|| ETO->query_paralyzed()) 
	{
      	ETO->send_paralyzed_message("info",ETO);
        	return 1;
    	}
    	if(!query_wielded() ||
	!ETO->is_class("bard") && 
	!ETO->is_class("cleric") && 
	!ETO->is_class("mage") && 
	!ETO->is_class("sorcerer") &&
	!ETO->is_class("psion")) 
	{
      	failure();
        	return 1;
    	}

	if(!objectp(ob = present(str, ETO))) 
	{
		tell_object(ETO, "You have no "+str+" in your possession.");
		return 1;
	}
	if(ob->query_worn())
	{
		tell_object(ETO, "You must remove your "+str+
		"first.");
		return 1;
	}
	if(ob->query_wielded())
	{
		tell_object(ETO, "You must release your hold on "+
		str+" first.");
		return 1;
	}
	x = (int)ob->query_property("enchantment");
	if(!x || x < 0) 
	{
		tell_object(ETO, "%^BOLD%^%^WHITE%^Your "+str+
		" has not magic that the staff can "+
		"absorb!%^RESET%^");
		return 1;
	}

	if(charges >= 40)
	{
		tell_object(ETO, "%^BOLD%^%^BLACK%^You staff "+
		"is full and cannot absorb anymore magic yet."+
		"%^RESET%^");
		return 1;
	}

	tell_object(ETO, "%^BOLD%^%^MAGENTA%^A violet "+
	"ray of light bursts forth from the %^BOLD%^"+
	"%^CYAN%^orbs%^BOLD%^%^MAGENTA%^ on the end "+
	"of your staff and engulfs "+ob->query_short()+
	"%^BOLD%^%^MAGENTA%^ leeching some its magical "+
	"energy to replenish its own!%^RESET%^");
	
	tell_room(EETO, "%^BOLD%^%^MAGENTA%^A violet "+
	"ray of light bursts forth from the %^BOLD%^"+
	"%^CYAN%^orbs%^BOLD%^%^MAGENTA%^ on the end "+
	"of "+ETOQCN+"%^BOLD%^%^MAGENTA%^'s staff and "+
	"engulfs "+ob->query_short()+
	"%^BOLD%^%^MAGENTA%^!%^RESET%^", ETO);

	ob->set("no curse", 1);
	ob->set_property("enchantment", -1);
	ob->set("no curse", -1);
	charges += 5;
	if(charges > 40) charges = 40;
	return 1;
}		
	
int destroy(string str) 
{
	object ob, myspell;
      int lev;
    	if(ETO->query_unconscious() || ETO->query_bound()
    	|| ETO->query_paralyzed()) 
	{
      	ETO->send_paralyzed_message("info",ETO);
        	return 1;
    	}

    	if(!str && query_wielded()) 
	{
      	tell_object(ETO, "%^BOLD%^%^BLACK%^Who do you wish "+
		"to %^BOLD%^%^RED%^destroy%^BOLD%^%^BLACK%^?%^RESET%^");
        	return 1;
    	}

    	if(charges <= 0 || !query_wielded() || charges - 2 < 0 ||
	!ETO->is_class("bard") && 
	!ETO->is_class("cleric") && 
	!ETO->is_class("mage") && 
	!ETO->is_class("sorcerer") &&
	!ETO->is_class("psion")) 
	{
      	failure();
        	return 1;
    	}

    	if(ob = present(str,EETO)) 
	{
      	if(living(ob) && objectp(ob)) 
		{
            	tell_object(ETO,"%^BOLD%^%^BLACK%^You point the "+
			"staff at "+ob->QCN+"%^BOLD%^%^BLACK%^ "+
			"and watch in awe as the %^BOLD%^%^CYAN%^"+
			"orbs%^BOLD%^%^BLACK%^ on the end of it "+
			"begin spinning!%^RESET%^");
            
            	tell_object(ob, ETOQCN+"%^BOLD%^%^BLACK%^ points "+
			ETO->QP+" staff at you and the %^BOLD%^%^CYAN%^orbs"+
			"%^BOLD%^%^BLACK%^ on the end of it begin "+
			"spinning!%^RESET%^");
            
            	tell_room(EETO,ETOQCN+"%^BOLD%^%^BLACK%^ points "+ETO->QP+ 
            	" staff at "+ob->QCN+"%^BOLD%^%^BLACK%^ and  "+
            	"the %^BOLD%^%^CYAN%^orbs%^BOLD%^%^BLACK%^ on "+
			"the end of it begin spinning!%^RESET%^",({ETO,ob}));

			switch(random(20)) 
			{
				case 1..14:
					
					myspell = new("/cmds/spells/f/_fireball");	
					charges -= 2;	
					break;
				case 15..18:
					if(charges - 8 >= 0)
					{
						charges -= 8;
						myspell = new("/cmds/spells/p/_prismatic_spray");
						break;
					}
					myspell = new("/cmds/spells/f/_fireball");
					break;
				case 19:
					if(charges - 10 >= 0)
					{
						charges -= 10;
						myspell = new("/cmds/spells/m/_meteor_swarm");
						break;
					}
					myspell = new("/cmds/spells/f/_fireball");
					break;
			}			
			ETO->set_paralyzed(5, "%^BOLD%^%^BLACK%^You are using the "+
			"staff!%^RESET%^");
			//cool echoes but not needed the way that 
			//using a spell currently works - Saide
			/*if(base_name(myspell) == "/cmds/spells/f/_fireball")
			{
				tell_object(ETO, "%^BOLD%^%^RED%^A massive fireball bursts "+
				"forth from the end of your staff and speeds "+
				"toward "+ob->QCN+"!%^RESET%^");

				tell_object(ob, "%^BOLD%^%^RED%^A massive fireball "+
				"bursts forth from the end of "+ETOQCN+
				"%^BOLD%^%^RED%^'s staff and speeds toward you!%^RESET%^");
			
				tell_room(EETO, "%^BOLD%^%^RED%^A massive fireball "+
				"bursts forth from the end of "+ETOQCN+
				"%^BOLD%^%^RED%^'s staff and speeds toward "+ob->QCN+
				"%^BOLD%^%^RED%^!%^RESET%^", ({ob, ETO}));
			}
			if(base_name(myspell) == "/cmds/spells/p/_prismatic_spray")
			{
				tell_object(ETO, "%^BOLD%^%^GREEN%^A ray of light "+
				"springs forth from the end of your staff and "+
				"streaks toward "+ob->QCN+"%^BOLD%^%^GREEN%^!%^RESET%^");
				
				tell_object(ob, "%^BOLD%^%^GREEN%^A ray of light "+
				"springs forth from the end of "+ETOQCN+"%^BOLD%^"+
				"%^GREEN%^'s staff and streaks toward you!%^RESET%^");

				tell_room(EETO, "%^BOLD%^%^GREEN%^A ray of light "+
				"springs forth from the end of "+ETOQCN+"%^BOLD%^"+
				"%^GREEN%^'s staff and streaks toward "+
				ob->QCN+"%^BOLD%^%^GREEN%^!%^RESET%^", ({ob, ETO}));
			}
			if(base_name(myspell) == "/cmds/spells/m/_meteor_swarm")
			{
				tell_object(ETO, "%^BOLD%^%^RED%^A massive wave of "+
				"energy shoots out in all directions from the "+
				"end of you staff!%^RESET%^");

				tell_room(EETO, "%^BOLD%^%^RED%^A massive wave of "+
				"energy shoots out in all directions from the "+
				"end of "+ETOQCN+"%^BOLD%^%^RED%^'s staff!%^RESET%^", ETO);
			}*/
			if(objectp(myspell)) 
			{
				lev = ETO->query_highest_level();
				if(ETO->query_property("empowered")) 
				{
					lev += (int)ETO->query_property("empowered");
				}
				myspell->use_spell(ETO, ob, lev, 0);			
			}
            	return 1;
        	}
    	}
    	tell_object(ETO, "You see no such target here.");
    	return 1;
}
        