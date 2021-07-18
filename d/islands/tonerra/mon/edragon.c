//Updated the ancient gender mismatch typo and new description - Octothorpe 1/23/10
// put the no-steal property back on it again - someone removed it. Who the hell pickpockets a dragon? :P Nienne, 09/07.

#include <std.h>
#define SAVE_D "/daemon/save_d"
#include "/d/islands/tonerra/areadefs.h"

inherit WEAPONLESS;

#define HOMEROOM MOUNTAIN+"dhome"

string *revenge;
object *bait = ({});

int doing;
int angry;

void create()
{
    object ob;
    ::create();
    set_race("dragon");
    set_no_clean(1);
    set_name("emerald dragon");
    set_property("no bow",1);
    set_property("no bows",1);
    set_id(({"dragon","emerald dragon","Dragon","emerald","geonslu","Geonslu"}));
    set_short("%^RESET%^%^GREEN%^G%^BOLD%^eo%^RESET%^%^GREEN%^nsl"+
       "%^BOLD%^u, a%^RESET%^%^GREEN%^n %^BOLD%^o%^RESET%^%^GREEN%^ld "+
       "%^BOLD%^e%^RESET%^%^GREEN%^m%^BOLD%^e%^RESET%^%^GREEN%^r"+
       "%^BOLD%^a%^RESET%^%^GREEN%^ld dr%^BOLD%^a%^RESET%^%^GREEN%^g"+
       "%^BOLD%^%^GREEN%^o%^RESET%^%^GREEN%^n%^RESET%^");
    set_long("%^GREEN%^This grand beast simply towers above you and its "+
      "body extends nearly to fifty feet.  Her body is covered in a "+
      "multitude of viridian scales that almost appear as if they "+
      "could have been shaped out of actual e%^RESET%^%^GREEN%^m"+
      "%^BOLD%^e%^RESET%^%^GREEN%^r%^BOLD%^a%^RESET%^%^GREEN%^lds.  "+
      "The scales are translucent and sp%^BOLD%^%^WHITE%^ar%^RESET%^"+
      "%^GREEN%^kle brightly in the dimmest of light.  This majestic "+
      "behemoth is the true ruler of Tonerra.%^RESET%^");
    set_class("fighter");
    set_class("mage");
    set_hd(44,8);
    set_hp(2050);
    set_guild_level("fighter",44);
    set_guild_level("mage",44);
    set_mlevel("fighter",44);
    set_mlevel("mage",44);
    set_exp(100000);
    set_new_exp(50,"boss");
    set_overall_ac(-30); // -36 with bonuses
    set_body_type("dragon");
    set_attack_limbs(({"right claw","left claw","mouth"}));
    set_attacks_num(3);
    set_damage(1,25);
    set_hit_funcs((["mouth":(:TO,"mouth_attack":),"right claw":(:TO,"claw_attack":),"left claw":(:TO,"claw_attack":)]));
    set_base_damage_type("slashing");
    set_class("fighter");
    set_gender("female");
    set_race("dragon");
    set_funcs(({"do_me"}));
    set_func_chance(102);
    add_money("gold",random(20000));
    add_money("platinum",random(1000));
    set_alignment(2);
    //set_property("no rush",1);
    set_mob_magic_resistance("average");
    set_property("no knockdown",1);
    set_property("no death",1);
    set_property("no hold", 1);
    set_property("no paralyze", 1);
    set_property("no steal",1);
	set_property("damage resistance",5);
    /*set_wimpy(15); Causing an issue with the new stab code where Geonslu is fleeing mid-round, instead of at the end of the round. This is making it difficult for players to kill her. Moving flee code to run off of heart_beat(). - Octothorpe 1/26/17*/
    //   revenge = ({});
    new(OBJ+"powergem")->move(TO);
   "/daemon/monster_d.c"->add_death_watcher(TO);
    set_resistance("sonic",20);
}

int mouth_attack(object targ)
{
    if(present("Emerald gem",TO))
    {
        tell_room(ETO,"%^GREEN%^The emerald the dragon carries glows brighter.");
        return roll_dice(3,25);
    }
    return roll_dice(2,15);
}

