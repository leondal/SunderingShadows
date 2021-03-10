//He's no longer a halfling - I have in mind for him to be some 
//very evil, very charismatic, intelligent, human/small devil/small 
//demon mix or maybe some type of experiment gone horribly
//wrong - Saide 01/02/04

#include <std.h>
#include <daemons.h>
inherit MONSTER;
int has_robe;
string robe_desc;

void create() {
      object ob, obj, money;
      ::create();
    	set_name("humanoid");
    	set_id(({"bandit","leader","thief","humanoid"}));
    	set_race("humanoid");
    	set_body_type("human");
    	set_size(1);
    	set_short("A slight humanoid with tanned flesh");

    	set_class("fighter");
    	set_guild_level("fighter",24);
    	set_mlevel("fighter",query_guild_level("fighter"));
    	set_class("thief");
    	set_guild_level("thief",24);
    	set_mlevel("thief",query_guild_level("thief"));
    	add_search_path("/cmds/thief");
    	set("aggressive", "stab_them");
    	set_alignment(7);
    	set_stats("strength",22);
    	set_stats("intelligence",17);
    	set_stats("wisdom",15);
    	set_stats("dexterity",17);
	set_stats("charisma",17);
    	set_stats("constitution",13);
    	set_gender("male");
    	set_hp(425 + random(100));
	set_new_exp(25, "boss");
    	//set_exp(8000);
    	new("/d/common/obj/weapon/shortsword")->move(TO);
    	command("wield sword");   
    	if(!random(3)) {
        	new("/d/deku/armours/leather")->move(TO);
    	}
    	else {
        	new("/d/common/obj/armour/leather")->move(TO);
    	}
    	command("wear leather");
    	new("/d/common/obj/weapon/dagger")->move(TO);
    	command("wield dagger");
    	switch(random(3)) {
        case 0:
            new("/d/deku/armours/ring_p")->move(TO);
            command("wear ring");
            break;
        case 1: 
            new("/d/deku/armours/brobe.c")->move(TO);
            command("wear robe");
            robe_desc = "a %^BLUE%^blue%^RESET%^ and "+
            "%^YELLOW%^yellow%^RESET%^ robe drapped over it";
            has_robe = 1;
            break;
        case 3:
            new("/d/common/obj/misc/pouch.c")->move(TO);
            new("/d/common/obj/misc/thief_tools.c")->move(TO);
            new("/d/common/obj/misc/flint.c")->move(TO);
            command("put tools in pouch");
            command("wear pouch");
        break;
    	}
    	if(has_robe == 0) {
        	ob = new("/d/common/obj/armour/robe.c");
        	ob->set_size(1);
        	ob->set_weight(7);
        	ob->move(TO);
        	robe_desc = "a flea infested robe draped over it";
        	command("wear robe");
    	}
    	set_long("%^RESET%^This strange creature wears a suit of%^BOLD%^ "+
    	"%^BLACK%^black leather%^RESET%^ with "+robe_desc+".  His eyes are an "+
    	"%^RED%^intense red%^RESET%^ and there is no hair on him to speak "+
    	"of.  His gaping mouth is littered with rows of teeth that have been "+
   	"%^RED%^sharpened%^RESET%^ in some unnatural manner, apart "+
	"from which there is "+
    	"no expression.  The exposed parts of his flesh are a light brown "+
    "and you are unsure if this suggests a tan or is his natural color.  "+
    "An occassional twitch, like a ripple through water, pulses "+
    "through his body and is complimented by a laugh from him.  It is "+
    "obvious that this man is not natural, his small human body has "+
    "several hints of another, more mysterious heritage.  An aura "+
    "of almost tangible superiority or at least confidence lingers "+
    "about him.  He is always armed, yet, doesn't appear afraid or "+
    "even very alert.%^RESET%^");

    add_money("silver",random(2000));
    add_money("gold",random(1250)+500);
    obj = new("/d/common/obj/misc/schest");
    obj->move(TO);
    money = new("/std/obj/coins");
    money->set_money("gold",random(400)+600);
    money->set_money("electrum",random(300)+50);
    money->set_money("silver",random(500)+75);
    money->set_money("copper",random(1000)+150);
    money->set_money("platinum",random(100) + 100);
    money->move(obj);
    obj->toggle_closed();
        
  
    set_property("no paralyze",1);
    set_property("no death",1);
    set_property("full attacks",1);
    set_mob_magic_resistance("average");
    set_max_level(30);
    set_funcs(({"attack"}));
    set_func_chance(50);
    ob = new("/d/common/obj/potion/healing");
    ob->set_uses(20 + random(21));
    ob->move(TO);
    command("open vial");
}

