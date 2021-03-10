// shadow double creature
#include <std.h>
#define SAVE_DIR = "/d/magic/obj/save/"
inherit "/d/magic/obj/aobject";

object thing, caster;

void create(){
  ::create();
  set_name("shadow");
  set_id(({"shadow","figure","shadowy figure","summoned monster"}));
  set_long("%^BOLD%^%^BLACK%^This being is shadowy and hard at times to make out, more so in areas of darkness. Its features are difficult to discern, other than the %^RESET%^%^RED%^glowing eyes%^BOLD%^%^BLACK%^ that peer forth like twin embers left to burn within a bed of dead coals. There is something unsettlingly familiar about its features that you can't quite make out...%^RESET%^");
  set_short("%^BOLD%^%^BLACK%^a shadowy figure%^RESET%^");
  set_alignment(5);
  set("magic",1);
  set_body_type("humanoid");
  set_race("shadow");
  set_size(2);
}

void die(object ob) {
        object obj;
        tell_room(ETO,"%^CYAN%^The shadow shimmers and disappears.%^RESET%^");
        if (objectp(thing)) {
            if(member_array(thing,caster->query_protectors()) != -1) { 
                caster->remove_protector(thing); 
            }
            thing->move(environment(TO));

            if(sizeof(all_inventory(thing))) {
                all_inventory(thing)->move(environment(thing));
            }
            thing->remove();
        }
        remove();
}
