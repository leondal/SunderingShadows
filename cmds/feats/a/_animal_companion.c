/*
  _animal_companion.c
  
  Feat that allows a ranger to summon an animal
  companion.
  
  -- Tlaloc -- 2.18.20
*/

#include <std.h>
#include <daemons.h>
#include <magic.h>

#define BEAST_MOD 2

inherit FEAT;

//Format - type : ({ STR, DEX, CON, INT, WIS, CHA, SIZE, AC BONUS, }),
mapping valid_types = ([ 
                         "ape" :       ({ 13, 17, 10, 2, 12, 7, 3, 2,  }),
                         "badger" :    ({ 10, 17, 15, 2, 12, 10, 2, 4, }),
                         "bear" :      ({ 15, 15, 13, 2, 12, 6, 3, 4,  }),
                         "bird" :      ({ 15, 15, 13, 2, 14, 6, 1, 2,  }),
                         "boar" :      ({ 13, 12, 15, 2, 13, 4, 2, 12, }),
                         "camel" :     ({ 18, 16, 14, 2, 11, 4, 3, 2,  }),
                         "cheetah" :   ({ 12, 21, 13, 2, 12, 6, 2, 2,  }),
                         "crocodile" : ({ 15, 14, 15, 1, 12, 2, 2, 8,  }),
                         "dinosaur" :  ({ 11, 17, 17, 2, 12, 14, 2, 2, }),
                         "dog" :       ({ 13, 17, 15, 2, 12, 6, 2, 4,  }),
                         "horse" :     ({ 16, 13, 15, 2, 12, 6, 3, 8,  }),
                         "lion" :      ({ 13, 17, 13, 2, 15, 10, 3, 2, }),
                         "snake" :     ({ 15, 17, 13, 1, 12, 2, 3, 4,  }),
                         "wolf" :      ({ 13, 15, 15, 2, 12, 6, 2, 4,  }),
                       ]);

object companion, pack_animal, *pack = ({  });

void create()
{
    ::create();
    feat_type("instant");
    feat_category("SavageCombat");
    feat_name("animal companion");
    feat_prereq("Ranger L4");
    feat_syntax("animal_companion [TYPE] to summon or animal_companion to dismiss");
    feat_desc("Summons or dismisses your faithful animal companion. This companion will follow you through thick and thin, will level up with you, and gains several perks as it grows. The TYPE of animal will determine its base stats and natural armor.  The animal companion gains its own feats as follows:

  LEVEL  3 - Evasion
  LEVEL  6 - Resistance
  LEVEL  9 - Precise Strikes
  LEVEL 15 - Stalwart
  
The Animal Companion will hide if you use the 'hide_in_shadows' command, allowing you to effectively sneak about with your faithful friend.

The Animal Companion can also be customized through several commands, which will allow you to change its description:

  'animal short [DESCRIPTION]' - Changes the short description of the companion.
  'animal long  [DESCRIPTION]' - Changes the long description of the companion.

  To have the animal companion follow you, use 'animal follow'.  
  To command the animal companion, use %^ORANGE%^<animal command %^ULINE%^ACTION%^RESET%^ORANGE%^>.%^RESET%^");
  
    set_target_required(0);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob))
        return 0;
    
    if(ob->query_class_level("ranger") < 4)
    {
        dest_effect();
        return 0;
    }
   
    return ::prerequisites(ob);
}

int cmd_animal_companion(string str)
{
    object feat;
    
    if(!objectp(this_player()))
        return 0;
    
    feat = new(base_name(this_object()));
    feat->setup_feat(this_player(), str);
    
    return 1;
}

