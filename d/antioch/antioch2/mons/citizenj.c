#include <std.h>
#include "../antioch.h"
inherit WEAPONLESS;

void create()
{
	::create();
	set_name("Cendamar");
	set_short("Cendamar, a citizen of Antioch");
	set_id(({"citizen","male","man","half-elf","Cendamar","cendamar"}));
	set_long(
	"Cendamar is a rather attractive man. He has a very handsome face with delicate"+
	" features from his elven heritage, and yet his body is fleshed out with the"+
	" muscles from his human side. He has shoulder length brown hair, and deep"+
	" emerald green eyes. There is always a smile on his face. You notice a wedding"+
	" band on his finger, his wife must be very happy."
	);
	set_gender("male");
	set_race("half-elf");
	set_hd(1,5);
	set_alignment(1);
	set("aggressive",0);
	set_wimpy(30);
	set_exp(1);
}
