#include <std.h>
#include <daemons.h>

inherit MONSTER;

void do_setup(object ob);

void create()
{
    ::create();
    set_id(({"monster999"}));
    set_thief_skill("move silently",95);
    set_thief_skill("hide in shadows",95);
}

void do_setup(object ob)
{
    object *inv,obj;
    string *classes,*ids,file;
    int i,caster=0,num=0;

    if(!objectp(ob)) { return; }

    classes = (string *)ob->query_classes();
    inv     = all_inventory(ob);
    
    set_name(""+ob->QCN+"'s Shadow");
    set_id(({ "monster999","monster","quest monster","quest","shadow",""+lower_case(ob->QCN)+"'s shadow"}));
    set_short("%^BOLD%^%^BLACK%^"+ob->QCN+"'s Shadow");
    set_long("%^BOLD%^%^BLACK%^"+ob->QCN+"'s Shadow "+FILTERS_D->filter_colors(ob->query_description())+"");
    set_race(""+ob->query_race()+"");
    set_body_type(""+ob->query_race()+"");
    set_size((int)ob->query_size());
    set_property("full attacks",1);

    for(i=0;i<sizeof(classes);i++)
    {
        file = "/std/class/"+classes[i]+".c";
        if(!file_exists(file)) { continue; }
        caster += (int)file->caster_class();        
        set_class(classes[i]);
        set_mlevel(classes[i],(int)ob->query_base_class_level(classes[i]));
        set_guild_level(classes[i],(int)ob->query_class_level(classes[i]));
        // This might need real fixing if it's still in use!
        add_search_path("/cmds/"+classes[i]+"");
    }

    set_max_hp((int)ob->query_max_hp() * 3);
    set_hp(query_max_hp());
    
    set_stats("strength",(int)ob->query_stats("strength"));
    set_stats("dexterity",(int)ob->query_stats("dexterity"));
    set_stats("constitution",(int)ob->query_stats("constitution"));
    set_stats("intelligence",(int)ob->query_stats("intelligence"));
    set_stats("wisdom",(int)ob->query_stats("wisdom"));
    set_stats("charisma",(int)ob->query_stats("charisma"));

    for(i=0;i<sizeof(inv);i++)
    {
        if(!objectp(inv[i])) { continue; }
        if(inv[i]->is_container()) { continue; }
        if(inv[i]->id("kit")) { continue; }
        obj = new(base_name(inv[i]));
        obj->move(TO);
        obj->set_property("monsterweapon",1);
        ids = (string *)obj->query_id();
        if(obj->is_armor()) { TO->force_me("wear "+ids[0]+""); }
        if(obj->is_weapon() && !num) { TO->force_me("wield "+ids[0]+""); num = 1; }
    }

    if(caster)
    {
        set_spells(({"fireball",
                     "scorcher",
                     "magic missile",
                     "flame strike",
                     "call lightning",
                     "mass cause critical wounds",
                     "ultrablast",
                     "swarm of crystals",
                     "mind thrust"}));

        set_spell_chance(40);
    }
    set_property("is_setup",1);
    set_property("add kits",20);
    return;
}   

void kill_player(object ob)
{
    if(!objectp(ob)) { return; }

    TO->force_me("stab "+ob->query_true_name()+"");
    TO->force_me("rush "+ob->query_true_name()+"");
    TO->force_me("kill "+ob->query_true_name()+"");
    return;
}

void heart_beat()
{
    object *attackers;
    int i;

    ::heart_beat();

    if(!objectp(TO)) { return; }

    attackers = (object *)TO->query_attackers();

    if(sizeof(attackers) && !TO->query_property("engaged"))
    {
        TO->force_me("scramble");
        TO->force_me("parry");
        TO->force_me("whirl");
        for(i=0;i<sizeof(attackers);i++)
        {
            if(!objectp(attackers[i])) { continue; }
            TO->force_me("rush "+attackers[i]->query_true_name()+"");
        }
        return;
    }
    if(!sizeof(attackers)) { TO->remove_property("engaged"); }
    return;
}

void init()
{  
    if(!objectp(TO)) { return; }
    if(interactive(TP) && !avatarp(TP))
    {
        if(!query_property("is_setup")) { do_setup(TP); }
        TO->force_me("say Well, my friend, I see you have made it this far in your quest.");
        TO->force_me("laugh");
        TO->force_me("say I am sure you have made your way preying upon the weak -- it is "
            "always the case with those such as yourself.");
        TO->force_me("shrug");
        TO->force_me("say Well, now we shall see how you fare against an opponent of similar "
            "ability to your own!");
        TO->force_me("grin");
        call_out("kill_player",10,TP);
    }
    ::init();
}

void die(object ob)
{
    //if(!objectp(ob)) { return; }
    TO->force_me("say You have indeed proven yourself worthy to advance.");
    TO->force_me("say One day we will meet again.");
    TO->move("/d/shadowgate/void"); 
    TO->remove();
    return;
}

