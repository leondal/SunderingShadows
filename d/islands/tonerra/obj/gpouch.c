// cut weight to 5 since it's so specific and also changed to use the set_allowed function *Styx* 4/27/06

#include <std.h>
#include <move.h>

inherit PARMOUR;

void create(){
   ::create();

   set_name("pouch");
   set_short("Pouch for gems");

   set_long("This pouch is woven from some skin. It is made specially to carry gems.");
   set_id(({"pouch","gem pouch","Pouch"}));
set_id(({"pouch","gem pouch","Pouch","pouch for gems"}));

   set_max_internal_encumbrance(75);
   set_limbs(({"waist"}));
   set_type("clothing");
   set_weight(5);
   set_value(10);
}

int item_allowed(object item) {
   if(item->is_gem()) {
      return 1;
   }
   write("The gem pouch is meant for gems only.");
   return 0;
}


/*
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

        if(ths == tht) {
          notify_fail("Get real!\n");
          return 0;
        }
        if(!tht) tht = present(that, environment(this_player()));
        if(ths->drop()) {
          notify_fail("You cannot drop that!\n");
          return 0;
        }
        if(tht != TO) return 0;
          if(!ths->is_gem()){
            notify_fail("This is meant for gems only.\n");
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
*/