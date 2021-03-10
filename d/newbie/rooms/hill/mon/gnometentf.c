// /d/newbie/rooms/hill/mon/gnometentf.c

#include "../../../newbie.h";
inherit MONSTER;

void create() {
    ::create();
    set_name("gnome");
    set_id(({"gnome","gnome female"}));
    set_race("gnome");
    set_body_type("human");
    set_gender("female");
    set_short("Gnome female");
    set_long("This female gnome looks quite a bit like a small, slender dwarf except you can't miss her typical gnomish bulbous nose and rounder face.  She is dressed in bright clothes that bring out her sparkling blue eyes.  Her pale gray hair must not be from age since she looks fairly young.");
 	 set_class("fighter");
    set_hd(2,1);
    set_hp(40);
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
    set_exp(15);
    new(FOREST"stuff/journal")->move(TO);
    if(random(2)) {
        new("/d/newbie/obj/clothing/c_clasp")->move(TO);
        command("wear clasp");
    }
    add_money("silver",random(10));
    add_money("copper",random(20));
    set_emotes(2, ({"%^BOLD%^The female gnome reads over the paper in her hand.", "%^BOLD%^The female gnome brushes the dust off the tent walls.", "%^BOLD%^The little gnome smiles at you somewhat cautiously.", "%^BOLD%^%^BLUE%^The gnome's eyes sparkle in the light as she polishes a gem.", "The female gnome mumbles about hobgoblins and shudders as she patches a hole in the tent."}), 0);
   set_achats(2, ({"%^BOLD%^The small gnome cries out in fear as she tries to defend herself.", "%^BOLD%^The small gnome tries to run past you to escape.", "%^BOLD%^The female gnome tries frantically to escape.", "%^RED%^The innocent and unarmed gnome's screams of fright will haunt all but the most evil person." }) );
}

void init(){
    ::init();
	 force_me("tent");
}
