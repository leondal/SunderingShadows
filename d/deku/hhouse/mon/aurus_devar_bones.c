#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
#define NUMBERS ({ "zero", "one", "two", "three", "four", "five", "six","seven", "eight", "nine", "ten" })

inherit MONSTER;
mapping AttackerInfo;
object *myBound, myMon;
string *myKnownSpells, *myKnownProtectSpells;
string *MyTreasure = ({"boots_of_combat_reflexes", "wavering", "shroud_of_the_impaler",
"redemption", "blasphemy", "azloths_blessing", "heart_of_talos", "lathanders_dawn",
"witheringmask", "portable_door"});

string MYQUEST = "%^BOLD%^%^BLACK%^Achieved:%^BOLD%^%^WHITE%^ "+
                "B%^BOLD%^%^BLACK%^a%^BOLD%^%^WHITE%^n%^BOLD%^%^BLACK%^i%^BOLD%^%^WHITE%^s%^BOLD%^%^BLACK%^"+
                "h%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^d The Bones of %^BOLD%^%^WHITE%^Ao'rus "+
                "Devar%^BOLD%^%^RED%^";

string *MyArmor = ({"azloths_blessing", "heart_of_talos", "lathanders_dawn", "witheringmask", "boots_of_combat_reflexes", "shroud_of_the_impaler"});
string *MyWeapon = ({"wavering", "redemption", "blasphemy"});
string *MyMisc = ({"portable_door"});

int myPhase, myCount, myChance;

void create()
{
    object ob;
    ::create();
    set_name("skeleton of aurus devar");
    set_id(({"devar", "skeleton of aurus devar", "aurus", "skeleton"}));
    set_gender("neuter");
    set_race("skeleton");

    set_short("%^BOLD%^%^RED%^The %^BOLD%^%^WHITE%^skeleton%^BOLD%^%^RED%^"+
    " of %^BOLD%^%^WHITE%^Au'rus Devar%^BOLD%^%^RED%^");

    set_long("%^BOLD%^%^RED%^This massive skeletal creature towers close to "+
    "ten feet tall. It has been constructed entirely from %^RESET%^%^RED%^dark red"+
    "%^BOLD%^%^RED%^ bones that are covered with complicated %^BOLD%^%^CYAN%^runes "+
    "%^BOLD%^%^RED%^of binding, which are quickly fading. %^BOLD%^%^WHITE%^P"+
    "%^BOLD%^%^YELLOW%^u%^BOLD%^%^WHITE%^l%^BOLD%^%^YELLOW%^s%^BOLD%^%^WHITE%^"+
    "a%^BOLD%^%^YELLOW%^t%^BOLD%^%^WHITE%^i%^BOLD%^%^YELLOW%^n%^BOLD%^%^WHITE%^g "+
    "%^BOLD%^%^BLACK%^dark orbs%^BOLD%^%^RED%^ are set deeply into the eye "+
    "sockets of this creature, they seeth with an unfathomable %^BOLD%^%^YELLOW%^"+
    "RAGE%^BOLD%^%^RED%^. The arms and legs of this creature are composed of "+
    "much larger, thicker bones as if the person who assembled it used "+
    "many different species. A gaping hole in the center of this creatures "+
    "chest spills forth a %^RESET%^%^GREEN%^dark acidic ooze%^BOLD%^%^RED%^ "+
    "constantly. An aura of %^BOLD%^%^BLUE%^power%^BOLD%^%^RED%^ radiates from "+
    "this creature and you assume the aura is what is causing the %^BOLD%^%^CYAN%^"+
    "runes%^BOLD%^%^RED%^ to fade.%^RESET%^");

    set_body_type("human");
    set_hd(50,2);
    set_alignment(9);
    set_size(4);
    set_stats("strength",20);
    set_stats("constitution",17);
    set_stats("wisdom",15);
    set_stats("intelligence",20);
    set_stats("dexterity",15);
    set_stats("charisma",15);

    set_property("no disarm", 1);
    set_property("no hold", 1);
    set_property("no death", 1);
    set_property("no paralyze", 1);
    set_property("full attacks", 1);
    set_property("no crit", 1);
    set_property("no tripped", 1);
    set("aggressive",2);
    set_overall_ac(-22);

    set_mob_magic_resistance("average");
    set_property("weapon resistance", 3);

    ob = new("/d/common/obj/weapon/large_battle_axe");
    ob->set_property("enchantment", 5);
    ob->move(TO);
    command("wield axe");

    ob = new("/d/common/obj/weapon/large_battle_axe");
    ob->set_property("enchantment", 5);
    ob->move(TO);
    command("wield axe");

    set_hp(6000);

    set_new_exp(32, "boss");
    set_funcs(({"my_spell_attack"}));
    set_func_chance(45);
    set_monster_feats(({
        "rush",
        "perfect caster",
    }));

    myBound = ({});
    myPhase = 1;
    myCount = 1;
    myChance = 3;
    AttackerInfo = ([]);
    myKnownSpells = (({"/cmds/spells/c/_cone_of_cold", "/cmds/spells/f/_fireball", "/cmds/spells/l/_lightning_bolt"}));
    myKnownProtectSpells = (({"/cmds/spells/b/_blink", "/cmds/spells/s/_stoneskin"}));
}

