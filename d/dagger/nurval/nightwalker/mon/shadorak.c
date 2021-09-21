/*
   nightwalker.c

   Boss monster for the Herald of Darkness.
   Refitted to become world boss.

   -- Tlaloc -- 7.19.20
 */


#include <std.h>
#include <daemons.h>
#include <magic.h>
#include "/d/islands/tonerra/areadefs.h"

inherit WEAPONLESS;

int coreparty = 4;

string color(string str)
{
    return CRAYON_D->color_string(str, "very black");
}

void create()
{
    object ob;
    ::create();

    set_name("nightwalker");
    set_id(({ "nightwalker", "demigod", "shadow god", "night walker", "shadorak" }));
    set_short("%^BLACK%^BOLD%^Shadorak, Greater %^BOLD%^BLACK%^N%^RESET%^%^CYAN%^i%^BOLD%^g%^BLACK%^h%^RESET%^%^CYAN%^t%^BOLD%^w%^BLACK%^a%^RESET%^%^CYAN%^l%^BOLD%^k%^BLACK%^er of Nilith%^RESET%^");
    set_long("%^BLACK%^BOLD%^This being is the stuff of nightmares. It is quite tall, towering over the nearby buildings with its lanky form. It is black and featureless, with a miasma of dark energies emanating from it. Upon its head are two shadow horns that sweep back and up away from its head, which is featureless save for two glowing azure eyes.");
    set_body_type("humanoid");
    add_limb("tendril one", "torso", 0, 0, 0);
    add_limb("tendril two", "torso", 0, 0, 0);
    add_limb("tendril three", "torso", 0, 0, 0);
    add_limb("tendril four", "torso", 0, 0, 0);
    set_gender("neuter");
    set_race("undead");
    set_size(4);
    set_hd(75, 9);
    set_class("fighter");
    set_class("mage");
    set_class("cleric");
    set_class("inquisitor");
    set_class("gravecaller");
    set_mlevel("fighter", 75);
    set_mlevel("mage", 75);
    set_mlevel("cleric", 75);
    set_mlevel("inquisitor", 75);
    set_mlevel("gravecaller", 10);
    set_guild_level("cleric", 75);
    set_guild_level("mage", 75);
    set_guild_level("inquisitor", 75);
    set_alignment(9);
    set_attack_limbs(({ "right claw", "left claw", "mouth", "tendril one", "tendril two", "tendril three", "tendril four" }));
    set_hit_funcs(([ "right claw" : (: this_object(), "claw" :), "left claw" : (: this_object(), "claw" :), "mouth" : (: this_object(), "bite" :), "tendril one" : (: this_object(), "tendril" :),"tendril two" : (: this_object(), "tendril" :),"tendril three" : (: this_object(), "tendril" :),"tendril four" : (: this_object(), "tendril" :) ]));
    set_base_damage_type("slashing");
    set_damage(16, 7);
    set_attacks_num(5);
    set_property("no death", 1);
    set_property("no bows", 1);
    set_property("no knockdown", 1);
    set_property("no trip", 1);
    set_property("no tripped", 1);
    set_property("no steal", 1);
    set_property("no dominate", 1);
    set_property("no hold", 1);
    set_property("hidden inventory", 1);
    set_property("cast and attack", 1);
    set_property("function and attack", 1);
    set_skill("perception", 50);
    set_mob_magic_resistance("high");
    set_overall_ac(-70);
    set_max_hp(125000);
    set_hp(query_max_hp());
    set_property("add kits", 40);
    set_new_exp(75, "boss");
    set_property("add quest", "%^BOLD%^%^BLACK%^Defeated the Nightwalker!%^RESET%^");
    set_property("quest exp", 12000000);
    add_money("gold", random(100000) + (80000));
    add_money("platinum", random(20000) + (40000));
    set_emotes(30, ({ "%^BLACK%^BOLD%^Nightwalker whispers : THE TIME OF THE LIVING IS OVER....%^RESET%^",
                      "%^BLACK%^BOLD%^Nightwalker whispers : YOU PLAY WITH POWERS YOU DO NOT UNDERSTAND....%^RESET%^",
                      "%^BLACK%^BOLD%^Nightwalker whispers : YOUR ESSENCE WILL FEED ME....%^RESET%^", }), 20);
    set_monster_feats(({
        "spell focus",
        "spell penetration",
        "greater spell penetration",
        "spell power",
        "perfect caster",
        "blind fight",
        "spell reflection",
        "lifeless shroud"
    }));
    set_spells(({ "unholy orb",
                  "umbral strike",
                  "eyebite",
                  "epidemic",
                  "mass fester",
                  "greater dispel magic",
                  "animus blizzard",
                  "nightmare maw",
                  "exhume corpses", }));
    set_spell_chance(85);
    add_money("platinum", 100000 + random(20000));
    set_property("no paralyze", 1);
    set_acquired_template("shade");
    set_sight_bonus(5);
    command("lifeless_shroud");
}

