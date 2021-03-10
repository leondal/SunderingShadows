#include <std.h>
#include "../inherits/area_stuff.h"
#include <daemons.h>

inherit WEAPONLESS;
int saving_throw_mod;

void create()
{
	::create();
   	add_search_path("/cmds/fighter");
   	set_body_type("human");
	set_race("phantom");
   	set_gender("neuter");
    	set_alignment(9);
   	set_property("full attacks", 1);
   	set_property("swarm",1);
   	set_attack_limbs(({"left hand", "right hand"}));	
   	set_property("magic",1);
   	set_funcs( ({"shriek"}) );
   	set_property("weapon resistance",4);
}

void possess_this(object ob)
{
	int mod;
	if(!objectp(ob)) ob = new("/d/common/obj/armour/banded");
	if(!objectp(TO)) return;
	mod = ob->query_ac() + random(5);
	set_id(ob->query_id());
	add_id("phantom");
	set_name("phantom posssed "+ob->query_name());
	set_short(ob->query_short() + " %^BOLD%^%^RED%^( possessed by "+
	"a %^BOLD%^%^WHITE%^p%^BOLD%^%^CYAN%^h"+
	"%^BOLD%^%^WHITE%^a%^BOLD%^%^CYAN%^n"+
	"%^BOLD%^%^WHITE%^t%^BOLD%^%^CYAN%^o"+
	"%^BOLD%^%^WHITE%^m%^BOLD%^%^RED%^ )%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^P%^BOLD%^%^CYAN%^h"+
	"%^BOLD%^%^WHITE%^a%^BOLD%^%^CYAN%^n"+
	"%^BOLD%^%^WHITE%^t%^BOLD%^%^CYAN%^o"+
	"%^BOLD%^%^WHITE%^m%^BOLD%^%^MAGENTA%^ appendages "+
	"have emerged from "+ob->query_short() + 
	"%^BOLD%^%^MAGENTA%^ - the arms and legs are "+
	"thick, muscular, and wrapped with chains.  The head of "+
	"the %^BOLD%^%^WHITE%^p%^BOLD%^%^CYAN%^h"+
	"%^BOLD%^%^WHITE%^a%^BOLD%^%^CYAN%^n"+
	"%^BOLD%^%^WHITE%^t%^BOLD%^%^CYAN%^o"+
	"%^BOLD%^%^WHITE%^m%^BOLD%^%^MAGENTA%^ "+
	"is %^BOLD%^%^GREEN%^grotesquely%^BOLD%^"+
	"%^MAGENTA%^ bloated and horridly maimed, "+
	"an open wound exposes the pulsing "+
	"brain beneath and a thick %^BOLD%^%^BLACK%^"+
	"black ooze%^BOLD%^%^MAGENTA%^ squirts "+
	"out with each contraction.  The "+
	"one visible eye of this thing seems "+
	"hopeless and confused, yet also seething "+
	"with an %^BOLD%^%^RED%^intense anger"+
	"%^BOLD%^%^MAGENTA%^.%^RESET%^");
	
	set_hd(24 + mod, 1);
	set_max_hp(375 + (10 * query_hd()));
	set_hp(query_max_hp());
	set_size(ob->query_size());
	set_mob_magic_resistance("average");
	set_stats("strength", 15 + mod);
  	set_stats("dexterity", 22);
  	set_stats("constitution", 18);
   	set_stats("intelligence", 6);
   	set_stats("charisma", 6);
   	set_stats("wisdom", 6);
   	set_new_exp(35, "normal");
   	set_overall_ac(-20 - mod);
   	set_attacks_num(4 + (mod/6));
   	set_damage(1, 10);
	set_attack_bonus(10 + mod);
	set_func_chance(20 + mod);
	saving_throw_mod = -5 - mod;
	ob->remove();
}

void shriek(object targ)
{
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;	
	if(!objectp(targ)) return;

	tell_room(ETO, TOQCN +" %^BOLD%^%^GREEN%^faces "+targ->QCN+
	"%^BOLD%^%^GREEN%^ and %^BOLD%^%^GREEN%^"+
	"S%^BOLD%^%^YELLOW%^H%^BOLD%^%^GREEN%^R%^BOLD%^%^YELLOW%^"+
	"I%^BOLD%^%^GREEN%^E%^BOLD%^%^YELLOW%^K%^BOLD%^%^GREEN%^S "+
	"loudly!%^RESET%^", targ);

	tell_object(targ, TOQCN +"%^BOLD%^%^GREEN%^ faces you "+
	"and %^BOLD%^%^GREEN%^"+
	"S%^BOLD%^%^YELLOW%^H%^BOLD%^%^GREEN%^R%^BOLD%^%^YELLOW%^"+
	"I%^BOLD%^%^GREEN%^E%^BOLD%^%^YELLOW%^K%^BOLD%^%^GREEN%^S"+
	" loudly!%^RESET%^");

	if(!"/daemon/saving_throw_d.c"->fort_save(targ, saving_throw_mod)) 
	{
		tell_object(targ,"%^BOLD%^%^RED%^Your "+
		"muscles suddenly freeze up and you are unable "+
		"move!%^RESET%^");
		targ->set_paralyzed(30, "%^BOLD%^%^GREEN%^Your muscles "+
		"are paralyzed from the phantom's shriek!%^RESET%^");
		tell_room(ETO, targ->QCN+"%^BOLD%^%^RED "+
		"stops moving!%^RESET%^", targ);
		return;
	}	
	return;

}

void heart_beat()
{
	::heart_beat();
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	if(!sizeof(filter_array(all_living(ETO), "is_non_immortal_player", FILTERS_D))) 
	{
		return die(TO);
	}
}

void die(object ob)
{
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;	
	tell_room(ETO, "%^BOLD%^%^YELLOW%^A loud %^BOLD%^%^GREEN%^"+
	"S%^BOLD%^%^YELLOW%^H%^BOLD%^%^GREEN%^R%^BOLD%^%^YELLOW%^"+
	"I%^BOLD%^%^GREEN%^E%^BOLD%^%^YELLOW%^K erupts from the "+
	"%^BOLD%^%^WHITE%^p%^BOLD%^%^CYAN%^h"+
	"%^BOLD%^%^WHITE%^a%^BOLD%^%^CYAN%^n"+
	"%^BOLD%^%^WHITE%^t%^BOLD%^%^CYAN%^o"+
	"%^BOLD%^%^WHITE%^m%^BOLD%^%^YELLOW%^ as the armor "+
	"containing it %^BOLD%^%^RED%^E%^BOLD%^%^YELLOW%^"+
	"X%^BOLD%^%^RED%^P%^BOLD%^%^YELLOW%^L%^BOLD%^%^RED%^"+
	"O%^BOLD%^%^YELLOW%^D%^BOLD%^%^RED%^E%^BOLD%^%^YELLOW%^"+
	"S!%^RESET%^");
	TO->move("/d/shadowgate/void");
	::die(ob);	
}


