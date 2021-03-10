/*  Shadow Guard   by Killashandra  */

#include <std.h>
#include "/d/stella/short.h"
inherit MONSTER;

void create() {
    :: create();
    set_name("Shadow Guard");
    set_id(({
      "shadow","guard","shadow guard"
      }));
    set_short("%^RESET%^%^BLUE%^Shadow Guard%^RESET%^");
    set_long(
	"%^BLUE%^The Shadow Guard is a humanoid which appears to be "
	"made from a cloth of shadow.  He seems to be garbed in a "
	"shadowy suit of full plate armour and is wielding a shadowy "
	"long sword.  He makes no noise when walking and seems to float "   
	"scant millimeters above the floor.%^RESET%^"); 
    set_gender("male");
    set_alignment(9);
    set_size(2);
    set_wielding_limbs(({"right hand","left hand"}));
    set_overall_ac(-15);
    set_hp(268);
    set_property("no bump",1);
    set_property("no steal",1);
    set_max_hp(268);
    set_exp(70000);
    set_body_type("humanoid");
    set_race("shadow");
    set_class("fighter");
    set_level(30);
//    set_guild_level("mage",30);
    set_stats("strength",24);
    set_stats("constitution",18);
    set_stats("dexterity",18);
    set_stats("wisdom",3);
    set_stats("intelligence",18);
    set_stats("charisma",10);
    set("aggressive",16);
//    set_spell_chance(30);
//    set_spells(({"lightning bolt","fireball","burning hands","wall of fire","cone of cold","chain lightning"}));
    new( OPATH "shadsw.c" )->move(TO);
    command("wield sword in right hand");
    new( OPATH "shadsw.c" )->move(TO);
    command("wield sword in left hand");
    new( OPATH "shadarm.c" )->move(TO);
    command("wear armor");
}
