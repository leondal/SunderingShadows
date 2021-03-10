#include <std.h>
inherit MONSTER;
#include "../ogres.h"

void create() {
    object ob;
    ::create();
    set_name("ogre shaman");
    set_id( ({"ogre", "shaman", "ogre shaman", "Ogre Shaman", "cavemon"}) );
    set_short("%^RESET%^%^ORANGE%^O%^RESET%^%^WHITE%^g%^RESET%^%^ORANGE%^re"+
" Sham%^RESET%^%^WHITE%^a%^RESET%^%^ORANGE%^n%^RESET%^");
    set_long(
      "%^RESET%^%^ORANGE%^This beast of an ogre is wielding no weapon, yet "+
"waves meaty hands in front of himself %^RESET%^%^RED%^angrily%^RESET%^"+
"%^ORANGE%^. It is over nine feet tall and bristling with %^RESET%^%^YELLOW%^"+
"m%^RESET%^%^ORANGE%^u%^RESET%^%^YELLOW%^scles%^RESET%^%^ORANGE%^. %^RESET%^"+
"%^YELLOW%^Ye%^RESET%^%^BOLD%^%^GREEN%^l%^RESET%^%^YELLOW%^low%^RESET%^"+
"%^ORANGE%^-%^RESET%^%^BOLD%^%^GREEN%^gre%^RESET%^%^YELLOW%^e%^RESET%^%^BOLD%^"+
"%^GREEN%^n %^RESET%^%^ORANGE%^skin is covered in a fine layer of %^RESET%^"+
"%^WHITE%^dust %^RESET%^%^ORANGE%^and %^RESET%^%^RED%^blo%^RESET%^%^BOLD%^"+
"%^RED%^o%^RESET%^%^RED%^d st%^RESET%^%^BOLD%^%^RED%^a%^RESET%^%^RED%^ins"+
"%^RESET%^%^ORANGE%^. It wears a suit of %^RESET%^%^BOLD%^%^BLACK%^plate "+
"%^RESET%^%^ORANGE%^covered in %^RESET%^%^BOLD%^%^BLACK%^runes %^RESET%^"+
"%^ORANGE%^and %^RESET%^%^WHITE%^fetishes%^RESET%^%^ORANGE%^.%^RESET%^"
    );
    set_gender("male");
    set("race", "ogre");
    set_body_type("human");
    set_overall_ac(3);
    set_property("swarm",1);
    set_hd(20,5);
   set_exp(2500);
   set_max_level(25);
    set_speed(10);
    set_stats("strength", 18);
    set_stats("dexterity", 8);
    set_stats("constitution", 18);
    set_stats("intelligence", 3);
    set_stats("wisdom", 5);
    set_stats("charisma", 3);
    set("aggressive", 20);
    set_alignment(9);
    set_size(3);
    set_max_hp(150+random(50));
    set_hp(query_max_hp());
    set_property("full attacks", 1);
    add_money("gold", random(100));

    set_class("cleric");
    set_mlevel("cleric",20);
    set_guild_level("cleric",20);

    set_new_exp(22,"normal");

    set_spell_chance(40);
    set_spells(({"confusion",
"blasphemy",
"crushing hand",
"earthquake",
"flame strike"}));

    ob = new("/d/common/obj/armour/field");
    ob->move(TO);
    ob->set_property("enchantment",1);
    ob->set_property("size",3);
    ob->set_property("monsterweapon",1);
    command("wear field");

}