void heart_beat() {
    ::heart_beat();
    if(!objectp(TO) || !objectp(ETO)) return;
    if(TO->query_hp() < ((int)TO->query_max_hp() / 2)) {
        if(present("kit",TO)) {
            command("open vial");
            command("drink vial");
            command("offer bottle");
            command("drink vial");
            command("offer bottle");
        }
    }
}

void attack(object targ) {
    if(!objectp(targ) || !objectp(TO)) return;
    switch(random(8)) {
        case 0..6:
            tell_object(targ,"%^YELLOW%^The humanoid stabs into your "+
            "chest with his shortsword!%^RESET%^");
            tell_room(ETO,"%^YELLOW%^The humanoid stabs into "+
            targ->QCN+"%^YELLOW%^'s chest with his shortsword!",targ);
            set_property("magic",1);
            targ->do_damage("torso",roll_dice(3,6) + random(5));
            set_property("magic",-1);
            break;
        case 7:
            tell_object(targ,"%^RED%^The humanoid spins to the "+
            "side and spits a %^BOLD%^%^GREEN%^green goo"+
            "%^RESET%^%^RED%^ into your eyes!%^RESET%^");
            tell_room(ETO,"%^RED%^The humanoid spints to the side "+
            "suddenly and spits a %^BOLD%^%^GREEN%^green goo"+
            "%^RESET%^%^RED%^ into "+targ->QCN+"%^RED%^'s "+
            "eyes!%^RESET%^",targ);
            set_property("magic",1);
            targ->do_damage("head",roll_dice(1,6));
            set_property("magic",-1);
            if(!SAVING_D->saving_throw(targ,"paralyzation_poison_death")) { 
                tell_object(targ,"%^RED%^You scream in pain as "+
                "the %^BOLD%^%^GREEN%^goo%^RESET%^%^RED%^ burns "+
                "into your eyes!%^RESET%^");
                tell_room(ETO,targ->QCN+"%^RED%^ screams out in pain "+
                "as the %^BOLD%^%^GREEN%^goo%^RESET%^%^RED%^ burns "+
                "into "+targ->QP+" eyes!%^RESET%^",targ);
                targ->set_temporary_blinded(2 + random(3),"%^BOLD%^%^GREEN%^"+
                "The goo has burned your eyes!%^RESET%^");
                break;
            }
            else {
                tell_object(targ,"%^RED%^You scream in pain as "+
                "the %^BOLD%^%^GREEN%^goo%^RESET%^%^RED%^ begins "+
                "burning, but quickly wipe it away!%^RESET%^");
                tell_room(ETO,targ->QCN+"%^RED%^ screams in "+
                "pain and then quickly wipes the %^BOLD%^%^GREEN%^"+
                "goo%^RESET%^%^RED%^ from "+targ->QP+" eyes!"+
                "%^RESET%^",targ);
                break;
            }
      }
}
       

void stab_them() {
    if(objectp(TP) && !TP->query_true_invis()) {
        command("speech say without emotion");
        command("say you have stepped into something "+
        "that was best left alone.");
        command("say now you must perish.");
        add_attack_bonus(4);
        command("stab "+TPQN);
        add_attack_bonus(-4);
        command("scramble");
        command("kill "+TPQN);
    }
}

