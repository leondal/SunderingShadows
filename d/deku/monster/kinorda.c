#include <std.h>
#include <daemons.h>
#include "/d/deku/inherits/forest.h"

inherit MONSTER;

int x, tmp, summoning;

create() {
    int y;
    int item;
    ::create();
    set_name("kinorda");
    set_id( ({"kinorda","priest"}));
    set_gender("male");
    set_race("human");
    set_short("Kinorda, Forgotten High Priest");
    
    set_long("%^RED%^This immaculately clean man stands around "+
    "six feet tall.  His body appears both stout and well defined.  "+
    "His hair is long and strangely black and seems to glow "+
    "with a strange darkness.  His eyes, in starking contrast, "+
    "are a very intense and very lively %^BOLD%^%^GREEN%^emerald "+
    "green%^RESET%^%^RED%^.  He is dressed in a fine robe that is "+
    "stretched tight and reveals his muscular body hidden just "+
    "beneath.    His hands appeared scaled or scabbed and are "+
    "a very %^BOLD%^%^BLACK%^sooty black%^RESET%^%^RED%^ and his "+
    "sandled feet are in the same state.  He carries a staff and "+
    "an aura about him suggests that he knows how to use it "+
    "precisely.  An amulet hangs around his neck, the stone "+
    "on it nothing more than a glowing ember from a fire that "+
    "must have ceased its burning some time ago.%^RESET%^");

    set_alignment(8);
    add_money("gold", 1000 + random(1500));
    add_money("platinum",50 + random(70));
    set("aggressive","talk");
    x = 32 + random(3);
    set_class("mage");
    set_class("cleric");
    set_mlevel("mage", x);
    set_mlevel("cleric",x);
    set_guild_level("mage",x);
    set_guild_level("cleric",x);
    set_stats("strength",16);
    set_stats("intelligence",17);
    set_stats("constitution",19);
    set_stats("dexterity",15);
    set_stats("wisdom",25);
    set_stats("charisma",17);
    set_property("full attacks",1);
    set_mob_magic_resistance("average");
    set_spells(({"burning hands","fireball",
    "scorcher","flame strike","wall of fire","lower resistance",
    "magic missile","powerword stun","fire storm","scorcher",
    "fireball","scorcher","flame strike","powerword stun",
    "hideous laughter",}));
    
    set_spell_chance(55);
    set_hp(x * 22 + random(21));
    set_exp(query_max_hp() * 50 + random(26));
    set_funcs(({"fire","summon","control","control","fire",
    "control","control","summon"}));
    set_func_chance(65);  
    set_max_level(25);
    set_overall_ac(2 - (random(4)));
    new(DEKU_ARM"fire_robe")->move(TO);    
    new(DEKU_ARM"fire_sandals")->move(TO);    
    new(DEKU_ARM"fire_cloak")->move(TO);    
    new(DEKU_WEP"kinordas_staff")->move(TO);    
    new(DEKU_ARM"spellring")->move(TO);    
    new(DEKU_ARM"fire_band")->move(TO);
    command("wearall");
    command("wield staff");
    y = random(2);
    if(y) {
        present("robe")->set_property("monsterweapon",1);
    }
    if(!y) {
        item++;
    }
    y = random(3);
    if(y) {
        present("sandals")->set_property("monsterweapon",1);
    }
    if(!y) {
        item++;
    }
    y = random(2);
    if(y || item > 1) {
        present("cloak")->set_property("monsterweapon",1);
    }
    if(!y) {
        item++;
    }
    y = random(5);
    if(y || item > 1) {
        present("staff")->set_property("monsterweapon",1);
    }
    if(!y) {
        item++;
    }
    y = random(15);
    if(y || item > 1) {
        present("spell ring")->set_property("monsterweapon",1);
    }
    if(!y) {
        item++;
    }
    if(item > 1) {
        present("band")->set_property("monsterweapon",1);
    }
    command("speak wizish");
}

void heart_beat() {
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(TO->query_paralyzed()) {
        tell_room(ETO,"%^RED%^Kinorda seems unaffected.%^RESET%^");
        TO->remove_paralyzed();
    }
    if(present("corpse",ETO) && !living(present("corpse",ETO))) {
        new("/cmds/spells/a/_animate_dead")->use_spell(TO,0,x,x,"mage");
        return;
    }
}


void init() {
    ::init();
    if(!tmp) {
        new("/cmds/spells/s/_stoneskin")->use_spell(TO,TO,20,20,"mage");
        tmp = 1;
    }
    add_action("no_stab","stab");
    add_action("no_stab","crit");
    add_action("no_stab","rush");
}

