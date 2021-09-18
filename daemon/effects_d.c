//ACTIVELY USED

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int spell_effect(object caster, object device, string command)
{
    string spell, who, cspell, stype;
    int level;
    object target, obj;

    spell = device->query("spell");
    level = device->query("level");
    cspell = "/cmds/spells/" + spell[0..0] + "/_" + replace_string(spell, " ", "_");
    stype = device->query("spell type");
    if (!stype) {
        stype = "mage";
    }

    if (!file_exists(cspell + ".c")) {
        write("%^BOLD%^ERROR unknown spell specified " + cspell + ".\n");
        error("ERROR unknown spell specified " + cspell);
        return 0;
    }

    if (command) {
        if (sscanf(command, "on %s", who) != 1) {
            return notify_fail("use <object> on <target>\n");
        }
    }else {
        who = caster->query_name();
    }
    
    if(!can_use_check(caster, spell, level))
        return notify_fail("You fail to get the item working.\n");

    /* if (!(target = present(who, environment(caster)))) { */
    /*     return notify_fail("No such target.\n"); */
    /* } */
    obj = new(cspell);
    caster->set_property("spell_casting", obj);
    obj->use_spell(caster, who, level, 100, stype);
    return 1;
}

int can_use_check(object caster, string spell, int level)
{
    int valid, lowest_spell_level, highest_mental_stat, rogue_clevel, roll1, DC;
    string *player_classes, *valid_classes;
    
    if(!caster || !spell)
        return 0;
    
    valid = 0;

    player_classes = caster->query_classes();
    valid_classes = keys(MAGIC_D->query_index_row(spell)["levels"]);
    lowest_spell_level = min(values(MAGIC_D->query_index_row(spell)["levels"]));
    highest_mental_stat = max(({caster->query_stats("intelligence"), caster->query_stats("wisdom"), caster->query_stats("charisma") })) - 10;
    
    foreach(string cls in player_classes)
    {
        string temp;
        
        temp = cls;
        
        if(temp == "sorcerer")
            temp = "mage";
        
        if(temp == "oracle")
            temp = "cleric";
        
        if(member_array(cls, valid_classes) >= 0)
            valid = 1;
    }
    
    if(lowest_spell_level > this_player()->query_level() / 2)
        valid = 0;
    
    if(!valid)
    {   
        //Thieves and bards can use a different roll based on thief level
        rogue_clevel = this_player()->query_prestige_level("thief") + this_player()->query_prestige_level("bard");
        
        if(FEATS_D->usable_feat(caster, "use magic device") && rogue_clevel > caster->query_skill("spellcraft"))
        {
            roll1 = roll_dice(1, 20);
            DC = level + lowest_spell_level;

            //rogue_clevel = this_player()->query_prestige_level("thief") + this_player()->query_prestige_level("bard");
            
            if(rogue_clevel / 2 < lowest_spell_level)
            {
                tell_object(caster, "The item's spell is too complex to use.");
                return 0;
            }
            
            if(this_player()->is_class("bard"))
                rogue_clevel += BONUS_D->query_stat_bonus(this_player(), "charisma");
            else
                rogue_clevel += BONUS_D->query_stat_bonus(this_player(), "intelligence");
            
            roll1 += rogue_clevel;
            
            if((roll1 < DC || roll1 == 1) && roll1 != 20)
                return 0;
        }
        //Other users have to pass a check to try to cast off-class. Kind of difficult, for a reason.
        else if(highest_mental_stat < lowest_spell_level)
        {
            if(caster->query_skill("spellcraft") < level)
                return 0;
            
            DC = 20 + lowest_spell_level;
            roll1 = roll_dice(1, 20) + (highest_mental_stat / 2) + (caster->query_skill("spellcraft") / 10);
            
            if((roll1 < DC || roll1 == 1) && roll1 != 20)
                return 0;
        }
        tell_object(caster, "You manage to figure out how to use the wand.");
        return 1;
    }
    
    return 1;
}