int add_bound(object ob)
{
    if(!objectp(ob)) return 0;
    if(!pointerp(myBound)) myBound = ({});
    if(member_array(ob, myBound) != -1) return 0;
    myBound += ({ob});
    return 1;
}

void awoken(object targ)
{
    string me;
    set("aggressive", 30);
    if(!objectp(targ)) return;
    me = TO->query_short();
    tell_room(ETO, me +"%^BOLD%^%^RED%^ emits a gutteral roar before speaking:%^RESET%^ "+targ->QCN+
    " HOW DARE YOU AWAKEN ME???? and where is ARAG DYNE??? I HAVE A DEBT TO SETTLE WITH HIM after I "+
    "am through destroying YOU!!%^RESET%^");
    TO->force_me("kill "+targ->query_name());
    MONSTER_FEAT_D->execute_monster_feat(TO, targ);
    return;
}

int remove_bound(object ob)
{
    if(!objectp(ob)) return 0;
    if(!pointerp(myBound))
    {
        myBound = ({});
        return 1;
    }
    if(member_array(ob, myBound) == -1) return 0;
    myBound -= ({ob});
    return 1;
}


varargs void bind_them(int flag)
{
    object *myEnemies, myTarg, myChain;
    string me;
    int x;
    myEnemies = TO->query_attackers();
    me = TO->query_short();
    myEnemies -= myBound;
    if(!sizeof(myEnemies)) return;
    if(!flag)
    {
        myTarg = myEnemies[random(sizeof(myEnemies))];
        tell_room(ETO, me + "%^BOLD%^%^BLACK%^ chants loudly for a brief moment, "+
        "conjuring up a %^BOLD%^%^CYAN%^chain of binding%^BOLD%^%^BLACK%^!%^RESET%^");
        myChain = new(HHOB+"binding_chain");
        myChain->set_controller(TO);
        myTarg->set_hp((int)myTarg->query_hp() / 2);
        if(objectp(myTarg)) tell_object(myTarg, "%^RESET%^HP: %^BOLD%^%^GREEN%^"+(int)myTarg->query_hp()+"%^RESET%^%^WHITE%^/%^RESET%^%^GREEN%^"+(int)myTarg->query_max_hp());
        myChain->bind(myTarg);
        myChain->move(ETO);
        myChain->bind_notify();
    }
    else
    {
        tell_room(ETO, me + "%^BOLD%^%^BLACK%^ chants loudly for a brief moment, "+
        "conjuring up a %^BOLD%^%^CYAN%^chains of binding%^BOLD%^%^BLACK%^!%^RESET%^");
        for(x = 0; x < sizeof(myEnemies);x++)
        {
            if(!objectp(myEnemies[x])) continue;
            myTarg = myEnemies[x];
            myChain = new(HHOB+"binding_chain");
            myChain->set_controller(TO);
            myTarg->set_hp((int)myTarg->query_hp() / 2);
            myChain->bind(myTarg);
            myChain->move(ETO);
            myChain->bind_notify();
        }
    }
}


