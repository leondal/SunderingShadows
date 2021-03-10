//Raising the exp per Ares order to increase leveling speed. Dinji 8/14/07
#include <std.h>
inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("blood hawk");
    set_short("A vicious looking hawk");
    set_id(({ "monster", "hawk", "blood hawk", "vicious hawk", "vicious looking hawk" }));
    set_long(
        "The hawk is quite large, with a set of sharp looking talons and a" +
        " rather nasty beak. He stares back at you with evident hunger in his" +
        " eyes. His feathers are a %^RED%^dark red%^CYAN%^ shade, and you wonder" +
        " if this is in fact a blood hawk. It is said such birds love the taste" +
        " of human flesh."
        );
    set_gender("male");
    set_race("hawk");
    set_body_type("fowl");
    set_size(2);
    set_alignment(6);
    set_overall_ac(5);
    set_hd(10, 4);
    //set_level(12);
    //set_class("fighter");
    //set_mlevel("fighter",12);
    set_hp(random(20) + 50);
    set_damage(1, 4);
    set_attacks_num(2);
    set_base_damage_type("piercing");
    set_attack_limbs(({ "beak", "right claw", "left claw" }));
    set_property("swarm", 1);
    set("aggressive", 18);
    set_stats("strength", 16);
    set_new_exp(6, "normal");
    //set_exp(350);
//   add_money("silver",random(50)+45);
//   add_money("electrum",random(100)+40);
//   add_money("gold",random(50)+10);
    set_emotes(4, ({
        "The blood hawk rakes its claws across your face!",
        "The blood hawk screeches loudly!",
        "The blood hawk tries to gouge out your eyes with its beak!",
    }), 1);
    set_max_level(10);
}

/* this was accumulating too much over long reboots, changing to dump out in die()
 * Styx*  2/5/03
   void reset()
   {
   ::reset();
   if(!random(3)) {
      new("/d/antioch/valley/obj/gem")->move(TO);
   }
   }
 */

void die(mixed ob)
{
    int gem;
    switch (random(10)) { // yes it's intentional to not have breaks.. *Styx*
    case 0..2:  break;

    case 3..4:  new("/d/antioch/valley/obj/gem")->move(TO);
        gem++;

    case 5..6:  break;

    case 7..8:  new("/d/antioch/valley/obj/gem")->move(TO);
        gem++;

    case 9:     new("/d/antioch/valley/obj/gem")->move(TO);
        gem++;
        break;
    }
    if (gem) {
        tell_room(ETO, "As the hawk dies, you catch a glimpse of something glittery from the bloody, battered corpse.");
    }
    ::die(ob);
}
