//added guild_level, etc. so it will cast the spell & 
//added max level *Styx* 7/21/01
//added a better describe - another spell and special
//Saide
#include <std.h>
inherit WEAPONLESS;

void create() 
{
    ::create();
    set_name("babu");
    set_id( ({"babu", "Babu"}) );
    set_gender("neuter");
    set_race("babu");
    set_short("A babu");
    set_long("%^BOLD%^%^BLACK%^This skeletal creature is "+
    "tall and is cloaked with a tight, form-fitting black "+
    "leather.  Its face has rotted and nothing more than "+
    "a skull remains, brilliant %^RED%^red orbs%^BOLD%^"+
    "%^BLACK%^ gaze out from its otherwise empty eye "+
    "sockets.  Atop its skull is a mane of thick black "+
    "hair, that is unkept and matted together with all "+
    "types of filth.  From almost the center of that "+
    "mane comes a lone, dull white, horn that extends "+
    "several inches above.%^RESET%^");
    set_body_type("human");
    set_alignment(6);
    add_money("gold", random(100));
    set("aggressive",30);
    set_property("undead",1);
    set_hd(20,1);
    set_stats("strength",18);
    set_stats("intelligence",17);
    set_stats("constitution",12);
    set_stats("dexterity",10);
    set_stats("wisdom",15);
    set_stats("charisma",8);
    set_class("mage");
    set_mlevel("mage", query_hd());
    set_guild_level("mage",query_hd());
    set_spells(({"burning hands","lightning bolt","fireball",
    "scorcher"}));
    set_spell_chance(30);
    new("/d/common/obj/armour/leather.c")->move(TO);
    command("wear leather");
    set_hp(246 + random(30));   
	set_new_exp(18, "normal");
    set_funcs(({"gaze"}));
    set_func_chance(15);
    set_attacks_num(3);
    set_damage(3,6);
}

void gaze(object targ)
{
	if(!objectp(TO)) return;
	if(!objectp(targ)) return;
	if(!"/daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")) 
	{ 
		tell_room(ETO,"%^BOLD%^%^BLACK%^The babu %^RED%^stares%^BOLD%^%^BLACK%^ into "+
		targ->QCN+"%^BOLD%^%^BLACK%^'s eyes and "+targ->QP+"%^BOLD%^%^BLACK%^ "+
		"body suddenly stiffens!%^RESET%^",targ);

		tell_object(targ,"%^BOLD%^%^BLACK%^The babu %^RED%^stares%^BOLD%^%^BLACK%^ "+
		"into your eyes and your body stiffens, leaving you unable to move!%^RESET%^");
   		
		return targ->set_paralyzed(roll_dice(2,20),"%^RED%^Your body is stiff!%^RESET%^");
  	}
 
	tell_room(ETO,"%^BOLD%^%^BLACK%^The babu %^RED%^stares%^BOLD%^%^BLACK%^ into "+
	targ->QCN+"%^BOLD%^%^BLACK%^'s eyes and "+targ->QS+
	"%^BOLD%^%^BLACK%^ seems to shake off the effect.%^RESET%^",targ);

  	tell_object(targ,"%^BOLD%^%^BLACK%^The babu %^RED%^stares%^BOLD%^%^BLACK%^ "+
	"into your eyes and you feel your body beginning to stiffen, but "+
	"you manage to shake off the effect.%^RESET%^");
}
