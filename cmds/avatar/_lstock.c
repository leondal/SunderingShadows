//faiths added by Circe 3/25/04
#include <std.h>
#include "/d/dagger/sp_armor.h"
#include "/d/dagger/sp_weapons.h"
#include "/d/dagger/sp_other.h"
#include "/d/dagger/sp_mundane.h"
#include "/d/dagger/sp_faiths.h"

inherit DAEMON;

int cmd_lstock(string str){
   int i;
   string *tmp =({});
   if(!str) notify_fail("List what stock?  Try armors, weapons, mundane, faiths, or other.\n");
   if(str == "armor" || str == "armors" || str == "armour"){
      tmp = keys(ARMOR);
      tmp += keys(ARMOR2);      
      tmp = sort_array(tmp, "sort_alpha", TO);
//      for(i=0;i<sizeof(tmp);i++){
//         write(tmp[i]);
//      }
      write(format_page(tmp,3));
      return 1;
   }
   if(str == "weapon" || str == "weapons"){
      tmp = keys(WEAPONS);
      tmp += keys(WEAPONS2);
      tmp = sort_array(tmp, "sort_alpha", TO);
//      for(i=0;i<sizeof(tmp);i++){
//         write(tmp[i]);
//      }
      write(format_page(tmp,3));
      return 1;
   }
   if(str == "other"){
      tmp = keys(OTHER);
      tmp = sort_array(tmp, "sort_alpha", TO);
//      for(i=0;i<sizeof(tmp);i++){
//         write(tmp[i]);
//      }
      write(format_page(tmp,3));
      return 1;
   }
   if(str == "mundane"){
      tmp = keys(MUNDANE);
      tmp = sort_array(tmp, "sort_alpha", TO);
//      for(i=0;i<sizeof(tmp);i++){
//         write(tmp[i]);
//      }
      write(format_page(tmp,3));
      return 1;
   }
   if(str == "faiths"){
      tmp = keys(FAITHS);
      tmp = sort_array(tmp, "sort_alpha", TO);
//      for(i=0;i<sizeof(tmp);i++){
//         write(tmp[i]);
//      }
      write(format_page(tmp,3));
      return 1;
   }
   write("Try 'lstock armor', 'lstock weapons', 'lstock mundane', 'lstock faiths', or 'lstock other' to see the stock lists");
   return 1;
}
string sort_alpha(string one, string two){
   return strcmp(one,two);
}
int help(){
   write("Syntax: lstock weapons, or lstock armor, lstock mundane, lstock faiths, or lstock "+
      "other \n\nThis will show you a list of items you can create "+
      "by using the rstock command. \n\nRelated subjects: rstock.");
   return 1;
}
