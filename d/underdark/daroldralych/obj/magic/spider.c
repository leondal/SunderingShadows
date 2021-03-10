#include <std.h>
inherit WEAPONLESS;

void create(){
   ::create();
   set_name("little spider");
   setenv("MIN", "$N scuttles in.");
   setenv("MOUT", "$N scuttles $D.");
   set_id(({"spider"}));
   set_short("%^BOLD%^%^BLACK%^little black spi%^RED%^d%^BLACK%^er%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This is a small spider, only a little "
"bigger than a coin. It has a bulbous body and %^YELLOW%^beady eyes"
"%^BLACK%^, and eight furry legs that carry it quickly to and fro. A "
"%^RED%^bright crimson %^BLACK%^splash of color marks its back.%^RESET%^");
   set_hd(5,6);
   set_max_hp(25);
   set_hp(25);
   set_race("spider");
   set_gender("male");
   set_body_type("arachnid");
   set_ac(0);
   set_exp(1);
   set_attacks_num(1);
   set_damage(1,4);
   set_base_damage_type("pierce");
   set_property("knock unconscious",1);
}

void die(object ob) {
   tell_room(ETO,"%^RED%^The little spider falls over and curls up its legs.%^RESET%^");
   ::die(ob);
}
