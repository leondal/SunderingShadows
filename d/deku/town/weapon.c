#include <std.h>
      
inherit "/std/room";
      
void create() 
{
    ::create();
    set_light(2);
    set_indoors(1);
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("smithy", 1);
    set_short("%^BOLD%^%^BLUE%^D%^RESET%^%^BLUE%^entiata's %^BOLD%^W%^RESET%^%^BLUE%^eapon %^BOLD%^S%^RESET%^%^BLUE%^hop%^WHITE%^");
    set_long(
"%^BOLD%^%^BLUE%^D%^RESET%^%^BLUE%^entiata's %^BOLD%^W%^RESET%^%^BLUE%^eapon %^BOLD%^S%^RESET%^%^BLUE%^hop%^WHITE%^
As soon as you enter this large building you feel intenseheat emanating from a big forge in the center. The hot coals are fanned by bellows to the side. The various anvils, hammers, and other trappings can only mean you are inside a blacksmith shop. Here you can buy and sell weapons. A large sign reads: %^RED%^Welcome to the Verbobone Smithy%^WHITE%^"
     );
    set_listen("default","The clang of metal reverberates through the store.");
    set_smell("default", "The smoke from the coals is stifling."); 
//  set_property("no attack",1);
    set_exits((["north":"/d/deku/town/road4"])); 
    set_items(([
    ] ));
    if(!present("shopkeeper")) 
    { 
        find_object_or_load("/d/deku/monster/shop_k")->move(TO);
    }
}

void reset()
{
    ::reset();
    if(!present("shopkeeper")) 
    {
        find_object_or_load("/d/deku/monster/shop_k")->move(TO);
    }
}
