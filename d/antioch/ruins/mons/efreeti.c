#include <std.h>
#include "../ruins.h"
inherit WEAPONLESS;

void create()
{
    object ob;
    ::create();
    set_name("efreeti");
    set_short("A swirling form of flames");
    set_id(({ "efreeti", "flames", "form of flames", "swirling form of flames", "monster" }));
    set_long("%^BOLD%^%^RED%^The efreeti is rather large, at least" +
             " twelve feet tall. This one wears a human upper body (except" +
             " that his skin is a %^RESET%^%^RED%^dark red%^BOLD%^ shade)" +
             " that is heavily muscled. %^YELLOW%^Yellow eyes%^RED%^ stare" +
             " coldly at you, and you notice sharp teeth and claws that could" +
             " easily rend you in pieces. The bottom half of the efreeti is" +
             " a swirling mass of orange and red flames that float just off" +
             " the ground. It is a fearsome creature indeed.");
    set_size(3);
    set_race("genie");
    set_body_type("humanoid");
    set_gender("male");
    set_class("fighter");
    set_mlevel("fighter", 25);
    set_class("mage");
    set_mlevel("mage", 20);
    set_property("full attacks", 1);
    set_mob_magic_resistance("high");
    set_property("weapon resistance", 1);
    set_property("magic", 1);
    set_property("no bows", 1);
    set_property("swarm", 1);
    set("aggressive", 25);
    set_hd(25, 8);
    set_max_hp(220 + random(30));
    set_hp(query_max_hp());
    set_exp(4300);
    set_level(25);
    set_max_level(30);
    set_overall_ac(-10);
    set_alignment(3);
    add_limb("right claw", "right hand", 0, 0, 0);
    add_limb("left claw", "left hand", 0, 0, 0);
    set_base_damage_type("slashing");
    set_attack_limbs(({ "right claw", "left claw" }));
    set_damage(4, 10);
    add_money("gold", random(1000) + 50);
    set_spells(({ "fireball", "meteor swarm" }));
    set_spell_chance(20);
    if (!random(2)) {
        ob = new("/d/common/obj/brewing/herb_special_inherit");
        ob->set_herb_name("tendril of flame");
        ob->move(TO);
    }
    set_resistance("fire", 15);
    set_resistance("cold", -15);
}

void init()
{
    ::init();
    if (TP->query_invis() && !avatarp(TP)) {
        tell_object(TP, "The efreeti looks directly at you and smiles evilly as he begins his attack.");
        force_me("kill " + TP->query_name() + "");
    }
}

/*  This was creating way too many gems over long reboots.  Changing to produce on die.  Circe 11/29/03
   void reset()
   {
   ::reset();
   if(!random(3)) new("/d/antioch/valley/obj/gem.c")->move(TO);
   if(!random(3)) new("/d/antioch/valley/obj/gem.c")->move(TO);
   }
 */

//it's meant to not have breaks to still offer chance of multiple gems.  Circe 11/29/03
void die(mixed ob)
{
    switch (random(4)) {
    case 0:  break;

    case 1:  new("/d/antioch/valley/obj/gem")->move(TO);
        new("/d/antioch/valley/obj/gem")->move(TO);

    case 2:  new("/d/antioch/valley/obj/gem")->move(TO);

    case 3:  new("/d/antioch/valley/obj/gem")->move(TO);
        break;
    }
    ::die(ob);
}
