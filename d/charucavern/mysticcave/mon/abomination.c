#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"

#define ABOMDEED "%^BOLD%^%^RED%^D%^RESET%^%^ORANGE%^e%^BOLD%^%^RED%^f%^RESET%^%^ORANGE%^e%^BOLD%^%^RED%^a%^RESET%^%^ORANGE%^te"\
"%^BOLD%^%^RED%^d The Abomination Lurking in The Mystic Cave!%^RESET%^"

inherit WEAPONLESS;
int attacked, delay;

void create()
{
    ::create();
    set_name("mass of oozing flesh");

    set_id(({"mass", "ooze", "oozing flesh", "mass of oozing flesh", "saideccbossmob"}));

    set_short("%^RESET%^%^ORANGE%^mass of o%^BOLD%^o%^RESET%^%^ORANGE%^z%^BOLD%^"+
    "i%^RESET%^%^ORANGE%^ng fl%^BOLD%^e%^RESET%^%^ORANGE%^sh%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^This monstrous creature resembles a giant lump of "+
    "twisted flesh, stretched far too thin over layers of fat. It is almost six "+
    "feet thick and takes up perhaps twelve feet in diamater. It has several "+
    "bent useless appendages jutting out oddly from around a gaping "+
    "toothless mouth. The mouth is set in almost the dead center of its "+
    "large center mass. There are dozens of swollen, unblinking eyes "+
    "spread all over its body, each one is oozing with an %^BOLD%^%^GREEN%^"+
    "acidic goo%^RESET%^%^ORANGE%^ and stares off blankly. One larger "+
    "eye right above its mouth looks much more intelligent and "+
    "it darts back and forth crazily, as if constantly alert and expecting "+
    "visitors. This creature gives off a repugnant odor that makes "+
    "breathing in its presence quite a challenge. Whatever this thing "+
    "might have once been is lost and all that remains is a horrid "+
    "abomination.%^RESET%^");

    set_hd(22,2);
    set_hp(1500);
    set_max_hp(query_hp());
    set_body_type("ooze");
    set_damage(2,6);
    set_attacks_num(5);
    set_attack_limbs(({"mass"}));
    set_base_damage_type("bludgeoning");
    set_gender("neuter");
    set_race("ooze");
    set_new_exp(22, "boss");
    set_alignment(9);
    set_overall_ac(-10);
    set("aggressive", "aggression");

    set_stats("strength", 19);
    set_stats("intelligence", 1);
    set_stats("wisdom", 1);
    set_stats("constitution", 19);
    set_stats("dexterity", 12);
    set_stats("charisma", 6);

    set_property("full attacks", 1);
    set_property("no crit", 1);
    set_property("weapon resistance", 1);
    set_property("no steal", 1);
    set_property("no paralyze", 1);
    set_property("no tripped",1);
    set_property("magic", 1);
    set_property("no death", 1);
    set_property("no hold", 1);
    set_property("no bows", 1);
    set_mob_magic_resistance("average");


    set_func_chance(55);
    set_funcs(({"spit", "feed"}));

    set_resistance("acid", 2000);
    set_resistance("cold", -60);
    set_resistance("bludgeoning", 10);
    attacked = 0;
    delay = 3;
}

void reset_attacked()
{
    if(!objectp(TO)) return;
    attacked = 1;
}

void set_paralyzed(int time,string message){return;}
void set_tripped(int time, string messsage){return;}


void form_ooze()
{
    object mon;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    switch(random(3))
    {
        case 0:
            mon = new(CRMON+"arcane_ooze");
            break;
        case 1:
            mon = new(CRMON+"conflaguration_ooze");
            break;
        case 2:
            mon = new(CRMON+"summoning_ooze");
            break;
    }
    mon->set_moving(0);
    mon->remove_id("chsaidemob9x");
    tell_room(ETO, "%^BOLD%^%^GREEN%^The massive glob of slime bubbles and "+
    "gurgles as it forms "+mon->QCN+"!%^RESET%^");
    mon->move(ETO);
    return;
}

