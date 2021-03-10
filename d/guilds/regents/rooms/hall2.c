#include <std.h>
inherit "/std/guilds/members.c";

void create()
{
	object obj;
	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("light",3);
	set_property("no sticks",1);
//	set_property("no teleport",1);
    set_guild_name("Regents of the Silver Lore");
    set_guild_object("/d/guilds/regents/obj/bracelet.c");
	set_short("Basement of the theatre");
	set_long(
	"You are in the guild hall of the Regents of the %^BOLD%^Silver%^RESET%^"+
	" Lore. It is an organized basement of the theatre. Costume racks and"+
	" prop tables are set up along the southern wall. Painted wooden sets"+
	" from previous plays are stacked against the western wall. The center"+
	" of the room is left fairly clear and a couch has been positioned near"+
	" the south. Several cushioned chairs are scattered across the floor"+
	" and there is a love seat in one corner of the room. A lovely ebony"+
	" desk with matching chair have been placed in the northwestern corner."+
	" The desk is for anyone who finds themselves struck by a creative"+
	" streak and feel impelled to begin writing. Paper and ink supplies are"+
	" found on top of the table. On the north wall is a board for guild"+
	" members to post on. There is also a sign posted beneath the board."
	);
	set_smell("default","There is a musky smell to the room.");
	set_listen("default","The thick walls prevent any sounds from traveling"+
	" down here.");
	set_items(([
	({"floor","carpet","green carpet"}) : "%^GREEN%^A thin green carpet"+
	" covers the floor of the room.",
	"ceiling" : "From the ceiling hang several oil lamps that light the room.",
	({"lamp","lamps","oil lamp","oil lamps"}) : "Oil lamps hang down from"+
	" the ceiling, providing the room with light.",
	({"wall","walls"}) : "The walls of the room are cluttered with costume"+
	" racks, prop tables, posting boards, and old sets.",
	({"prop table","props","prop tables"}) : "Prop tables are found on the"+
	" southern side of the room. They are more organized than the one"+
	" upstairs was, but that doesn't really say much. Props from previous"+
	" plays that can likely be used again, or are too memorable to let go,"+
	" are found on the tables.",
	({"costume rack","costume racks","costumes"}) : "Racks of costumes are"+
	" set up next to the prop tables on the south. All sorts of costumes can"+
	" be found dangling from them, anything from the royal garb of a king to"+
	" that of a street prostitute.",
	({"sets","wooden sets","painted wooden sets"}) : "Wooden sets from past"+
	" productions are carefully stacked against the west wall. Some of them"+
	" can be used again, like those of forests or castles, while others can"+
	" be painted over and re-used later.",
	"couch" : "%^YELLOW%^A comfortable beige couch is positioned in front"+
	" of the prop tables, though it doesn't block them. It looks a little"+
	" worn, but still in fairly good condition.",
	"love seat" : "%^BOLD%^%^BLUE%^A cute little sapphire blue love seat"+
	" can be found in the southwestern corner of the room. The back of it"+
	" is heart-shaped and it is the favorite seat of Margath and Bryanna,"+
	" that is when their busy schedules actually permit them to sit down"+
	" together.",
	({"chairs","cushioned chair"}) : "Several mahogany chairs are padded"+
	" with %^GREEN%^forest green%^RESET%^ cushions for extra comfort."+
	" They are scattered about the room for guild members to sit on.",
	({"desk","ebony desk","writing desk"}) : "%^BOLD%^%^BLACK%^A lovely"+
	" ebony writing desk is in the northwestern corner. It is quite"+
	" expensive looking and doesn't have a scratch on it. A drawer"+
	" contains writing paper and there is a pot of ink with a quill in"+
	" it on the desk top. Anyone who gets the inspiration to write"+
	" something is free to use this desk.",
	({"chair","ebony chair","matching chair"}) : "%^BOLD%^%^BLACK%^An"+
	" exquisite ebony chair perfectly matches the writing desk. It is"+
	" ornately carved and quite beautiful. It is subtly padded with"+
	" black velvet cushions to make it comfortable.",
	({"ink","paper","supplies","ink supplies","paper supplies","paper and ink supplies","table top","pot of ink","quill"}) : "A large stack of paper"+
	" can be found in a desk drawer. A pot of ink and a quill sit on"+
	" the desk top, waiting to be used.",
	"stairs" : "Stairs leading out of the basement are on the east.",
	"sign" : "What a pretty sign, you should try reading it.",
	]));
	set_exits(([
	"stairs" : "/d/guilds/regents/rooms/hall1.c",
	]));
	set_pre_exit_functions(({"stairs"}),({"go_stairs"}));
	obj = new("std/bboard");
	obj->set_name("board");
	obj->set_id(({"board","bulletin board","regents board"}));
	obj->set_board_id("regents_board");
	obj->set_short("Regents of the Silver Lore event board");
	obj->set_long("This is a large board that the members of Regents of"+
	" the Silver Lore may post on.");
	obj->set_max_posts(50);
	obj->set_location("/d/guilds/regents/rooms/hall2.c");

}

int go_stairs()
{
	write("You walk up the narrow stairs.");
	return 1;
}

void init()
{
	::init();
	add_action("sit","sit");
    // add_action("get_stuff","get");
}

void sit(string str)
{
	if(str == "couch") {
		tell_object(TP,"%^YELLOW%^You plop down on the comfortable couch.");
		tell_room(ETP,"%^YELLOW%^"+TP->query_cap_name()+" plops down"+
		" on the comfortable couch.",TP);
		return 1;
	}
	if(str == "chair") {
		tell_object(TP,"%^GREEN%^You sit down on one of the numerous"+
		" chairs scattered about the room.");
		tell_room(ETP,"%^GREEN%^"+TP->query_cap_name()+" sits down"+
		" on one of the numerous chairs that's scattered about the room.",TP);
		return 1;
	}
	if(str == "ebony chair" || str == "desk") {
		tell_object(TP,"%^BOLD%^%^BLACK%^You slide into the ebony chair"+
		" and prepare to create a master piece.");
		tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->query_cap_name()+" slides"+
		" into the ebony chair and prepares to create a master piece.",TP);
		return 1;
	}
	if(str == "love seat") {
		if((string)TP->query_name() == "margath" || (string)TP->query_name() == "bryanna") {
			tell_object(TP,"%^BOLD%^You sink down into the cozy %^RED%^love%^WHITE%^"+
			" seat.");
			tell_room(ETP,"%^BOLD%^"+TP->query_cap_name()+" sinks down into the"+
			" cozy %^RED%^love%^WHITE%^ seat.",TP);
			return 1;
		}
	tell_object(TP,"That love seat is reserved for Margath and Bryanna!");
	return 1;
	}
	if(str == "floor") {
		tell_object(TP,"You take a seat on the cold hard floor.");
		tell_room(ETP,""+TP->query_cap_name()+" takes a seat on the cold"+
		" hard floor.",TP);
		return 1;
	}
}

/*
void get_stuff(string str)
{
	if(str == "silver bracelet") {
		if(present("silver bracelet",TP)) {
			tell_object(TP,"Don't be greedy, you already have one.");
			return 1;
		}
		else {
			tell_object(TP,"You pick up a %^BOLD%^silver%^RESET%^ bracelet"+
			" off one of the prop tables.");
			tell_room(ETP,""+TP->query_cap_name()+" picks up a %^BOLD%^silver%^RESET%^"+
			" bracelet off of one of the prop tables.",TP);
			new("/d/guilds/regents/obj/bracelet.c")->move(TP);
			return 1;
		}
	}
}
*/
