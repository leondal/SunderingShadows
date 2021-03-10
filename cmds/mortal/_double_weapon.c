#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_double_weapon(string str)
{
    object * wielded;

    if (!objectp(TP)) {
        return 0;
    }

    wielded = (object*)TP->query_wielded();

    if (!sizeof(wielded)) {
        return 0;
    }

    if (!wielded[0]->query_property("double weapon")) {
        tell_object(TP, "This is not a double weapon.");
        return 1;
    }

    if (!TP->validate_combat_stance("two hander") && !TP->validate_combat_stance("double weapon")) {
        tell_object(TP, "You must use both hands to wield this as a double weapon.");
        return 1;
    }

    if (!FEATS_D->usable_feat(TP, wielded[0]->query_weapon_prof() + " weapon proficiency")) {
        tell_object(TP, "You don't have the proficiency to wield this as a double weapon.");
        return 1;
    }

    if (str) str = lower_case(str);
    if (str != "on" &&
        str != "off" &&
        str != "check") {
        str = "check";
    }
    
    switch (str)
    {
    case "on":
        TP->set_combat_stance("double weapon");
        tell_object(TP, "You are wielding this as a double weapon.");
        break;
    case "off":
        TP->set_combat_stance("two hander");
        tell_object(TP, "You are wielding this as a two handed weapon.");
        break;
    case "check":
        if (TP->query_combat_stance() == "double weapon") {
            tell_object(TP, "You are wielding this as a double weapon.");
        }else {
            tell_object(TP, "You are wielding this as a two handed weapon.");
        }
        break;
    }
    return 1;
}

void help()
{

    write(
"
%^CYAN%^NAME%^RESET%^

double_weapon - switch the stance of a double weapon

%^CYAN%^SYNOPSIS%^RESET%^

double_weapon
double_weapon check
double_weapon on | off

%^CYAN%^DESCRIPTION%^RESET%^

The command will allow player to switch between fighting with both ends of a double weapon as if fighting with two weapons or use a double weapon two-handed, attacking with only one end of it.

%^ORANGE%^<double_weapon check>%^RESET%^
  Will show your current stance while wielding a double weapon.

%^ORANGE%^<double_weapon on>%^RESET%^
  Will switch to fight with both ends of a double weapon as if fighting with two weapons.

%^ORANGE%^<double_weapon off>%^RESET%^
  Will switch to two-handed, attacking with only one end.

%^CYAN%^SEE ALSO%^RESET%^

wield, unwield
"
        );
}
