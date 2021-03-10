#include <std.h>
#include <daemons.h>
#include "/d/deku/inherits/graveyard.h"
inherit MONSTER;

void make_me(int i) 
{
    object ob, ob2;
    switch(i) {
    case 0:
        set_name("A crimson mohrg");
        set_id(({"mohrg","crimson mohrg","undead"}));
        set_short("%^RED%^A crimson mohrg%^RESET%^");
        set_long("%^RED%^This grotesque creature almost appears "+
        "to be a red skeleton at first glance.  The flesh that "+
        "remains on it has been pulled tightly against the "+
        "bones that quite clearly linger beneath.  Several "+
        "places on its body have been torn open to reveal "+
        "the bones and rotting insides.  Strangely, "+
        "every visible part of this creature is a "+
        "deep crimson color, almost like something, "+
        "or someone has painted it in a cruel joke.  "+
        "More disturbing, is its tongue, hanging ever out of "+
        "its mouth and having a clawed tentacle at the end.  "+
        "The most freightening part of this creature are "+
        "its eyesockets which burn brightly with embers "+
        "that reflect an intelligence and a deep hatred.%^RESET%^");
        if(!random(2)) {
            ob = new(GY_OBJS+"komnoels_mutilator");
        }
        if(!ob) ob = new("/d/common/obj/weapon/handaxe");
        ob->move(TO);
        if(!random(2)) {
            ob2 = new(GY_OBJS+"komnoels_penetrator");
        }
        if(!ob2) ob2 = new("/d/common/obj/weapon/handaxe");
        ob2->move(TO);
        command("wield axe");
        command("wield axe 2");

        break;
    case 1:
        set_name("A charred mohrg");
        set_id(({"mohrg","charred mohrg","undead"}));
        set_short("%^BOLD%^%^BLACK%^A charred mohrg%^RESET%^");
        set_long("%^BOLD%^%^BLACK%^This grotesque creature "+
        "almost appears to be a skeleton at first glance.  "+
        "Its flesh has been completely seared off and "+
        "the bones beneath have been charred by what you "+
        "would guess to be an intense heat.  The stomach of "+
        "this creature is filled with what could very well "+
        "be a gigantic purple worm that snakes its way up the "+
        "throat to become the tongue.  The tongue of this "+
        "creature is ever hanging out of its mouth and "+
        "ends in a clawed tentacle.  The most freightening "+
        "part of this creature is the bright %^RED%^embers"+
        "%^BOLD%^%^BLACK%^ that shine out from its eyesockets, "+
        "reflecting an intelligence and a deep hatred.%^RESET%^");
        set_size(3);
        if(!random(2)) {
            ob = new(GY_OBJS+"devians_splitter");
        }
        if(!ob) {
            ob = new("/d/common/obj/weapon/battle_axe");
        }
        ob->move(TO);
        command("wield axe");
        new("/d/common/obj/weapon/longsword")->move(TO);
        command("wield sword");
        break;
    }
}

void create() 
{
    ::create();
    set_race("mohrg");
    set_gender("neuter");
    set_body_type("human");
    set_alignment(9);
    set("aggressive",26);
    set_hd(26,4);
    set_hp(675 + random(20));
    set_new_exp(20, "high");
    set_stats("strength",18);
    set_stats("wisdom",10);
    set_stats("intelligence",11);
    set_stats("dexterity",13);
    set_stats("charisma",10);
    set_stats("constitution",0);
    set_property("undead",1);
    set_property("no death",1);
    set_property("full attacks",1);
    set_property("weapon resistance",1);
    set_funcs(({"paralyzing_touch"}));
    set_max_level(25);
}

void paralyzing_touch(object targ) 
{
    int x;
    if(!objectp(targ)) return;
    tell_object(targ,TO->query_name()+"%^RED%^ lashes out at and strikes "+
    "you with its grotesque tongue!%^RESET%^");
    tell_room(ETO,TO->query_name() +"%^RED%^ lashes out "+
    "at "+targ->QCN+"%^RED%^ with its grotesque tongue "+
    "and strikes "+targ->QO+"%^RED%^!%^RESET%^",targ);
    targ->cause_typed_damage(targ, return_target_limb(),
    roll_dice(4,20), "negative energy");
    if(targ->will_save(28)) 
    { 
        tell_object(targ,"%^RED%^The touch of the grotesque tongue "+
        "paralyzes your body!%^RESET%^");
        targ->set_paralyzed(roll_dice(6,6),"%^RED%^Your body "+
        "is paralyzed!%^RESET%^");
    }
}

void heart_beat() 
{
    object ob;
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if((ob = present("snake",ETO))) 
    {
        tell_room(ETO,query_name()+" shoots its long tongue "+
        "out and grabs the snake, eating it!");
        TO->add_hp(ob->query_hp());
        ob->remove();
    }
    if((ob = present("corpse",ETO)) && !living(ob)) 
    {
        new("/cmds/spells/a/_animate_dead")->use_spell(TO,0,20,20,"cleric");
        return;
    }
}