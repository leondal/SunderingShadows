#include <std.h>
#include <move.h>

inherit PARMOUR;

void create(){
   ::create();

   set_name("quiver for arrows");
   set_short("%^RESET%^%^ORANGE%^leather quiver%^RESET%^");
   set_long("%^ORANGE%^Crafted out of hardened leather "+
      "this conical shaped quiver serves as a place to "+
      "store arrows.  A simple geometical pattern has been"+
      " tooled into the leather.  A buckskin strap allows "+
      "for the quiver to be slung across the shoulder.%^RESET%^");
   set_id(({"quiver","quiver for arrows"}));
   set_max_internal_encumbrance(128);
   set_limbs(({"torso"}));
   set_type("ring");
   set_weight(10);
   set_value(10);
    set_property("repairtype",({ "leatherwork" }));
}

int put_into(string str){
  int res, i, silly;
  object ths,tht,*inv;
  string this, that;

  if (stringp(str) && sscanf(str,"%s in %s",this,that) == 2) {
    if (present(this,this_player())) {
      if (present(that,this_player()) || present(that,environment(this_player()))) {
        ths = present(this,this_player());
        tht = present(that, this_player());

        if(ths == tht) /* Plura 930208 */{
          notify_fail("Get real!\n");
          return 0;
        }
        if(!tht) tht = present(that, environment(this_player()));
        if(ths->drop()) {
          notify_fail("You cannot drop that!\n");
          return 0;
        }
        if(tht != TO) return 0;
          if(!ths->is_arrows()){
            notify_fail("This is meant for arrows only.");
                return 0;
          }

         if (tht->receive_objects()) {
          res = (int)ths->move(tht);
          if (res == MOVE_OK) {
            write("You put "+ths->query_short()+" in "+tht->query_short()+".\n");
            say(this_player()->query_cap_name()+" puts "+ths->query_short()+ " in "+tht->query_short()+".\n");
            return 1;
          }
          if (res == MOVE_NO_ROOM)
            notify_fail("For some reason it does not fit...\n");
          if (res == MOVE_NOT_ALLOWED)
            notify_fail("You are not allowed to do that...\n");
          return 0;
        }
        notify_fail("It is closed.\n");
        return 0;
      }
      notify_fail(capitalize(that)+" is not here.\n");
      return 0;

    }
    notify_fail("You are not carrying "+this+".\n");
    return 0;
  }
 return 0;
}
