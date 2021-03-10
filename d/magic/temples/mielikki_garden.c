//by Circe 8/29/04 - desc provided by Lukas
#include <std.h>
inherit ROOM;

void create() {
        ::create();
        set_property("indoors",0);
        set_property("light",2);
        set_terrain(RUINS);
        set_travel(FOOT_PATH);
        set_name("Sheltered Garden");
        set_short("%^RED%^Sheltered garden%^RESET%^");
        set_long("%^BLUE%^The wide branches of a%^RESET%^ %^GREEN%^w"+
           "%^RESET%^%^BOLD%^%^BLUE%^i%^RESET%^%^GREEN%^l%^BOLD%^%^BLUE%^"+
           "l%^RESET%^%^GREEN%^o%^RESET%^%^BOLD%^%^BLUE%^w%^RESET%^ "+
           "%^BLUE%^spread across the the garden, sheltering it in a "+
           "natural curtain.%^RESET%^  %^RED%^De%^RESET%^%^YELLOW%^ad"+
           "%^RESET%^ %^RED%^le%^RESET%^%^YELLOW%^av%^RESET%^%^RED%^es"+
           "%^RESET%^ %^GREEN%^and%^RESET%^ %^RED%^limbs%^RESET%^ "+
           "%^BLUE%^of the old tree decay on the ground whilst others "+
           "crunch under foot.  A few large logs have been moved in, "+
           "turned into impromtu seats and now surround an %^BOLD%^"+
           "%^BLACK%^ash-filled fire pit.%^RESET%^  %^BLUE%^A few "+
           "small%^RESET%^ %^YELLOW%^rodents%^RESET%^ %^BLUE%^scurry "+
           "about the trunk of the willow, startled by the numerous "+
           "visitors seeking respite in this peaceful area.  Many "+
           "weary travellers, mostly rangers, have gathered to this "+
           "spot, absorbing the atmosphere and enjoying the natural "+
           "carpet of%^RESET%^ %^RED%^dried leaves%^RESET%^ %^BLUE%^as "+
           "they talk and laugh amongst themselves.%^RESET%^\n");
        set_items(([
           "willow" : "%^BLUE%^This weeping willow sways gently in "+
              "the wind, its branches and leaves shading the area from "+
              "the elements.%^RESET%^",
           "leaves" : "%^RED%^Dead leaves crunch underfoot as you walk "+
              "upon them.%^RESET%^", 
           "logs" : "%^RED%^These large fallen logs provide "+
              "comfortable seating for the rangers and visitors that "+
              "gather under the shade of the tree%^RESET%^", 
           ({"pit","fire pit","ash"}) : "%^BOLD%^%^BLACK%^This pit "+
              "is filled with ash from previous campfires and is now "+
              "quite cool.%^RESET%^"
        ]));
        set_smell("default","%^RED%^The smell of decaying debris "+
           "is %^YELLOW%^pungent,%^RESET%^ %^RED%^but not unpleasant.");
        set_listen("default","%^BOLD%^%^BLUE%^Boisterous laughter and "+
           "merriment fill the air, along with the sounds of the forest.");
        set_exits(([
           "west" : "/d/magic/temples/mielikki_center"
        ]));
}