//  The Watchers's Guild Hall
//  Thorn@ShadowGate
//  970216
//  Watcher's Guild
//  guildhall.c

#include <std.h>

inherit ROOM;

void create() {
  room::create();
	set_light(2);
	set_indoors(1);
	set_property("no teleport",1);
	set_property("no attack",1);
	set_property("no steal",1);
	set_short("Guild Hall of the Watchers");
  set_long(
@WATCHERS
%^BOLD%^MAGENTA%^Guild Hall of the Watchers%^RESET%^
  You have found yourself in a gigantic underground gallery of
some form.  The walls have been carved into sculptures of
strange and wonderful creatures.  Bookshelves line the other
spaces in the chamber, giving the impression of a giant library,
larger than the Great Libraries of the southern realms.  This is
the hall of the Watcher's Guild, a society made up of people of
all backgrounds who have the common goal of the gaining of
knowledge.
  Up the stairs, you see some people unloading some precious
finds for cataloguing and storage which can be made available
for the use of guild members.
  To the east is the guild situation room.  This room is the
nexus of the guild's information network, and thus any guild
member who is there can use the services of the network for less
money than usually required.
  You can leave the hall by pulling the lever in the back of the
room, leading back to the Scribe's Office.
  A huge seal has been set into the floor in the center of the
room.
WATCHERS
    );
	set_exits(([
	"up" : "guildstore",     
	"east" : "situation",     
  ] ));     
	set_items(([
		"bookshelves" : "The shelves seem to be sagging under the strain of huge bound tomes.",
		"stairs" : "The stairs are ornately carved stone leading up to a higher gallery.",
		"gallery" : "Carved out from a large underground cave, the gallery is cool and slightly musty.",
		"seal" : (: "seal_fun" :),
  ] ));
}

init()
{
	::init();
	add_action("pull", "pull");
}

int seal_fun()
{
	return write(
@SEAL
%^MAGENTA%^                         %^RESET%^
%^MAGENTA%^         *  *  *         %^RESET%^
%^MAGENTA%^     * OOOOOOOOOOO *     %^RESET%^
%^MAGENTA%^     OOO         OOO     %^RESET%^
%^MAGENTA%^  * OO    Truth    OO *  %^RESET%^
%^MAGENTA%^   OO               OO   %^RESET%^
%^MAGENTA%^ * OO @@@@     @@@@ OO * %^RESET%^
%^MAGENTA%^   OO@@@@@@@ @@@@@@@OO   %^RESET%^
%^MAGENTA%^ * OO@    @@@@@    @OO * %^RESET%^
%^MAGENTA%^   OO      @@@      OO   %^RESET%^
%^MAGENTA%^  * OO     @@@     OO *  %^RESET%^
%^MAGENTA%^     OOO   @@@   OOO     %^RESET%^
%^MAGENTA%^     * OOOOOOOOOOO *     %^RESET%^
%^MAGENTA%^         *  *  *         %^RESET%^
%^MAGENTA%^                         %^RESET%^
SEAL
	);
}

int pull(string str) 
{
	if(str != "lever") return 0;
	else TP->move_player("/d/shadow/room/main/scribe");
	return 1;
}
