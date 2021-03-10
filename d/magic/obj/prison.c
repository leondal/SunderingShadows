#include <std.h>;
inherit OBJECT;

object spell;

void create(){
   ::create();
   set_name("statue");
   set_id( ({"statue","satue of energy"}) );
   set_short("%^BOLD%^Statue of energy");
   set_long("Thi is a strange statue vaguely resembling humanoid figure. It seems to be made out of pure energy.");
   set_weight(450);
}

void set_spell(object ob){
    spell=ob;
    return 1;
}
