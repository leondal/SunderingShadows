#include <std.h>
#include "/d/deku/keep/keep.h"
#include <daemons.h>
#define AR "/d/deku/armours/"+
#define WP "/d/deku/weapons/"+
#define WPS ({"stonecrusherhammer","stonecutter","graniteclub",\
"frostbitesickle","elazoshammer"})
#define ARS ({"deep_red_boots"})
#define SHDS ({"gloom_shield","shieldoflight"})
#define ARS2 ({"dralthoraks_flesh","diamond_helm","boots_of_twilight"})
//removing "yellow garment" - Saide

#define SEEK_ITEMS ({"obsidian robe", "graystaff",\
"amulet of protection","komnoels mutilator" }) 

#define DSEEK "deku_drakkan_item_seeking"
#define ODSEEK "old_deku_drakkan_item_seeking"

#define DKILLERS "deku_drakkan_killers"

inherit NPC;

int flag, delay, flag2, already_helped;
string helper;
void do_help(object to);
void check_present();
void go_home(object to);
void special_attack(object targ);

void init() {
    ::init();
    
    /*if(interactive(TP) 
    && member_array(TPQN,SAVE_D->query_array(DKILLERS)) != -1
    && !TP->query_invis()) {
        special_attack(TP);
        return;
    }*/
    if(interactive(TP) && !TP->query_invis()) {
        do_help(TO);
    }
    add_action("choose_item","choose");
    add_action("show_item","showme");
}

void create() {
    object ob;
    string *oitems, *items, oitem, nitem;
    ::create();
    set_name("drakkan");
    set_id(({"drakkan","elorian","yurnklaw","ranger","servant"}));
    set_short("Drakkan Elorian Yurnklaw, Silvanus' Sword");
    
    set_long("%^RESET%^The man you behold carries himself with an "+
    "aura of confidence and calmness.  His entire body is well "+
    "toned and his face reflects an image of youth, boyish "+
    "charm to accompany it.  The eyes that stare out from him "+
    "are a piercing, yet somehow calm %^BLUE%^light blue%^RESET%^ "+
    "and the hair that falls from the top of his head is a "+
    "thick and shining %^ORANGE%^brown%^RESET%^, that is kept "+
    "long, reaching nearly the middle of his back.  His ears "+
    "are slightly pointed, suggesting that he may have some "+
    "distant heritage that is not human.  A leaf amulet hangs "+
    "around his neck and from that amulet comes another "+
    "more brilliant aura.  He glances up, seeing you watch him "+
    "and offers a friendly smile, but the child-like innocence "+
    "of this man is betrayed by his reputation as one of the "+
    "chosen of silvanus.");

    set_gender("male");
    set_race("human");
    set_class("ranger");
    set_guild_level("ranger",34 + random(3));
    set_mlevel("ranger",query_guild_level("ranger"));
    set_guild_level("cleric",34);
    set_mlevel("cleric",34);
    set_mob_magic_resistance("average");
    set_spell_chance(30);
    set_func_chance(30);
    set_funcs(({"special_attack"}));
    set_spells(({"call lightning","thorn spray","dispel magic"}));
    set_alignment(5);
    set_hp(query_level() * 20);
    set_exp(query_max_hp() * 30);
    flag = 0;
    set_stats("strength",18 + random(2));
    set_stats("wisdom",17);
    set_stats("intelligence",15);
    set_stats("charisma",13);
    set_stats("constitution",17);
    set_stats("dexterity",18);

    set_attack_bonus(4);
    set_damage_bonus(4);
    set_property("full attacks",1);
    set_property("no death",1);
    //set_property("no rush",1);
    set_property("no paralyze",1);
    add_attack_bonus(6);
    set_overall_ac(-15 - (random(7)));
    set_property("magic",1);
    switch(random(20)) {
        case 0..5:
            ob = new(WP"jade_scimitar");
            ob->set_property("monsterweapon",1);
            ob->move(TO);
            command("wield scimitar");
            flag++;
            break;
        case 6..12:
            new("/d/common/obj/weapon/scimitar")->move(TO);
            command("wield scimitar");
            break;
        case 13..14:
            new("/d/common/obj/weapon/longsword")->move(TO);
            command("wield sword");
            break;
        case 15..19:
            ob = new(WP"ruby_scimitar");
            ob->set_property("monsterweapon",1);
            ob->move(TO);
            command("wield scimitar");
            flag++;
            break;
    }
    switch(random(60)) {
        case 0..14:
            ob = new("/d/deku/keep/obj/"+WPS[random(sizeof(WPS))]);
            ob->set_property("monsterweapon",1);
            ob->move(TO);
            check_present();
            flag++;
            break;
        case 15..20:
            new("/d/common/obj/weapon/scimitar")->move(TO);
            command("wield scimitar");
            break;
        case 21..48:
            ob = new("/d/deku/keep/obj/"+WPS[random(sizeof(WPS))]);
            ob->set_property("monsterweapon",1);
            ob->move(TO);
            check_present();
            flag++;
            break;
        case 49..52:
            new("/d/common/obj/weapon/warhammer")->move(TO);
            command("wield hammer");
            break;
        case 53..59:
            ob = new("/d/deku/keep/obj/"+SHDS[random(sizeof(SHDS))]);
            ob->set_property("monsterweapon",1);
            ob->move(TO);
            flag++;
            break;
    }
    if(flag < 2) {
        switch(random(2)) {
            case 0:
                ob = new("/d/deku/keep/obj/"+ARS[random(sizeof(ARS))]);
                ob->set_property("monsterweapon",1);
                ob->move(TO);
                flag++;
                break;
            case 1:
                ob = new("/d/deku/armours/"+ARS2[random(sizeof(ARS2))]);
                ob->set_property("monsterweapon",1);
                ob->move(TO);
                flag++;
                break;
        }
    }
    command("wearall");
    if(sizeof(SAVE_D->query_array(DSEEK)) < 1) {
        items = SEEK_ITEMS;
        if(sizeof(SAVE_D->query_array(ODSEEK))) {
            oitems = SAVE_D->query_array(ODSEEK);
            oitem = oitems[0];
            items -= ({oitem});
        }
        nitem = items[random(sizeof(items))];
        SAVE_D->remove_array(ODSEEK);
        SAVE_D->set_value(ODSEEK,nitem);
        SAVE_D->set_value(DSEEK,nitem);
    }
}

