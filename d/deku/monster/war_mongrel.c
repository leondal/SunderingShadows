#include <std.h>
#include <daemons.h>
#include "/d/deku/inherits/forest.h"
inherit MONSTER;

string *MyTreasure = ({DEKU_ARM"fire_robe", DEKU_ARM"fire_sandals", 
			     DEKU_ARM"fire_cloak", DEKU_WEP"kinordas_staff",
			     DEKU_ARM"spellring", DEKU_ARM"fire_band",
			     DEKU_ARM"eviscerator_exoskeleton"});
void create() 
{
    ::create();
    set_name("The War Mongrel");
    set_id(({"mongrel","war mongrel", "the war mongrel"}));
    set_race("magical creature");
    set_gender("neuter");
    set_short("%^BOLD%^%^BLACK%^The War Mongrel%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This grotesque creature towers over ten "+
    "feet tall, its flesh a cracked and rotting brown, oozing "+
    "%^BOLD%^%^GREEN%^green%^BOLD%^%^BLACK%^ puss in almost a "+
    "steady stream.  Instead of one head, there are four "+
    "atop this massive creature, one of a fire elemental, "+
    "one of a screaming, agonized imp, and two of dwarves, "+
    "which are locked in a constant argument amongst "+
    "themselves.  Beneath these heads, is perhaps, the worst, as "+
    "inset into its chest is the screaming head of what "+
    "appears to be an average male human.  Jaunting out, at "+
    "odd angles, on each side are four arms, each perhaps "+
    "two feet thick and holding either a flaming "+
    "dagger or flaming short sword.  Finally, though by no means "+
    "offering any comfort or confidence, this creature is held "+
    "up by no fewer than eight legs, each jaunting "+
    "outward, just as the arms, at very odd angles.  This thing "+
    "issues guttural moans and growls with each intake of air "+
    "and you fear that at any moment it may topple down on you.%^RESET%^");

    set_body_type("humanoid");
    set_alignment(7);
    set_mob_magic_resistance("average");
    set_property("full attacks", 1);
    add_limb("upper right hand", "torso", 0, 0, 0);
    add_limb("upper left hand", "torso", 0, 0, 0);
    add_limb("middle right hand", "torso", 0, 0, 0);
    add_limb("middle left hand", "torso", 0, 0, 0);
    add_limb("lower right hand", "torso", 0, 0, 0);
    add_limb("lower left hand", "torso", 0, 0, 0);
    add_limb("Kinorda's Head", "torso", 0, 0, 0);
    add_limb("Javiijeys' Head", "torso", 0, 0, 0);
    add_limb("Daliigwin's Head", "torso", 0, 0, 0);
    add_limb("Dalragwian's Head", "torso", 0, 0, 0);
    add_limb("Javiisees' Head", "torso", 0, 0, 0);
    add_limb("second right leg", "torso", 0, 0, 0);
    add_limb("third right leg", "torso", 0, 0, 0);
    add_limb("fourth right leg", "torso", 0, 0, 0);
    add_limb("second left leg", "torso", 0, 0, 0);
    add_limb("third left leg", "torso", 0, 0, 0);
    add_limb("fourth left leg", "torso", 0, 0, 0);

    set_wielding_limbs(({"upper right hand", "upper left hand", "middle right hand", 
    "middle left hand", "lower right hand", "lower left hand"}));
    set_hd(28,1);
    set_class("fighter");
    set_size(3);
    set_stats("dexterity", 18);
    set_stats("strength", 20);
    set_property("swarm", 1);
    set_funcs(({"inferno", "here_puppy_puppy", "golem_helper", 
    "flames", "control"}));
    set_func_chance(75);
    set_hp(975 + random(51));
    set_max_hp(query_hp());
    set_new_exp(25, "boss");
    //set_exp(12000);
    new(DEKU_WEP"fire_dagger")->move(TO);
    command("wield dagger");
    new(DEKU_WEP"fire_dagger")->move(TO);
    command("wield dagger");
    new(DEKU_WEP"fire_dagger")->move(TO);
    command("wield dagger");
    new(DEKU_WEP"fire_dagger")->move(TO);
    command("wield dagger");
    new(DEKU_WEP"fire_short")->move(TO);
    command("wield sword");
    new(DEKU_WEP"fire_short")->move(TO);
    command("wield sword");
    new(DEKU_WEP"fire_short")->move(TO);
    command("wield sword");
    new(DEKU_WEP"fire_short")->move(TO);
    command("wield sword");
    set_overall_ac(-12);
}

void persona_msg(string str)
{
    if(!str) return;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    tell_room(ETO, "%^BOLD%^%^WHITE%^The War Mongrel Assumes the "+
    "persona of "+str+"!%^RESET%^");
}

