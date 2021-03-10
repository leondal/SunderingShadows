//_wearall.c

#include <std.h>

inherit DAEMON;

int limbs_okay(object armor);
int check_stuff(object armor);

int cmd_wearall() {
   object *inv;
   string *acname;
   int i, n, stop;


   if (TP->query_bound()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }

   if(this_player()->query_ghost()) {
      notify_fail("You are a ghost!  You can't do that.\n");
      return 0;
   }

   n = 1;
   inv=all_inventory(this_player());
   for(i=0; i<sizeof(inv); i++) {
      if(inv[i]->is_armour()  && !(inv[i]->query_worn()) ) {
         acname=inv[i]->query_id();
         if( !(inv[i]->query_worn()) && inv[i]->wearable() && limbs_okay(inv[i]) && !check_stuff(inv[i])) {
            while(present(acname[0]+" "+n,TP)->query_worn())
               n++;
            this_player()->force_me("wear "+acname[0]+" "+n);
         }
         n = 1;
      }
   }

   return 1;
} /* end equip */

void help() {
    write("
%^CYAN%^NAME%^RESET%^

wearall - wear everything

%^CYAN%^DESCRIPTION%^RESET%^

This command allows you to wear all your armor.

%^CYAN%^SEE ALSO%^RESET%^

wear, remove, drop, wield
");
}

int limbs_okay(object armor) {
   string *limbs,*alimbs;
   int i, j;

   limbs = TP->query_limbs();
   alimbs = armor->query_limbs();
   j = sizeof(alimbs);
   for(i = 0;i<j;i++)
      if(member_array(alimbs[i],limbs) != -1)
         return 1;

   return 0;
}

int check_stuff(object armor) {
   string *limb, type;
   int i;

   type = (string)armor->query_type();
   limb = armor->query_limbs();

   i = sizeof(limb);
   while(i--)
      if((TP->type_ok(type, limb[i]))) return 1;

   return 0;
}
