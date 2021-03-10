#include <std.h>
#include "../ruins.h"
inherit MONSTER;

void create()
{
    object ob;
    ::create();
    set_name("salamander");
    set_short("A fiery salamander");
    set_id(({ "salamander", "fiery salamander", "monster", "fire snake" }));
    set_long(
        "%^RED%^The salamander is a fearesome sight indeed! Its lower half is" +
        " that of a giant serpent, with sharp spines that stretch along" +
        " his tail and back. The upper torso is that of a man..more or" +
        " less. His underbelly is plated, and the plating extends up to" +
        " his chest. His skin is more like the scales of a snake and is a" +
        " bright %^ORANGE%^orange%^RED%^ and %^BOLD%^red%^RESET%^%^RED%^, mottled with %^BOLD%^%^BLACK%^black%^RESET%^%^RED%^ as though it is" +
        " smoldering. Indeed, there seems to be heat coming off the" +
        " creature! He has a flaming beard and moustache, with glowing" +
        " yellow eyes. In his hand is a fiery spear that he obviously" +
        " knows how to use."
        );
    set_gender("male");
    set_body_type("humanoid");
    set_race("salamander");
    set_size(2);
    add_limb("tail", "torso", 0, 0, 0);
    remove_limb("right leg");
    remove_limb("left leg");
    remove_limb("right foot");
    remove_limb("left foot");
    set_alignment(9);
    set("aggressive", 25);
    set_max_level(30);
    set_hd(20, 10);
    set_level(20);
    set_exp(3200);
    set_class("fighter");
    set_mlevel("fighter", 20);
    set_property("full attacks", 1);
    set_mob_magic_resistance("average");
    set_property("weapon resistance", 2);
    set_property("no hold", 1);
    set_max_hp(180 + random(50));
    set_hp(query_max_hp());
    set_stats("strength", 20);
    set_stats("charisma", 3);
    set_stats("intelligence", 12);
    set_stats("wisdom", 10);
    set_stats("constitution", 18);
    set_stats("dexterity", 14);
    set_property("swarm", 1);
    set_overall_ac(-15);
    if (!random(6)) {
        set_property("magic", 1);
    }
    new(OBJ + "fire_spear")->move(TO);
    if (random(8)) {
        present("fire spear", TO)->set_property("monsterweapon", 1);
    }
    command("wield fire spear");
    set_diety("kossuth");
    if (!random(2)) {
        ob = new("/d/common/obj/brewing/herb_special_inherit");
        ob->set_herb_name("tendril of flame");
        ob->move(TO);
    }
    set_resistance("fire", 10);
    set_resistance("cold", -15);
}

/*  This was creating way too many gems over long reboots.  Changing to produce on die.  Circe 11/29/03
   void reset()
   {
   ::reset();
   if(!random(3)) new("/d/antioch/valley/obj/gem.c")->move(TO);
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
