

//Seeth thanks tristan for creating the pouch for gems
//cause he certainly would not have any idea how to fix this guild chest without it ;)
#include <std.h>
#include <move.h>

inherit "/std/bag_logic";

void create(){
   ::create();

   set_name("guild chest");
set_short("%^BOLD%^%^RED%^Donation Chest for the %^BLACK%^Crimson Hand");

   set_long(
@SEETH
%^RED%^The chest is made of %^BLACK%^black iron %^RED%^with many engravements of vines with %^BLACK%^thorns %^RED%^and %^BLACK%^roses%^RED%^. It is meant for family members to leave items for other memebers to use.%^BOLD%^
SEETH
);
   set_id(({"chest","guild chest","Chest","donation chest","Donation chest"}));

   set_no_clean(1);
   set_max_internal_encumbrance(99999);
   set_weight(99999);
   set_value(10);
   set_possible_to_close(1);
}

int cleanup() {
    return 1;
}

int put_into(string str){
  int res, i, silly;
  object ths,tht,*inv;
  string this, that;

  if(total_light(this_player())+(int)this_player()->query_sight_bonus()<-1){
    notify_fail("It is too dark.\n");
    return 0;
  }
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
