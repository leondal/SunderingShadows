#include <std.h>
inherit "/std/vendor.c";
create() {
    ::create();
    set_name("grimm");
    set_id(({"Mr Grimm","Grimm","grimm","Mr grimm","mr grimm","Mr"}));
    set_short("%^BOLD%^%^RED%^Mr Grimm, %^WHITE%^Tobacco Dealer");
    set_long(
@SEETH
%^BOLD%^%^BLUE%^He gets the best tobacco throughout the Realms for you to buy. If you like smoking he has the tobacco you need.
SEETH
    );
    set_gender("male");
    set("aggressive",0);
    set_race("human");
    set_hd(15,0);
   set_hp(300);
    set_property("no bump",1);
   add_money("gold", random(200));
    set_body_type("human");
    set_storage_room("/d/guilds/pack/hall/smokeroom");
}