void set_paralyzed(int time, string message)
{
    if (!objectp(this_object()))
    {
        return;
    }
    if (!objectp(environment(this_object()))) 
    {
        return;
    }
    tell_room(environment(this_object()), "The Nightwalker seems unaffected by paralysis!");
    return;
}

void init()
{
    int psize;
    object player, room;
    
    ::init();
    
    player = this_player();
    player && room = environment(this_object());
    
    if(!player || !room)
        return;
    
    if (wizardp(player) || player->query_true_invis()) {
        return;
    }

    if(player->query_true_align() != 3 &&
       player->query_true_align() != 6 &&
       player->query_true_align() != 9 &&
       !player->is_undead() &&
       player->query("subrace") != "dhampir" &&
       member_array("collector", player->query_id()) < 0 &&
       member_array("nightmare", player->query_id()) < 0)
         this_object()->kill_ob(player);

    psize = sizeof(filter_array(all_inventory(ETO), (: userp($1) :)));
    psize = psize < 1 ? 1 : psize;
    if (psize > coreparty) {
        set_max_hp(30000 * psize);
        set_hp(query_max_hp());
        set_damage(16, 5 + psize);
        coreparty = psize;
    }
    
    new("/cmds/spells/v/_vampiric_shadow_shield.c")->use_spell(this_object(), 0, 70, 100, "mage");
    new("/cmds/spells/s/_shadow_body.c")->use_spell(this_object(), 0, 70, 100, "mage");
    new("/cmds/spells/s/_shadowform.c")->use_spell(this_object(), 0, 70, 100, "mage");
    new("/cmds/spells/f/_frightful_aspect.c")->use_spell(this_object(), 0, 70, 100, "mage");
}

die(object ob)
{
    tell_room(environment(this_object()), "%^BLACK%^BOLD%^The tendrils of shadow seem to collapse in on themselves. "
              "The darkness coalesces into a swirling miasma as it drains back into the Shadow Plane.%^RESET%^");
    
    foreach(object obj in this_object()->query_attackers())
    {
        userp(obj) && obj->set_mini_quest("Challenged the Avatar of Nilith", 1000000, "%^BOLD%^BLACK%^Challenged the Avatar of Nilith%^RESET%^");
        userp(obj) && tell_object(obj, "%^BOLD%^BLACK%^You accomplished: Challenged the Avatar of Nilith.%^RESET%^");
    }
    /*          
    WORLD_EVENTS_D->kill_event("The Nightwalker has been defeated");
    WORLD_EVENTS_D->inject_event((["The Nightwalker has been defeated" : (["start message" : "%^BOLD%^%^BLACK%^The Nightwalker has been defeated!", "event type" : "exp bonus", "length" : 720, "notification" : "3% Bonus Exp", "event name" : "The Nightwalker has been defeated", "modifier" : 3, "announce" : 1, "announce to" : "world" ]), ]));
    */
    return ::die();
}

