#include <std.h>
#include "../area_stuff.h"

inherit ELDEBARO_MONSTER;

int level;

void create() 
{
    object ob;
    string me;
    :: create();
    set_name("wandering nomad");
    set_id(({"nomad", "crazed nomad", "insane nomad", "wandering nomad", "man", "cloaked man", "eldebarocreature"}));
    set_short("%^RESET%^%^ORANGE%^A man cl%^BOLD%^oa%^RESET%^%^ORANGE%^k%^BOLD%^e%^RESET%^%^ORANGE%^d "+
    "in a %^BOLD%^%^BLACK%^dark%^RESET%^%^ORANGE%^ robe%^RESET%^");
    
    set_long("%^RESET%^%^ORANGE%^This hunched over man looks quite insane. His eyes are darting back and "+
    "forth constantly and chaotically, as if he is either unsure of where he is or maybe even unsure of "+
    "what he is. A constant %^BOLD%^%^BLACK%^darkness%^RESET%^%^ORANGE%^ dwells over him, almost as if he "+
    "is possessed by something or perhaps somehow %^BOLD%^%^RED%^cursed%^RESET%^%^ORANGE%^. His average "+
    "body is exceedingly tense as well, suggesting that perhaps he is constantly on the look out for "+
    "something or just very afraid. He is cloaked in a dark robe and wields two serrated sickles which he "+
    "ocassionally slashes out at the very air in front of him with.%^RESET%^");
    me = TO->query_short();
    
    set_gender("male");
    
    set_class("ranger");
    level = 32 + random(9);
    set_guild_level("ranger",level);
    set_mlevel("ranger",level);
    
    set_max_hp(level * 20);
    set_hp(query_max_hp());
    set_size(2);
    set_property("magic",1);
    set_overall_ac(-20);
    set_mob_magic_resistance("average");
    set_new_exp(level, "normal");
    set_body_type("humanoid");
    set_race("human");
    set("aggressive",50);

    set_alignment(9);
    
    ob = new(ELOB"shroud_of_darkness");
    if(random(6)) { ob->set_property("monsterweapon",1); }
    ob->move(TO);
    command("wear robe");
    ob = new(ELOB+"the_reaping");
    ob->move(TO);
    ob->set_property("monsterweapon", 1);
    command("wield sickle");
    ob = new(ELOB+"the_reaping");
    ob->move(TO);
    ob->set_property("monsterweapon", 1);
    command("wield sickle");
    
    set_property("full attacks",1);

    add_money("gold",random(1800)+600);
    
    set_emotes(3, ({"%^BOLD%^%^BLACK%^Darkness threatens to overwhelm you!%^RESET%^",
	    me+" %^BOLD%^%^GREEN%^SCREAMS in rage!%^RESET%^",
	    me+" %^BOLD%^%^GREEN%^CACKLES%^BOLD%^%^WHITE%^ insanely!%^RESET%^",
	    me+" %^BOLD%^%^BLACK%^swings his weapons wildly at the air in front of him!%^RESET%^",
	    me+" %^BOLD%^%^GREEN%^spits in your face!%^RESET%^",}),1);

    set_achats(4,({
        me +"%^BOLD%^%^BLACK%^ whispers hoarsely: %^RESET%^we should have not came here...", 
        me + "%^BOLD%^%^MAGENTA%^ says rapidly: %^RESET%^we will ALL die here.... ",
        me + "%^BOLD%^%^GREEN%^ utters barely above a whisper: %^RESET%^He's watching you too, you know.... he'll come for you...",
        me + "%^BOLD%^%^CYAN%^ cackles before speaking: %^RESET%^You're going to LOVE it on this side, the world looks so different!",
    }));
        
        
    set_property("no paralyze",1);
    set_property("no tripped",1);
    
    set_speed(50);
    set_moving(1);
    
    set_nogo(({DOCKROOM}));
    
    set_property("add kits",20);
    
    set_stats("strength",19);
    set_stats("dexterity",19);
    set_stats("constitution",22);
    set_stats("intelligence",1);
    set_stats("wisdom",1);
    set_stats("charisma",1);
    
    add_attack_bonus(roll_dice(1,10));
    add_damage_bonus(roll_dice(1,6));
    
    set_monster_feats(({
      "shatter",
      "sunder",
      "whirl"
    }));
    set_funcs(({
	   "insane_blows", 
       "push_em",
       "insane_blows",
       "insane_blows",
       "insane_blows",
       "push_em",
       "something_evil"
	}));
    set_func_chance(35);   
}

