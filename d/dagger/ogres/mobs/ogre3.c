#include <std.h>
inherit MONSTER;
#include "../ogres.h"

void create() {
    object ob;
    ::create();
    set_name("ogre veteran");
    set_id( ({"ogre", "ogre veteran", "veteran", "Ogre Veteran", "cavemon"}) );
    set_short("%^RESET%^%^ORANGE%^O%^RESET%^%^BOLD%^%^RED%^g%^RESET%^"+
"%^ORANGE%^re Veter%^RESET%^%^BOLD%^%^RED%^a%^RESET%^%^ORANGE%^n%^RESET%^");
    set_long(
      "%^RESET%^%^ORANGE%^This beast of an ogre is wielding a "+
"%^RESET%^%^BOLD%^%^WHITE%^giant axe %^RESET%^%^ORANGE%^easily. "+
"It is over nine feet tall and bristling with %^RESET%^%^YELLOW%^m%^RESET%^"+
"%^ORANGE%^u%^RESET%^%^YELLOW%^scles%^RESET%^%^ORANGE%^. Brown wart covered "+
"skin is covered with countless %^RESET%^%^RED%^sca%^RESET%^%^BOLD%^%^RED%^r"+
"%^RESET%^%^RED%^s %^RESET%^%^ORANGE%^from past battles. It wears %^RESET%^"+
"%^BOLD%^%^BLACK%^a set of banded plate %^RESET%^%^ORANGE%^that serves to "+
"protect it. There is a look of experience to this ogre, and it moves with "+
"greater purpose and intelligence then most.%^RESET%^"
    );
    set_gender("male");
    set("race", "ogre");
    set_body_type("human");
    set_overall_ac(5);
    set_property("swarm",1);
    set_class("fighter");
    set_mlevel("fighter", 22);
    set_hd(19,7);
    set_attack_bonus(2);
   set_max_level(25);
    set_stats("strength", 18);
    set_stats("dexterity", 8);
    set_stats("constitution", 18);
    set_stats("intelligence", 3);
    set_stats("wisdom", 5);
    set_stats("charisma", 3);
    set("aggressive", 20);
    set_alignment(9);
    set_size(3);
    set_max_hp(115);
    set_hp(200);
    set_speed(20);
        set_nogo( ({"/d/dagger/ogres/rooms/0_2", "/d/dagger/ogres/rooms/ogremaze55"}) );
    set_property("full attacks", 2);
    add_money("gold", random(25));

    ob = new("/d/common/obj/weapon/giant_battle_axe.c");
    ob->move(TO);
    ob->set_property("enchantment",2);
    ob->set_property("size",3);
    ob->set_property("monsterweapon",1);
    command("wield axe");

    ob = new("/d/common/obj/armour/banded");
    ob->move(TO);
    ob->set_property("enchantment",1);
    ob->set_property("size",3);
    ob->set_property("monsterweapon",1);
    command("wear banded");
}