void spit(object vic)
{
    string tlim;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(vic)) return;

    tell_object(vic, TOQCN+"%^BOLD%^%^GREEN%^ spits a glob of "+
    "thick, acidic slime at you!%^RESET%^");

    tell_room(ETO, TOQCN+"%^BOLD%^%^GREEN%^ spits a glob of thick, "+
    "acidic spit slime at "+vic->QCN+"%^BOLD%^%^GREEN%^!%^RESET%^", vic);

    if(vic->reflex_save(25))
    {
        tell_object(vic, "%^BOLD%^%^WHITE%^You easily dodge the glob of "+
        "%^BOLD%^%^GREEN%^acidic slime%^BOLD%^%^WHITE%^ and it splats on "+
        "the floor of the cavern!%^RESET%^");

        tell_room(ETO, vic->QCN+"%^BOLD%^%^WHITE%^ easily dodges the glob of "+
        "%^BOLD%^%^GREEN%^acidic slime%^BOLD%^%^WHITE%^ and it splats on "+
        "the floor of the cavern!%^RESET%^", vic);
        if(!random(3)) call_out("form_ooze", 10);
        return;
    }
    tlim = vic->return_target_limb();

    tell_object(vic, "%^BOLD%^%^GREEN%^The acidic slime splats you in the "+tlim+
    "%^BOLD%^%^GREEN%^ and burns into your flesh!%^RESET%^");

    tell_room(ETO, "%^BOLD%^%^GREEN%^The acidic slime splats into "+vic->QCN+
    "%^BOLD%^%^GREEN%^'s "+tlim+" and burns into "+vic->QP+" flesh!%^RESET%^", vic);

    vic->cause_typed_damage(vic, tlim, roll_dice(20,6), "acid");
    
    if(tlim == "head")
    {
        tell_object(vic, "%^BOLD%^%^GREEN%^The acidic slime blinds you!%^RESET%^");
        vic->set_temporary_blinded(2, "%^BOLD%^%^GREEN%^Your eyes are burning from "+
        "the acidic slime!%^RESET%^");
    }
    return;
}

void aggression()
{
    command("speech gurgle");
    command("speak common");
    if(!objectp(TP)) return;
    if(TP->query_true_invis()) return;
    if(!attacked)
    {
        command("say shooouuullllldddd noooottttt beeeee hhhhheeeerrrrreeee");
        spit(TP);
        attacked = 1;
        command("kill "+TP->query_name());
        call_out("reset_attacked", 45);
        return;
    }
    command("kill "+TP->query_name());
    spit(TP);
    return;
}

void belch()
{
    object *vics;
    int x;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;

    tell_room(ETO, TOQCN+"%^BOLD%^%^RED%^ BELCHES%^BOLD%^%^GREEN%^ loudly and "+
    "the entire cavern around you shakes!%^RESET%^");
    vics = all_living(ETO);
    vics -= ({TO});
    for(x = 0;x < sizeof(vics);x++)
    {
        if(!objectp(vics[x])) continue;
        if(vics[x]->query_true_invis()) continue;
        if(vics[x]->reflex_save(22))
        {
            tell_object(vics[x], "%^BOLD%^%^RED%^You manage to keep your footing as the "+
            "shaking continues!%^RESET%^");
            continue;
        }
        tell_object(vics[x], "%^BOLD%^%^BLACK%^You fall to the floor of the chamber, uneven "+
        "to maintain your footing as the shaking continues!%^RESET%^");
        tell_room(ETO, vics[x]->QCN+"%^BOLD%^%^BLACK%^ falls to the floor, unable to maintain "+
        vics[x]->QP+" footing!%^RESET%^", vics[x]);
        vics[x]->set_paralyzed(20, "%^BOLD%^%^BLACK%^You're struggling to get back to your "+
        "feet!%^RESET%^");
        continue;
     }
     tell_room(ETO, "%^BOLD%^%^RED%^Finally the shaking subsides and the cavern remains "+
     "intact.... for now.....%^RESET%^");
     return;
}

void feed(object vic)
{
    object cor;
    int myheal;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(cor = present("corpse", ETO)))
    {
        spit(vic);
        return;
    }
    tell_room(ETO, "%^BOLD%^%^BLACK%^A mutated and %^BOLD%^%^GREEN%^festering%^BOLD%^%^BLACK%^"+
    " tongue jets out from "+TOQCN+"%^BOLD%^%^BLACK%^'s gaping mouth and sucks away much of "+
    "the remaining flesh and marrow from "+cor->query_name()+"%^BOLD%^%^BLACK!%^RESET%^");
    cor->decay();
    myheal += roll_dice(4, 20);
    if(objectp(cor))
    {
        cor->decay();
        myheal += roll_dice(4, 20);
    }
    if(objectp(cor))
    {
        cor->decay();
        myheal += roll_dice(4, 20);
    }
    TO->heal(myheal);
    belch();
    return;
}