void insane_blows(object targ) 
{
    object storm;
    string me;
    int hits;

    if(!objectp(TO)) { return; }
    if(!objectp(targ)) { return; }
    if(!objectp(ETO)) { return; }
    me = TO->query_short();
    tell_object(targ, me +"%^BOLD%^%^BLACK%^ CHARGES%^BOLD%^%^YELLOW%^ at you, screaming in some bizarre "+
    "language, both of his weapons swinging wildly!%^RESET%^");
    
    tell_room(ETO, me +"%^BOLD%^%^BLACK%^ CHARGES%^YELLOW%^ at "+targ->QCN+", screaming in some bizarre "+
    "language, both of his weapons swinging wildly!%^RESET%^", targ);
    hits = 2 + random(5);
    if(targ->reflex_save(25))
    {
        tell_object(targ, "%^BOLD%^%^GREEN%^You are able to move just in time and are only nicked by "+
        me+"%^BOLD%^%^GREEN%^'s weapons!");
        
        tell_room(ETO, targ->QCN+"%^BOLD%^%^GREEN%^ is able to move just in time and is only nicked "+
        me+"%^BOLD%^%^GREEN%^'s weapons!%^RESET%^", targ);
        
        targ->cause_typed_damage(targ, targ->return_target_limb(), (roll_dice((hits*3),8)/2),"slashing");
    }
    else
    {
        tell_object(targ, "%^BOLD%^%^WHITE%^You are %^BOLD%^%^RED%^UNABLE%^BOLD%^%^WHITE%^ to move in time and "+
        me+"%^BOLD%^%^RED%^ SLASHES%^BOLD%^%^WHITE%^ wildly into you!%^RESET%^");
        
        tell_room(ETO, targ->QCN+"%^BOLD%^%^WHITE%^ is %^BOLD%^%^RED%^UNABLE%^BOLD%^%^WHITE%^ to move in time and "+
        me+"%^BOLD%^%^RED%^ SLASHES%^BOLD%^%^WHITE%^ wildly into "+targ->QO+"!%^RESET%^", targ);
        targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice((hits*3),8),"slashing");
    }
    return;
    
}

void push_em(object targ)
{    
    string me;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;
    me = TO->query_short();
    
    tell_object(targ, me +"%^BOLD%^%^BLACK%^ CHARGES%^BOLD%^%^YELLOW%^ at you, screaming in some bizarre "+
    "language, a look of %^BOLD%^%^RED%^RAGE%^BOLD%^%^YELLOW%^ on his face!%^RESET%^");
    
    tell_room(ETO, me +"%^BOLD%^%^BLACK%^ CHARGES%^YELLOW%^ at "+targ->QCN+", screaming in some bizarre "+
    "language, a look of %^BOLD%^%^RED%^RAGE%^BOLD%^%^YELLOW%^ on his face!%^RESET%^", targ);
    
    if(targ->reflex_save(30))
    {
        tell_object(targ, "%^RESET%^%^MAGENTA%^You step out of the way just in time and "+me+
        " charges past you!%^RESET%^");
        
        tell_room(ETO, targ->QCN+"%^RESET%^%^MAGENTA%^ steps out of the way just in time and "+me+
        " charges past "+targ->QO+"!", targ);
        return;
    }
    tell_object(targ, me+"%^BOLD%^%^MAGENTA%^ SLAMS%^BOLD%^%^BLACK%^ into you, knocking you "+
    "%^BOLD%^%^RED%^FORCIBLY%^BOLD%^%^BLACK%^ to the ground!%^RESET%^");
    
    tell_room(ETO, me+"%^BOLD%^%^MAGENTA%^ SLAMS%^BOLD%^%^BLACK%^ into "+targ->QCN+", knocking "+targ->QO+
    "%^BOLD%^%^RED%^ FORCIBLY%^BOLD%^%^BLACK%^ to the ground!%^RESET%^", targ);
    
    targ->set_tripped(2, "%^BOLD%^%^MAGENTA%^You are still trying to get up!%^RESET%^");
    return;   
}

void init()
{
    if(!objectp(TO)) { return; }
    if(!objectp(TP)) { return; }
    
    ::init();
    if(TP->query_true_invis()) return;
    if(!userp(TP)) return;
    command("emoteat "+TPQN+ " turns and glares at $N");
    command("shatter "+TPQN); 
}