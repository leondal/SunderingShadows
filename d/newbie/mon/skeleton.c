//Styx - essentially copied from /d/deku/monster/skeleton.c

#include <daemons.h>
#include "/d/common/common.h"

inherit "/std/monster";

void create() {
    ::create();
        set_name("skeleton");
        set_id( ({ "skeleton" }) );
        set("race", "undead");
        set_gender("male");
        set("short", "Skeleton");
        set("long", "%^BOLD%^A creature of the undead, this skeleton is just bones that have been cleaned of flesh by time and insects.  Somehow it has been caused to rise and hunt the living.\n");
        set_hd(4,1);
        set_level(4);
        set_body_type("human");
        set_class("fighter");
        set_alignment(9);
        set_size(2);
        set_hp(random(15)+60);
        set_stats("intelligence",6);
        set_stats("wisdom",4);
        set_stats("strength",15);
        set_stats("charisma",3);
        set_stats("dexterity",9);
        set_stats("constitution",7);
        set_max_mp(0);
        set_mp(query_max_mp());
        set_max_hp(query_hp());
        set_max_sp(query_hp());
        set_sp(query_max_sp());
        set_wielding_limbs( ({ "right hand", "left hand" }) );
        new(CWEAP"fauchard")->move(this_object());
        command("wield fauchard");
        add_money("electrum",random(50));
        add_money("gold",random(50));
        set_property("undead",1);
        set_property("swarm",1);
        set("aggressive",15);
        set_overall_ac(9);
        set_exp(100);
}