void assign_attacks(int step)
{
    object *liv;
    int x;
    if(!objectp(TO)) return;
    switch(step)
    {
        case 0:
            if(!mapp(AttackerInfo)) AttackerInfo = ([]);
            liv = all_living(ETO);
            for(x = 0;x < sizeof(liv);x++)
            {
                AttackerInfo += ([ liv[x] : liv[x]->query_attackers() ]);
                continue;
            }
            liv->cease_all_attacks();
            tell_room(ETO, "%^BOLD%^%^BLUE%^All combat ceases as "+TO->query_short()+
            "%^BOLD%^%^BLUE%^ mumbles a quick incantation!%^RESET%^");
            break;
        case 1:
            if(!mapp(AttackerInfo)) return;
            liv = keys(AttackerInfo);
            for(x = 0;x < sizeof(liv);x++)
            {
                if(!objectp(liv[x])) continue;
                liv[x]->set_attackers(AttackerInfo[liv[x]]);
                continue;
            }
            if(objectp(myMon)) myMon->set_attackers(TO->query_attackers());
            break;
    }
    return;
}

void adjust_me()
{
    int flag;
    object ob;
    string me;
    if(!objectp(TO)) return;

    if(myPhase != 3)
    {
        if(objectp(myMon))
        {
            myMon->move("/d/shadowgate/void");
            myMon->remove();
        }
    }
    myPhase++;
    assign_attacks(0);
    me = TO->query_short();
    switch(myPhase)
    {
        case 1:

            myChance = 15;
            set_funcs(({"my_spell_attack"}));
            set_func_chance(35);
            myKnownSpells = (({"/cmds/spells/c/_cone_of_cold", "/cmds/spells/f/_fireball", "/cmds/spells/l/_lightning_bolt"}));
            myKnownProtectSpells = (({"/cmds/spells/b/_blink", "/cmds/spells/s/_stoneskin"}));
            while(objectp(ob = present("oblivion", TO)))
            {
                ob->remove();
                flag = 1;
            }
            if(flag)
            {
                ob = new("/d/common/obj/weapon/large_battle_axe");
                ob->set_property("enchantment", 4);
                ob->move(TO);
                command("wield axe");

                ob = new("/d/common/obj/weapon/large_battle_axe");
                ob->set_property("enchantment", 5);
                ob->move(TO);
                command("wield axe");
            }
            TO->set_hp(TO->query_max_hp());
            bind_them(1);
            break;

        case 2:

            myChance = 10;
            while(objectp(ob = present("axe", TO)))
            {
                ob->remove();
                flag = 1;
            }
            myKnownSpells = (({"/cmds/spells/m/_meteor_swarm", "/cmds/spells/c/_cone_of_cold", "/cmds/spells/f/_fireball",
            "/cmds/spells/l/_lightning_bolt", "/cmds/spells/f/_flame_strike"}));

            tell_room(ETO, me +"%^BOLD%^%^CYAN%^ whispers a soft incantation and "+
            "conjures two gleaming black battle axes!%^RESET%^");

            ob = new(HHOB+"oblivion");
            ob->move(TO);
            command("wield axe");

            ob = new(HHOB+"oblivion");
            ob->set_property("monsterweapon", 1);
            ob->move(TO);
            command("wield axe");

            command("speech roar");

            command("say you COULDN'T possibly believe it would be this easy? "+
            "Now, I'm afraid, you MUST die!%^RESET%^");

            tell_room(ETO, me +"%^BOLD%^%^RED%^ groans then roars loudly and you "+
            "watch in %^BOLD%^%^BLACK%^HORROR%^BOLD%^%^RED%^ as its bones "+
            "mend themselves!%^RESET%^");
			bind_them(1);
            TO->set_hp(TO->query_max_hp());
            set_funcs(({"construct", "my_spell_attack", "myshadow"}));
            set_func_chance(50);
            break;

        case 3:

            myChance = 5;
            tell_room(ETO, me +"%^BOLD%^%^RED%^ whispers a quick deep incantation "+
            "and a portal %^BOLD%^%^CYAN%^opens%^BOLD%^%^RED%^ high above you!%^RESET%^");

            tell_room(ETO, me +"%^BOLD%^%^RED%^ groans then roars loudly and you "+
            "watch in %^BOLD%^%^BLACK%^HORROR%^BOLD%^%^RED%^ as its bones "+
            "mend themselves!%^RESET%^");

            TO->set_hp(TO->query_max_hp());

            command("speech roar");

            command("say ARAG DYNE, I SUMMON YOU!!!! YOU WILL SERVE ME UNTIL YOUR "+
            "DEATH!");

            myKnownSpells = (({"/cmds/spells/m/_meteor_swarm", "/cmds/spells/c/_cone_of_cold", "/cmds/spells/f/_fireball",
            "/cmds/spells/l/_lightning_bolt", "/cmds/spells/f/_flame_strike", "/cmds/spells/p/_prismatic_spray"}));

            myKnownProtectSpells = (({"/cmds/spells/b/_blink", "/cmds/spells/s/_stoneskin", "/cmds/spells/t/_timeless_body"}));
            bind_them(1);
            myMon = new(HHMON+"arag_dyne");
            tell_room(ETO, myMon->query_short() + "%^BOLD%^%^BLUE%^ is tossed "+
            "through the portal before it %^BOLD%^%^CYAN%^blinks%^BOLD%^%^BLUE%^ "+
            "out of existence!%^RESET%^");
            myMon->set_property("minion", TO);
            TO->set_property("minion", myMon);
            myMon->delete("aggressive");
            myMon->move(ETO);
			//set_funcs(({"construct", "myshadow", "obliterate", "my_spell_attack"}));
            set_func_chance(75);
            TO->add_protector(myMon);
            myMon->make_undead();
            break;
	}
    assign_attacks(1);
    return;
}

