// trying to tweak lujke's code (hades)
// he is too smart for me
#include <std.h>
#include "../elf.h"

#define HUNTER MON"hunter"
#define ARCHER MON"archer"

inherit OBJECT;

object *HUNTERS = ({}), *ARCHERS = ({});


void create() 
{
    ::create();
    set_name("feeling of being unwelcome in Ashta'Rathai");   
                        
    set_id(({"feeling1"}));   

    set_short("");
    
    set_long("As you reflect inwards into your emotions, you are"
        +" aware of a distinct feeling that you are not welcome in the"
        +" city of Ashta'Rathai, and that they might shoot arrows at you if"
        +" you go there.");
        
    set_weight(0);          
    set_property("no drop",1);
    set_property("no offer",1);
    set_property("no animate",1);
    set_heart_beat(1);
}


void init()
{
    ::init();
    call_out("check_func",5);
}


int in_elf_area(object obj)
{
    string file;
    
    if(!objectp(obj)) { return 0; }    
    file = base_name(obj);
    if(!stringp(file) || !strlen(file)) { return 0; }    
    if(strsrch(file,"/d/islands/elf/") == -1) { return 0; }
    return 1;
}


void check_hunters()
{
    int i;
    
    HUNTERS -= ({ 0 });
    
    for(i=0;sizeof(HUNTERS),i<sizeof(HUNTERS);i++)
    {
        if(!objectp(HUNTERS[i])) { continue; }
        if(!objectp(ETO) || !interactive(ETO) || !objectp(EETO))
        {
            HUNTERS[i]->off_duty();
        }
    }
    
    HUNTERS -= ({ 0 });
    return;
}


void check_archers()
{
    int i;
    
    ARCHERS -= ({ 0 });
    
    for(i=0;sizeof(ARCHERS),i<sizeof(ARCHERS);i++)
    {
        if(!objectp(ARCHERS[i])) { continue; }
        if(!objectp(ETO) || !interactive(ETO) || !objectp(EETO))
        {
            ARCHERS[i]->off_duty();
        }
    }
    
    ARCHERS -= ({ 0 });
    return;
}


void heart_beat()
{
    object creature, *creatures = ({});
    int i,j, num, groups, level;
  
    if(!objectp(ETO) || !interactive(ETO) || !objectp(EETO))
    {
        return;
    }
  
    set_hidden(1);
  
    if(in_elf_area(EETO))
    {
        if(EETO->query_property("indoors") == 1)
        {
            if(!random(10))
            {
                check_hunters();
                
                if(!sizeof(HUNTERS))
                {
                    for(i=0;i<roll_dice(2,2);i++)
                    {
                        creature = new(HUNTER);                        
                        
                        tell_room(EETO, "A vicious hunter bursts in and attacks "+ETO->QCN + "!", ETO);
                        tell_object(ETO,"A vicious hunter bursts in and attacks you!");
                        
                        level = ETO->query_base_character_level();
          
                        creature->set_property("fighter_attacks_mod",level/7);
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
                        creature->set_target(ETO->query_name());
                        creature->force_me("kill " + ETO->query_name());
                        creature->rush_em(ETO);
                        
                        HUNTERS += ({ creature });
                    }
                }
            }
        }

        else
        {
            check_archers();
            
            if(!sizeof(ARCHERS))
            {
                for(i=0;i<roll_dice(3,3);i++)
                {
                    creature = new(ARCHER);                        

                    level = ETO->query_base_character_level();
      
                    creature->set_property("fighter_attacks_mod",level/10);
                    creature->set_property("magic resistance",level + 30);
                    creature->add_damage_bonus(7+(level/5));
                    creature->add_attack_bonus(7+(level/5));
                    creature->set_hd(level + 10,20);
                    creature->set_mlevel("fighter",level + 10);
                    creature->set_stats("strength", level);
                    creature->set_stats("dexterity", level);
                    creature->set_stats("constitution", level);
                    creature->set_hp(level * 100);
                    creature->set_overall_ac(-1 * level);
      
                    creature->set_target(ETO->query_name());
                    ARCHERS += ({ creature });  
                }
                
                if(!place_archer(ARCHERS))
                {
                    for(i=0;sizeof(ARCHERS),i<sizeof(ARCHERS);i++)
                    {
                        ARCHERS[i]->move("/d/shadowgate/void");
                        ARCHERS[i]->remove();
                    }
                }
            }
        }
    }
}



int place_archer(object *creatures)
{
    object startroom, temproom, nextroom;
    string *exits, direction;
    int i, distance;

    if(!pointerp(creatures) || !sizeof(creatures)) { return; }    
    if(!objectp(EETO)) { return; }

    startroom = EETO;  
    exits = startroom->query_exits();
    
    if(!sizeof(exits)) { return; }
   
    i = random(sizeof(exits));
    
    direction = exits[i];
    distance = roll_dice(1,4);
    temproom = startroom;
  
    for(i=0;i<distance;i++)
    {
        if(temproom->query_exit(direction) == "/d/shadowgate/void") { break; }     
        nextroom = find_object_or_load(temproom->query_exit(direction));        
        if(objectp(nextroom)) { temproom = nextroom; }
    }
  
    if(objectp(temproom))
    {
        tell_room(EETO, "%^GREEN%^Some movement to the %^CYAN%^"+direction + "%^GREEN%^ catches"
            " your attention as a some elven archers appear from hiding places.");
        
        for (i=0;sizeof(creatures),i<sizeof(creatures);i++)
        {
            if(!objectp(creatures[i])) { continue; }
            creatures[i]->move(temproom);
        }
    }
    else
    {
        for(i=0;i<sizeof(creatures);i++)
        {
            if(!objectp(creatures[i])) { continue; }
            creatures[i]->remove();
        }
    }
    return 1;
}


//due to the eq change, can't run this off of wear funcs so tweaking
int check_func()
{
    int i, num;
    
    if(!objectp(ETO) || !objectp(EETO)) { return 0; }
    
    if(ETO->query_ghost())
    {
        TO->move("/d/shadowgate/void");
        TO->remove();
        return 1;
    }
    
    set_hidden(1);
    set_heart_beat(1);
    
    if(!in_elf_area(EETO)) { return 0; }

    if(!random(20)) { tell_object(ETO, "You realise that you are really not wanted in Ashta'Rathai."); }

    return 1;
}
