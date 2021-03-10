#include <std.h>

inherit OBJECT;

#define SCRY_D "/daemon/ic_scry_locate_d"


object target,scry_control,*drainees=({});
int hunger,step;

void dest_effect();

void create()
{
    ::create();

    set_name("orb of scrying");

    set_id(({ "orb", "scrying orb","orb of scrying","crystal ball","ball" }));

    set_short("%^RESET%^orb %^MAGENTA%^of %^CYAN%^s%^RESET%^c%^BOLD%^r%^CYAN%^ying%^RESET%^");

    set_obvious_short("%^CYAN%^a hazy crystal ball%^RESET%^");

    set_long("%^CYAN%^This fist sized ball looks to be made from fragile glass but "
        "a surprising aura of strength radiates outwards from it.  A glowing blue mist "
        "swirls inside of the orb and murky shapes can almost be made out in its depths.%^RESET%^");

    set_weight(5);

    set_value(12000);

    set_lore("%^BOLD%^Adventurers first reported seeing these orbs in the forests north of "
        "Asgard.  Since those initial reports, more of the orbs have been located throughout "
        "the realms.  The first adventurers who found the orbs met their untimely end by abusing "
        "the orbs power.  The tales say that one might %^MAGENTA%^gaze%^RESET%^%^BOLD%^ into the orb "
        "and see events at a distance.  But the stories also say that doing so begins a drain on a person's "
        "soul.  The longer a person watches the images inside the orb, the more deadly the drain becomes.  "
        "One must be careful to %^MAGENTA%^stop%^RESET%^%^BOLD%^ before the drain becomes too great.%^RESET%^");

    set_property("lore difficulty",20);

    set_heart_beat(4);
}

void init()
{
    ::init();
    add_action("lookin","gaze");
    add_action("stop_scrying","stop");
}

int lookin(string str)
{
    string *map_keys,real;
    int i,matches,num,duration,power,cost;
    mapping map;
    if(ETO->query_property("scrying_orb_drain"))
    {
      notify_fail("You are already using a scrying device.\n");
      return 0;
    }
    if(!objectp(TO)) { return 0; }
    if(!objectp(ETO)) { return 0; }
    if(living(ETO))
    {
        if(!objectp(EETO)) { return 0; }
    }

    if(!ETO->is_player()) { return 0; }

    if(!str)
    {
        notify_fail("What?\n");
        return 0;
    }

    target = lower_case(str);

    if(!stringp(real = (string)ETO->realNameVsProfile(target)))
    {
        tell_object(ETO,"%^CYAN%^The mist inside of the orb shifts for a moment but then "
            "nothing happens.%^RESET%^");
        return 1;
    }

    target = find_player(real);

    if(!target || target->query_true_invis())
    {
        tell_object(ETO,"%^CYAN%^The mist inside of the orb shifts for a moment but then "
            "nothing happens.%^RESET%^");
        return 1;
    }

    if(target == TP)
    {
        tell_object(ETO,"%^CYAN%^An image of yourself peers back at you for an instant and "
            "then it is gone!%^RESET%^");
        return 1;
    }

    if(target->query_property("no scry"))
    {
        tell_object(ETO,"%^GREEN%^The mist inside of the orb takes on a sickly green glow and suddenly "
            "the orb flashes a bright light before returning to normal!%^RESET%^");
        return 1;
    }

    tell_object(ETO,"%^CYAN%^As you stare into the orb, the mist begins to clear "
        "and in its place forms a crystal clear image!%^RESET%^");

    tell_room(EETO,"%^CYAN%^As "+TPQCN+"'s stares into the orb, "
              "the mist begins to clear and is replaced by a crystal clear image!%^RESET%^", ETO);

    tell_object(ETO,"%^GREEN%^You feel a tug at your soul as the orb begins to do your bidding!%^RESET%^");

    scry_control = new("/d/magic/obj/eye_orb");
    scry_control->set_caster(ETO);
    power = ETO->query_level() * 3 / 4;
    scry_control->set_scry_power(power);
    scry_control->set_target(target);
    scry_control->move(environment(target));
    ETO->set_property("scrying_orb_drain",1);
    set_property("active",1);
    drainees += ({ ETO });
    hunger=1;
    return 1;
}