void check_present() {
    if(present("pick",TO)) {
        command("wield pick");
    }
    if(present("hammer",TO)) {
        command("wield hammer");
    }
    if(present("sickle",TO)) {
        command("wield sickle");
    }
    if(present("club",TO)) {
        command("wield club");
    }
}

void heart_beat() {
    int x;
    string *enemies;
    object cor;
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    enemies = query_attackers();
    
    /*if(sizeof(enemies) > 0) {
       for(x = 0;x < sizeof(enemies);x++) {
            if(!interactive(enemies[x])) continue;
            if(member_array(enemies[x]->query_name(),SAVE_D->query_array(DKILLERS)) == -1) {
                SAVE_D->set_value(DKILLERS,enemies[x]->query_name());
            }
        }
    }*/
    if(flag2 == 0 && query_current_attacker()) {
        if(ETO->query_property("used sticks")) ETO->remove_property("used sticks");
        new("/cmds/spells/s/_sticks_into_snakes.c")->use_spell(TO,0,20,20,"cleric");
        flag2 = 1;
        return;
    }
    if(delay > 400) {
        flag2 = 0;
        delay = 0;
    }
    if(flag2 == 1) {
        delay++;
    }            
}

void reset() {
    ::reset();
}

/*void special_attack(object targ) {
    command("say die you scum!");
    if(!objectp(targ)) return;
    new("/cmds/spells/t/_thorn_spray")->use_spell(TO,targ,30,30,"cleric");
}*/

