#include <std.h>
inherit VENDOR;
create() {
   ::create();
   set_name("burford");
   set_id( ({ "gstorekeeper","Burford", "burford","clerk", "shop keeper", "shopkeeper"}) );
   set_short("%^BOLD%^%^GREEN%^B%^RESET%^%^GREEN%^urford%^CYAN%^, the %^BOLD%^g%^RESET%^%^CYAN%^e%^BOLD%^n%^RESET%^%^CYAN%^e%^BOLD%^r%^RESET%^%^CYAN%^a%^BOLD%^l s%^RESET%^%^CYAN%^t%^BOLD%^o%^RESET%^%^CYAN%^r%^BOLD%^e c%^RESET%^%^CYAN%^l%^BOLD%^e%^RESET%^%^CYAN%^r%^BOLD%^k%^RESET%^");
   set("aggressive", 0);
   set_level(19);
   set_long("This crooked portly human watches you intently.
%^BOLD%^<help shop>%^RESET%^ will get you a list of shop commands.\n");
   set_gender("male");
   set_alignment(4);
   set_race("human");
   add_money("gold", random(500));
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(19,3);
   set_max_hp(query_hp());
   set_exp(query_max_hp() * 10);
   set_storage_room("/d/deku/town/gs_storage");
   remove_std_db();
}
 
