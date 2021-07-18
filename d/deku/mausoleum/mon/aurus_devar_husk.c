#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
inherit MONSTER;
object mySphere;
mapping AttackerInfo;
string *myKnownSpells, *myKnownProtectSpells;
string *MyTreasure = ({"amulet_of_insight", "enchanting_powder", "gauntlets_of_power", "greaves_of_power"});

string MYQUEST = "%^BOLD%^%^BLACK%^Achieved:%^BOLD%^%^WHITE%^ "+
                "B%^BOLD%^%^BLACK%^r%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^k%^BOLD%^%^WHITE%^e The Husk of %^BOLD%^%^WHITE%^Ao'rus "+
                "Devar%^RESET%^";                
int myPhase, myCount, myChance;
varargs void sphere(object targ);

void create() 
{
    object ob;
    ::create();
    set_name("husk of aorus devar");
    set_id(({"devar", "husk of aorus devar", "aorus", "husk"}));
    set_gender("male");
    set_race("human");

    set_short("%^BOLD%^%^GREEN%^The %^BOLD%^%^WHITE%^husk%^BOLD%^%^GREEN%^"+
    " of %^BOLD%^%^WHITE%^Ao'rus Devar%^RESET%^");

    set_long("%^BOLD%^%^GREEN%^This simple fleshly creature stands around six "+
    "feet tall. The flesh of the creature sags horribly. You actually wonder "+
    "for a moment if there are any bones for the flesh to attach to... "+
    "somehow it does stand upright, but something is definitely wrong with it. "+
    "The face of the creature is dead, there is %^BOLD%^%^BLACK%^no life%^BOLD%^"+
    "%^BOLD%^%^GREEN%^ there anymore, or nothing that you recognize as life anyway. " +
    "There are two %^BOLD%^%^BLACK%^dark eyes%^BOLD%^%^GREEN%^ that are void of "+
    "any color and a mass of stringy strands of %^BOLD%^%^WHITE%^silver%^BOLD%^%^GREEN%^"+
    " hair tops its head. The appendages of the creature are the only things that "+
    "appear to even have any remaining muscle mass, they are grotesquely veiny and "+
    "muscular, in fact the skin on all of its appendages has busted open in "+
    "places and muscle tissue peaks out.%^RESET%^");
  
    set_body_type("human");
    set_hd(25,2);
    set_alignment(9);
    set_size(4);
    set_class("mage", 26);
    set_stats("strength",30);
    set_stats("constitution",28);
    set_stats("wisdom",8);
    set_stats("intelligence",8);
    set_stats("dexterity",15);
    set_stats("charisma",15);

    set_property("no disarm", 1);
    set_property("no hold", 1);
    set_property("no death", 1);
    set_property("no paralyze", 1);
    set_property("full attacks", 1);
    set_property("no crit", 1);
    set_property("no tripped", 1);
    set_property("no steal", 1);    
    set_overall_ac(-12);

    set_mob_magic_resistance("average");
    set_property("weapon resistance", 3);

    ob = new("/d/common/obj/weapon/large_battle_axe");
    ob->set_property("enchantment", 4);
    ob->move(TO);
    command("wield axe");

    ob = new("/d/common/obj/weapon/large_battle_axe");
    ob->set_property("enchantment", 4);
    ob->move(TO);
    command("wield axe");

    set_hp(1500);
	
    set_new_exp(20, "boss");
    set_funcs(({"my_spell_attack"}));
    set_func_chance(45);
    set_monster_feats(({
        "rush",
        "perfect caster",
    }));

    myPhase = 1;
    myCount = 1;
    myChance = 10;
    AttackerInfo = ([]);
    myKnownSpells = (({"/cmds/spells/c/_cone_of_cold", "/cmds/spells/f/_fireball", "/cmds/spells/l/_lightning_bolt"}));
    myKnownProtectSpells = (({"/cmds/spells/b/_blink", "/cmds/spells/s/_stoneskin"}));
    new(MOBJ"sphere_key")->move(TO);
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

    myPhase++;
    assign_attacks(0);
    me = TO->query_short();
    if(objectp(mySphere)) mySphere->extinguish();
    
    switch(myPhase)
    {
        case 1:
            myChance = 10;
            set_funcs(({"my_spell_attack"}));
            set_func_chance(35);
            myKnownSpells = (({"/cmds/spells/c/_cone_of_cold", "/cmds/spells/f/_fireball", "/cmds/spells/l/_lightning_bolt"}));
            myKnownProtectSpells = (({"/cmds/spells/b/_blink", "/cmds/spells/s/_stoneskin"}));
            TO->set_hp(TO->query_max_hp());            
            break;

        case 2:

            myChance = 8;
            myKnownSpells = (({"/cmds/spells/m/_meteor_swarm", "/cmds/spells/c/_cone_of_cold", "/cmds/spells/f/_fireball", 
            "/cmds/spells/l/_lightning_bolt", "/cmds/spells/f/_flame_strike"}));
	
            command("speech cackle");
		
            command("say what would possess such weak mortal beings to attempt to "+
            "stand against my might??!!??%^RESET%^");
		
            tell_room(ETO, me +"%^BOLD%^%^RED%^ emits a gutteral moan as its "+
            "flesh mends!%^RESET%^");
            TO->set_hp(TO->query_max_hp());
            set_funcs(({"my_spell_attack", "sphere"}));
            set_func_chance(50);
            break;

        case 3:

            myChance = 5;
            command("speech cackle");
		
            command("say You thought it would be this easy??!!??%^RESET%^");
		
            tell_room(ETO, me +"%^BOLD%^%^RED%^ emits a gutteral moan as its "+
            "flesh mends!%^RESET%^");
			
            TO->set_hp(TO->query_max_hp());
           
            myKnownSpells = (({"/cmds/spells/m/_meteor_swarm", "/cmds/spells/c/_cone_of_cold", "/cmds/spells/f/_fireball", 
            "/cmds/spells/l/_lightning_bolt", "/cmds/spells/f/_flame_strike", "/cmds/spells/p/_prismatic_spray"}));			

            myKnownProtectSpells = (({"/cmds/spells/b/_blink", "/cmds/spells/s/_stoneskin", "/cmds/spells/t/_timeless_body"}));                        
            set_func_chance(75);            
            break;
	}
    assign_attacks(1);
    return;
}

