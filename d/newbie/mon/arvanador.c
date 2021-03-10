#include <std.h>
inherit NPC;

void create(){
   ::create();
   set_name("Arvanador");
   set_short("Arvanador, Zabeth's familiar");
   set_id(({"arvanador","Arvanador","parrot","bird"}));
   set_long("%^RESET%^%^CYAN%^This is Arvanador, the familiar of Zabeth. He has a matching %^BLUE%^ink-smudge %^CYAN%^"
"against the side of his beak, and he has more of a pechant to answer questions that customers have, as Zabeth is always "
"busy keeping books copied and sorted out.%^RESET%^");
   set_race("parrot");
   set_body_type("fowl");
   set_class("fighter");
   set_mlevel("fighter",5);
   set_guild_level("fighter",5);
   set_hd(5,2);
   set_max_hp(query_hp());
   set_exp(12);
   remove_std_db();
   set_db("arvanador");
   set_random_act_db("arvanadorrandom");
   set_random_act_chance(6);
   set_need_addressed(0);
}