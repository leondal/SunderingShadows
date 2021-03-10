#include <std.h>
#include "../dagger.h"
inherit MONSTER;

void create() {
    object ob;
    ::create();
    set_id(({"kiervalan","half-elf"}));
    set_name("Kiervalan");
    set_short("%^BOLD%^%^BLACK%^Kiervalan Telkaror, Lo%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^d Wo%^RESET%^"
"%^WHITE%^l%^BOLD%^%^BLACK%^f of %^RESET%^%^MAGENTA%^T%^BOLD%^%^BLACK%^al%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^"
"s%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This man is an i%^RESET%^%^WHITE%^m%^BOLD%^%^BLACK%^po%^RESET%^%^WHITE%^s"
"%^BOLD%^%^BLACK%^ing sight. His six foot height is well matched by a %^RESET%^%^RED%^m%^BOLD%^u%^RESET%^"
"%^RED%^scled fr%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^me%^BOLD%^%^BLACK%^ and a %^RESET%^%^CYAN%^confid%^BOLD%^"
"%^BLACK%^e%^RESET%^%^CYAN%^nt %^BOLD%^%^BLACK%^bearing. His features are completely obscured by an %^RESET%^"
"%^WHITE%^ebony wolf's head %^BOLD%^%^BLACK%^mask that is perpetually set into a %^RESET%^%^RED%^vi%^BOLD%^ci"
"%^RESET%^%^RED%^ous s%^BOLD%^n%^RESET%^%^RED%^arl%^BOLD%^%^BLACK%^. Wild black hair frames the mask, giving "
"him an even more %^RED%^feral %^BLACK%^appearance. He wears black leather armor, and a tattered black and "
"%^RESET%^%^MAGENTA%^purple %^BOLD%^%^BLACK%^cloak flutters in an unfelt wind. He grips two swords in "
"gauntlets formed into claws. By the %^RESET%^%^ORANGE%^ni%^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^ks %^BOLD%^"
"%^BLACK%^in the swords, and the %^RESET%^%^RED%^ga%^BOLD%^%^BLACK%^s%^RESET%^%^WHITE%^h%^RED%^es %^BOLD%^"
"%^BLACK%^in his armor, this man can handle himself. He stands in the ruins of the city like a victorious "
"general.%^RESET%^");
    set_race("half-elf");
    set_body_type("human");
    set_gender("male");
    set_alignment(6);
    set_class("ranger");
    set_class("fighter");
    set_hd(47,8);
    set_guild_level("ranger",35);
    set_mlevel("ranger",35);
    set_guild_level("fighter",47);
    set_mlevel("fighter",47);
    set_max_hp(1500);
    set_hp(1500);
    set_exp(25000);
    set_overall_ac(-23);
    set("aggressive",0);
    set_stats("dexterity",18);
    set_stats("strength",18);
    set_property("full attacks",1);
    set_wielding_limbs(({"left hand","right hand"}));
    command("message in stalks in.");
    command("message out stalks $D.");
    set_emotes(1, ({"%^BOLD%^%^BLACK%^Kiervalan growls softly:%^RESET%^ Do you doubt the power of my Lord "
"Talos now?","%^BOLD%^%^BLACK%^Kiervalan growls softly:%^RESET%^ Moonlight does not touch this soul, nor the "
"ground I scorch in HIS name.","%^BOLD%^%^BLACK%^Kiervalan growls softly:%^RESET%^ I had thought the city "
"could defend itself better, the drow almost didnt need me.","%^BOLD%^%^BLACK%^Kiervalan seems to regard you "
"for a moment, his grip tightening on the hilts of his swords.%^RESET%^","%^BOLD%^%^BLACK%^Kiervalan glances "
"around at the ruins, a low chuckle coming from behind the wolf's head visor.%^RESET%^" }), 0);
    add_money("gold", random(100)+400);
    add_money("platinum", random(30)+200);
    add_money("electrum", random(100)+500);
    ob = new(MONOBJ"wolfhelm");
    ob->move(TO);
    command("wear visor");
    ob = new("/d/islands/dallyh/marsh/obj/assarmor");
    ob->move(TO);
    ob->set_obvious_short("%^BOLD%^%^BLACK%^aged leather armor%^RESET%^");
    ob->set_property("monsterweapon",1);
    command("wear leather");
    ob = new("/d/antioch/valley/obj/tcloak");
    ob->move(TO);
    ob->set_short("%^BOLD%^%^BLACK%^tat%^RESET%^t%^BOLD%^%^BLACK%^ered clo%^RESET%^%^MAGENTA%^a%^BOLD%^"
"%^BLACK%^k%^RESET%^");
    ob->set_property("monsterweapon",1);
    command("wear cloak");
    ob = new(MONOBJ"demonblade");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    command("wield blade");
    ob = new("/d/islands/common/obj/esword");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    command("wield scimitar");
    set_funcs(({"zap_me"}));
    set_func_chance(15);
}

void zap_me(object targ) {
    if(!objectp(TO) || !objectp(targ)) return;
    if(!present(targ->query_name(),ETO)) return;
    if(!present("wolf",ETO)) {

    }
    tell_room(ETO,"%^BOLD%^%^BLACK%^Kiervalan grabs "+targ->QCN+" roughly and lifts "+targ->QO+" up. The air "
"crackles as %^YELLOW%^li%^WHITE%^g%^YELLOW%^htn%^WHITE%^i%^YELLOW%^ng %^BLACK%^courses through both of them!"
"%^RESET%^",targ);
    tell_object(targ,"%^BOLD%^%^BLACK%^Kiervalan grabs you roughly and holds you in the air, muttering a "
"prayer. %^YELLOW%^Li%^WHITE%^g%^YELLOW%^htn%^WHITE%^i%^YELLOW%^ng %^BLACK%^courses through him and into you, "
"and you feel your insides %^RESET%^%^RED%^burn%^BOLD%^%^BLACK%^!%^RESET%^");
    targ->do_damage(targ->return_target_limb(),roll_dice(10,10));
}

void die(object ob) {
   tell_room(ETO,"%^BOLD%^%^BLACK%^Kiervalan drops to his knees, %^YELLOW%^light%^WHITE%^n%^YELLOW%^ing "
"%^BLACK%^crackling around him, and he looks at the sky and begs his lord's mercy. %^YELLOW%^Lig%^WHITE%^h"
"%^YELLOW%^tning %^BLACK%^strikes the %^RESET%^%^ORANGE%^grou%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^d %^BOLD%^"
"%^BLACK%^and all that is left is a %^RESET%^smoking %^BOLD%^%^BLACK%^visor%^BOLD%^%^BLACK%^.%^RESET%^");
   ::die(ob);
}