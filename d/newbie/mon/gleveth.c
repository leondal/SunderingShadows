#include <std.h>
#include "../newbie.h"
inherit NPC;

void create() {
	::create();
	set_name("Gleveth");
	set_short("Gleveth, bank teller of Offestry");
	set_id(({"bank teller","Gleveth","gleveth","teller"}));
	set_long(
	"Gleveth is a middle-aged man who seems down to earth. He is a little impatient"+
	" with the customers, but never seems to make an error with his math. A pair"+
	" of glasses are perched on his nose so that he can see well enough to write"+
	" everything carefully down for the bank's records. He is very meticulous about"+
	" the record keeping, and you feel you can probably trust him with your money."
	);
	set_race("human");
	set_gender("male");
	set_hd(19,5);
	set_alignment(2);
	set_max_hp(200);
	set_hp(200);
	set_exp(10);
    set_db("teller");
    set_random_act_db("tellerrandom");
    remove_std_db();
        new("/d/newbie/obj/misc/lpouch.c")->move(TO); //added in on advice of Tristan that we need more stealable things in newbieland Ts
}
