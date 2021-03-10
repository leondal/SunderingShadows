#include <std.h>
#include <daemons.h>
#include "../keep.h"

inherit MONSTER;

int i,flag, fb;
object ob;

void spells() 
{
    if(objectp(ETO)) 
    {
        if(flag == 0) 
        {
            flag = 1;
            new("/cmds/spells/s/_stoneskin")->use_spell(TO,TO,14,7,"mage");
            if(present("lord blacktongue",ETO)) 
            {
                new("/cmds/spells/s/_stoneskin")->use_spell(TO,"lord blacktongue",14,7,"mage");
            }
        }
    }
}

void create()
{
    ::create();
    set_name("A half drow");
    set_id(({"half drow","siere","mage","wizard"}));
    set_short("%^BOLD%^%^BLACK%^A half drow%^RESET%^");
    set_long("%^CYAN%^This female %^BOLD%^%^BLACK%^creature%^RESET%^%^CYAN%^ stands a little "+
    "under five feet tall.  She is petite and her skin is a %^BOLD%^%^BLACK%^dark obsidian"+
    "%^RESET%^%^CYAN%^.  She has high cheek bones, slightly pointed ears, and her face is "+
    "amazingly attractive by most standards.  She has short %^BOLD%^%^WHITE%^silver%^CYAN%^ "+
    "hair which is kept loose and intense %^RED%^red%^CYAN%^ eyes.  She carries no "+
    "visible weapons and is garbed only in a thin %^BOLD%^%^WHITE%^silver%^CYAN%^ dress.  "+
    "She wears a %^RESET%^%^WHITE%^bone ring%^CYAN%^, which is strikingly out of place.  An "+
    "uneasy feeling stirs within you as you behold her.%^RESET%^");
    set_body_type("human");
    set_gender("female");
    set_race("half-drow");
    set_class("mage");
    add_search_path("/cmds/wizard");
    set_alignment(9);
    set_mlevel("mage",24);
    set_guild_level("mage",24);
    set_mob_magic_resistance("average");
    set_overall_ac(-8);
    set_hp(787 + random(50));
    set_new_exp(20, "very high");
    add_money("gold",500 + random(300));
    set_stats("strength",12);
    set_stats("intelligence",22);
    set_stats("wisdom",16);
    set_stats("constitution",14);
    set_stats("dexterity",20);
    set_stats("charisma",8);
    set_spell_chance(50);
    set_spells(({"magic missile","lightning bolt", "fire ball",
    "lower resistance"}));
    set("aggressive","aggression");
    set_property("full attacks",1);
    set_property("swarm",1);
    ob = new(KEEPO + "insigniaring");
    ob->set_id(({"ring","bone ring","siere's ring"}));
    ob->set_long("%^BOLD%^%^WHITE%^This ring is made from what appears to be a bone fragment.  "+
    "It is remarkably simple with two words etched into the underside of the band.%^RESET%^");
    ob->delete("read");
    ob->delete("language list");
    ob->delete("language");
    ob->set_read("Siere Domsdrail");
    if(random(2) == 1) {
        ob->set_language("drow");
    }
    else {
        ob->set_language("common");
    }
    ob->move(TO);
    command("wear bone ring");
    new(KEEPO + "silverdress")->move(TO);
    command("wear dress");
    call_out("spells",1);
    MOB_TR_D->do_treasure(TO,"C");
    add_money("gold",random(500) + 500);
    set_funcs(({"heal_self"}));
    set_func_chance(50);
}

void heal_self() 
{
    if(!objectp(TO)) return;
  
    tell_room(ETO,"%^BOLD%^%^YELLOW%^The half drow female %^RED%^cackles%^BOLD%^%^YELLOW%^ "+
    "and her entire body is briefly outlined in a brilliant %^BLUE%^blue%^BOLD%^%^YELLOW%^!");
    switch(random(3)) 
    {
        case 0:
            TO->set_property("magic resistance",2);
            break;
        case 1:
            TO->heal(20 + random(21));
            break;
        case 2:
            TO->set_property("magic resistance",1);
            TO->heal(35 + random(11));
            break;
    }
}

void reset_intro() 
{
    if(!objectp(TO)) return;
    fb = 0;
}

int filter_targets(object ob) 
{
    int x;
    if(objectp(ob)) return 0;
    if(ob == TO) return 0;
    if(ob->query_true_invis()) return 0;
    if(ob->id("werewolf")) return 0;
    return 1;
}

void aggression()
{
    object targ, *alive;
    
    int x;
    if(random(2) == 1) 
    {
        command("speak common");
    }

    else 
    {
        command("speak drow");
    }
       
    if(!fb) 
    {
        call_out("reset_intro",60);
        alive = filter_array(all_living(ETO), "filter_targets", TO);
        if(!sizeof(alive)) return;
        targ = alive[random(sizeof(alive))];   
                     
        command("speech cackle");
        command("say None shall oppose Lord BlackTongue and live!");
        new("/cmds/spells/f/_fireball")->use_spell(TO,targ,14,10,"mage");
        fb = 1;
        new("/cmds/spells/b/_blink")->use_spell(TO,TO,20,10,"mage");
        return;			
    }
    if(objectp(TP) && !TP->query_invis()) 
    {
        command("kill "+TP->query_name());
    }
    return;
}


