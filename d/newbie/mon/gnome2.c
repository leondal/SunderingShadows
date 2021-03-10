// /d/newbie/mon/gnome2.c

#include "../newbie.h";
inherit MONSTER;

void create() {
    ::create();
    set_name("gnome");
    set_id(({"gnome","mining gnome","miner","gnome miner"}));
    set_race("gnome");
    set_body_type("human");
    set_gender("male");
    set_short("Gnome miner");
    set_long("This creature looks quite a bit like a small, slender dwarf except you can't miss the bulbous nose that dominates his round face.  His hair and short, neatly-trimmed beard and mustache are a pale gray.  Sparkling blue eyes the color of the sky reflect the torchlight and stand in stark contrast to its deep woody brown skin and light hair.  His hands are calloused, probably from swinging his pick and handling the rocks and gems day after day.");
  	 set_class("fighter");
  	 set_level(2);
    add_search_path("/cmds/fighter");
    set("aggressive",1);
    set_wimpy(30);	 
    set_stats("intelligence",12);
    set_stats("wisdom",10);
    set_stats("strength",15);
    set_stats("charisma",10);
    set_stats("dexterity",10);
    set_stats("constitution",17);
    set_property("swarm",1);
    set_alignment(4);
    set_size(1);
    set_exp(10);
    set_hp(45 + random(10));
    new("/d/newbie/obj/misc/mining_pick")->move(TO);
    command("wield pick");
    add_money("silver",random(10));
    add_money("copper",random(20));
    set_emotes(3, ({"%^BOLD%^%^GREEN%^The gnome swings his pick and mines diligently.", "%^ORANGE%^The gnome miner pauses to load the loose rocks into a cart.", "%^BOLD%^The gnome whispers to a guard and looks at you cautiously.", "%^BOLD%^%^GREEN%^The gnome miner brushes some of the dirt from the walls and examines it closely.", "%^ORANGE%^The gnome gives a cart a shove to send it to the next room." }),0);
	 set_achats(3, ({"%^BOLD%^%^MAGENTA%^The gnome yells for the guards and tries to defend himself.", "%^BOLD%^%^MAGENTA%^The gnome fights for his life and tries to escape.", "%^BOLD%^%^MAGENTA%^The gnome swings his pick at you trying to defend himself." }) );
    set_new_exp(1, "very low");
}