void heart_beat()
{
    string me;
    int num_mon;
    object *myEnemies, myTarg, myChain;
    if(!objectp(TO)) return;
    if(TO->query("is_dying")) return;
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
	
    myEnemies = TO->query_attackers();
    me = TO->query_short();
    if((int)TO->query_hp() < ((int)TO->query_max_hp() / 12)) 
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
        TO->heal(15 + roll_dice(6,6));
    }

    if(!sizeof(myEnemies) && myPhase != 1) 
    {
        myCount++;
        if(myCount > 1200) 
        {
            myPhase = 1;
            adjust_me();
            myCount = 0;
        }
        return;
    }
    if(!random(myChance)) 
    {
        sphere();
    }
    if(!random(myChance) && present("corpse", ETO))
    {
        num_mon = (int)TO->query_property("raised");
        if(num_mon < (int)TO->query_class_level("mage")) 
        {
            new("/cmds/spells/a/_animate_dead")->use_spell(TO, ETO, 25, 0);
        }
    }
    if(!random(myChance) && sizeof(filter_array(all_inventory(ETO), "is_non_living", FILTERS_D)))
    {
        new("/cmds/spells/a/_animate_object")->use_spell(TO, ETO, 25, 0);
    }
    return;
}

void die(object ob) 
{
    string me, *tmpquests, tmp;
    int Amt, flag;
    object *MyKillers, MyOb;
    if(myPhase >= 3) 
    {       
        TO->set("is_dying");
        me = TO->query_short();
        tell_room(ETO, me +"%^BOLD%^%^BLACK%^ collapses, as the flesh holding it "+
        "together finally falters... and you notice a couple items among its broken "+
        "corpse.%^RESET%^");
        Amt = 2;
        while(Amt--)
        {
            tmp = MyTreasure[random(sizeof(MyTreasure))];
            MyTreasure -= ({tmp});
            MyOb = new(MOB+tmp);            
            MyOb->move(TO);
        }
        MyKillers = TO->query_attackers();
        MyKillers = filter_array(TO->query_attackers(), "is_player", FILTERS_D);              
        for(Amt = 0;Amt < sizeof(MyKillers);Amt++)
        {
            if(!objectp(MyKillers[Amt])) continue;
            if(environment(MyKillers[Amt]) != ETO) continue;
            tmpquests = (string *)MyKillers[Amt]->query_mini_quests();
            if(member_array(MYQUEST, tmpquests) != -1) continue;
            MyKillers[Amt]->set_mini_quest(MYQUEST, 3200000, MYQUEST);
            tell_object(MyKillers[Amt], "%^BOLD%^%^BLACK%^You have broken the husk of Ao'rus Devar... "+
            "but somehow you feel as if parts of the strange being %^BOLD%^%^CYAN%^still "+
            "exist%^BOLD%^%^BLACK%^ somewhere....");
        }       
        return ::die(ob);
    }
    else adjust_me();
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
        new(mySpell)->use_spell(TO, targ, 25, 0);
    }
    else
    {
        tell_room(ETO, me +"%^BOLD%^%^CYAN%^'s %^BOLD%^%^BLACK%^dark eyes%^BOLD%^%^BOLD%^%^CYAN%^ grow dim as "+
        "it completes a quick incantation in a mysterious language!%^RESET%^");

        mySpell = myKnownProtectSpells[random(sizeof(myKnownProtectSpells))];
        new(mySpell)->use_spell(TO, TO, 25, 0);
    }
}

varargs void sphere(object targ)
{
    string me;
    int num;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(objectp(mySphere)) return my_spell_attack(targ);
    else
    {
        me = TO->query_short();
        mySphere = new(MOBJ"chaos_sphere");
        tell_room(ETO, me +"%^BOLD%^%^GREEN%^ cackles deeply from its lifeless husk "+
        "before mumbling a quick incantation in a mysterious language.... ");
        mySphere->set_owner(TO);
        num = mySphere->get_number();
        tell_room(ETO, me +"%^BOLD%^%^WHITE%^ tosses a glowing sphere to the floor.... and "+
        "it rolls...... when it lands, the number "+num+" is flashing rapidly!%^RESET%^");  
        mySphere->move(ETO);
        return;
    }    
}
void set_paralyzed(int time,string message) { return;}

void set_tripped(int time, string message) { return; }
