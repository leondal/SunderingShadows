#include <std.h>
#include "/d/common/common.h"

inherit MONSTER;

void create() {

	::create();
	set_name("Ratkin");
	set_id(({"Ratkin","scout", "ratkin", "ratkin scout"}));
	set_race("ratkin");
	set_gender("male");
	set_short("%^RESET%^%^GREEN%^Ra%^MAGENTA%^t%^ORANGE%^k%^GREEN%^in%^CYAN%^ scout%^RESET%^");
	set_long("This is a ratkin, small rat-like humanoid. This particular individual is cloaked, it wears many pouches and bandoliers over its armor. It holds a sword in its hands. Its face can't be seen, but red eyes reflect with menacing glow.");

	set_hd(12, 2);
	set("aggressive",10);
	set_alignment(6);
	set_size(1);
	set_overall_ac(8);
	set_stats("intelligence",8);
	set_stats("wisdom",16);
	set_stats("strength",18);
	set_stats("charisma",4);
	set_stats("dexterity",18);
	set_stats("constitution",12);

        set_class("thief");
        set_mlevel("thief",query_level());
        set_guild_level("thief",query_level());
        set_skill("stealth", query_level());
        set_hidden(1);

        set_monster_feats(({
                    "dodge",
                        "mobility",
                        "evasion",
                        "combat reflexes",
                        "parry"
                        }));

	add_money("gold",random(50));

        {
            object ob;
            ob = new(CWEAP"shortsword");
            ob->set_property("monsterweapon",1);
            ob->move(this_object());
            command("wield sword in right hand");
            ob = new(CARMOR"hide");
            ob->set_property("monsterweapon",1);
            ob->move(TO);
            command("wear armor");
        }

        set_monster_feats(({
                    "dodge",
                        "mobility",
                        "evasion",
                        "combat reflexes"
                        }));

}

init()
{
    ::init();

    if (sizeof(query_attackers())) {
        return;
    }

    if (TP->query_level() > 12 && !TP->query_invis() && !TP->query_hidden()) {
        tell_object(TP,"%^BOLD%^%^WHITE%^Someone stabs you in the back!%^RESET%^");
        TO->add_attacker(TP);
        TP->add_attacker(TO);
    }
}
