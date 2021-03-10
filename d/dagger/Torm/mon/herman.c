#include <std.h>
#include <daemons.h>
inherit TOWNSMAN;

string *killers;

void create() {
	::create();
	killers = ({});
	set_name("herman");
	set_id( ({ "herman", "Herman", "healer"}) );
	set_short("Herman, Private Healer of the Torm Thieves Guild");
	set("aggressive", 0);
	set_level(19);
	set_long("This balding pudgy man busily moves about his small shop, tending to this patient or that and "
"mixing up potions or restocking his salves when he gets a free moment.  He knows he is replaceable, so he "
"works hard to make himself a useful part of his organization.");
	set_languages( ({ "common" }) );
	set_gender("male");
	set_alignment(6);
	set("race", "human");
	set_body_type("human");
	set_property("no attack", 1);
	set_hd(19,3);
	set_level(19);
}

int kill_ob(object victim, int which){
    int hold;
    killers = SAVE_D->query_array("DDguild_killers");
    hold = ::kill_ob(victim, which);
    if(member_array(TPQN, killers) != -1) return hold;
    SAVE_D->set_value("DDguild_killers", TPQN);
    ETO->remove_member(TPQN);
    return hold;
}