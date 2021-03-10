// /d/newbie/mon/gnome1.c

#include "../newbie.h";
inherit MONSTER;

void create() {
    ::create();
    set_name("gnome");
    set_id(({"gnome","mining gnome"}));
    set_race("gnome");
    set_body_type("human");
    set_gender("male");
    set_short("Small gnome");
    set_long("This creature looks quite a bit like a small, slender dwarf except you can't miss the bulbous nose that dominates his round face.  He has a short, neatly-trimmed beard and mustache.  Sparkling blue eyes the color of the sky reflect the torchlight and stand in stark contrast to its deep woody brown skin and pale gray hair.");
 	 set_class("fighter");
 	 set_level(5);
    add_search_path("/cmds/fighter");
    set("aggressive",1);
    set_wimpy(10);
	 set_stats("intelligence",12);
    set_stats("wisdom",10);
    set_stats("strength",15);
    set_stats("charisma",10);
    set_stats("dexterity",10);
    set_stats("constitution",17);
    set_property("swarm",1);
    set_alignment(4);
    set_size(1);
    set_exp(15);
    set_hp(55 + random(15));
    if(random(2)) {
        new("/d/newbie/obj/weapons/sdagger")->move(TO);
        command("wield dagger");
    }
    add_money("silver",random(10));
    add_money("copper",random(20));
    set_emotes(3, ({"%^BOLD%^The gnome hums as he works mining the gems.", "%^BOLD%^%^BLUE%^The small gnome sits down to rest, smiling as he carefully cleans the dirt from a gem.", "%^BOLD%^%^BLUE%^The small gnome smiles at you but seems to be a little nervous.", "%^BOLD%^%^BLUE%^The gnome sharpens his dagger on a soft stone.", "%^BOLD%^The gnome chips at the rock and dirt around a gem with his dagger then loads up the cart."}), 0);
	 set_achats(4, ({"%^YELLOW%^The small gnome cries out in fear as he tries to defend himself.", "%^YELLOW%^The small gnome tries to run past you to escape.", "%^YELLOW%^The gnome dodges toward an exit fearfully." }) );
    set_new_exp(1, "very low");
}

