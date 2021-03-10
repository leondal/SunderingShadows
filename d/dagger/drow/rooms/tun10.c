#include "/d/dagger/drow/short.h"
#include <std.h>
inherit "/std/room";
void create() {
    object ob;
    ::create();
   set_terrain(NAT_TUNNEL);
   set_travel(FOOT_PATH);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("%^BLUE%^Dark cavern tunnel%^RESET%^");
    set_long(
	"%^BLUE%^The tunnel continues from the pile of bones another forty "
	"feet, bringing you to an abrupt stop. Ahead of you, deeper into "
	"the tunnel, a %^CYAN%^wall of fog%^BLUE%^ totally fills the "
	"tunnel. The %^CYAN%^fog%^BLUE%^ billows and swirls in and out "
	"continually and is made up of hues of %^RED%^red%^BLUE%^, "
	"%^GREEN%^green%^BLUE%^ and %^MAGENTA%^purple%^BLUE%^. Something "
	"from within the %^CYAN%^fog%^BLUE%^ compels you to continue "
	"through it.%^RESET%^"
    );
    set_listen("default",
	"A howl roars from within the fog causing the hair to stand on "
	"the back of your neck."
    );
    set_items(([
	"lichen":"%^MAGENTA%^The lichen is of a very unusual type and "
	"seems to provide the light source within the cavern "
	"tunnel.%^RESET%^",
	"fog":"%^CYAN%^The fog is foreign to you. It seems to have the "
	"property to suggest you to enter into it.%^RESET%^",
	"walls":"The walls are bare stone and obviously have been carved "
	"through the mountain. Glowing %^MAGENTA%^lichen%^RESET%^ grows "
	"on the walls here."
    ]));
    set_exits(([
	"south": RPATH "tun9",
	"fog": RPATH "tun11"
    ]));
/* removing non-IC boards where they have outlived their usefulness
    ob=new(BBOARD);
    ob->set_name("board");
    ob->set_id(({"board","drow board"}));
      ob->set_board_id("drow");
    ob->set_max_posts(40);
    ob->set_location( RPATH "tun10" );
      ob->set_short("%^BLUE%^Drow Board%^MAGENTA%^");
    ob->set_long(
	"This is the board for information, comments and suggestions "
	"about the drow areas. "
    );
*/
}