void add_bonus(object ob)
{
    if(!objectp(ob)) return;
    switch(random(10))
    {
        case 0:
            ob->set_item_bonus(!random(2) ? "bonus_spell_slot_5" : "bonus_spell_slot_6", 1);
            break;
        case 1:
            ob->set_item_bonus(!random(2) ? "strength" : "dexterity", 2);
            break;
        case 2:
            ob->set_item_bonus(!random(2) ? "perception" : "dungeoneering", 4);
            break;
        case 3:
            ob->set_item_bonus(!random(2) ? "piercing resistance" : "slashing resistance", 5);
            break;
        case 4:
            ob->set_item_bonus(!random(2) ? "bludgeoning resistance" : "acid resistance", 8);
            break;
        case 5:
            ob->set_item_bonus(!random(2) ? "fire resistance" : "cold resistance", 8);
            break;
        case 6:
            ob->set_item_bonus(!random(2) ? "constitution" : "charisma", 2);
            break;
        case 7:
            ob->set_item_bonus(!random(2) ? "wisdom" : "intelligence", 2);
            break;
        case 8:
            ob->set_item_bonus(!random(2) ? "attack bonus" : "damage bonus", 2);
            break;
        case 9:
            ob->set_item_bonus(!random(2) ? "magic resistance" : "spell penetration", 1);
            break;
    }
    ob->remove_property("enchantment");
    ob->set_property("enchantment", 3);
    return;
}

void die(object ob)
{
    string RAN = "/d/common/obj/rand/", myItem, *tmpquests;
    object myOb, *MyKillers;
    int y, Amt;
    string *obs = ({"cloak", "mage_robes", "r_helm", "r_shoes", "rand_leath_head", "randrobe", "s_curiass", "steelshield", "womendress"});
    //pick some items, add some bonuses to each
    y = 2 + random(3);
    TO->set_property("dying", 1);
    while(y--)
    {
        myItem = obs[random(sizeof(obs))];
        obs -= ({myItem});
        myOb = new(RAN+myItem);
        if(!objectp(myOb)) continue;
        add_bonus(myOb);
        if(!random(5)) add_bonus(myOb);
        myOb->move(TO);
        continue;
    }
    MyKillers = TO->query_attackers();
    MyKillers = filter_array(TO->query_attackers(), "is_player", FILTERS_D);
    for(Amt = 0;Amt < sizeof(MyKillers);Amt++)
    {
        if(!objectp(MyKillers[Amt])) continue;
        if(environment(MyKillers[Amt]) != ETO) continue;
        tmpquests = MyKillers[Amt]->query_mini_quests();
        if(member_array(ABOMDEED, tmpquests) != -1) continue;
        MyKillers[Amt]->set_mini_quest(ABOMDEED, 1000000, ABOMDEED);
            
        tell_object(MyKillers[Amt], "%^BOLD%^%^CYAN%^You have destroyed the abomination that "+
        "plagued the charu caverns!%^RESET%^");
    }
    
    
    if(objectp(ETO))
    {
        tell_room(ETO, "%^BOLD%^%^RED%^You notice something inside the mass of %^BOLD%^%^YELLOW%^oozing flesh"+
        "%^BOLD%^%^RED%^ as the abomination collapses into a heap!%^RESET%^");
    }
    SAVE_D->remove_value("charu_cavern_boss_delay");
    SAVE_D->set_value("charu_cavern_boss_delay", time() + 14400);
    SAVE_D->remove_array("charu_cavern_boss_location");
    return ::die(ob);
}

void heart_beat()
{
    string me;
    object *myEnemies;
    int x;
    if(!objectp(TO)) return;
    ::heart_beat();
    if(!objectp(TO)) return;
    if(TO->query_property("dying")) return;
    if(delay > 0)
    {
        delay--;
        return;
    }
    if(delay <= 0) delay = 3;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
	
    myEnemies = all_living(ETO);
    me = TO->query_short();
    for(x = 0; x < sizeof(myEnemies);x++)
    {
        if(!objectp(myEnemies[x])) continue;
        if(!myEnemies[x]->id("chsaideoozefood")) continue;
        tell_room(ETO, me +"%^BOLD%^%^BLACK%^ encompasses "+myEnemies[x]->query_short() +
        " and quickly devours "+myEnemies[x]->QO+" adding to its own mass!%^RESET%^");
        myEnemies[x]->move("/d/shadowgate/void");
        myEnemies[x]->remove();
        set_max_hp(query_max_hp() + 10);
        set_hp(query_hp() + 10);
        break;
    }
    return;
}

