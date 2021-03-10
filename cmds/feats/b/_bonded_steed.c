/*
  _bonded_steed.c
  
  Feat that allows a paladin to summon a bonded steed
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit FEAT;

object companion;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("DivineBond");
    feat_name("bonded steed");
    feat_prereq("Paladin L5");
    feat_syntax("bonded_steed to summon or bonded_steed to dismiss");
    feat_desc("Summons or dismisses the paladin's faithful bonded steed. The steed will be loyal only to its owner and can be ridden, like any other mount, with the 'mount' command.

The Bonded Steed can also be customized through several commands, which will allow you to change its description:

  'steed short [DESCRIPTION]' - Changes the short description of the steed.
  'steed long  [DESCRIPTION]' - Changes the long description of the steed.

  To have the bonded steed follow you, use 'steed follow'.  
  To command the bonded steed, use %^ORANGE%^<steed command %^ULINE%^ACTION%^RESET%^ORANGE%^>.%^RESET%^

This feat costs one Divine Grace point.
 
N.B. This is a divine feat, use <feats divinebond bonded steed> to gain the feat. ");

    set_target_required(0);
}

int prerequisites(object ob)
{
    if(!objectp(ob))
        return 0;
    
    if(ob->query_class_level("paladin") < 5)
    {
        dest_effect();
        return 0;
    }
   
    return ::prerequisites(ob);
}

int cmd_bonded_steed(string str)
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
        tell_object(caster, "You can't summon your bonded steed during combat!");
        return;
    }
    
    if(!(int)USER_D->spend_pool(TP, 1, "grace"))
    {
        tell_object(caster, "You don't have the Divine Grace to summon your steed!");
        return;
    }
    
    companion = caster->query_property("animal_companion");
    
    if(objectp(companion))
    {
        companion && tell_object(caster, "You dismiss your bonded steed.");
        caster->remove_property("animal_companion");
        companion && companion->remove();
                
        return;
    }
    
    tell_object(caster, sprintf("You summon your trusty steed to your side."));
    
    class_level = caster->query_guild_level("paladin");
    comp_hd = class_level + 2;
    comp_ac = class_level + 10;
    
    companion = new("/d/magic/mon/bonded_steed");
    companion->set_race("horse");
    companion->set_name("steed");
    companion->set_id( ({ "steed", "bonded steed", "greater summon", "animal", caster->query_name() + "'s ally" }) );
    companion->set_short(sprintf("%s's faithful bonded steed.",capitalize(caster->query_name())));
    companion->set_level(class_level);
    companion->set_hd(comp_hd, 14);
    companion->set_attacks_num(2 + class_level / 10);
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
    companion->set_stats("strength", 16);
    companion->set_stats("dexterity", 12);
    companion->set_stats("constitution", 18);
    companion->set_stats("intelligence", 6);
    companion->set_stats("wisdom", 8);
    companion->set_stats("charisma", 14);
    companion->set_size(3);
    companion->set_property("spell resistance", class_level);
    companion->set_overall_ac(0 - comp_ac - 10);
    
    caster->force_me("mount bonded steed");
       
    return;
}

void dest_effect()
{
    remove_feat(this_object());
    ::dest_effect();
    return;
}