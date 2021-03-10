#include <std.h>
#include "/d/dagger/drow/short.h"
inherit MONSTER;
void init() {
    ::init();
    add_action("free_func","free");
}
void create() {
    :: create();
    set_name("slave");
    set_id(({
   "slave","elf","elven slave"
    }));
   set_short("%^GREEN%^Elven slave%^RESET%^");
    set_long(
	"%^GREEN%^The elven slave is dressed in dirty rags. "
	"His tear streaked face cries to you his misery."
	"He wears shackles around his legs and is very malnourished. "
	"You feel sorrow for this creature."
    );
    set_gender("male");
    set_hd(5,1);
    set_size(2);
    set_wielding_limbs(({"right hand","left hand"}));
    set_overall_ac(9);
    set_hp(32);
    set_max_hp(32);
    set_exp(200);
    set_body_type("humanoid");
    set_race("elf");
    set_class("mage");
    set_guild_level("mage",5);
    set_stats("strength",16);
    set_stats("constitution",9);
    set_stats("dexterity",16);
    set_stats("wisdom",12);
    set_stats("intelligence",15);
    set_stats("charisma",10);
    set_alignment(1);
    new ( OPATH "bread.c" )->move(TO);
    set_emotes(10, ({
	"The slave cries pitifully.",
	"The slave looks around in desperation.",
	"The slave pulls a small piece of bread out of fold in the rag "
	"and munches it down.",
	"Slave sighs.",
   "%^MAGENTA%^Slave says%^RESET%^: Please free me!"
    }),0);
}
int free_func(string str) {
    if(!str) {
	notify_fail("Free what?\n");
	return 0;
    }
    if(str != "slave") {
	notify_fail("Free what?\n");
	return 0;
    }
    write("%^GREEN%^"
	"You break the shackles which bind the slave!\n"
	"The slave quickly runs off, leaving a piece of bread "
	"behind.%^RESET%^"
    );
    say("%^GREEN%^"
	+TPQCN+" breaks the shackles which bind the slave!\n"
	"The slave quickly runs off, leaving a piece of bread "
	"behind.%^RESET%^"
    ,TP);
    TP->add_exp(100);
    TO->remove();
    return 1;
}
	