int overpowered_enemies(object enemy)
{
    return 0;
}

void total_annilihation(object targ)
{
    if(!objectp(TO) || !objectp(ETO) || !objectp(targ)) return;

    tell_room(ETO, TO->query_short()+" %^RESET%^%^RED%^growls loudly as he speaks:%^RESET%^ "+
    "It has been far too long since I have seen one of your prowess... "+targ->QCN+". "+
    "I look forward to absorbing your %^BOLD%^%^YELLOW%^ESS%^BOLD%^%^GREEN%^E%^BOLD%^%^YELLOW%^"+
    "NCE%^RESET%^!");

    TO->add_hp(targ->query_hp() / 2);
    tell_object(targ, "%^BOLD%^%^BLACK%^You feel a strange sensation almost overwhelm you.....%^RESET%^");
    tell_object(targ, "%^BOLD%^%^RED%^A pulsing sound echoes around you, chaotically!%^RESET%^");
    tell_object(targ, "%^BOLD%^%^WHITE%^You fall to your knees as your mind seizes up!%^RESET%^");

    tell_room(ETO, targ->QCN+"%^BOLD%^%^RED%^ falls to "+targ->QP+" knees, "+targ->QP+" mouth "+
    "gaping wide in agony!%^RESET%^", targ);

    targ->set_paralyzed(25, "%^BOLD%^%^WHITE%^You are unable to control your body!%^RESET%^");

    tell_object(targ, "%^CYAN%^"+TO->query_short()+"%^RESET%^%^%^CYAN%^ whispers to you:%^RESET%^ "+
    "do not fight it... we shall be one soon!%^RESET%^");

    tell_room(ETO, TO->query_short()+"%^RESET%^%^CYAN%^ whispers something to "+targ->QCN+"%^RESET%^%^CYAN%^.%^RESET%^", targ);

    targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(60,30), "divine");
    targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(60,30), "electricity");
    targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(60,30), "cold");
    return;
}

