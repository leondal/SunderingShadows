//elf vampire coded by hades 9/5/20
#include <std.h>
#include "../elf.h"
inherit MONSTER;

int FLAG = 0;

void create()
{
    object ob;
    ::create();
    set_name("Daelas");
    set_id(({ "elf", "undead", "vampire", "daelas" }));
    set_short("%^BOLD%^%^RED%^Daelas, Elven Betrayer%^RESET%^");
    set_long("Daelas stands before you.  He is a noble looking "+
    "gold elf with amber eyes and golden hair.  He was once"+
    " known as a great elven weapons master who mastered both"+
    " blade and magic but was killed by vampires and forced"+
    " to become an evil vampire thrall.");
    set_race("elf");
    set_alignment(3);
    set_hd(50, 1000);
    set_gender("male");
    add_search_path("/cmds/wizard");
    add_search_path("/cmds/thief");
    add_money("gold", random(10000) + 50000);
    set_stats("strength", 12);
    set_stats("constitution", 15);
    set_stats("dexterity", 16);
    set_stats("wisdom", 19);
    set_stats("intelligence", 30);
    set_stats("charisma", 17);
    set_body_type("human");
    set_max_hp(6500);
    set_new_exp(45,"high");
    set_max_level(47);
    set_hp(query_max_hp());
    set_size(2);
    set_attacks_num(6);
    set_func_chance(40);
    set_funcs(({ "special1" }));
    set_spell_chance(60);
    set_spells(({
        "eyebite",
        "animus blast",
        "vampiric touch",
        "necrophage",
        "powerword stun"
    }));
    set_class("mage");
    set_class("thief");
    set_mlevel("mage", 50);
    set_mlevel("thief", 50);
    set_property("water breather", 1);
    set_property("full attacks", 1);
    set_property("weapon resistance", 5);
    set_property("no steal", 1);
    set_property("no paralyze", 1);
    set_property("no death", 1);
    set_monster_feats(({
        "spell penetration", "greater spell penetration",
        "scramble", "evasion","combat reflexes",
        "dodge","mobility","blindfighting"
    }));
    set_mob_magic_resistance("high");
    set_emotes(5, ({
        "%^MAGENTA%^Daelas says%^RESET%^: I can't e blamed...I had no choice. " ,
        "%^MAGENTA%^Daelas says%^RESET%^: I died for my people only to be brought back and forced to obey.",
        "%^MAGENTA%^Daelas says%^RESET%^: The master vampire...the things I was forced to do.",
        "%^MAGENTA%^Daelas says%^RESET%^: I don't even know how many years have passed.  Hundreds?  Thousands?",
        "%^MAGENTA%^Daelas says%^RESET%^: They made me kill the prince and princess.  I had to obey... ",
        "Daelas wavers, like he has some great burden he is carrying.",
        "%^MAGENTA%^Daelas says%^RESET%^: The heart of water sealed us for centuries... was it moved?",
        "%^MAGENTA%^Daelas says%^RESET%^: Leave me now...I don't want your death on my hands as well.",
    }), 0);
    set_achats(2, ({
        "%^MAGENTA%^Daelas says%^RESET%^:I see you have chosen death.",
        "%^MAGENTA%^Daelas says%^RESET%^:You should run.  Prove you are the coward.",
        "%^MAGENTA%^Daelas sasy%^RESET%^:I hate fighting. Let us finish this quickly.",
        "%^MAGENTA%^Daelas sasy%^RESET%^:Looks like you have resolved to die here."
     }) );
    set_property("function and attack",1);
    add_attack_bonus(20);
    add_damage_bonus(20);
    set_skill("perception",50); 
    set_skill("stealth",50); 


    ob = new("/d/magic/scroll");
    switch (random(4)) {
    case 0:
        ob->set_spell(6);
        break;

    case 1:
        ob->set_spell(7);
        break;

    case 2:
        ob->set_spell(8);
        break;

    case 3:
        ob->set_spell(9);
        break;
    }
    new(OBJ"v_gloves")->move(TO);
    new(OBJ"knife")->move(TO);
    new(OBJ"pants")->move(TO);
    new(OBJ"tunic")->move(TO);
    new(OBJ"sheath1")->move(TO);
    force_me("wield knife");
    force_me("wearall");
}

void special1(object targ)
{
 if(!"/daemon/saving_throw_d.c"->reflex_save(targ,-40)){
 
        tell_object(targ,
                    "%^BOLD%^%^RED%^The elf vampire bites into your neck!");
        tell_room(ETO,
                  "%^BOLD%^%^RED%^Daelas bites into "+targ->QCN+"'s neck!", targ);
        targ->cause_typed_damage(targ,0,roll_dice(10,10+200),"negative energy");
        TO->add_hp(200);
 }
 tell_room(ETO,"%^BOLD%^%^RED%^Dealas lunges for "+targ->QCN+"'s neck but misses.",targ);
 tell_object(targ,"%^BOLD%^%^RED%^Daelas lunges for your neck but you dodge.");
    return ;
}

void heart_beat()
{
    ::heart_beat();
    if (!objectp(TO)) {
        return;
    }
    if ((TO->query_hp() < 1000) && (FLAG != 1)) {
        FLAG = 1;
        TO->force_me("say %^BOLD%^%^RED%^I HAVEN'T BEEN HERE FOR CENTURIES TO DIE LIKE THIS!");
        new("/cmds/spells/b/_blink")->use_spell(TO, TO, 50, 100, "mage");
        TO->add_hp(random(500) + 675);
    }
    if (!TO->query_property("has_elemental") ) {
        new("/cmds/spells/g/_gate")->use_spell(TO, "summoning", 50, 100, "mage"); 
    }
    if(present("corpse",ETO))
    new("/cmds/spells/c/_create_greater_undead")->use_spell(TO, 0, 50, 100, "mage");
    return;
}
init()
{
  ::init();
  add_action("xlook", "look");
}

int xlook(string str)
{
  if(!str) return 0;
  if((member_array(str, query_id()) != -1) &&

  ((int)TP->query_level() > 15) &&
  ((int)TP->query_stats("charisma") < 25))
  {
    force_me("say Stop looking at me, "+TPQCN+
    "...Nnnnn...I can't stand being judged by those condeming eyes!");
    force_me("hide in shadows");
    force_me("stab "+TPQN);

    return 0;
  }
  else if(member_array(str, query_id()) != -1)
  {
    force_me("say Excuse me, "+TPQCN+", I normally "+
    "kill anyone that looks at me.  Just leave if "+
    "you don't want to die here.");

    return 0;
  }
}
