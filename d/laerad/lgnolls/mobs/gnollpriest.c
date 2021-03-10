#include <std.h>
inherit MONSTER;
#include "../lgnoll.h"


void create() {
    object obj;
	::create();
	
    set_name("Gnoll cleric");
    set_id( ({"gnoll", "Gnoll", "priest", "Priest"}) );
    set_short("A shielded gnoll");
    set_long("This gnoll stands taller than most humans. It is covered in %^BOLD%^%^BLACK%^grayish "+
	"fur %^RESET%^all over its body, except for its head where the fur is a %^RED%^dark red color%^WHITE%^, "+
	"most likely colored by dried %^BOLD%^%^RED%^blood. %^RESET%^Covered in scalemail and a shield "+
	"this gnoll somehow looks more 'important' than its larger kin. On the front of its scale there is "+
	"a symbol of %^MAGENTA%^Bane%^WHITE%^. It still has that hungry look in its eyes, like it is "+
	"ready to attack and devour pretty much everything living.");
    set_gender("male");
    set("race", "gnoll");
    set_body_type("gnoll");
    set_overall_ac(0);
    set_property("swarm",1);
    set_class("cleric");
    set_mlevel("cleric",25);
	set_guild_level("cleric",25);
    set_hd(20,8);
    set_attack_bonus(6);
    set_exp(2250);
    set_stats("strength", 16);
    set_stats("dexterity", 16);
    set_stats("constitution", 20);
    set_stats("intelligence", 14);
    set_stats("wisdom", 22);
    set_stats("charisma", 14);
    set_speed(20);
    set_nogo( ({ROOMS"2",ROOMS"1",ROOMS"6"}) );
    set("aggressive", 20);
    set_alignment(9);
    set_size(2);
    set_max_hp(150+(random(150)));
    set_hp(query_max_hp());
    set_property("full attacks", 2);
    add_money("gold", random(550));
	
	obj = new("/d/common/obj/armour/scale");
	obj->set_property("enchantment",4);
	if(random(10)) obj->set_property("monsterweapon",1);
	obj->move(TO);
	
	obj = new("/d/common/obj/armour/coif");
	obj->set_property("enchantment",3);
	if(random(10)) obj->set_property("monsterweapon",1);
	obj->move(TO);
	
	obj = new("/d/common/obj/armour/shield");
	obj->set_property("enchantment",3);
	if(random(10)) obj->set_property("monsterweapon",1);
	obj->move(TO);
	
	obj = new("/d/common/obj/weapon/morningstar");
	obj->set_property("enchantment",3);
	if(random(10)) obj->set_property("monsterweapon",1);
	obj->move(TO);
	command("wield morningstar");
	command("wearall");
	
	set_spells(({"flame strike", "call lightning", "call lightning", "mass cause critical wounds"}));
	set_spell_chance(20);
	set_funcs(({"bite"}));
	set_func_chance(15);
					   
}



void bite(object targ){

	if(!present(targ)) return;
	tell_object(targ, "%^BOLD%^%^BLACK%^The gnoll suddenly jumps at you with its %^RESET%^%^RED%^jaws %^BOLD%^%^BLACK%^wide open!%^RESET%^\n",targ);
	tell_room (environment(targ), "The gnoll jumps at "+targ->QCN+" with its jaws wide open!\n",targ);
	if(targ->query_stats("dexterity")>random(25)){
	tell_object(targ,"%^BOLD%^%^BLACK%^The gnoll bites into your arm with his powerful jaws and tears a %^RESET%^%^RED%^ch%^MAGENTA%^u%^RED%^nk %^BOLD%^%^BLACK%^of %^RESET%^%^RED%^fl%^RESET%^%^RED%^e%^BOLD%^sh %^BOLD%^%^BLACK%^out of you!%^RESET%^\n",targ);
	tell_room (environment(targ),"%^BOLD%^%^BLACK%^The gn%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^ll warrior has caught " +targ->QCN+ " in his jaws and %^RED%^rips %^BOLD%^%^BLACK%^out a %^RED%^c%^RESET%^%^RED%^h%^BOLD%^u%^RESET%^%^RED%^n%^BOLD%^k %^BOLD%^%^BLACK%^of %^RED%^fl%^RESET%^%^RED%^e%^BOLD%^sh%^BOLD%^%^BLACK%^!%^RESET%^\n",targ);
	tell_object(targ,"%^BOLD%^%^BLACK%^The gn%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^ll %^RESET%^%^MAGENTA%^wolfs %^BOLD%^%^BLACK%^down the %^BOLD%^%^RED%^fl%^RESET%^%^RED%^e%^BOLD%^sh %^BOLD%^%^BLACK%^it tore from your arm and licks the %^BOLD%^%^RED%^blood %^BOLD%^%^BLACK%^from his %^RED%^l%^BOLD%^i%^RESET%^%^RED%^ps.%^RESET%^\n",targ); 
	tell_room (environment(targ),"%^BOLD%^%^BLACK%^The gn%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^ll %^RESET%^%^MAGENTA%^wolfs %^BOLD%^%^BLACK%^down the %^BOLD%^%^RED%^fl%^RESET%^%^RED%^e%^BOLD%^sh %^BOLD%^%^BLACK%^it tore from " +targ->QCN+ "'s arm and licks the %^BOLD%^%^RED%^blood %^BOLD%^%^BLACK%^from his %^RED%^l%^BOLD%^i%^RESET%^%^RED%^ps.\n",targ);
	targ->do_damage("torso",(4,20)+20);
	TO->add_hp(random(40)+10);
	}
	else
	{
	tell_object(targ, "%^BOLD%^%^BLACK%^CL%^RED%^A%^BLACK%^CK! %^RESET%^%^MAGENTA%^The gnoll's jaws slam shut just %^GREEN%^i%^MAGENTA%^nc%^GREEN%^h%^MAGENTA%^es from your arm!%^RESET%^",targ);
	tell_room (environment(targ), "%^ORANGE%^You hear a loud %^BOLD%^%^BLACK%^CL%^RED%^A%^BLACK%^CK %^RESET%^%^ORANGE%^as the gnoll's jaws miss "+targ->QCN+"'s arm!",targ);
	}
}

