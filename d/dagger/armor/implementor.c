//someone nuked the old seneca dir that contained the retractable claws - Yves 12/2/2019

#include <std.h>
inherit "std/monster";

create() {
    ::create();
    set_name("Shadowy Implementor");
    set_id( ({"shadowy implementor", "implementor", "shadow"}) );
    set("race", "half-elf");
    set_gender("male");
    set_short("Shadowy Implementor");
    set_long(
      "The ancient shadowy implementor once stood guardian over some of the greatest treasures of the Kinnesaruda empire, now he still stands watch, it is just that some of that treasure is now gone.\n   It is a seven foot tall figure cast in darkness with only a single cold red eye peering out at you.  There is no compassion here...  No regret...  No remorse...  Just pain."
    );
    set_body_type("human");
    set_overall_ac(-15);
    set_property("swarm",1);
    set_class("ranger");
    set_mlevel("ranger", 40);
    set_hd(40, 2);
    set_stats("strength", 17);
    set_stats("constitution", 17);
    set_stats("dexterity", 17);
    set_stats("intelligence", 17);
    set_stats("wisdom", 17);
    set_stats("charisma", 17);
    set_property("full attacks",1);
    set("aggressive", 50);
    set_alignment(4);
    set_size( 2 );
    set_max_hp(600);
    set_hp(600);
    set_sp(500);
    set_exp(55000);
    add_money("silver",random(1010));
    add_money("gold",random(1020));
    set_property("no bows", 1);
    new("/d/dagger/armor/cs_armor.c")->move(TO);
    command("wear armor");
    new("/d/attaya/seneca/obj/claw.c")->move(TO);
    new("/d/attaya/seneca/obj/claw.c")->move(TO);
    new("/d/magic/obj/orb_of_scrying.c")->move(TO);
    command("wield blades");
    command("wield blades 2");

}

void init(){
    ::init();
    if(TP->query_invis()&&!wizardp(TP)) {
	tell_room(ETO, "The demon peers deep into your eyes, into your soul, and pulls you from your deception.");
	TP->set_invis();
	kill_ob(TP,1);
    }
    kill_ob(TP,1);
}
