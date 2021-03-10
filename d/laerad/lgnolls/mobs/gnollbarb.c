#include <std.h>
inherit MONSTER;
#include "../lgnoll.h"


void create() {
    object obj;
	::create();
	
    set_name("gnoll barbarian");
    set_id( ({"gnoll", "Gnoll", "barbarian", "Barbarian", "Gnollbarbarian", "gnoll barbarian"}) );
    set_short("A brutish gnoll");
    set_long("%^ORANGE%^This gn%^RED%^o%^ORANGE%^ll is even bigger than the rest. Dressed only in "+
	"le%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^th%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^r h%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^d%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^s "+
	"he has an impressive collection of %^BOLD%^%^BLACK%^b%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^ttl%^RESET%^%^RED%^e "+
	"%^BOLD%^%^BLACK%^sc%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^rs %^RESET%^%^ORANGE%^covering covering his body and "+
	"face. His beady %^RED%^red e%^BOLD%^y%^RESET%^%^RED%^es %^ORANGE%^are burning with a crazed light that "+
	"seem to scare even the other gn%^RED%^o%^ORANGE%^lls in the camp. What he does not have in armor, he makes "+
	"up for in his massive bulk as well as wielding a weapon nearly the size of a normal human.%^RESET%^");
    set_gender("male");
    set("race", "gnoll");
    set_body_type("gnoll");
    set_overall_ac(7);
    set_property("swarm",1);
    set_class("barbarian");
    set_mlevel("barbarian", 20);
    set_hd(20,7);
    set_attack_bonus(3);
    set_exp(2250);
    set_stats("strength", 22);
    set_stats("dexterity", 16);
    set_stats("constitution", 22);
    set_stats("intelligence", 14);
    set_stats("wisdom", 16);
    set_stats("charisma", 14);
    set_speed(20);
    set_nogo( ({ROOMS"2",ROOMS"1",ROOMS"6"}) );
	set("aggressive","berserk");
    set_alignment(9);
    set_size(2);
    set_hp(400+(random(200)));
    set_max_hp(query_hp());
    set_property("full attacks", 3);
    add_money("gold", random(250));
	
	obj = new("/d/common/obj/armour/hide");
	obj->set_property("enchantment",3);
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	
	
	obj = new("/d/common/obj/weapon/large_battle_axe");
	obj->set_property("enchantment",3);
	if(random(10)) obj->set_property("monsterweapon",1);
	obj->move(TO);
	command("wield axe");
	command("wearall");
	
	set_funcs(({"bite"}));
	set_func_chance(15);
	
	      set_monster_feats(({
      "mighty rage",
      "rage", 
	  "greater rage",
	  "light weapon",
	  "improved two weapon fighting",
	  "strength of arm",
	  "blade block",
	  "toughness",
	  "powerattack",
	  
   }));
					   
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
	targ->do_damage("torso",(2,20)+20);
	TO->add_hp(random(40)+10);
	}
	else
	{
	tell_object(targ, "%^BOLD%^%^BLACK%^CL%^RED%^A%^BLACK%^CK! %^RESET%^%^MAGENTA%^The gnoll's jaws slam shut just %^GREEN%^i%^MAGENTA%^nc%^GREEN%^h%^MAGENTA%^es from your arm!%^RESET%^",targ);
	tell_room (environment(targ), "%^ORANGE%^You hear a loud %^BOLD%^%^BLACK%^CL%^RED%^A%^BLACK%^CK %^RESET%^%^ORANGE%^as the gnoll's jaws miss "+targ->QCN+"'s arm!",targ);
	}
}

int berserk(object target){
	force_me("kill "+TP->query_name());
	command("rage");
	return 1;
}