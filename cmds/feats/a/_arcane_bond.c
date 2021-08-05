/*
  _arcane_bond.c
  
  Feat that allows a mage to summon a familiar.
  
  -- Tlaloc -- 8.5.21
*/

#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit FEAT;
//Familiar helps with touch attacks, similar to spectral hand
//Format - type : ({ STR, DEX, CON, INT, WIS, CHA, SIZE, AC BONUS, }),
mapping valid_types = ([ 
                         "fox"           :    ({  9, 15, 14, 2, 12,  6, 1, 14,  }), //+2 Reflex Save
                         "armadillo"     :    ({  4, 15, 11, 2, 12,  9, 1, 16,  }), //+1 Natural Armor
                         "cat"           :    ({  3, 15,  8, 2, 12,  7, 1, 14,  }), //+3 Stealth
                         "goat"          :    ({ 12, 13, 12, 2, 11,  5, 1, 13,  }), //+3 Survival
                         "lemming"       :    ({  1, 12,  6, 2, 13,  4, 1, 15,  }), //+2 Fort Save
                         "monkey"        :    ({  3, 15, 10, 2, 12,  5, 1, 14,  }), //+3 Athletics
                         "owl"           :    ({  6, 17, 11, 2, 15,  6, 1, 15,  }), //+3 Perception
                         "raccoon"       :    ({  8, 15, 11, 2, 16,  5, 1, 15,  }), //+3 Thievery
                         "hedgehog"      :    ({  1, 16,  6, 2, 12,  7, 1, 18,  }), //+2 Will Save
                         "peacock"       :    ({  7, 12, 10, 2,  6, 13, 1, 12,  }), //+3 Influence
                       ]);

object companion;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("ArcaneSpellcraft");
    feat_name("arcane_bond");
    feat_prereq("Mage L1");
    feat_syntax("arcane_bond [TYPE] to summon or arcane_bond to dismiss");
    feat_desc("Summons or dismisses your trusty familiar. This familiar will follow you through thick and thin and will level up with you. The TYPE of familiar will determine its base stats and natural armor.  The familiar can also assist with touch attack spells, much like spectral hand. The familiar is a non-combat companion, and won't fight or protect you in combat.

The available familiars are as follows, along with their passive benefits:
%^CYAN%^BOLD%^ Armadillo %^RESET%^: +1 Natural Armor
%^CYAN%^BOLD%^ Cat       %^RESET%^: +3 Stealth
%^CYAN%^BOLD%^ Fox       %^RESET%^: +2 Reflex Save
%^CYAN%^BOLD%^ Goat      %^RESET%^: +3 Survival
%^CYAN%^BOLD%^ Hedgehog  %^RESET%^: +2 Will Save
%^CYAN%^BOLD%^ Lemming   %^RESET%^: +2 Fortitude Save
%^CYAN%^BOLD%^ Monkey    %^RESET%^: +3 Athletics
%^CYAN%^BOLD%^ Owl       %^RESET%^: +3 Perception
%^CYAN%^BOLD%^ Peacock   %^RESET%^: +3 Influence
%^CYAN%^BOLD%^ Raccoon   %^RESET%^: +3 Thievery

The Familiar will hide if you use the 'hide_in_shadows' command, allowing you to effectively sneak about with your faithful friend. It will also go invisible with you.

The Familiar can also be customized through several commands, which will allow you to change its description:

%^ORANGE%^<familiar short [DESCRIPTION]>%^RESET%^ - Changes the short description of the familiar.
%^ORANGE%^<familiar long  [DESCRIPTION]>%^RESET%^ - Changes the long description of the familiar.

  To have the familiar follow you, use 'familiar follow'.  
  To command the familiar, use %^ORANGE%^<familiar command %^ULINE%^ACTION%^RESET%^ORANGE%^>.%^RESET%^");
  
    set_target_required(0);
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob))
        return 0;
    
    if(ob->query_class_level("mage") < 1)
    {
        dest_effect();
        return 0;
    }
   
    return ::prerequisites(ob);
}

int cmd_arcane_bond(string str)
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
        tell_object(caster, "You can't summon your familiar during combat!");
        return;
    }
    
    
    companion = caster->query_property("familiar");
    
    if(objectp(companion))
    {
        companion && tell_object(caster, "You dismiss your familiar.");
        caster->remove_property("familiar");
        companion && companion->remove();               
        return;
    }
    
    
    if(!arg || member_array(arg, keys(valid_types)) < 0)
    {
        tell_object(caster, "That is not a valid choice for familiar.");
        tell_object(caster, "Valid options are: (" + implode(m_indices(valid_types), ",") + ") ");
        return;
    }
    
    tell_object(caster, sprintf("You summon your trusty %s familiar to your side.", arg));
    
    class_level = caster->query_prestige_level("mage");
    
    comp_hd = class_level + 2;
    comp_ac = class_level + 10;
    
    companion = new("/d/magic/mon/familiar");
    companion->set_race(arg);
    companion->set_name(arg);
    companion->set_id( ({ arg, "familiar", caster->query_name() + "'s familiar" }) );
    companion->set_short(sprintf("%s's faithful %s familiar.",capitalize(caster->query_name()),arg));
    companion->set_level(class_level);
    companion->set_hd(comp_hd, 14);
    companion->set_attacks_num(2 + class_level / 8);
    companion->set_mlevel("fighter", comp_hd);
    companion->set_max_hp(14 + (14 * comp_hd));
    companion->set_hp(14 * comp_hd + 14);
    companion->set_alignment(caster->query_alignment());
    companion->set_owner(caster);
       
    caster->set_property("familiar", companion);
    caster->add_follower(companion);
    //caster->add_protector(companion);

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
       
    return;
}

void dest_effect()
{
    remove_feat(this_object());
    ::dest_effect();
    return;
}