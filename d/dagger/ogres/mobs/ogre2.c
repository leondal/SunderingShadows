#include <std.h>
inherit MONSTER;
#include "../ogres.h"

void create() {
    object ob;
    ::create();
    set_name("ogre warrior");
    set_id( ({"ogre", "ogre warrior", "warrior", "Ogre Warrior", "cavemon"}) );
    set_short("%^RESET%^%^ORANGE%^O%^RESET%^%^WHITE%^"+
"g%^RESET%^%^ORANGE%^re Warri%^RESET%^%^WHITE%^o%^RESET%^%^ORANGE%^r%^RESET%^");
    set_long(
      "%^RESET%^%^ORANGE%^This beast of an ogre is wielding a %^RESET%^%^BOLD%^"+
"%^WHITE%^cl%^RESET%^%^WHITE%^u%^RESET%^%^BOLD%^%^WHITE%^b of bo%^RESET%^%^WHITE%^"+
"n%^RESET%^%^BOLD%^%^WHITE%^e %^RESET%^%^ORANGE%^easily. It is over nine feet tall"+
" and bristling with %^RESET%^%^YELLOW%^m%^RESET%^%^ORANGE%^u%^RESET%^%^YELLOW%^"+
"scles%^RESET%^%^ORANGE%^. Brown wart covered skin is covered with countless "+
"%^RESET%^%^RED%^sca%^RESET%^%^BOLD%^%^RED%^r%^RESET%^%^RED%^s %^RESET%^%^ORANGE%^"+
"from past battles. It wears a ragged set of %^RESET%^%^WHITE%^armor %^RESET%^"+
"%^ORANGE%^that serves to protect it. %^RESET%^"
    );
    set_gender("male");
    set("race", "ogre");
    set_body_type("human");
    set_overall_ac(5);
    set_property("swarm",1);
    set_class("fighter");
    set_mlevel("fighter", 20);
    set_hd(15,7);
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
    set_speed(20);
        set_nogo( ({"/d/dagger/ogres/rooms/0_2", "/d/dagger/ogres/rooms/ogremaze55"}) );
    set_size(3);
    set_max_hp(115);
    set_hp(160);
    set_property("full attacks", 2);
    add_money("gold", random(25));

    ob = new("/d/common/obj/armour/studded");
    ob->move(TO);
    ob->set_property("enchantment",1);
    ob->set_property("size",3);
    ob->set_property("monsterweapon",1);
    command("wear studded");

    new(OBJ"bone")->move(TO);
    command("wield bone");
}
