#include <std.h>
#include <daemons.h>
#include "/d/deku/inherits/forest.h"

inherit MONSTER;
int exps;

void create() 
{
    object ob;
    int x;
    ::create();
	set_race("athach");
    set_name("abomination");
    set_id(({"athach","abomination","giant","monstrous abomination"}));
    set_short("A monstrous three armed abomination");
    
    set_long("%^BOLD%^%^GREEN%^This monstrous creature towers "+
    "nearly twenty feet high.  Its body is a mound of flesh "+
    "that has not been toned nor kept clean.  It offers a "+
    "partcularly disturbing smell to anyone coming within "+
    "sight of it.  More disturbing than its odor is the "+
    "massive arm that grows unnaturally from the center of its "+
    "grotesquely wide chest.  The flesh that composes this "+
    "creature is a sickly green color, it is impossible to "+
    "determine if its current hue is the natural one or a "+
    "result of prolonged improper care.  Its obese face is composed of "+
    "an out of place small nose, squinted and tiny eyes, "+
    "two contrasting ears, one small, and the other much larger.  "+
    "The mouth centered in its face is wide and continually "+
    "produces an abundance of saliva that hangs out in the form "+
    "of yellowish slobber.   An almost hog-like tusk grows up "+
    "from each bottom corner and smaller, peg-like, teeth compose "+
    "the rows visible within.%^RESET%^");
    
    set_hd(20,1);
    add_search_path("/cmds/fighter");
    set_body_type("humanoid");
    set_size(4);
    set_hp(1000 + random(30));
   //set_exp(10000 + random(1000));
   // exps = query_exp();
    set_stats("strength",19);
    set_stats("intelligence",7);
    set_stats("wisdom",10);
    set_stats("charisma",6);
    set_stats("constitution",21);
    set_stats("dexterity",12);
    set_alignment(9);
    set("aggressive",27);
    set_property("full attacks",1); 
    //set_property("no bows",1);
    set_func_chance(25);
    set_funcs(({"bite","stun"}));
    set_max_level(30);
    set_overall_ac(-5);
    add_limb("center hand", "torso", 0, 0, 0);
    set_wielding_limbs(({"center hand"}));

    ob = new("/d/common/obj/weapon/club_lg");

    if(!random(3)) ob->set_property("enchantment",1);
    ob->move(TO);
    command("wield club");
    
    new("/d/common/obj/weapon/club_lg")->move(TO);
    command("wield club");
    new("/d/common/obj/weapon/club_lg")->move(TO);
    command("wield club in center hand");
    if(!random(2)) 
    {
        ob = new("/d/common/obj/misc/pouch");
        ob->move(TO);
        command("wear pouch");
        new("/d/deku/armours/amulet_of_protection")->move(ob);
    }
    for(x = 0;x < 4 + random(3);x++) { 
        new("/d/antioch/valley/obj/gem")->move(TO);
    }
    FENC->fix_nogo(TO);
	set_new_exp(20, "very high");
    set_property("not random monster", 1);
}

void heart_beat() {
    object ob;
    ::heart_beat();
    if(!objectp(TO) || !objectp(ETO)) return;
    if(!random(7)) {
        if((ob = present("snake",ETO))) {
        if(!objectp(ob)) return;
            tell_room(ETO,"%^RED%^The abomination smashes the "+
            "head of the snake with its club!%^RESET%^");
            if(!objectp(ob)) return;
            ob->die();
            return;
        }
    }
}

void stun(object targ) {
    if(!objectp(targ) || !objectp(TO)) return;
    tell_room(ETO,"%^RED%^The abomination slams "+targ->QCN+"%^RED%^ "+
    "in the face with one of his large clubs!%^RESET%^",targ);
    tell_object(targ,"%^RED%^The abomination slams you in the "+
    "face with one of its clubs!%^RESET%^");
    targ->do_damage("head",roll_dice(4,6));
    if(!SAVING_D->saving_throw(targ,"paralyzation_poison_death",-6)) {
        tell_object(targ,"%^BOLD%^%^BLACK%^You reel unsteadily "+
        "backwards from the force of the blow!%^RESET%^");
        targ->set_paralyzed(10 + random(16),"%^RED%^You struggle "+
        "to regain your balance!%^RESET%^");
        tell_room(ETO,targ->QCN+"%^BOLD%^%^BLACK%^ reels unsteadily "+
        "backward from the force of the blow!%^RESET%^",targ);
        return;
    }
    tell_object(targ,"%^YELLOW%^You manage to shake the brunt of the "+
    "blow off.%^RESET%^");
    tell_room(ETO,targ->QCN+"%^YELLOW%^ shakes "+targ->QP+" head, "+
    "absorbing the blunt of the blow.%^RESET%^",targ);
    return;
}

void bite(object targ) {
    if(!objectp(targ) || !objectp(TO)) return;
    if((random(20) + 6) > (int)targ->query_stats("dexterity")) {
        tell_room(ETO,"%^RED%^The abomination suddenly lunges forward "+
        "and bites "+targ->QCN+"%^RED%^ on the neck!%^RESET%^",targ);
        
        tell_object(targ,"%^RED%^The %^BOLD%^%^BLACK%^abomination"+
        "%^RESET%^%^RED%^ suddenly lunges forward and bites "+
        "you on the neck!%^RESET%^");
        
        targ->do_damage("neck",roll_dice(2,8));
        
        if(!SAVING_D->saving_throw(targ,"paralyzation_poison_death",-3)) { 
            tell_object(targ,"%^BLUE%^The bite drains your "+
            "strength and leaves you feeling weak!%^RESET%^");
            targ->add_stat_bonus("strength",-1);
            return;
        }
    }
    tell_room(ETO,"%^RED%^The abomination suddenly lunges forward "+
    "at "+targ->QCN+"%^RED%^ but "+targ->QS+" manages to dodge "+
    "the attack.%^RESET%^",targ);
    tell_object(targ,"%^RED%^The %^BOLD%^%^BLACK%^abomination"+
    "%^RESET%^%^RED%^ suddenly lunges forward at you, but you "+
    "manage to dodge the attack!%^RESET%^");
    return;
}

int query_watched() { return 40 + random(71); }