void heart_beat()
{
    string me;
    object *myEnemies, myTarg, myChain, *opEnemies;
    if(!objectp(TO)) return;
    if(TO->query("is_dying")) return;
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;

    myEnemies = TO->query_attackers();
    me = TO->query_short();
    opEnemies = filter_array(myEnemies, "overpowered_enemies", TO);
    if(TO->query("rapid_healing"))
    {
        TO->add_hp(roll_dice(40,40));
    }

    if((int)TO->query_hp() < ((int)TO->query_max_hp() / 5))
    {
        if(myPhase < 3)
        {
            adjust_me();
            return;
        }
    }

    if(!random(myChance) && (int)TO->query_hp() < (int)TO->query_max_hp())
    {
        tell_room(ETO, me + "%^BOLD%^%^RED%^ completes a deep incantation in an "+
        "ancient language, restoring some of its life!%^RESET%^");
        TO->heal(150 + roll_dice(12,12));
    }

    if(!sizeof(myEnemies))
    {
        myCount++;
        if(myCount > 1200)
        {
            myPhase = 1;
            adjust_me();
            myCount = 0;
            TO->delete("rapid_healing");
        }
        return;
    }
    //people higher level than the boss was made for



    if(!random(myChance))
    {
        tell_room(ETO,me + "%^BOLD%^%^BLACK%^ whispers an %^BOLD%^%^CYAN%^incantation"+
        "%^BOLD%^%^BLACK%^ quickly in an unknown language!%^RESET%^");
        ETO->head_damage(myEnemies[random(sizeof(myEnemies))], 3 + random(2));
    }


    if(!random(myChance))
    {
        bind_them(0);
    }
    return;
}


void die(object ob)
{
    string me, tmp, *tmpquests;
    int Amt, flag;
    object MyOb, *MyKillers;
    if(myPhase >= 3)
    {
        TO->set("is_dying");
        me = TO->query_short();
        tell_room(ETO, me +"%^BOLD%^%^BLACK%^ finally collapses, his bones broken and "+
        "shattered... you notice several items laying amongst them!%^RESET%^");

        tell_room(ETO, "%^BOLD%^%^CYAN%^A quiet voice whispers:%^RESET%^ This is not over... I have only "+
        "began in your world!%^RESET%^");

        MyKillers = TO->query_attackers();
        MyKillers = filter_array(TO->query_attackers(), "is_player", FILTERS_D);
        //tell_room(ETO, "MyKillers = "+identify(MyKillers));
        if(!sizeof(MyKillers)) Amt = 3;
        else Amt = sizeof(MyKillers) * 3;
        while(Amt--)
        {
            if(!flag)
            {
                switch(random(4))
                {
                    case 0: case 2:
                        tmp = MyArmor[random(sizeof(MyArmor))];
                        break;
                    case 1:
                        tmp = MyMisc[random(sizeof(MyMisc))];
                        flag = 1;
                        break;
                    case 3:
                        tmp = MyWeapon[random(sizeof(MyWeapon))];
                        break;
                }
            }
            else
            {
                switch(random(4))
                {
                    case 0: case 2:
                        tmp = MyArmor[random(sizeof(MyArmor))];
                        break;
                    case 1: case 3:
                        tmp = MyWeapon[random(sizeof(MyWeapon))];
                        break;
                }
            }
            //tmp = MyTreasure[random(sizeof(MyTreasure))];
            MyOb = new(HHOB+tmp);
            MyOb->move(TO);
        }

        for(Amt = 0;Amt < sizeof(MyKillers);Amt++)
        {
            if(!objectp(MyKillers[Amt])) continue;
            if(environment(MyKillers[Amt]) != ETO) continue;
            tmpquests = (string *)MyKillers[Amt]->query_mini_quests();
            if(member_array(MYQUEST, tmpquests) != -1) continue;
            MyKillers[Amt]->set_mini_quest(MYQUEST, 1000000, MYQUEST);
            tell_object(MyKillers[Amt], "%^BOLD%^%^BLACK%^You have banished the bones of Ao'rus Devar... "+
            "but somehow you feel as if a part of the strange being %^BOLD%^%^CYAN%^still "+
            "exists%^BOLD%^%^BLACK%^ somewhere....");
        }
        message("info", "%^BOLD%^%^BLACK%^A massive explosion of D%^BOLD%^%^WHITE%^A%^BOLD%^"+
        "%^BLACK%^RK %^BOLD%^%^WHITE%^E%^BOLD%^%^BLACK%^N%^BOLD%^%^WHITE%^E%^BOLD%^%^BLACK%^"+
        "RGY erupts over the island of "+
        "Deku as the bones of %^BOLD%^%^WHITE%^Au'rus Devar%^BOLD%^%^BLACK%^ are "+
        "banished!%^RESET%^", users());

        WORLD_EVENTS_D->inject_event((["Banishment of Au'rus Devar!" : (["start message" : "%^BOLD%^%^BLACK%^A wave of power from the blast circles the world "+
        "multiple times... and you feel some of it settle over you, seeping into your very %^BOLD%^%^CYAN%^soul%^BOLD%^%^BLACK%^!! You feel your ability to "+
        "absorb information "+
        "expand incredibly!! For the next %^BOLD%^%^CYAN%^two hours%^BOLD%^%^BLACK%^ all experience gained will award an additional %^BOLD%^%^CYAN%^"+
        "15%%^BOLD%^%^BLACK%^!%^RESET%^",
        "event type" : "exp bonus", "length" : 120, "notification" : "15% Bonus Exp",
        "event name" : "Banishment of Au'rus Devar!", "modifier" : 15, "announce" : 1, "announce to" : "world" ]),]));

        return ::die(ob);
    }
    else adjust_me();
    return;
}

