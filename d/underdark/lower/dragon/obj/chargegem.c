#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit OBJECT;

int charged;

void create(){
   ::create();
   set_name("colorless gemstone");
   set_id(({"gem","gemstone","colorless gem","colorless gemstone","essence","essence of arcana","holorems essence of arcana","holorem's essence of arcana","Essence of Arcana","Essence"}));
   set_short("%^RESET%^%^MAGENTA%^Holorem's Essence of %^CYAN%^A%^BOLD%^rc%^RESET%^%^CYAN%^an%^BOLD%^a%^RESET%^");
   set_obvious_short("%^RESET%^%^CYAN%^a %^RESET%^colorless %^CYAN%^gemstone infused with a %^BOLD%^soft glow%^RESET%^");
   set_long("%^RESET%^%^CYAN%^To an initial glance, this gem appears %^ORANGE%^unremarkable %^CYAN%^and likely "
"not of a great value.  While of a moderate size, approximately that of a %^RESET%^small egg%^CYAN%^, the cut "
"of the stone is asymmetrical and lacks the %^MAGENTA%^elegant %^CYAN%^precision of many other expensive "
"stones.  %^RESET%^Cl%^BOLD%^%^BLACK%^ou%^RESET%^dy %^CYAN%^and semi-transparent, it lacks the %^YELLOW%^br"
"%^WHITE%^il%^YELLOW%^lia%^WHITE%^n%^YELLOW%^t %^RESET%^%^CYAN%^lustre of diamond, and instead more closely "
"resembles a cut of quartz.  A closer examination of the gem, however, reveals a pale blossom of %^BOLD%^soft "
"light %^RESET%^%^CYAN%^within its core, difficult at first to notice, but ever-present and never fading."
"%^RESET%^\n");
   set_lore("Deep in the library of the Mystran temple, merticulous notes are kept of every success and "
"failure ever made or reported by magi.  In this way, the keepers of the weave are able to trace back the "
"magical origins of even the most obscure items.  Often these are little more then simple one or two line "
"notes recording date and achievement.  In the case of some successes or failures though, whole books have "
"been devoted to their inspiration and effect.  Such is the case of Holorem the Transmuter.  Holorem became a "
"devotee of the Mystran church in 249 SG, and his skills of reshaping items through the touch of the weave "
"were well admired until the day he produced his Charging Crystals.  By weaving powerful arcana into a holding "
"matrix of power and then placing these matrixes into such simple items as crystals he was able to maintain a "
"readily available power source for many of the high-magic items that drained their power with each use.  Such "
"crystals could easily %^YELLOW%^recharge%^RESET%^ a drained item.  Both hailed as a great inventor, and "
"ridiculed for his disrespect of the weave, Holorem eventually retreated into obscurity, leaving only a "
"handful of his greatest achievements behind.");
   set_weight(5);
   set_value(600);
   set_property("lore difficulty",30);
   set_property("id difficulty",30);
   charged = 1;
}

int isMagic(){ return 5; }

void init(){
   ::init();
   add_action("recharge_fun","recharge");
}

int recharge_fun(string str) {
    object mytarg;
    if(!str) {
      notify_fail("What do you want to recharge?\n");
      return 0;
    }
    if(!present(str,TP)) {
      notify_fail("You do not have a "+str+".\n");
      return 0;
    }
    mytarg = present(str,TP);
    if(!mytarg->is_tazrak_charged()) {
      notify_fail("You cannot recharge that item.\n");
      return 0;
    }
    if(!charged) {
      notify_fail("The gemstone's energies are spent.\n");
      return 0;
    }
    tell_object(ETO,"%^CYAN%^You touch the gemstone against the "+mytarg->query_name()+"%^RESET%^%^CYAN%^, and "
"the glow within suddenly intensifies, finally emitting a %^BOLD%^bright flash %^RESET%^%^CYAN%^before it goes "
"dead.%^RESET%^");
    tell_room(EETO,"%^CYAN%^"+TP->QCN+" touches the gemstone against the "+mytarg->query_name()+"%^RESET%^"
"%^CYAN%^, and the glow within suddenly intensifies, finally emitting a %^BOLD%^bright flash %^RESET%^%^CYAN%^"
"before it goes dead.%^RESET%^",ETO);
    charged = 0;
    mytarg->renew_charges();
    set_obvious_short("%^RESET%^%^CYAN%^a %^RESET%^colorless %^CYAN%^gemstone%^RESET%^");
    set_long("%^RESET%^%^CYAN%^This gem appears %^ORANGE%^unremarkable %^CYAN%^and likely not of a great "
"value.  While of a moderate size, approximately that of a %^RESET%^small egg%^CYAN%^, the cut of the stone is "
"asymmetrical and lacks the %^MAGENTA%^elegant %^CYAN%^precision of many other expensive stones.  %^RESET%^Cl"
"%^BOLD%^%^BLACK%^ou%^RESET%^dy %^CYAN%^and semi-transparent, it lacks the %^YELLOW%^br%^WHITE%^il%^YELLOW%^lia"
"%^WHITE%^n%^YELLOW%^t %^RESET%^%^CYAN%^lustre of diamond, and instead more closely resembles a cut of quartz."
"%^RESET%^\n");
    return 1;
}
