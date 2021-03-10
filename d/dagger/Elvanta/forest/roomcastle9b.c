#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short("Moirbin Castle, the King and Queens Bedroom");
set_long("%^CYAN%^The King and Queen's bedroom is as grand as any other part of the castle, however, it is also made for comfort and love.  Subdued lighting supplied by hanging globes casts a warm glow over a large bed.  Tables laden with bottles of scent and oddly shaped containers with even odder contents rest beside the bed.
%^CYAN%^The walls are inlaid with woods of every hue, creating pastoral scenes, scenes of great battles and heroes of another age.%^RESET%^");
set_smell("default", "%^MAGENTA%^Incense and perfumes rise from the bottles");
set_listen("default", "%^CYAN%^You only hear echoes of laughter and perhaps a girlish giggle or two.");
set_exits( ([
"north" : "/d/dagger/Elvanta/forest/room6b",
"south" : "/d/dagger/Elvanta/forest/roomdruid2",
"east" : "/d/dagger/Elvanta/forest/roomcastle4b", 
"west" : "/d/dagger/Elvanta/forest/roomcastle8b", 
]) );
set_items(([
"bottles" : "Hand blown elegant bottles of soft blues and purples hold perfumes and oils",
"containers" : "Oddly shaped containers hold slaves and potions for whatever purpose unknown to you.",
"walls" : "The intricate inlay work done by a masters hand creates scenes of great battles of another age.",
"globes" : "The globes here cast a golden glow upon everything and everyone who enters this room"
]) );
if(!present("dragonbed"))
new("/d/dagger/Elvanta/forest/mon/dragonbed")->move(TO);
}
