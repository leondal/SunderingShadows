#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_property("indoors",1);
    set_property("light",0);
    set_terrain("nat cave");
    set_travel("ledge");
    set_name("A natural cave");
    set_short("%^RESET%^%^ORANGE%^A natural cave%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This cave is dug deep into the earth and was likely an expansion of a small "
"fissure or other natural occurrence.  Although there is a clear sense of finishing about the chamber, much of "
"it is still left in the raw stone and earth state.  Only about half way up the walls do the mosaic of crude "
"%^RESET%^%^RED%^decorations %^BOLD%^%^BLACK%^extend.  Additional decorations are comprised of half formed "
"%^RESET%^%^ORANGE%^statues%^BOLD%^%^BLACK%^, and at one end, a stone structure that looks to be an %^RED%^"
"altar%^BLACK%^. Scraps of cloth have been lain over this pile of %^WHITE%^bones %^BLACK%^and %^RESET%^"
"%^ORANGE%^rocks%^BOLD%^%^BLACK%^, and behind it, carved into the wall is a large image of a %^RED%^noble "
"dragon%^BLACK%^.  All told, the chamber is twenty feet long and half as wide.  Providing access to the shrine "
"is a curious, free standing staircase made of large %^WHITE%^bones%^BLACK%^ with thick coils of rope to keep "
"it in place and from swinging too much when climbed.  The floor is mostly clear of rubble and debris, looking "
"recently swept and attended.  At the base of the stairs, a deeper indentation with a narrow trough leading "
"away provides a means of draining off any water that leaks down from the foggy forest above.  Clearly the "
"kobolds of the forest care for their shrine.%^RESET%^\n");
    set_smell("default","The air reeks with the smell of decaying remains.");
    set_listen("default","The faint sound of dust shifting catches your attention.");

    set_items(([ 
	({ "dragon" }) : "%^BOLD%^%^RED%^Carved into the wall above the altar is a large image of a dragon "
"sitting upon a pile of skulls.  Though crude in its depiction, the dragon has a noble fatherly look to it.  "
"With his wings close to the body and the tail pulled around his legs, he gazes out of two ruby eyes across "
"the chamber, watching the faithful kobolds that come to worship their version of the earthlord as %^RESET%^"
"%^ORANGE%^Kurtulmak%^BOLD%^%^RED%^.%^RESET%^",
	({ "altar", "cloth" }) : "%^RESET%^%^RED%^The stone altar is little more then a pile of rocks held "
"together with some dried mud.  Bits of metal and wood, gem shards and less identifiable items are set into "
"the mud to decorate the squarish block.  Covering the top are a few scraps of red velvet and dark red leather"
".%^RESET%^",
	({ "statue", "statues" }) : "%^BOLD%^%^BLACK%^None of these statues appear to be whole.  Limbs, tails, "
"snouts and other bits are broken away, but you can tell that every statue is some type of kobold.%^RESET%^",
	({ "fog", "forest" }) : "%^BOLD%^%^BLACK%^Fog curls along the ground of the forest above and spills down "
"through the hole in the ceiling, collecting in a thin pool at the base of the stairs.%^RESET%^",
	({ "bones", "bone", "stairwell", "staircase", "stairs" }) : "%^BOLD%^%^WHITE%^Someone has spent a lot of "
"time and energy to fashion this stairwell.  Created from what appears to be rib bones from giants, the stairs "
"are held together by thick ropes and wind down around themselves in a steep spiral.%^RESET%^",
	({ "decorations", "walls", "wall" }) : "%^RESET%^%^RED%^The decorations in this chamber are simple and "
"made mostly from scraps of cloth, bone, wood and bits of metal.  Things one might find in a trash heap or "
"other cast off area.  Most of these things are burried into the wall about two feet up, and appear to be "
"simply shoved in haphazardly, creating a chaotic mosaic.  A few sections, however, define themselves.  "
"Perhaps you could look closer at these %^WHITE%^sections%^RED%^.%^RESET%^",
	({ "sections", "section" }) : "%^RED%^There are three sections on the wall that look purposeful.  You "
"could look at %^RESET%^section1%^RED%^,%^RESET%^ section2%^RED%^ or %^RESET%^section3%^RED%^.%^RESET%^",
	"section1" : "%^BOLD%^%^BLUE%^This section of the mosaic appears more purposeful then other parts.  As "
"you look close, you see a cave with several kobolds standing before the altar.  They each hold weapons and "
"look ready to fight, a noble stand off.  Before them, gnomes swarm like rats.  All around the gnomes, snakes "
"slither.%^RESET%^",
	"section3" : "%^BOLD%^%^BLACK%^This section shows a %^RESET%^%^ORANGE%^t%^YELLOW%^o%^RESET%^%^ORANGE%^"
"paz %^BOLD%^%^BLACK%^colored kobold holding a gem above his head.  The gem is glittering with a %^RED%^bloody "
"glow%^BLACK%^.  The kobold is turned toward the room, behind him a great dragon rises over an altar.%^RESET%^",
	"section2" : "%^BOLD%^%^GREEN%^This section shows a lone kobold with %^RESET%^%^ORANGE%^t%^YELLOW%^o"
"%^RESET%^%^ORANGE%^paz %^BOLD%^%^GREEN%^colored scales fighting against a giant snake.  The image captures "
"the kobold holding the snake's neck, a dagger in his other paw, poised to strike.%^RESET%^",
    ]));

    set_exits(([ 
	"out" : "/d/deku/forest/dforest37-8",
    ]));
    set_property("blessed",({"grumbar"}));
}