void stop_scrying()
{
    if(ETO->query_property("scrying_orb_drain"))
    {
        ETO->remove_property("scrying_orb_drain");
    }

    dest_effect();
    return 1;
}


void heart_beat()
{
    int i;

    if(!objectp(ETO)) { return; }

    if(!ETO->is_player())
    {
        if(sizeof(drainees))
        {
            for(i=0;i<sizeof(drainees);i++)
            {
                if(!objectp(drainees[i])) { continue; }
                drainees[i]->remove_property("scrying_orb_drain");
            }
        }

        if(query_property("active")) { dest_effect(); }

        return;
    }

    if(!ETO->query_property("scrying_orb_drain"))
    {
        if(hunger > 0)
        {
            hunger -= (int)ETO->query_base_character_level() * 10;
        }
        return;
    }

    step++;

    hunger += (int)ETO->query_base_character_level() * 10;

    //ETO->add_exp(-1*hunger);
    if(!avatarp(ETO))
    {
        if((int)"/daemon/config_d.c"->check_config("character improvement") == 0)
        {
            if(interactive(ETO)) { ETO->add_exp(hunger * -1); }
        }
        else if((int)"/daemon/config_d.c"->check_config("character improvement") == 1)
        {
            if(interactive(ETO))
            {
                if((int)ETO->set_XP_tax(hunger, 0, "improvement") == -1)
                {
                    tell_object(ETO, "The orb shudders violently as it attempts to draw from your life-force.");
                    ETO->cause_damage_to(ETO,"head",roll_dice(3,100));
                    return 1;
                }
            }
        }
    }

    //debug
    //tell_object(ETO,"exp loss: "+hunger+"");

    if(step == 1)
    {
        switch(hunger)
        {

        case 0..1000:

            tell_object(ETO,"%^CYAN%^You feel a slight pull in your chest.");
            break;

        case 1001..5000:

            tell_object(ETO,"%^YELLOW%^Pain begins to radiate outwards from your middle.");
            break;

        case 5001..10000:

            tell_object(ETO,"%^RED%^A terrible pain courses through your whole body!");
            break;

        case 10001..15000:

            tell_object(ETO,"%^BOLD%^%^BLACK%^Everything hurts, you feel as if you are about to die!");
            break;

        default:

            tell_object(ETO,"%^RED%^The terrible pain has become too much, you feel your lifeforce being "
                "drained away by the orb!");
            stop_scrying();
            ETO->die();
            break;
        }
    }

    if(step >= 7) { step = 0; }

    return;
}




void remove()
{
    int i;

    if(!objectp(ETO)) { return; }

    if(!ETO->is_player())
    {
        if(sizeof(drainees))
        {
            for(i=0;i<sizeof(drainees);i++)
            {
                if(!objectp(drainees[i])) { continue; }
                drainees[i]->remove_property("scrying_orb_drain");
            }
        }
    }

    return ::remove();
}


void dest_effect()
{
    if(objectp(scry_control))
    {
        SCRY_D->stop_scry(scry_control, 0);
        scry_control->dest_me();
    }
    if(objectp(ETO))
    {
        if(living(ETO))
        {
            if(objectp(EETO))
            {
                tell_room(EETO,"%^CYAN%^The hazy mist reforms inside of the crystal orb, concealing "
                    "the images from view!");
            }
        }
    }
    return;
}

void control_failure()
{
    TO->remove_call_out("dest_effect");
    if(objectp(ETO))
    {
        if(living(ETO))
        {
            if(objectp(EETO))
            {
                tell_room(EETO,"%^CYAN%^The hazy mist reforms inside of the crystal orb, concealing "
                    "the images from view!");
            }
        }
    }
    return;
}

int is_crystal_ball()
{
	return 1;
}
