#include <std.h>
#include <daemons.h>
inherit FEAT;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("Presence");
    feat_name("channel smite");
    feat_prereq("Channel");
    feat_classes(({"paladin", "cleric"}));
    feat_desc("This power allows a divine caster to channel primal energies (divine) through their weapon, causing it to become infused with divine wrath, striking at their current attacker, causing divine damage. You must spend one Divine Grace point to use Channel Smite. The damage is based on your Channel dice. Note : This is not a free feat.");
    feat_syntax("channel_smite");
    set_target_required(0);
}

int allow_shifted()
{
    return 1;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    
    if(!FEATS_D->usable_feat(ob, "channel"))
    {
        dest_effect();
        return 0;
    }
    
    return ::prerequisites(ob);
}

int cmd_channel_smite(string str)
{
    object feat;
    
    if (!objectp(this_player()))
        return 0;
    
    feat = new(base_name(TO));
    feat->setup_feat(TP, "");
    return 1;
}

void execute_feat()
{
    object *weapons;

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    if ((int)caster->query_property("using instant feat")) {
        tell_object(caster, "You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    
    if(!caster->query_current_attacker())
    {
        tell_object(caster, "You are not fighting anyone!");
        return;
    }
    
    if(!(int)USER_D->spend_pool(TP, 1, "grace"))
    {
        tell_object(caster, "You don't have the Divine Grace to Channel Energy!");
        return;
    }

    /*    
    else if ((int)caster->query_property("using channel") > time() &&
        !FEATS_D->usable_feat(caster, "supreme healer")) {
        tell_object(caster, "It's too soon to use channel or channel smite!");
        dest_effect();
        return;
    }
    */

    ::execute_feat();

    tell_object(caster,"%^BOLD%^%^WHITE%^You waver unevenly as you prepare to channel primal energies through yourself.");
    tell_room(place,"%^BOLD%^%^WHITE%^Closes their eyes an look distant for a split second.",caster);

    caster->set_property("using instant feat",1);
    return;
}

void execute_attack()
{
    object attacker;
    string energy_type;
    string color;
    int dam;
    int i;

    if(!objectp(caster)) {
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");

    caster->remove_property("using channel");
    
    attacker = caster->query_current_attacker();
    
    if(!objectp(attacker))
    {
        dest_effect();
        return;
    }
    
    if(caster->query_class_level("cleric"))
    {
        caster->set_property("using channel",(time() + 35));

        if (!FEATS_D->usable_feat(caster, "supreme healer")) {
            delay_messid_msg(35, "%^BOLD%^%^WHITE%^You can %^CYAN%^channel%^WHITE%^ again.%^RESET%^");
        }
    }

    ::execute_attack();

    dam = flevel + (FEATS_D->usable_feat(caster, "improved channel") * 2);
    dam = roll_dice(dam, 6);

    //Evil channel negative energy
    if (caster->query_true_align() % 3 == 0) {
        //energy_type = "negative energy";
        color = "%^BLACK%^";
    } else {
        //energy_type = "positive energy";
        color = "%^WHITE%^";
    }
    
    energy_type = "divine";

    if(BONUS_D->process_hit(caster, attacker, 1, 0, 0, 0) <= 0)
        tell_room(ENV(caster), caster->QCN + " tries to strike + " + attacker->QCN + " with their divine-infused weapon but misses!");
    else
    {        
        tell_room(ENV(caster), "%^BOLD%^" + color + caster->QCN + " channels divine energy through " + caster->QP + " weapon and strikes " + attacker->QCN + "!", ({ attacker }));
        caster->execute_attack();
        attacker->cause_typed_damage(attacker, attacker->return_target_limb(), dam, energy_type);
        attacker && tell_object(attacker, "%^BOLD%^" + color + "You are struck with divine energy!");
    }

    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
