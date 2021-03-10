#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("The gardens of the castle Moirbin");
set ("day long", "%^GREEN%^As you pass through the huge gates of iron, you notice right away, the <guards>.  As they stand motionless, you have the feeling that they could jump into action and death at any moment.  The grounds are lush green, with many different trees and flowers to titillate your senses.%^RESET%^");
set ("night long", "%^CYAN%^As you pass through the huge gates of iron, you notice right away the <guards>.  As they stand motionless, you have the feeling that they could jump into action and death at any moment.  The grounds are filled with lush green moss, trees and flowers.  This is all lit by different coloured <globes> to light your way.%^RESET%^");
set_smell ("default", "%^CYAN%^The fragrance of a thousand flowers hovers in the air.");
set_listen ("default", "You hear birds, squirrels and the wind whispering through the trees.  Was that laughter you heard, as well?");
set_exits (([
"east" : "/d/dagger/Elvanta/forest/roomgarden3",
"gate" : "/d/dagger/Elvanta/forest/roomgarden1"
]));
set_items
(([
"moonbeam" : "Thank whatever Gods there may be that you have some light at least.",
"globes" : "Great cirles of light pour from these globes, lighting the way for you and other travellers.  They hang from intricately forged silver chains, which give off a glow of their own.",
"lights" : "Is it your imagination or just wishful thinking perhaps, but you see high in the trees to the northwest flickering points of light."
]));
}
void reset() {
::reset();
new("/d/dagger/Elvanta/forest/mon/guard")->move(this_object());
}