void obliterate_two()
{
    object *myEnemies;
    int x, dam;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    myEnemies = TO->query_attackers();
    if(!sizeof(myEnemies)) return;

    tell_room(ETO, "%^BOLD%^%^RED%^The very %^BOLD%^%^WHITE%^AIR%^BOLD%^%^RED%^"+
    " around you E%^BOLD%^%^YELLOW%^X%^BOLD%^%^RED%^P%^BOLD%^%^YELLOW%^L%^BOLD%^%^RED%^"+
    "O%^BOLD%^%^YELLOW%^D%^BOLD%^%^RED%^E%^BOLD%^%^YELLOW%^S%^BOLD%^%^RED%^ and a "+
    "massive %^BOLD%^%^CYAN%^WAVE%^BOLD%^%^RED%^ of flame washes over "+
    "everything!%^RESET%^");

    for(x = 0;x < sizeof(myEnemies);x++)
    {
        if(!interactive(myEnemies[x]))
        {
            dam = roll_dice(60,12);
            set_property("noMissChance", 1);
            myEnemies[x]->cause_typed_damage(myEnemies[x], 0, dam, "fire");
            set_property("noMissChance", -1);
            continue;
        }
        dam = roll_dice(30, 12);
        if(myEnemies[x]->fort_save(35)) dam = dam/2;
        tell_object(myEnemies[x], "%^BOLD%^%^RED%^The massive wave of flame "+
        "engulfs you!%^RESET%^");
        set_property("noMissChance", 1);
        myEnemies[x]->cause_typed_damage(myEnemies[x], 0, dam, "fire");
        set_property("noMissChance", -1);
        continue;
    }
    tell_room(ETO, "%^BOLD%^%^CYAN%^The air around you quickly cools as the wave of "+
    "flame dies out!%^RESET%^");
    return;
}


void obliterate(object targ)
{
    string me;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    me = TO->query_short();

    command("say HOW DARE YOU???? I will SHOW YOU %^BOLD%^%^RED%^SUFFERING%^RESET%^!");

    tell_room(ETO, me +"%^BOLD%^%^BLUE%^ roars loudly before uttering a quick incantation in a "+
    "mysterious language and you feel the air around you warmingly rapidly!%^RESET%^");

    call_out("obliterate_two", 10);
    return;
}


