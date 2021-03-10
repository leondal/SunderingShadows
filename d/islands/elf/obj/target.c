// coded by hades, most of code is stolen from
//Lujke's ulfang target
#include <std.h>
#include <terrain.h>
#include "../elf.h"

inherit OBJECT;

int tracker;


void create() 
{
   ::create();
   set_name("targetob");
   set_id( ({ "target999"}) );
   set_short("");
   set_long("");
   set_weight(0);
   set_property("no animate",1);
   set_heart_beat(2);
   tracker = time() + 14400;
}


void heart_beat()
{
    object creature;
    int level;
    
    if(!objectp(ETO)) return;
    if(!objectp(EETO)) return;
    if(!interactive(ETO))return;
    
    //send assassin if not in city
    if (tracker > time()) return;
    //wait a day before attack
    if(member_array(EETO->query_terrain(), CIVILIZATION) != -1) { return; }
    if(EETO->query_property("no teleport")) return;
    if(ETO->query_invis()) return; // and vis
    if(present("elven assassin",EETO)) return;
    
    creature = new(MON"elfass2");
   
    tell_room(EETO, "%^RED%^An elven assassin bursts in and attacks "+ ETO->QCN + "!", ETO);
    tell_object(ETO,"%^RED%^A vengeful elf bursts in and attacks you!");
    
    level = ETO->query_base_character_level();

    creature->set_property("fighter_attacks_mod",level/5);
    creature->set_property("magic resistance",level + 30);
    creature->add_damage_bonus(7+(level/7));
    creature->add_attack_bonus(7+(level/7));
    creature->set_hd(level + 10,20);
    creature->set_mlevel("fighter",level + 10);
    creature->set_stats("strength", level);
    creature->set_stats("dexterity", level);
    creature->set_stats("constitution", level);
    creature->set_hp(level * 100);
    creature->set_overall_ac(-1 * level);

    
    creature->move(EETO);
    creature->force_me("speak elven");
    creature->force_me("say You will die for murdering like the murdering pig you are!");
    creature->set_target(ETO->query_name());
    creature->kill_ob(ETO);
    TO->remove();
    return;
}