void special_attack(object targ) {
    int x, atts;
    command("say you should have let me be, NOW YOU WILL DIE!");
    if(!objectp(targ)) return;
    atts = 2 + random(3);
    
    tell_object(targ,"%^RED%^Drakkan chants loudly and you feel "+
    "something attempt to grip your mind!%^RESET%^");

    tell_room(ETO,"%^RED%^Drakkan chants loudly and faces "+
    targ->QCN+"!%^RESET%^",targ);

    if(!"/daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death",-7)) { 
       tell_object(targ,"%^RED%^You feel your mind succumb to "+
       "the power that is attempting to grip it and your body "+
       "freezes!%^RESET%^");
       targ->set_paralyzed(30,"%^RED%^Your body is immobile, held "+
       "by the strange force.%^RESET%^");
       tell_room(ETO,targ->QCN+"%^RED%^'s body seems to freeze!"+
       "%^RESET%^",targ);
    }
    for(x = 0;x < atts;x++) {
        tell_object(targ,"%^RED%^Drakkan chants loudly and "+
        "stabs you in the chest!%^RESET%^");
        tell_room(ETO,"%^RED%^Drakkan chants loudly and stabs "+
        targ->QCN+" in the chest!%^RESET%^",targ);
        set_property("magic",1);
        if(!"/daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death",-4)) { 
            targ->do_damage("torso",roll_dice(2,8));
        }
        else {
            targ->do_damage("torso",roll_dice(4,8));
        }
        set_property("magic",-1);
    }
}
  
    
void do_help(object to) {
    object *alive;
    int people, x;
  
    if(!objectp(ETO)) return;
    if(!objectp(to)) return;
    if(already_helped == 1) return;
    
    alive = filter_array(all_living(ETO),"is_non_immortal_player",FILTERS_D);
    
    if(sizeof(alive) < 1) {
        if(!objectp(to)) return;
        return;
    }	
    command("speech hmm and then says");
    command("speak wizish");
    command("say you up for an adventure?");
    command("emote grins slightly");
}

void catch_say(string msg){
    ::catch_say(msg);
    if(interactive(TP)) {
        call_out("response",1,msg,TP);
    }
}

void convert_item_to_msg(string item, int x) {
    if(x == 0) {
         command("emote grins");
         command("say so you want an adventure, eh?");
    }               
    if(item == "graystaff") {
        switch(x) {
            case 0:
                command("say well, I seek the gray staff of an elderly "+
                "woman.  This woman is not natural, she's far beyond "+
                "that point.  Her body is corrupted and she now wields "+
                "the perverted winter of Auril, offering an imbalance "+
                "to the very natural world.  Slay her and bring the "+
                "staff back to me and I'll reward you.");
                break;
            case 1:
                command("say I am looking for the gray staff of "+
                "an elderly woman right now.  I seek nothing more "+
                "from this land.");
                break;
            case 2:
                command("say The staff is the item that the woman "+
                "uses to focus her power.  It is nothing more.  "+
                "Without the staff her evil cannot continue, that "+
                "is why I seek it.");
                command("say the woman wanders the forest occassionally.  "+
                "I have no idea how difficult she will be to find.  "+
                "I know that her flesh is a frost blue and her "+
                "eyes are a lifeless gray.");
                break;
        }
    }
    if(item == "amulet of protection") {
        switch(x) {
            case 0:
                command("say I seek a blue crystal amulet.  The only "+
                "real piece of information I can offer you is "+
                "that I think its located somewhere in the forest.  "+
                "If you can manage to find it and bring it back to "+
                "me then I will let you have anything that I've "+
                "got on me.");
                break;
            case 1:
                command("say all I seek is a blue crystal amulet.  "+
                "I seek nothing more of this land now.");
                break;
            case 2:
                command("say The amulet offers a magic that an "+
                "ally of mine wishes to study.  I believe "+
                "if the amulet falls into the wrong hands that "+
                "it may be able to be used to cause much havoc.  "+
                "I seek it to keep it out of the hands of evil "+
                "and for my ally to examine.");
                command("say I have no clear idea of where the "+
                "amulet might be found.  All that I know is that "+
                "something in the forest may have it in its "+
                "possession.  I've heard tale of a three armed "+
                "beast that carries gems, it may have it.");
                break;
        }        
    }
    if(item == "komnoels mutilator") {
        switch(x) {
            case 0:
                command("say I seek a weapon that has been corrupted "+
                "by the evil which it has caused.  The weapon is an "+
                "axe that was long ago used by a murderer.  "+
                "The axe could easily be carried in one hand by "+
                "anyone and from legend it is made of a crimson "+
                "substance.  I will reward you once I have it.");
                break;
            case 1:
                command("say I seek only an evil and corrupt axe "+
                "this day.  I wish nothing more from the land.");
                break;
            case 2:
                command("say I wish to take the axe and have it "+
                "destroyed.  I am certain that the evil acts it "+
                "was used to commit have corrupted it beyond "+
                "renewal.  Fortunately, the murderer who used it "+
                "has long since been dead.");
                command("hmm");
                command("say there was once a beautiful and "+
                "well kept graveyard somewhere on the outskirts of "+
                "this dying forest.  Until the shadowlord came into "+
                "being.... I'd look there for it, look for the name "+
                "Komnoel Gytorl, he was the murderer who wielded "+
                "it.");
                break;
        }
    }
    if(item == "yellow garment") {
        switch(x) {
            case 0:
                command("say I seek the yellow and blue garment "+
                "worn by a creature that should never have come "+
                "into being.  Bring the garment to me and I will "+
                "offer you a reward of any of the things I have "+
                "with me.");
                break;
            case 1:
                command("say I seek only the yellow and blue "+
                "garment.  I wish nothing more this day.");
                break;
            case 2:
                command("say this garment was once worn by a "+
                "good and kind halfling.  He fell some years ago "+
                "and the garment disappeared.  It took us a great "+
                "deal of time to learn of this halflings fate and "+
                "we are certain now that this creature has it.");
                command("emote sighs and shakes his head");
                command("say this creature is foul beyond "+
                "comprehension.  His body mutated and grotesque "+
                "as a result of something gone horribly wrong.  "+
                "He has been said to lead the bandits that occassionally "+
                "wander this forest, robbing those who stumble "+
                "upon them and 'falsely' protecting the forest "+
                "at night.");
                break;
        }
    }
    if(item == "obsidian robe") {
        switch(x) {
            case 0:
                command("say I seek the obsidian robe worn by "+
                "a very evil and foul beast.  I only seek the "+
                "robe for proof that the beast no longer "+
                "draws breath.  The beast is one of the damned "+
                "lycanthropies that dwell in this region.  "+
                "Bring me the robe and I will reward you.");
                break;
            case 1:
                command("say I only search for the obsidian robe "+
                "of a foul and evil beast, I want nothing more.");
                break;
            case 2:
                command("say The robe is made from a strange "+
                "obsidian colored fabric.  I do not know what magic "+
                "it contains and only want it for proof that the "+
                "wolf beast who wears it no longer lives.");
                command("emote visibly shudders and shakes his head");
                command("say the beast dwells somewhere on this "+
                "island, but I am not sure where.  I know that his "+
                "children come out at night and wander this forest.");
                break;
        }  
    }
    if(x == 0) {
        command("say if you want more %^CYAN%^information%^RESET%^ "+
        "just ask.");
        command("say if you want to look at an item that I have "+
        "available for rewards you can %^CYAN%^showme item%^RESET%^ " +
        "and I'll show you the item.");
        return;
    }
}

