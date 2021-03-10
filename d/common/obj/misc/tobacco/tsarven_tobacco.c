//Gave new desc and made it more IG - Cythera 4/05
#include <std.h>
inherit "/d/common/obj/misc/tobacco/tobacco";

void create()
{
    ::create();
    loads = 10;
    set_id(({ "brazil", "tsarven", "tobacco", "tsarven tobacco", "tsarven" }));
    set_name("tsarven");
    set_short("%^RESET%^%^RED%^Tsarven tobacco%^RESET%^");
    set_long("%^RED%^A satisfying, spicy and aromatic blend of Black Cavendish, Golden & Red Undrin, mixed with luxury brocken flake. The aromatic recipe of Vanilla and Rum make this blend smooth and very pleasent.\n%^ORANGE%^You should pack this in a pipe.\n%^YELLOW%^There are " + loads + " loads left.");
    set_value(400);
    set_has_messages();
    set_my_messages(({ "%^RESET%^%^ORANGE%^You enjoy the rich taste of the vanilla and rum infused Tsarven tobacco.%^RESET%^" }));
    set_your_messages(({ "%^RESET%^%^ORANGE%^You smell the odor of vanilla and rum infused Tsarven tobacco.%^RESET%^" }));
}

int use_load()
{
    ::use_load();
    set_long("%^RED%^A satisfying, spicy and aromatic blend of Black Cavendish, Golden & Red Undrin, mixed with luxury brocken flake. The aromatic recipe of Vanilla and Rum make this blend smooth and very pleasent.\n%^ORANGE%^You should pack this in a pipe.\n%^YELLOW%^There are " + loads + " loads left.");
}
