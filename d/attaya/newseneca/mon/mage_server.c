//server for the mage tower
//Coded by ~Circe~ for new Seneca 1/3/07 
#include <std.h>

inherit NPC;
//NPC because she is not a real barkeep - the food needs to be stronger than a zero price would allow

void create(){
   ::create();
   set_name("an enchanted teapot");
   set_id(({"teapot","enchanted teapot","an enchanted teapot","waitress","server"}));
   set_short("An enchanted teapot");
   set_level(10);
   set_long("%^RESET%^%^CYAN%^Hopping about on a base rimmed with "+
      "%^BOLD%^%^MAGENTA%^pink%^RESET%^%^CYAN%^, this %^BOLD%^"+
      "%^WHITE%^teapot%^RESET%^%^CYAN%^ is a most pleasant hostess.  "+
      "Her rotund %^BOLD%^%^WHITE%^white form %^RESET%^%^CYAN%^"+
      "is decorated with beautifully painted %^BOLD%^%^MAGENTA%^"+
      "flowers %^RESET%^%^CYAN%^complete with scrolling %^GREEN%^"+
      "vines %^CYAN%^and %^GREEN%^leaves%^CYAN%^.  When angered, "+
      "a thin stream of %^RESET%^steam %^CYAN%^often escapes her "+
      "spout, but most of the time her cheerful demeanor is "+
      "upheld, making her an amiable - if unusual - hostess.%^RESET%^");
   set_gender("female");
   set_exp(20);
   set_alignment(1);
   set_race("teapot");
   set_hd(10,0);
   set_hp(100);
   set_max_hp(query_hp());
   set_body_type("snake");
   remove_limb("mouth");
   remove_limb("head");
   remove_limb("tail");
   add_limb("spout","torso",0,0,0);
   add_limb("handle","torso",0,0,0);
   force_me("speech %^BOLD%^%^MAGENTA%^whistle");
   force_me("speak wizish");
}