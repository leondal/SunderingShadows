//Added to give Commander Greenshield somewhere to work. Consider remodeling if the situation in Antioch changes and a new commander takes his place. Kismet. 
//Ready to be installed. Proper path is: /d/antioch/antioch2/rooms/commanders_private Kismet.

#include <std.h>
#include "../antioch.h" 
inherit CVAULT;

void create()
{
    ::create();
	set_terrain(WOOD_BUILDING); 
	set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",2);
	set_property("teleport proof",67);
    set_short("The Commander's Private Quarters");
    set_long("The Commander's Private Quarters\n"+
"This small room functions as the commander's private quarters, as well as a closed-off meeting area. It hosts a relatively big table, circled by wooden chairs, and a small cupboard. On the wall above the table hangs a large painting of the sun setting over a warm mountain range. There is a fireplace set into the southern wall, providing some warmth and comfort on cold days, as well as an area to brew tea.  Just west of the fireplace, a room divider of Tsarven origin provides some privacy to a simple bed, a chest of clothes and a small wash-bin. A window set in the west wall gives a view of the King's forests behind Antioch."
    );
	set_smell("default","It smells of herbal tea and tobacco.");
    if(query_night() == 1) {
        set_listen("default","It is quite silent. Perhaps you can hear the crackle of the fire or a prisoner cry far below.");
        }
    else {
        set_listen("default","The chatter of the guards from below fills the room.");
    }
    set_items(([
        "table" : "The square table takes up quite a lot of room and has seen its fair share of use. A cup of tea can often be found sitting neatly upon it.",
        "fireplace" : "The modest fireplace adds a bit of warmth to the room. There is a hook inside, on which one could place a pot for brewing tea.",
		"cupboard" : "The small cupboard is made from wood and contains plates and a small set for brewing and serving tea.", 
		"door" : "A narrow doorway leads out to the main office.",
		"painting" : "The painting is professionally done and shows the sun setting above the vast mountain range known as Talzashaar's Teeth in the Tsarven Kingdom.",
		"window" : "Looking through the window, you see the king's forest spread out to the west, with the mountains looming not far behind.",
    ]));
	set_exits(([
        "east" : ROOMS+"commanders_office",
    ])); 
    set_door("door",ROOMS+"commanders_office","east",0);
	set_locked("door", 1, "lock");
		lock_difficulty("door", get_phouse_lock_dc("epic"), "lock");
}