void my_spell_attack(object targ)
{
    string mySpell, me;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;
    me = TO->query_short();
    if(random(3))
    {
        tell_object(targ, me + "%^BOLD%^%^CYAN%^ mumbles a quiet incantation in a mysterious language while pointing "+
        "at you!%^RESET%^");

        tell_room(ETO, me+"%^BOLD%^%^CYAN%^ mumbles a quiet incancation in a mysterious language while pointing at "+
        targ->QCN+"%^BOLD%^%^CYAN%^!%^RESET%^", targ);

        mySpell = myKnownSpells[random(sizeof(myKnownSpells))];
        new(mySpell)->use_spell(TO, targ, 75, 0);
    }
    else
    {
        tell_room(ETO, me +"%^BOLD%^%^CYAN%^'s %^BOLD%^%^BLACK%^dark orbs%^BOLD%^%^BOLD%^%^CYAN%^ grow dim as "+
        "it completes a quick incantation in a mysterious language!%^RESET%^");

        mySpell = myKnownProtectSpells[random(sizeof(myKnownProtectSpells))];
        new(mySpell)->use_spell(TO, TO, 75, 0);
    }
}

void myshadow(object targ)
{
    object mon;
    string me;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;
    me = TO->query_short();

    if(present("hulking shadow", ETO))
    {
        my_spell_attack(targ);
        return;
    }


    tell_object(targ, me +"%^BOLD%^%^CYAN%^ whispers an incantation in "+
    "perfect drow directed at you%^RESET%^: Barra chi' dos!%^RESET%^");

    tell_room(ETO, me +"%^BOLD%^%^CYAN%^ whispers an incantation in perfect drow directed "+
    "at "+targ->QCN+"%^RESET%^: Barra chi' dos!%^RESET%^", targ);

    tell_object(targ, "%^BOLD%^%^RED%^The hair on the back of your neck "+
    "stands up as you sense something is incredibly wrong.....%^RESET%^");

    tell_room(ETO, "%^BOLD%^%^BLUE%^Before your very eyes, "+targ->QCN+
    "%^BOLD%^%^BLUE%^'s shadow %^BOLD%^%^RED%^RISES%^BOLD%^%^BLUE%^"+
    " up behind "+targ->QO+"%^BOLD%^%^BLUE%^ and attacks!%^RESET%^", targ);

    mon = new(HHMON+"hulking_shadow");
    mon->shadow_me(targ);
    mon->move(ETO);
    mon->set_property("minion", TO);
    //TO->set_property("minion", mon);
    TO->add_protector(mon);
    mon->dark_bolt(targ);
    return;
}

void construct(object targ)
{
    int amt;
    object mon;
    string me;
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    if(!objectp(ETO)) return;

    me = TO->query_short();
    if(present("gleaming black skeleton 2", ETO))
    {
        my_spell_attack(targ);
        return;
    }

    tell_room(ETO, me + "%^BOLD%^%^GREEN%^ utters an incantation in perfect "+
    "drow%^RESET%^: Rothrl uns'aa!");

    amt = 2;

    tell_room(ETO, "%^BOLD%^%^BLACK%^"+capitalize(NUMBERS[amt])+ " %^BOLD%^%^BLACK%^"+
    "%^BOLD%^%^WHITE%^g%^BOLD%^%^BLACK%^l%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^a%^BOLD%^%^WHITE%^m"+
    "%^BOLD%^%^BLACK%^i%^BOLD%^%^WHITE%^n%^BOLD%^%^BLACK%^g %^BOLD%^%^WHITE%^black skeletons "+
    "quickly assemble from the piles of bone and attack "+targ->QCN+"!%^RESET%^", targ);

    tell_object(targ, "%^BOLD%^%^BLACK%^"+capitalize(NUMBERS[amt])+ " %^BOLD%^%^BLACK%^"+
    "%^BOLD%^%^WHITE%^g%^BOLD%^%^BLACK%^l%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^a%^BOLD%^%^WHITE%^m"+
    "%^BOLD%^%^BLACK%^i%^BOLD%^%^WHITE%^n%^BOLD%^%^BLACK%^g %^BOLD%^%^WHITE%^black skeletons "+
    "quickly assemble from the piles of bone and attack you!%^RESET%^");

    while(amt--)
    {
        mon = new(HHMON+"giant_skeleton");
        mon->move(ETO);
        TO->add_protector(mon);
        mon->set_property("minion", TO);
        //TO->set_property("minion", mon);
    }
    mon->destroy(targ);
    return;
}

void set_paralyzed(int time,string message) { return;}

void set_tripped(int time, string message) { return; }
