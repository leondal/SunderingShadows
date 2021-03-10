#include <std.h>
#include <daemons.h>
inherit "/std/monster";
int flag;

void create() 
{
    object ob;
    ::create();
	set_name("skeleton king");
    set_id(({"skeleton","king","skeleton king"}));
	set_race("undead");
	set_gender("male");
	set_short("Skeleton King");
	set_long("%^BOLD%^%^WHITE%^This skeletal creature towers "+
    "nearly ten feet in the air.  It was quite obviously, in life, "+
    "a large being, probably an ogre or giant of some kind, "+
    "though possibly just a very large human.  Decaying flesh "+
    "still hangs from its large bones, though rot is quickly "+
    "taking all of it.  The eyes of this creature radiate an "+
    "intense anger, they are inset into its bleached white "+
    "skull several inches and blazing a deep %^RED%^red%^BOLD%^"+
    "%^WHITE%^.  A thin %^YELLOW%^golden crown%^BOLD%^%^WHITE%^ "+
    "sits atop its head, an apparent attempt to project its "+
    "royalty.  Its body is draped with a robe that "+
	"has rotted over the course of time and it carries two "+
    "short swords at ready.%^RESET%^");
    set_hd(24,1);
    set_body_type("human");
	set_alignment(9);
    set_size(3);
    set_stats("intelligence",6);
    set_stats("wisdom",4);
    set_stats("strength",18);
    set_stats("charisma",3);
    set_stats("dexterity",8);
    set_stats("constitution",7);
    set_hp(950 + random(30));
    //set_exp(10000);
    set_max_hp(query_hp());
	set_new_exp(20, "very high");
	new("/d/common/obj/weapon/shortsword")->move(TO);
    command("wield sword");
	new("/d/common/obj/weapon/shortsword")->move(TO);
	command("wield sword");
	ob = new("/d/common/obj/armour/robe");
	ob->set_size(3);
	ob->set_short("A rotted robe");
	ob->set_long("%^RED%^This large robe is made from light cotton that was sewn together "+
	"flawlessly, obviously by the hand of an experienced tailor.  However, like all "+
	"other things, the ravages of time have not left this robe untouched.  The cotton it was "+
	"made from has began to rot and large holes have been worn into it.  If not for the fact "+
	"that it was sewn so flawlessly, it would have already fallen completely apart.%^RESET%^");
	ob->move(TO);
	command("wear robe");
    add_search_path("/cmds/fighter");
    set_property("undead",1); 
    set("aggressive","rush");
    set_overall_ac(-4);
    set_property("full attacks",1);
    set_max_level(30);
    set_monster_feats(({
            "rush",
            "flash",
            "scramble",
        }));	    
    set_funcs(({"flash_em"}));
    set_func_chance(25);
}

void rush()
{
    if(!objectp(TO)) return;
    if(!objectp(TP)) return;
	if(flag == 0) 
    {
        command("speech growl");
        command("say you greedy bastard! DIE!");
        flag = 1;
	}
    TO->add_attack_bonus(8);
	command("rush "+TPQN);
    TO->add_attack_bonus(-8);
	return;
}
void flash_em(object targ)
{
    command("flash");
    command("flash");
    if(!random(3)) rush();
}
void reset() {
    ::reset();
    flag = 0;
}

void die(object ob){
    if((string)ETO->query_short() == "%^BOLD%^%^WHITE%^Burial Chamber%^RESET%^") {
        ETO->monster_died();
    }
    ::die(ob);
}
