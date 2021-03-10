/*
  _bane.c

  Inquisitor feat from PF SRD.
  Temporarily buffs your weapon against a specific enemy type.

  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>
#include <dirs.h>
#include <favored_types.h>

inherit FEAT;

object weapon, feat;
string *valid_choices;

void create()
{
    ::create();

    valid_choices = keys(VALID_ENEMY);

    set_author("tlaloc");
    feat_type("instant");
    feat_category("Inquisition");
    feat_name("bane");
    feat_prereq("Inquisitor L5");
    feat_syntax("bane [TYPE]");
    feat_desc("This feat allows the inquisitor to infuse the weapon in their main " +
"hand with divine power that targets a specific type of enemy. This infusion has a " +
"chance to do divine damage, based on weapon dice. The chance of this bane hitting and the " +
"damage done increases with your Inquisitor levels. Additionally, your weapon gets an additional +2 " +
"attack and +2 damage bonuses against the selected type.\n " +
              "%^BOLD%^You can select from the following bane enemy types: \n\n" + implode(map(valid_choices, (:" " + $1:)), "\n"));
    set_target_required(0);
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob)) {
        return 0;
    }
    if(ob->query_class_level("inquisitor") < 5)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_bane(string str)
{
    if(!this_player())
        return 0;

    feat = new(base_name(this_object()));
    feat->setup_feat(this_player(), str);
    return 1;
}

void execute_feat()
{
    string type;
    mapping info;
    int timer, glvl;

    ::execute_feat();

    if(!caster)
        return;

    if(caster->query_property("using instant feat"))
    {
        write("You are already in the middle of using a feat!");
        return;
    }

    /*
    if(caster->query_current_attacker())
    {
        write("You cannot infuse your weapon with a bane during combat.");
        return;
    }
    */

    if(!arg || member_array(arg, valid_choices) < 0)
    {
        write("Valid bane choices are : " + implode(valid_choices, ", "));
        return;
    }

    if(sizeof(caster->query_wielded()))
        weapon = caster->query_wielded()[0];

    if(!weapon)
    {
        write("You must be wielding a weapon in your main hand to use Bane.");
        return;
    }

    if(caster->query_property("bane weapon"))
    {
        write("Your weapon is already magically enhanced.");
        return;
    }

    write("%^BOLD%^You infuse your weapon with extra potency against %^CYAN%^" + arg + "%^RESET%^.");
    tell_room(environment(caster),"%^BOLD%^"+caster->QCN+" infuses their weapon with magical potency.", ({ caster }));

    weapon->set_property("added short", ({ "%^CYAN%^BOLD%^ [bane]%^RESET%^" }) );
    caster->set_property("using instant feat",1);
    caster->remove_property("bane weapon");
    caster->set_property("bane weapon", ({ weapon, arg }));

    glvl = caster->query_guild_level("inquisitor");
    timer = (5 + (glvl / 3)) * 8;

    call_out("dest_effect", timer);
}

void execute_attack()
{
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");
    ::execute_attack();
}


void dest_effect()
{
    caster && tell_object(caster, "%^BOLD%^You sense the magical bane fading from your weapon.%^RESET%^");
    caster && caster->remove_property("bane weapon");
    weapon && weapon->remove_property_value("added short", ({ "%^CYAN%^BOLD%^ [bane]%^RESET%^" }) );
    ::dest_effect();
    remove_feat(this_object());
    return;
}
