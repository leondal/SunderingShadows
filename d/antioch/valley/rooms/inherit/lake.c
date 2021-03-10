#include <std.h>
#include "../../valley.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(SHORE);
   set_travel(FOOT_PATH);
	set_property("outdoors",3);
	set_property("light",2);
   set_short("%^BOLD%^%^CYAN%^Secluded Lake%^RESET%^");
	set_long(
	"%^CYAN%^A %^BOLD%^waterfall%^RESET%^%^CYAN%^ pours into a"+
        " large %^BOLD%^%^BLUE%^lake%^RESET%^%^CYAN%^, churning"+
	" the %^BOLD%^crystal blue%^RESET%^%^CYAN%^ waters and causing ripples to"+
	" spread out to the shore. The lake itself is large"+
	" but the %^BOLD%^%^WHITE%^mist%^RESET%^%^CYAN%^ from the waterfall obscures the"+
	" other side so you can't see exactly how big it"+
	" is.  It is also very deep, you can't even see the"+
	" bottom of the %^BOLD%^%^BLUE%^lake%^RESET%^%^CYAN%^, it's just a seemingly endless"+
	" %^BLUE%^blue%^CYAN%^. The shores of the lake are %^ORANGE%^sandy%^CYAN%^ but merge"+
	" with the %^GREEN%^grass%^CYAN%^ as it gets closer to the valley."+
	" Everything here seems so %^BOLD%^calm%^RESET%^%^CYAN%^, as though it's"+
	" separate from the rest of the world.\n"
	);
	set("night long",
	"%^CYAN%^A %^BOLD%^waterfall%^RESET%^%^CYAN%^ cascades down"+
        " a cliff into the %^BOLD%^%^BLUE%^lake%^RESET%^%^CYAN%^,"+
	" creating ripples that trail to the shore. The"+
	" lake is very large and you cannot see the other"+
	" side this %^BLUE%^night%^CYAN%^, the %^BOLD%^%^WHITE%^moonlight%^RESET%^%^CYAN%^ seems to fall"+
	" short and leaves it in darkness. The waters of"+
	" the lake are a %^BLUE%^deep blue%^CYAN%^ and reflect almost"+
	" like a %^BOLD%^mirror%^RESET%^%^CYAN%^. The ripples seem to be"+
        " %^BOLD%^%^WHITE%^silver%^RESET%^%^CYAN%^"+
	" rings, disturbing the reflection as they pass."+
	" The shores of the lake are covered with fine"+
	" %^ORANGE%^sand%^CYAN%^ that blends with %^GREEN%^grass%^CYAN%^ as it gets closer"+
	" to the valley. Everything here is so still,"+
        " as though forever undisturbed from the rest of"+
	" the world.\n"
	);
	set_smell("default",
	"You smell the mist from the waterfall as it"+
	" drifts against your face."
	);
	set_listen("default",
	"The waterfall splashes into the lake in the"+
	" background and you can hear the waves as they"+
	" lap against the shore."
	);
	set_items( ([
	"waterfall" : "%^BOLD%^%^CYAN%^The waterfall cascades down the cliff"+
	" and crashes into the lake.",
	"lake" : "%^BOLD%^%^BLUE%^The waters of the lake are clear and seem"+
	" almost depthless.",
	"sand" : "%^ORANGE%^The sand is pale and very fine.",
	]) );
}