int claw_attack(object targ)
{
    if(present("Emerald gem",TO))
    {
        tell_room(ETO,"%^GREEN%^The emerald the dragon carries glows brighter.");
        return roll_dice(2,7);
    }
    return 0;
}

void do_me(object targ)
{
    int i,j;
    object *inven;

    inven = all_living(ETO);

    j = sizeof(inven);
    tell_room(ETO,"%^BOLD%^The dragon lets out a loud keening wail that shakes the world.");
    for(i=0;i<j;i++)
    {
        if(!objectp(inven[i])) continue;
        if(inven[i] == TO) continue;
        if(avatarp(inven[i])) continue;
        set_property("magic",1);
        tell_object(inven[i],"The keening wail strikes you down shaking your soul.\n");
        //if("daemon/saving_d"->saving_throw(inven[i],"breath_weapon",-35)) // switching to 3ed saves
        if("/daemon/saving_throw_d"->reflex_save(inven[i],-35))
        {
            inven[i]->do_damage("torso",roll_dice(24,4)/2+6);
        }
        else 
        {
            inven[i]->do_damage("torso",roll_dice(24,4)+12);

            //if ( !"daemon/saving_d"->saving_throw(inven[i],"breath_weapon",-14)) {
            if(!"/daemon/saving_throw_d"->fort_save(inven[i],-14)) 
            {
                inven[i]->set_paralyzed(( roll_dice(1,12))*8,"%^BOLD%^The ringing in your head won't stop!");
            } 
            else
            {
                bait += ({ inven[i] });
                bait = distinct_array(bait);
                inven[i]->set_property("emerald_dragon_bait",-1);
                inven[i]->add_attack_bonus(-1);
            }
        }
        remove_property("magic");
    }
    set_func_chance(25);
}

void heart_beat()
{
    int i,j;
    object ob;
    string *tmp, location;

    ::heart_beat();

    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;

    tmp = ({});

   if(query_attackers() == ({}))
    {
        set_func_chance(102);
        if(!doing && sizeof((string *)SAVE_D->query_array("emerald_revenge")))
        {
            call_out("get_um",60);
            doing = 1;
        }
        if(base_name(ETO) != HOMEROOM)
        call_out("home",10);
    } 
    else
    {
        doing = 0;
    }

    if(query_attackers() != ({})) { add_hp(55); }
    else { set_hp(query_max_hp()); }
    
    if(query_attackers() != ({}))
    {
        if((int)TO->query_hp() < 308)
        {
            if(!query_paralyzed())
            {
                tell_room(ETO,"%^GREEN%^With horrible wounds the dragon "+
                    "flies high into the sky.");
                tell_room(ETO,"%^GREEN%^The words revenge echo through your "+
                    "mind.");
                tell_room(ETO,"%^GREEN%^You know that you will meet that "+
                    "dragon again.");
                tell_room(ETO,"%^BOLD%^%^BLACK%^\n\nREVENGE\n\n");
                move("/d/magic/obj/place");
            }
        }
   }
   
    j=sizeof(revenge = (string *)SAVE_D->query_array("emerald_revenge"));
    
    for(i=0;i<j;i++)
    {
        if(objectp(ob = find_player(revenge[i])))
        if(ob->query_ghost())
        SAVE_D->remove_name_from_array("emerald_revenge",revenge[i]);
    }
    
    location = base_name(ETO);
    if(location == HOMEROOM || location == "/d/islands/tonerra/mountain/mount63") 
    {
        if(!present("Emerald gem",TO)) new(OBJ+"powergem")->move(TO);
    }
    
    else 
    {
        if(ob = present("Emerald gem",TO)) 
        {
            ob->move("/d/shadowgate/void");
            ob->remove();
        }
    }
}

/*void run_away()
{
   if(!query_paralyzed())
   {
      tell_room(ETO,"%^GREEN%^With horrible wounds the dragon flies high into the sky.");
      tell_room(ETO,"%^GREEN%^The words revenge echo through your mind.");
      tell_room(ETO,"%^GREEN%^You know that you will meet that dragon again.");
      tell_room(ETO,"%^BOLD%^%^BLACK%^\n\nREVENGE\n\n");
      move("/d/magic/obj/place");
   }
}*/

