#include <std.h>
#include <daemons.h>
inherit "/std/guilds/members.c";

void create()
{
	object obj;
	::create();
   set_terrain(GARDEN);
   set_travel(FOOT_PATH);
	set_property("indoors",0);
	set_property("light",2);
	set_guild_name("The Kindred");
	set_guild_object("/d/guilds/kindred/obj/pendant.c");
	set_short("%^BOLD%^%^GREEN%^The Garden");
	set_long(
	"A large autograph tree stands at the edge of the path here in leiu of"+
	" a posting board. This is where those of the Kindred can write their"+
	" suggestions and ideas for the rest of the guild to read. The tree"+
	" itself is of an average height, its branches spread out wide to either"+
	" side and are low to the ground, very easy to reach. Dark green leaves"+
	" that are round, thick, and hard cover the branches. At the base of the"+
	" tree a collection of old leaves have been gathered together and formed"+
	" into a sort of sign. Each leaf has a name on it, listing the members."
	);
	set_smell("default","A faint scent of honey lingers in the air.");
	set_listen("default","The sound of buzzing bees comes from the northeast.");
	set_items(([
	"sign" : "The leaf sign is here for any to read who wish to know the"+
	" current guild members.",
	"leaves" : "%^GREEN%^The leaves of the tree are rather unusual. They are"+
	" round in shape and rather hard, practically inflexible. They are quite"+
	" easy to write on and a simple scratch of a finger nail leaves a clear"+
	" mark that lasts forever. Writing on the leaves in no way hurts the"+
	" tree, though.",
	]));
	set_exits(([
	"west" : "/d/guilds/kindred/rooms/trail3",
	"northeast" : "/d/guilds/kindred/rooms/bees",
	]));
	obj = new("std/bboard");
	obj->set_name("Autograph tree");
	obj->set_id(({"tree","posting tree","autograph tree"}));
	obj->set_board_id("kindred_board");
	obj->set_short("%^RESET%^%^GREEN%^Autograph Tree%^BOLD%^%^MAGENTA%^");
	obj->set_long("This is a rare tree known as the Autograph Tree. It earned"+
	" its name because people can easily write on the leaves and their"+
	" message will stay on the leaf forever. It doesn't hurt the tree to"+
	" write on the leaves, and occassionally some leaves must be removed in"+
	" order for the tree to grow new ones.\n");
	obj->set_max_posts(50);
	obj->set_location("/d/guilds/kindred/rooms/atree.c");
}

int read_fcn(string str) {
   if(member_array("The Kindred",TP->query_guild()) != -1 || avatarp(TP)) {
      return ::read_fcn(str);
   }  else {
  return 0;
  }
}
