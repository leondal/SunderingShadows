//Coded by Lujke
//stolen and tweaked by hades
#include <std.h>
#include <daemons.h>

#include "../elf.h"

#define PATHFINDER "/daemon/pathfinder_d.c"
#define ELF "/d/islands/elf"

#define YELL ({ "He's over here! Shoot him cousins!",\
                "There is the fiend, Aim true!",\
                "Fall you killer!",\
                "You are not wanted here! Crawl back under the rock you climbed out from!",\
                "The enemy is in sight! Cousins, shoot!",\
                "Foul Beast! Leave now or die!",\
                "Ashta'Rathai will stand for this no longer! It's time for you to leave!",\
                " We will not stop until you fall!",\
                "Leave now and we might spare your pathetic life!",\
                "We don't like your kind around here!",\
                "Now you die, guard killer!",\
                "Leave now and we might spare your pathetic life!",\
                "You will not defeat us! Surrender yourself!"})


inherit MONSTER;

int is_shooting,idle;
string target_name;
object far_targ;


void create()
{
    object obj;
    
    ::create();
    
    set_name("%^RESET%^%^GREEN%^Ashta'Rathai archer%^RESET%^");
    
    set_id(({"archer","Ashta'Rathai archer","elf","guard"}));
    
    set_short("%^RESET%^%^GREEN%^Ashta'Rathai archer%^RESET%^");
    
    set_long("%^GREEN%^The archer is clothes in simple "+
        "leather garments of woodland greens and "+
        "browns.  This guard holds a determined "+
        "look on their face to accomplish the task at"+
        " hand.  The guard is armed with a bow, and a sword.\n");
    
    set_race("elf");
    
    if(!random(2)) { set_gender("male"); }
    else { set_gender("female"); }
    
    set_hd(25,4);
    set_size(3);
    set("aggressive",0);
    set_class("fighter");
    set_mlevel("fighter",25);
    set_level(30);
    set_guild_level("fighter",25);
    set_hp(random(50)+200);
    set_speed(30);
    set_exp(3000);
    set_max_level(60);
    set_property("swarm",1);
    set_overall_ac(-10);
    set_alignment(4);
    set_mob_magic_resistance("average");
    set_property("full attacks",1);
    is_shooting = 0;

    obj = new(OBJ"bow");
    obj->move(TO);

    obj = new("/d/common/obj/lrweapon/limitlessquiver.c.c");
    obj->set_property("monsterweapon",1);
    obj->move(TO);

    obj = new("/d/common/obj/weapon/longsword");
    obj->set_property("monsterweapon",1);
    obj->move(TO);
    
    force_me("speak elven");
    new(OBJ"gloves")->move(TO);
    force_me("wearall");
 
    increase_skill("long bow", 200);
}


void init()
{
    ::init();
    force_me("wield bow");
}


void yell() { force_me("yell " + YELL[random(sizeof(YELL))] ); }


void heart_beat()
{
    object targ, * players;
    int i;
    if(!target_name) return;
    
    targ = present(target_name, ETO);
    
    if(objectp(targ))
    {
        drawsword();
        return;
    }

    if(is_shooting)
    {
        if(!random(5))
        {
            far_targ = PATHFINDER->far_present(ETO, target_name,  5);
            if(!objectp(far_targ))
            {
                off_duty();
            }
        }
    
        usebow();
        shoot(far_targ);
    }
    else
    {
        far_targ = PATHFINDER->far_present(ETO, target_name, 5);
        if(objectp(far_targ))
        {
            yell();
            is_shooting = 1;
        }
        else
        {
            off_duty();
        }
    }
}


void off_duty()
{
    force_me("emote goes back about his business");
    
    TO->move("/d/shadowgate/void");
    TO->remove();
}


void shoot(object targ)
{
    string direction;
    int distance, i, level;
    
    direction =  locate_target(targ, direction, distance);
    
    if(direction != "notfound")
    {
        if (!random(3))
        {
            yell();
        }
        
        level = targ->query_base_character_level() / 5;
        for(i=0;level, i<level;i++)
        {
            force_me("shoot " + target_name + " " + direction);
        }
    }
}


string locate_target(object target, string direction, int distance)
{
    object startroom, temproom, nextroom;
    string * exits;
    
    int i, j;

    if(!objectp(target)) { return -1; }
    
    startroom = ETO;
  
    if(!objectp(startroom)) { return -2; }
  
    exits = startroom->query_exits();
    
    if(sizeof(exits)<1) { return -1; }
  
    for(i=0;i<sizeof(exits);i++)
    {
        direction = exits[i];
        temproom = startroom;

        for (j=0;j<10;j++)
        {
            if(file_exists(temproom->query_exit(direction) + ".c"))
            {
                nextroom = find_object_or_load(temproom->query_exit(direction)+".c");
            }
            if(!objectp(nextroom))
            {
                break;
            }            
            if(present(target, temproom))
            {
                distance = j+1;
                return direction;
            }
            temproom = nextroom;
        }
    }
    return "notfound";
}


void drawsword()
{
    force_me("unwield bow");
    force_me("wield sword");
}


void usebow()
{
    force_me("unwield sword");
    force_me("wield bow"); 
}


void set_target(string name) { target_name = name; }

string query_target() { return target_name; }

