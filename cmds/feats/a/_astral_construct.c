/*
  _astral_construct.c
  
  Feat that allows a shaper to summon an astral construct
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit FEAT;

object companion;

string *valid_args = ({ "toughness", "cleave", "resistance", "mobility", "regeneration", "damage resistance", "rapid strikes" });

void create()
{
    ::create();
    feat_type("instant");
    feat_category("Psionics");
    feat_name("astral construct");
    psionic(1);
    feat_prereq("Psion (Shaper) L2");
    feat_syntax("astral_construct [FEAT] to summon or astral_construct to dismiss");
    feat_desc("This feat showcases the shaper's ability to realize their imagination through astral materials by building an astral construct to fight alongside them.

The [FEAT] argument will let you add one of the following feats to your construct:

  %^BOLD%^" + upper_case(implode(valid_args, "\n\  ")) + "%^RESET%^
  
The Astral Construct can be customized through several commands, which will allow you to change its description:

  'construct short [DESCRIPTION]' - Changes construct's short description.
  'construct long  [DESCRIPTION]' - Changes construct's long description.

  To have the astral construct follow you, use 'construct follow'.  
  To command the astral construct, use %^ORANGE%^<construct command %^ULINE%^ACTION%^RESET%^ORANGE%^>.%^RESET%^

This feat requires the shaper to be focused and expends Psionic Focus upon use.");

    set_target_required(0);
}

int prerequisites(object ob)
{
    if(!objectp(ob))
        return 0;
    
    if(ob->query_class_level("psion") < 2)
    {
        dest_effect();
        return 0;
    }
    
    if(ob->query_discipline() != "shaper")
    {
        dest_effect();
        return 0;
    }
   
    return ::prerequisites(ob);
}

int cmd_astral_construct(string str)
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
    int bonus,
        class_level,
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
        tell_object(caster, "You can't build your astral construct during combat!");
        return;
    }
    
    companion = caster->query_property("animal_companion");
    
    if(objectp(companion))
    {
        companion && tell_object(caster, "You dismiss your astral construct.");
        caster->remove_property("animal_companion");
        companion && companion->remove();
                
        return;
    }
    
    if(!arg || member_array(arg, valid_args) < 0)
    {
        tell_object(caster, "You need to choose a feat for your astral construct.");
        tell_object(caster, "Valid options are: (" + implode(valid_args, ",") + ") ");
        return;
    }

    if(!(int)USER_D->spend_pool(TP, 1, "focus"))
    {
        tell_object(caster, "You don't have the Psionic Focus to build your construct!");
        return;
    }
    
    tell_object(caster, "%^CYAN%^BOLD%^You twirl your fingers, weaving ectoplasmic material from the Astral plane.%^RESET%^");
    tell_object(caster, "%^BOLD%^You rearange the fibers, pulling and place them into the proper order, until finally, an astral construct stands before you.");

    bonus = FEATS_D->usable_feat(caster, "summoners call") * 5;    
    class_level = caster->query_prestige_level("psion") + bonus;

    comp_hd = class_level + 2;
    comp_ac = class_level + 10;
    
    companion = new("/d/magic/mon/astral_construct");
    companion->set_race("construct");
    companion->set_name("construct");
    companion->set_id( ({ "construct", "astral construct", "greater summon", caster->query_name() + "'s ally" }) );
    companion->set_short("%^BOLD%^%^CYAN%^Astral Construct%^RESET%^");
    companion->set_level(class_level);
    companion->set_hd(comp_hd, 14);
    companion->set_attacks_num(2 + class_level / 10);
    companion->set_mlevel("fighter", comp_hd);
    companion->set_max_hp(14 + (14 * comp_hd));
    companion->set_hp(14 * comp_hd + 14);
    companion->set_alignment(caster->query_alignment());
    companion->set_owner(caster);
    companion->set_property("effective_enchantment", (class_level / 7) + 1);
    companion->set_attacks_num(class_level / 13 + 1);
    companion->set_monster_feats( ({ arg }) );
       
    caster->set_property("animal_companion", companion);
    caster->add_follower(companion);
    caster->add_protector(companion);

    companion->set_property("minion", caster);
    companion->move(environment(caster));
    companion->set_heart_beat(1);
    
    //Setting companion stats based on type per SRD
    companion->set_stats("strength", 16);
    companion->set_stats("dexterity", 14);
    companion->set_stats("constitution", 18);
    companion->set_stats("intelligence", 6);
    companion->set_stats("wisdom", 8);
    companion->set_stats("charisma", 10);
    companion->set_size(3);
    companion->set_property("spell damage resistance", class_level);
    companion->set_overall_ac(0 - comp_ac - 10);
       
    return;
}

void dest_effect()
{
    remove_feat(this_object());
    ::dest_effect();
    return;
}