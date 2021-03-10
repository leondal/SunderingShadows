// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_u2");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("slick floor");
    set_climate("tropical");

    set_short("%^BOLD%^%^WHITE%^A mage's workroom%^RESET%^");

    set_long("%^RESET%^Clearly a mage's workshop, or what used to be one, this chamber is vast and open.  Lined with %^ORANGE%^shelves %^RESET%^of books, you see that there is a wide verity of topics, though most b"
	"ooks look to be on arcana and weather. A %^BOLD%^%^BLACK%^work table %^RESET%^and a few %^ORANGE%^benches %^RESET%^are off to one side and a %^BLUE%^magic circle %^RESET%^is etched into the floor boar"
	"ds.  Juding by the stumps of %^YELLOW%^candles %^RESET%^and pools of %^BOLD%^%^WHITE%^wax%^RESET%^, the last time someone was in this room they summoned something.  At least one of the %^BOLD%^%^WHITE"
	"%^wax pools %^RESET%^looks disturbed.  Outside on the %^CYAN%^balcony%^RESET%^, you can see some sort of %^BOLD%^%^BLACK%^metal structures%^RESET%^, but not exactly what they are from here.%^RESET%^"
	);

    set_smell("default","
The smell of aged components fills the room.");
    set_listen("default","Surely its just the wind making that slight sound of rushing air.");

    
set_items(([ 
	({ "table", "benches", "work table" }) : "%^BOLD%^%^BLACK%^The furniture looks to be in good repair and very solid.  You imagine it would hold up to a good number of failed spells.%^RESET%^",
	({ "circle", "magic circle" }) : "%^BOLD%^%^BLUE%^The circle is etched into the floor boards and lined with %^RESET%^%^ORANGE%^copper wire%^BOLD%^%^BLUE%^.  This wire, in turn, bundles together and follows a narrow channel to the balcony.%^RESET%^",
	({ "candles", "wax" }) : "%^BOLD%^%^WHITE%^The remains of several candles line the magical ring.  Pools of wax surrounding them and suggesting they burnt down and out.  One pool is disturbed as though something kicked the candle and broke the circle of power.  You wonder what might have done that.%^RESET%^",
	({ "book", "books" }) : "%^BOLD%^%^BLACK%^There are several books on the shelves.  Most look like they deal with arcane matters or weather topics but you notice that there is one that looks like it might be a journal of some sort.%^RESET%^",
	"journal" : "%^BOLD%^%^BLACK%^You open up the journal and read from it:  %^RESET%^Tonight is a full eclipse, although with the anticipated storm, I doubt we'll be able to see it.  Still, I look forward to this storm as it will finally answer the question of whether or not my theory is right.  If I can harness the power of lightning, I'll be able to open a portal to anywhere. It will completely change the way the world works.  Now even remote places such as this plantation will have easy connections to towns and cities without having to concern themselves over the dangers found within the wilds.  I'm excited!  I need to go finish finalizing things.  Jezulfin is in Verbobone buying more of his seeds, but he will await at the appointed place and if everything works out, he'll step through the portal way at the stroke of midnight.%^RESET%^",
	"structures" : "%^BOLD%^%^BLACK%^You can't tell what they are, perhaps you could go outside and take a look.%^RESET%^",
	"shelves" : "%^RESET%^%^ORANGE%^The shelves hold a large selection of books ranging through mostly arcana subjects, though you see there is a good number dedicated to the weather and its effects.  One large book catches your attention, a journal perhaps.  Or maybe a spellbook.%^RESET%^",
	]));

    set_exits(([ 
		"north" : "/d/av_rooms/lurue/dekumage_u3",
		"south" : "/d/av_rooms/lurue/dekumage_u1",
	]));

    set_door("double doors","/d/av_rooms/lurue/dekumage_u2","south","manor key","metal lock");
    add_lock("double doors","manor key","metal lock","This lock looks reasonably simple as though it was meant simply to keep people from bothering the occupant rather then preventing thieves. ");
    set_locked("double doors",1,"metal lock");
    lock_difficulty("double doors",-20,"metal lock");
    set_open("double doors",0);
    set_string("double doors","knock","knock on the ");
    set_string("double doors","open","The double doors swing open silently.");
    set_string("double doors","close","The double doors swing closed silently.");
    set_door_description("double doors","These double doors are made from thick beams of oak and are held together with simple metal facets that give them a stately appearance despite their simplicity.");
}