void fire(object targ) {
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    
    tell_room(ETO,"%^RED%^Kinorda turns to "+targ->QCN+"%^RED%^ and mumbles "+
    "a short phrase and "+targ->QP+" body is suddenly outlined "+
    "in fire!%^RESET%^",targ);

    tell_object(targ,"%^RED%^Kinorda turns to you and mumbles a short phrase "+
    "and your body is outlined in fire!%^RESET%^");

    tell_object(targ,"%^RED%^Your body is wracked with intense "+
    "pain from the fire and you struggle to even move!%^RESET%^");
    targ->do_damage("torso",roll_dice(6,6));
     
    if(!SAVING_D->saving_throw(targ,"paralyzation_poison_death",-2)) { 
        targ->set_paralyzed(20,"%^RED%^The intense pain "+
        "leaves you immobile.%^RESET%^");
        return 1;
    }
    targ->set_paralyzed(12,"%^RED%^The intense pain leaves "+
    "you immobile.%^RESET%^");
    return 1;
}

void do_successful_summon() {
    int y, g, i;
    object mob;
    y = 1 + random(2);
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    while(y) {
        y--;
        switch(random(2)) {
            case 0:
                g++;
                break;
            case 1:
                i++;
                break;
        }        
    }
    for(y = 0;y < i;y++) {
        mob = new(DEKU_MON"fire_imp");
        mob->move(ETO);
        TO->add_protector(mob);
    }
    for(y = 0;y < g;y++) {
        mob = new(DEKU_MON"hellfire_golem");
        mob->move(ETO);
        TO->add_protector(mob);
    }
    tell_room(ETO,"%^RED%^Some servants arrive to aide their "+
    "master.");
}

void do_failed_summon() {
    if(!objectp(TO)) return;
    command("say DAMN FOOLS!! Don't look like any of them are gonna show....");
}

void summon() {
    command("yell SERVANTS!!!!!  COME TO MY AIDE!!!");
    if(!random(6) && !summoning) {
        summoning = 1;
        call_out("do_successful_summon",10);
        return 1;
    }
    call_out("do_failed_summon",10);
    return 1;
}        

void control() {
    int y;
    object *mobs;
    if(!objectp(ETO)) return;
    mobs = all_living(ETO);
    mobs -= ({TO});
    for(y = 0;y < sizeof(mobs);y++) {
        if(avatarp(mobs[y])) continue;
        if(interactive(mobs[y])) {
            if(!SAVING_D->saving_throw(mobs[y],"paralyzation_poison_death",8)) { 
                tell_object(mobs[y],"%^RED%^You feel a force "+
                "compel you to protect Kinorda and you "+
                "can't seem to deny it!");
                tell_room(ETO,mobs[y]->QCN+"%^RED%^ stands in "+
                "protection of Kinorda!%^RESET%^",mobs[y]);
                TO->add_protector(mobs[y]);
                continue;
            }
            tell_object(mobs[y],"%^RED%^You feel a force "+
            "compel you to protect Kinorda, but you manage "+
            "to deny its influence!%^RESET%^");
            continue;
        }
        if(!SAVING_D->saving_throw(mobs[y],"paralyzation_poison_death",-3)) { 
            tell_room(ETO,mobs[y]->QCN+"%^RED%^ stands in "+
            "protection of Kinorda!%^RESET%^",mobs[y]);
            TO->add_protector(mobs[y]);
            continue;
        }
    }
}
         
 


int no_stab(string str) {
    if(TO->id(str)) {
        command("say I warned you, you ignorant fool.  Now "+
        "you will die and after I'm through killing you "+
        "I'll bring your corpse back as my pet.");
        new("/cmds/spells/f/_fireball")->use_spell(TO,TP,x,x,"mage");
        fire(TP);
        return 1;
    }
}

void talk() {
    call_out("talk2",4);
    return;
}

void talk2() {
    if(!objectp(TO)) return;
    command("speech slur slightly");
    
    command("say I have no quarrel with any of "+
    "those that live in this realm.");
    
    command("say you may leave through this portal, "+
    "I offer an apology for any inconvenience.");
    
    command("say ..... some I suppose, are fools, but "+
    "do take my offer and leave, or I will be "+
    "boiling your flesh and playing with your entrails "+
    "long before I grow bored with torturing you....");
}

void die(object ob) {
    int x;
    tell_room(ETO,"%^RED%^Kinorda whispers:%^RESET%^  I can "+
    "never die... if only it were that simple...I will return...");       
    return ::die(ob);
}

int query_watched() { return 1000; }
