#include <std.h>
inherit OBJECT;

void create()
{
::create();
set_name("bed");
set_short("a bed");
set_long("%^BOLD%^RED%^The bed is in the shape of a dragon, with wings half furled.  The head board contains the shoulders and head of the dragon and its eyes glare at you as they are reflected in the globes light.");
set_weight(1000);
set_value (0);
if(!present("dragonbed"))
new("/d/dagger/Elvanta/forest/mon/dragonbed")->move(TO);
}
