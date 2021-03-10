#include <std.h>
#include "../antioch.h"
inherit WEAPONLESS;

void create()
{
	::create();
	set_name("Gaille");
	set_short("Gaille, a kindly old woman");
   set_id(({"citizen","woman","female","human","gaille","Gaille","kindly woman","old woman"}));
	set_long(
	"Gaille is probably in her forties. Her dark red hair is slowly beginning to"+
	" turn a lighter shade, and has streaks of white running through it. Her smile"+
	" is still bright, and her blue eyes twinkle merrily. She has a wedding band"+
	" that she wears on her right hand, so she is probably a widow. She does not"+
	" seem unhappy with her life, however. She was probably once a very pretty woman"+
	" but has let her figure go. Her arms are still strong, however, and you can"+
	" see smudges of dirt on her face and hands from working in the garden."
	);
	set_gender("female");
	set_race("human");
	set_hd(1,5);
	set_alignment(1);
	set("aggressive",0);
	set_wimpy(30);
	set_exp(1);
}
