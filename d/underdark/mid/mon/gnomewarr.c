#include <std.h>
#include "../../defs.h"
inherit MONSTER;

int following;

void create() {
    object ob;
    ::create();
    set_id(({"gnome","svirfneblin","deep gnome"}));
    set_name("svirfneblin");
    set_short("%^RESET%^A small, armored gnome%^RESET%^");
    set_long("%^ORANGE%^Standing at three feet in height, this gnome has dark %^BOLD%^%^BLACK%^gray skin "
"%^RESET%^%^ORANGE%^and instead of a full head of hair, several small %^WHITE%^wh%^BOLD%^i%^RESET%^%^WHITE%^"
"sps of h%^BOLD%^a%^RESET%^%^WHITE%^ir %^ORANGE%^sprout at odd places on his head. Large expressive %^CYAN%^bl"
"%^BOLD%^%^BLUE%^u%^RESET%^%^CYAN%^e e%^BOLD%^%^BLUE%^y%^RESET%^%^CYAN%^es %^ORANGE%^stare forth from under "
"deep brows. He wears a set of armor made from what looks like %^BOLD%^%^BLACK%^sto%^RESET%^%^WHITE%^n%^BOLD%^"
"%^BLACK%^e pl%^RESET%^%^WHITE%^a%^BOLD%^%^BLACK%^tes%^RESET%^%^ORANGE%^, and the %^YELLOW%^hooked hammer "
"%^RESET%^%^ORANGE%^in his hand is obviously more than just a tool.%^RESET%^");
    set_race("gnome");
    set_body_type("human");
    set_gender("male");
    set_alignment(4);
    set_size(1);
    set_class("fighter");
    set_hd(28,10);
    set_guild_level("fighter",28);
    set_mlevel("fighter",28);
    set_max_hp(350);
    set_hp(350);
    set_stats("strength",16);
    set_exp(3000);
    set_overall_ac(-12);
    set("aggressive",18);
    set_wielding_limbs(({"left hand","right hand"}));
    new(OBJ"hookhammer")->move(TO);
    command("wield hammer");
    ob = new("/d/common/obj/armour/splate");
    ob->move(TO);
    ob->set_short("%^BOLD%^%^BLACK%^stony plate armor%^RESET%^");
    ob->set_property("monsterweapon",1);
    command("wear plate");
    set_mob_magic_resistance("average");
    add_money("gold", random(100)+400);
    add_money("platinum", random(30)+200);
    add_money("electrum", random(100)+500);
}

void init(){
   object ob;
   ::init();
   if(!following) {
     if(ob = present("svirfneblin priest",ETO)) {
       ob->add_follower(TO);
       ob->add_protector(TO);
       following = 1;
     }
   }
}