int clean_up() { return 1; }

void set_paralyzed(int time, string mes)
{
    if(!PO->is_spell()) return ::set_paralyzed(time,mes);
    return;
}

int kill_ob(object victim, int which)
{
    int hold;
    hold = ::kill_ob(victim,which);

    if(!hold) return hold;

    if(userp(victim))
    {
        SAVE_D->set_value("emerald_revenge",victim->query_name());
    }
    return hold;
}

void set_bound(int xxx, string msg) {return 1;}

void set_tripped(int xxx, string msg) {return 1;}

void init()
{
    ::init();

    if(wizardp(TP)) return;
    
    if(TP->query_invis())
    {
        tell_object(TP,"%^GREEN%^The dragon chuckles as she glances in your direction.%^RESET%^\n");
    }
    
    if(TP == TO) return;
    if((int)SAVE_D->is_member("emerald_revenge",(string)TP->query_name()) != -1)
    {
        tell_object(TP,"%^GREEN%^Geonslu raises with a mighty roar and lashes out at you.%^RESET%^\n");
        tell_room(ETP,"%^GREEN%^Geonslu, with a mighty roar drives herself into "+TPQCN+"%^RESET%^!",TP);
        TP->set_paralyzed(5,"%^BOLD%^You're still reeling from the dragon's blow!%^RESET%^");
        kill_ob(TP,1);
        return;
    }

    if(member_array((string)TP->query_race(),({"firbolg","voadkyn","ogre","giant","minotaur"})) != -1)
    {
        tell_object(TP,"%^GREEN%^Geonslu raises with a mighty roar and lashes out at you.%^RESET%^\n");
        tell_room(ETP,"%^GREEN%^Geonslu, with a mighty roar drives herself into "+TPQCN+"!%^RESET%^",TP);
        TP->set_paralyzed(5,"%^BOLD%^You're still reeling from the dragon's blow!%^RESET%^");
        kill_ob(TP,1);
        return;
    }

    if(TP == present("horse"))
    {
        tell_room(ETO,"%^BOLD%^%^GREEN%^The dragon picks the horse up in her mouth and shakes "
            "it violently breaking its neck.");
        TP->die(TO);
    }
    ETO->set_property("no pocket space",1);
    add_action("steal","steal");
}

int steal(string str)
{
    string who,what;
    if(!str) return 0;
    if(sscanf(str,"%s from %s",what,who) != 2) return 0;
    if(!id(who)) return 0;
    SAVE_D->set_value("emerald_revenge",TP->query_name());
    tell_object(TP,"%^GREEN%^I will extract revenge.\n");
    return 0;
}

void home()
{
    if(query_attackers() == ({}))
    if(base_name(ETO) != HOMEROOM)
    {
        tell_room(ETO,"%^GREEN%^Geonslu lifts into the air and heads home.%^RESET%^");
        move(HOMEROOM);
    }
}

void get_um()
{
    int i,j,k = 0;
    object ob;

    if(query_attackers() != ({})) return;

    j = sizeof(revenge = SAVE_D->query_array("emerald_revenge"));

    for(i=0;i<j;i++)
    {
        if (objectp(ob = find_player(revenge[i]))) 
        {
            if (environment(ob)->query_property("indoors")) { continue; } 
            else 
            {
                k = i+1;
                break;
            }
        }
    }
    if(!k)
    {
        doing = 0;
        return;
    }

    message("combat","%^BOLD%^%^GREEN%^The dragon awakes as she searches for revenge.%^RESET%^",users());
    call_out("headin",5,revenge[k-1],environment(find_player(revenge[k-1])));

    //set_wimpy(25);
}

void break_um() 
{
    if(!random(3))
    new("/cmds/spells/d/_dispel_magic")->use_spell(TO,0,TO->query_guild_level("mage"),200,"mage");
}


