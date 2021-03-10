// made this board used for posting (only) by mortals via avatarmail command
// *Styx* 6/2002

#include <std.h>
inherit ROOM;

void place_board()
{
   object obj;
   if(!present("avatarmail board")) {
	obj = new("std/bboard");
	obj->set_name("avatarmail board");
	obj->set_id(({"board", "bulletin board","avatarmail board"}));
	obj->set_board_id("ava2_board");
	obj->set_short("The Mail Discussion Board");
        obj->set("long", "A large board where mail from players asking for help "
           "help goes when they use the <avatarmail> command.  It is meant to "
           "facilitate the immortal discussions of the "
           "requests and/or for immortals to let others they have responded.");
       obj->set_max_posts(400);
	obj->set_location("/d/dagger/avaboard2.c");
        obj->set_ooc_board(1);
//added by Styx 6/02 just in case a mortal ends up in the room
       obj->set_restricted_read();
   }

}

void create() {
	::create();
	set_property("no teleport",1);
	set_property("indoors",1);
	set_property("light",2);
	set_short("Mail Discussion Board");
	set_long(
	"This room is bare except for the large posting board in the center of it."+
	" It is where the avatars and wizzes can post responses to mails they"+
	" all receive, instead of filling up someone's mail box with one sentence"+
   " answers.\n"+
   "There is a large dresser that has been put on the back wall that appears to have kits of makeup (?) scattered about it."
	);
	set_smell("default","You smell the wet ink from one of Mielikki's latest novels.");
	set_listen("default","You hear whispered voices in your head.");
   set_items(([
   ({"dresser","kit","makeup kit","makeup"}) : "There are several kits of makeup here. It looks like you could grab a kit if you wanted one...if you're into that stuff, that is.\n"+
   "You can use the kits to <sethair> or <seteyes> for your avatar characters.",
   ]));
	set_exits(([
	"west" : "/d/dagger/avalounge",
	"east" : "/d/dagger/pkboard",
        "bodytyper":"/d/dagger/bodyhold",
        "colors" : "/d/dagger/colorhold",
	]));
    //place_board();
}

void reset()
{
    ::reset();
    place_board();
}

void init() {
   ::init();
   add_action("grab","grab");
}

void grab(string str) {
   if(str != "kit" && str != "makeup") {
      tell_object(TP,"No grabbing that! Go for the kit.");
      return 1;
   }
   new("/realms/crystal/obj/makeup")->move(TP);
   return 1;
}
