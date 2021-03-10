#include <std.h>
#include "../../defs.h"
inherit MONSTER;

void create() {
    object ob;
    ::create();
    set_id(({"gnome","svirfneblin","deep gnome","svirfneblin priest"}));
    set_name("svirfneblin");
    set_short("%^RESET%^A bald, gray-skinned gnome%^RESET%^");
    set_long("%^ORANGE%^At just under three feet in height, this gnome has dark %^BOLD%^%^BLACK%^gray skin "
"%^RESET%^%^ORANGE%^and quite a bald, shiney head with not a trace of hair. His large %^CYAN%^bl%^BOLD%^"
"%^BLUE%^u%^RESET%^%^CYAN%^e e%^BOLD%^%^BLUE%^y%^RESET%^%^CYAN%^es %^ORANGE%^watch out over his world with a "
"deep, wise gaze. He wears only a simple woolen robe and boots, and seems to carry little else of value on his "
"person.%^RESET%^");
    set_race("gnome");
    set_body_type("human");
    set_gender("male");
    set_alignment(4);
    set_size(1);
    set_nogo(({MID+"tunnel09","/d/dagger/kinaro/mines/lower2q"}));
    set_speed(80);
    set_moving(1);
    set_class("priest");
    set_diety("grumbar");
    set_hd(30,8);
    set_guild_level("priest",30);
    set_mlevel("priest",30);
    set_max_hp(250);
    set_hp(250);
    set_exp(3500);
    set_overall_ac(-9);
    set("aggressive",18);
    new(OBJ"sboots")->move(TO);
    command("wear boots");
    ob = new("/d/common/obj/armour/robe");
    ob->move(TO);
    ob->set_size(1);
    ob->set_property("monsterweapon",1);
    ob->set_short("%^RESET%^%^ORANGE%^Dark brown wool vestments%^RESET%^");
    command("wear robe");
    set_mob_magic_resistance("average");
    add_money("gold", random(100)+200);
    add_money("platinum", random(30)+100);
    add_money("electrum", random(100)+250);
    add_search_path("/cmds/priest");
    set_spells(({"earthenair","earthenair","cause serious wounds","cause serious wounds","cause serious wounds","hold person","hold person"}));
    set_spell_chance(60);
}
