#include <std.h>
inherit MONSTER;
void init() {
    ::init();
    add_action("free_func","free");
}
void create() {
    :: create();
    set_name("slave");
    set_id(({
   "slave","beaten slave"
    }));
   set_short("%^RESET%^%^ORANGE%^Beaten slave%^RESET%^");
    set_long(
      "This poor man has been beaten and kicked around for what"+
       " you would guess was years. He looks tired, worn out, and"+
        " saddened beyond belief. Like the others, it looks like he"+
        " is carrying tools meant for digging."
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
   set_race("human");
    set_class("mage");
    set_guild_level("mage",5);
    set_stats("strength",16);
    set_stats("constitution",9);
    set_stats("dexterity",16);
    set_stats("wisdom",12);
    set_stats("intelligence",15);
    set_stats("charisma",10);
    set_alignment(1);
    set_emotes(10, ({
	"The slave cries pitifully.",
	"The slave looks around in desperation.",
	"Slave sighs.",
   "%^MAGENTA%^The slave says%^RESET%^: If only someone could free me..."
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
        "The slave quickly runs off, giving praise to the Gods."
    );
    say("%^GREEN%^"
	+TPQCN+" breaks the shackles which bind the slave!\n"
        "The slave quickly runs off, giving praise to the Gods."
    ,TP);
    TP->add_exp(100);
    TO->remove();
    return 1;
}
	
