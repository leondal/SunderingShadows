#include <std.h>
#include "../keep.h"

inherit MONSTER;

void create()
{
    object ob;
    string wdesc;
    ::create();
    set_name("An ogre");
    set_id(({"ogre","telair","general","massive ogre","general telair"}));
    set_short("%^YELLOW%^A massive ogre%^RESET%^");
    set_gender("male");
    set_race("ogre");
    set_hd(28,1);
    add_search_path("/cmds/fighter");
    set_alignment(9);
    //set_property("no rush",1);
    set_overall_ac(-8);
    set_hp(777 + random(41));
    set_new_exp(25, "very high");
    add_money("gold",3500 + random(3000));
    set_stats("strength",22);
    set_stats("intelligence",6);
    set_stats("wisdom",8);
    set_stats("constitution",20);
    set_stats("dexterity",8);
    set_stats("charisma",8);
    set("aggressive","aggression");
    set_property("full attacks",1);
    set_property("swarm",1);
    if(!random(3) || !random(3)) 
    {
        ob = new(KEEPO + "oakclub");
        ob->move(TO);
        command("wield club");
        ob = new(KEEPO + "oakclub");
        ob->move(TO);
        command("wield club");
        wdesc = "%^BOLD%^%^GREEN%^To make things more pleasant it wields a "+
        "%^BOLD%^%^BLACK%^blackened club%^BOLD%^%^GREEN%^ in each hand";
    }
    else 
    {
        new(KEEPO + "diamondhalberd")->move(TO);
        command("wield halberd");
        wdesc = "%^BOLD%^%^GREEN%^To make matters worse, it carries a "+
        "%^CYAN%^massive, diamond halberd%^BOLD%^%^GREEN%^";
    }
    set_long("%^BOLD%^%^GREEN%^This hideous creature stands a towering ten feet high.  "+
    "Its thick skin is a %^YELLOW%^dull yellow%^BOLD%^%^GREEN%^ and covered with dark, "+
    "enormous, %^YELLOW%^warts%^BOLD%^%^GREEN%^.  Its eyes are a dark, dull brown and "+
    "its hair is long, unkept, and matted together with all types of %^YELLOW%^filth"+
    "%^BOLD%^%^GREEN%^.  A strong nauseating odor is emitted from this disgusting "+
    "creature.  " +wdesc+ "%^RESET%^.");
    ob = new(KEEPO + "insigniaring");
    ob->set_long("%^BOLD%^%^WHITE%^This ring is made from what appears to be a bone fragment.  "+
    "It is remarkably simple with two words etched into the underside of the band.%^RESET%^");
    ob->delete("read");
    ob->delete("language list");
    ob->delete("language");
    ob->set_id(({"ring","bone ring","telair's ring"}));
    ob->set_language("giant");
    ob->set_read("General Telair");
    ob->move(TO);
    command("wear bone ring");
    ob = new(KEEPO + "blacktonguejailkey");
    ob->move(TO);
    MOB_TR_D->do_treasure(TO,"C");
    set_monster_feats(({
        "parry",
        "powerattack",
        "shatter",
        "sunder",
        "rush"
    }));
    set_funcs(({"rushit","flash"}));
    set_func_chance(30);   	
    //add_attack_bonus(6);
}

void flash() 
{
    if(!objectp(TP)) return;
    command("flash "+TPQN);
    command("flash "+TPQN);
    command("flash "+TPQN);
    command("flash "+TPQN);
}

void aggression(object targ)
{		
    int what;
    if(!TP->query_invis()) 
    {
        command("speak giant");
        command("speech growl");
        command("say me smash you now!");
        if(!objectp(TP) || !interactive(TP)) return;
    //    TO->add_attack_bonus(6);
        command("rush "+TPQN);
        command("parry");
      //  TO->add_attack_bonus(-6);
    }
}

void rushit(object targ) 
{
    TO->force_me("rush "+targ->query_name());
}
