//guild1.c

#include <std.h>

inherit VAULT;

void create(){
  ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
   set_property("no teleport",1);
    
    set_property("light",2);
    set_property("indoors",1);
    set("short","This is the main lounge of the Tharis merchants");
    set("long",
@OLI
	%^BOLD%^%^YELLOW%^The main lounge, where merchants sit and chat.
%^RESET%^This area is filled with cushioned seats and hard wood tables.
There are various charts hanging from the walls. Most of these appear to 
be simply nostalgic. The room is mostly empty of people. If one manages to 
get into this room one can learn much of the trade of this city. Often is 
people listen carefully they can overhear important conversations. There are
two doors here, the east door and the reception door. A hall leads to the 
south to some offices but you can't go there. 
OLI
	);
    set_listen("default","You hear an occasional scratching of chairs on the wooden floor.");
    set_listen("conversations", (:TO, "my_listen":));
    set_listen("people", (:TO, "my_listen":));
    set_listen("merchants", (:TO, "my_listen":));
    set_listen("conversation", (:TO, "my_listen":));

    set_smell("default","The room smells of well sanded wood and newly oiled leather.");
    
    set_exits(([
		"east1":"/d/tharis/Tharis/market9",
		"east2":"/d/tharis/Tharis/guild2",
		"south":"/d/tharis/Tharis/gmasters"
		]));

    set_door("east door","/d/tharis/Tharis/market9","east1","guild key");
    set_door("reception door","/d/tharis/Tharis/guild2","east2","guild key");
    set_items(([
       "charts":"These charts have ore prices and lumber prices from years past",
       "chairs":"These chairs are well cushioned and comfortable."
     ]));

    }

string my_listen(){
    string time;
    
    time = "/daemon/events_d"->query_time_of_day();
    if(time == "day"){
       write("%^BOLD%^%^RED%^You hear a conversation about how ores to the west of the city are being stolen.");
       write(
@OLI
    The speaker, a broad chested dwarf, tells a blunt nosed gnome about 
three shipments or ores from his mines that have been stolen. You lean 
closer hoping to hear more about these thefts. You hear of the reports 
of elven arrows being found near the sites of the attacks. The dwarf says
that no matter how many men he sends with his caravans only a few return.
And they always return running scared from the "Elven marksmen"
   The two leave the room discussing the events and how they might effect the 
ecomnomy and there own walets.
OLI
);
  }
  else {
     write("%^BOLD%^%^RED%^You hear a conversation concerning elves.");
       write(
@OLI
    "...and they wonder why we lock them on the west side of the city,"
says a short fat man to a bearded ugly man. "They have been raiding our
supplies for weeks. Only one in 5 or 6 caravans get through."
   "True True my friend I think maybe our duke has even been too lenient
with this elven menace. It is time for us to move our armies in and destroy
them. Besides if we gain full control of the forest think of the lumber 
revenues." The ugly man grins revealing ivory false teeth.
   "Yes a move against them is in order. But when will the duke move? All the
BLASTED red tape. Those elves claiming to be good and to serve only nature and 
life. How many lives have they served ... served to the god of death!?!"
    They continue to grumble on. Nothing of interest to you is said.
OLI
);
   }
   return " ";
}