void heart_beat()
{
    object attackers, corpse, room;

    if (!objectp(this_object()))
    {
        return;
    }

    ::heart_beat();
    
    room = environment(this_object());
    
    if(!room)
        return;

    if (!random(10) && (query_hp() < query_max_hp()))
    {
        tell_room(room, "%^BLACK%^BOLD%^Nightwalker draws strength from the shadows around it.%^RESET%^");
        add_hp(1000);
    }

    //If a group of corpses are in the room, raise them.
    corpse = present("corpse 4", room);

    if(objectp(corpse) && !random(3))
        new("/cmds/spells/a/_animate_dead")->use_spell(this_object(), 0, 70, 100, "mage");

    attackers = this_object()->query_attackers();

    if(sizeof(attackers))
    {
        if(!random(5))
        {
            tell_room(room, "%^BOLD%^BLACK%^Waves of necrotic energy pour off of the Nightwalker, tearing life energy from its enemies!");
            
            foreach(object ob in attackers)
                ob->cause_typed_damage(ob, ob->return_target_limb(), roll_dice(20, 20) + 100, "negative energy");
        }
        
        if(!present("corpse", room) && !random(5))
            new("/cmds/spells/e/_exhume_corpses.c")->use_spell(this_object(), 0, 70, 100, "mage");

        if(!present("banshee", room) && !random(5))
        {
            tell_room(room, "%^BOLD%^MAGENTA%^The Nightwalker raises its hand and summons a group of screaming banshees!");
            new("/d/dagger/nurval/mon/banshee")->move(room);
            new("/d/dagger/nurval/mon/banshee")->move(room);
            new("/d/dagger/nurval/mon/banshee")->move(room);
            new("/d/dagger/nurval/mon/banshee")->move(room);
            new("/d/dagger/nurval/mon/banshee")->move(room);
            new("/d/dagger/nurval/mon/banshee")->move(room);
        }
        if(!present("bonewyvern", room) && !random(10))
        {
            tell_room(room, "%^BOLD%^GREEN%^The Nightwalker raises its clawed hand and bone wyverns crawl out of the ground!");
            new("/d/dagger/nurval/mon/bonewyvern")->move(room);
            new("/d/dagger/nurval/mon/bonewyvern")->move(room);
        }
    }
}

object pick_random_target()
{
    object* attackers;
    if (!objectp(TO)) {
        return 0;
    }

    attackers = this_object()->query_attackers();

    if (!sizeof(attackers)) {
        return 0;
    }
    return attackers[random(sizeof(attackers))];
}

/*
  MELEE ATTACK SPECIALS
*/

int bite(object me, object ob)
{   
    if(!ob)
        return 0;
    
    if(random(5))
        return roll_dice(1, 8);
    
    tell_object(ob, color("The Nightwalker envelops you in its shadowy jaws!"));
    tell_room(environment(this_object()), color("The Nightwalker envelops " + ob->QCN + " in its shadowy jaws!"), ({ ob }));
    
    return roll_dice(6, 10) + 10;
}

int claw(object me, object ob)
{   
    if(!ob)
        return 0;
    
    if(random(5))
        return roll_dice(1, 8);
    
    tell_object(ob, color("The Nightwalker slashes you with its claws!"));
    tell_room(environment(this_object()), color("The Nightwalker slashes " + ob->QCN + " with its claws!"), ({ ob }));
    
    ob->set_property("rend", 5);
    
    return roll_dice(6, 10) + 10;
}

int tendril(object me, object ob)
{   
    if(!ob)
        return 0;
    
    if(random(5))
        return roll_dice(1, 8);
    
    if(SAVING_THROW_D->reflex_save(ob, 0))
    {
        tell_object(ob, "%^BOLD%^You slip away from the tendril's grasp!%^RESET%^");
        return 0;
    }
    
    tell_object(ob, color("The Nightwalker reaches out with a shadow tendril and grabs you!"));
    tell_room(environment(this_object()), color("The Nightwalker reaches out with a shadowy tendril and grabs " + ob->QCN + "!"), ({ ob }));
    
    ob->set_paralyzed(roll_dice(1,4) * 6, color("The tendril has you wrapped tight!"));
    
    return roll_dice(6, 10) + 10;
}
    
    
    
    
    
