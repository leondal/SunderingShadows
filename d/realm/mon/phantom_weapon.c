#include <std.h>
#include "../inherits/area_stuff.h"
#include <daemons.h>

inherit WEAPONLESS;
void possess_this(object ob);

void create()
{
	::create();
   	add_search_path("/cmds/fighter");
   	set_gender("neuter");
    set_alignment(9);
   	set_property("full attacks", 1);
   	set_property("swarm",1);
   	set_property("magic",1);
   	set_property("weapon resistance",4);
}

void possess_this(object ob)
{
	string *tmp, mylim, myshort;
	int mod, flag = 0;
	if(!objectp(TO)) return;
	if(!objectp(ob)) 
	{
		tmp = get_dir("/d/common/obj/weapon/*.c");
		tmp -= ({"rake-garrett"});
		ob = new("/d/common/obj/weapon/"+tmp[random(sizeof(tmp))]);
		flag = 1;
	}	
	mod = ob->query_wc() + 6;
	set_id(ob->query_id());
	add_id("phantom");
	add_id("weapon");
	tmp = explode(ob->query_short(), " ");
	tmp -= ({"a"});
	tmp -= ({"A"});
	tmp -= ({"An"});
	tmp -= ({"an"});
	tmp -= ({"the"});
	tmp -= ({"The"});
	myshort = implode(tmp, " ");
	myshort = explode(myshort, " (")[0];
	myshort = capitalize(myshort);
	set_name("phantom "+myshort);
	set_short("%^BOLD%^%^WHITE%^p%^BOLD%^%^CYAN%^h"+
	"%^BOLD%^%^WHITE%^a%^BOLD%^%^CYAN%^n"+
	"%^BOLD%^%^WHITE%^t%^BOLD%^%^CYAN%^o"+
	"%^BOLD%^%^WHITE%^m%^BOLD%^%^RED%^ "+ myshort+ 
	"%^BOLD%^%^WHITE%^ ( %^BOLD%^%^CYAN%^floating "+
	"%^BOLD%^%^WHITE%^)%^RESET%^");

	set_long("%^BOLD%^%^RED%^This "+myshort+
	"%^BOLD%^%^RED%^ seems to have taken on a life of its own.  "+
	"Ancient mysterious %^BOLD%^%^BLUE%^r%^BOLD%^%^CYAN%^u"+
	"%^BOLD%^%^BLUE%^n%^BOLD%^%^CYAN%^e%^BOLD%^%^BLUE%^s "+
	"%^BOLD%^%^RED%^have been viciously scrawled into "+
	"every available surface on it.  An %^BOLD%^%^YELLOW%^"+
	"e%^BOLD%^%^RED%^e%^BOLD%^%^YELLOW%^r%^BOLD%^%^RED%^"+
	"i%^BOLD%^%^YELLOW%^e %^BOLD%^%^RED%^red "+
	"glow p%^BOLD%^%^BLACK%^u%^BOLD%^%^RED%^ls%^BOLD%^"+
	"%^BLACK%^a%^BOLD%^%^RED%^tes outward from it, bathing the area "+
	"in a blood red light.%^RESET%^");
	mylim = ob->query_prof_type();
	if(!stringp(mylim)) mylim = "weapon";
	set_body_type(mylim);
   	set_race("phantom "+mylim);
	add_limb(mylim, 0, 0, 0, 0);
	set_attack_limbs(({mylim}));
	set_hd(20 + mod, 1);
	set_max_hp(125 + (10 * query_hd()));
	set_hp(query_max_hp());
	set_size(ob->query_size());
	set_mob_magic_resistance("average");
	set_stats("strength", 8 + mod);
  	set_stats("dexterity", 10 + mod);
  	set_stats("constitution", 18);
   	set_stats("intelligence", 6);
   	set_stats("charisma", 6);
   	set_stats("wisdom", 6);
   	set_new_exp(35, "normal");
   	set_overall_ac(-2 - mod);
   	set_attacks_num(4 + (mod/6));
   	set_damage(1, mod);
	set_attack_bonus(10 + mod);
	set_monster_feats(({
       "parry"
	}));
	if(flag) 
	{
		ob->remove();
	}
	return;
}

void die(object ob)
{
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;	
	tell_room(ETO, "%^BOLD%^%^MAGENTA%^A hideous "+
	"%^BOLD%^%^GREEN%^S%^BOLD%^%^YELLOW%^H%^BOLD%^"+
	"%^GREEN%^R%^BOLD%^%^YELLOW%^"+
	"I%^BOLD%^%^GREEN%^E%^BOLD%^%^YELLOW%^K%^BOLD%^"+
	"%^MAGENTA%^ resounds here as the "+
	TO->query_name() + " "+
	"%^BOLD%^%^RED%^E%^BOLD%^%^YELLOW%^"+
	"X%^BOLD%^%^RED%^P%^BOLD%^%^YELLOW%^L%^BOLD%^%^RED%^"+
	"O%^BOLD%^%^YELLOW%^D%^BOLD%^%^RED%^E%^BOLD%^%^YELLOW%^"+
	"S%^BOLD%^%^MAGENTA%^ into a million molecules that "+
	"wink out of %^BOLD%^%^RED%^e%^BOLD%^%^YELLOW%^"+
	"x%^BOLD%^%^RED%^i%^BOLD%^%^YELLOW%^s%^BOLD%^"+
	"%^RED%^t%^BOLD%^%^YELLOW%^e%^BOLD%^%^RED%^"+
	"n%^BOLD%^%^YELLOW%^c%^BOLD%^%^RED%^e%^BOLD%^"+
	"%^MAGENTA%^ before ever landing!%^RESET%^");
	TO->move("/d/shadowgate/void");
	::die(ob);	
}


