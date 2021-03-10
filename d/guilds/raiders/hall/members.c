// /d/guilds/raiders/hall/members.c

#include <std.h>

inherit "/std/guilds/members";

object ob;
void create(){
   	::create();
   set_terrain(BUILT_CAVE);
   set_travel(PAVED_ROAD);
   	set_indoors(1);
   	set_light(1);
   	set_short("Members room");
   	set_long(
@DESC
The room is very dim. The only light source is a candle set 
atop a large rectangular table with chairs in the center of 
the room. The room is all dark stone, mostly granite. Small 
flickers of mica can be seen in the walls as the gentle light 
reflects against the rock. One wall is covered a large 
tapestry of purple hues.  The table is covered with playing 
cards, jewelry and several valuable coins from around the 
realms. It looks as if a pokiir game was abruptly dropped for 
something better.
DESC
   	);
   	set_smell("default","The smell of damp mildew can be detected in the air.");
   	set_listen("default","Your footsteps echo around the room as your feet "+
   		"hit the cold hard floor.");
    set_search("jewelry",(:TO,"find_ring":));
   	set_exits(([
      	"up":"/d/guilds/raiders/hall/entrance.c",
      	"north":"/d/guilds/raiders/hall/hallway.c",
      	"west":"/d/guilds/raiders/hall/office.c",
   	]));
   	set_items(([
      	"tapestry":"It appears to be magical in nature, with a list of names "+
      		"woven into the threads.",
		"jewelry":"A variety of jewelry covers the table, running the "+
		    "gamut from rings to necklaces.  Perhaps you could search "+
			"through the jewelry to find an interesting trinket.",
   	]));
   	
   	set_guild_name("The Raiders in Night's Cloak");
   	set_guild_object("/d/guilds/raiders/obj/earring.c");
}

int found;
int find_ring(){
     object ob;
    if (! found){ 
      tell_object(TP,"As you search through the jewelry, you come "+
	     "across an intriguing earring.");
      tell_room(TO,"As "+TPQCN+" searches the through the jewelry, "+
	     ""+TP->query_subjective()+" finds a intriguing earring.",TP);
      ob = new("/d/guilds/raiders/obj/earring.c");
      ob->move(TO);
     found = 1;
      return 1;
   }
   return 0;
}