void show_item(string str) {
    object ob;
    if(!str) return;
    if(str) {
        /*if((string)TPQN != helper) {
            command("emote shakes his head and hmms");
            command("say you have never helped me, I have no reason "+
            "to show you anything of mine.");
            return 1;
        }*/ 

        if(TP->query_invis()) {
            command("say what?  Who goes there?");
            return 1;
        }
        
        TP->force_me("emoteat drakkan walks up to $N and points at "+
        "something.");

        if(!(ob = present(str,TO))) {
            command("shake");
            command("say I am sorry, I do not have that item for you "+
            "to look at.");
            return 1;
        }
        command("emote smiles");
        command("say very well, here is what the "+str+" looks like.");
        command("show "+str+" to "+TPQN);
        if(ob->query_property("enchantment") < 0) {
            command("whisper "+TPQN+" the magic on that item is "+
            "cursed and will only cause you harm.");
        }
        return 1;
    }
}        

void choose_item(string str) {
    object ob;
    if(!str) return;
    if(str) { 
        TP->force_me("emoteat drakkan walks up to $N and points at "+
        "something.");
        
        if((string)TPQN != helper) {
            command("emote shakes his head and hmms");
            command("say you have never helped me, I owe you no reward");
            return 1;
        }  
        if(!(ob = present(str,TO))) {
            command("shake");
            command("say I am sorry, I do not have that item.  "+
            "Please choose something else.");
            return 1;
        }
        if(ob->query_property("enchantment") < 0) {
            command("shake");
            command("say I am afraid that the magic on this item "+
            "would only hurt you.  I cannot give it to you.");
            command("whisper "+helper+" the magic of this item is "+
            "a curse and will harm you, please understand I cannot "+
            "give it to you.");
            return 1;
        }
        command("emote smiles");
        command("say very well, it is now yours.");
        if(ob->query_property("monsterweapon")) {
            ob->remove_property("monsterweapon");
        }
        command("give "+str+" to "+helper);
	  if(present(str, TO))
	  {
		command("emote hums softly");
		command("say I guess I'll just lay it here then.");
		command("drop "+str);
		command("emote smiles");
	  }
        command("say farewell now, I must be on my way.");
        remove_call_out("go_home");
        go_home(TO);
        return 1;
    }
}