void execute_feat()
{
    object ob;
    
    int class_level,
        comp_hd,
        comp_ac;
    
    ::execute_feat();
    
    if(caster->query_property("using instant feat"))
    {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }

    
    if(sizeof(caster->query_attackers()))
    {
        tell_object(caster, "You can't summon your animal companion during combat!");
        return;
    }
    
    
    companion = caster->query_property("animal_companion");
    pack = caster->query_protectors();
    pack = filter_array(pack, (: $1->query_pack_member() :));
    
    if(objectp(companion) || sizeof(pack))
    {
        companion && tell_object(caster, "You dismiss your animal companion.");
        caster->remove_property("animal_companion");
        companion && companion->remove();
        
        if(sizeof(pack))
        {
            foreach(object obj in pack)
            {
                tell_object(caster, "You dismiss your pack member.");
                //pack -= ({ obj });
                obj && obj->remove();
                //Trying to get rid of sticky animals
                if(objectp(obj))
                    destruct(obj);
            }
            
            pack = ({  });
        }
                
        return;
    }
    
    pack = ({  });
    
    if(!arg || member_array(arg, keys(valid_types)) < 0)
    {
        tell_object(caster, "That is not a valid choice for your animal companion.");
        tell_object(caster, "Valid options are: (" + implode(m_indices(valid_types), ",") + ") ");
        return;
    }
    
    tell_object(caster, sprintf("You summon your trusty %s companion%s to your side.", arg, caster->query_chosen_animal() == arg ? "s" : ""));
    
    class_level = caster->query_guild_level("ranger");
    comp_hd = class_level + 2;
    comp_ac = class_level + 10;
    
    companion = new("/d/magic/mon/acompanion");
    companion->set_race(arg);
    companion->set_name(arg);
    companion->set_id( ({ arg, "companion", "animal companion", "greater summon", "animal", caster->query_name() + "'s ally" }) );
    companion->set_short(sprintf("%s's faithful %s companion.",capitalize(caster->query_name()),arg));
    companion->set_level(class_level);
    companion->set_hd(comp_hd, 14);
    companion->set_attacks_num(2 + class_level / 8);
    companion->set_mlevel("fighter", comp_hd);
    companion->set_max_hp(14 + (14 * comp_hd));
    companion->set_hp(14 * comp_hd + 14);
    companion->set_alignment(caster->query_alignment());
    companion->set_owner(caster);
       
    caster->set_property("animal_companion", companion);
    caster->add_follower(companion);
    caster->add_protector(companion);

    companion->set_property("minion", caster);
    companion->move(environment(caster));
    companion->set_heart_beat(1);
    
    //Setting companion stats based on type per SRD
    companion->set_stats("strength", valid_types[arg][0] + min( ({ class_level / 5, 6 }) ) );
    companion->set_stats("dexterity", valid_types[arg][1] + min( ({ class_level / 5, 6 }) ) );
    companion->set_stats("constitution", valid_types[arg][2]);
    companion->set_stats("intelligence", valid_types[arg][3]);
    companion->set_stats("wisdom", valid_types[arg][4]);
    companion->set_stats("charisma", valid_types[arg][5]);
    companion->set_size(valid_types[arg][6]);
    companion->set_overall_ac(0 - comp_ac - valid_types[arg][7]);
  
    //Based on SRD - companion gets "specials" at certain caster levels
    if(class_level >= 3)
        companion->set_monster_feats( ({ "evasion" }) );
    if(class_level >= 6)
        companion->set_monster_feats( ({ "evasion", "resistance" }) );
    if(class_level >= 9)
        companion->set_monster_feats( ({ "evasion", "resistance", "precise strikes" }) );
    if(class_level >= 15)
        companion->set_monster_feats( ({ "evasion", "resistance", "precise strikes", "stalwart" }) );
    
    if(caster->query_chosen_animal() == arg)
    {
        //Chosen animal greatly buffs the animal companion
        if(FEATS_D->usable_feat(caster, "chosen animal"))
        {
            companion->set_property("damage_resistance", 10);
            companion->set_monster_feats( ({ "toughness", "improved toughness", "evasion", "resistance", "precise strikes", "stalwart", "rapid strikes" }) );
        }
    
        if(FEATS_D->usable_feat(caster, "pack leader"))
        {
            for(int x = 0; x < BEAST_MOD; x++)
            {
                pack_animal = new("/d/magic/mon/pack_member");
                pack_animal->set_race(arg);
                pack_animal->set_name(arg);
                pack_animal->set_id( ({ arg, "pack animal", "greater summon", "animal", "pack member", caster->query_name() + "'s ally" }) );
                pack_animal->set_short("%^BOLD%^GREEN%^" + caster->QCN + "'s faithful %^BLACK%^" + arg + "%^RESET%^BOLD%^GREEN%^ pack member");
                //pack_animal->set_short(sprintf("%s's faithful %s pack member",capitalize(caster->query_name()),arg));
                pack_animal->set_level(class_level);
                pack_animal->set_hd(comp_hd, 14);
                pack_animal->set_attacks_num(2 + class_level / 8);
                pack_animal->set_mlevel("fighter", comp_hd);
                pack_animal->set_max_hp(14 + (14 * comp_hd));
                pack_animal->set_hp(14 * comp_hd + 14);
                pack_animal->set_alignment(caster->query_alignment());
                pack_animal->set_owner(caster);
                pack_animal->set_property("damage_resistance", 10);
       
                caster->add_follower(pack_animal);
                caster->add_protector(pack_animal);

                pack_animal->set_property("minion", caster);
                pack_animal->move(environment(caster));
                pack_animal->set_heart_beat(1);
    
                //Setting companion stats based on type per SRD
                pack_animal->set_stats("strength", valid_types[arg][0] + min( ({ class_level / 5, 6 }) ) );
                pack_animal->set_stats("dexterity", valid_types[arg][1] + min( ({ class_level / 5, 6 }) ) );
                pack_animal->set_stats("constitution", valid_types[arg][2]);
                pack_animal->set_stats("intelligence", valid_types[arg][3]);
                pack_animal->set_stats("wisdom", valid_types[arg][4]);
                pack_animal->set_stats("charisma", valid_types[arg][5]);
                pack_animal->set_size(valid_types[arg][6]);
                pack_animal->set_overall_ac(0 - comp_ac - valid_types[arg][7]);
                
                //Based on SRD - companion gets "specials" at certain caster levels
                if(class_level >= 3)
                    pack_animal->set_monster_feats( ({ "evasion" }) );
                if(class_level >= 6)
                    pack_animal->set_monster_feats( ({ "evasion", "resistance" }) );
                if(class_level >= 9)
                    pack_animal->set_monster_feats( ({ "evasion", "resistance", "precise strikes" }) );
                if(class_level >= 15)
                    pack_animal->set_monster_feats( ({ "evasion", "resistance", "precise strikes", "stalwart" }) );
            }
        }
    }
       
    return;
}

void dest_effect()
{
    remove_feat(this_object());
    ::dest_effect();
    return;
}