void headin(string who, object waswhere) 
{
    object ob;

    if(query_attackers() != ({})) return;
    
    if(!objectp(ob = find_player(who)))
    {
        doing = 0;
        return;
    }

    tell_room(environment(ob),"%^BOLD%^%^GREEN%^The beating of wings draws close to you.");
    
    if(environment(ob)->query_property("indoors")) 
    {
        tell_room(waswhere,"%^BOLD%^%^GREEN%^The beating of wings receeds off into the distance...");
        doing = 0;
        return;
    }
    
    tell_room(environment(ob),"%^BOLD%^%^GREEN%^Geonslu lands before you, angry as hell itself, and "
        "screeches:%^RESET%^ RETURN TO ME WHAT IS MINE!");
    move(environment(ob));
    doing = 0;
    tell_object(ob,"%^GREEN%^Geonslu raises with a mighty roar and lashes out at you.%^RESET%^\n");
    tell_room(environment(ob),"%^GREEN%^Geonslu, with a mighty roar drives herself into "+TPQCN+"!%^RESET%^",ob);
    ob->set_paralyzed(5,"%^BOLD%^You're still reeling from the dragon's blow!%^RESET%^");
    kill_ob(ob,1);
    call_out("break_um",0);
    call_out("break_um",3);
}

string *query_revenge() { return (string *)SAVE_D->query_array("emerald_revenge"); }

void add_revenge(string str) { SAVE_D->set_value("emerald_revenge", str); return; }

void die(object obj)
{
    int i,j;
    object ob;
    revenge = TO->query_attackers() + TO->query_hunted();

    if(revenge != ({}))
    {
        j = sizeof(revenge);
        for(i=0;i<j;i++)
        {
            if(objectp(ob = find_player(revenge[i])))
            {
                if(ob->query_highest_level() > 15)
                {
                    tell_object(ob,"You have helped to silence the voice of the volcano.");
                    ob->set_mini_quest("Silence the volcano voice\n",1000000,"Silence the volcano voice\n");
                }
            }
        }
    }
    
    for(i=0;sizeof(bait),i<sizeof(bait);i++)
    {
        if(!objectp(bait[i])) { continue; }
        j = bait[i]->query_property("emerald_dragon_bait");
        if(j) { bait[i]->add_attack_bonus(-1 * j); }
    }

    SAVE_D->remove_array("emerald_revenge");
    message("combat","%^BOLD%^%^GREEN%^The dragon's rage is silenced...for now.%^RESET%^",users());
    
    ob = find_object_or_load(HOMEROOM);
    if(objectp(ob)) { ob->set_had_players(6*4); }
    
    ::die(obj);
}

int test_heart() { return 1; }

void receive_given_item(object obj)
{
    object item;
    string location;
    if(!objectp(obj)) return;
    location = base_name(ETO);

    if(location == HOMEROOM || location == "/d/islands/tonerra/mountain/mount63") 
    {
        if(base_name(obj) == "/d/islands/tonerra/obj/powergem") 
        {
            tell_room(ETO,"%^BOLD%^%^GREEN%^The two gemstones flare brightly upon contact and "
                "merge into one!%^RESET%^");
            obj->move("/d/shadowgate/void");
        obj->remove();
        }
        return;
    }

    if(base_name(obj) == "/d/islands/tonerra/obj/powergem" && !avatarp(TP)) 
    {
        tell_room(ETO,"%^BOLD%^%^GREEN%^Geonslu's attentions are drawn abruptly to the "
            "gem before her, her rage forgotten.  She takes it between two claws, holding "
            "it almost tenderly, as she raises it to eye level.%^RESET%^");
        tell_room(ETO,"%^RESET%^%^GREEN%^A flash of anger returns to her fearsome gaze as "
            "she looks back upon you, and her hissing words seem to vibrate upon the "
            "air:%^RESET%^ Take what is mine ever again, and I will not be so merciful.");
        tell_room(ETO,"%^BOLD%^%^GREEN%^She lifts her head, and a single flap of her mighty "
            "wings draws her aloft.%^RESET%^");
        message("combat","%^BOLD%^%^GREEN%^The dragon returns to her lair, her rage abated.%^RESET%^",users());
        TO->move(HOMEROOM);
        SAVE_D->remove_array("emerald_revenge");
    }
}

void notice_death(object whom) {remove_attacker(whom); return;}