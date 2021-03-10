#include <std.h>
#include "../antioch.h"
inherit VAULT;

int found;

void create()
{
	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_short("%^RED%^Rose Room");
	set_long(
	"%^RED%^The Rose Room\n"+
	"%^BOLD%^It is easy to tell how this room got its name, for it"+
	" smells like roses. Most of the furniture is made out of cherry"+
	" wood and the carpet and walls are a ruby shade. A vase of red"+
	" roses sits on the dresser on the right hand side of the room."+
	" The dresser is very large, taking up most of the length of the"+
	" wall and is approximately five feet in height. An oval shaped"+
	" mirror is hung to the side of it and framed in cherry wood in"+
	" the design of a rose vine. This room is obviously for female"+
	" guests, the mirror allows women to admire themselves in their"+
	" outfits and fix their hair before going out. The large canopy"+
	" bed is also done in varying shades of red and is very plush."+
	" Several large heart shaped pillows are on it and it looks quite"+
	" soft and comfortable. Next to the bed is a nightstand with a"+
	" basin of water for washing your face off. On the far side of"+
	" the room is a window that overlooks a little garden and part"+
	" of the palace. The window has thick red curtains pulled back"+
	" on either side of it that can be closed for privacy or to block"+
	" out the light. Candles are placed in sconces in the shape of"+
	" roses around the room."
	);
	set_smell("default","This room smells like roses.");
	set_listen("default","You can hear the wind whistling outside"+
	" the window.");
	set_items(([
	({"candle","candles"}) : "%^RED%^Several thick red candles are"+
	" placed in scones in the shape of roses around the room. The"+
	" candles also seem to be giving off the rose fragrance which"+
	" envelopes the place.",
	"sconces" : "Silver sconces that have been worked into the shapes"+
	" of large roses line the room. Within them are large %^RED%^red"+
	" %^RESET%^candles.",
	({"floor","carpet"}) : "%^RED%^A thick red carpet covers the"+
	" floor, it is easily several inches deep.",
	"dresser" : "A cherry wood dresser is on the eastern wall. It is"+
	" several feet long and about five feet in height. Engraved roses"+
	" decorate the drawers and a vase of %^RED%^red roses%^RESET%^ sits"+
	" on top.",
	"mirror" : "An oval mirror is placed next to the dresser. It reaches"+
	" seven feet in height and the cherry wood frame is copied in"+
	" the likeness of a rose vine.",
	"night stand" : "A nightstand rests next to the bed. On top of"+
	" it is a basin of water for washing.",
	"vase" : "%^BOLD%^A porcelain vase sits on top of the large"+
	" dresser. It holds several beautiful %^RED%^red roses%^RESET%^.",
	"roses" : "%^RED%^Lovely red roses are in a vase on top of the"+
	" dresser. They give off a wonderful fragrance.",
	"basin" : "%^BOLD%^%^MAGENTA%^A pink basin rests on top of the"+
	" nightstand. It contains water for washing your face off.",
	({"bed","canopy bed"}) : "%^RED%^This large canopy bed is very luxurious."+
	" Red silk thinly veils the bed, draping down from the top. Several"+
	" heart shaped pillows are on it and the blankets are also red."+
	" It looks as though you would sink down into it if you laid on"+
	" it, the pillows and bedding are probably made of goose feathers."+
	" The bed looks quite comfortable and it is placed on the western"+
	" side of the room.",
	"window" : "The window on the northern side of the room looks"+
	" out over a small garden and part of the palace. It is framed"+
	" by heavy %^RED%^red curtains%^RESET%^ that can block out the"+
	" light or keep out prying eyes.",
	"curtains" : "%^RED%^Heavy red curtains are pulled back next to"+
	" the windows. They can be let down to keep the light out or"+
	" to give the guests some modesty.",
	({"pillow","pillows"}) : "The pillows are large and heart shaped,"+
	" probably made out of soft goose feathes.",
	]));
	set_exits(([
	"south" : ROOMS+"inn4",
	]));
	set_door("rose door",ROOMS+"inn4","south",0);
	set_search("room","It is a large room, best to search individual"+
	" items.");
	set_search("dresser",(:TO,"search_dresser":));
}

int search_dresser()
{
	if(found) {
		write("You can't seem to find anything in these drawers.");
		return 1;
	}
	else {
		write("You search around in the drawers of the dresser and find"+
		" a couple of candles.");
		say(""+TP->query_cap_name()+" searches around in the drawers of"+
		" the dresser and finds a couple of candles.");
		new(OBJ+"candle")->move(TO);
		new(OBJ+"candle")->move(TO);
		found = 1;
		return 1;
	}
}
