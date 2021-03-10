#include <std.h>
inherit MONSTER;
#include "../lgnoll.h"


void create() {
    object obj;
	::create();
	
    set_name("Gnoll warrior");
    set_id( ({"gnoll", "Gnoll", "warrior", "Warrior", "Gnollwarrior"}) );
    set_short("A gnoll warrior");
    set_long("%^ORANGE%^This %^RED%^brutish %^ORANGE%^looking %^BOLD%^%^BLACK%^gnoll %^RESET%^%^ORANGE%^stands "+
	"taller than most humans. It is covered in %^BOLD%^%^BLACK%^gr%^RESET%^a%^BOLD%^%^BLACK%^y%^RESET%^i%^BOLD%^%^BLACK%^sh "+
	"f%^RESET%^u%^BOLD%^%^BLACK%^r %^RESET%^%^ORANGE%^all over its body, except for its head where the fur is a %^RED%^dark "+
	"red color%^ORANGE%^, most likely colored by %^BOLD%^%^RED%^dr%^RESET%^%^RED%^ie%^BOLD%^d bl%^RESET%^%^RED%^oo%^BOLD%^d%^RESET%^%^ORANGE%^. "+
	"Covered in %^BOLD%^%^BLACK%^pl%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^e %^ORANGE%^and %^BOLD%^%^BLACK%^he%^RESET%^a%^BOLD%^%^BLACK%^v%^RESET%^y "+
	"%^BOLD%^%^BLACK%^b%^RESET%^oo%^BOLD%^%^BLACK%^ts %^RESET%^%^ORANGE%^this brutish beast appears ready for most challenges. Its beady "+
	"%^BOLD%^%^RED%^r%^BLACK%^e%^RED%^d e%^BLACK%^y%^RED%^es %^RESET%^%^ORANGE%^glare %^MAGENTA%^hungrily %^ORANGE%^at everything that moves.");
    set_gender("male");
    set("race", "gnoll");
    set_body_type("gnoll");
    set_overall_ac(5);
    set_property("swarm",1);
    set_class("fighter");
    set_mlevel("fighter", 20);
	set_class("cleric");
	set_mlevel("cleric", 20);
    set_hd(20,7);
    set_attack_bonus(3);
    set_exp(2250);
    set_stats("strength", 22);
    set_stats("dexterity", 16);
    set_stats("constitution", 18);
    set_stats("intelligence", 14);
    set_stats("wisdom", 16);
    set_stats("charisma", 14);
    set_speed(20);
    set_nogo( ({ROOMS"2",ROOMS"1",ROOMS"6"}) );
    set("aggressive", 20);
    set_alignment(9);
    set_size(3);
    set_hp(150+(random(200)));
    set_max_hp(query_hp());
    set_property("full attacks", 3);
    add_money("gold", random(250));
	
	obj = new("/d/common/obj/armour/fullplate");
	obj->set_property("enchantment",2);
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	
	obj = new("/d/common/obj/armour/helm");
	obj->set_property("enchantment",2);
	if(random(10)) obj->set_property("monsterweapon",1);
	obj->move(TO);
	
	  switch(random(3)) {
    case 0: "/d/common/daemon/randgear_d"->arm_me(TO,"clubm",20,3);
            break;
    case 1: "/d/common/daemon/randgear_d"->arm_me(TO,"bluntl",20,3);   
            break;
    case 2: "/d/common/daemon/randgear_d"->arm_me(TO,"edgedl",20,3);   
            break;
	  }
	command("wearall");
	
	set_funcs(({"bite"}));
	set_func_chance(15);
					   
	   set_monster_feats(({
      "parry"	  
   }));				   
}

void callout_1()
{

     tell_room(ETO,"%^RED%^The Gnoll warrior goes into berserk!%^RESET%^\n");
     new("/cmds/spells/b/_berserker")->use_spell(TO,"gnoll warrior",45,100,"cleric");
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








