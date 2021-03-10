// Illithid FleshWarper  - LoKi - 01-02-2008 ((gith_hunt.c)


#include <std.h>

#include "../githyanki.h"
inherit MONSTER;

void create() {
    object ob;
    ::create();
    set_name("illithid");
    set_id(({"illithid","monster","fleshwarper","gruesome illithid"}));
    set_race("illithid");
    set_gender("female");
    set_short("%^RESET%^%^MAGENTA%^gr%^RESET%^%^RED%^u%^RESET%^%^MAGENTA%^es%^"+
"RESET%^%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^me i%^RESET%^%^BOLD%^%^MAGENTA%^"+
"l%^RESET%^%^MAGENTA%^lith%^RESET%^%^WHITE%^i%^RESET%^%^MAGENTA%^d%^RESET%^");

    set_long("%^RESET%^%^MAGENTA%^The creature that stands before you once was an "+
"%^RESET%^%^BOLD%^%^MAGENTA%^illithid%^RESET%^%^MAGENTA%^. Its frame is %^RESET%^"+
"%^BOLD%^%^BLACK%^gaunt %^RESET%^%^MAGENTA%^and its movements alien. Its head is "+
"large and squid like, ending in a number of tentacles that writhe around. However"+
" the resemblance ends there, as it looks like several extra body parts have been "+
"grafted onto the creature. An %^RESET%^%^BOLD%^%^BLACK%^eyestalk %^RESET%^%^MAGENTA%^"+
"from what looks like a %^RESET%^%^BOLD%^%^BLACK%^beholder %^RESET%^%^MAGENTA%^extends"+
" from their neck, each arm is from a %^RESET%^%^GREEN%^diff%^RESET%^%^BOLD%^%^GREEN%^e"+
"%^RESET%^%^GREEN%^rent creat%^RESET%^%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^re%^RESET%^"+
"%^MAGENTA%^, and the weight of several grotesque %^RESET%^%^RED%^sacs %^RESET%^%^MAGENTA%^"+
"hunches its back and makes its movements sporatic. There is a look of complete madness "+
"in its eyes. %^RESET%^");
    set_size(2);
    set_alignment(6);
    set_level(22);
    set_hd(22,2);
    set_max_hp(random(50)+400);
    set_hp(query_max_hp());
    set_overall_ac(-2);
    set_mob_magic_resistance("average");
    set_property("swarm",1);
    set_stats("intelligence",18);
    set_stats("wisdom",14);
    set_stats("strength",18);
    set_stats("charisma",3);
    set_stats("dexterity", 18);
    set_stats("constitution",17);
      
    set_class("mage");
    
    set_class("psion");
    set_mlevel("mage",22);
    set_mlevel("psion",22);
    set_guild_level("psion",22);
    set_guild_level("mage",22);
    add_search_path("/cmds/psion");
    add_search_path("/cmds/mage");

    set_exp(15000);
    set_max_level(25);

    set_spell_chance(40);
    set_spells(({"magic missile", 
"lightning bolt", 
"breath of the black dragon", 
"fireball"}));
    set_funcs(({"special_1","special_2","special_3"}));
    set_func_chance(40);

    set_body_type("human");
	
    ob = new("/d/common/obj/armour/robe");
    ob->move(TO);
    ob->set_short("%^BLACK%^%^BOLD%^tattered black robe%^RESET%^");
    ob->set_property("enchantment",3);
    ob->set_property("monsterweapon",1);
    command("wear robe");

    ob = new("/d/common/obj/armour/bracers");
    ob->move(TO);
    ob->set_property("enchantment",3);
    ob->set_property("monsterweapon",1);
    command("wear bracers");

		
    set("aggressive","agg_func");
    set_emotes(10,({"%^RESET%^%^MAGENTA%^The illithid pokes at some flesh%^RESET%^",
"%^RESET%^%^RED%^The illithid bleeds from several wounds%^RESET%^",
"%^RESET%^%^RED%^The illithid rips off a peice of her torso and shoves it into another spot%^RESET%^"}),0);
    set_achats(10,({"%^BLACK%^%^BOLD%^The illithid screams!!!%^RESET%^"}));
}

void agg_func() {
    if (TP->query_invis()) {return;}
    force_me("speech %^RESET%^%^MAGENTA%^gurgle in a broken slur%^RESET%^");
    force_me("say You will not take me! I will not be a gith's toy!!");
        if(!TO->query_property("blink")){
        new("/cmds/spells/b/_blink.c")->use_spell(TO,TO,17,100,"mage");
        }
    force_me("emoteat "+TPQN+ " %^BLACK%^%^BOLD%^The $M screams and leaps at $N.%^RESET%^");
    force_me("kill "+TP->query_name());
    
return;
}

int special_1(object target) {
    object *pplz;
    int i,freeze;
    pplz = all_living(ETO);
    tell_room(ETO,"%^CYAN%^The illithid hunches over, and exposes a ghostly white sac that spews forth a white mist!");
    TO->set_property("magic",1);
    for(i=0;i<sizeof(pplz);i++) {
        if("daemon/saving_d"->saving_throw(pplz[i],"breath_weapon")) {
           tell_object(pplz[i],"%^RESET%^%^BOLD%^the mist spreads towards you, but you manage to avoid most of it%^RESET%^");
           pplz[i]->do_damage("torso",roll_dice(4,8));
        }
        else {
           tell_object(pplz[i],"%^RESET%^%^BOLD%^the mist envelops you, freezing every bone in your body%^RESET%^");
           pplz[i]->do_damage("torso",roll_dice(8,8));
           freeze = pplz[i]->query_stats("constitution");
           freeze = 20-freeze;
           pplz[i]->set_paralyzed(freeze*2);
        }
    }
    TO->remove_property("magic");
    return 1;
}

int special_2(object target) {
    tell_object(target,"%^GREEN%^The illithid lashes out with a tentacle that came from... somewhere...");
    tell_room(ETO,"%^GREEN%^A tentacle snakes out from the illithid and slashes "+target->QCN+"!",target);
    TO->set_property("magic",1);
    target->add_poisoning(50);
    target->do_damage("torso",random(10)+20);
    tell_object(target,"%^GREEN%^Your veins begin to burn!");
    TO->remove_property("magic");
    return 1;
}

int special_3(object target) {
    tell_object(target,"%^RED%^%^BOLD%^The illithid grabs you with it's tentacles and lifts you off the ground");
    tell_room(ETO,"%^RESET%^%^RED%^the illithid grabs "+target->QCN+" with it's tentacles and holds "+target->QCN+" up!",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(15)+30);
    TO->remove_property("magic");
    tell_object(target,"You resist the tentacles boring into your head and the illithid throws you in anger");
    tell_room(ETO,"%^RED%^%^BOLD%^Tentacles try to bore into "+target->QCN+"'s head but they fail and it throws "+target->QCN+" across the room.",target);
    target->set_paralyzed(30,"You are trying to catch your breath!");
    return 1;
}
