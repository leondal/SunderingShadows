//Updated description and mechanics - Octothorpe 6/7/13
//Coded by the one and only master of monsters...BANE//
// adding id of laeradmon *Styx* 12/20/03, last change 4/25/99

#include <std.h>
#include "/d/common/common.h"
inherit MONSTER;

void create(){
    ::create();
    set_id(({"titan","Titan", "laeradmon"}));
    set_name("titan");
    set_short("%^BOLD%^massive crazed %^YELLOW%^titan%^RESET%^");
    set_long("%^RED%^This gargantuan man is over twenty-five feet "+
       "tall and is dressed in a long flowing toga. The titan is "+
       "covered in fantastic jewelry, making himself appear as "+
       "beautiful as possible, yet his incredible beauty is touched "+
       "by the gaze of insanity. He looks incredibly strong and "+
       "could probably crush you quite easily.%^RESET%^");
    set_body_type("human");
    set_property("magic",1);
    set_race("titan");
    set_gender("male");
    set_size(3);
    set_alignment(8);
    set_overall_ac(-10);
    set("aggressive",24);
    set_mob_magic_resistance("average");
    set_class("mage");
    set_guild_level("mage",20);
    set_hd(20,200);
    set_hp(360+random(140));
    set_max_hp(query_hp());
    set_new_exp(22,"very high");
    set_spells(({
	   "magic missile",
	   "fireball",
	   "lightning bolt",
	   "hideous laughter",
	   "cone of cold",
	   "chain lightning"
    }));
    set_spell_chance(15);
    set_attack_limbs(({"right hand","left hand"}));
    set_property("full attacks",1);
    set_base_damage_type("bludgeoning");
    set_damage(6,6);
    set_attack_bonus(2);
    set_damage_bonus(2);
    add_money("gold",random(5000)+5000);
    add_money("silver",random(1000)+2000);
    set_funcs(({"rage"}));
    set_func_chance(10);
    if(random(10) < 5){
	   new("/d/laerad/obj/tl_staff.c")->move(TO);
    }
    set_nogo(({"/d/laerad/wasteland/waste1"}));
}

void rage(object targ){
    tell_object(targ,"%^ORAGNGE%^The titan calls forth the power of the "+
       "gods to aid him and strikes you with an incredible blast "+
       "of lightning!");
    tell_room(ETO,"%^ORANGE%^The Titan calls forth the power of the "+
       "gods to aid him and strikes "+targ->QCN+" with an incredible "+
       "blast of lightning!",targ);
    targ->do_damage("torso",roll_dice(10,6)+random(20));
}

void heart_beat(){
    ::heart_beat();
    if(query_hp() < 30){
   	set_func_chance(102);
    }
}

void die(object ob){
   object ob1;
   ob1 = new("/d/common/daemon/sp_randwpn.c");
   ob1->move(TO);
   RANDTREAS->find_stuff(TO,"random",100);
   ::die();
}