void response(string msg, object ob){
    string *list, item;
    if(!objectp(ob)) return;
    list = SAVE_D->query_array(DSEEK);
    if(sizeof(list) < 1) return;
    if(sizeof(list) > 0) item = list[0];
    if(ob->query_invis() && !ob->query_true_invis()) {
        new("/cmds/spells/d/_dispel_magic")->use_spell(TO,0,35,35,"cleric");
        return;
    }
    if((strsrch(msg,"ello") != -1 || strsrch(msg,"reeting") != -1 
    && already_helped != 1)) {
        do_help(TO);
        return;
    }
    
    if((strsrch(msg, "adventure") != -1 
    || strsrch(msg, "Adventure") != -1 
    || strsrch(msg,"yes") != -1 || strsrch(msg,"Yes") != -1 
    && already_helped != 1)) {
        command("emote hmms and then nods quickly");
        command("speech say slowly");
        convert_item_to_msg(item, 0);
        return;
    }
    if(strsrch(msg,item) != -1 || strsrch(msg,"info") != -1) {
        command("speech take a deep breath and say");
        //command("emote nods and takes a deep breath");
        convert_item_to_msg(item,2);
        return;
    }
}

void go_home(object to) {
    if(!objectp(to)) return;
    tell_room(environment(to),"Drakkan offers a slight bow before "+
    "quickly and quietly wandering off through the forest.");
    to->move("/d/shadowgate/void");
    to->remove();
}

void receive_given_item(object ob){
    string item, *list, *nams;
    list = SAVE_D->query_array(DSEEK);
    nams = ob->query_id();
    if(sizeof(list) < 1) {
        command("give "+nams[0]+" to "+TPQN);
        command("say I have no need for that.");
        if(already_helped != 1) {
            command("say OOC - There is something wrong with me, "+
            "tell %^RED%^saide%^RESET%^.");
            return 1;
        }
    }
    item = list[0];
    if(ob->id(item)) {
        command("say You have did well, this is what I seek.");
        SAVE_D->remove_array(DSEEK);
        command("say I will reward you with anything that "+
        "I now have.  You have five minutes to make your decision "+
        "and then I must be on my way.");
        command("say you may %^CYAN%^showme item%^RESET%^ and get a "+
        "look at what you want before you choose.  When you are "+
        "ready please %^CYAN%^choose item%^RESET%^");
        command("emote carefully puts away the "+ob->query_name()+".");
        ob->remove();
        helper = TPQN;
        already_helped = 1;
        call_out("go_home",300,TO);
        return 1;
    }
    command("shake");
    convert_item_to_msg(item,1);
    command("give "+nams[0]+" to "+TPQN);
    return 1;
}

/*void kill_ob(object victim, int which) {
    int hold;
    hold = ::kill_ob(victim, which);
    if(member_array(victim->query_name(),SAVE_D->query_array(DKILLERS)) == -1
    && interactive(victim)) {
        command("say I will remember this, SCUM!");
        SAVE_D->set_value(DKILLERS,victim->query_name());
    }  
    return hold;
}*/

void die(object ob) {
    int x;
    object *inv;
    tell_room(ETO,"A %^CYAN%^brilliant light%^RESET%^ surrounds "+
    "drakkan as he falls to the ground, dissolving most of what "+
    "he has!");
    inv = all_inventory(TO);
    for(x = 0;x < sizeof(inv);x++) {
        if(inv[x]->query_property("monsterweapon")) {
            if(!random(12)) {
                inv[x]->remove_property("monsterweapon");
                continue;
            }
        }
    }
    return ::die(ob);
}

