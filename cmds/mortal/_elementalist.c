// elementalist command for versatile arcanist feat.
// changing preferred elemental type at will (ok to use in combat!) or remove the setting to let the spells default. N, 8/15.
#include <std.h>
#include <daemons.h>
inherit DAEMON;

#define OKELEMENTS ({ "reset","acid","cold","electricity","fire","sonic" })

int cmd_elementalist(string str) {
    if(!FEATS_D->usable_feat(TP,"versatile arcanist") && !TP->is_class("versatile_arcanist")) return notify_fail("Only a versatile arcanist has the skill to shift the elements of their spells.\n");
    if (TP->query_bound() || TP->query_paralyzed()) {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    if(!str) return notify_fail("Syntax: <elementalist (type)> or <elementalist reset>\n");
    if(TP->query_casting()) return notify_fail("You're in the middle of casting a spell!\n");

    if(member_array(str,OKELEMENTS) == -1)
      return notify_fail("Sorry, that's not a valid element. You can only select from acid, cold, electricity, fire, sonic, or reset to cast all spells as normal.");
    switch(str) {
      case "reset":
      if(TP->query("elementalist")) TP->delete("elementalist");
      tell_object(TP,"%^BOLD%^%^WHITE%^Your spells will now all be cast as their default elements.%^RESET%^");
      break;

      default:
      TP->set("elementalist",str);
      tell_object(TP,"%^BOLD%^%^WHITE%^All of your elemental spells will now be cast as "+str+".%^RESET%^");
      break;
    }
    return 1;
}

void help() {
    write(
             "
%^CYAN%^NAME%^RESET%^

elementalist - set damage element for versatile arcanist prestige class

%^CYAN%^SYNOPSIS%^RESET%^

elementalist %^ORANGE%^%^ULINE%^TYPE%^RESET%^|reset

%^CYAN%^DESCRIPTION%^RESET%^

This command allows prestige class versatile arcanist that has taken Master of Elements feat to change their primary attack damage type.

Only some spells are affected by this feat, so be sure to read spell descriptions.

Available options are:

%^ORANGE%^<elementalist reset>%^RESET%^
    Will cast all spells as normal

%^ORANGE%^<elementalist acid|cold|electricity|fire|sonic>%^RESET%^
    Will cast spells as an element of that type

%^CYAN%^SEE ALSO%^RESET%^

versatile arcanist, master of the elements *feats, sorcerer, cast, fireball

");
         
}
