// /d/newbie/mon/gnome3.c

#include "../newbie.h";
inherit MONSTER;

void create() {
    ::create();
    set_name("gnome");
    set_id(({"gnome","mining gnome","guard","gnome guard"}));
    set_race("gnome");
    set_body_type("human");
    set_gender("male");
    set_short("Gnome guard");
    set_long("This creature looks quite a bit like a small, slender dwarf except you can't miss the bulbous nose that dominates his round face.  His hair and short, neatly-trimmed beard and mustache are a pale gray.  Sparkling blue eyes the color of the sky reflect the torchlight and stand in stark contrast to its deep woody brown skin and light hair.  This one looks to be dressed and armed to protect the others.");
  	 set_class("fighter");
  	 set_level(4);
    add_search_path("/cmds/fighter");
    set("aggressive",1);
    set_wimpy(10);
  	 set_stats("intelligence",12);
    set_stats("wisdom",10);
    set_stats("strength",17);
    set_stats("charisma",10);
    set_stats("dexterity",10);
    set_stats("constitution",17);
    set_property("swarm",1);
    set_alignment(4);
    set_size(1);
    set_exp(30);
    set_hp(35 + random(25));
    new("/d/newbie/obj/weapons/sbattleaxe")->move(TO);
    force_me("wield axe");
    new("/d/newbie/obj/armor/spadded")->move(TO);
    force_me("wear padded");
    add_money("silver",random(10));
    add_money("copper",random(20));
    set_emotes(3, ({"%^BLUE%^The gnome stands guard watchfully.", "%^BLUE%^The gnome guard eyes you appraisingly.", "%^BLUE%^The gnome guard picks up a few rocks to help out and tosses them in the cart.", "%^BLUE%^The guard polishes his weapon as he watches you out of the corner of his eye.", "%^BLUE%^The gnome peers into the next room cautiously.", "%^BLUE%^The gnome smiles at one of the miners and helps push an empty cart closer to his work."}),0);
	 set_achats(4, ({"%^BOLD%^%^BLUE%^The gnome guard tries to protect the miners from your attack!", "%^BOLD%^%^BLUE%^The gnome guard swings his weapon in a wide sweep to try to keep you at a distance.", "%^BOLD%^%^BLUE%^The guard fights bravely to protect the others.", "%^BOLD%^%^BLUE%^The guard steps in front of the battle to try to give the others time to run.", "%^BOLD%^%^BLUE%^The guard tries to push a cart at you to make time to escape." }) );
    set_new_exp(1, "very low");
}