void inferno(object targ) 
{
    int dam, x;
    object *targs;
    if(!objectp(TO)) return;
    if(objectp(TO)) 
    {
        targs = all_living(ETO);
    }
    targs -= ({TO});
	dam = roll_dice(14, 6);
    persona_msg("The Fire Elemental King");
    tell_room(ETO, "%^RED%^With a sudden ferocious sound, that "+
    "could only be described as an inhuman growl of rage, "+
    "the war mongrel erupts into a flaming inferno, engulfing "+
    "everything in the immediate area%^RESET%^", ({TO}));
	
    for(x = 0;x < sizeof(targs);x++)
    {
        if(!objectp(targs[x])) continue;
        if(targs[x] == TO) continue;
        if(targs[x]->id("saidedekufiremon")) continue;
        if(targs[x]->reflex_save(14))
        {
            dam = dam/2;
        }
        tell_object(targs[x], "%^RED%^You are engulfed by the %^BOLD%^"+
        "%^RED%^I%^YELLOW%^N%^BOLD%^%^RED%^F%^YELLOW%^E%^RED%^R"+
        "%^YELLOW%^N%^RED%^O%^YELLOW%^!%^RESET%^");
	
        tell_room(environment(targs[x]),targs[x]->query_cap_name()+
        " is engulfed by the %^BOLD%^"+
        "%^RED%^I%^YELLOW%^N%^BOLD%^%^RED%^F%^YELLOW%^E%^RED%^R"+
        "%^YELLOW%^N%^RED%^O%^YELLOW%^!%^RESET%^", ({targs[x]}));
        targs[x]->cause_typed_damage(targs[x], "torso", dam, "fire");
        continue;
    }
    return;
}

void golem_helper(object targ) 
{
    int x;
    object ob;
    if(!random(2)) return;
    if(!TO) return;
    persona_msg("The Golem Master");
    command("say you wanna fight?????? Then fight these, you derty "+
    "elf arse!!");
    x = 1 + random(2);
    while(x > 0)	
    {
        tell_room(ETO, "%^BOLD%^%^RED%^A hellfire golem lumbers into "+
        "the room, in protection of The War Mongrel!%^RESET%^");
        ob = new(DEKU_MON"hellfire_golem");
        ob->move(ETO);
        ob->command("protect war mongrel");
        ob->command("protect war mongrel");
        if(!TO) return;
        x--;
    }
}
     
void flames(object targ) 
{
    int spells;
    spells = 1 + random(2);
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    if(targ->id("saidedekufiremon")) return;
    persona_msg("The Imp King");
    switch(random(5)) 
    {
        case 0..3:
            while(spells) 
            {
                spells--;
                new("/cmds/spells/m/_magic_missile")->use_spell(TO,targ,28, 28,"mage");
            }
            break;
        case 4:
            while(spells) 
            {
                spells--;
                new("/cmds/spells/f/_fireball.c")->use_spell(TO,targ,28,28,"mage");
            }
            break;
    }
}

void here_puppy_puppy(object targ) 
{
    int x;
    object ob;
    if(!random(2)) return;
    if(!TO) return;
    persona_msg("The Keeper of The Hounds");
    command("say Come Forth my minions, protect your master!");
    x = 1 + random(2);
    while(x > 0)	
    {
        tell_room(ETO, "%^BOLD%^%^RED%^A hellhound rushes into the "+
        "room, in protection of The War Mongrel!%^RESET%^");
        ob = new(DEKU_MON"hellhound");
        ob->move(ETO);
        ob->command("protect hound keeper");
        ob->command("protect hound keeper");
        if(!TO) return;
        x--;
    }
}

void control() 
{
    int y;
    object *mobs;
    if(!objectp(ETO)) return;
    mobs = all_living(ETO);
    mobs -= ({TO});	
    persona_msg("Kinorda");
    for(y = 0;y < sizeof(mobs);y++) 
    {
        if(avatarp(mobs[y])) continue;
        if(mobs[y]->id("saidedekufiremon")) continue;
        if(mobs[y]->will_save(10)) 
        { 
            tell_object(mobs[y],"%^RED%^You feel a force "+
            "compel you to protect The War Mongrel and you "+
            "can't seem to deny it!");

            tell_room(ETO,mobs[y]->QCN+"%^RED%^ stands in "+
            "protection of The War Mongrel!%^RESET%^",mobs[y]);

            TO->add_protector(mobs[y]);
            continue;
        }
        tell_object(mobs[y],"%^RED%^You feel a force "+
        "compel you to protect The War Mongrel, but you manage "+
        "to deny its influence!%^RESET%^");
        continue;
    }    
}

void pick_some_treasure(int how_many)
{
    int x;
    string this_treasure;
    object ob;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(how_many > sizeof(MyTreasure))
    {
        how_many = sizeof(MyTreasure);
    }
    while(how_many > 0)
    {
        how_many--;
        this_treasure = MyTreasure[random(sizeof(MyTreasure))];
        MyTreasure -= ({this_treasure});
        ob = new(this_treasure);
        ob->move(ETO);
        continue;
    }
}

void die(object ob) 
{
    int x;
    object weap;
    x = 4;
    while(x) 
    {
        if(random(5)) 
        {
            if(weap = present("fire dagger",TO)) 
            {
                tell_room(ETO,"%^RED%^The fire from the War Mongrel's dagger "+
                "burns out and it ceases its humming.%^RESET%^");
                weap->remove();
                new("/d/common/obj/weapon/dagger")->move(TO);
            }
            if(weap = present("fire sword", TO))
            {
                tell_room(ETO, "%^RED%^The fire from the War Mongrel's sword "+
                "burns out and it ceases its humming.%^RESET%^");
                weap->remove();
                new("/d/common/obj/weapon/shortsword")->move(TO);
            }
        }
        x--;
    }
    tell_room(ETO, "%^BOLD%^%^BLACK%^The monstrous corpse of the War Mongrel "+
    "topples over and its entrails spill out on the floor, along with a couple "+
    "other objects!%^RESET%^");   	
    pick_some_treasure(3);
    "/d/deku/forest/fire_tunnel/rooms/war_mongrels_tunnel10"->add_portal();
    return ::die(TO);
}